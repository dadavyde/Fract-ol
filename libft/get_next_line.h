/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:41:11 by dadavyde          #+#    #+#             */
/*   Updated: 2018/01/11 18:41:13 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_node
{
	char			*str;
	int				fd;
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);
int					check_line(char **line, char *str, t_node *rest_of_line);
int					read_file(char **line, t_node **begin,
					t_node **rest_of_line);
int					free_list(char **line, int ret, t_node **begin,
					t_node **rest_of_line);

#endif
