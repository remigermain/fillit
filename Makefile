# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/01/31 19:16:33 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra

INCLUDE	=	-Iincludes

HEADER	=	fillit.h color.h

SRC		=	main.c main_manager.c checkfiles.c lst_init.c \
			resolve_manager.c utils.c

OBJ		=	$(SRC:.c=.o)

DSRC	=	
DOBJ	=
DHEADER	=	
PATH_ALL = $(DOBJ)

CSRC	=	$(addprefix $(DSRC), $(SRC))
COBJ	=	$(addprefix $(DOBJ), $(OBJ))
CHEADER	=	$(addprefix $(DHEADER), $(HEADER))

all: $(NAME)

$(NAME): $(COBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(INCLUDE) $(LIBFT) $? -o $(NAME)
	@echo "Compilation de l'executable" $(NAME)

$(PATH_ALL):
	@mkdir -p $(DOBJ)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) | $(PATH_ALL)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compilation des objects "$<

clean:
	@rm -rf $(COBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Suppresion de l'executble "$(NAME)

re: fclean all

.PHONY: all clean fclean re
