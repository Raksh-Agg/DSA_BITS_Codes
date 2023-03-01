runs: externalSort.o intMerge.o intMergeAuxIter.o Person.o
	gcc -o runguy externalSort.o intMerge.o intMergeAuxIter.o Person.o
	./runguy 
externalSort.o: externalSort.c intMerge.h
	gcc -c externalSort.c
insSort.o: intMerge.c intMerge.h 
	gcc -c intMerge.c
intMergeAuxIter.o: intMergeAuxIter.c intMergeAux.h
	gcc -c intMergeAuxIter.c
Person.o: Person.c Person.h
	gcc -c Person.c
clean:
	rm -f *.o runguy
# To run, type [make runs]

