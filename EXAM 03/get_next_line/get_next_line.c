# include <unistd.h>
# include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s || s == NULL)
		return (0);
	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c > 255)
		c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *b, char *s, int count)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s) + BUFFER_SIZE) + 1);
	if (tab == 0)
		return (0);
	while (s && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	while (b[j])
	{
		tab[i + j] = b[j];
		b[j] = 0;
		j++;
	}
	tab[i + j] = 0;
	if (count > 0)
		free(s);
	return (tab);
}

void	ft_save(char *s, char *b)
{
	int	j;

	j = 0;
	while (s[j])
	{
		b[j] = s[j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		b[j] = 0;
		j++;
	}
}

char	*ft_cut(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (s[i] != '\n' || s[i] == 0)
		i++;
	if (s[i] == '\n' || s[i] == 0)
		i++;
	tab = malloc (i + 1);
	while (j < i)
	{
		tab[j] = s[j];
		j++;
	}
	tab[j] = 0;
	i = 0;
	while (s[j])
	{
		j++;
	}
	ft_save(&s[ft_strchr(s, '\n')], b);
	free(s);
	return (tab);
}

char	*ft_finish(char *s)
{
	if (s[0] == 0)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*stash;
	static char	buffer[BUFFER_SIZE + 1];
	static int	count;
	int			n;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = BUFFER_SIZE;
	if (count > 0)
		stash = ft_strjoin(buffer, stash, count);
	while (ft_strchr(stash, '\n') == 0 && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		if (n < 0)
			return (NULL);
		stash = ft_strjoin(buffer, stash, count++);
	}
	if (ft_strchr(stash, '\n') > 0)
		return (ft_cut(stash, buffer));
	else if (n == 0)
		return (ft_finish(stash));
	return (0);
}

