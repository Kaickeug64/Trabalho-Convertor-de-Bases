#include <iostream>
#include <string>
using namespace std;

string conversaoDecimalBinario(float numero) {

    // Parte inteira
    int parteInteira = (int)numero;

    // Parte decimal
    float parteFracionaria = numero - parteInteira;

    string binarioInteiro = "";

    // Conversão da parte inteira
    if (parteInteira == 0) {
        binarioInteiro = "0";
    }

    while (parteInteira > 0) {
        binarioInteiro = to_string(parteInteira % 2) + binarioInteiro;
        parteInteira /= 2;
    }

    // Conversão da parte fracionária
    string binarioFracionario = "";

    int limite = 10; // quantidade de casas binárias

    while (parteFracionaria > 0 && limite--) {

        parteFracionaria *= 2;

        if (parteFracionaria >= 1) {
            binarioFracionario += "1";
            parteFracionaria -= 1;
        } else {
            binarioFracionario += "0";
        }
    }

    return binarioInteiro + "." + binarioFracionario;
}

string conversaoDecimalOctal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string octalInteiro = "";
    if(parteInteira == 0){
        octalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        octalInteiro = to_string(parteInteira % 8) + octalInteiro;
        parteInteira /= 8;
    }

    // Conversão da parte fracionária
    string octalFracionario = "";
    int limite = 10; // número de casas
    while(parteFracionaria > 0 && limite--){
        parteFracionaria *= 8;
        int digito = (int)parteFracionaria;
        octalFracionario += to_string(digito);
        parteFracionaria -= digito;
    }

    return octalInteiro + "." + octalFracionario;
}

string conversaoDecimalHexadecimal(float numero){
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    string hexadecimalInteiro = "";
    if(parteInteira == 0){
        hexadecimalInteiro = "0";
    }

    // Conversão da parte inteira
    while(parteInteira > 0){
        int digito = parteInteira % 16;
        if(digito < 10)
            hexadecimalInteiro = to_string(digito) + hexadecimalInteiro;
        else
            hexadecimalInteiro = char('A' + digito - 10) + hexadecimalInteiro;
        parteInteira /= 16;
    }

    // Conversão da parte fracionária
    string hexadecimalFracionaria = "";
    int limite = 10; // número de casas
    while(parteFracionaria > 0 && limite--){
        parteFracionaria *= 16;
        int digito = (int)parteFracionaria;
        if(digito < 10)
            hexadecimalFracionaria += to_string(digito);
        else
            hexadecimalFracionaria += char('A' + digito - 10);
        parteFracionaria -= digito;
    }

    return hexadecimalInteiro + "." + hexadecimalFracionaria;
}

string conversaoBinarioOctal(float numero){
    // Separar parte inteira e fracionária
    int parteInteira = (int)numero;
    float parteFracionaria = numero - parteInteira;

    // Converter parte inteira binária para octal
    string octalInteiro = "";
    if(parteInteira == 0){
		octalInteiro = "0";
	}
    int n = parteInteira;
    string temp = "";
    while(n > 0){
        // Pegar 3 últimos dígitos binários
        int grupo = n % 1000; // 3 dígitos binários
        int decimal = 0, base = 1;
        while(grupo > 0){
            decimal += (grupo % 10) * base;
            base *= 2;
            grupo /= 10;
        }
        temp = to_string(decimal) + temp;
        n /= 1000;
    }
    octalInteiro = temp;

    // Converter parte fracionária binária para octal
    string octalFracionaria = "";
    int limite = 10; // número de casas
    float frac = parteFracionaria;
    while(frac > 0 && limite--){
        frac *= 8;
        int digito = (int)frac;
        octalFracionaria += to_string(digito);
        frac -= digito;
    }

    return octalInteiro + "." + octalFracionaria;
}
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
