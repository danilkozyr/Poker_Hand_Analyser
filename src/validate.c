#include "header.h"

void    validate_suits(int i, t_poker *poker) {
    if (!(ft_strcmp(poker->suit[i], "H") == 0 ||
        ft_strcmp(poker->suit[i], "C") == 0 ||
        ft_strcmp(poker->suit[i], "S") == 0 ||
        ft_strcmp(poker->suit[i], "D") == 0)) {
            poker-> err = 1;
            warning(2, i, poker);
        }
}

void    validate_ranks(int i, t_poker *poker) {
    if (!(ft_strcmp(poker->rank[i], "2") == 0 ||
        ft_strcmp(poker->rank[i], "3") == 0 ||
        ft_strcmp(poker->rank[i], "4") == 0 ||
        ft_strcmp(poker->rank[i], "5") == 0 ||
        ft_strcmp(poker->rank[i], "6") == 0 ||
        ft_strcmp(poker->rank[i], "7") == 0 ||
        ft_strcmp(poker->rank[i], "8") == 0 ||
        ft_strcmp(poker->rank[i], "9") == 0 ||
        ft_strcmp(poker->rank[i], "10") == 0 ||
        ft_strcmp(poker->rank[i], "J") == 0 ||
        ft_strcmp(poker->rank[i], "Q") == 0 ||
        ft_strcmp(poker->rank[i], "K") == 0 ||
        ft_strcmp(poker->rank[i], "A") == 0)) {
        poker->err = 1;
        warning(1, i, poker);
    }
}

void    validate_duplicates(int i, t_poker *poker) {
    int j = -1;

    while (++j < i) {
        if (ft_strcmp(poker->rank[i], poker->rank[j]) == 0 &&
            ft_strcmp(poker->suit[i], poker->suit[j]) == 0) {
            poker->err = 1;
            warning(3, 0, NULL);
        }
    }
}

void     validate(int i, t_poker *poker) {
    validate_suits(i, poker);
    validate_ranks(i, poker);
    if (i > 0) {
        validate_duplicates(i, poker);
    }
}
