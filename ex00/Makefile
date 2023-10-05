NAME		= btc
SRCS		= main.cpp BitcoinExchange.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADER = BitcoinExchange.hpp

%.o: %.cpp $(HEADER) 
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CPP			= c++
RM			= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
		@echo  "\n\t\t🤹 Compiling $(NAME)... \n" 
		$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)
		@echo "\n\t\t😱 Compiled   $(NAME)\n"

clean	:
		@echo "\n\t\t🙀 Removing object files...\n"
		$(RM) $(OBJS)

fclean	: 	clean
			@echo "\n\t\t🙀 Removing $(NAME)...\n"
			$(RM) $(NAME)  
			rm -rf ~/LIbrary/Caches

re		:fclean all
.PHONY: all clean fclean re