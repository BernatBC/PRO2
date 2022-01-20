OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
#
program.exe: program.o Colleccio_cursos.o Conjunt_problemes.o Conjunt_sessions.o Conjunt_usuaris.o Curs.o Problema.o Sessio.o Usuari.o
	g++ -o program.exe program.o Colleccio_cursos.o Conjunt_problemes.o Conjunt_sessions.o Conjunt_usuaris.o Curs.o Problema.o Sessio.o Usuari.o
#
program.o: program.cc Colleccio_cursos.hh Conjunt_problemes.hh Conjunt_sessions.hh Conjunt_usuaris.hh
	g++ -c program.cc $(OPCIONS)
#
Colleccio_cursos.o: Colleccio_cursos.cc Colleccio_cursos.hh
	g++ -c Colleccio_cursos.cc $(OPCIONS)
#
Conjunt_problemes.o: Conjunt_problemes.cc Conjunt_problemes.hh
	g++ -c Conjunt_problemes.cc $(OPCIONS)
#
Conjunt_sessions.o: Conjunt_sessions.cc Conjunt_sessions.hh
	g++ -c Conjunt_sessions.cc $(OPCIONS)
#
Conjunt_usuaris.o: Conjunt_usuaris.cc Conjunt_usuaris.hh
	g++ -c Conjunt_usuaris.cc $(OPCIONS)
#
Curs.o: Curs.cc Curs.hh
	g++ -c Curs.cc $(OPCIONS)
#
Sessio.o: Sessio.cc Sessio.hh
	g++ -c Sessio.cc $(OPCIONS)
#
Problema.o: Problema.cc Problema.hh
	g++ -c Problema.cc $(OPCIONS)
#
Usuari.o: Usuari.cc Usuari.hh
	g++ -c Usuari.cc $(OPCIONS)
#
clean:
	rm -f *.o
	rm -f *.exe
#
practica.tar: program.cc Problema.cc Problema.hh Sessio.cc Sessio.hh Curs.cc Curs.hh Usuari.cc Usuari.hh Conjunt_problemes.cc Conjunt_problemes.hh Conjunt_sessions.cc Conjunt_sessions.hh Colleccio_cursos.cc Colleccio_cursos.hh Conjunt_usuaris.cc Conjunt_usuaris.hh BinTree.hh Makefile
	tar -cvf practica.tar program.cc Problema.cc Problema.hh Sessio.cc Sessio.hh Curs.cc Curs.hh Usuari.cc Usuari.hh Conjunt_problemes.cc Conjunt_problemes.hh Conjunt_sessions.cc Conjunt_sessions.hh Colleccio_cursos.cc Colleccio_cursos.hh Conjunt_usuaris.cc Conjunt_usuaris.hh BinTree.hh Makefile
