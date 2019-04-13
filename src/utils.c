#include "header.h"

void     warning(int key, int i, t_poker *poker) {
    if (key == 0) {
        ft_print_str("usage: ./race03 [card1] [card2] [card3] [card4] [card5]");
    }
    if (key == 1) {
        ft_print_str("Invalid card rank: ");
        ft_print_str(poker->rank[i]);
    }
    if (key == 2) {
        ft_print_str("Invalid card suit: ");
        ft_print_str(poker->suit[i]);
    }
    if (key == 3) {
        ft_print_str("Error: duplicate cards");
    }
    ft_print_str("\n");
}

void    solution(t_poker *poker) {
    if (poker->comb.flash && poker->comb.straight && poker->i_rank[0] == 10)
        ft_print_str("Royal flush\n");
    else if (poker->comb.flash && poker->comb.straight)
        ft_print_str("Straight flush\n");
    else if (poker->comb.four == 1)
        ft_print_str("Four of a kind\n");
    else if (poker->comb.three == 1 && poker->comb.pair == 1)
        ft_print_str("Full house\n");
    else if (poker->comb.flash)
        ft_print_str("Flush\n");
    else if (poker->comb.straight)
        ft_print_str("Straight\n");
    else if (poker->comb.three == 1)
        ft_print_str("Three of a kind\n");
    else if (poker->comb.two_pairs == 1)
        ft_print_str("Two pair\n");
    else if (poker->comb.pair == 1)
        ft_print_str("One pair\n");
    else
        ft_print_str("No pair\n");
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i = -1;
	int	j = -1;
	int				temp;

	while (++i < (size - 1)) {
		j = -1;
		while (++j < (size - i - 1)) {
			if (tab[j] > tab[j + 1]) {
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}

void    convert_to_ints(t_poker *poker) {
    int i = -1;

    while (++i < 5) {
        (ft_strcmp(poker->rank[i], "2") == 0) ? poker->i_rank[i] = 2 : 0;
        (ft_strcmp(poker->rank[i], "3") == 0) ? poker->i_rank[i] = 3 : 0;
        (ft_strcmp(poker->rank[i], "4") == 0) ? poker->i_rank[i] = 4 : 0;
        (ft_strcmp(poker->rank[i], "5") == 0) ? poker->i_rank[i] = 5 : 0;
        (ft_strcmp(poker->rank[i], "6") == 0) ? poker->i_rank[i] = 6 : 0;
        (ft_strcmp(poker->rank[i], "7") == 0) ? poker->i_rank[i] = 7 : 0;
        (ft_strcmp(poker->rank[i], "8") == 0) ? poker->i_rank[i] = 8 : 0;
        (ft_strcmp(poker->rank[i], "9") == 0) ? poker->i_rank[i] = 9 : 0;
        (ft_strcmp(poker->rank[i], "10") == 0) ? poker->i_rank[i] = 10 : 0;
        (ft_strcmp(poker->rank[i], "J") == 0) ? poker->i_rank[i] = 11 : 0;
        (ft_strcmp(poker->rank[i], "Q") == 0) ? poker->i_rank[i] = 12 : 0;
        (ft_strcmp(poker->rank[i], "K") == 0) ? poker->i_rank[i] = 13 : 0;
        (ft_strcmp(poker->rank[i], "A") == 0) ? poker->i_rank[i] = 14 : 0;
    }
}
