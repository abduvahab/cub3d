# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:02:27 by averon            #+#    #+#              #
#    Updated: 2022/12/05 11:59:32 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = 	cub3d.c 						\
		configure.c						\
		casting.c						\
		draw_and_text.c					\
		draw_and_text2.c				\
		key_hook.c						\
		key_hook_details.c				\
		get_next_line.c					\
		get_next_line_utils.c			\
		parsing/ctrl_map.c				\
		parsing/ctrl_map_border.c		\
		parsing/ctrl_file_and_init.c	\
		parsing/parsing_map.c			\
		parsing/parsing_deco.c			\
		parsing/parsing_utils.c			\
		parsing/parsing_tab_int.c		\
		parsing/utils.c					\
		mini_map.c						\
	
OBJS = $(SRCS:.c=.o)

HEADERS = ./ -I /usr/X11/include
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LIB = -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all :		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(HEADERS) -Imlx_linux -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -Lmlx_linux -Imlx_linux  -lm -lz libft.a -o $(NAME) 
 
clean :
			$(RM) $(OBJS)
			$(RM) libft.a

fclean:		clean
			make -C ./libft fclean	
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 