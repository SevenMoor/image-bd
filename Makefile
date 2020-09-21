NAME      = features
SRC       = Image.cpp
OBJ       = $(SRC:.cpp=.o)
CXXFLAGS  = -Wall -g
LIBFLAGS  = -Ilib/libnrc.a
CC        = g++

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBFLAGS)

all: $(NAME)

clean   :
	rm -f $(OBJ) $(NAME)
