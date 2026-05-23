#ifndef TESTEENTRADA_H
#define TESTEENTRADA_H
bool teste_entrada(string numConversao, int base) {
    switch (base) {
        case 2:{
            for (int i = 0; i < numConversao.length(); i++)
            {
                if (numConversao[i] != '0' && numConversao[i] != '1'&& numConversao[i] != '.' && numConversao[i] != '-')
                {
                    cout<< endl << "Número inválido para a base 2. Tente novamente." << endl<<endl;
                    return false;
                }
            }
            return true;

            }break;
        case 8:{

            for (int i = 0; i < numConversao.length(); i++)
            {
                if (numConversao[i] != '0' && numConversao[i] != '1' && numConversao[i] != '2' && numConversao[i] != '3' && numConversao[i] != '4' && numConversao[i] != '5' && numConversao[i] != '6' && numConversao[i] != '7' && numConversao[i] != '.' && numConversao[i] != '-')
                {
                    cout<< endl << "Número inválido para a base 8. Tente novamente." << endl<<endl;
                    return false;
                }
            }
            return true;

        }break;
        case 10:
        {
            for (int i = 0; i < numConversao.length(); i++)
            {
                if (numConversao[i] != '0' && numConversao[i] != '1' && numConversao[i] != '2' && numConversao[i] != '3' && numConversao[i] != '4' && numConversao[i] != '5' && numConversao[i] != '6' && numConversao[i] != '7' && numConversao[i] != '8' && numConversao[i] != '9' && numConversao[i] != '.' && numConversao[i] != '-')
                {
                    cout<< endl << "Número inválido para a base 10. Tente novamente." << endl<<endl;
                    return false;
                }
            }
            return true;
        }
        break;
        case 16:{

            for (int i = 0; i < numConversao.length(); i++)
            {
                if (numConversao[i] != '0' && numConversao[i] != '1' && numConversao[i] != '2' && numConversao[i] != '3' && numConversao[i] != '4' && numConversao[i] != '5' && numConversao[i] != '6' && numConversao[i] != '7' && numConversao[i] != '8' && numConversao[i] != '9' && numConversao[i] != 'A' && numConversao[i] != 'B' && numConversao[i] != 'C' && numConversao[i] != 'D' && numConversao[i] != 'E' && numConversao[i] != 'F' && numConversao[i] != '.' && numConversao[i] != '-')
                {
                    cout<< endl << "Número inválido para a base 16. Tente novamente." << endl<<endl;
                    return false;
                }
            }
            return true;

        }break;
        default:{
            cout<< endl << "Base inválida. Tente novamente." << endl<<endl;
            return false;
        }  
    }        
}
#endif 