
CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = cipher_lib/cipher_lib.a

SRC_CIPHER = src/cipher.c

NAME_CIPHER = cipher

SRC_DECIPHER = src/decipher.c

NAME_DECIPHER = decipher

all: build_cipher_lib $(NAME_CIPHER) $(NAME_DECIPHER)

$(NAME_CIPHER): $(SRC_CIPHER)
	$(CC) $(CFLAGS) -o $(NAME_CIPHER) $(SRC_CIPHER) $(LIBS)

$(NAME_DECIPHER): $(SRC_DECIPHER)
	$(CC) $(CFLAGS) -o $(NAME_DECIPHER) $(SRC_DECIPHER) $(LIBS)

build_cipher_lib:
	@if [ ! -f cipher_lib/cipher_lib.a ]; then \
		echo "$(NARANJA)Compiling Cipher Lib...$(NC)"; \
		make all -C cipher_lib > /dev/null 2>&1; \
		tput cuu1 && tput el; \
		echo "$(VERDE)Cipher Lib compiled!$(NC)"; \
	fi

fclean_cipher_lib:
	@echo "Cleaning Cipher Lib..."
	@make fclean -C cipher_lib > /dev/null 2>&1
	@echo "Cipher Lib cleaned!"

clean: fclean_cipher_lib

fclean: clean
	rm -f $(NAME_CIPHER) $(NAME_DECIPHER)

re: clean all