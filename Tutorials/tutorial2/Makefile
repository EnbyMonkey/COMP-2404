EXECS = p1 main.o battle.o Character.o

all:	$(EXECS)

p1:	main.o battle.o Character.o
	g++ -o p1 main.o battle.o Character.o

main.o: main.cc battle.h Character.h
	g++ -c main.cc

battle.o:	battle.cc battle.h Character.h
	g++ -c battle.cc

Character.o:	Character.cc Character.h
	g++ -c Character.cc

clean:
	rm -f $(EXECS) *.o
