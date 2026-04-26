# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/26 03:31:28 by ide-dieg          #+#    #+#              #
#    Updated: 2026/04/26 04:10:16 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cipher_lib.a

SRC =	César_cipher.c \
		César_decipher.c \
		César_break.c \
		Vigenère_cipher.c \
		Vigenère_decipher.c \
		Vigenère_break.c \

CC = cc
AR = ar

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "█";

all: $(NAME)

$(NAME): pipex_title $(OBJ)
	@echo "$(NARANJA)Building $(NAME)...$(NC)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ);
	@tput cuu1 && tput el
	@echo "$(VERDE)$(NAME) built!$(NC)"

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJ)
	@echo "Objects cleaned!"

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re: fclean $(NAME)

ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m
AZUL = \033[0;34m
VERDE = \033[0;32m

pipex_title:
	@echo "  ___  __  ____  _  _  ____  ____        __    __  ____  "
	@echo " / __)(  )(  _ \/ )( \(  __)(  _ \      (  )  (  )(  _ \ "
	@echo "( (__  )(  ) __/) __ ( ) _)  )   / ____ / (_/\ )(  ) _ ( "
	@echo " \___)(__)(__)  \_)(_/(____)(__\_)(____)\____/(__)(____/ "
