CC        = g++
CXXFLAGS  =-Wall -g

TARGET    = out
SRC       =main.cpp Image.cpp Matrix.cpp ImagePGM.cpp ImagePPM.cpp FileExporter.cpp DBFacade.cpp
OBJ       =$(SRC:.cpp=.o)
LIB  	    =lib/libnrc.a

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIB) $(CXXFLAGS)

all: $(TARGET)

clean   :
	rm -f $(OBJ) $(TARGET)
