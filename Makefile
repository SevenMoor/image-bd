NAME      = features
SRC       = features.c
OBJ       = $(SRC:.c=.o)
CXXFLAGS  = -Wall -g
LIBFLAGS  = -Ilib/libnrc.a
CC        = gcc

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBFLAGS)

all: $(NAME)

clean   :
	rm -f $(OBJ) $(NAME)
