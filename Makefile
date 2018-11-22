# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/21 16:28:47 by alepercq    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	fillit

CFLAGS	=	-Wall -Werror -Wextra

INCLUDE	=	-Iincludes

HEADER	=	fillit.h color.h

SRC		=	main.c main_manager.c checkfiles.c lst_init.c \
			tab_manager.c tab_utils.c \
			algo_manager.c algo_u_init.c algo_u_find.c algo_u_remove.c \
			algo_utils.c utils.c algo_valid.c

OBJ		=	$(SRC:.c=.o)

DSRC	=	
DOBJ	=	obj/
DHEADER	=	
PATH_ALL = $(DOBJ)

CSRC	=	$(addprefix $(DSRC), $(SRC))
COBJ	=	$(addprefix $(DOBJ), $(OBJ))
CHEADER	=	$(addprefix $(DHEADER), $(HEADER))

all: $(NAME)

$(NAME): $(COBJ)
	@make -C libft/ 
	@gcc -o3 $(CFLAGS) $(INCLUDE) $(LIBFT) $? -o $(NAME)
	@echo "Compilation de l'executable" $(NAME)

$(PATH_ALL):
	@mkdir -p $(DOBJ)

#$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
#	@mkdir -p $(DOBJ)
$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) | $(PATH_ALL)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Compilation des objects "$<

clean:
	@rm -rf $(DOBJ)
	@Make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@Make -C libft/ fclean
	@echo "Suppresion de l'executble "$(NAME)

re: fclean all

.PHONY: all clean fclean re
