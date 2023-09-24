#/**
# * @file Makefile
# * @author Tucker Self, Braden Windsor
# * @date 2023-09-24
# * @brief the makefile for the Simple Steganography 
# * 
# * allows for the usage of make commands for the code within the DualSteganography file
# */

#Compile using g++
CC = g++
#Compile with all errors and warnings
CFLAGS = -g -Wall -Wextra
#The build target
TARGET = DualSteganography

#Compilation commands
all: $(TARGET)

$(TARGET): Steganography.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) Steganography.o main.o

Steganography.o: Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) -c Steganography.cpp

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

#Clean up files
clean:
	$(RM) $(TARGET) *.o *~
