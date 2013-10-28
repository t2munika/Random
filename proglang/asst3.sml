(* Coursera Programming Languages, Homework 3, Provided Code *)

exception NoAnswer

datatype pattern = Wildcard
         | Variable of string
         | UnitP
         | ConstP of int
         | TupleP of pattern list
         | ConstructorP of string * pattern

datatype valu = Const of int
          | Unit
          | Tuple of valu list
          | Constructor of string * valu

fun g f1 f2 p =
    let 
    val r = g f1 f2 
    in
    case p of
        Wildcard          => f1 ()
      | Variable x        => f2 x
      | TupleP ps         => List.foldl (fn (p,i) => (r p) + i) 0 ps
      | ConstructorP(_,p) => r p
      | _                 => 0
    end

(**** for the challenge problem only ****)

datatype typ = Anything
         | UnitT
         | IntT
         | TupleT of typ list
         | Datatype of string

(**** you can put all your code here ****)

fun only_capitals(str_list) =
    List.filter (fn x => Char.isUpper(String.sub(x,0))) str_list

fun longest_string1(str_list) =
    List.foldl
        (fn (x, y) => 
           if String.size(x) > String.size(y)
           then x
           else y) "" str_list

fun longest_string2(str_list) =
    List.foldl
        (fn (x, y) => 
           if String.size(x) >= String.size(y)
           then x
           else y) "" str_list

fun longest_string_helper f str_list = 
    List.foldl
        (fn (x,y) => 
           if f(String.size(x), String.size(y))
           then x
           else y) "" str_list

val longest_string3 =
    longest_string_helper (fn (x,y) => x > y)

val longest_string4 =
    longest_string_helper (fn (x,y) => x >= y)

val longest_capitalized = longest_string3 o only_capitals

val rev_string = String.implode o List.rev o String.explode

fun first_answer f lst =
    case lst of
         [] => raise NoAnswer
         | x::x' => 
           case f x of
                NONE => first_answer f x'
                | SOME y => y

fun all_answers f lst = 
    let
        fun helper(lst_in, acc) =
            case lst_in of
                 [] => SOME acc
                 | x::xs' =>
                   case f x of
                        NONE => NONE
                        | SOME y => helper(xs', acc@y)
    in
        helper(lst, [])
    end

fun count_wildcards p = g (fn () => 1) (fn x => 0) p

fun count_wild_and_variable_lengths p = g (fn () => 1) (fn x => String.size(x)) p

fun count_some_var (str, p) = 
    g (fn () => 0) (fn x => if x = str then 1 else 0) p

fun check_pat p =
    let
        fun has_no_dups(str_list) =
            case str_list of
                 [] => true
                 | x::xs' => 
                   if List.exists (fn a => x = a) xs'
                   then false 
                   else has_no_dups(xs')
        fun get_vars(ptn : pattern) =
            case ptn of
                 Variable x => [x]
                 | TupleP ps => List.foldl (fn (x,y) => get_vars(x)@y) [] ps
                 | ConstructorP(_,pat) => get_vars(pat)
                 | _ => []
    in
        has_no_dups(get_vars(p))
    end

fun match(v, p) = 
    case p of
         Wildcard => SOME []
         | Variable var => (SOME [(var, v)])
         | UnitP => (case v of Unit => SOME [] | _ => NONE)
         | ConstP c => (case v of 
           Const(num) => if (c = num) then (SOME[]) else NONE
           | _ => NONE)
         | ConstructorP (s1, p1) => (case v of
           Constructor(s2, v2) => if (s1 = s2) then match(v2, p1) else NONE
           | _ => NONE)
         | TupleP ps => (case v of 
           Tuple vs => 
                 if (List.length(ps) = List.length(vs)) 
                 then (all_answers match (ListPair.zip(vs, ps)))
                 else NONE
           | _ => NONE)

fun first_match v p_lst = 
        SOME (first_answer (fn p => match(v,p)) p_lst) handle NoAnswer => NONE 