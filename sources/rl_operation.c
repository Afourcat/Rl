/*
** EPITECH PROJECT, 2017
** operation.c
** File description:
** operation for line
*/

#include "rl.h"

int delete_char(line_t *line, int size)
{
	if (size > 0) {
		line->cmd = realloc(line->cmd, size + 1);
		line->cmd[size] = 0;
		memmove(line->cmd + line->pos[X] - 1, 	\
			line->cmd + line->pos[X], 	\
			size - line->pos[X] + 1);
		le_move(line);
		INS_MODE;
		DEL_CHAR;
		EXIT_INS;
	}
	return (0);
}

int suppr_char(line_t *line, int size)
{
	if (size > 0) {
		line->cmd = realloc(line->cmd, size + 1);
		line->cmd[size] = 0;
		memmove(line->cmd + line->pos[X],
			line->cmd + line->pos[X] + 1,
			size - line->pos[X]);
		INS_MODE;
		DEL_CHAR;
		EXIT_INS;
	}
	return (0);
}

int add_char(line_t *line, int size, char buffer[3])
{
	if (!IS_VALID(buffer[0]))
		return (1);
	line->cmd = realloc(line->cmd, sizeof(char) * size + 2);
	memset(line->cmd + size, 0, 2);
	memmove(line->cmd + line->pos[X] + 1,
		line->cmd + line->pos[X],
		strlen(line->cmd + line->pos[X]));
	line->cmd[line->pos[X]] = buffer[0];
	line->pos[X]++;
	refresh(line);
	return (0);
}

int refresh(line_t *line)
{
	SAVE_CURSOR;
	DEL_LINE;
	CAR_RETURN;
	printf("%s%s", line->prompt, line->cmd);
	fflush(stdout);
	REC_CURSOR;
	MV_RIGHT;
	return (0);
}
