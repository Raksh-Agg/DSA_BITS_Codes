runs: Driver.o intMerge.o intMergeAuxRec.o heap_usage.o
	gcc -o runguy Driver.o intMerge.o intMergeAuxRec.o heap_usage.o
	./runguy 
Driver.o: Driver.c intMerge.h
	gcc -c Driver.c
insSort.o: intMerge.c intMerge.h heap_usage.h
	gcc -c intMerge.c
Person.o: intMergeAuxRec.c intMergeAux.h
	gcc -c intMergeAuxRec.c
heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c
clean:
	rm -f *.o runguy
# To run, type [make runs]

