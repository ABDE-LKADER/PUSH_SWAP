# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/02/18 15:42:31 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		=	mandatory/parse_in.c \
				mandatory/push_swap.c \
				mandatory/best_move.c  \
				mandatory/sort_tools.c  \
				mandatory/actions_sp.c   \
				mandatory/actions_ro.c    \
				mandatory/check_errors.c   \

NAME_BONUS	=	checker
SRCS_BONUS	=	bonus/checker_bonus.c  \
				bonus/parse_in_bonus.c  \
				bonus/actions_sp_bonus.c \
				bonus/actions_ro_bonus.c  \
				bonus/check_errors_bonus.c \

OBJS 		=	$(SRCS:.c=.o)
OBJS_BONUS 	=	$(SRCS_BONUS:.c=.o)

HEADER		=	mandatory/push_swap.h
HD_BONUS	=	bonus/push_swap_bonus.h

MYHD		=	MYLIB/mylib.h
MYLB		=	MYLIB

FLGS 		=	cc -Wall -Wextra -Werror
RM			=	rm -f

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: $(MYLB) $(NAME)
	@echo $(GREEN)Done !!$(RESET)

bonus: $(MYLB) $(NAME_BONUS)
	@echo $(GREEN)Done !!$(RESET)

$(MYLB):
	@make -C MYLIB --no-print-directory

$(NAME): $(OBJS)
	@$(FLGS) $^ -L $(MYLB) -l ar -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(FLGS) $^ -L $(MYLB) -l ar -o $(NAME_BONUS)

$(OBJS): %.o: %.c $(MYHD) $(HEADER)
	@$(FLGS) -c -I $(MYLB) $< -o $@

$(OBJS_BONUS): %.o: %.c $(MYHD) $(HD_BONUS)
	@$(FLGS) -c -I $(MYLB) $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C MYLIB
	@echo $(YELOW)Done !!$(RESET)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C MYLIB
	@echo $(REDCL)Done !!$(RESET)

re: fclean all

.PHONY: $(MYLB)
