NAME = uls

INCI = inc/uls.h

INC = uls.h

SRCS = src/main.c \
	src/mx_clean_uls.c \
	src/mx_parse_flags.c \
	src/mx_get_sorted_flags.c \
	src/mx_printerr.c \
	src/mx_p_err_flag.c \
	src/mx_get_uls.c \
	src/mx_is_no_our_flags.c\
	src/mx_printerr_char.c \
	src/mx_get_root.c \
	src/mx_del_flag_dubl.c \
	src/mx_ret_clean_flag.c \
	src/mx_filter_flags.c \
	src/mx_del_dich_flags.c \
	src/mx_take_root.c \
	src/mx_push_root.c \
	src/mx_clean_root.c \
	src/mx_flags_to_int.c \
	src/mx_clean_file.c \
	src/mx_push_file.c \
	src/mx_get_files.c \
	src/mx_printend.c \
	src/mx_print_l.c \
	src/mx_ret_num_len_lld.c \
	src/mx_ret_num_len.c \
	src/mx_get_limits.c \
	src/mx_get_access.c \
	src/mx_get_flag_l.c \
	src/mx_flag_l_clean.c \
	src/mx_num_to_str.c \
	src/mx_get_hard_links.c \
	src/mx_get_user_name.c \
	src/mx_get_g_name.c \
	src/mx_lld_num_to_str.c \
	src/mx_get_size.c \
	src/mx_get_time.c \
	src/mx_print_total.c \
	src/mx_print_link.c \
	src/mx_get_min_maj.c \
	src/mx_push_dich.c \
	src/mx_clean_dich.c \
	src/mx_print_dich.c \
	src/mx_p_l.c \
	src/mx_push_file_light.c \
	src/mx_print_dich_inputs.c \
	src/mx_print_l_light.c \
	src/mx_get_last_u_names.c \
	src/mx_get_last_g_names.c \
	src/mx_get_files1.c \
	src/mx_push_file1.c \
	src/mx_print_c.c \
	src/mx_print_one.c \
	src/mx_print_space.c \
	src/mx_get_time_big.c \
	src/mx_print_ex_atr.c \
	src/mx_merge_sort.c \
	src/mx_split_f_b.c \
	src/mx_merge_sort_size.c \
	src/mx_merge_sort_status.c \
	src/mx_merge_sort_last_acc.c \
	src/mx_merge_sort_modification.c \
	src/mx_print_x.c \
	src/mx_merge_sort_r.c \
	src/mx_merge_sort_size_r.c \
	src/mx_merge_sort_status_r.c \
	src/mx_merge_sort_last_acc_r.c \
	src/mx_merge_sort_modification_r.c \
	src/mx_split_f_b_root.c \
	src/mx_merge_sort_root.c \
	src/mx_merge_sort_size_root.c \
	src/mx_merge_sort_status_root.c \
	src/mx_merge_sort_last_acc_root.c \
	src/mx_merge_sort_modification_root.c \
	src/mx_merge_sort_r_root.c \
	src/mx_merge_sort_size_r_root.c \
	src/mx_merge_sort_status_r_root.c \
	src/mx_merge_sort_last_acc_r_root.c \
	src/mx_merge_sort_modification_r_root.c \
	src/mx_print_space_x.c \
	src/mx_file_reverse.c \
	src/mx_root_reverse.c \
	src/mx_get_limits1.c \
	src/mx_print_main_nl.c \
	src/mx_main_rec.c \
	src/mx_get_files_rec.c \
	src/mx_print_main_nl_rec.c \
	src/mx_get_h.c \
	src/mx_get_h_pow.c \
	src/mx_add_h.c \
	src/mx_print_col.c \
	src/mx_print_c_col.c \
	src/mx_print_x_col.c \
	src/mx_get_access_col.c \
	src/mx_print_space_x_col.c \
	src/mx_print_space_col.c \


OUT = main.o \
	mx_clean_uls.o \
	mx_parse_flags.o \
	mx_get_sorted_flags.o \
	mx_printerr.o \
	mx_p_err_flag.o \
	mx_get_uls.o \
	mx_is_no_our_flags.o \
	mx_printerr_char.o \
	mx_get_root.o \
	mx_del_flag_dubl.o \
	mx_ret_clean_flag.o \
	mx_filter_flags.o \
	mx_del_dich_flags.o \
	mx_take_root.o \
	mx_push_root.o \
	mx_clean_root.o \
	mx_flags_to_int.o \
	mx_clean_file.o \
	mx_push_file.o \
	mx_get_files.o \
	mx_printend.o \
	mx_print_l.o \
	mx_ret_num_len_lld.o \
	mx_ret_num_len.o \
	mx_get_limits.o \
	mx_get_access.o \
	mx_get_flag_l.o \
	mx_flag_l_clean.o \
	mx_num_to_str.o \
	mx_get_hard_links.o \
	mx_get_user_name.o \
	mx_get_g_name.o \
	mx_lld_num_to_str.o \
	mx_get_size.o \
	mx_get_time.o \
	mx_print_total.o \
	mx_print_link.o \
	mx_get_min_maj.o \
	mx_push_dich.o \
	mx_clean_dich.o \
	mx_print_dich.o \
	mx_p_l.o \
	mx_push_file_light.o \
	mx_print_dich_inputs.o \
	mx_print_l_light.o \
	mx_get_last_u_names.o \
	mx_get_last_g_names.o \
	mx_get_files1.o \
	mx_push_file1.o \
	mx_print_c.o \
	mx_print_one.o \
	mx_print_space.o \
	mx_get_time_big.o \
	mx_print_ex_atr.o \
	mx_merge_sort.o \
	mx_split_f_b.o \
	mx_merge_sort_size.o \
	mx_merge_sort_status.o \
	mx_merge_sort_last_acc.o \
	mx_merge_sort_modification.o \
	mx_print_x.o \
	mx_merge_sort_r.o \
	mx_merge_sort_size_r.o \
	mx_merge_sort_status_r.o \
	mx_merge_sort_last_acc_r.o \
	mx_merge_sort_modification_r.o \
	mx_split_f_b_root.o \
	mx_merge_sort_root.o \
	mx_merge_sort_size_root.o \
	mx_merge_sort_status_root.o \
	mx_merge_sort_last_acc_root.o \
	mx_merge_sort_modification_root.o \
	mx_merge_sort_r_root.o \
	mx_merge_sort_size_r_root.o \
	mx_merge_sort_status_r_root.o \
	mx_merge_sort_last_acc_r_root.o \
	mx_merge_sort_modification_r_root.o \
	mx_print_space_x.o \
	mx_file_reverse.o \
	mx_root_reverse.o \
	mx_get_limits1.o \
	mx_print_main_nl.o \
	mx_main_rec.o \
	mx_get_files_rec.o \
	mx_print_main_nl_rec.o \
	mx_get_h.o \
	mx_get_h_pow.o \
	mx_add_h.o \
	mx_print_col.o \
	mx_print_c_col.o \
	mx_print_x_col.o \
	mx_get_access_col.o \
	mx_print_space_x_col.o \
	mx_print_space_col.o \

OUT1 = ./obj/main.o \
	./obj/mx_clean_uls.o \
	./obj/mx_parse_flags.o \
	./obj/mx_get_sorted_flags.o \
	./obj/mx_printerr.o \
	./obj/mx_p_err_flag.o \
	./obj/mx_get_uls.o \
	./obj/mx_is_no_our_flags.o \
	./obj/mx_printerr_char.o \
	./obj/mx_get_root.o \
	./obj/mx_del_flag_dubl.o \
	./obj/mx_ret_clean_flag.o \
	./obj/mx_filter_flags.o \
	./obj/mx_del_dich_flags.o \
	./obj/mx_take_root.o \
	./obj/mx_push_root.o \
	./obj/mx_clean_root.o \
	./obj/mx_flags_to_int.o \
	./obj/mx_clean_file.o \
	./obj/mx_push_file.o \
	./obj/mx_get_files.o \
	./obj/mx_printend.o \
	./obj/mx_print_l.o \
	./obj/mx_ret_num_len_lld.o \
	./obj/mx_ret_num_len.o \
	./obj/mx_get_limits.o \
	./obj/mx_get_access.o \
	./obj/mx_get_flag_l.o \
	./obj/mx_flag_l_clean.o \
	./obj/mx_num_to_str.o \
	./obj/mx_get_hard_links.o \
	./obj/mx_get_user_name.o \
	./obj/mx_get_g_name.o \
	./obj/mx_lld_num_to_str.o \
	./obj/mx_get_size.o \
	./obj/mx_get_time.o \
	./obj/mx_print_total.o \
	./obj/mx_print_link.o \
	./obj/mx_get_min_maj.o \
	./obj/mx_push_dich.o \
	./obj/mx_clean_dich.o \
	./obj/mx_print_dich.o \
	./obj/mx_p_l.o \
	./obj/mx_push_file_light.o \
	./obj/mx_print_dich_inputs.o \
	./obj/mx_print_l_light.o \
	./obj/mx_get_last_u_names.o \
	./obj/mx_get_last_g_names.o \
	./obj/mx_get_files1.o \
	./obj/mx_push_file1.o \
	./obj/mx_print_c.o \
	./obj/mx_print_one.o \
	./obj/mx_print_space.o \
	./obj/mx_get_time_big.o \
	./obj/mx_print_ex_atr.o \
	./obj/mx_merge_sort.o \
	./obj/mx_split_f_b.o \
	./obj/mx_merge_sort_size.o \
	./obj/mx_merge_sort_status.o \
	./obj/mx_merge_sort_last_acc.o \
	./obj/mx_merge_sort_modification.o \
	./obj/mx_print_x.o \
	./obj/mx_merge_sort_r.o \
	./obj/mx_merge_sort_size_r.o \
	./obj/mx_merge_sort_status_r.o \
	./obj/mx_merge_sort_last_acc_r.o \
	./obj/mx_merge_sort_modification_r.o \
	./obj/mx_split_f_b_root.o \
	./obj/mx_merge_sort_root.o \
	./obj/mx_merge_sort_size_root.o \
	./obj/mx_merge_sort_status_root.o \
	./obj/mx_merge_sort_last_acc_root.o \
	./obj/mx_merge_sort_modification_root.o \
	./obj/mx_merge_sort_r_root.o \
	./obj/mx_merge_sort_size_r_root.o \
	./obj/mx_merge_sort_status_r_root.o \
	./obj/mx_merge_sort_last_acc_r_root.o \
	./obj/mx_merge_sort_modification_r_root.o \
	./obj/mx_print_space_x.o \
	./obj/mx_file_reverse.o \
	./obj/mx_root_reverse.o \
	./obj/mx_get_limits1.o \
	./obj/mx_print_main_nl.o \
	./obj/mx_main_rec.o \
	./obj/mx_get_files_rec.o \
	./obj/mx_print_main_nl_rec.o \
	./obj/mx_get_h.o \
	./obj/mx_get_h_pow.o \
	./obj/mx_add_h.o \
	./obj/mx_print_col.o \
	./obj/mx_print_c_col.o \
	./obj/mx_print_x_col.o \
	./obj/mx_get_access_col.o \
	./obj/mx_print_space_x_col.o \
	./obj/mx_print_space_col.o \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@make -sC libmx
	@clang $(CFLAGS) -c $(SRCS) -I $(INCI)
	@mkdir -p obj
	@mv $(OUT) ./obj
	@clang $(CFLAGS) libmx/libmx.a $(OUT1) -o $(NAME)

uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)

clean:
	@make clean -sC libmx
	@rm -rf obj

reinstall: uninstall install
