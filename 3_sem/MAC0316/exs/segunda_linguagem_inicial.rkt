#lang plai-typed

;; A segunda linguage permite declarar e aplicar funções

(define-type ExprC
  [numC (n : number)]
  [idC (s : symbol)] ;;identificador para argumentos
  [appC (fun : symbol) (arg : ExprC)] ;; aplicação com o nome e argumento
  [plusC (l : ExprC) (r : ExprC)]
  [multC (l : ExprC) (r : ExprC)]
  [ifC (condição : ExprC) (sim : ExprC) (não : ExprC)])

;; função de um argumento
(define-type FunDefC
  [fdC (name : symbol) (arg : symbol) (body : ExprC)])

;; açucar sintático para demais operações
(define-type ExprS
  [numS (n : number)]
  [idS (s : symbol)]
  [appS (fun : symbol) (arg : ExprS)]
  [plusS (l : ExprS) (r : ExprS)]
  [bminusS (l : ExprS) (r : ExprS)]
  [uminusS (e : ExprS)]
  [multS (l : ExprS) (r : ExprS)]
  [ifS (condição : ExprS) (sim : ExprS) (não : ExprS)]
  )

(define (desugar [as : ExprS]) : ExprC
  (type-case ExprS as
    [numS (n) (numC n)]
    [idS (s) (idC s)]
    [appS (fun arg) (appC fun (desugar arg))] ;; fun é um simbolo
                                              ;; não precisa de desugar
    [plusS (l r) (plusC (desugar l) (desugar r))]
    [multS (l r) (multC (desugar l) (desugar r))]
    [bminusS (l r) (plusC (desugar l) (multC (desugar r) (numC -1)))]
    [uminusS (e) (multC (numC -1) (desugar e))]
    [ifS (c s n) (ifC (desugar c) (desugar s) (desugar n))]
    ))

;; é preciso substituir um valor no simbolo e avaliar a expressão
;; edu - quem é o valor passado?
(define (subst [valor : ExprC] [isso : symbol] [em : ExprC]) : ExprC
  (type-case ExprC em
    [numC (n) em] ;; se for um numC devolve ele mesmo
    [idC (s) (cond
               [(symbol=? s isso) valor]
               [else em])]
    [appC (f a) (appC f (subst valor isso a))] ;; chamada de função arruma o argumento
    [plusC (l r) (plusC (subst valor isso l) (subst valor isso r))]
    [multC (l r) (multC (subst valor isso l) (subst valor isso r))]
    [ifC (c s n) (ifC (subst valor isso c)
                      (subst valor isso s) (subst valor isso n))]
    ))

;; interpretador
(define (interp [a : ExprC] [fds : (listof FunDefC)]) : number
  (type-case ExprC a
    [numC (n) n]
    [appC (f a)
          (local ([define fd (get-fundef f fds)]) ;; pega a def. na lista (que devolve um FunDefC
            (interp (subst a ;; substitui o valor a nos argumentos e corpo da função
                           (fdC-arg fd) ;; pega os argumentos da função
                           (fdC-body fd) ;; pega o corpo da função
                           )
                    fds))]
    [idC (_) (error 'interp "nao deveria encontrar isso")]
    [plusC (l r) (+ (interp l fds) (interp r fds))]
    [multC (l r) (* (interp l fds) (interp r fds))]
    [ifC (c s n) (if (zero? (interp c fds)) (interp n fds) (interp s fds))]
    ))

(define (get-fundef [f : symbol] [fds : (listof FunDefC)]) : FunDefC
  (cond
    [(empty? fds) (error 'get-fundef "referência não definida")]
    [(cons? fds) (cond
                   [(equal? f (fdC-name (first fds))) (first fds)] ;; se o nome na lista for igual ao nome passdo então devolve o primeiro
                   [else (get-fundef f (rest fds))])]
    ))

(define (parse [s : s-expression]) : ExprS
  (cond
    [(s-exp-number? s) (numS (s-exp->number s))]
    [(s-exp-list? s)
     (let ([sl (s-exp->list s)])
     (case (s-exp->symbol (first sl))
       [(+) (plusS (parse (second sl)) (parse (third sl)))]
       [(*) (multS (parse (second sl)) (parse (third sl)))]
       [(-) (bminusS (parse (second sl)) (parse (third sl)))]
       [(~) (uminusS (parse (second sl)))]
       [(call) (appS (s-exp->symbol (second sl)) (parse (third sl)))]
       [(if) (ifS (parse (second sl)) (parse (third sl)) (parse (fourth sl)))]
       [else (error 'parse "entrada inválida")]))]
    [else (error 'parse "entrada inválida")])
     )

;;Exemplos
(define biblioteca
  (list
   [fdC 'dobro 'x (plusC (idC 'x) (idC 'x))]
   [fdC 'quadrado 'y (multC (idC 'y) (idC 'y))]
   [fdC 'fatorial 'n (ifC (idC 'n)
                          (multC (appC 'fatorial (plusC (idC 'n) (numC -1)))
                                 (idC 'n))
                          (numC 1))]
   [fdC 'narciso 'narciso (multC (idC 'narciso) (numC 1000))]))

(interp (desugar (parse '(+ -1400 (call fatorial 7)))) biblioteca)
(test (interp (desugar (parse '(call narciso (call fatorial 7)))) biblioteca) 5040000)
(test (interp (desugar (parse '(call fatorial 5))) biblioteca) 120)
  


    