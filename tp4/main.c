#include <stdio.h>
#include <string.h>

//prototipo
char* ingresarNombre();
void ingresarNombrePuntero(char *nombre);
void ingresarNombreArray(char nombre[]);
void incrementar(int* n);
// void funcion(int x);

// int x = 10;
// void funcion(int x) {
//     printf("%d\n", x);
// }


// void contador() {
//  static int count = 0; //se inicializa una sola vez
//  count++;
//  printf("Contador: %d\n", count);
// }

// void contador() {
//  int count = 0;
//  count++;
//  printf("Contador: %d\n", count);
// }

static int count = 0;
void contador() {
 count++;
 printf("Contador: %d\n", count);
}

int main(){

    //1. char[] ingresarNombre();
    // no es valida la sintaxis
    // no se puede devolver arrays por valor
    
    // char* nombre = ingresarNombre();
    // printf("Hola %s\n", nombre);
    
    // // 2) 
    // char nombre2[20];
    // ingresarNombrePuntero(nombre2);
    // printf("Hola %s\n", nombre2);

    // // 3)
    // char nombre3[20];
    // ingresarNombreArray(nombre3);
    // printf("Hola %s\n", nombre3);


    // funcion(20);
    // printf("%d\n", x);

    // contador();
    // contador();
    // contador();

    // int x = 10;
    // for (int x = 0; x < 5; x++) {
    // printf("%d\n", x); // 0,1,2,3,4
    // }
    // printf("%d\n", x); // 10

    // int x = 10;
    // {
    //     int x = 20;
    //     printf("%d\n", x);
    // }
    // printf("%d\n", x);

    // int* a;
    // int b = 16;
    // a = &b;

    // printf("%d", *a);

    // int a[5] = {1, 2, 3 ,4 ,5};
    // int* p; 

    // p = &a[0];

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", *(p + i));
    //     printf("%p\n", p);
    // }
    

    // int a = 10;
    // int* n;
    // n = &a;
    // printf("%d\n", a);
    // incrementar(n);

    // int a[5] = {2,4,6,8,10};
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", a[i]*a[i]);
    // }

    // char c[] = "Esto es una cadena";
    // int i = 0;

    // while (c[i++] != '\0')
    // {
    //     printf("%d", i-1);
    // }
    // int l = strlen(c);
    // printf("%d\n", l);
    
    // for (int i = l - 1; i >= 0; i--)
    // {
    //     printf("%c", c[i]);
    // }

    int mitad = 5/2;
    printf("%d", mitad);
    

    return 0;
}

void incrementar(int* n){
    (*n)++;
    printf("%d", *n);
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

