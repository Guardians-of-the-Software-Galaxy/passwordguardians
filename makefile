passwordguardians: application.o database.o
	gcc -o passwordguardians application.o database.o

application.o: application.c database.h login_credential.h
	gcc -c -ansi -pedantic-errors -Wall -c application.c

database.o: database.c database.h login_credential.h
	gcc -c -ansi -pedantic-errors -Wall -c database.c