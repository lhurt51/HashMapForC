/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:31:56 by lhurt             #+#    #+#             */
/*   Updated: 2017/03/20 17:31:58 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

# define HASHSIZE 101

typedef struct			s_hashlst
{
	char				*name; /* name that is defined */
	char				*defn; /* replacement bits */
	struct s_hashlst	*next;
}						t_hashlst;

static t_hashlst		*hashtab[HASHSIZE]; /* pointer table */

#endif
