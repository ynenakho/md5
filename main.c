/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:17:21 by ynenakho          #+#    #+#             */
/*   Updated: 2018/05/08 14:17:28 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void  check_args(int argc, char **argv, t_dict *dict)
{
  if (argc < 2)
  {
    write(2, "usage: ./ft_ssl [md5/sha512] [-pqrt] [-s string] [files ...]\n", 61);
  	exit(1);
  }
	if (!dictSearch(dict, argv[1]))
  {
    write (2, "wrong option\n", 13);
    exit (1);
  }
}

t_dict *make_dict()
{
	t_dict *dict;
	dict = dictInit(1);

	dictInsert(dict, "md5", &ft_ssl_md5);
//	dictInsert(dict, "sha256", &ft_ssl_sha256);
	return(dict);
}

int main(int argc, char **argv)
{
	t_funcs func;
	t_dict *dict;

	dict = make_dict();
  check_args(argc, argv, dict);
	func = dictSearch(dict, argv[1]);
	func(argc, argv);

  return (0);
}
