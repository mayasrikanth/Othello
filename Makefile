CC          = g++
CFLAGS      = -std=c++11 -Wall -pedantic -ggdb
OBJS        = player.o board.o
BotsWoohoo  = player

all: $(BotsWoohoo) testgame

$(BotsWoohoo): $(OBJS) wrapper.o
	$(CC) -o $@ $^

testgame: testgame.o
	$(CC) -o $@ $^

testminimax: $(OBJS) testminimax.o
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) -x c++ $< -o $@

java:
	make -C java/

cleanjava:
	make -C java/ clean

clean:
	rm -f *.o $(BotsWoohoo) testgame testminimax

.PHONY: java testminimax
