runStackWithArray: computeSpan.o stack_2.o linked_list.o
	gcc -o runguy computeSpan.o stack_2.o linked_list.o
	./runguy 
stackDriver.o: computeSpan.c stack.h  linked_list.h
	gcc -c computeSpan.c
stack_array.o: stack_2.c stack.h linked_list.h
	gcc -c stack_2.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
clean:
	rm -f *.o runguy
