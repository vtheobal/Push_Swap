NAME		=	push_swap

NAME_B  	=	checker

SRCS		= 	ft_atoi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_split.c main.c\
				ft_list.c\
				ft_swap_function_1.c\
				ft_swap_function_2.c\
				ft_swap_function_3.c\
				ft_swap_function_4.c\
				ft_indexing.c\
				ft_sort_boll_1.c\
				ft_algo_three_five.c\
				ft_sort_big_1.c\
				ft_sort_big_2.c\

SRCS_B		= 	checker.c\
				checker_dop.c\
				ft_atoi.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_list.c\
				ft_swap_function_1_bonus.c\
				ft_swap_function_2_bonus.c\
				ft_swap_function_3_bonus.c\
				ft_swap_function_4.c\
				ft_indexing.c\
				ft_sort_boll_1.c\


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