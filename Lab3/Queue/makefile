runguy: qDriver.o queue_ll.o linked_list.o heap_usage.o
	gcc -o runguy qDriver.o queue_ll.o heap_usage.o linked_list.o
	./runguy
qDriver.o: qDriver.c queue.h heap_usage.h 
	gcc -c qDriver.c
queue_ll.o: queue_ll.c queue.h heap_usage.h linked_list.h
	gcc -c queue_ll.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c
clean:
	rm -f *o runguy

