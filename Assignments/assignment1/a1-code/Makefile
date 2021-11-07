all: a1-global

a1-global: a1-global.cc Date.o Student.o Room.o Date.o Student.o Reservation.o Library.o
	g++ -o a1-global $^

Room.o: Room.h Room.cc
	g++ -c Room.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

Student.o: Student.h Student.cc
	g++ -c Student.cc

Reservation.o: Student.h Room.h Date.h Reservation.h Reservation.cc
	g++ -c Reservation.cc

Library.o: Student.h Room.h Date.h Reservation.h Library.h Library.cc
	g++ -c Library.cc

clean:
	rm -f  a1-global *.o
