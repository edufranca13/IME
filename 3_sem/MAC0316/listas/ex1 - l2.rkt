#lang plai-typed

(define-syntax (cps e)
  (syntax-case e (with rec lam cnd seq set quote display read-number)
    ; with é como o ret
    [(_ (with (v e) b))
     #'(cps ((lam (v) b) e))]
    
    ; rec é como letrec
    [(_ (rec (v f) b))
     #'(cps (with (v (lam (arg) (error 'dummy "nothing")))
                  (seq
                   (set v f)
                   b)))]
    
    ; lambda
    [(_ (lam (a) b))
     (identifier? #'a)
     #'(lambda (k)
         (k (lambda (a dyn-k)
              ((cps b) dyn-k))))] ; por que dyn-k e não k?
    
    ; cnd é o if
    [(_ (cnd tst thn els))
     #'(lambda (k)
         ((cps tst) (lambda (tstv)
                      (if tstv
                          ((cps thn) k)
                          ((cps els) k)))))]
    
    ; set é o mesmo que set!
    [(_ (set v e))
     #'(lambda (k)
         ((cps e) (lambda (ev)
                    (k (set! v ev)))))]
    
    ; begin para 2 expressões
    [(_ (seq e1 e2))
     #'(lambda (k)
         ((cps e1) (lambda (_)
                     ((cps e2) k))))]
    
    ; símbolo
    [(_ atomic)
     #'(lambda (k)
         (k atomic))]
    
    ; display - definido internamente
    [(_ (display output))
     #'(lambda (k)
         ((cps output) (lambda (ov)
                         (k (display ov)))))]
    
    ; read-number 
    [(_ (read-number prompt))
     #'(lambda (k)
         ((cps prompt) (lambda (pv)
                         (read-number/suspend pv k))))]
    ; chamada com 1 argumento
    [(_ (f a))
     #'(lambda (k)
         ((cps f) (lambda (fv)
                    ((cps a) (lambda (av)
                               (fv av k))))))]
    
    ; com dois
    [(_ (f a b))
     #'(lambda (k)
         ((cps a) (lambda (av)
                    ((cps b) (lambda (bv)
                               (k (f av bv)))))))]
    
    ))

((lambda (k)
     ((cps 1.618034) (lambda (av)
                ((cps 1729) (lambda (bv)
                              ((cps 42) (lambda (cv)
                                          (k (+ cv (* av bv)))))))))) (lambda (id) id))

(+ 42 (* 1.618034 1729))