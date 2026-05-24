#ifndef BINOCT_H
#define BINOCT_H

#include <iostream>
#include <string>
using namespace std;

string conversaoBinOctProcesses(string numero, int type){
    int resto = numero.length() % 3;
    
    if (resto != 0) {
        int casasFaltantes = 3 - resto;
        numero = string(casasFaltantes, '0') + numero;
    }
    
    if (type == 2) {
        cout << "Alinhamento em blocos de 3 bits: " << numero << endl;
    }
    
    string resultado = "";
    
    for(int i = numero.length() - 1; i >= 0; i -= 3) {

        string bloco = string() + numero[i-2] + numero[i-1] + numero[i];
        
        string hexAtual = "";

        if(bloco == "000") hexAtual = "0";
        else if(bloco == "001") hexAtual = "1";
        else if(bloco == "010") hexAtual = "2";
        else if(bloco == "011") hexAtual = "3";
        else if(bloco == "100") hexAtual = "4";
        else if(bloco == "101") hexAtual = "5";
        else if(bloco == "110") hexAtual = "6";
        else if(bloco == "111") hexAtual = "7";
        
        if (type == 2) {
            cout << "Bloco '" << bloco << "' -> Digito: " << hexAtual << endl;
        }

        resultado = hexAtual + resultado; 
    }
    
    return resultado;
}

string conversaoBinarioOctal(string numero, int type){
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);
    if (pos != string::npos) {

        string parteInteira = numero.substr(0, pos);
        numerofracionario = numero.substr(pos + 1);

        if (type == 2) {
            cout << "--- Parte Inteira (" << parteInteira << ") ---" << endl;
        }
        string octInteiro = conversaoBinOctProcesses(parteInteira, type);

        if (type == 2) {
            cout << "--- Parte Fracionaria (" << numerofracionario << ") ---" << endl;
        }
        numerofracionario = conversaoBinOctProcesses(numerofracionario, type);
        
        if (numerofracionario.length() > 16) {
            numerofracionario.resize(16);
            cout <<endl<< "Alerta: Número truncado para 16 caracteres após o ponto" << endl<<endl<<"Resultado:";
        }

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return octInteiro + "." + numerofracionario;  

    }else{
        if (type == 2) {
            cout << "--- Parte Inteira (" << numero << ") ---" << endl;
        }
        string octInteiro = conversaoBinOctProcesses(numero, type);

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return octInteiro;
    }
}

#endif