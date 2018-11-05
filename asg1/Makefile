# Vineet Ramareddi (vramared@ucsc.edu)
# Husain Adam Askari (haskari@ucsc.edu)

COMPILECPP = g++ -std=gnu++17 -g -O0 -Wall -Wextra -Wold-style-cast
MAKEDEPCPP = g++ -std=gnu++17 -MM
VALGRIND   = valgrind --leak-check=full --show-reachable=yes 

MKFILE     = Makefile
DEPFILE    = Makefile.dep
SOURCES    = cppstrtok.cpp string_set.cpp  
OBJECTS    = ${SOURCES:.cpp=.o}
EXECBIN    = oc
SRCFILES   = ${SOURCES} ${MKFILE}
SMALLFILES = ${DEPFILE} foo.oc foo1.oh foo2.oh string_set.h  
CHECKINS   = ${SRCFILES} ${SMALLFILES}
LISTING    = Listing.ps
TEST       = test.str
all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILECPP} -o${EXECBIN} ${OBJECTS}

%.o : %.cpp
	${COMPILECPP} -c $<

ci :
	cid + ${CHECKINS}
	checksource ${CHECKINS}
valgrind	:
	${VALGRIND} ${EXECBIN} foo.oc 10-hundred.oc

clean :
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN} ${DEPFILE} 

${DEPFILE} :
	${MAKEDEPCPP} ${SOURCES} >${DEPFILE}

deps :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include Makefile.dep

test : ${EXECBIN}
	${VALGRIND} ${EXECBIN} foo.oc 1>test.out 2>&1

misc.lis : ${DEPFILE} foo.oc foo1.oh foo2.oh
	catnv ${DEPFILE} foo.oc foo1.oh foo2.oh >misc.lis

lis : misc.lis test
	mkpspdf ${LISTING} ${SRCFILES} misc.lis test.out

again :
	${MAKE} spotless dep all test lis

