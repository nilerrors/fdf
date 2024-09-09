/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:01:02 by senayat           #+#    #+#             */
/*   Updated: 2024/07/20 17:40:33 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_add_to_str(t_str *s1, const t_str s2)
{
	int		i;
	int		j;
	t_str	str;

	i = 0;
	j = 0;
	str = (t_str)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!str)
		return ((void)(*s1 = NULL));
	while ((*s1)[i] != '\0')
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(*s1);
	*s1 = str;
}

static void	ft_read_file(int fd, t_str *buf)
{
	int		read_size;
	t_str	tmp;

	if (!*buf)
		return ;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return ;
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size < 0)
			return ((void)(ft_set_free(
					(t_data *)&tmp) || ft_set_free((t_data *)buf)));
		tmp[read_size] = 0;
		ft_add_to_str(buf, tmp);
		if (ft_char_in_str('\n', tmp))
			break ;
	}
	ft_set_free((t_data *)&tmp);
}

static void	ft_update_buf(t_str *buf)
{
	size_t	i;
	size_t	j;
	t_str	line;

	if (!*buf)
		return ;
	i = 0;
	j = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if (!(*buf)[i])
		return ((void)ft_set_free((t_data *)buf));
	line = ft_calloc(ft_strlen(*buf) - i + 1, sizeof(char));
	if (!line)
		return ((void)ft_set_free((t_data *)buf));
	while ((*buf)[++i])
		line[j++] = (*buf)[i];
	ft_set_free((t_data *)buf);
	*buf = line;
}

t_str	get_next_line(int fd)
{
	return (get_next_line_with_abort(fd, FALSE));
}

t_str	get_next_line_with_abort(int fd, t_bool abort)
{
	static t_str	buf[TOTAL_FD];
	t_str			line;

	if (abort)
	{
		ft_set_free((t_data *)&buf[fd]);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > TOTAL_FD)
		return (NULL);
	if (!buf[fd])
		buf[fd] = ft_calloc(1, sizeof(char));
	if (!buf[fd])
		return (NULL);
	ft_read_file(fd, &buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_extract_line(buf[fd]);
	if (!line)
	{
		ft_set_free((t_data *)&buf[fd]);
		return (NULL);
	}
	ft_update_buf(&buf[fd]);
	return (line);
}
