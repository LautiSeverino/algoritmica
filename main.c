#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipo de funcs
void agregarProducto();
void menu();
void verProductos(char codigo[10]);
int verificarProducto(char codigo[10]);

int main(){
    menu();
    return 0;
}

// struct del producto
struct Producto {
    char codigo[10];
    char nombre[50];
    int stock;
    float precio;
};

// alias para struct y no escribir struct todo el tiempo que declare Producto
typedef struct Producto Producto;

//catalogo de productos
Producto productos[100];
// cantidad actual de productos
int cantidadProductos = 0;

//menu de opciones
void menu(){
    int opcion;
    do {
        printf("\n--- Menu de Productos ---\n");
        printf("1. Agregar producto\n");
        printf("2. Ver productos\n");
        printf("3. Buscar producto\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // func agregar prod
                agregarProducto(); 
                break;
            case 2:
                // func ver catalogo, case all prods
                verProductos(NULL); // como no se pasa ningun param va nul
                break;
            case 3: {
                char codigo[10];
                printf("Ingrese el codigo del producto a buscar: ");
                scanf("%s", codigo);
                //func ver catalogo by filter
                verProductos(codigo);
                break;
            }
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 4);
}

void agregarProducto(){
    // si ya hay 100 productos no deja agregar mas
    if(cantidadProductos >= 100){
        printf("No se pueden agregar mas productos. Catalogo lleno.\n");
        return;
    }
    //definir prod y construirlo
    Producto p;
    printf("Ingrese el codigo del producto: ");
    scanf("%s", p.codigo);
    // verificar si ya existe
    if(verificarProducto(p.codigo) != -1){
        printf("El producto ya existe.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    scanf("%s", p.nombre);
    printf("Ingrese el stock del producto: ");
    scanf("%d", &p.stock);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &p.precio);
    // add prod al catalogo en la posicion libre
    productos[cantidadProductos] = p;
    // incrementar catalogo para cuando se agregue otro y saber la cantidad de prods
    cantidadProductos++;
}

// get all de prods
void verProductos(char codigo[10]){
    // si no hay prods
    if(cantidadProductos == 0){
        printf("No hay productos registrados.\n");
        return;
    }
    // si hay filter
    if(codigo != NULL) {
        int index = verificarProducto(codigo);
        if(index != -1){ // si lo encontro
            printf("Codigo: %s, Nombre: %s, Stock: %d, Precio: %.2f\n", 
                productos[index].codigo, productos[index].nombre, 
                productos[index].stock, productos[index].precio);
        } else {
            printf("Producto no encontrado.\n");
        }
        return;
    }
    // si no hay filter
    for(int i = 0; i < cantidadProductos; i++){
        printf("Codigo: %s, Nombre: %s, Stock: %d, Precio: %.2f\n", 
            productos[i].codigo, productos[i].nombre, 
            productos[i].stock, productos[i].precio);
    }
}

// validacion de codigo
int verificarProducto(char codigo[10]){
    for(int i = 0; i < cantidadProductos; i++){
        if(strcmp(productos[i].codigo, codigo) == 0){ // comparar codigos
            return i; // devuelve la posicion del prod
        }
    }
    return -1; // devuelve -1 si no lo encuentra
}
