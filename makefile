strfunctions: strfunctions.c
	gcc strfunctions.c -o strfunctions

run: strfunctions
	./strfunctions

clean:
	rm *~
