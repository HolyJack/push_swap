# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 19:14:01 by ejafer            #+#    #+#              #
#    Updated: 2022/03/11 04:10:56 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	push_swap

SRC_DIR		=	
OBJ_DIR		=	obj/


HDR			=	
LIBFT_HDR	=	


SRC_NAMES	=   push_swap data list1 list2 array error validation sort_small sort_big sort_big_push_back find_sorted_subseq list_steps rotate  find_min find_med find_max ft_atoi ft_strncmp ft_memset ft_split ft_strlcpy ft_strlen ft_memcpy ft_isdigit

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))
D_FILES 	=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_NAMES)))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
OPFLAGS		=	-O2

RM      	=	rm -f
AR			=	ar rcs
MK			=	mkdir -p

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OPFLAGS) $(OBJ) -o $(NAME)


$(OBJ):	$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
			@${MK} ${OBJ_DIR}
			$(CC) $(CFLAGS) $(OPFLAGS) -c $< -o $@	-MD

include $(wildcard $(D_FILES))

clean:
			@$(RM) $(OBJ) $(D_FILES)

fclean:	clean
			@$(RM) $(NAME)

re:	fclean all

.PHONY: re fclean clean bonus all
