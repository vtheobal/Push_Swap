NAME		=	push_swap

NAME_B  	=	checker

SRCS		= 	src/main.c\
				src/ft_atoi.c\
				src/ft_putchar_fd.c\
				src/ft_putstr_fd.c\
				src/ft_split.c\
				src/ft_list.c\
				src/ft_swap_function_1.c\
				src/ft_swap_function_2.c\
				src/ft_swap_function_3.c\
				src/ft_swap_function_4.c\
				src/ft_indexing.c\
				src/ft_sort_boll_1.c\
				src/ft_algo_three_five.c\
				src/ft_sort_big_1.c\
				src/ft_sort_big_2.c\

SRCS_B		= 	src/checker.c\
				src/checker_dop.c\
				src/ft_atoi.c\
				src/ft_putchar_fd.c\
				src/ft_putstr_fd.c\
				src/ft_split.c\
				src/ft_list.c\
				src/ft_swap_function_1_bonus.c\
				src/ft_swap_function_2_bonus.c\
				src/ft_swap_function_3_bonus.c\
				src/ft_swap_function_4.c\
				src/ft_indexing.c\
				src/ft_sort_boll_1.c\


OBJS		= 	$(patsubst %.c,%.o,$(SRCS))

OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	push_swap.h

RM			= 	rm -rf

all: 			$(NAME)

$(OBJS): $(INCLUDES)
$(OBJS_B): $(INCLUDES)

$(NAME): 		$(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME_B): 		$(OBJS_B)
				@$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B)	

bonus:			$(NAME_B)			

clean:
				@${RM} $(OBJS) $(OBJS_B)

fclean:			
				@${RM} $(OBJS) $(OBJS_B) $(NAME) $(NAME_B)

re:				fclean all

.PHONY:			all clean fclean re bonus