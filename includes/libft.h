/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:47:37 by leaugust          #+#    #+#             */
/*   Updated: 2024/09/16 15:34:54 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <assert.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*LIBFT*/

char	**ft_split(char const *s, char c);

/*PRINTF*/

int		ft_printf(const char *format, ...);
void	ft_ifchr(char c);
void	ft_ifint(int value, int *output);
int		ft_ifstr(char *value, int *output);
void	ft_ifptr(unsigned long long value, int *output);
void	ft_ifudi(unsigned int value, int *output);
void	ft_ifhex(unsigned int value, const char c, int *output);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

/*GNL*/

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*set_line(char *line_buffer);
char	*fill_line_buffer(int fd, char *buffer, char *stash);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*initialize_buf(int fd, char **stash);

#endif