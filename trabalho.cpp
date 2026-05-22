#include <iostream>
#include <string>

#include <DecBin.h>
#include <DecOct.h>
#include <DecHex.h>
#include <BinOct.h>

using namespace std;


string conversaoOctalBinario(float numero){
    // Separar parte inteira e fracionária
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    // Converter parte inteira
    string binarioInteiro = "";
    if(parteInteira == 0) binarioInteiro = "0";

    int n = parteInteira;
    string temp = "";
    while(n > 0){
        int digito = n % 10; // pega o último dígito octal
        string bin = "";
        // Converter dígito octal para 3 bits binários
        for(int i=0; i<3; i++){
            bin = to_string(digito % 2) + bin;
            digito /= 2;
        }
        temp = bin + temp;
        n /= 10;
    }
    binarioInteiro = temp;

    // Converter parte fracionária
    string binarioFracionaria = "";
    float frac = parteFracionaria;
    int limite = 10; // número de casas binárias
    while(frac > 0 && limite--){
        frac *= 10;
        int digito = (int)frac;
        frac -= digito;
        // Converter dígito octal para 3 bits binários
        string bin = "";
        for(int i=0; i<3; i++){
            bin = to_string(digito % 2) + bin;
            digito /= 2;
        }
        binarioFracionaria += bin;
    }

    return binarioInteiro + "." + binarioFracionaria;
}

int main() {
    float numConversao = 0;
    int baseOrigem = 0;
    int baseDestino;
    
    cin>>numConversao;
    cin>>baseOrigem;
    cin>>baseDestino;
    
    switch(baseDestino){
		
		case 2:{
			if(baseOrigem == 10){
				conversaoDecimalBinario(numConversao);
		}
			
			else if(baseOrigem == 8){
				conversaoOctalBinario(numConversao);
			}
			else if(baseOrigem == 16){
				conversaoHexadecimalBinario(numConversao);
			}
			else{
				cout<<"ERRO";
			}
			break;
		}
		case 8:{
			if(baseOrigem == 10){
				conversaoDecimalOctal(numConversao);
			}
			else if(baseOrigem == 2){
				conversaoBinarioOctal(numConversao);
			}
			else if(baseOrigem == 16){
				conversaoHexadecimalOctal(numConversao);
			}
			else{
				cout<<"ERRO";
			}
			break;
		}
		
		case 16:{
			if(baseOrigem == 10){
				conversaoDecimalHexadecimal(numConversao);
			}
			else if(baseOrigem == 2){
				conversaoBinarioHexadecimal(numConversao);
			}
			else if(baseOrigem == 8){
				conversaoOctalHexadecimal(numConversao);
			}
			else{
				cout<<"ERRO";
			}
			break;
		}
		
	
		case 10:{
			if(baseOrigem == 2){
				conversaoBinarioDecimal(numConversao);
			}
			else if(baseOrigem == 8){
				conversaoOctalDecimal(numConversao);
			}
			else if(baseOrigem == 16){
				conversaoHexadecimalDecimal(numConversao);
			}
			else{
				cout<<"ERRO";
			}
			break;
		}
		default:
			cout<<"ERRO";
	}
}
