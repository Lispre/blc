* run eval_expr from input stream?
* add method (define?) for adding input-variable to environment
  place eval reading from input into lambda expression?
* readBit function (monadic IO) <-> quote, eval?
* add quote and eval to environment
* implement define
* primitives (implement using quote and eval?)
    * quote, null, true, false, cons, (1 . ()), first, rest
    * define, list, eq?, not, null?, pair?, and, or, xor, if
    * member?, append, assoc, cond, equal?
    * eval, quasiquote, quote
    * sublis (substitution)
* ffi
* Earley parser for bits?
* binary tree tokenizer, compose grammars
* overload representation of pairs?
* macros