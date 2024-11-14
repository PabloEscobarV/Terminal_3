/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:39:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/14 14:13:33 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../libft/libft.h"
#include "../../E_Codes/e_codes.h"
#include <stdlib.h>
#include <stdio.h>

int	cmp_strv(const char *str, const char **spltrs)
{
	while (*spltrs && !ft_strlcmp(str, *spltrs))
		++spltrs;
	return (ft_strlen(*spltrs));
}

void  clear_llist_void(void *data)
{

}

int	get_str_crd(const char *str, t_crd *crd, const char **spltrs)
{
	int	i;

	while (crd->i < crd->size)
	{
		i = cmp_strv(str + crd->i, spltrs);
		if (i)
			break ;
    ++crd->i;
	}
  return (i);
}

char  *get_str(const char *str, t_crd *crd, const char **spltrs)
{
  int   i;
  int   tmp;
  char  *result;

  tmp = crd->i;
  i = get_str_crd(str, crd, spltrs);
  if (tmp < crd->i)
    result = ft_strldup(str + tmp, crd->i - tmp);
  else
    result = NULL;
  crd->i += i;
  return (result);
}

t_llist *get_data_list(const char *str, t_crd *crd, const char **spltrs)
{
  char    *tmp;
  t_llist *llst;

  llst = NULL;
  while (crd->i < crd->size)
  {
    tmp = get_str(str, crd, spltrs);
    if (tmp)
      llistadd_back(&llst, llistnewnode(tmp));
  }
  return (llst);
}

char  **get_strv_from_llst(t_llist *llst)
{
  int   sizev;
  char  **strv;

  sizev = llistsize(llst);
  if (!sizev)
    return (NULL);
  strv = malloc((sizev + 1) * sizeof(char *));
  if (!strv)
  {
    ft_perror("ERROR!!! Bad mammory allocation");
    exit(E_ERR);
  }
  strv[sizev] = NULL;
  sizev = 0;
  while (llst)
  {
    strv[sizev] = llst->data;
    ++sizev;
    llst = llst->next;
  }
  return (strv);
}

char	**splitter(const char *str, const char **spltrs)
{
  char    **strv;
  t_llist *llst;
  t_crd   crd;

  if (!str || !spltrs)
    return (NULL);
  crd.i = 0;
  crd.size = ft_strlen(str);
  llst = get_data_list(str, &crd, spltrs);
  strv = get_strv_from_llst(llst);
  llistclear(&llst, ft_void);
  return (strv);
}
