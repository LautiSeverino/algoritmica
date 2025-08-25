#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayRandon(void);


int main() {

    arrayRandon();


    return 0;
}


//ejercicio 1
void arrayRandon(void) {
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