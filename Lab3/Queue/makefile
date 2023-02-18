runguy: qDriver.o queue_array.o heap_usage.o
	gcc -o runguy qDriver.o queue_array.o heap_usage.o
	./runguy
qDriver.o: qDriver.c queue.h heap_usage.h
	gcc -c qDriver.c
queue_array.o: queue_array.c queue.h heap_usage.h 
	gcc -c queue_array.c
heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c
clean:
	rm -f *o runguy

