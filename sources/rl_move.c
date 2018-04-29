/*
** EPITECH PROJECT, 2017
** rl_move.c
** File description:
** move
*/

#include "rl.h"

int ri_move(line_t *line)
{
	if (line->pos[X] < strlen(line->cmd)) {
		MV_RIGHT;
		line->pos[X]++;
		return (1);
	}
	return (0);
}

int le_move(line_t *line)
{
	if (line->pos[X] > 0) {
		MV_LEFT;
		line->pos[X]--;
		return (1);
	}
	return (0);
}
