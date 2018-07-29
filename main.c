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

static char	**check_flags(char **argv, int argc, t_main *main)
{
	int x;

	while ((x = ft_getopt(argv, "pqrtx")) != -1)
	{
		if (x == 'p')
			main->flags.p = true;
		if (x == 'q')
			main->flags.q = true;
		if (x == 'r')
			main->flags.r = true;
		if (x == 's')
			main->flags.s = true;
		// if (x == 'x')
		// 	main->flags.x = true;
	}
	argv += g_optint;
	argc -= g_optint;
	main->multargs = (argc <= 1) ? false : true;
	// main->argc = argc;
	return (argv);
}

void ft_ssl_md5(int argc, char **argv)
{
  t_main main;

  check_flags(argv, argc, &main);
  

}

void  check_args(int argc, char **argv)
{
  if (argc < 2)
  {
    write(2, "\nusage: ./ft_ssl [md5/sha512] [-pqrtx] [-s string] [files ...]\n", 31);
  	exit(1);
  }
  if (ft_strequ(argv[1], "md5"))
      ft_ssl_md5(argc, argv + 1);
  else
  {
    write (2, "wrong option\n", 13);
    exit (1);
  }
}

int main(int argc, char **argv)
{
  check_args(argc, argv);

  return (0);
}
