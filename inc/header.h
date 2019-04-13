#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct  c_comb {
    int         straight;
    int         flash;
    int         four;
    int         three;
    int         two_pairs;
    int         pair;
}               t_comb;

typedef struct  s_poker {
    int         err;
    char        **rank;
    int         *i_rank;
    char        **suit;
    t_comb      comb;
}               t_poker;

int     ft_strlen(const char *s);
void    ft_print_str(char *str);
char	*ft_strnew(size_t size);
char    *ft_strjoin(char const *s1, char const *s2);
int     ft_strcmp(const char *s1, const char *s2);

void    warning(int key, int i, t_poker *poker);
void    validate(int i, t_poker *poker);
void    convert_to_ints(t_poker *poker);
void    solution(t_poker *poker);
void	ft_sort_int_tab(int *tab, int size);

void    check_comb(t_poker *poker);
int     read_card(char *s, int i, t_poker *poker);

#endif
