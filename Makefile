#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := cc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c \
                          src/gnl/get_next_line.c \
                          src/gnl/get_next_line_utils.c \
                          src/libft/ft_atoi.c \
                          src/libft/ft_bzero.c \
                          src/libft/ft_calloc.c \
                          src/libft/ft_isalnum.c \
                          src/libft/ft_isalpha.c \
                          src/libft/ft_isascii.c \
                          src/libft/ft_isdigit.c \
                          src/libft/ft_isprint.c \
                          src/libft/ft_itoa.c \
                          src/libft/ft_lstadd_back.c \
                          src/libft/ft_lstadd_front.c \
                          src/libft/ft_lstclear.c \
                          src/libft/ft_lstdelone.c \
                          src/libft/ft_lstiter.c \
                          src/libft/ft_lstlast.c \
                          src/libft/ft_lstmap.c \
                          src/libft/ft_lstnew.c \
                          src/libft/ft_lstsize.c \
                          src/libft/ft_memchr.c \
                          src/libft/ft_memcmp.c \
                          src/libft/ft_memcpy.c \
                          src/libft/ft_memmove.c \
                          src/libft/ft_memset.c \
                          src/libft/ft_putchar_fd.c \
                          src/libft/ft_putendl_fd.c \
                          src/libft/ft_putnbr_fd.c \
                          src/libft/ft_putstr_fd.c \
                          src/libft/ft_split.c \
                          src/libft/ft_strchr.c \
                          src/libft/ft_strdup.c \
                          src/libft/ft_striteri.c \
                          src/libft/ft_strjoin.c \
                          src/libft/ft_strlcat.c \
                          src/libft/ft_strlcpy.c \
                          src/libft/ft_strlen.c \
                          src/libft/ft_strmapi.c \
                          src/libft/ft_strncmp.c \
                          src/libft/ft_strnstr.c \
                          src/libft/ft_strrchr.c \
                          src/libft/ft_strtrim.c \
                          src/libft/ft_substr.c \
                          src/libft/ft_tolower.c \
                          src/libft/ft_toupper.c \
                          src/map.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


