NAME = libmx.a

INCI = inc/libmx.h

SRCS = src/mx_printchar.c \
	src/mx_strlen.c \
	src/mx_printstr.c \
	src/mx_strcmp.c \
	src/mx_strdel.c \
	src/mx_strnew.c \
	src/mx_strcpy.c \
	src/mx_strdup.c \
	src/mx_strcat.c \
	src/mx_memcmp.c \
	src/mx_del_strarr.c \
	src/mx_nbr_to_hex.c \
	src/mx_printint.c \
	src/mx_pow.c \

OUT = mx_printchar.o \
	mx_strlen.o \
	mx_printstr.o \
	mx_strcmp.o \
	mx_strdel.o \
	mx_strnew.o \
	mx_strcpy.o \
	mx_strdup.o \
	mx_strcat.o \
	mx_memcmp.o \
	mx_del_strarr.o \
	mx_nbr_to_hex.o \
	mx_printint.o \
	mx_pow.o \

OUT1 = obj/mx_printchar.o \
	obj/mx_strlen.o \
	obj/mx_printstr.o	\
	obj/mx_strcmp.o \
	obj/mx_strdel.o \
	obj/mx_strnew.o \
	obj/mx_strcpy.o \
	obj/mx_strdup.o \
	obj/mx_strcat.o \
	obj/mx_memcmp.o \
	obj/mx_del_strarr.o \
	obj/mx_nbr_to_hex.o \
	obj/mx_printint.o \
	obj/mx_pow.o \

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@clang $(CFLAGS) -c $(SRCS) -I $(INCI)
	@mkdir -p obj
	@mv $(OUT) ./obj
	@ar -rcs $(NAME) $(OUT1)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf obj

reinstall: uninstall install
