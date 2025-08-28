#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

void arrayRandom(void);
void diezArrayRandom(void);
void sumaVectores(void);
void arrayEstadisticas(void);
void arraySinDuplicados(void);
void imprimirArray(void);


int main() {

    //arrayRandom();
    //diezArrayRandom();
    //sumaVectores();
    //arrayEstadisticas();
    //arraySinDuplicados();
    imprimirArray();
    return 0;
}


//ejercicio 1
void arrayRandom(void) {
    //semilla generacion numero random
    srand(time(NULL));

    int numeros[10];
    int longitud = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < longitud; i++)
    {
        int numeroRandom;
        int repetido;

        do
        {
            numeroRandom = rand() % 11;
            repetido = 0;

            for (int j = 0; j < i; j++)
            {
                if (numeros[j] == numeroRandom)
                {
                    repetido = 1;
                    break;
                }
            }
            
        } while (repetido);

        numeros[i] = numeroRandom;
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

//ejercicio 2

void diezArrayRandom(void) {
    
    //semilla generacion numero random
    srand(time(NULL));
    
    // cada indice de representa ese numero
    // cuando sale un numero va a esa posicion del array e incrementa en uno el valor que por defecto esta en cero
    int frecuencias[11] = {0};  // inicializar en 0

    int numeros[10];
    int longitud = sizeof(numeros) / sizeof(numeros[0]);

    
    for (int t = 0; t < 10; t++)
    {
    
        for (int i = 0; i < longitud; i++)
        {
            int numeroRandom;
            int repetido;

            do
            {
                numeroRandom = rand() % 11;
                repetido = 0;

                for (int j = 0; j < i; j++)
                {
                    if (numeros[j] == numeroRandom)
                    {
                        repetido = 1;
                        break;
                    }
                }
                
            } while (repetido);

            numeros[i] = numeroRandom;
        }

        for (int p = 0; p < 10; p++)
        {
            frecuencias[numeros[p]]++;
        }
    
    }

    for (int i = 0; i < 11; i++) {
        printf("Numero %2d -> %d veces\n", i, frecuencias[i]);
    }
    
    printf("\n");
}

//ejercicio 3
void sumaVectores(void){
    int vector1[] = {1, 2, 3, 4, 5};
    int vector2[] = {6, 7, 8, 9, 10};
    int suma[5];
    int longitud = sizeof(suma) / sizeof(suma[0]);

    for (int i = 0; i < longitud; i++)
    {
        suma[i] = vector1[i] + vector2[i];
        printf("%d + %d = %d \n", vector1[i], vector2[i], suma[i]);
    }
}

//ejercicio 4
void arrayEstadisticas(void) {
    
    srand(time(NULL));
    int numeros[50]; 
    int numeroRandom;
    int moda[11] = {0};
    int longitud = sizeof(numeros) / sizeof(numeros[0]);
    int numeroModa = 0;
    int maxFrecuencia = moda[0];
    int suma = 0;
    
    for (int i = 0; i < longitud; i++)
    {
        numeroRandom = rand() % 11;
        numeros[i] = numeroRandom;
        moda[numeroRandom]++;
        suma +=numeroRandom;
    }
    
    for (int i = 0; i < 11; i++)
    {
        if(moda[i] > maxFrecuencia) {
            maxFrecuencia = moda[i];
            numeroModa = i;
        }
    }

    double media = (double)suma / 50;

    double varianza = 0.0;
    for (int i = 0; i < longitud; i++)
    {
        double diff = numeros[i] - media;
        varianza = diff * diff;
    }
    
    varianza /= longitud - 1;
    double desviacion = sqrt(varianza);

    printf("Numeros generados:\n");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nModa: %d (aparecio %d veces)\n", numeroModa, maxFrecuencia);
    printf("Media: %f\n", media);
    printf("Desviacion estandar: %f", desviacion);
}


//ejercicio 5
void arraySinDuplicados(void) {
    
    srand(time(NULL));

    int numeros[20];
    int sinDuplicados[20];
    int numeroRandom;
    int nuevoTam = 0;
    int longitud = sizeof(numeros) / sizeof(numeros[0]); 


    for (int i = 0; i < longitud; i++)
    {
        numeroRandom = rand() % 10;
        numeros[i] = numeroRandom;
        printf("%d ", numeros[i]);
    }

    for (int i = 0; i < longitud; i++)
    {
        int yaExiste = 0;
        for (int j = 0; j < nuevoTam; j++)
        {
            if (numeros[i] == sinDuplicados[j])
            {
                yaExiste = 1;
                break;
            }
        }
        if (!yaExiste)
        {
            sinDuplicados[nuevoTam] = numeros[i];
            nuevoTam++;
        }
        
    }
    
    printf("Array sin duplicados \n");
    for (int i = 0; i < nuevoTam; i++)
    {
        printf("%d ", sinDuplicados[i]);
    }

} 

//ejercicio 7
void imprimirArray(void){

    char *palabras[10] = {"hola", "chau", "perro", "casa", "gato", "azul", "rojo", "lapiz", "celular", "dado"};
    int longitud = sizeof(palabras) / sizeof(palabras[0]); 
    
    printf("Al derecho: \n");
    for (int i = 0; i < longitud; i++)
    {
        printf("%s ", palabras[i]);
    }

    printf("\n---------\n");

    printf("Al reves: \n");
    for (int i = longitud - 1; i >= 0; i--)
    {
        printf("%s ", palabras[i]);
    }
}
