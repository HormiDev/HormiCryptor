/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vigenère_cipher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:02:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/26 03:54:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cipher_lib.h"

void	vigenere_cipher(char *str, const char *key, int str_len)
{
	int	i;
	int	j;
	int	key_len;

	if (!str || !key)
		return;
	key_len = strlen(key);
	i = 0;
	j = 0;
	while (i < str_len)
	{
		str[i] += key[j];
		i++;
		j++;
		if (j >= key_len)
			j = 0;
	}
}
