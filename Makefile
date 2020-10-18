OS = $(shell uname)

SOURCEDIR = src
BUILDDIR = out
VPATH =  src/main : out/

ifeq ($(OS), Linux)
  VER=c++1y
else
  VER=c++14
endif

CC = g++
CFLAGS = -Wall -Werror -Wno-deprecated -std=$(VER) -O -g

BASE_OBJECTS = main.o file_io.o strategies.o memory_block.o
OBJECTS = $(addprefix out/, $(BASE_OBJECTS))

.default: all

all: Main

run: all
	echo "file,allocator,memory_usage" > ./results/totals.csv
	echo "file,allocator,list,address,size,contents" > ./results/combined.csv
	./Main first-names FIRST 4945
	./Main first-names BEST 4945
	./Main first-names WORST 4945
	
	./Main middle-names FIRST 3897
	./Main middle-names BEST 3897
	./Main middle-names WORST 3897

clean:
	if [ $(shell ls out | grep -wv "*.o" -c) -gt 0 ]; then rm $(BUILDDIR)/*.o; fi;
	if [ -f Main ]; then rm Main; fi;
	rm ./results/**/*
	rm ./results/*

Main: $(BASE_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o Main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $(BUILDDIR)/$@
	