/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:32:08 by lhurt             #+#    #+#             */
/*   Updated: 2017/03/20 17:32:10 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

/* hash: orm hash value for string s */
unsigned int	hash(char *s)
{
	unsigned int	hval;

	hval = 0;
	while (*s != '\0')
	{
		hval = *s + 31 * hval;
		s++;
	}
	return (hval % HASHSIZE);
}

/* lookup: look for s in hashtab */
t_hashlst	*lookup(char *s)
{
	t_hashlst	*lst;

	lst = hashtab[hash(s)];
	while (lst != NULL)
	{
		if (strcmp(s, lst->name) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

// char	*mystrdup(char *);

/* install: put (name, defn) in hashtab */
t_hashlst	*install(char *name, char *defn)
{
	t_hashlst		*lst;
	unsigned int	hval;

	if ((lst = lookup(name)) == NULL)
	{
		lst = malloc(sizeof(t_hashlst));
		if (lst == NULL || (lst->name = ft_strdup(name)) == NULL)
			return (NULL);
		hval = hash(name);
		lst->next = hashtab[hval];
		hashtab[hval] = lst;
	}
	else
		free((void *) lst->defn);
	if ((lst->defn = ft_strdup(defn)) == NULL)
		return (NULL);
	return (lst);
}

void	add(t_hashlst **bgnlst, t_hashlst *new)
{
	new->next = *bgnlst;
	*bgnlst = new;
}

int		main(void)
{
	t_hashlst	*tmp;

	install("hello", "niceeeee man");
	install("elloh", "This is great");
	install("code", "if this equals that");
	install("for", "for loops are great wish i could use them");
	tmp = lookup("hello");
	if (tmp != NULL)
		printf("Name: %s, Def: %s\n", tmp->name, tmp->defn);
	tmp = lookup("elloh");
	if (tmp != NULL)
		printf("Name: %s, Def: %s\n", tmp->name, tmp->defn);
	install("elloh", "Diffenrent Def");
	tmp = lookup("elloh");
	if (tmp != NULL)
		printf("Name: %s, Def: %s\n", tmp->name, tmp->defn);
	tmp = lookup("code");
	if (tmp != NULL)
		printf("Name: %s, Def: %s\n", tmp->name, tmp->defn);
	tmp = lookup("for");
	if (tmp != NULL)
		printf("Name: %s, Def: %s\n", tmp->name, tmp->defn);
	return (1);
}
