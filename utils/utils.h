/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:17:26 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 19:16:11 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int			data;
	int				check;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(long content);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
int				ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *s, int c, size_t len);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif