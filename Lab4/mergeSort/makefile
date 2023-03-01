runs: Driver.o intMerge.o intMergeAuxRec.o
	gcc -o runguy Driver.o intMerge.o intMergeAuxRec.o
	./runguy 
Driver.o: Driver.c intMerge.h
	gcc -c Driver.c
insSort.o: intMerge.c intMerge.h
	gcc -c intMerge.c
Person.o: intMergeAuxRec.c intMergeAux.h
	gcc -c intMergeAuxRec.c
clean:
	rm -f *.o runguy
# To run, type [make runs]

