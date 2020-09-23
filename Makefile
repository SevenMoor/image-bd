CC       =g++
CXXFLAGS  =-Wall -g

TARGET    =features
SRC       =features.cpp Image.cpp Matrix.cpp ImagePGM.cpp ImagePPM.cpp
OBJ       =$(SRC:.cpp=.o)
LIB  	  =lib/libnrc.a

$(TARGET) : $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIB)

all: $(TARGET)

clean   :
	rm -f $(OBJ) $(TARGET)
