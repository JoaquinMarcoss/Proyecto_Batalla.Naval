#include <iostream>
#include "Humano.h"
#include "Maquina.h"
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
int main() {
    string opcion;
    int op;
    bool bandOP;
    cout<<endl<< "--------------------------------- BATALLA NAVAL --------------------------------";
    cout<<endl<< "| REGLAS                                                                       |";
    cout<<endl<< "| - Coloque sus barcos en su tablero                                           |";
    cout<<endl<< "| - Debe ingresar coordenadas (1 al 9) para intentar hundir la flota contraria |";
    cout<<endl<< "| - Se sumara un punto a la hora de HUNDIR un barco                            |";
    cout<<endl<< "| - Gana el jugador que mantiene su flota                                      |";
    cout<<endl<< "--------------------------------------------------------------------------------" << endl;
    do {
        cout<<endl<<" MODOS DE JUEGO ";
        cout<<endl<<" 1) DOS JUGADORES";
        cout<<endl<<" 2) JUGADOR VS MAQUINA";
        cout<<endl<<" 0) SALIR";
        cout<<endl<<" Elija el modo de juego: ";
        cin>>opcion;
        if (opcion.length()==1 && isdigit(opcion[0])) {
            op = stoi(opcion);
            if(op>=0 && op<=2){
                bandOP = true;
            }else{
                bandOP = false;
                cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                cout<<endl<<" El valor tiene que ser 0 - 1 - 2"<<endl;
            }
        }else{
            bandOP = false;
            cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
            cout<<endl<<" El valor tiene que ser 0 - 1 - 2"<<endl;
        }
    }while (bandOP==false);

    switch (op){
        case 1: {
            Humano H[2];
            cout<<endl<<" Turno Jugador 1 ";
            H[0].CargarTableroH();
            cout<<endl<<" Turno Jugador 2 ";
            H[1].CargarTableroH();
            cout << endl << " ------------------- A JUGAR -------------------";
            int turno=0, aux=1;
            while (H[0].getPuntaje() != 7 && H[1].getPuntaje() != 7) {
                string Chf, Chc;
                int hf, hc;
                bool bandera;
                //TIRO JUGADOR
                if (turno == 0){
                    cout<<endl<<" Turno de " <<H[0].getNombre();
                } else {
                    cout<<endl<<" Turno de " <<H[1].getNombre();
                }
                do {
                    cout<<endl<<" Numero de fila: ";
                    cin>>Chf;
                    cout<<"Numero de columna: ";
                    cin>>Chc;
                    if (Chf.length()==1 && Chc.length()==1 && isdigit(Chf[0]) && isdigit(Chc[0])) {
                        hf = stoi(Chf);
                        hc = stoi(Chc);
                        bandera = true;
                    }else{
                        bandera = false;
                        cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                        cout<<endl<<" El valor tiene que ser un numero del 1 al 9"<<endl;
                    }
                } while (bandera == false);
                H[aux].setHf((hf - 1));
                H[aux].setHc((hc - 1));
                H[aux].Tiro_Hum();
                if (turno==0) {
                    cout<<" - Puntaje de "<<H[0].getNombre()<<": "<<H[aux].getPuntaje()<<endl;
                } else {
                    cout<<" - Puntaje de "<<H[1].getNombre()<<": "<<H[aux].getPuntaje()<<endl;
                }
                H[aux].Mostrar_TableroTX();
                if (turno == 0) {
                    turno = 1;
                    aux = 0;
                } else {
                    turno = 0;
                    aux = 1;
                }
            }
            if (H[0].getPuntaje() == 7){
                cout<<endl<<" GANADOR: "<<H[1].getNombre();
            } else {
                cout<<endl<<" GANADOR: "<<H[0].getNombre();
            }
            break;
        }
        case 2: {
            Humano H;
            Maquina M;
            M.CargarTableroM();
            H.CargarTableroH();
            M.Mostrar_TableroT();
            cout<<endl<<" ------------------- A JUGAR -------------------";
            while (M.getPuntaje() != 7 && H.getPuntaje() != 7) {
                int hf, hc, mf, mc;
                string Chf, Chc;
                bool bandera;
                //TIRO JUGADOR
                cout<<endl<<" Turno de "<<H.getNombre();
                do {
                    cout<<endl<<" Numero de fila: ";
                    cin>>Chf;
                    cout<<"Numero de columna: ";
                    cin>>Chc;
                    if (Chf.length()==1 && Chc.length()==1 && isdigit(Chf[0]) && isdigit(Chc[0])) {
                        hf = stoi(Chf);
                        hc = stoi(Chc);
                        bandera = true;
                    }else{
                        bandera = false;
                        cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                        cout<<endl<<" El valor tiene que ser un numero del 1 al 9" << endl;
                    }
                } while (bandera == false);
                M.setMf((hf - 1));
                M.setMc((hc - 1));
                M.Tiro_Maq();
                M.Mostrar_TableroTX();
                cout<<endl<<" Puntaje de " <<H.getNombre()<< ": "<<M.getPuntaje()<<endl;

                //TIRO MAQUINA
                srand(time(NULL));
                cout<<endl<<" Turno de la maquina";
                mf = rand() % 9;
                mc = rand() % 9;
                cout<<endl<<" Numero de fila: "<<mf+1;
                cout<<endl<<" Numero de columna: "<<mc+1;
                H.setHf(mf);
                H.setHc(mc);
                H.Tiro_Hum();
                H.Mostrar_TableroTX();
                cout<<endl<<" Puntaje de maquina: "<<H.getPuntaje()<<endl;
            }
            if (M.getPuntaje() == 7) {
                cout<<endl<<" GANADOR: " <<H.getNombre();
            } else {
                cout<<endl<<" GANADOR: Maquina";
            }
        }
    }
    getch();
    return 0;
}