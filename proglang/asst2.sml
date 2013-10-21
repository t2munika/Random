(* Dan Grossman, Coursera PL, HW2 Provided Code *)

(* if you use this function to compare two strings (returns true if the same
   string), then you avoid several of the functions in problem 1 having
   polymorphic types that may be confusing *)
fun same_string(s1 : string, s2 : string) =
    s1 = s2

(* put your solutions for problem 1 here *)
fun all_except_option(str : string, str_list : string list) =
	let fun helper(str_list_in) =
		case str_list_in of
			 [] => []
			|x::x' => if same_string(str, x) then x' else x::helper(x')
	val potential_list = helper(str_list)
	in
		if (potential_list = str_list) then NONE else SOME(potential_list)
	end
				   
fun get_substitutions1(str_lists : string list list, str : string) =
	case str_lists of
		 [] => []
	   | x::x' =>
	   	 	  case all_except_option(str, x) of
			  	   NONE => get_substitutions1(x', str)
			     | SOME i => i @ get_substitutions1(x', str)

fun get_substitutions2(str_lists : string list list, str : string) =
	let fun get_subs(str_lists_in : string list list, acc : string list) =
		case str_lists_in of
			[] => acc
		  | x::x' =>
		  		case all_except_option(str, x) of
					NONE => get_subs(x', acc)
		    	  | SOME i => get_subs(x', acc@i)
	in
		get_subs(str_lists, [])
	end

fun similar_names(str_lists, {first=x, last=y, middle=z}) =
	case str_lists of
		[] => [{first=x, last=y, middle=z}]
	  | lst::lst' =>
	  		let fun sim_names(str_list : string list) =
				case str_list of
					[] => []
				  | alt::alt' => {first=alt, last=y, middle=z}::sim_names(alt')
			in
				{first=x,last=y,middle=z}::sim_names(get_substitutions2(str_lists, x))
			end

(* you may assume that Num is always used with values 2, 3, ..., 10
   though it will not really come up *)
datatype suit = Clubs | Diamonds | Hearts | Spades
datatype rank = Jack | Queen | King | Ace | Num of int
type card = suit * rank

datatype color = Red | Black
datatype move = Discard of card | Draw

exception IllegalMove

(* put your solutions for problem 2 here *)
fun card_color(the_card : card) =
	case the_card of
		 (Clubs, _) => Black
		|(Spades, _) => Black
		|(Hearts, _) => Red
		|(Diamonds, _) => Red

fun card_value(the_card : card) =
	case the_card of
		 (_, Jack) => 10
		|(_, Queen) => 10
		|(_, King) => 10
		|(_, Ace) => 11
		|(_, Num x) => x

fun remove_card(cs, c, e) =
	case cs of
		 [] => raise e
		|x::x' =>
			 if c = x
			 then x'
			 else x::remove_card(x', c, e)

fun all_same_color(cs) =
	case cs of
		 [] => true
		|x::x' =>
		 case x' of
		 	  [] => true
			 |y::y' =>
			 	  if card_color(x) = card_color(y)
			 	  then all_same_color(x')
				  else false

fun sum_cards(cs) =
	let fun sum_cards_helper(cs_in, sum_so_far) =
		case cs_in of
			 [] => sum_so_far
			|x::x' => sum_cards_helper(x', sum_so_far + card_value(x))
	in
		sum_cards_helper(cs, 0)
	end

fun score(cs, goal) =
	let
		val sum = sum_cards(cs)
		val same = all_same_color(cs)
		val over_prelim = 3 * (sum - goal)
		val under_prelim = goal - sum
	in
		if same
		then if sum > goal then over_prelim div 2 else under_prelim div 2
		else if sum > goal then over_prelim else under_prelim
	end

fun officiate(cs, move, goal) =
	let fun helper(cs_in, move_in, held_cards) =
		case move_in of
			 [] => score(held_cards, goal)
			|m::moves' =>
				 case m of
				 	  Discard c => helper(cs_in, moves',
					  		  remove_card(held_cards, c, IllegalMove))
					 |Draw =>
					  	   case cs_in of
						   		[] => score(held_cards, goal)
							   |c::cards' =>
									if (sum_cards(held_cards) > goal)
									then score(held_cards, goal)
									else helper(cards', moves', c::held_cards)
	in
		helper(cs, move, [])
	end
