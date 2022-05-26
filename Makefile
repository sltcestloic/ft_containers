# Properties

NAME				:= ft_containers
STL_NAME			:= stl_containers
FT_OUT				:= out_ft.diff
STL_OUT				:= out_stl.diff

# Commands

override CPPC		:= clang++
override CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98 -g3
override RM			:= rm -rf

# Sources

override SRCS		:=							\
				main.cpp						\

override HEADERS	:=							\
				iterator.hpp					\
				utils.hpp						\
				vector.hpp						\
				stack.hpp						\

# Rules

all:		$(NAME) $(STL_NAME)

$(NAME):	$(SRCS) $(HEADERS)
			$(CPPC) $(CPPFLAGS) -Iincludes -o $@ $(SRCS)

$(STL_NAME):	$(SRCS) $(HEADERS)
			$(CPPC) $(CPPFLAGS) -Iincludes -DSTL_CONTAINERS -o $@ $(SRCS)

clean:
			$(RM) $(FT_OUT) $(STL_OUT)

fclean:		clean
			$(RM) $(NAME) $(STL_NAME)

re:			fclean all

ft_test:	$(NAME)
			./$(NAME) > $(FT_OUT)
			./$(NAME)

stl_test:	$(STL_NAME)
			./$(STL_NAME) > $(STL_OUT)

test:		stl_test ft_test
			diff out_ft.diff out_stl.diff

.PHONY:		all clean fclean re test ft_test stl_test