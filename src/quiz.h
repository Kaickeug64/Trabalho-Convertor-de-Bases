#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include <vector>

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

struct DadosRodada {
    string nomeOrigem;
    string nomeDestino;
    string pergunta;
    string gabarito;
};

string limparNumero(string s) {
    while (!s.empty() && (s.back() == ' ' || s.back() == '\r' || s.back() == '\n' || s.back() == '\t')) {
        s.pop_back();
    }
    size_t start = 0;
    while (start < s.size() && (s[start] == ' ' || s[start] == '\r' || s[start] == '\n' || s[start] == '\t')) {
        start++;
    }
    if (start > 0) {
        s = s.substr(start);
    }
    if (s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') {
            s.pop_back();
        }
        if (!s.empty() && s.back() == '.') {
            s.pop_back();
        }
    }
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

string obterNomeBase(int base) {
    if (base == 2) return "Binária";
    if (base == 8) return "Octal";
    if (base == 10) return "Decimal";
    return "Hexadecimal";
}

string converterDecimalParaBase(int num, int base) {
    if (base == 10) return to_string(num);
    if (base == 2)  return conversaoDecimalBinario((float)num);
    if (base == 8)  return conversaoDecimalOctal((float)num);
    return conversaoDecimalHexadecimal((float)num);
}

string obterGabarito(string pergunta, int origem, int destino) {
    if (origem == 10) return converterDecimalParaBase(stoi(pergunta), destino);
    if (destino == 10) return to_string((int)conversaoparaDecimal(pergunta, origem));
    
    if (origem == 2 && destino == 8)  return conversaoBinarioOctal(pergunta);
    if (origem == 2 && destino == 16) return conversaoBinarioHexadecimal(pergunta);
    if (origem == 8 && destino == 2)  return conversaoOctalBinario(pergunta);
    if (origem == 8 && destino == 16) return conversaoOctalHexadecimal(pergunta);
    if (origem == 16 && destino == 2) return conversaoHexadecimalBinario(pergunta);
    if (origem == 16 && destino == 8) return conversaoHexadecimalOctal(pergunta);
    
    return "";
}

double executarRodada(int numMin, int numMax, int type, int tempoLimite, int numRodada) {
    int bases[] = {2, 8, 10, 16};
    int baseOrigem, baseDestino;

    if (type == 1) {
        if (rand() % 2 == 0) {
            baseOrigem = 10;
            do { baseDestino = bases[rand() % 4]; } while (baseDestino == 10);
        } else {
            do { baseOrigem = bases[rand() % 4]; } while (baseOrigem == 10);
            baseDestino = 10;
        }
    } else {
        baseOrigem = bases[rand() % 4];
        do { baseDestino = bases[rand() % 4]; } while (baseDestino == baseOrigem);
    }

    int numeroDecimalSorteado = rand() % (numMax - numMin + 1) + numMin;
    
    string rawPergunta = converterDecimalParaBase(numeroDecimalSorteado, baseOrigem);
    
    DadosRodada rodada;
    rodada.nomeOrigem = obterNomeBase(baseOrigem);
    rodada.nomeDestino = obterNomeBase(baseDestino);
    rodada.pergunta = limparNumero(rawPergunta);
    rodada.gabarito = limparNumero(obterGabarito(rodada.pergunta, baseOrigem, baseDestino));

    cout << "\n=========================================" << endl;
    cout << "RODADA " << numRodada << " | Tempo Limite: " << tempoLimite << "s" << endl;
    cout << "Converta o numero: " << rodada.pergunta << " (" << rodada.nomeOrigem << ") -> para " << rodada.nomeDestino << endl;
    cout << "=========================================" << endl;
    cout << "Sua resposta: ";

    auto tempoInicial = chrono::steady_clock::now();
    string respostaUsuario;
    cin >> respostaUsuario;
    auto tempoFinal = chrono::steady_clock::now();

    respostaUsuario = limparNumero(respostaUsuario);

    int segundosGastos = chrono::duration_cast<chrono::seconds>(tempoFinal - tempoInicial).count();

    if (segundosGastos > tempoLimite) {
        cout << "\nTIMEOUT! Voce estourou o tempo de " << tempoLimite << " segundos (Gastou " << segundosGastos << "s)." << endl;
        cout << "A resposta correta era: " << rodada.gabarito << endl;
        return 0.0;
    }

    if (respostaUsuario == rodada.gabarito) {
        double fatorTempo = (double)(tempoLimite - segundosGastos) / tempoLimite;
        cout << "\nResposta CORRETA! (Tempo: " << segundosGastos << "s)" << endl;
        return fatorTempo;
    } else {
        cout << "\nResposta INCORRETA! Voce gastou " << segundosGastos << "s." << endl;
        cout << "A resposta correta era: " << rodada.gabarito << endl;
        return 0.0;
    }
}

void quiz() {
    srand(time(0)); 

    cout << endl << "=========================================" << endl;
    cout << "   Bem-vindo ao Quiz de Conversao de Bases!   " << endl;
    cout << "=========================================" << endl;
    cout << "Digite o nivel desejado de 1 a 5 (0 para sair): ";
    int nivel;
    cin >> nivel;

    if (nivel <= 0 || nivel > 5) {
        cout << "Saindo do Quiz..." << endl;
        return;
    }

    int numMax = 0, numMin = 1, type = 0, rodadas = 0, tempoLimite = 0;

    switch(nivel) {
        case 1: {
            numMax = 7; type = 1; rodadas = 3; tempoLimite = 60;
            break;
        }
        case 2: {
            numMax = 15; type = 1; rodadas = 3; tempoLimite = 60;
            break;
        }
        case 3: {
            numMax = 31; type = 1; rodadas = 5; tempoLimite = 60;
            break;
        }
        case 4: {
            numMax = 63; type = 2; rodadas = 5; tempoLimite = 120;
            break;
        }
        case 5: {
            numMax = 255; type = 2; rodadas = 7; tempoLimite = 120;
            break;
        }
    }

    cout << "\nNivel " << nivel << " selecionado! Preparado? Inicializando..." << endl;
    cout << "| " << rodadas << " Rodadas | Escopo: " << numMin << " a " << numMax << " | Limite: " << tempoLimite << "s por rodada |" << endl;

    double pontuacaoAcumuladafator = 0.0;
    int acertos = 0;

    for (int i = 1; i <= rodadas; i++) {
        double resultadoRodada = executarRodada(numMin, numMax, type, tempoLimite, i);
        if (resultadoRodada > 0.0) {
            acertos++;
            pontuacaoAcumuladafator += resultadoRodada;
        }
    }

    int pontuacaoFinal = (int)((pontuacaoAcumuladafator / rodadas) * 1000);

    cout << "\n=========================================" << endl;
    cout << "             FIM DO QUIZ!                " << endl;
    cout << "=========================================" << endl;
    cout << "Nivel disputado: " << nivel << endl;
    cout << "Acertos: " << acertos << " de " << rodadas << endl;
    cout << "Sua Pontuacao Final: " << pontuacaoFinal << " / 1000 pontos" << endl;
    
    if (pontuacaoFinal == 1000) {
        cout << "Performance Perfeita! Voce e um mestre das bases!" << endl;
    } else if (pontuacaoFinal > 700) {
        cout << "Otimo desempenho! Muito veloz!" << endl;
    } else if (pontuacaoFinal > 0) {
        cout << "Bom trabalho, mas tente responder mais rápido na proxima!" << endl;
    } else {
        cout << "Melhor treinar um pouco mais as contas de cabeça." << endl;
    }
    cout << "=========================================" << endl;
}

#endif