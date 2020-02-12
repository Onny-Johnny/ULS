#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdlib.h>

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void mx_del_strarr(char ***arr);
char *mx_nbr_to_hex(unsigned long nbr);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);

#endif
