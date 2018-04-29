#!/bin/bash

gcc \
ctrl_move.c ctrl_jump.c rl.c event_handler.c rl_move.c rl_operation.c \
-I ../include/ -Wall -Wextra -g -l ncurses -D RL_TEST
