cal: cal.o
	g++ -Wall -g -o cal cal.o


cal.o: cal.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors cal.cpp

date: date.o
	g++ -Wall -g -o date date.o


date.o: date.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors date.cpp

env: env.o
	g++ -Wall -g -o env env.o


env.o: env.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors env.cpp
 
false: false.o
	g++ -Wall -g -o false false.o


false.o: false.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors false.cpp
 
head: head.o
	g++ -Wall -g -o head head.o


head.o: head.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors head.cpp
 
ln: ln.o
	g++ -Wall -g -o ln ln.o


ln.o: ln.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors ln.cpp
 
ls: ls.o
	g++ -Wall -g -o ls ls.o


ls.o: ls.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors ls.cpp
 
mkdir: mkdir.o
	g++ -Wall -g -o mkdir mkdir.o


mkdir.o: mkdir.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors mkdir.cpp
 
tail: tail.o
	g++ -Wall -g -o tail tail.o


tail.o: tail.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors tail.cpp
 
true: true.o
	g++ -Wall -g -o true true.o


true.o: true.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors true.cpp
 
wc: wc.o
	g++ -Wall -g -o wc wc.o


wc.o: wc.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors wc.cpp

cksum: cksum.o
	g++ -Wall -g -o cksum cksum.o

cksum.o: cksum.cpp
	g++ -Wall -std=c++14 -c -g -O0 -pedantic-errors cksum.cpp

clean:
	rm -rf *o cal date env false head ln ls mkdir tail true wc cksum