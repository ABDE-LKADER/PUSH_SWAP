# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 17:23:22 by abadouab          #+#    #+#              #
#    Updated: 2024/04/19 19:36:26 by abadouab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		=	mandatory/parse_in.c \
				mandatory/push_swap.c \
				mandatory/best_move.c  \
				mandatory/sort_tools.c  \
				mandatory/lon_in_sub.c   \
				mandatory/actions_sp.c    \
				mandatory/actions_ro.c     \
				mandatory/check_errors.c    \

NAME_BONUS	=	checker
SRCS_BONUS	=	bonus/checker_bonus.c  \
				bonus/parse_in_bonus.c  \
				bonus/sort_tools_bonus.c \
				bonus/actions_sp_bonus.c  \
				bonus/actions_ro_bonus.c   \
				bonus/check_errors_bonus.c  \

OBJS 		=	$(SRCS:.c=.o)
OBJS_BONUS 	=	$(SRCS_BONUS:.c=.o)

HEADER		=	mandatory/push_swap.h
HD_BONUS	=	bonus/push_swap_bonus.h

MYAR		=	MYLIB/libar.a
MYLB		=	MYLIB

FLGS 		=	cc -Wall -Wextra -Werror
RM			=	rm -fr

GREEN		=	"\033[1;32m"
YELOW 		=	"\033[1;33m"
REDCL 		=	"\033[1;31m"
RESET 		=	"\033[0m"

all: start $(MYLB) $(NAME) finish

bonus: start $(MYLB) $(NAME_BONUS) finish

start:
	@printf "\n"
	@echo $(GREEN)"Starting build..."
	@sleep 1
	@printf "Loading [ "

finish:
	@echo $(GREEN) ] 100%$(RESET)
	@echo $(GREEN)Project built.$(RESET)
	@printf "\n"

$(MYLB):
	@make -C $(MYLB) --no-print-directory

$(NAME): $(OBJS)
	@$(FLGS) $^ -L $(MYLB) -l ar -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(FLGS) $^ -L $(MYLB) -l ar -o $(NAME_BONUS)

$(OBJS): %.o: %.c $(MYAR) $(HEADER)
	@$(FLGS) -c -I $(MYLB) $< -o $@
	@printf $(GREEN)"."$(RESET)

$(OBJS_BONUS): %.o: %.c $(MYAR) $(HD_BONUS)
	@$(FLGS) -c -I $(MYLB) $< -o $@
	@printf $(GREEN)"."$(RESET)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(MYLB) --no-print-directory
	@echo $(YELOW)Cleaning up 🧹💫$(RESET)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C $(MYLB) --no-print-directory
	@echo $(REDCL)Purging all files 🗑️$(RESET)

re: fclean all

.PHONY: $(MYLB)
