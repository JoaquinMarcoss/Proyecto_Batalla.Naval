
#ifndef BATALLA_NAVAL_JUGADOR_H
#define BATALLA_NAVAL_JUGADOR_H
#include <fstream>
#include <string>
#include<iostream>
#include "Barcos.h"
using namespace std;
class Jugador{
protected:
    string Nombre;
    int Puntaje;
public:
    Jugador();
    Jugador(string Nom);
    string getNombre();
    int getPuntaje();
    Barcos B;
};


#endif //BATALLA_NAVAL_JUGADOR_H
