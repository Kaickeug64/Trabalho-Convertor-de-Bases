#ifndef BINOCT_H
#define BINOCT_H

#include <iostream>
#include <string>
using namespace std;
string conversaoBinOctProcesses(string numero){
    int resto = numero.length() % 3;
    
    if (resto != 0) {
        int casasFaltantes = 3 - resto;
        numero = string(casasFaltantes, '0') + numero;
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
        
        resultado = hexAtual + resultado; 
    }
    
    return resultado;
}
string conversaoBinarioOctal(string numero){
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);
    if (pos != string::npos) {

        numerofracionario = numero.substr(pos + 1);

        numero = numero.substr(0, pos);
        return conversaoBinOctProcesses(numero) + "." + conversaoBinOctProcesses(numerofracionario);  

    }else{
        return conversaoBinOctProcesses(numero);
    }
     
    
}

#endif