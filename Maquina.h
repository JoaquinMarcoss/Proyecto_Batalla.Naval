
#ifndef BATALLA_NAVAL_MAQUINA_H
#define BATALLA_NAVAL_MAQUINA_H
#include "Jugador.h"
#include <fstream>
#include <string>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"
using namespace std;
class Maquina: public Jugador, public Tablero{
private:
    int Mf;
    int Mc;
public:
    Maquina();
    Maquina(string Nom, int mf, int mc);
    void setMf(int mf);
    void setMc(int mc);
    void Tiro_Maq();
    void CargarTableroM();
    Barcos B;
};


#endif //BATALLA_NAVAL_MAQUINA_H
