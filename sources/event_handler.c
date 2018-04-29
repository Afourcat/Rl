/*
** EPITECH PROJECT, 2017
** event_handler.c
** File description:
** event handling
*/

#include "rl.h"

int handle_multi(line_t *line, int size, char buffer[3])
{
	switch(buffer[0]) {
	case CTR_ALT:
		if (buffer[1] == 53)
			do_ctrl_move(line, size, buffer);
		break;
	case CTRL_E:
		return (go_end(line, size));
	case CTRL_A:
		return (go_begin(line));
	case CTRL_K:
		return (delete_from_cursor(line));
	case CTRL_Y:
		return (paste_from_cursor(line, size));
	default:
		if (buffer[1] == 0 && buffer[2] == 0)
			add_char(line, size, buffer);
	}
	return (0);
}

int handle_special_key(line_t *line, int size, char buffer[3])
{
	switch (buffer[0]) {
	case SUPPR:
		suppr_char(line, size);
		break;
	case ESC:
		if (buffer[1] == 91)
			get_arrow(line, buffer[2]);
		else if (buffer[1] == DEL)
			delete_left_word(line, size);
		break;
	case TAB:
		//Auto-Complete
		break;
	default:
		handle_multi(line, size, buffer);
	}
	return (0);
}

int get_arrow(line_t *line, char buff)
{
	switch (buff) {
	case UP:
		//Historique <-
		break;
	case DOWN:
		//Historique ->
		break;
	case RIGHT:
		ri_move(line);
		break;
	case LEFT:
		le_move(line);
		break;
	}
	return (0);
}
