runs: Driver.o insSort.o Person.o
	gcc -o runguy Driver.o insSort.o Person.o
	./runguy 
Driver.o: Driver.c insSort.h
	gcc -c Driver.c
insSort.o: insSort.c insSort.h
	gcc -c insSort.c
Person.o: Person.c Person.h
	gcc -c Person.c
clean:
	rm -f *.o runguy
