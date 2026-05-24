#ifndef DECBIN_H
#define DECBIN_H

#include <iostream>
#include <string>
using namespace std;

inline string conversaoDecimalBinario(float numero, int type) {

    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;
    string binarioInteiro = "";

    if (parteInteira == 0) {
        binarioInteiro = "0";
        if (type == 2) {
            cout << "Parte inteira e 0 -> bit: 0" << endl;
        }
    }

    if (type == 2 && parteInteira > 0) {
        cout << "--- Divisoes Sucessivas (Parte Inteira) ---" << endl;
    }

    while (parteInteira > 0) {
        int resto = parteInteira % 2;
        if (type == 2) {
            cout << parteInteira << " / 2 = " << (parteInteira / 2) << " | Resto: " << resto << endl;
        }
        binarioInteiro = to_string(resto) + binarioInteiro;
        parteInteira /= 2;
    }

    string binarioFracionario = "";
    int limite = 10;

    if (type == 2 && parteFracionaria > 0) {
        cout << "\--- Multiplicacoes Sucessivas (Parte Fracionaria) ---" << endl;
    }

    while (parteFracionaria > 0 && limite--) {
        float anterior = parteFracionaria;
        parteFracionaria *= 2;

        if (parteFracionaria >= 1) {
            if (type == 2) {
                cout << anterior << " * 2 = " << parteFracionaria << " -> bit 1" << endl;
            }
            binarioFracionario += "1";
            parteFracionaria -= 1;
        } else {
            if (type == 2) {
                cout << anterior << " * 2 = " << parteFracionaria << " -> bit 0" << endl;
            }
            binarioFracionario += "0";
        }
    }

    if (binarioFracionario.length() > 16) {
        binarioFracionario.resize(16);
        cout << endl << "Alerta: Numero truncado para 16 caracteres apos o ponto" << endl << endl << "Resultado:";
    }

    if (type == 2) {
        cout << "--------------------------------------------" << endl;
    }

    if (binarioFracionario.empty()) {
        return binarioInteiro;
    }

    return binarioInteiro + "." + binarioFracionario;
}

#endif