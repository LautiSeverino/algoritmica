#include <stdio.h>
#include <string.h>
#include <math.h>

int  leerCadenaParentesisRecursiva(char cadena[], int indice, int balance);
int fun(int n);
int esPalindromo(char* cadena, int longitud);
int potencia(int n, int m);
void piramide(int n, int nivelActual);
void dineroBilletesMonedas(int monto, int i);
void descomposicionEnFactoresPrimos(int num, int i);
void invertirElementos(int* nums, int i, int longitud);

int main() { 
    // char cadena[100];
    // printf("Ingrese una cadena de parentesis: ");
    // scanf("%s", cadena);

    // int resultado = leerCadenaParentesisRecursiva(cadena, 0, 0);

    // if (resultado == 0)
    //     printf("Los parentesis estan balanceados.\n");
    // else
    //     printf("Los parentesis NO estan balanceados.\n");

    // int n = 5;
    // int resultado = fun(n);


    // char* provincia = "asd";
    // int longitud = strlen(provincia);
    // int palindromo = esPalindromo(provincia, longitud);

    // if (palindromo == 0) {
    //     printf("La cadena NO es un palindromo.\n");
    // } else {
    //     printf("La cadena es un palindromo.\n");
    // }


    // int pot = potencia(2, 5);
    // printf("potencia %d\n", pot);


    //piramide(5, 1);


    //dineroBilletesMonedas(45000, 0);

    //descomposicionEnFactoresPrimos(256, 2);

    int nums[] = {1, 2, 3};
    int longitud = sizeof(nums)/sizeof(nums[0]);

    invertirElementos(nums, 0,longitud);
    printf("Elementos invertidos:\n");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
 // aa
 // ab
//ejercicio 1
int esPalindromo(char* cadena, int longitud) {
    if (longitud <= 1) return 1; // si tiene 0 o 1 caracteres es palindromo
    if (cadena[0] != cadena[longitud - 1]) return 0; // comparar primer y ultimo cacter 
    return esPalindromo(cadena + 1, longitud - 2); //son iguales los cacteres, entonces llama a la func
}

// 2^4 = 2 * (2^3)
// 2^3 = 2 * (2^2)
// 2^2 = 2 * (2^1)
// 2^1 = 2              ← acá ya sabemos el resultado
//ejercicio 2
int potencia(int m, int n){
    if(n == 0) return 1;
    if(n == 1) return m;
    return m * potencia(m, n - 1);
}

//ejercicio 3
// es para saber si el num pasado es par o impar
// int f(int n) {
//  if (n == 0) {
//  return 1;
//  } else if (n == 1) {
//  return 0;
//  } else {
//  return f(n - 2);
//  }
// }

//ejercicio 4
void piramide(int n, int nivelActual) {
    if (nivelActual > n) return;

    imprimirEspacios(n - nivelActual);
    imprimirFila(nivelActual, nivelActual);
    printf("\n");

    piramide(n, nivelActual + 1);
}

void imprimirFila(int num, int rep) {
    if (rep == 0) return;
    printf("%d ", num);
    imprimirFila(num, rep - 1);
}

void imprimirEspacios(int cant) {
    if (cant == 0) return;
    printf(" ");
    imprimirEspacios(cant - 1);
}

int fun(int n) {
    if (n == 0) return 1; // Caso base
    printf("%d\n", n);
    return n + fun(n - 1); // Llamada recursiva acercándose al caso base
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

//ejercicio 6
int denominaciones[] = {20000, 10000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 1};
char* nombres[] = {
    "billetes de veinte mil",
    "billetes de diez mil",
    "billetes de dos mil",
    "billetes de mil",
    "billetes de quinientos",
    "billetes de doscientos",
    "billetes de cien",
    "billetes de cincuenta",
    "billetes de veinte",
    "billetes de diez",
    "monedas de cinco",
    "monedas de uno"
};

void dineroBilletesMonedas(int monto, int i) {
    if (monto == 0 || i == 12) return;

    int cant = monto / denominaciones[i];
    if (cant > 0) {
        printf("%d %s\n", cant, nombres[i]);
    }

    dineroBilletesMonedas(monto % denominaciones[i], i + 1);
}

//ejercicio 7 3,2
void descomposicionEnFactoresPrimos(int num, int i){
    if (num == 1) return; 

    if (num % i == 0){
        printf("%d\n", i);
        descomposicionEnFactoresPrimos(num / i, i);
    } else {
        descomposicionEnFactoresPrimos(num, i + 1);
    } 
}


void invertirElementos(int* nums, int i, int longitud){
    if (i >= longitud - 1 - i) return; // caso base (cuando se cruzan o se tocan)

    int tmp = nums[i];
    nums[i] = nums[longitud - 1 - i];
    nums[longitud - 1 - i] = tmp;

    invertirElementos(nums, i + 1, longitud);
}