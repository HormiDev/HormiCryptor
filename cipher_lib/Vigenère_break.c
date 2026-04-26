/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vigenère_break.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:02:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/26 03:54:09 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_lib.h"

static int	search_key_len(const char *patron_key)
{
	int	len;
	int	key_len;
	int	posible_repeat;
	int	repeat_count;

	len = strlen(patron_key);
	key_len = 1;
	while (key_len < len)
	{
		posible_repeat = len / key_len;
		repeat_count = 0;
		while (repeat_count < posible_repeat)
		{
			if (strncmp(patron_key, patron_key + repeat_count * key_len, key_len) != 0)
				break ;
			repeat_count++;
		}
		if (repeat_count == posible_repeat)
		{
			if (strncmp(patron_key, patron_key + repeat_count * key_len, len % key_len) != 0)
			return (key_len);
		}
		key_len++;
	}
	return (len);
}

char	*vigenere_break(const char *o_str, const char *c_str, int len)
{
	char	*patron_key;
	char	*key;

	int		key_len;
	int		i;

	if (!o_str || !c_str)
		return (0);
	patron_key = malloc(sizeof(char) * (len + 1));
	if (!patron_key)
		return (0);
	i = 0;
	while (i < len)
	{
		patron_key[i] = c_str[i] - o_str[i];
		i++;
	}
	patron_key[len] = '\0';
	key_len = search_key_len(patron_key);
	key = malloc(sizeof(char) * (key_len + 1));
	if (!key)
	{
		free(patron_key);
		return (0);
	}
	strncpy(key, patron_key, key_len);
	key[key_len] = '\0';
	free(patron_key);
	return (key);
}
