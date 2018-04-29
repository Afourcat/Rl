##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=	.

LIB_DIR	=	.

SRC_DIR	=	sources

CC	=	gcc

BIN	=	example

NAME	=	librl.a

SRC	=	$(SRC_DIR)/rl.c			\
		$(SRC_DIR)/rl_operation.c	\
		$(SRC_DIR)/rl_move.c		\
		$(SRC_DIR)/ctrl_jump.c		\
		$(SRC_DIR)/ctrl_move.c		\
		$(SRC_DIR)/event_handler.c

WARN	=	-W -Wall -Wextra

CFLAGS	=	-I include $(WARN)

LDFLAGS	=	-l ncurses

TEST	?=	0

DEB	?=      0

G	=	-g

V	?=	@

B_MODE	=	-D RL_TEST

OBJS	=	$(SRC:.c=.o)

ifeq ($(DEB), 1)
	CFLAGS += $(G)
endif

ifeq ($(TEST), 1)
	CFLAGS	+= $(MACRO)
endif

#COLOR

GREEN	=	\e[1;32m

WHITE	=	\e[0m

ORANGE	=	\e[1;33m

RED	=	\e[1;35m

BLUE	=	\e[1;34m

$(LIB_DIR)/$(NAME): 	CFLAGS	= -I include $(WARN)
$(BIN):			CFLAGS	= -I include $(WARN) -D RL_TEST

all:			$(LIB_DIR)/$(NAME)

$(LIB_DIR)/$(NAME):	$(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)ar rc -o $(LIB_DIR)/$(NAME) $(OBJS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BIN):			fclean $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $@ $(OBJS) $(CFLAGS) $(LDFLAGS)

%.o:			%.c
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			$(V)rm -rf $(OBJS)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:			clean
			$(V)rm -f $(LIB_DIR)/$(NAME)
			$(V)rm -f $(BIN)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:			fclean
			$(V)make --no-print-directory all

echo_debug:
			$(V)if [ $(DEB) == 1 ]; then\
				printf "$(RED)Debug mode initialized.$(WHITE)\n";\
			fi

.PHONY: clean fclean debug all re echo_build echo_debug buildrepo
