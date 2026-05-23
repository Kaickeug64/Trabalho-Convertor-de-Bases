#ifndef CalculadoraMax_H
#define CalculadoraMax_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void calculadoraMaximos() {
    cout<<endl<<"digite o número total de bits: ";
    long numBits;
    if(numBits < 0){
        cout<<"ERRO! Número de bits não pode ser negativo. Tente novamente."<<endl;
        return;
    }
    cin>>numBits;
    cout<<"=============================================================================";
    cout<<endl<<"Número decimal maximo representável na base 2 com "<<numBits<<" : "<< pow(2, numBits) - 1 << endl;
    cout<<endl<<"Número decimal maximo representável na base 8 com "<<numBits<<" : "<< pow(8, numBits) - 1 << endl;
    cout<<endl<<"Número decimal maximo representável na base 10 com "<<numBits<<" : "<< pow(10, numBits) - 1 << endl;  
    cout<<endl<<"Número decimal maximo representável na base 16 com "<<numBits<<" : "<< pow(16, numBits) - 1 << endl;
    cout<<"============================================================================="<<endl;      
}
#endif