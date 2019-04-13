#include "header.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i = 0;;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < (size + 1))
		*(str + i++) = '\0';
	*(str + i) = '\0';
	return (str);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i = 0;
	size_t	j = 0;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void   ft_print_str(char *str) {
    int i = -1;

    while (str[++i]) {
        write(1, &str[i], 1);
    }
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& (unsigned char)s1 != '\0' && (unsigned char)s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
