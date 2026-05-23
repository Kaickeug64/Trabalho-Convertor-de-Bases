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
#include "CalculadoraMax.h"
using namespace std;



int main() {
	int escolha =1;
	while(escolha != 0){
		cout<<"================================"<<endl;
		cout<<"Bem-vindo ao conversor de bases!"<<endl;
		cout<<"================================"<<endl<<endl;
		cout<<"Digite 1 para modo Convetor de Números"<<endl
		<<"Digite 2 para modo Passo-a-Passo"<<endl
		<<"Digite 3 para modo Batch"<<endl
		<<"Digite 4 para modo Quiz"<<endl
		<<"Digite 5 para modo Calculadora de máximos"<<endl
		<<"ou 0 para sair: ";
		cin>>escolha;
		if(escolha == 0){
			break;
		}
		switch(escolha){
			case 1:{
				cout<<endl<<"Modo conversão simples selecionado!"<<endl<<endl;

				int baseOrigem = 0;
				int baseDestino;
				
				cout<<"Digite a base de origem: ";
				cin>>baseOrigem;

				cout<<"Digite a base de destino: ";
				cin>>baseDestino;
				
				switch(baseDestino){
					
					case 2:{
						if(baseOrigem == 10){
							double numConversaoTestado;
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								numConversaoTestado = stod(numConversao);
								cout<<"Resultado: " <<conversaoDecimalBinario((numConversaoTestado))<<endl<<endl;
							}
					}
						
						else if(baseOrigem == 8){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoOctalBinario((numConversao))<<endl<<endl;
							}
						}
						else if(baseOrigem == 16){
							
							string numConversao;
							cout<<"Digite o número a ser convertido (Use apenas letras maiúsculas e números): ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoHexadecimalBinario((numConversao))<<endl<<endl;
							}
						}
						else{
							cout<<endl<<"ERRO! Base de entrada inválida." <<endl<<"Bases suportadas: 2, 8, 10, 16."<<endl<<"Tente novamente."<<endl<<endl;
						}
						break;
					}
					case 8:{
						if(baseOrigem == 10){
							double numConversaoTestado;
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								numConversaoTestado = stod(numConversao);
								cout<<"Resultado: " <<conversaoDecimalOctal((numConversaoTestado))<<endl<<endl;
							}
						}
						else if(baseOrigem == 2){
							string numConversao;
							cout<<"Digite o número a ser convertido (Use apenas letras maiúsculas e números): ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoBinarioOctal((numConversao))<<endl<<endl;
							}
						}
						
						else if(baseOrigem == 16){
							string numConversao;
							cout<<"Digite o número a ser convertido (Use apenas letras maiúsculas e números): ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoHexadecimalOctal((numConversao))<<endl<<endl;
							}
						}
						
						else{
							cout<<endl<<"ERRO! Base de entrada inválida." <<endl<<"Bases suportadas: 2, 8, 10, 16."<<endl<<"Tente novamente."<<endl<<endl;
						}
						break;
					}
					
					case 16:{
						if(baseOrigem == 10){
							double numConversaoTestado;
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								numConversaoTestado = stod(numConversao);
								cout<<"Resultado: " <<conversaoDecimalHexadecimal((numConversaoTestado))<<endl<<endl;
							}
						}
						
						else if(baseOrigem == 2){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoBinarioHexadecimal((numConversao))<<endl<<endl;
							}
						}
						else if(baseOrigem == 8){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoOctalHexadecimal((numConversao))<<endl<<endl;
							}
						}
						else{
							cout<<endl<<"ERRO! Base de entrada inválida." <<endl<<"Bases suportadas: 2, 8, 10, 16."<<endl<<"Tente novamente."<<endl<<endl;
						}
						break;
					}
					
					
					case 10:{
						if(baseOrigem == 2){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoparaDecimal((numConversao), baseOrigem)<<endl<<endl;
							}
						}
						else if(baseOrigem == 8){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoparaDecimal((numConversao), baseOrigem)<<endl<<endl;
							}
						}
						else if(baseOrigem == 16){
							string numConversao;
							cout<<"Digite o número a ser convertido: ";
							cin>>numConversao;
							if(teste_entrada(numConversao, baseOrigem)){
								cout<<"Resultado: " <<conversaoparaDecimal((numConversao), baseOrigem)<<endl<<endl;
							}
						}
						else{
							cout<<endl<<"ERRO! Base de entrada inválida." <<endl<<"Bases suportadas: 2, 8, 10, 16."<<endl<<"Tente novamente."<<endl<<endl;
						}
						break;
					}
					default:
						cout<<endl<<"ERRO! Base de destino inválida." <<endl<<"Bases suportadas: 2, 8, 10, 16."<<endl<<"Tente novamente."<<endl<<endl;
				}
			}break;
			case 2:
				cout<<"Modo passo-a-passo selecionado!"<<endl;
				break;
			case 3:
				cout<<"Modo batch selecionado!"<<endl;
				break;
			case 4:
				cout<<"Modo quiz selecionado!"<<endl;
				break;
			case 5:{
				cout<<"Modo Calculadora de Máximos selecionado!"<<endl;
				calculadoraMaximos();

			}break;
			default:
				cout<<"Opção inválida, tente novamente."<<endl;
		}
	}

    
}
