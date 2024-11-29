
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_CIPHER = src/cipher.c

NAME_CIPHER = cipher

SRC_DECIPHER = src/decipher.c

NAME_DECIPHER = decipher

all: $(NAME_CIPHER) $(NAME_DECIPHER)

$(NAME_CIPHER): $(SRC_CIPHER)
	$(CC) $(CFLAGS) -o $(NAME_CIPHER) $(SRC_CIPHER)

$(NAME_DECIPHER): $(SRC_DECIPHER)
	$(CC) $(CFLAGS) -o $(NAME_DECIPHER) $(SRC_DECIPHER)

clean:
	rm -f $(NAME_CIPHER) $(NAME_DECIPHER)

re: clean all