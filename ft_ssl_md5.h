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
  int len;
  char *orig_msg;
  uint8_t *msg;
  t_flags flags;
  bool  multargs;
}              t_main;

extern int g_optint;
extern int g_s[64];
extern int g_k[64];



struct s_item {
  char           *key;
  t_funcs   func;
  struct s_item  *next;
};

typedef struct s_dict {
  struct s_item **items;
  int           capacity;
}             t_dict;


// DICTIONNARY

size_t hash(char *input); //return hash result
t_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(t_dict *dict, char *key, t_funcs   func); //add one element in the dictionnary, if FAIL return 0, otherwise 1
t_funcs   dictSearch(t_dict *dict, char *key); //find one element in the dictionnary, if not found, return NULL

// main

void ft_ssl_md5(int argc, char **argv);
int			ft_getopt(char **argv, char *optstr);

#endif
