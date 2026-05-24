#include <iostream>
#include <string>

#include "CalculadoraMax.h"
#include "ConvetorDeNumeros.h"
#include "ConvertorCSV.h"
#include "quiz.h"
#include "PassoAPasso.h"

using namespace std;

int main() {
    int escolha = 1;
    while(escolha != 0){
        cout<<"================================"<<endl;
        cout<<"Bem-vindo ao conversor de bases!"<<endl;
        cout<<"================================"<<endl<<endl;
        cout<<"Digite 1 para modo Convetor de Numeros"<<endl
            <<"Digite 2 para modo Passo-a-Passo"<<endl
            <<"Digite 3 para modo Batch"<<endl
            <<"Digite 4 para modo Quiz"<<endl
            <<"Digite 5 para modo Calculadora de maximos"<<endl
            <<"ou 0 para sair: ";
        cin>>escolha;
        
        if(escolha == 0){
            break;
        }
        
        switch(escolha){
            case 1:{
                conversorDeNumeros();
            }break;
            case 2:{
                passoAPasso();
            }break;
            case 3:{
                conversorDeNumerosCSV();
            }break;
            case 4:{
                cout<<"Modo quiz selecionado!"<<endl;
                quiz();
            }break; 
            case 5:{
                cout<<"Modo Calculadora de Maximos selecionado!"<<endl;
                calculadoraMaximos();

            }break;
            default:
                cout<<"Opcao invalida, tente novamente."<<endl;
        }
    }
    cout<<"Saindo do programa..."<<endl;
    return 0;
}