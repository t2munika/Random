(* Assignment 1 unit tests *)

(* is_older tests *)
val is_older_same = is_older((2013, 4, 4), (2013, 4, 4)) = false
val is_older_old_year = is_older((2012, 4, 4), (2013, 4, 4)) = true
val is_older_old_month = is_older((2013, 4, 4), (2013, 5, 4)) = true
val is_older_old_day = is_older((2013, 4, 4), (2013, 4, 5)) = true
val is_older_younger_year = is_older((2013, 4, 4), (2012, 4, 4)) = false
val is_older_younger_month = is_older((2013, 6, 4), (2013, 5, 4)) = false
val is_older_younger_day = is_older((2013, 4, 6), (2013, 4, 5)) = false

(* number_in_month tests *)
val number_in_month_empty = number_in_month([], 4) = 0
val number_in_month_none = number_in_month([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)], 6) = 0
val number_in_month_some = number_in_month([(2013, 4, 6), (2011, 4, 5), (2013, 11, 6), (2013, 7, 5)], 4) = 2

(* number_in_months tests *)
val number_in_months_all_empty = number_in_months([],[]) = 0
val number_in_months_mths_empty = number_in_months([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)],[]) = 0
val number_in_months_dates_empty = number_in_months([],[1, 2 ,3]) = 0
val number_in_months_some = number_in_months([(2013, 4, 6), (2011, 4, 5), (2013, 11, 6), (2013, 7, 5)],[4, 11]) = 3
val number_in_months_none = number_in_months([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)], [1, 2]) = 0

(* dates_in_month tests *)
val dates_in_month_empty = dates_in_month([], 4) = []
val dates_in_month_none = dates_in_month([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)], 6) = []
val dates_in_month_some = dates_in_month([(2013, 4, 6), (2011, 4, 5), (2013, 11, 6), (2013, 7, 5)], 4) = [(2013, 4, 6), (2011, 4, 5)]

(* dates_in_months tests *)
val dates_in_months_all_empty = dates_in_months([],[]) = []
val dates_in_months_mths_empty = dates_in_months([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)],[]) = []
val dates_in_months_dates_empty = dates_in_months([],[1, 2 ,3]) = []
val dates_in_months_some = dates_in_months([(2013, 4, 6), (2011, 4, 5), (2013, 11, 6), (2013, 7, 5)],[4, 11]) = [(2013, 4, 6), (2011, 4, 5), (2013, 11, 6)]
val dates_in_months_none = dates_in_months([(2013, 4, 6), (2011, 3, 5), (2013, 11, 6), (2013, 7, 5)], [1, 2]) = []

(* get_nth tests *)
val str_list = ["Aw", "Yeah", "strings", "are", "awesome"]
val get_nth_beginning = get_nth(str_list, 1) = "Aw"
val get_nth_middle = get_nth(str_list, 3) = "strings"
val get_nth_end = get_nth(str_list, 5) = "awesome"

(* date_to_string test *)
val dts_test = date_to_string((2013, 4, 4)) = "April 4, 2013"

(* number_before_reaching_sum tests *)
val nbrs_equal = number_before_reaching_sum(10, [1, 2, 3, 4, 5]) = 3
val nbrs_zero = number_before_reaching_sum(4, [3, 2, 1, 34]) = 0
val nbrs_typical = number_before_reaching_sum(19, [14, 4, 3]) = 2

(* what_month tests *)
val what_month_first = what_month(1) = 1
val what_month_border = what_month(31) = 1
val what_month_middle = what_month(70) = 3

(* month_range tests *)
val month_range_within_one_month = month_range(10, 14) = [1, 1, 1, 1, 1]
val month_range_across_two = month_range(29, 32) = [1, 1, 1, 2, 2]
val month_range_mixed_up = month_range(31, 12) = []

(* oldest tests *)
val oldest_none = oldest([]) = NONE
val oldest_one = oldest([(2012, 4, 4)]) = SOME((2012, 4, 4))
val oldest_two = oldest([(2012, 4, 4), (2013, 12, 4)]) = SOME((2012,4,4))
val oldest_three = oldest([(2012,2,28),(2011,3,31),(2011,4,28)]) = SOME (2011,3,31)



