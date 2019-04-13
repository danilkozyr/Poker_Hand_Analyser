#include <header.h>

void    run(char *s, int i, t_poker *poker) {
    poker->rank[i] = malloc(sizeof(char) * ft_strlen(s));
    poker->suit[i] = malloc(sizeof(char) * ft_strlen(s));
    poker->err = 0;
    read_card(s, i, poker);
    validate(i, poker);
    if (poker->err == 1)
        exit(1);
}

void    init(t_poker *poker) {
    poker->comb.straight = 0;
    poker->comb.flash = 0;
    poker->comb.four = 0;
    poker->comb.three = 0;
    poker->comb.two_pairs = 0;
    poker->comb.pair = 0;
}

int     main(int ac, char **av) {
    int i = 0;
    t_poker *poker;

    if (ac == 6) {
        poker = malloc(sizeof(t_poker));
        poker->rank = (char **)malloc(sizeof(char *) * 5);
        poker->suit = (char **)malloc(sizeof(char *) * 5);
        poker->i_rank = (int *)malloc(sizeof(int) * 5);
        init(poker);
        while (++i < ac)
            run(av[i], i - 1, poker);
        check_comb(poker);
        solution(poker);
    }
    else
        warning(0, 0, NULL);
    return 1;
}
