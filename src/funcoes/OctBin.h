#ifndef OCTBIN_H
#define OCTBIN_H

#include <iostream>
#include <string>
using namespace std;

string conversaoOctBinProcesses(string numeroString, int type) {
    int tamanho = numeroString.length();
    string *bin = new string[tamanho];
    string somatorioBin = ""; 

    for (int i = 0; i < tamanho; i++)
    {
        switch (numeroString[i])
        {
        case '0': bin[i] = "000"; break;
        case '1': bin[i] = "001"; break;
        case '2': bin[i] = "010"; break;
        case '3': bin[i] = "011"; break;
        case '4': bin[i] = "100"; break;
        case '5': bin[i] = "101"; break;
        case '6': bin[i] = "110"; break;
        case '7': bin[i] = "111"; break;
        default: break;
        }

        if (type == 2) {
            cout << "Digito '" << numeroString[i] << "' -> " << bin[i] << endl;
        }
    }
    
    for (int i = 0; i < tamanho; i++)
    {
        somatorioBin += bin[i];
    }

    delete[] bin;
    return somatorioBin;
}

string conversaoOctalBinario(string numero, int type) {
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);

    if (pos != string::npos) {
        string parteInteira = numero.substr(0, pos);
        numerofracionario = numero.substr(pos + 1);

        if (type == 2) {
            cout << "--- Parte Inteira (" << parteInteira << ") ---" << endl;
        }
        string binInteiro = conversaoOctBinProcesses(parteInteira, type);

        if (type == 2) {
            cout << "--- Parte Fracionaria (" << numerofracionario << ") ---" << endl;
        }
        numerofracionario = conversaoOctBinProcesses(numerofracionario, type);

        if (numerofracionario.length() > 16) {
            numerofracionario.resize(16);
            cout << endl << "Alerta: Numero truncado para 16 caracteres apos o ponto" << endl << endl << "Resultado:";
        }

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return binInteiro + "." + numerofracionario;  

    } else {
        if (type == 2) {
            cout << "--- Parte Inteira (" << numero << ") ---" << endl;
        }
        string binInteiro = conversaoOctBinProcesses(numero, type);

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return binInteiro;
    }
}

#endif