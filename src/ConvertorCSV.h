#ifndef ConvertorCSV_H
#define ConvertorCSV_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std; 

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

void conversorDeNumerosCSV()
{
    int type = 1;
    cout << endl
         << "Modo arquivo CSV!" << endl
         << endl;

    int baseOrigem = 0;
    int baseDestino = 0;

    ifstream arquivoEntrada("CSV/entrada_gigante_valida.csv");
    ofstream arquivoSaida("CSV/saida.csv");
    string linha;

    if (!arquivoEntrada.is_open() || !arquivoSaida.is_open()) {
        cout << "Erro ao abrir os arquivos!" << endl;
        return;
    }
    
    int contadorLinhas = 1;
    
    while (getline(arquivoEntrada, linha))
    {
        if (!linha.empty() && linha.back() == '\r') {
            linha.pop_back();
        }
        if (linha.empty() || linha.find_first_not_of(" ") == string::npos) {
            contadorLinhas++;
            continue; 
        }

        stringstream ss(linha);
        string numConversao;
        string baseOrigemStr;
        string baseDestinoStr;

        getline(ss, numConversao, ',');
        getline(ss, baseOrigemStr, ',');
        getline(ss, baseDestinoStr, ',');


        baseOrigem = stoi(baseOrigemStr);
        baseDestino = stoi(baseDestinoStr);

        switch (baseDestino)
        {
        case 2:
        {
            if (baseOrigem == 10)
            {
                double numConversaoTestado;
                if (teste_entrada(numConversao, baseOrigem))
                {
                    numConversaoTestado = stod(numConversao);
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoDecimalBinario(numConversaoTestado, type) << endl;
                }
            }
            else if (baseOrigem == 8)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoOctalBinario(numConversao, type) << endl;
                }
            }
            else if (baseOrigem == 16)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoHexadecimalBinario(numConversao, type) << endl;
                }
            }
            else
            {
                cout << endl << "ERRO! Base de entrada da linha " << contadorLinhas << ": "<< baseOrigem << " inválida." << endl
                     << "Bases suportadas: 2, 8, 10, 16." << endl;
            }
            break;
        }
        case 8:
        {
            if (baseOrigem == 10)
            {
                double numConversaoTestado;
                if (teste_entrada(numConversao, baseOrigem))
                {
                    numConversaoTestado = stod(numConversao);
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoDecimalOctal(numConversaoTestado, type) << endl;
                }
            }
            else if (baseOrigem == 2)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoBinarioOctal(numConversao, type) << endl;
                }
            }
            else if (baseOrigem == 16)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoHexadecimalOctal(numConversao, type) << endl;
                }
            }
            else
            {
                cout << endl << "ERRO! Base de entrada da linha " << contadorLinhas << ": "<< baseOrigem << " inválida." << endl
                     << "Bases suportadas: 2, 8, 10, 16." << endl;
            }
            break;
        }

        case 16:
        {
            if (baseOrigem == 10)
            {
                double numConversaoTestado;
                if (teste_entrada(numConversao, baseOrigem))
                {
                    numConversaoTestado = stod(numConversao);
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoDecimalHexadecimal(numConversaoTestado, type) << endl;
                }
            }
            else if (baseOrigem == 2)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoBinarioHexadecimal(numConversao, type) << endl;
                }
            }
            else if (baseOrigem == 8)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoOctalHexadecimal(numConversao, type) << endl;
                }
            }
            else
            {
                cout << endl << "ERRO! Base de entrada da linha " << contadorLinhas << ": "<< baseOrigem << " inválida." << endl
                     << "Bases suportadas: 2, 8, 10, 16." << endl;
            }
            break;
        }

        case 10:
        {

            if (baseOrigem == 2 || baseOrigem == 8 || baseOrigem == 16)
            {
                if (teste_entrada(numConversao, baseOrigem))
                {
                    arquivoSaida << numConversao << "," << baseOrigem << "," << baseDestino << "," << conversaoparaDecimal(numConversao, baseOrigem, type) << endl;
                }
            }
            else
            {
                cout << endl << "ERRO! Base de entrada da linha " << contadorLinhas << ": "<< baseOrigem << " inválida." << endl
                     << "Bases suportadas: 2, 8, 10, 16." << endl;
            }
            break;
        }
        default:
            cout << endl << "ERRO! Base de destino da linha " << contadorLinhas << ": "<< baseDestino << " inválida." << endl
                 << "Bases suportadas: 2, 8, 10, 16." << endl;
        }
        cout << "Linha " << contadorLinhas << " processada." << endl;
        contadorLinhas++;

    }
    
    arquivoEntrada.close();
    arquivoSaida.close();
    cout << "Processamento do arquivo CSV finalizado!" << endl;
}

#endif