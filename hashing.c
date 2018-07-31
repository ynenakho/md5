/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:12:08 by ynenakho          #+#    #+#             */
/*   Updated: 2018/07/29 18:12:16 by ynenakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

size_t hash(char *input)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *input++))
        hash = ((hash << 5) + hash) + c;

    return (hash);
}

t_funcs  dictSearch(struct s_dict *dict, char *key)
{
  size_t index;
  struct s_item *tmp;

  if (dict->capacity <= 0)
    return (NULL);
  index = hash(key) % dict->capacity;
  tmp = dict->items[index];
  while (tmp)
  {
    if (strcmp(tmp->key, key) == 0)
      return (tmp->func);
    tmp = tmp->next;
  }
  return (NULL);
}

struct s_dict *dictInit(int capacity)
{
  struct s_dict *dict;

  if (capacity <= 0)
    return (NULL);
  dict = (struct s_dict *)malloc(sizeof(struct s_dict));
  dict->capacity = capacity;
  dict->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity);
  if (!dict->items)
    return (NULL);
  bzero(dict->items, sizeof(struct s_item *) * capacity);
  return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, t_funcs   func)
{
  struct s_item *item;
  struct s_item *head;
  size_t index;

  if (dict->capacity <= 0)
    return (0);
  item = (struct s_item *)malloc(sizeof(struct s_item));
  if (!item)
    return (0);
  bzero(item, sizeof(struct s_item));
  item->key = key;
  item->func = func;
  item->next = NULL;
  index = hash(key) % dict->capacity;
  if (dict->items[index])
  {
    head = dict->items[index];
    while (head->next)
      head = head->next;
    head->next = item;
}
else
  dict->items[index] = item;
  return (1);
}
