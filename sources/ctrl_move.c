/*
** EPITECH PROJECT, 2017
** ctrl_move.c
** File description:
** movement from ctrl
*/

#include "rl.h"

int go_end(line_t *line, int size)
{
	while (line->pos[X] < (unsigned int) size)
		ri_move(line);
	MV_LEFT;
	refresh(line);
	return (0);
}

int go_begin(line_t *line)
{
	while (line->pos[X] > 0)
		le_move(line);
	MV_LEFT;
	refresh(line);
	return (0);
}

int delete_from_cursor(line_t *line)
{
	int len_new = line->pos[X];

	copy_from_cursor(line);
	MV_LEFT;
	line->cmd = realloc(line->cmd, len_new + 1);
	line->cmd[len_new] = 0;
	refresh(line);
	return (0);
}

int copy_from_cursor(line_t *line)
{
	int len_new = strlen(line->cmd + line->pos[X]);

	free(line->cpy_buffer);
	line->cpy_buffer = calloc(len_new + 1, sizeof(char));
	memcpy(line->cpy_buffer, line->cmd + line->pos[X], len_new);
	MV_LEFT;
	refresh(line);
	return (0);
}

int paste_from_cursor(line_t *line, int size)
{
	int len_cpy = strlen(line->cpy_buffer);
	int len_new = len_cpy + size;

	line->cmd = realloc(line->cmd, len_new + 1);
	line->cmd[len_new] = 0;
	memmove(line->cmd + line->pos[X] + len_cpy,
		line->cmd + line->pos[X],
		strlen(line->cmd + line->pos[X]));
	memcpy(line->cmd + line->pos[X],
		line->cpy_buffer,
		len_cpy);
	MV_LEFT;
	for (int i = 0; i < len_cpy; ++i)
		ri_move(line);
	refresh(line);
	return (0);
}
