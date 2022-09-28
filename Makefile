CC = G++
CFLAGS = -Wall -g -std=c++17
EXEC: blackack

${EXEC}: blackjack.o cards.o deck.o
	${CC} ${CFLAGS} -o ${EXEC} blackjack.o cards.o deck.o

blackjack.o: blackjack.cpp cards.h deck.h
	${CC} ${CFLAGS} -c blackjack.cpp
cards.o: cards.h
deck.o: deck.h cards.h