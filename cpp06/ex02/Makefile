NAME = Serialization

INCS        := include

SRC		=	main.cpp \
			src/Base.cpp

OBJS 	= $(SRC:.c=.o)


CC 		= c++
FLAGS	= -std=c++98 -Wall -Wextra -Werror 
CPPFLAGS    := $(addprefix -I,$(INCS))

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(CPPFLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re