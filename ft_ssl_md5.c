/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:39:53 by ynenakho          #+#    #+#             */
/*   Updated: 2018/07/30 13:39:58 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void check_flags(char **argv, int argc, t_main *main)
{
	int x;

  main->flags.p = false;
  main->flags.q = false;
  main->flags.r = false;
  main->flags.s = false;
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
	}
	argc -= g_optint;
	main->multargs = (argc <= 2) ? false : true;
}

uint8_t *msg_bits_padding(t_main *main)
{
  uint8_t		*msg;
  uint64_t	bits_len;

  main->len = main->orig_len * 8 + 1;
  while (main->len % 512 != 448)
    (main->len)++;
  main->len /= 8;
  msg = ft_memalloc(main->len + 64);
  ft_memcpy(msg, main->orig_msg, main->orig_len);
  msg[main->orig_len] = 128;
  bits_len = 8 * main->orig_len;
  ft_memcpy(msg + main->len, &bits_len, 8);
  return (msg);
}

void handle_string(char *str, t_main *main)
{
  main->orig_msg = str;
  main->orig_len = ft_strlen(str);
  main->msg = msg_bits_padding(main);


}

void ft_ssl_md5(int argc, char **argv)
{
  t_main main;
  int i = 2;

  check_flags(argv, argc, &main);

  while(argv[i])
  {
    if (ft_strequ(argv[i], "-s"))
    {
      handle_string(argv[++i], &main);
    }
    else if (argv[i][0] == '-' && argv[i][1] == 's')
    {
      handle_string(&argv[i][2], &main);
    }
    i++;
  }
  	ft_printf("Msg: %s, Len: %d\n", main.orig_msg, main.orig_len);
    write(1, main.msg, 64);
}
