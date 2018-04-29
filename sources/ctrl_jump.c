/*
** EPITECH PROJECT, 2017
** ctrl_jump.c
** File description:
** ctrl jump function
*/

#include "rl.h"

int delete_left_word(line_t *line, int size)
{
	if (size > 0 && line->pos[X] > 0) {
		do {
			delete_char(line, size);
		} while(line->pos[X] > 0 && line->cmd[line->pos[X] - 1] != ' ');
	}
	return (0);
}

int delete_right_word(line_t *line, int size)
{
	do {
		ri_move(line);
	} while (line->pos[X] < (unsigned int) size &&
				line->cmd[line->pos[X]] != ' ');
	return (0);
}

static int jump_left(line_t *line)
{
	do {
		le_move(line);
	} while(line->pos[X] > 0 && line->cmd[line->pos[X] - 1] != ' ');
	return (0);
}

static int jump_right(line_t *line, int size)
{
	do {
		ri_move(line);
	} while (line->pos[X] < (unsigned int) size &&
				line->cmd[line->pos[X]] != ' ');
	return (0);
}

int do_ctrl_move(line_t *line, int size, char buffer[3])
{
	switch (buffer[2]) {
	case LEFT:
		return (jump_left(line));
	case RIGHT:
		return (jump_right(line, size));
	default:
		return (1);
	}
}
