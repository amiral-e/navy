##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC_DIR 	:= ./src/

# navy #
SRC_NAMES	:= main.c
SRC_NAMES	+= free.c

# game #
SRC_NAMES	+= game/attack_defend/attack_defend.c
SRC_NAMES	+= game/attack_defend/check.c
SRC_NAMES	+= game/getline/getline.c
SRC_NAMES	+= game/getline/check.c
SRC_NAMES	+= game/game.c

# init #
SRC_NAMES	+= init/map/map.c
SRC_NAMES	+= init/map/check.c
SRC_NAMES	+= init/boat/boat.c
SRC_NAMES	+= init/boat/check.c

# print #
SRC_NAMES	+= print/print.c
SRC_NAMES	+= print/usage.c

# sig #
SRC_NAMES	+= sig/connection.c
SRC_NAMES	+= sig/reception.c
SRC_NAMES	+= sig/sending.c

SRC			:= $(addprefix $(SRC_DIR), $(SRC_NAMES))
#------other------#
OBJ			:= $(SRC:.c=.o)
INC			:= -iquote ./include/
LIB			:= -L lib/ -l:m_files.a -l:m_printf.a
### SOURCES ###


### COMPILE_USEFULL ###
#----general_usefull----#
CC			=	gcc
#----project_usefull----#
NAME		=	navy
MAKEFLAGS 	+=	--no-print-directory
CFLAGS		:=	-Wall -Wextra
#CFLAGS		+=	-Werror
CFLAGS		+=	$(INC) $(LIB)
CFLAGS		+=	-g3
### COMPILE_USEFULL ###


### COLORS ###
ccred		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\033[0m"
ccyellow	= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\033[0m"
ccend		= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\033[0m"
### COLORS ###


all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -sC lib/
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)
			@$(call ccend, "Project successfully compiled.")

clean:
			$(MAKE) -sC lib/ clean
			$(RM) -rf $(OBJ) *.gc* *.o vgcore.*
			@$(call ccyellow, "Project cleaned.")

fclean:		clean
			$(MAKE) -sC lib/ fclean
			$(RM) -rf $(NAME) a.out
			@$(call ccred, "Project fully cleaned.")

re:			fclean all

.PHONY:		all clean fclean re