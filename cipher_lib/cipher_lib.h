/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 03:13:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/26 03:55:01 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIPHER_H
#define CIPHER_H

#include <string.h>
#include <stdlib.h>

void	cesar_cipher(char *str, int shift, int str_len);
void	cesar_decipher(char *str, int shift, int str_len);
int		cesar_break(char original, char chipher);

void	vigenere_cipher(char *str, const char *key, int str_len);
void	vigenere_decipher(char *str, const char *key, int str_len);
char	*vigenere_break(const char *o_str, const char *c_str, int len);

#endif