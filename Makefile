CC        = g++
CXXFLAGS  =-Wall -g

TARGET    =features
SRC       =features.cpp Image.cpp
OBJ       =$(SRC:.cpp=.o)
LIB  	  =lib/libnrc.a

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIB)

all: $(TARGET)

clean   :
	rm -f $(OBJ) $(TARGET)
