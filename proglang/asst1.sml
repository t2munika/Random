fun is_older(dt1 : int * int * int, dt2 : int * int * int) =
	if (#1 dt1) <> (#1 dt2)
	then (#1 dt1) < (#1 dt2)
	else
		if (#2 dt1) <> (#2 dt2)
		then (#2 dt1) < (#2 dt2)
		else
			if (#3 dt1) <> (#3 dt2)
			then (#3 dt1) < (#3 dt2)
			else false

fun number_in_month(dt_list : (int*int*int) list,  month : int) =
	if null(dt_list)
	then 0
	else 
		 if (#2 (hd(dt_list))) = month
		 then 1 + number_in_month(tl(dt_list), month)
		 else number_in_month(tl(dt_list), month)

fun number_in_months(dt_list : (int*int*int) list, mth_list : int list) =
	if null(mth_list)
	then 0
	else number_in_month(dt_list, hd(mth_list)) + number_in_months(dt_list, tl(mth_list))

fun dates_in_month(dt_list : (int*int*int) list, month : int) =
	if null(dt_list)
	then []
	else 
		 if (#2 (hd(dt_list))) = month
		 then hd(dt_list)::dates_in_month(tl(dt_list), month)
		 else dates_in_month(tl(dt_list), month)

fun dates_in_months(dt_list : (int*int*int) list, mth_list : int list) =
	if null(mth_list)
	then []
	else dates_in_month(dt_list, hd(mth_list)) @ dates_in_months(dt_list, tl(mth_list))

fun get_nth(str_list : string list, n : int) =
	if n = 1
	then hd(str_list)
	else get_nth(tl(str_list), n - 1)

val month_names = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

val month_lengths = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

fun date_to_string(date : int*int*int) =
	get_nth(month_names, #2 date) ^ " " ^ Int.toString(#3 date) ^ ", " ^ Int.toString(#1 date)

fun number_before_reaching_sum(sum : int, int_list : int list) =
	if sum <= hd(int_list)
	then 0
	else 1 + number_before_reaching_sum(sum - hd(int_list), tl(int_list))

fun what_month(day : int) =
	number_before_reaching_sum(day, month_lengths) + 1

fun month_range(day1 : int, day2 : int) =
	if day1 > day2
	then []
	else what_month(day1)::month_range(day1 + 1, day2)

fun oldest(dt_list : (int*int*int) list) =
	if null(dt_list)
	then NONE
	else let
		fun oldest_nonempty (dts : (int*int*int) list) =
			if null(tl(dts))
			then hd(dts)
			else 
				let 
					val old_date = oldest_nonempty(tl(dts)) 
			    in
					if is_older(old_date, hd(dts))
					then old_date
					else hd(dts)
				end
		in
			SOME(oldest_nonempty(dt_list))
		end
