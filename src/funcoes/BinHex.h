#ifndef BINHEX_H
#define BINHEX_H

#include <iostream>
#include <string>
using namespace std;
string conversaoBinHexProcesses(string numero){
    int resto = numero.length() % 4;
    
    if (resto != 0) {
        int casasFaltantes = 4 - resto;
        numero = string(casasFaltantes, '0') + numero;
    }
    
    string resultado = "";
    
    for(int i = numero.length() - 1; i >= 0; i -= 4) {

        string bloco = string() + numero[i-3] + numero[i-2] + numero[i-1] + numero[i];
        
        string hexAtual = "";

        if(bloco == "0000") hexAtual = "0";
        else if(bloco == "0001") hexAtual = "1";
        else if(bloco == "0010") hexAtual = "2";
        else if(bloco == "0011") hexAtual = "3";
        else if(bloco == "0100") hexAtual = "4";
        else if(bloco == "0101") hexAtual = "5";
        else if(bloco == "0110") hexAtual = "6";
        else if(bloco == "0111") hexAtual = "7";
        else if(bloco == "1000") hexAtual = "8";
        else if(bloco == "1001") hexAtual = "9";
        else if(bloco == "1010") hexAtual = "A";
        else if(bloco == "1011") hexAtual = "B";
        else if(bloco == "1100") hexAtual = "C";
        else if(bloco == "1101") hexAtual = "D";
        else if(bloco == "1110") hexAtual = "E";
        else if(bloco == "1111") hexAtual = "F";
        
        resultado = hexAtual + resultado; 
    }
    
    return resultado;
}

string conversaoBinarioHexadecimal(string numero) {
    
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);
    if (pos != string::npos) {

        numerofracionario = numero.substr(pos + 1);

        numero = numero.substr(0, pos);
        return conversaoBinHexProcesses(numero) + "." + conversaoBinHexProcesses(numerofracionario);  

    }else{
        return conversaoBinHexProcesses(numero);
    }
}

#endif