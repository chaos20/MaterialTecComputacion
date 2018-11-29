#include <iostream>
#include <string>
#include <ArrayStack.h>
#include <LinkedStack.h>

using namespace std;

int main(){
    char opStk;
    cout << "elija el tipo de Pila a usar: A=Array Stack o L=Linked Stack" << endl;
    cin >> opStk;
    if (opStk == 'A'){
        string cadena;
        int tam;
        bool cadCorrecta = true;
        cout << "Introdusca la cadena a leer: " << endl;
        cin >> cadena;
        tam = cadena.size();
        ArrayStack<char> ArS(tam);
        for(int i = 0; i < tam; i++){
            if (cadena[i] == '{' || cadena[i] == '(' || cadena[i] == '['){
                ArS.push(cadena[i]);
            }
            if(ArS.isEmpty()){
                cadCorrecta = false;
                break;
            }
            else{
                if(cadena[i] == '}' && ArS.topValue() != '{'){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == ']' && ArS.topValue() != '['){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == ')' && ArS.topValue() != '('){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == '}' && ArS.topValue() == '{'){
                ArS.pop();
                }
                if(cadena[i] == ']' && ArS.topValue() == '['){
                ArS.pop();
                }
                if(cadena[i] == ')' && ArS.topValue() == '('){
                ArS.pop();
                }
            }
        }
        if (cadCorrecta){
            cout << "cadena valida" << endl;
        }
        else{
            cout << "cadena invalida" << endl;
        }
    }
    if (opStk == 'L'){
        string cadena;
        int tam;
        bool cadCorrecta = true;
        cout << "Introdusca la cadena a leer: " << endl;
        cin >> cadena;
        tam = cadena.size();
        LinkedStack<char> LnS;
        for(int i = 0; i < tam; i++){
            if (cadena[i] == '{' || cadena[i] == '(' || cadena[i] == '['){
                LnS.push(cadena[i]);
            }
            if(LnS.isEmpty()){
                cadCorrecta = false;
                break;
            }
            else{
                if(cadena[i] == '}' && LnS.topValue() != '{'){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == ']' && LnS.topValue() != '['){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == ')' && LnS.topValue() != '('){
                cadCorrecta = false;
                break;
                }
                if(cadena[i] == '}' && LnS.topValue() == '{'){
                LnS.pop();
                }
                if(cadena[i] == ']' && LnS.topValue() == '['){
                LnS.pop();
                }
                if(cadena[i] == ')' && LnS.topValue() == '('){
                LnS.pop();
                }
            }
        }
        if (cadCorrecta){
            cout << "cadena valida" << endl;
        }
        else{
            cout << "cadena invalida" << endl;
        }
    }

    return 0;
}
