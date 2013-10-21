(* Assignment 2 tests *)

(* all_except_option tests *)
val aeo_empty = all_except_option("Fred", []) = NONE
val aeo_no_alts = all_except_option("Fred", ["Fran", "Francisco"]) = NONE
val aeo_some_alts = all_except_option("Fred", ["Freddy", "Fred", "Fredster"]) = SOME(["Freddy", "Fredster"]);

(* get_substitutions1 [and 2] tests *)
val has_no_subs_list = [["Britney", "Brit"], ["Davis", "Panda"]]
val has_subs_list = [["Britney", "Brit"], ["Fred", "Freddy"], ["Davis", "Panda"], ["Fred", "Fredster"]]

val gs1_empty = get_substitutions1([], "Fred") = []
val gs1_no_subs = get_substitutions1(has_no_subs_list, "Fred") = []
val gs1_some_subs = get_substitutions1(has_subs_list, "Fred") = ["Freddy", "Fredster"]

val gs2_empty = get_substitutions2([], "Fred") = []
val gs2_no_subs = get_substitutions2(has_no_subs_list, "Fred") = []
val gs2_some_subs = get_substitutions2(has_subs_list, "Fred") = ["Freddy", "Fredster"]

(* similar_names tests *)
val name = {first="Fred", middle="W", last="Smith"}
val sn_empty = similar_names([], name) = [name]
val sn_no_names = similar_names(has_no_subs_list, name) = 
	[{first="Fred", last="Smith", middle="W"}]
val sn_some_names = similar_names(has_subs_list, name) = 
	[{first="Fred", last="Smith", middle="W"},
	 {first="Freddy", last="Smith", middle="W"},
	 {first="Fredster", last="Smith", middle="W"}]

(* card_color and card_value tests *)
val cc_black = card_color((Clubs, Ace)) = Black
val cc_red = card_color(Diamonds, Jack) = Red
val cv_10 = card_value((Spades, King)) = 10
val cv_11 = card_value((Hearts, Ace)) = 11
val cv_num = card_value((Hearts, Num(42))) = 42

(* remove_card tests *)
val rc_empty = ((remove_card([], (Clubs, Num 9), IllegalMove); false) 
	handle IllegalMove => true)
val rc_card_not_there = ((remove_card([(Clubs, Ace), (Clubs, Jack), (Hearts, Num 9)], (Clubs, Num 9), IllegalMove); false)
	handle IllegalMove => true)
val rc_card_there  = remove_card([(Clubs, Ace), (Clubs, Jack), (Hearts, Num 9)], (Clubs, Ace), IllegalMove) = [(Clubs, Jack), (Hearts, Num 9)]

(* all_same_color tests *)
val diff_color_set = [(Clubs,Ace), (Spades, Jack), (Hearts, Num 9)]
val same_color_set = [(Clubs,Ace), (Spades, Jack), (Clubs, Num 9)]

val asc_empty = all_same_color([]) = true
val asc_not_same = all_same_color(diff_color_set) = false
val asc_same = all_same_color(same_color_set) = true

(* sum_cards tests *)
val sc_empty = sum_cards([]) = 0
val sc_some_same = sum_cards(same_color_set) = 30
val sc_some_diff = sum_cards(diff_color_set) = 30

(* score tests *)
val score_under_same = score(same_color_set, 35) = 2
val score_on_same = score(same_color_set, 30) = 0
val score_over_same = score(same_color_set, 28) = 3
val score_under_diff = score(diff_color_set, 35) = 5
val score_on_diff = score(diff_color_set, 30) = 0
val score_over_diff = score(diff_color_set, 28) = 6

(* officiate tests *)

val moves_gone_first = officiate([(Hearts, Num 2),(Clubs, Num 4)],[Draw], 15) = 6

val cards_gone_first = officiate(
	[(Clubs,Ace),(Spades,Ace),(Clubs,Ace),(Spades,Ace)],
    [Draw,Draw,Draw,Draw,Draw],
    42)
    = 3

val officiate_illegal_move = ((officiate([(Clubs,Jack),(Spades,Num(8))],
                         [Draw,Discard(Hearts,Jack)],
                         42);
               false) 
              handle IllegalMove => true)
