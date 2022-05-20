mini5: mini5main.o mini5phone.o
	gcc -o mini5 mini5main.o mini5phone.o
mini5main.o: mini5main.c mini5phone.h
	gcc -c mini5main.c
mini5phone.o: mini5phone.c mini5phone.h
	gcc -c mini5phone.c
