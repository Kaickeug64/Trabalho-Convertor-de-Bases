#ifndef HEXBIN_H
#define HEXBIN_H

#include <iostream>
#include <string>
using namespace std;

int contadorCasasDecimal(int numero)
{
    int n = 1;
    while (numero >= 10)
    {
        n++;
        numero /= 10;
    }
    return n;
}

string somaBinario(string atual, string soma)
{
    int tam = atual.length();
    bool resto = false;

    // SOLUÇÃO DO PROBLEMA 2: Preencher com zeros à esquerda usando 
    // os recursos nativos da string, sem o loop que estourava a memória.
    if (tam > soma.length())
    {
        soma = string(tam - soma.length(), '0') + soma;
    }

    for (int i = 0; i < tam; i++)
    {
        int idx = tam - 1 - i;

        if (atual[idx] == '0' && soma[idx] == '1' && resto == false)
        {
            atual[idx] = '1';
            resto = false;
        }
        else if (atual[idx] == '0' && soma[idx] == '1' && resto == true)
        {
            resto = true;
        }
        else if (atual[idx] == '1' && soma[idx] == '0' && resto == true)
        {
            atual[idx] = '0';
            resto = true;
        }
        else if (atual[idx] == '1' && soma[idx] == '1' && resto == false)
        {
            atual[idx] = '0';
            resto = true;
        }
        else if (atual[idx] == '1' && soma[idx] == '1' && resto == true)
        {
            atual[idx] = '1';
            resto = true;
        }
    }
    
    if (resto == true)
    {
        atual = "1" + atual;
    }
    
    return atual;   
}

string conversaoHexBinProcesses(string numeroString, int type){
    int tamanho = numeroString.length();
    string *bin = new string[tamanho];
    string somatorioBin = ""; 

    for (int i = 0; i < tamanho; i++)
    {
        switch (numeroString[i])
        {
        case '0': bin[i] = "0000"; break;
        case '1': bin[i] = "0001"; break;
        case '2': bin[i] = "0010"; break;
        case '3': bin[i] = "0011"; break;
        case '4': bin[i] = "0100"; break;
        case '5': bin[i] = "0101"; break;
        case '6': bin[i] = "0110"; break;
        case '7': bin[i] = "0111"; break;
        case '8': bin[i] = "1000"; break;
        case '9': bin[i] = "1001"; break;
        case 'A': bin[i] = "1010"; break;
        case 'B': bin[i] = "1011"; break;
        case 'C': bin[i] = "1100"; break;
        case 'D': bin[i] = "1101"; break;
        case 'E': bin[i] = "1110"; break;
        case 'F': bin[i] = "1111"; break;
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

string conversaoHexadecimalBinario(string numero, int type){
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);
    if (pos != string::npos) {

        string parteInteira = numero.substr(0, pos);
        numerofracionario = numero.substr(pos + 1);

        if (type == 2) {
            cout << "--- Parte Inteira (" << parteInteira << ") ---" << endl;
        }
        string binInteiro = conversaoHexBinProcesses(parteInteira, type);

        if (type == 2) {
            cout << "--- Parte Fracionaria (" << numerofracionario << ") ---" << endl;
        }
        numerofracionario = conversaoHexBinProcesses(numerofracionario, type);
        
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
        string binInteiro = conversaoHexBinProcesses(numero, type);

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return binInteiro;
    }
}
#endif