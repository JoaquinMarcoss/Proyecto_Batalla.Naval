
#ifndef BATALLA_NAVAL_HUMANO_H
#define BATALLA_NAVAL_HUMANO_H
#include "Jugador.h"
#include <fstream>
#include <string>
#include<iostream>
#include "Tablero.h"
class Humano: public Jugador, public Tablero{
private:
    int Hf;
    int Hc;
public:
    Humano();
    Humano(string Nom, int hf, int hc);
    Humano(string t[9][9], string tx[9][9], int hf, int hc);
    void setHf(int hf);
    void setHc(int hc);
    void Tiro_Hum();
    void CargarTableroH();
    Barcos B;
};


#endif //BATALLA_NAVAL_HUMANO_H
