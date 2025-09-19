#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Fecha {
 int dia;
 int mes;
 int anio;
};
struct Persona {
 char nombre[50];
 char apellido[50];
 struct Fecha fechaNacimiento;
 int edad;
};


// prototipo de funcs
void agregarProducto();
void menu();
void verProductos(char codigo[10]);
int verificarProducto(char codigo[10]);
void cargarPersona(struct Persona *p);
int calcularEdad(struct Fecha fn);
void imprimirPersona(struct Persona p);


int main(){
    //menu();
    struct Persona persona;

    cargarPersona(&persona);
    persona.edad = calcularEdad(persona.fechaNacimiento);
    imprimirPersona(persona);
    return 0;
}




// Función para cargar datos de la persona
void cargarPersona(struct Persona *p) {
    printf("Ingrese nombre: ");
    fgets(p->nombre, sizeof(p->nombre), stdin);
    p->nombre[strcspn(p->nombre, "\n")] = 0; // quitar salto de línea

    printf("Ingrese apellido: ");
    fgets(p->apellido, sizeof(p->apellido), stdin);
    p->apellido[strcspn(p->apellido, "\n")] = 0;

    printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &p->fechaNacimiento.dia, &p->fechaNacimiento.mes, &p->fechaNacimiento.anio);
}

// Función para calcular edad
int calcularEdad(struct Fecha fn) {
    time_t t = time(NULL);
    struct tm *hoy = localtime(&t);

    int edad = hoy->tm_year + 1900 - fn.anio;

    // Ajustar si no cumplió años todavía este año
    if (fn.mes > hoy->tm_mon + 1 || (fn.mes == hoy->tm_mon + 1 && fn.dia > hoy->tm_mday)) {
        edad--;
    }

    return edad;
}

// Función para imprimir datos
void imprimirPersona(struct Persona p) {
    printf("La persona %s %s nació el día %02d-%02d-%04d y tiene %d años de edad.\n",
           p.nombre, p.apellido,
           p.fechaNacimiento.dia,
           p.fechaNacimiento.mes,
           p.fechaNacimiento.anio,
           p.edad);
}



// struct del producto
struct Producto {
    char codigo[10];
    char nombre[50];

    // union guarda un espacio en memoria que puede ser de un tipo de dato o de otro pero no de ambos al mismo tiempo
    // union para stock
    union {
        int unidades;
        float kilosLitros;
    } stock;

    int tipoStock; // 0 = unidades, 1 = kilos/litros
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

    printf("Ingrese el tipo de stock del producto (0 = unidades, 1 = kilos/litros): ");
    scanf("%d", &p.tipoStock);

    if(p.tipoStock == 0) {
        printf("Ingrese el stock en unidades: ");
        scanf("%d", &p.stock.unidades); //entero
    } else {
        printf("Ingrese el stock en kilos/litros: ");
        scanf("%f", &p.stock.kilosLitros); //float
    }

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
                productos[index].precio);

                if(productos[index].tipoStock == 0) {
                    printf("Stock en unidades: %d\n", productos[index].stock.unidades);
                } else {
                    printf("Stock en kilos/litros: %.2f\n", productos[index].stock.kilosLitros);
                }
        } else {
            printf("Producto no encontrado.\n");
        }
        return;
    }
    // si no hay filter
    for(int i = 0; i < cantidadProductos; i++){
        printf("Codigo: %s, Nombre: %s, Stock: %d, Precio: %.2f\n", 
            productos[i].codigo, productos[i].nombre, 
            productos[i].precio);

            if(productos[i].tipoStock == 0) {
                printf("Stock en unidades: %d\n", productos[i].stock.unidades);
            } else {
                printf("Stock en kilos/litros: %.2f\n", productos[i].stock.kilosLitros);
            }
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
