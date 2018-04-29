/*
** EPITECH PROJECT, 2017
** rl.h
** File description:
** realine header
*/

#ifndef RL_H_
#define RL_H_

#define Y 0
#define X 1

#define DEL	127
#define CTR_ALT	59
#define CTRL_DEL 8
#define TAB	9
#define ESC	27
#define RET	10
#define UP	65
#define DOWN	66
#define RIGHT	67
#define LEFT	68
#define CTRL_K	11
#define CTRL_E	5
#define CTRL_A	1
#define CTRL_Y	25
#define SUPPR	126
#define IS_VALID(x) ((x) >= ' ' && (x) <= '~')

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Function
#define CLEAR 		tputs(tgetstr("cl", NULL), 1, &my_out)
#define MV_RIGHT 	tputs(tgetstr("nd", NULL), 1, &my_out)
#define MV_LEFT 	tputs(tgetstr("le", NULL), 1, &my_out)
#define SAVE_CURSOR 	tputs(tgetstr("sc", NULL), 1, &my_out)
#define REC_CURSOR	tputs(tgetstr("rc", NULL), 1, &my_out)
#define DEL_LINE	tputs(tgetstr("dl", NULL), 1, &my_out)
#define CAR_RETURN 	tputs(tgetstr("cr", NULL), 1, &my_out)
#define INS_MODE 	tputs(tgetstr("im", NULL), 1, &my_out)
#define DEL_CHAR 	tputs(tgetstr("dc", NULL), 1, &my_out)
#define EXIT_INS 	tputs(tgetstr("ei", NULL), 1, &my_out)

struct line_s {
	char *prompt;
	char *cmd;
	char *cpy_buffer;
	struct termios *term;
	unsigned int pos[2];
};

typedef struct line_s line_t;

line_t *create_struct(const char *prompt, struct termios *term);

//Move
int ri_move(line_t *line);
int le_move(line_t *line);

//Operation
int refresh(line_t *line);
int add_char(line_t *line, int size, char buffer[3]);
int delete_char(line_t *line, int size);
int delete_left_word(line_t *line, int size);
int suppr_char(line_t *line, int size);
int my_out(int c);

//Event
int handle_multi(line_t *line, int size, char buffer[3]);
int handle_special_key(line_t *line, int size, char buffer[3]);
int get_arrow(line_t *line, char buff);
int go_end(line_t *line, int size);
int go_begin(line_t *line);
int delete_from_cursor(line_t *line);
int copy_from_cursor(line_t *line);
int paste_from_cursor(line_t *line, int size);
int do_ctrl_move(line_t *line, int size, char buffer[3]);

#endif /* RL_H_ */
