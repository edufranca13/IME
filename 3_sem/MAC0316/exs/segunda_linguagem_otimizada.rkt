#lang plai-typed

;; tipo principal de nossa linguagem
(define-type ExprC
  [numC (n : number)]
  [idC (s : symbol)]
  [fdC (name : symbol) (arg : symbol) (body : ExprC)]
  [appC (fun : ExprC) (arg : ExprC)]
  [plusC (l : ExprC) (r : ExprC)]
  [multC (l : ExprC) (r : ExprC)]
  [ifC (condição : ExprC) (sim : ExprC) (não : ExprC)]
  )

;; açucar sintático para demais operações
(define-type ExprS
  [numS (n : number)]
  [idS (s : symbol)]
  [fdS (name : symbol) (arg : symbol) (body : ExprS)]
  [appS (fun : ExprS) (arg : ExprS)]
  [plusS (l : ExprS) (r : ExprS)]
  [bminusS (l : ExprS) (r : ExprS)]
  [uminusS (e : ExprS)]
  [multS (l : ExprS) (r : ExprS)]
  [ifS (condição : ExprS) (sim : ExprS) (não : ExprS)]
  )

;; converte do tipo açucarado para o tipo principal
(define (desugar [as : ExprS]) : ExprC
  (type-case ExprS as
    [numS (n) (numC n)]
    [idS (s) (idC s)]
    [fdS (n a b) (fdC n a (desugar b))]
    [appS (fun arg) (appC (desugar fun) (desugar arg))]
    [plusS (l r) (plusC (desugar l) (desugar r))]
    [multS (l r) (multC (desugar l) (desugar r))]
    [bminusS (l r) (plusC (desugar l) (multC (numC -1) (desugar r)))]
    [uminusS (e) (multC (numC -1) (desugar e))]
    [ifS (c s n) (ifC (desugar c) (desugar s) (desugar n))]
    ))


(define (parse [s : s-expression]) : ExprS
  (cond
    [(s-exp-number? s) (numS (s-exp->number s))]
    [(s-exp-symbol? s) (idS (s-exp->symbol s))]
    [(s-exp-list? s)
     (let ([sl (s-exp->list s)])
     (case (s-exp->symbol (first sl))
       [(func) (fdS (s-exp->symbol (second sl))
                    (s-exp->symbol (third sl))
                    (parse (fourth sl)))]
       [(+) (plusS (parse (second sl)) (parse (third sl)))]
       [(*) (multS (parse (second sl)) (parse (third sl)))]
       [(-) (bminusS (parse (second sl)) (parse (third sl)))]
       [(~) (uminusS (parse (second sl)))]
       [(call) (appS (parse (second sl)) (parse (third sl)))]
       [(if) (ifS (parse (second sl)) (parse (third sl)) (parse (fourth sl)))]
       [else (error 'parse "entrada inválida")]))]
    [else (error 'parse "entrada inválida")])
     )

(define (interp [a : ExprC] [env : Env]) : Value
  (type-case ExprC a
    [numC (n) (numV n)]
    [idC (n) (lookup n env)]
    [fdC (n a b) (funV n a b)]
    [appC (f a) (local ([define fd (interp f env)])
                  (interp (funV-body fd)
                          (extend-env (bind (funV-arg fd)
                                            (interp a env))
                                      mt-env)))]
    [plusC (l r) (num+ (interp l env) (interp r env))]
    [multC (l r) (num* (interp l env) (interp r env))]
    [ifC (c s n) (if (value0? (interp c env)) (interp n env) (interp s env))]
    ))

(define-type Binding
  [bind (name : symbol) (val : Value)])

(define-type-alias Env (listof Binding))
(define mt-env empty)
(define extend-env cons)

(define-type Value
  [numV (n : number)]
  [funV (name : symbol) (arg : symbol) (body : ExprC)]
  )

(define (num+ [l : Value] [r : Value]) : Value
  (cond
    [(and (numV? l) (numV? r))
     (numV (+ (numV-n l) (numV-n r)))]
    [else
     (error 'num "um dos argumentos não é número")]))

(define (num* [l : Value] [r : Value]) : Value
  (cond
    [(and (numV? l) (numV? r))
     (numV (* (numV-n l) (numV-n r)))]
    [else
     (error 'num "um dos argumentos não é número")]))

(define (value0? [c : Value]) : boolean
  (if (zero? (numV-n c)) #f #t))

(define (lookup [for : symbol] [env : Env]) : Value
  (cond
    [(empty? env) (error 'lookup "nome não encontrado")]
    [else (cond
            [(symbol=? for (bind-name (first env)))
                           (bind-val (first env))]
            [else (lookup for (rest env))])]))
            

;; exemplos

(interp (desugar (parse '(* 2 2))) mt-env)
(interp (desugar (parse '(func f1 a (+ a a)))) mt-env)
(interp (desugar (parse '(call (func f1 x (+ x x)) 3))) mt-env)