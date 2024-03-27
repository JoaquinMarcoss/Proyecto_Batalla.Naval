#include "Jugador.h"
Jugador::Jugador() {
    Nombre = " ";
    Puntaje = 0;
}
Jugador::Jugador(string Nom){
    Nombre = Nom;
    Puntaje = 0;
}

int Jugador::getPuntaje(){
    return Puntaje;
}

string Jugador::getNombre(){
    return Nombre;
}