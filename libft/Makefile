# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schibane <schibane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 16:16:24 by schibane          #+#    #+#              #
#    Updated: 2023/12/10 17:32:14 by schibane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =    libft.a
CC_Flags           =    gcc  -Wall -Wextra -Werror
 
SRCS            =   ft_isalpha.c    ft_isdigit.c    ft_strlen.c     ft_tolower.c    ft_toupper.c    ft_strncmp.c	ft_memset.c\
                    ft_isalnum.c    ft_isascii.c	ft_isprint.c	ft_strlcpy.c	ft_strlcat.c	ft_strchr.c		ft_strrchr.c\
					ft_memcpy.c		ft_substr.c		ft_memmove.c	ft_bzero.c		ft_memchr.c		ft_memcmp.c		ft_strnstr.c\
					ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_strcmp.c	\
					ft_itoa.c		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_all_isalphanum.c ft_memory.c

SRCS_BONUS		= 	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c		ft_lstsize_bonus.c		ft_lstlast_bonus.c		ft_lstadd_back_bonus.c\
					ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c		ft_lstmap_bonus.c

OBJS            = $(SRCS:.c=.o)

OBJS_BONUS      = $(SRCS_BONUS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	
fclean: clean
	rm -rf $(NAME)
	
clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	
re: fclean all

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: all fclean clean re bonus

