CC = g++
CFLAGS = -g -std=c++17
EXEC = blackjack
OBJECTS = blackjack.o cards.o dealer.o deck.o hand.o human.o player.o table.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}