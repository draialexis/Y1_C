
all: mesTests

mesTests: mesTests.o aTester.o
	gcc -Wall -o mesTests mesTests.o aTester.o
	
mesTests.o: mesTests.c
	gcc -Wall -c mesTests.c
	
aTester.o:
	gcc -Wall -c aTester.c
	rm -f aTester.c
	
clean:
	rm -f mesTests.o
	
cleanAll:
	rm -f mesTests.o mesTests
