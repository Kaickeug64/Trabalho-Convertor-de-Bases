#ifndef PASSOAPASSO_H
#define PASSOAPASSO_H

#include <iostream>
#include <string>

#include "funcoes/DecBin.h"
#include "funcoes/DecOct.h"
#include "funcoes/DecHex.h"
#include "funcoes/BinOct.h"
#include "funcoes/OctBin.h"
#include "funcoes/HexBin.h"
#include "funcoes/HexOct.h"
#include "funcoes/BinHex.h"
#include "funcoes/OctHex.h"
#include "funcoes/xDec.h"

#include "testeEntrada.h"

using namespace std;

void passoAPasso()
{
    int type = 2;
    cout << endl
         << "Modo passo-a-passo selecionado!" << endl
         << endl;

    int baseOrigem = 0;
    int baseDestino;

    cout << "Digite a base de origem: ";
    cin >> baseOrigem;

    cout << "Digite a base de destino: ";
    cin >> baseDestino;

    switch (baseDestino)
    {

    case 2:
    {
        if (baseOrigem == 10)
        {
            double numConversaoTestado;
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                numConversaoTestado = stod(numConversao);
                cout << "Resultado: " << conversaoDecimalBinario((numConversaoTestado), type) << endl
                     << endl;
            }
        }

        else if (baseOrigem == 8)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoOctalBinario((numConversao), type) << endl
                     << endl;
            }
        }
        else if (baseOrigem == 16)
        {

            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes Use apenas letras maiusculas e numeros): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoHexadecimalBinario((numConversao), type) << endl
                     << endl;
            }
        }
        else
        {
            cout << endl
                 << "ERRO! Base de entrada invalida." << endl
                 << "Bases suportadas: 2, 8, 10, 16." << endl
                 << "Tente novamente." << endl
                 << endl;
        }
        break;
    }
    case 8:
    {
        if (baseOrigem == 10)
        {
            double numConversaoTestado;
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                numConversaoTestado = stod(numConversao);
                cout << "Resultado: " << conversaoDecimalOctal((numConversaoTestado), type) << endl
                     << endl;
            }
        }
        else if (baseOrigem == 2)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (Use . para fracoes e apenas letras maiusculas e numeros): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoBinarioOctal((numConversao), type) << endl
                     << endl;
            }
        }

        else if (baseOrigem == 16)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (Use . para fracoes e apenas letras maiusculas e numeros): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoHexadecimalOctal((numConversao), type) << endl
                     << endl;
            }
        }

        else
        {
            cout << endl
                 << "ERRO! Base de entrada invalida." << endl
                 << "Bases suportadas: 2, 8, 10, 16." << endl
                 << "Tente novamente." << endl
                 << endl;
        }
        break;
    }

    case 16:
    {
        if (baseOrigem == 10)
        {
            double numConversaoTestado;
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                numConversaoTestado = stod(numConversao);
                cout << "Resultado: " << conversaoDecimalHexadecimal((numConversaoTestado), type) << endl
                     << endl;
            }
        }

        else if (baseOrigem == 2)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoBinarioHexadecimal((numConversao), type) << endl
                     << endl;
            }
        }
        else if (baseOrigem == 8)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoOctalHexadecimal((numConversao), type) << endl
                     << endl;
            }
        }
        else
        {
            cout << endl
                 << "ERRO! Base de entrada invalida." << endl
                 << "Bases suportadas: 2, 8, 10, 16." << endl
                 << "Tente novamente." << endl
                 << endl;
        }
        break;
    }

    case 10:
    {
        if (baseOrigem == 2)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoparaDecimal((numConversao), baseOrigem, type) << endl
                     << endl;
            }
        }
        else if (baseOrigem == 8)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (use . para fracoes): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoparaDecimal((numConversao), baseOrigem, type) << endl
                     << endl;
            }
        }
        else if (baseOrigem == 16)
        {
            string numConversao;
            cout << "Digite o numero a ser convertido (Use . para fracoes e apenas letras maiusculas e numeros): ";
            cin >> numConversao;
            if (teste_entrada(numConversao, baseOrigem))
            {
                cout << "Resultado: " << conversaoparaDecimal((numConversao), baseOrigem, type) << endl
                     << endl;
            }
        }
        else
        {
            cout << endl
                 << "ERRO! Base de entrada invalida." << endl
                 << "Bases suportadas: 2, 8, 10, 16." << endl
                 << "Tente novamente." << endl
                 << endl;
        }
        break;
    }
    default:
        cout << endl
             << "ERRO! Base de destino invalida." << endl
             << "Bases suportadas: 2, 8, 10, 16." << endl
             << "Tente novamente." << endl
             << endl;
    }
}

#endif