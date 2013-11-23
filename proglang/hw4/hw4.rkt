#lang racket

(provide (all-defined-out)) ;; so we can put tests in a second file

;; put your code below

(define (sequence low high stride)
  (cond [(> low high) null]
        [else (cons low (sequence (+ low stride) high stride))]))

(define (string-append-map xs suffix)
  (map (lambda (x) (string-append x suffix)) xs))

(define (list-nth-mod xs n)
  (cond [(< n 0) (error "list-nth-mod: negative number")]
       [(empty? xs) (error "list-nth-mod: empty list")]
       [else (car (list-tail xs (remainder n (length xs))))]))

(define nats
  (letrec ([f (lambda (x) (cons x (lambda () (f (+ x 1)))))])
    (lambda () (f 1))))

(define (stream-for-n-steps s n)
  (if (= n 0)
      null
      (cons (car (s)) (stream-for-n-steps (cdr (s)) (- n 1)))))

(define funny-number-stream
  (letrec ([f (lambda (x) (cons x (lambda () 
                                    (let ([next (+ (abs x) 1)])
                                    (f (if (= (remainder next 5) 0) 
                                           (- next)
                                           next))))))])
    (lambda () (f 1))))

(define dan-then-dog
  (letrec ([f (lambda (x) (cons x (lambda ()
                                    (f (if (equal? x "dan.jpg")
                                           "dog.jpg"
                                           "dan.jpg")))))])
    (lambda () (f "dan.jpg"))))

(define (stream-add-zero s) 
  (letrec ([f (lambda (str) (cons (cons 0 (car (str))) 
                                  (lambda () (f (cdr (str))))))])
    (lambda () (f s))))

(define (cycle-lists xs ys) 
  (letrec
      ([f (lambda (n) (cons (cons (list-nth-mod xs n) (list-nth-mod ys n))
                            (lambda () (f (+ n 1)))))])
    (lambda () (f 0))))

(define (vector-assoc v vec)
  (letrec ([veclen (vector-length vec)]
           [helper (lambda (index)
              (cond
                [(empty? vec) #f]
                [(= index veclen) #f]
                [(not (pair? (vector-ref vec index))) (helper (+ index 1))]
                [(equal? v (car (vector-ref vec index))) (vector-ref vec index)]
                [else (helper (+ index 1))]))])
    (helper 0)))

(define (cached-assoc xs n)
  (let ([cache (make-vector n #f)]
        [index 0])
    (lambda (val)
      (let ([ans (vector-assoc val cache)])
        (cond
          [ans ans]
          [else (letrec 
                    ([result (assoc val xs)])                  
                  (begin
                    (vector-set! cache index result)
                    (set! index (remainder (+ index 1) n))
                    result))])))))                                