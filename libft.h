/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:19:18 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 16:41:16 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_info
{
	int				flag[5];// 0->-, 1->+, 2->space, 3->0, 4->#
	int				field_width;// -1-> none, -2->*
	int				precision;//-1->none, -2->*
	int				lenght_modifier;// 1-> l, 2->ll, 3->h, 4->hh, 5->L, 0->none
	int				len;
}				t_info;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(long long n);
void			ft_putunbr(unsigned long long n);
size_t			ft_strlen(const char *str);
char			*ft_itoa(long long n);
char			*ft_uitoa(unsigned long long n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long long		ft_atoi(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_isalnum(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strndup(const char *s1, size_t n);
int				ft_isspace(int c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long long		power_of(long long nbr, int power);


int				ft_printf(const char *str, ...);
void			ft_putnstr(char *str, int n);
void			ft_putnspace(int n);
void			ft_signnbr(int nbr);
void			ft_spacenbr(int nbr);
int				ft_padding_char(unsigned int main, int side, char c, int *len);//1->right, 2->left
int				ft_padding_str(char *str, int side, char c, int len); //1->right, 2->left
int				ft_padding_nbr(long long nbr, int *flag, char *c); //1->right, 2->left
int				ft_padding_ptr(unsigned long int add, int side, char *c, int *len);//1->right, 2->left
int				ft_padding_oct(unsigned long long nbr, int *par, char c, char conv);//1->right, 2->left
int				ft_padding_ver(char *nbr, int *par, char *c);//1->right, 2->left
char			*ft_putoct(unsigned long long nbr);
char			*ft_puthexa(unsigned long long nbr, char c);//a->Lower, A->Upper
char			*ft_putpointer(unsigned long int point);
int				treat_c(va_list *ap, t_info *info);
int				treat_s(va_list *ap, t_info *info);
int				treat_p(va_list *ap, t_info *info);
int				treat_d(va_list *ap, t_info *info);// i as well
int				treat_ou(va_list *ap, t_info *info, char conv);
int				treat_f(va_list *ap, t_info *info);
char			*convert_dbl(double nbr);
char			*dic_bin(int nbr);
int				bin_dic(char *bin, int i);
char			*get_flt_ieee(float nbr);
char			*add_char(char *nbr1, char *nbr2);
char			*multi_char(char *nbr1, char *nbr2);
char			*multi1_char(char *nbr1, int nbr2);
char			*power_char(char *nbr1, int nbr2);
char			*get_dbl_ieee(double nbr);
char			*get_all(char *str, int ver, int ex);
char			*get_all_neg(char *str, int ver, int ex);
char			*get_ldbl_ieee(long double nbr);
void			reset_struct(t_info **info);
int				ft_putuchar(unsigned int i);
int				ft_putunichar(char *str);
int				ft_putustr(unsigned int *str);
int				ft_voidlen(unsigned int *src);
unsigned int	*ft_voidndup(unsigned int *str, int len);
int				treat_S(va_list *ap, t_info *info);
int				nbr_bytes(unsigned int c);
int				treat_per(va_list *ap, t_info *info);

#endif
