/** @mainpage
  Pagina principal de l'Evaluator

  El prgrama principal de la practica es pot trobar a program.cc. Atenent a l'enunciat he necessitat crear un mòdul Problema que representa un problema del qual es pot fer enviaments.
  Per recollir aquests problemes he fet un mòdul Conjunt_problemes on es poden recollir les funcions dels problemes.
  Les sessions queden representades pel mòdul Sessio i Conjunt_sessions, on es recullen les operacions de les sessions.
  Els mòduls Curs i Colleccio_cursos contenen les operacions que es poden fer sobre dels cursos, i finalment, els mòduls Usuari i Conjunt_usuaris recullen les diferents operacions que un usuari pot fer.
  */
/**
    @file program.cc
    @brief Programa principal

    En aquest cas suposem que la lectura inicial de problemes, sessions, cursos i usuaris són correctes
    Des d'aquest fitxer es criden les operacions necessaries per posar en funcionament el programa.
*/
#include "Conjunt_problemes.hh"
#include "Conjunt_sessions.hh"
#include "Conjunt_usuaris.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

int main() {
  Conjunt_problemes problemes;
  Conjunt_sessions sessions;
  Colleccio_cursos cursos;
  Conjunt_usuaris usuaris;
  problemes.llegir_problemes();
  sessions.llegir_sessions();
  cursos.llegir_cursos(sessions);
  usuaris.llegir_usuaris();

  string opcio;
  cin >> opcio;
  while (opcio != "fin") {
    cout << "#" << opcio;
    if (opcio == "nuevo_problema" or opcio == "np") {
      string p;
      cin >> p;
      cout << " " << p << endl;
      if (not problemes.existeix(p)) {
        problemes.afegir_problema(p);
        cout << problemes.consultar_n_problemes() << endl;
      }
      else cout << "error: el problema ya existe" << endl;
    }
    else if (opcio == "nueva_sesion" or opcio == "ns") {
      string s;
      cin >> s;
      cout << " " << s << endl;
      Sessio sessio(s);
      sessio.llegir_sessio();
      if (not sessions.existeix(s)) {
        sessions.afegir_sessio(sessio);
        cout << sessions.consultar_n_sessions() << endl;
      }
      else cout << "error: la sesion ya existe" << endl;
    }
    else if (opcio == "nuevo_curso" or opcio == "nc") {
      cout << endl;
      Curs curs;
      if (curs.llegir_curs_repetit(sessions)) {
        cursos.afegir_curs(curs);
        cout << cursos.consultar_n_cursos() << endl;
      }
      else cout << "error: curso mal formado" << endl;
    }
    else if (opcio == "alta_usuario" or opcio == "a") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (not usuaris.existeix(u)) {
        usuaris.afegir_usuari(u);
        cout << usuaris.consultar_n_usuaris() << endl;
      }
      else cout << "error: el usuario ya existe" << endl;
    }
    else if (opcio == "baja_usuario" or opcio == "b") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) {
        if (usuaris.inscrit(u)) {
          cursos.eliminar_inscrit(usuaris.consultar_curs(u));
        }
        usuaris.eliminar_usuari(u);
        cout << usuaris.consultar_n_usuaris() << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "inscribir_curso" or opcio == "i") {
      string u;
      int c;
      cin >> u >> c;
      cout << " " << u << " " << c << endl;
      if (usuaris.existeix(u)) {
        if (cursos.existeix(c)) {
          if (not usuaris.inscrit(u)) {
            usuaris.inscriure(u, c, cursos, sessions);
            cursos.afegir_inscrit(c);
            cout << cursos.consultar_n_inscrits(c) << endl;
          }
          else cout << "error: usuario inscrito en otro curso" << endl;
        }
        else cout << "error: el curso no existe" << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "curso_usuario" or opcio == "cu") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) {
        cout << usuaris.consultar_curs(u) << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "sesion_problema" or opcio == "sp") {
      int c;
      string p;
      cin >> c >> p;
      cout << " " << c << " " << p << endl;
      if (cursos.existeix(c)) {
        if (problemes.existeix(p)) {
          string sessio = cursos.consultar_sessio(c, p);
          if (sessio != "") cout << sessio << endl;
          else cout << "error: el problema no pertenece al curso" << endl;
        }
        else cout << "error: el problema no existe" << endl;
      }
      else cout << "error: el curso no existe" << endl;
    }
    else if (opcio == "problemas_resueltos" or opcio == "pr") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) usuaris.escriure_problemes_resolts(u);
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "problemas_enviables" or opcio == "pe") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) {
        if (usuaris.inscrit(u)) usuaris.escriure_problemes_disponibles(u);
        else cout << "error: usuario no inscrito en ningun curso" << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "envio" or opcio == "e") {
      string u, p;
      int r;
      cin >> u >> p >> r;
      cout << " " << u << " " << p << " " << r << endl;
      if (usuaris.disponible(u, p)) {
        usuaris.enviament(u, p, r, sessions, cursos);
        problemes.enviament(p, r);
      }
      else cout << "error: problema no enviable" << endl;
    }
    else if (opcio == "listar_problemas" or opcio == "lp") {
      cout << endl;
      problemes.escriure_problemes();
    }
    else if (opcio == "escribir_problema" or opcio == "ep") {
      string p;
      cin >> p;
      cout << " " << p << endl;
      if (problemes.existeix(p)) problemes.escriure_problema(p);
      else cout << "error: el problema no existe" << endl;
    }
    else if (opcio == "listar_sesiones" or opcio == "ls") {
      cout << endl;
      sessions.escriure_sessions();
    }
    else if (opcio == "escribir_sesion" or opcio == "es") {
      string s;
      cin >> s;
      cout << " " << s << endl;
      if (sessions.existeix(s)) sessions.escriure_sessio(s);
      else cout << "error: la sesion no existe" << endl;
    }
    else if (opcio == "listar_cursos" or opcio == "lc") {
      cout << endl;
      cursos.escriure_cursos();
    }
    else if (opcio == "escribir_curso" or opcio == "ec") {
      int c;
      cin >> c;
      cout << " " << c << endl;
      if (cursos.existeix(c)) cursos.escriure_curs(c);
      else cout << "error: el curso no existe" << endl;
    }
    else if (opcio == "listar_usuarios" or opcio == "lu") {
      cout << endl;
      usuaris.escriure_usuaris();
    }
    else if (opcio == "escribir_usuario" or opcio == "eu") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) usuaris.escriure_usuari(u);
      else cout << "error: el usuario no existe" << endl;
    }
    else if (opcio == "acabar_curso" or opcio == "ac") {
      string u;
      cin >> u;
      cout << " " << u << endl;
      if (usuaris.existeix(u)) {
        if (usuaris.inscrit(u)) {
          int c = usuaris.consultar_curs(u);
          usuaris.desapuntar(u, cursos);
          cout << cursos.consultar_n_inscrits(c) << endl;
        }
        else cout << "error: usuario no inscrito en ningun curso" << endl;
      }
      else cout << "error: el usuario no existe" << endl;
    }
    cin >> opcio;
  }
}
