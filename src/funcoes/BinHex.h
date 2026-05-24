#ifndef BINHEX_H
#define BINHEX_H

#include <iostream>
#include <string>
using namespace std;

string conversaoBinHexProcesses(string numero, int type)
{
    int resto = numero.length() % 4;

    if (resto != 0)
    {
        int casasFaltantes = 4 - resto;
        numero = string(casasFaltantes, '0') + numero;
    }

    if (type == 2) {
        cout << "Alinhamento em blocos de 4 bits: " << numero << endl;
    }

    string resultado = "";

    for (int i = numero.length() - 1; i >= 0; i -= 4)
    {
        string bloco = string() + numero[i - 3] + numero[i - 2] + numero[i - 1] + numero[i];
        string hexAtual = "";

        if (bloco == "0000")
            hexAtual = "0";
        else if (bloco == "0001")
            hexAtual = "1";
        else if (bloco == "0010")
            hexAtual = "2";
        else if (bloco == "0011")
            hexAtual = "3";
        else if (bloco == "0100")
            hexAtual = "4";
        else if (bloco == "0101")
            hexAtual = "5";
        else if (bloco == "0110")
            hexAtual = "6";
        else if (bloco == "0111")
            hexAtual = "7";
        else if (bloco == "1000")
            hexAtual = "8";
        else if (bloco == "1001")
            hexAtual = "9";
        else if (bloco == "1010")
            hexAtual = "A";
        else if (bloco == "1011")
            hexAtual = "B";
        else if (bloco == "1100")
            hexAtual = "C";
        else if (bloco == "1101")
            hexAtual = "D";
        else if (bloco == "1110")
            hexAtual = "E";
        else if (bloco == "1111")
            hexAtual = "F";

        if (type == 2) {
            cout << "Bloco '" << bloco << "' -> Digito: " << hexAtual << endl;
        }

        resultado = hexAtual + resultado;
    }

    return resultado;
}

string conversaoBinarioHexadecimal(string numero, int type)
{
    string numerofracionario = "";
    char divisor = '.';
    size_t pos = numero.find(divisor);

    if (pos != string::npos)
    {
        string parteInteira = numero.substr(0, pos);
        numerofracionario = numero.substr(pos + 1);

        if (type == 2) {
            cout << "--- Parte Inteira (" << parteInteira << ") ---" << endl;
        }
        string hexInteiro = conversaoBinHexProcesses(parteInteira, type);

        if (type == 2) {
            cout << "--- Parte Fracionaria (" << numerofracionario << ") ---" << endl;
        }
        numerofracionario = conversaoBinHexProcesses(numerofracionario, type);

        if (numerofracionario.length() > 16) {
            numerofracionario.resize(16);
            cout << endl << "Alerta: Número truncado para 16 caracteres após o ponto" << endl << endl << "Resultado:";
        }

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return hexInteiro + "." + numerofracionario;  
    }
    else
    {
        if (type == 2) {
            cout << "--- Parte Inteira (" << numero << ") ---" << endl;
        }
        string hexInteiro = conversaoBinHexProcesses(numero, type);

        if (type == 2) {
            cout << "--------------------------------------------" << endl;
        }

        return hexInteiro;
    }
}

#endif