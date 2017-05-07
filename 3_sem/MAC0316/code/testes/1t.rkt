#lang plai-typed

(define-type Shape
  [square (side : number)]
  [circle (radius : number)]
  [triangle (height : number)
          (width : number)
          ])

(define (area [s : Shape])
  (type-case Shape s
    [square (l) (* l l)]
    [circle (r) (* (* r r) 3.14)]
    [triangle (h w) (/ (* h w) 2)]
    ))

(define (curvy? [s : Shape]) : boolean
  (circle? s))
