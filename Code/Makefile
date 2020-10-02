#MakeFile example

#target: dependency1 dependency2 ...
#	<tab> command

#NOTE: remember to add the TAB character before the command part

#Typing 'make' will invoke the first target entry in the file

#declare the variable as CC will tell type of compiler
CC=g++

CFLAGS=-c -Wall

#this target will compile all the files "make all"
all: encode
	
encode: encode.cpp
	$(CC) encode.cpp -o encode

encode.o: encode.cpp
	$(CC) $(CFLAGS) encode.cpp

clean:
	rm -rf *o encode


#this target will compile when "make compile" is executed
#compile:
#	g++ encode.cpp -o encode
