#define _POSIX_C_SOURCE 200809L
# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 



int arregloOrdenado();
void numsEnArreglo();
void bubbleSort(int *arr, int n);
int busquedaBinaria(int *arr, int n, int buscado);
void numsEnArregloBBSyBB();
void numsEnArregloBBSyBBCienMil();
void comparacionOrdenamientos();
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void comparacionOrdenamientosUnMill();

int main() {

    //arregloOrdenado();

    //numsEnArreglo();

    //numsEnArregloBBSyBB();

    //numsEnArregloBBSyBBCienMil();

    //comparacionOrdenamientos();

    comparacionOrdenamientosUnMill();
    return 0;
}

// ejercicio 1
int arregloOrdenado(){
    int nums[] = {3, 2, 2};

    int creciente = 1;
    int decreciente = 1;
    int longitud = sizeof(nums)/sizeof(nums[0]);

    for (int i = 0; i < longitud - 1; i++) {
        if (nums[i] < nums[i+1]) {
            decreciente = 0; // si sube, ya no es decreciente
        }
        if (nums[i] > nums[i+1]) {
            creciente = 0;   // si baja, ya no es creciente
        }
    }

    if (creciente || decreciente) {
        printf("SI estan ordenados\n");
    } else {
        printf("NO estan ordenados\n");
    }
}


// ejercicio 2
void numsEnArreglo(){
    int numsBuscados[] = {3,11, 330, 16, 5, 99 ,100 , 8, 9, 10};
    int cantNumsBuscados = sizeof(numsBuscados)/sizeof(numsBuscados[0]);
    int *nums = malloc(10000 * sizeof(int));
    int numeroRandom;
    int i = 0;
    int n = 0;
    

    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        nums[i] = rand() % 10001;
    }

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);  // INICIO medición


    // Búsqueda secuencial
    for (int n = 0; n < cantNumsBuscados; n++) {
        int encontrado = 0;

        for (int i = 0; i < 10000; i++) {
            if (nums[i] == numsBuscados[n]) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            printf("El número %d está\n", numsBuscados[n]);
        } else {
            printf("El número %d NO está\n", numsBuscados[n]);
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &t1); // FIN medición

    double ms = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                (t1.tv_nsec - t0.tv_nsec) / 1e6;

    printf("\nTiempo total de búsqueda secuencial: %.3f ms\n", ms);

    free(nums);
}

//ejercicio 3
void numsEnArregloBBSyBB(){
    int numsBuscados[] = {3,11, 330, 16, 5, 99 ,100 , 8, 9, 10};
    int cantNumsBuscados = sizeof(numsBuscados)/sizeof(numsBuscados[0]);
    int *nums = malloc(10000 * sizeof(int));
    int numeroRandom;
    int i = 0;
    int n = 0;
    int encontrado;

    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        nums[i] = rand() % 10001;
    }
    bubbleSort(nums, 10000);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);  // INICIO medición


    // Búsqueda binaria
    for (int i = 0; i < cantNumsBuscados; i++)
    {
        encontrado = busquedaBinaria(nums, 10000, numsBuscados[i]);
        if (encontrado == 1)
        {
            printf("se econtro el num %d\n", numsBuscados[i]);
        }
        if (encontrado == 1) {
            printf("El número %d está\n", numsBuscados[i]);
        } else {
            printf("El número %d NO está\n", numsBuscados[i]);
        }
    }
    

    clock_gettime(CLOCK_MONOTONIC, &t1); // FIN medición

    double ms = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                (t1.tv_nsec - t0.tv_nsec) / 1e6;

    printf("\nTiempo total de búsqueda binaria: %.3f ms\n", ms);

    free(nums);
}


//ejercicio 4
void numsEnArregloBBSyBBCienMil(){
    int numsBuscados[] = {3,11,330,16,5,99,100,8,9,10};
    int cantNumsBuscados = sizeof(numsBuscados)/sizeof(numsBuscados[0]);
    int *nums = malloc(100000 * sizeof(int));

    srand(time(NULL));

    // Generar 100000 números aleatorios
    for (int i = 0; i < 100000; i++) {
        nums[i] = rand() % 100000 + 1;
    }

    // --- MEDIR BÚSQUEDA SECUENCIAL ---
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    for (int n = 0; n < cantNumsBuscados; n++) {
        int encontrado = 0;

        for (int i = 0; i < 100000; i++) { // <--- ACÁ ESTABA EL ERROR
            if (nums[i] == numsBuscados[n]) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) printf("Secuencial: %d está\n", numsBuscados[n]);
        else            printf("Secuencial: %d NO está\n", numsBuscados[n]);
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);

    double msSec = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                   (t1.tv_nsec - t0.tv_nsec) / 1e6;
    printf("\nTiempo TOTAL búsqueda secuencial: %.3f ms\n\n", msSec);

    // --- ORDENAR FUERA DEL TIEMPO ---
    bubbleSort(nums, 100000);

    // --- MEDIR BÚSQUEDA BINARIA ---
    clock_gettime(CLOCK_MONOTONIC, &t0);

    for (int i = 0; i < cantNumsBuscados; i++) {
        int encontrado = busquedaBinaria(nums, 100000, numsBuscados[i]);
        if (encontrado) printf("Binaria: %d está\n", numsBuscados[i]);
        else            printf("Binaria: %d NO está\n", numsBuscados[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &t1);

    double msBin = (t1.tv_sec - t0.tv_sec) * 1000.0 +
                   (t1.tv_nsec - t0.tv_nsec) / 1e6;

    printf("\nTiempo total búsqueda binaria: %.3f ms\n", msBin);

    free(nums);
}


//ejercicio 5
void comparacionOrdenamientos() {
    int *base = malloc(100000 * sizeof(int));
    int *a = malloc(100000 * sizeof(int));
    int *b = malloc(100000 * sizeof(int));
    int *c = malloc(100000 * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        base[i] = rand() % 100000 + 1;
    }

    // Copias
    memcpy(a, base, 100000 * sizeof(int));
    memcpy(b, base, 100000 * sizeof(int));
    memcpy(c, base, 100000 * sizeof(int));

    struct timespec t0, t1;

    // Burbujeo
    clock_gettime(CLOCK_MONOTONIC, &t0);
    bubbleSort(a, 100000);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double tBubble = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    // Merge Sort
    clock_gettime(CLOCK_MONOTONIC, &t0);
    mergeSort(b, 0, 99999);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double tMerge = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    // Quick Sort
    clock_gettime(CLOCK_MONOTONIC, &t0);
    quickSort(c, 0, 99999);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double tQuick = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    printf("\nBurbujeo: %.3f ms\n", tBubble);
    printf("Merge Sort: %.3f ms\n", tMerge);
    printf("Quick Sort: %.3f ms\n", tQuick);

    free(base); free(a); free(b); free(c);
}

//ejercicio 6
void comparacionOrdenamientosUnMill() {
    int *base = malloc(1000000 * sizeof(int));
    int *a = malloc(1000000 * sizeof(int));
    int *b = malloc(1000000 * sizeof(int));
    int *c = malloc(1000000 * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < 1000000; i++) {
        base[i] = rand() % 1000000 + 1;
    }

    // Copias
    memcpy(a, base, 1000000 * sizeof(int));
    memcpy(b, base, 1000000 * sizeof(int));
    memcpy(c, base, 1000000 * sizeof(int));

    struct timespec t0, t1;

    // // Burbujeo
    // clock_gettime(CLOCK_MONOTONIC, &t0);
    // bubbleSort(a, 1000000);
    // clock_gettime(CLOCK_MONOTONIC, &t1);
    // double tBubble = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    // Merge Sort
    clock_gettime(CLOCK_MONOTONIC, &t0);
    mergeSort(b, 0, 999999);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double tMerge = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    // Quick Sort
    clock_gettime(CLOCK_MONOTONIC, &t0);
    quickSort(c, 0, 999999);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double tQuick = (t1.tv_sec-t0.tv_sec)*1000.0 + (t1.tv_nsec-t0.tv_nsec)/1e6;

    //printf("\nBurbujeo: %.3f ms\n", tBubble);
    printf("Merge Sort: %.3f ms\n", tMerge);
    printf("Quick Sort: %.3f ms\n", tQuick);

    free(base); free(a); free(b); free(c);
}




void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m+1, k = 0;
    int size = r-l+1;
    int *temp = malloc(size * sizeof(int));

    while (i <= m && j <= r)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = 0; i < size; i++)
        arr[l+i] = temp[i];

    free(temp);
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[i];
    arr[i] = arr[high];
    arr[high] = tmp;
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
}

int busquedaBinaria(int *arr, int n, int buscado) {
    int izq = 0, der = n - 1;

    while (izq <= der) {
        int mid = (izq + der) / 2;
        if (arr[mid] == buscado) return 1;
        if (arr[mid] < buscado) izq = mid + 1;
        else der = mid - 1;
    }
    return 0;
}


