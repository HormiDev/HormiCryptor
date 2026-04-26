/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   César_decipher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:50:09 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/26 01:13:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cesar_decipher(char *str, int shift, int str_len)
{
	int	i;

	if (!str)
		return;
	i = 0;
	while (i < str_len)
	{
		str[i] -= shift;
		i++;
	}
}
