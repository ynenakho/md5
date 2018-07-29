/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:17:46 by ynenakho          #+#    #+#             */
/*   Updated: 2018/05/08 14:17:48 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include "libft/libft.h"
# include <stdbool.h>

typedef void		(*t_funcs)(int , char **);

typedef struct s_flags
{
  bool  s;
  bool  q;
  bool  p;
  bool  r;
}               t_flags;

typedef struct s_main
{
  int orig_len;
  int cur_len;
  uint8_t *msg;
  t_flags flags;
  bool  multargs;
}              t_main;

extern int g_optint;

int			ft_getopt(char **argv, char *optstr);

#endif
