/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:12:58 by mawinter          #+#    #+#             */
/*   Updated: 2022/04/18 15:12:24 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*infobuf[FD_SIZE];
	char		*line;
	int			linelen;

	if (setup(&linelen, fd, &line, infobuf))
		return (NULL);
	if (get_idx_read(infobuf[fd], 0) == 0)
		readnew(infobuf[fd], buf, fd);
	while (0 < get_idx_read(infobuf[fd], -1))
	{
		while (get_idx_read(infobuf[fd], 0) < get_idx_read(infobuf[fd], -1))
		{					
			line = join_line(infobuf[fd], line, &linelen);
			if (!line)
				return (NULL);
			if (line[linelen - 1] == '\n')
				return (line);
		}
		readnew(infobuf[fd], buf, fd);
	}
	free(infobuf[fd]);
	infobuf[fd] = NULL;
	return (line);
}
