##
## Makefile for makefile in /home/paskal/rendu/System_Unix/PSU_2016_philo/
##
## Made by Paskal Arzel
## Login   <paskal.arzel@epitech.eu>
##
## Started on  Mon Mar  6 15:33:06 2017 Paskal Arzel
## Last update Sun May  7 02:24:53 2017 Paskal Arzel
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"
BLUE		=	"\033[0;34m"

DIR_INC = ./include/
DIR_SRC = ./src/
DIR_INIT = ./src/init/
DIR_PARS = ./src/parser/
DIR_SON = ./src/son/
DIR_FTH = ./src/father/
DIR_PRT = ./src/print/
DIR_SOLO = ./src/solo/
DIR_NM = ./src/nm/
DIR_NMI = ./src/nm/nm_init/

SRC 	=	$(DIR_SRC)ftrace.c \
			$(DIR_SRC)separator.c \
      $(DIR_INIT)init.c \
			$(DIR_PARS)parser.c \
			$(DIR_SON)ftrace_son.c \
			$(DIR_FTH)ftrace_father.c \
			$(DIR_FTH)father_setinsck.c \
			$(DIR_FTH)father_delfrsck.c \
			$(DIR_PRT)print_less.c \
			$(DIR_PRT)print_full.c \
			$(DIR_PRT)print_numbers.c \
			$(DIR_PRT)print_string.c \
			$(DIR_PRT)find_fct.c \
			$(DIR_NM)nm.c \
			$(DIR_NM)sort.c \
			$(DIR_NM)sym.c \
			$(DIR_NM)set_fctnames.c \
			$(DIR_NM)find_dyn.c \
			$(DIR_NMI)init_longname.c \
			$(DIR_NMI)init.c \
			$(DIR_NMI)init_dyn.c \
			$(DIR_NMI)set_base.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

RM	=	rm -f

CFLAGS	+=	-Wextra \
		-Wall \
		-Werror \
		-O3 \
		-I$(DIR_INC)

LDFLAGS +=	-L./lib

NAME	= ftrace

all:	message $(NAME)

message:
	@$(ECHO) $(BLUE) "::::::::: ::::::::::: :::::::::      :::      ::::::::  :::::::::: " $(DEFAULT)
	@$(ECHO) $(BLUE) ":+:           :+:     :+:    :+:   :+: :+:   :+:    :+: :+:        " $(DEFAULT)
	@$(ECHO) $(BLUE) "+:+           +:+     +:+    +:+  +:+   +:+  +:+        +:+        " $(DEFAULT)
	@$(ECHO) $(BLUE) "+#++:++       +#+     +#++:++#:  +#++:++#++: +#+        +#++:++#   " $(DEFAULT)
	@$(ECHO) $(BLUE) "+#+           +#+     +#+    +#+ +#+     +#+ +#+        +#+        " $(DEFAULT)
	@$(ECHO) $(BLUE) "#+#           #+#     #+#    #+# #+#     #+# #+#    #+# #+#        " $(DEFAULT)
	@$(ECHO) $(BLUE) "###           ###     ###    ### ###     ###  ########  ########## " $(DEFAULT)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) ./$(NAME)

re:		fclean all

.c.o:
		@gcc $(CFLAGS) $(LDFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re libmy getch $(NAME) .c.o message
