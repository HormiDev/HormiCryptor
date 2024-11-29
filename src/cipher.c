
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int		in_file;
	char	*buffer;
	char	*key;
	int		key_len;
	int 	out_file;
	int		i;
	int		read_bytes;
	char	*out_file_name;

	if (argc != 3)
	{
		write(2, "Usage: <file> <key>\n", 20);
		return 1;
	}
	in_file = open(argv[1], O_RDONLY);
	if (in_file < 0)
	{
		write(2, "Error: cannot open file\n", 24);
		return 1;
	}
	out_file_name = malloc(strlen(argv[1]) + 5);
	if (out_file_name == NULL)
	{
		write(2, "Error: cannot allocate memory\n", 30);
		close (in_file);
		return 1;
	}
	strcpy(out_file_name, argv[1]);
	strcat(out_file_name, ".enc");
	if (out_file_name == NULL)
	{
		write(2, "Error: cannot allocate memory\n", 30);
		close (in_file);
		return 1;
	}
	out_file = open(out_file_name, O_WRONLY | O_CREAT, 0666);
	free(out_file_name);
	if (out_file < 0)
	{
		write(2, "Error: cannot create file\n", 26);
		close (in_file);
		free(out_file_name);
		return 1;
	}
	key = argv[2];
	key_len = strlen(key);
	buffer = malloc(key_len);
	if (buffer == NULL)
	{
		write(2, "Error: cannot allocate memory\n", 30);
		close (in_file);
		close (out_file);
		free(out_file_name);
		return 1;
	}
	read_bytes = read(in_file, buffer, key_len);
	while (read_bytes > 0)
	{
		i = 0;
		while (i < read_bytes)
		{
			buffer[i] += key[i];
			i++;
		}
		write(out_file, buffer, read_bytes);
		read_bytes = read(in_file, buffer, key_len);
	}
	free(buffer);
	close(in_file);
	close(out_file);
	printf("File %s has been encrypted\n", argv[1]);
	unlink(argv[1]);
	return 0;
}