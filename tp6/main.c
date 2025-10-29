#include <stdio.h>

int  leerCadenaParentesisRecursiva(char cadena[], int indice, int balance);

int main() { 
    char cadena[100];
    printf("Ingrese una cadena de parentesis: ");
    scanf("%s", cadena);

    int resultado = leerCadenaParentesisRecursiva(cadena, 0, 0);

    if (resultado == 0)
        printf("Los parentesis estan balanceados.\n");
    else
        printf("Los parentesis NO estan balanceados.\n");

    return 0; 
}


//ejercicio 5
int  leerCadenaParentesisRecursiva(char cadena[], int indice, int balance) {
    // Caso base: fin de cadena
    if (cadena[indice] == '\0') {
        return balance; // Si termina con 0 => balanceado
    }

    if (cadena[indice] == '(') {
        balance++;
    } else if (cadena[indice] == ')') {
        balance--;
    }

    // Si en algun momento hay mas ')' que '(' => ya esta mal
    if (balance < 0) {
        return -1;
    }

    // Llamada recursiva de la func al siguiente caracter
    return leerCadenaParentesisRecursiva(cadena, indice + 1, balance);
}