#include <stdio.h>

//prototipo
char* ingresarNombre();
void ingresarNombrePuntero(char *nombre);
void ingresarNombreArray(char nombre[]);

int main(){

    //1. char[] ingresarNombre();
    // no es valida la sintaxis
    // no se puede devolver arrays por valor
    
    char* nombre = ingresarNombre();
    printf("Hola %s\n", nombre);
    
    // 2) 
    char nombre2[20];
    ingresarNombrePuntero(nombre2);
    printf("Hola %s\n", nombre2);

    // 3)
    char nombre3[20];
    ingresarNombreArray(nombre3);
    printf("Hola %s\n", nombre3);

    
    return 0;
}

// retorna puntero a char
char* ingresarNombre(){
    static char nombre[20]; //static para que persista el array 
    printf("Ingrese su nombre: \n");
    scanf("%s", nombre);
    return nombre;
}

// se le pasa el arreglo como param con puntero
void ingresarNombrePuntero(char *nombre) {
    printf("Ingrese su nombre: \n");
    scanf("%s", nombre);
}

// se le pasa el param como arreglo (equivalente a la func del puntero)
void ingresarNombreArray(char nombre[]) {
    printf("Ingrese su nombre: \n");
    scanf("%s", nombre);
}