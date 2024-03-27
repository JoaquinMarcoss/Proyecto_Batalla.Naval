#include "Humano.h"
#include "Tablero.h"
#include <cctype>

Humano::Humano(){
    Hf = 0;
    Hc = 0;
}
Humano::Humano(string Nom, int hf, int hc): Jugador(Nom){
    Hf = hf;
    Hc = hc;
}
Humano::Humano(string t[9][9], string tx[9][9], int hf, int hc): Tablero(t, tx){
    Hf = hf;
    Hc = hc;
}
void Humano::setHf(int hx){
    Hf = hx;
}

void Humano::setHc(int hy){
    Hc = hy;
}

void Humano::Tiro_Hum(){
    int i = 0, j = 0;
    if (T[Hf][Hc] == " O") {
        cout<<endl<<" AGUA"<<endl;
        TX[Hf][Hc] = " A";
    } else {
        for (i = 1; i < 8; i++) {
            switch (i) {
                case 1:
                    if (T[Hf][Hc] == "B1") {
                        if (B.Barco1() == true) {
                            cout<<endl<<" BARCO 1 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 2:
                    if (T[Hf][Hc] == "B2") {
                        if (B.Barco2() == true) {
                            cout<<endl<<" BARCO 2 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 3:
                    if (T[Hf][Hc] == "B3") {
                        if (B.Barco3() == true) {
                            cout<<endl<<" BARCO 3 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 4:
                    if (T[Hf][Hc] == "B4") {
                        if (B.Barco4() == true) {
                            cout<<endl<<" BARCO 4 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 5:
                    if (T[Hf][Hc] == "B5") {
                        if (B.Barco5() == true) {
                            cout<<endl<<" BARCO 5 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 6:
                    if (T[Hf][Hc] == "B6") {
                        if (B.Barco6() == true) {
                            cout<<endl<<" BARCO 6 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
                case 7:
                    if (T[Hf][Hc] == "B7") {
                        if (B.Barco7() == true) {
                            cout<<endl<< " BARCO 7 HUNDIDO"<<endl;
                            Puntaje++;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        } else {
                            cout<<endl<<" TIRO ACERTADO "<<endl;
                            T[Hf][Hc] = " X";
                            TX[Hf][Hc] = " X";
                        }
                    }
                    break;
            }
        }
    }
}

void Humano::CargarTableroH() {
    Crear_Tablero();
    int fila, columna, i = 0, j = 0, aux = 0, op;
    string Cfila, Ccolumna, opcion;
    char verFila, verCol;
    bool bandera, bandera1, bandera2, bandera3, bandera4, bandOP;
    cout<<endl<<" Ingrese su nombre: ";
    cin>>Nombre;
    cout<<endl<< " COLOQUE SUS BARCOS EN LA POSICION QUE DESEE ";
    cout<<endl<< " BARCO 1 - ocupacion de 4 casillas: ";
    do {
        cout << endl << " Numero de fila: ";
        cin >> Cfila;
        cout << "Numero de columna: ";
        cin >> Ccolumna;
        if (Cfila.length()==1 && Ccolumna.length()==1 && isdigit(Cfila[0]) && isdigit(Ccolumna[0])) {
                fila = stoi(Cfila);
                columna = stoi(Ccolumna);
                bandera = true;
            }else{
                bandera = false;
                cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                cout << endl << " El valor tiene que ser un numero del 1 al 9" << endl;
            }
    }while (bandera == false);

    fila = fila-1;
    columna = columna-1;
    do {

        do {
            cout << endl << "1) VERTICAL HACIA ABAJO";
            cout << endl << "2) VERTICAL HACIA ARRIBA";
            cout << endl << "3) HORIZONTAL A LA DERECHA";
            cout << endl << "4) HORIZONTAL A LA IZQUIERDA";
            cout << endl << " Elija una opcion: ";
            cin >> opcion;
            if (opcion.length()==1 && isdigit(opcion[0])) {
                op = stoi(opcion);
                if(op>=1 && op<=4){
                    bandOP = true;
                }else{
                    bandOP = false;
                    cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                    cout<<endl<<" El valor tiene que ser 1 - 2 - 3 - 4"<<endl;
                }
            }else{
                bandOP = false;
                cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                cout<<endl<<" El valor tiene que ser 1 - 2 - 3 - 4"<<endl;
            }
        }while (bandOP==false);
        switch(op){
            case 1: {
                for (i = fila; i < fila + 4; i++) {
                    if (T[i][columna] == " O" && i < 8) {
                        bandera1 = true;
                    } else {
                        bandera1 = false;
                        break;
                    }
                }
                if (bandera1 == true) {
                    for (i = fila; i < fila + 4; i++) {
                        T[i][columna] = "B1";
                    }
                } else {
                    cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                }
                break;
            }
            case 2: {
                for (i = fila; i > fila - 4; i--) {
                    if (T[i][columna] == " O" && i > 0) {
                        bandera1 = true;
                    } else {
                        bandera1 = false;
                        break;
                    }
                }
                if (bandera1 == true) {
                    for (i = fila; i > fila - 4; i--) {
                        T[i][columna] = "B1";
                    }
                } else {
                    cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                }
                break;
            }
            case 3: {
                for (j = columna; j < columna + 4; j++) {
                    if (T[fila][j] == " O" && j < 8) {
                        bandera1 = true;
                    } else {
                        bandera1 = false;
                        break;
                    }
                }
                if (bandera1 == true) {
                    for (j = columna; j < columna + 4; j++) {
                        T[fila][j] = "B1";
                    }
                } else {
                    cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                }
                break;
            }
            case 4: {
                for (j = columna; j > columna - 4; j--) {
                    if (T[fila][j] == " O" && j > 0) {
                        bandera1 = true;
                    } else {
                        bandera1 = false;
                        break;
                    }
                }
                if (bandera1 == true) {
                    for (j = columna; j > columna - 4; j--) {
                        T[fila][j] = "B1";
                    }
                } else {
                    cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                }
                break;
            }
        }
    }while (bandera1 == false);
    Mostrar_TableroT();

    cout << endl << " BARCO 2,3,4 - ocupacion de 3 casillas: ";
    for (int k = 0; k < 3; k++){
        do {
            do {
                cout << endl << " Numero de fila: ";
                cin >> Cfila;
                cout << "Numero de columna: ";
                cin >> Ccolumna;
                if (Cfila.length()==1 && Ccolumna.length()==1 && isdigit(Cfila[0]) && isdigit(Ccolumna[0])) {
                    fila = stoi(Cfila);
                    columna = stoi(Ccolumna);
                    bandera = true;
                }else{
                    bandera = false;
                    cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                    cout << endl << " El valor tiene que ser un numero del 1 al 9" << endl;
                }
            }while(bandera==false);
            fila = fila - 1;
            columna = columna - 1;
            do{
            cout << endl << "1) VERTICAL HACIA ABAJO";
            cout << endl << "2) VERTICAL HACIA ARRIBA";
            cout << endl << "3) HORIZONTAL A LA DERECHA";
            cout << endl << "4) HORIZONTAL A LA IZQUIERDA";
            cout << endl << " Elija una opcion: ";
            cin >> opcion;
            if (opcion.length()==1 && isdigit(opcion[0])) {
                op = stoi(opcion);
                if(op>=1 && op<=4){
                    bandOP = true;
                }else{
                    bandOP = false;
                    cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                    cout<<endl<<" El valor tiene que ser 1 - 2 - 3 - 4"<<endl;
                }
            }else{
                bandOP = false;
                cout<<endl<<" ADVERTENCIA: El valor ingresado es erroneo";
                cout<<endl<<" El valor tiene que ser 1 - 2 - 3 - 4"<<endl;
            }
        }while (bandOP==false);
            switch (op) {
                case 1: {
                    for (i = fila; i < fila + 3; i++) {
                        if (T[i][columna] == " O" && i<8) {
                            bandera2 = true;
                        } else {
                            bandera2 = false;
                            break;
                        }
                    }
                    if (bandera2 == true){
                        switch (k) {
                            case 0:
                                for (i = fila; i < fila + 3; i++) {
                                    T[i][columna] = "B2";
                                }
                                break;
                            case 1:
                                for (i = fila; i < fila + 3; i++) {
                                    T[i][columna] = "B3";
                                }
                                break;
                            case 2:
                                for (i = fila; i < fila + 3; i++) {
                                    T[i][columna] = "B4";
                                }
                                break;
                        }
                    } else {
                        cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                    }
                    break;
                    case 2: {
                        for (i = fila; i > fila - 3; i--) {
                            if (T[i][columna] == " O" && i > 0) {
                                bandera2 = true;
                            } else {
                                bandera2 = false;
                                break;
                            }
                        }
                        if (bandera2 == true) {
                            switch (k) {
                                case 0:
                                    for (i = fila; i > fila - 3; i--) {
                                        T[i][columna] = "B2";
                                    }
                                    break;
                                case 1:
                                    for (i = fila; i > fila - 3; i--) {
                                        T[i][columna] = "B3";
                                    }
                                    break;
                                case 2:
                                    for (i = fila; i > fila - 3; i--) {
                                        T[i][columna] = "B4";
                                    }
                                    break;
                            }
                        } else {
                            cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                        }
                        break;
                    }
                    case 3:{
                        for (j=columna; j<columna+3; j++){
                            if (T[fila][j] == " O" && j<8){
                                bandera2 = true;
                            } else {
                                bandera2 = false;
                                break;
                            }
                        }
                        if (bandera == true) {
                            switch (k) {
                                case 0:
                                    for (j = columna; j < columna + 3; j++) {
                                        T[fila][j] = "B2";
                                    }
                                    break;
                                case 1:
                                    for (j = columna; j < columna + 3; j++) {
                                        T[fila][j] = "B3";
                                    }
                                    break;
                                case 2:
                                    for (j = columna; j < columna + 3; j++) {
                                        T[fila][j] = "B4";
                                    }
                                    break;
                            }
                        } else {
                            cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                        }
                        break;
                    }
                    case 4: {
                        for (j = columna; j > columna - 3; j--) {
                            if (T[fila][j] == " O" && j>0) {
                                bandera2 = true;
                            } else {
                                bandera2 = false;
                                break;
                            }
                        }
                        if (bandera2 == true){
                            switch (k) {
                                case 0:
                                    for (j = columna; j > columna - 3; j--) {
                                        T[fila][j] = "B2";
                                    }
                                    break;
                                case 1:
                                    for (j = columna; j > columna - 3; j--) {
                                        T[fila][j] = "B3";
                                    }
                                    break;
                                case 2:
                                    for (j = columna; j > columna - 3; j--) {
                                        T[fila][j] = "B4";
                                    }
                                    break;
                            }
                        } else {
                            cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                        }
                        break;
                    }
                }
            }
            Mostrar_TableroT();
        }while (bandera2 == false);
    }

    cout << endl << " BARCO 5,6 - ocupacion de 2 casillas: ";
    for (int k = 0; k < 2; k++){
        bool bandera = false;
        do {
            do {
                cout << endl << " Numero de fila: ";
                cin >> Cfila;
                cout << "Numero de columna: ";
                cin >> Ccolumna;
                if (Cfila.length() == 1 && Ccolumna.length() == 1 && isdigit(Cfila[0]) && isdigit(Ccolumna[0])) {
                    fila = stoi(Cfila);
                    columna = stoi(Ccolumna);
                    bandera = true;
                } else {
                    bandera = false;
                    cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                    cout << endl << " El valor tiene que ser un numero del 1 al 9" << endl;
                }
            }while (bandera == false);
            fila = fila - 1;
            columna = columna - 1;
            do {
                cout << endl << "1) VERTICAL HACIA ABAJO";
                cout << endl << "2) VERTICAL HACIA ARRIBA";
                cout << endl << "3) HORIZONTAL A LA DERECHA";
                cout << endl << "4) HORIZONTAL A LA IZQUIERDA";
                cout << endl << " Elija una opcion: ";
                cin >> opcion;
                if (opcion.length() == 1 && isdigit(opcion[0])) {
                    op = stoi(opcion);
                    if (op >= 1 && op <= 4) {
                        bandOP = true;
                    } else {
                        bandOP = false;
                        cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                        cout << endl << " El valor tiene que ser 1 - 2 - 3 - 4" << endl;
                    }
                } else {
                    bandOP = false;
                    cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                    cout << endl << " El valor tiene que ser 1 - 2 - 3 - 4" << endl;
                }
            } while (bandOP == false);
            switch (op) {
                case 1: {
                    for (i = fila; i < fila + 2; i++) {
                        if (T[i][columna] == " O" && i < 8) {
                            bandera3 = true;
                        } else {
                            bandera3 = false;
                            break;
                        }
                    }
                    if (bandera3 == true) {
                        switch (k) {
                            case 0:
                                for (i = fila; i < fila + 2; i++) {
                                    T[i][columna] = "B5";
                                }
                                break;
                            case 1:
                                for (i = fila; i < fila + 2; i++) {
                                    T[i][columna] = "B6";
                                }
                                break;
                        }
                    } else {
                        cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                    }
                    break;
                }
                case 2: {
                    for (i = fila; i > fila - 2; i--) {
                        if (T[i][columna] == " O" && i > 0) {
                            bandera3 = true;
                        } else {
                            bandera3 = false;
                            break;
                        }
                    }
                    if (bandera3 == true) {
                        switch (k) {
                            case 0:
                                for (i = fila; i > fila - 2; i--) {
                                    T[i][columna] = "B5";
                                }
                                break;
                            case 1:
                                for (i = fila; i > fila - 2; i--) {
                                    T[i][columna] = "B6";
                                }
                                break;
                        }
                    } else {
                        cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                    }
                    break;
                }
                case 3: {
                    for (j = columna; j < columna + 2; j++) {
                        if (T[fila][j] == " O" && j < 8) {
                            bandera3 = true;
                        } else {
                            bandera3 = false;
                            break;
                        }
                    }
                    if (bandera3 == true) {
                        switch (k) {
                            case 0:
                                for (j = columna; j < columna + 2; j++) {
                                    T[fila][j] = "B5";
                                }
                                break;
                            case 1:
                                for (j = columna; j < columna + 2; j++) {
                                    T[fila][j] = "B6";
                                }
                                break;
                        }
                    } else {
                        cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                    }
                    break;
                }
                case 4: {
                    for (j = columna; j > columna - 2; j--) {
                        if (T[fila][j] == " O" && j > 0) {
                            bandera3 = true;
                        } else {
                            bandera3 = false;
                            break;
                        }
                    }
                    if (bandera3 == true) {
                        switch (k) {
                            case 0:
                                for (j = columna; j > columna - 2; j--) {
                                    T[fila][j] = "B5";
                                }
                                break;
                            case 1:
                                for (j = columna; j > columna - 2; j--) {
                                    T[fila][j] = "B6";
                                }
                                break;
                        }
                    } else {
                        cout << endl << " ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
                    }
                    break;
                }
            }
            Mostrar_TableroT();
        }while (bandera3==false);
    }

    cout << endl << " BARCO 7 - ocupacion de 1 casillas: ";
    do{
        do{
            cout << endl << " Numero de fila: ";
            cin >> Cfila;
            cout << "Numero de columna: ";
            cin >> Ccolumna;
            if (Cfila.length()==1 && Ccolumna.length()==1 && isdigit(Cfila[0]) && isdigit(Ccolumna[0])) {
                fila = stoi(Cfila);
                columna = stoi(Ccolumna);
                bandera = true;
            }else{
                bandera = false;
                cout << endl << " ADVERTENCIA: El valor ingresado es erroneo";
                cout << endl << " El valor tiene que ser un numero del 1 al 9" << endl;
            }
        }while(bandera==false);
    fila = fila - 1;
    columna = columna - 1;
    if (T[fila][columna] == " O"){
            T[fila][columna] = "B7";
            bandera4 = true;
        }else{
        cout<<endl<<" ADVERTENCIA: no se puede colocar el barco de esa manera" << endl;
        bandera4 = false;
    }
}while(bandera4 == false);
    Mostrar_TableroT();
}