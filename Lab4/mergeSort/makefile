runs: Driver.o intMerge.o intMergeAuxIter.o
	gcc -o runguy Driver.o intMerge.o intMergeAuxIter.o
	./runguy 
Driver.o: Driver.c intMerge.h
	gcc -c Driver.c
insSort.o: intMerge.c intMerge.h
	gcc -c intMerge.c
Person.o: intMergeAuxIter.c intMergeAux.h
	gcc -c intMergeAuxIter.c
clean:
	rm -f *.o runguy
# To run, type [make runs]

