/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:28:19 by gaesteve          #+#    #+#             */
/*   Updated: 2023/09/10 19:54:05 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

typedef struct s_tab
{
	char	*str_nbr;
	char	*str_let;
}		t_tab;

char			*ft_strtrim(char const *s1, char const *set);
char			*dict_to_string(ssize_t len);
char			*ft_strdup(char *src, int start, int end);
char			**ft_split(char *str, char *charset);
void			print_tab(char **tab);
void			ft_putstr(char *str);
void			manage_split(char **tab);
int				dict_len(void);
int				is_sep(char c, char *charset);
int				count_word(char *str, char *charset);

#endif
