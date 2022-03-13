# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 19:14:01 by ejafer            #+#    #+#              #
#    Updated: 2022/03/11 22:53:32 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	push_swap
BONUS		= 	checker

SRC_DIR		=	src/
OBJ_DIR		=	obj/

HDR			=	./push_swap.h

SRC_NAMES	=   push_swap parser data list1 list2\
				array error validation sort_small\
				sort_big sort_big_push_back sort_big_rotation\
				find_sorted_subseq list_steps rotate  find_min\
				find_med find_max ft_atoi ft_strncmp ft_memset\
				ft_split ft_strlcpy ft_strlen ft_memcpy\
				ft_putstr_fd ft_isdigit is_sorted

SRC_NAMES_BONUS	=	checker parser list1 list2 list_steps error\
					array validation ft_split find_min data ft_strlen\
					ft_memset ft_strncmp ft_strlcpy ft_atoi ft_memcpy\
					ft_isdigit get_next_line get_next_line_utils\
					ft_putstr_fd is_sorted

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))
D_FILES 	=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_NAMES)))

SRC_BONUS		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES_BONUS)))
OBJ_BONUS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES_BONUS)))
D_FILES_BONUS	=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_NAMES_BONUS)))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
OPFLAGS		=	-O2

RM      	=	rm -f
AR			=	ar rcs
MK			=	mkdir -p

all: $(NAME)

$(NAME): $(OBJ)
			$(CC) $(CFLAGS) $(OPFLAGS) $(OBJ) -o $(NAME)

bonus: ${OBJ_BONUS}
			$(CC) $(CFLAGS) $(OPFLAGS) $(OBJ_BONUS) -o $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
			@${MK} ${OBJ_DIR}
			$(CC) $(CFLAGS) $(OPFLAGS) -c -I . $< -o $@	-MD

include $(wildcard $(D_FILES))

clean:
			@$(RM) $(OBJ) $(D_FILES)
			@$(RM) $(OBJ_BONUS) $(D_FILES_BONUS)

fclean:	clean
			@$(RM) $(NAME)
			@${RM} $(BONUS)

re:	fclean all

.PHONY: re fclean clean bonus all
