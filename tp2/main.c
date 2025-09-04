#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include <string.h>

void arrayRandom(void);
void diezArrayRandom(void);
void sumaVectores(void);
void arrayEstadisticas(void);
void arraySinDuplicados(void);
void imprimirArray(void);
void fechaMayorYMenor(void);
void palabrasEnOrdenAlfabetico(void);
void palabrasDiferentes(void);
void palabrasEnDiccionario(void);

int main() {

    //arrayRandom();
    //diezArrayRandom();
    //sumaVectores();
    //arrayEstadisticas();
    //arraySinDuplicados();
    //imprimirArray();
    //fechaMayorYMenor();
    //palabrasEnOrdenAlfabetico();
    //palabrasDiferentes();
    palabrasEnDiccionario();
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

//ejercicio 8
void fechaMayorYMenor(void){
    char fechas[10][11] = {
        "01-01-2025",
        "04-03-2025",
        "02-10-2025",
        "15-06-2001",
        "30-08-2025",
        "20-04-2025",
        "19-07-2025",
        "13-10-2025",
        "08-12-2025",
        "06-09-1990"
    };
    int longitud = sizeof(fechas) / sizeof(fechas[0]);
    
    int dia, mes, anio;
    int diaMayor, mesMayor, anioMayor;
    int diaMenor, mesMenor, anioMenor;
    
    sscanf(fechas[0],"%2d-%2d-%4d", &diaMenor, &mesMenor, &anioMenor);
    
    diaMayor = diaMenor;
    mesMayor = mesMenor;
    anioMayor = anioMenor;

    for (int i = 0; i < longitud; i++)
    {
        sscanf(fechas[i],"%2d-%2d-%4d", &dia, &mes, &anio);

        if ((dia > diaMayor && mes >= mesMayor && anio >= anioMayor) ||
        (mes > mesMayor && anio >= anioMayor) ||
        (anio > anioMayor))
        {
            diaMayor = dia;
            mesMayor = mes;
            anioMayor = anio;
        }

        if ((anio < anioMenor) ||
        (mes < mesMenor && anio <= anioMenor) ||
        (dia < diaMenor && mes <= mesMenor && anio <= anioMenor))
        {
            diaMenor = dia;
            mesMenor = mes;
            anioMenor = anio;
        }
        
    }
    
    printf("Fecha Menor: %2d-%2d-%4d \n", diaMenor, mesMenor, anioMenor);
    printf("Fecha Mayor: %2d-%2d-%4d", diaMayor, mesMayor, anioMayor);

}

//ejercicio 9
void palabrasEnOrdenAlfabetico(void) {
    char continua[10];
    char palabra[20];
    char palabras[10][20] = {""};
    int count = 0; // cuántas palabras tenemos ahora

    do {
        printf("Ingrese la palabra: ");
        scanf("%s", palabra);

        // Verificar si ya está lleno
        if (count == 10) {
            // Ver si la nueva palabra debería ir al final
            if (strcmp(palabra, palabras[10-1]) > 0) {
                printf("La palabra no se inserta (es la ultima alfabeticamente).\n");
            } else {
                // Insertar desplazando y perdiendo la última
                int i = 10 - 2;
                while (i >= 0 && strcmp(palabra, palabras[i]) < 0) {
                    strcpy(palabras[i+1], palabras[i]);
                    i--;
                }
                strcpy(palabras[i+1], palabra);
            }
        } else {
            // Insertar normal si aún hay espacio
            int i = count - 1;
            while (i >= 0 && strcmp(palabra, palabras[i]) < 0) {
                strcpy(palabras[i+1], palabras[i]);
                i--;
            }
            strcpy(palabras[i+1], palabra);
            count++;
        }

        // Mostrar estado actual del arreglo
        for (int i = 0; i < count; i++) {
            printf("%s ", palabras[i]);
        }
        printf("\n");

        printf("Desea continuar? (si/fin) \n");
        scanf("%s", continua);

    } while (strcmp(continua, "fin") != 0);
}


//ejercicio 10
void palabrasDiferentes(void) {
    char palabras[20][30];
    char palabra[30];
    char continua[3];
    float porcentajeIgualdad= 0;
    float letrasIguales = 0;
    int esValida = 1; 
    int count = 0;


    do
    {   
        printf("Ingrese la palabra: ");
        scanf("%s", palabra);
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < strlen(palabras[i]); j++)
            {
                if (palabras[i][j] == palabra[j])
                {
                    letrasIguales ++;
                }
            }
            float len = strlen(palabra);
            if (strlen(palabras[i]) > strlen(palabra))
            {
                porcentajeIgualdad = letrasIguales / strlen(palabras[i]);
            } else
            {
                porcentajeIgualdad += letrasIguales / len;
            }
            
            porcentajeIgualdad *= 100;
            
            if (porcentajeIgualdad == 0.0) {
                strcpy(palabras[count], palabra);
                break;
            }

            if (porcentajeIgualdad >= 80.0){
                printf("No es al menos un 20 porciento diferente: (%f) \n", porcentajeIgualdad);
                esValida = 0;
                break;
            }
            letrasIguales = 0.0;
        }

        if (esValida && count < 20) {
        strcpy(palabras[count], palabra);
        count++;
    }
    
    
    for (int t = 0; t < count; t++)
    {
        printf("%s \n", palabras[t]);
    }

            printf("\n");
            
            printf("Desea continuar? (si/fin) \n");
            scanf("%s", continua);
            
    } while (strcmp(continua, "fin") != 0);
    
    
}

//ejericio 11 
void palabrasEnDiccionario(void) {

    char diccionario[1000][30];
    char oracion[300];
    int cantPalabras = 0;
    char continua[4];

    
    do
    {
        printf("Ingrese la oracion:");
        fgets(oracion, sizeof(oracion), stdin); // leer con espacios hasta enter
        oracion[strcspn(oracion, "\n")] = 0; // eliminar salto de linea de enter

        char *palabra = strtok(oracion, " "); //separa palabras por cada espacio
        while (palabra != NULL)
        {
            int encontrada = 0;
            for (int i = 0; i < cantPalabras; i++)
            {
                if (strcmp(diccionario[i], palabra) == 0) // si son iguales
                {
                    encontrada = 1;
                    break;
                }
            }

            if (!encontrada)
            {
                printf("La palabra (%s) no esta en el diccionario, desea agregarla (s/n) :", palabra);
                char respuesta[3];
                fgets(respuesta, sizeof(respuesta), stdin);
                if (respuesta[0] == 's' && cantPalabras < 1000) // si dice que si, la agrega
                {
                    strcpy(diccionario[cantPalabras], palabra);
                    cantPalabras++;
                }
            }

            palabra = strtok(NULL, " "); // que siga con la siguiente palabra despues del espacio en donde paro hasta el proximo espacio
        }
        printf("\nDiccionario: \n");
        for (int i = 0; i < cantPalabras; i++)
        {
            printf("%s\n", diccionario[i]);
        }
        
        printf("\nDesea continuar? (si/fin): ");
        fgets(continua, sizeof(continua), stdin);
        continua[strcspn(continua, "\n")] = 0; // sacar enter

    } while (strcmp(continua, "fin") != 0);

}