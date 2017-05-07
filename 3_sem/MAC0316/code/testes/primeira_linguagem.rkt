#lang plai-typed

(define-type ArithC
  [numC (n : number)]
  [plusC (l : ArithC) (r : ArithC)]
  [multC (l : ArithC) (r : ArithC)]
  [ifC (condição : ArithC) (sim : ArithC) (não : ArithC)])

(define (parse (s : s-expression)) : ArithS
  (cond
    ;; se a s-expression for número retorna um number a partir dela
    ((s-exp-number? s) (numS (s-exp->number s)))
    ;; se ela for uma lista
    ((s-exp-list? s)
     ;; converte a s-expression em uma lista
     (let ((sl (s-exp->list s)))
       ;; analisa o primeiro simbolo
       (case (s-exp->symbol (first sl))
         ;; para cada simbolo eu crio o correspondente tipo da minha linguagem
         ;; finalmente se tem uma lista parseada na minha linguagem
         ((+) (plusS (parse (second sl)) (parse (third sl))))
         ((*) (multS (parse (second sl)) (parse (third sl))))
         ((-) (bminusS (parse (second sl)) (parse (third sl))))
         ((~) (uminusS (parse (second sl))))
         [(if) (ifS (parse (second sl))
                    (parse (third sl)) (parse (fourth sl)))]
         (else (error 'parse "invalid")))))
    (else (error 'parse "invalid"))))

;; a lista na minha linguagem é interpretada
(define (interp [a : ArithC]) : number
  (type-case ArithC a
    (numC (n) n)
    (plusC (l r) (+ (interp l) (interp r)))
    (multC (l r) (* (interp l) (interp r)))
    ;; o if é verdadeiro para não-zero
    [ifC (c s n) (if (zero? (interp c))
                     (interp n) (interp s))]
    ))

(define-type ArithS
  [numS (n : number)]
  [plusS (l : ArithS) (r : ArithS)]
  [multS (l : ArithS) (r : ArithS)]
  [bminusS (l : ArithS) (r : ArithS)]
  [uminusS (e : ArithS)]
  [ifS (c : ArithS) (s : ArithS) (n : ArithS)])

(define (desugar (as : ArithS))
  (type-case ArithS as
    (numS (n) (numC n))
    (plusS (l r) (plusC (desugar l) (desugar r)))
    (multS (l r) (multC (desugar l) (desugar r)))
    (bminusS (l r) (plusC (desugar l) (multC (numC -1) (desugar r))))
    (uminusS (e) (multC (numC -1) (desugar e)))
    [ifS (c s n) (ifC (desugar c) (desugar s) (desugar n))]))

;; Exemplo - (interp (desugar (parse '(- 3 4))))
;; Exemplo - (interp (desugar (parse '(if (- 3 2) 42 (+ 4 3))))
;; Exemplo - (define (interpS [a : ArithS]) (interp (desugar a)))

