/*
** EPITECH PROJECT, 2017
** rl.c
** File description:
** readline lib
*/

#include "rl.h"

int my_out(int c)
{
	write(1, &c, 1);
	return (1);
}

static int init_term(struct termios term)
{
	char *name = getenv("TERM");

	if (!isatty(0))
		return (-1);
	if (tgetent(NULL, name) < 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}

static int event(line_t *line, char buffer[3])
{
	int size = strlen(line->cmd);

	switch (buffer[0]) {
	case RET:
		putchar('\n');
		return (1);
	case DEL:
		delete_char(line, size);
		break;
	default:
		handle_special_key(line, size, buffer);
		break;
	}
	return (0);
}

static int get_line(line_t *line)
{
	char buffer[3] = {0, 0, 0};
	char send = 0;

	while (!send) {
		memset(buffer, 0, 3);
		read(0, &buffer, 3);
		if (buffer[0] == 4)
			return (1);
		send = event(line, buffer);
	}
	return (0);
}

char *rl(const char *prompt)
{
	struct termios term;
	line_t *line = calloc(1, sizeof(line_t));
	line->prompt = strdup(prompt);
	line->cmd = strdup("");
	line->term = &term;
	
	if (init_term(term) == -1)
		return (NULL);
	printf("%s", prompt);
	fflush(stdout);
	if (get_line(line))
		return (NULL);
	return (line->cmd);
}

#ifdef RL_TEST
int main(void)
{
	char *line = NULL;

	while ((line = rl("[toto42sh]$> ")) != NULL) {
		puts(line);
		free(line);
	}
}
#endif /* RL_TEST */
