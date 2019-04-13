#include "header.h"

int     read_card(char *s, int i, t_poker *poker) {
    int j = -1;
    int k = 0;

    while (s[++j] != '\0') {
        if (s[j + 1] == '\0') {
            poker->suit[i][0] =s[j];
        }
        else {
            poker->rank[i][k++] = s[j];
        }
    }
    poker->rank[i][k] = '\0';
    poker->suit[i][1] = '\0';
    return 1;
}

void    check_straight_flash(t_poker *poker) {
    int i = -1;
    int count = 0;

    while(++i < 5) {
        if (count == 3 && poker->i_rank[3] == 5 && poker->i_rank[4] == 14) {
            count++;
        }
        else if (poker->i_rank[i] + 1 == poker->i_rank[i + 1]) {
            count++;
        }
    }
    (count == 4) ? poker->comb.straight = 1 : 0;
    count = 0;
    i = -1;
    while (++i <= 4) {
        if (ft_strcmp(poker->suit[i], poker->suit[4]) == 0) {
            count++;
        }
    }
    (count == 5) ? poker->comb.flash = 1 : 0;
}

void    assign_combs(int count, t_poker *poker) {
    (count == 3) ? poker->comb.four = 1 : 0;
    (count == 2) ? poker->comb.three = 1 : 0;
    if (poker->comb.pair && count == 1) {
        poker->comb.two_pairs = 1;
    }
    else {
       (count == 1) ? poker->comb.pair = 1 : 0;
    }
}

void    check_doubles(int *tab, t_poker *poker) {
    int tmp = 0;
    int tmp1 = 0; 
    int count = 0;

    for(int i = 0; i < 4; i++) {
        tmp = tab[i];
        count = 0;
        for(int j = i + 1; j < 5; j++) {
            if(tmp == tab[j] && tmp != tmp1) {
                count++;
            }
        }
        if (count) {
            tmp1 = tmp;
            assign_combs(count, poker);
        }
    }
}


void     check_comb(t_poker *poker) {
    convert_to_ints(poker);
    check_doubles(poker->i_rank, poker);
    ft_sort_int_tab(poker->i_rank, 5);
    check_straight_flash(poker);
}
