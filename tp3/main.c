#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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


// prototipo de funcs
int esPrimo(int numero);
int calcularEdad(int diaNac, int mesNac, int anioNac); 
void imprimir(char nombre[]);
int producto(int factor1, int factor2);
int potencia(int base, int exponente);
void calculadora(void);
int suma (int a, int b);
int resta (int a, int b);
int multiplicacion (int a, int b);
int division (int a, int b);
int verificarCapicua(int numero);
void arrayCapicua();
void imprimirFecha(struct Fecha f);
void fechaActual();

void menuGeo();
void ingresarPuntoGeo();
void calcularDistancia();
double haversine(double lat1, double lon1, double lat2, double lon2);
int buscarGeoPoint(char nombre[30]);
void getGeoPoints();

void agregarProducto();
void menu();
void verProductos(char codigo[10]);
int verificarProducto(char codigo[10]);
void cargarPersona(struct Persona *p);
int calcularEdadDesdeFecha(struct Fecha fn);
void imprimirPersona(struct Persona p);


int main(){
    // int num;
    // printf("Ingrese un numero: ");
    // scanf("%d", &num);
    // int numPrimo = esPrimo(num);
    // if (numPrimo)
    // {
    //     printf("%d es primo", num);
    // } else {
    //     printf("%d no es primo", num);
    // }

    
    // int dia, mes, anio, edad;
    // printf("Ingrese su dia de nacimiento: ");
    // scanf("%d", &dia);
    
    // printf("Ingrese su mes de nacimiento: ");
    // scanf("%d", &mes);
    
    // printf("Ingrese su año de nacimiento: ");
    // scanf("%d", &anio);
    
    // edad = calcularEdad(dia, mes, anio);
    // printf("Su edad es %d", edad);


    // char nombre[30];
    // printf("Ingrese su nombre: ");
    // scanf("%s", nombre);
    // imprimir(nombre);


    // int num1, num2, result;
    // printf("Ingrese el primer factor: ");
    // scanf("%d", &num1);
    
    // printf("Ingrese el segundo factor: ");
    // scanf("%d", &num2);

    // result = producto(num1, num2);
    // printf("%d * %d = %d",num1, num2, result);

    // int base, exponente, resultado;
    // printf("Ingrese la base: ");
    // scanf("%d", &base);

    // printf("Ingrese la potencia: ");
    // scanf("%d", &exponente);

    // resultado = potencia(base, exponente);
    // printf("Resultado: %d", resultado);


    //arrayCapicua();


    // struct Fecha f;
    // printf("ingrese fecha (dd/mm/aaaa): \n");
    // scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);

    // imprimirFecha(f);


    //fechaActual();



    //menu();


    // struct Persona persona;

    // cargarPersona(&persona);

    // imprimirPersona(persona);

    menuGeo();


    return 0;
}

//ejercicio 1
int esPrimo(int numero){
    int j, i, numEsPrimo;

    if (numero <= 1) return 0;

    numEsPrimo = 1;
    for ( i = 2; i*i <= numero; i++)
    {
            if (numero % i == 0)
            {
                numEsPrimo = 0;
                return numEsPrimo;
            }
            
    }

    return numEsPrimo;
}

//ejercicio 2
int calcularEdad(int diaNac, int mesNac, int anioNac) {
    int edad;
    time_t t = time(NULL); //tiempo actual
    struct tm *fechaActual = localtime(&t); //devuelve puntero a un struct con fecha y hora local
    
    //tm_yesr no da el año directamente, te da la cantida de años desde el 1900
    // entonces aca seteamos año actual
    //fecha es un struct con -> se accede a los miembros
    int anioActual = fechaActual->tm_year + 1900;
    // sin +1 muestra mes anetrior 
    // tm_mon (0-11)
    int mesActual = fechaActual->tm_mon + 1;
    int diaActual = fechaActual->tm_mday;
    
    edad = anioActual - anioNac;
    
    if (mesActual < mesNac || (mesNac == mesActual && diaActual > diaNac)){
        edad--;
    }
    return edad;
}

//ejercicio 3
void imprimir(char nombre[]) {
    printf("Hola %s!", nombre);
}


//ejercicio 4
int producto(int factor1, int factor2) {
    int result;
    result = 0;
        for (int i = 0; i < factor1; i++)
    {
        result += factor2;
    }

    return result;
}
// ejercicio 4
int potencia(int base, int exponente){
    int resultado, acumulador;
    
    resultado = 1;
    
    for (int i = 1; i <= exponente; i++){
        acumulador = 0;
        for (int j = 0; j < base; j++)
        {
            acumulador += resultado; 
        }
        resultado = acumulador;
    }
    return resultado;
}

//ejercicio 5
void calculadora(void){
    int num1, num2, resultado;
    char operador;
    printf("Ingrese el primer numero: \n");
    scanf("%d", &num1);

    
    printf("Ingrese el operador: \n");
    //con espacio para limpiar buffer
    scanf(" %c", &operador);

    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);

    switch (operador)
    {
    case '+':
        resultado = suma(num1, num2);
        break;
    case '-':
        resultado = resta(num1, num2);
        break;
    case '*':
        resultado = multiplicacion(num1, num2);
        break;
    case '/':
        resultado = division(num1, num2);
        break;
    default:
        printf("Operando no configurado");
    }
    if (num2 != 0 || operador != '/'){
        printf("%d %c %d = %d", num1, operador, num2, resultado);
    }
}


int suma (int a, int b){
    return a + b;
}
int resta (int a, int b){
    return a - b;
}
int multiplicacion (int a, int b){
    return a * b;
}
int division (int a, int b){
    if (b == 0){
        printf("No se puede dividir entre cero");
        return 0;
    }
    return a / b;
}


//ejercicio 6
void arrayCapicua(){

    srand(time(NULL));

    int numeros[10];
    int contador = 0;
    int intentos = 0;
        while (contador < 10)
        {
            intentos +=1;
            int numRandom = rand() % 100000;
            if(verificarCapicua(numRandom)){
                numeros[contador] = numRandom;
                contador++;
            }
        }
    
    printf("numeros generados (intentos): %d\n", intentos);
    printf("Numeros Capicua:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numeros[i]);
    }
}

int verificarCapicua(int numero){
    int ultimoDigito, numeroInvertido, numeroOriginal;
    numeroOriginal = numero;
    numeroInvertido = 0;
    
    //algoritmo inversion
    while (numero != 0)
    {
        //obtener ultimo digito
        ultimoDigito = numero % 10;
        //construir numero invertido
        numeroInvertido = numeroInvertido * 10 + ultimoDigito;
        //eliminar ultimo digito
        numero /= 10;
    }
    
    if (numeroOriginal != numeroInvertido) {
        return 0;
    }
    return 1;
}

//ejercicio 8
void imprimirFecha(struct Fecha f){
    printf("Fecha: %d/%d/%d", f.dia, f.mes, f.anio);
}

//ejercicio 9
void fechaActual(){
        // 1. Obtener el tiempo actual en segundos desde Epoch
    time_t t = time(NULL);

    // 2. Convertirlo a fecha/hora local
    struct tm *fecha = localtime(&t);

    // 3. Imprimir con formato dd/mm/yyyy
    printf("Hoy es %02d/%02d/%04d\n",
            fecha->tm_mday,
            fecha->tm_mon + 1,       // tm_mon va de 0 a 11 → sumamos 1
            fecha->tm_year + 1900);  // tm_year es años desde 1900
}



// ejercicio 10
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

    p->edad = calcularEdadDesdeFecha(p->fechaNacimiento);
}

// Función para calcular edad
int calcularEdadDesdeFecha(struct Fecha fn) {
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

//ejercico 11 y 12

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
            printf("Codigo: %s, Nombre: %s, Precio: %.2f\n", 
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
        printf("Codigo: %s, Nombre: %s, Precio: %.2f\n", 
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


//ejercicio 13
#define PI 3.14159265358979323846

struct GeoPoint {
    char nombre[30];
    float latitud;
    float longitud;
};

typedef struct GeoPoint GeoPoint;

GeoPoint GeoPoints[100];
int cantidadGeoPoints = 0;

void menuGeo(){
    int opcion;
    do
    {
        printf("\n--- Menu de Geo Points ---\n");
        printf("1. Agregar Geo Point\n");
        printf("2. Calcular Distancia entre 2 geo points\n");
        printf("3. Ver geo Points\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarPuntoGeo();
            break;
        case 2:
            calcularDistancia();
            break;
        case 3:
            getGeoPoints();
            break;
        default:
            printf("Opcion Invalida");
        }

    } while (opcion != 4);
    
}


void ingresarPuntoGeo(){
    GeoPoint lugar;
    printf("Ingrese Nombre: ");
    scanf("%s", lugar.nombre);

    printf("Ingrese Latitud: ");
    scanf("%f", &lugar.latitud);

    printf("Ingrese Longitud: ");
    scanf("%f", &lugar.longitud);

    GeoPoints[cantidadGeoPoints] = lugar;
    cantidadGeoPoints++;
}

void calcularDistancia(){
    char nombreA[30], nombreB[30];
    int index = 0;
    GeoPoint puntoA;
    GeoPoint puntoB;
    
    do
    {
        
        printf("Ingrese el nombre del punto A: ");
        scanf("%s", nombreA);
        
        index = buscarGeoPoint(nombreA);
    } while (index == -1);
    puntoA = GeoPoints[index];

    do
    {
        
        printf("Ingrese el nombre del punto B: ");
        scanf("%s", nombreB);
        
        index = buscarGeoPoint(nombreB);
    } while (index == -1);
    puntoB = GeoPoints[index];

    double distancia = 0.0;

    distancia = haversine(puntoA.latitud, puntoA.longitud, puntoB.latitud, puntoB.longitud);

    printf("La distacia entre el %s y %s es de %f km", puntoA.nombre, puntoB.nombre, distancia);




}



double haversine(double lat1_deg, double lon1_deg, double lat2_deg, double lon2_deg) {
    double lat1 = lat1_deg * PI / 180.0;
    double lon1 = lon1_deg * PI / 180.0;
    double lat2 = lat2_deg * PI / 180.0;
    double lon2 = lon2_deg * PI / 180.0;

    
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distancia = 6371 * c; // Radio de la Tierra en km
    return distancia;
}


int buscarGeoPoint(char nombre[30]){
    for (int i = 0; i < cantidadGeoPoints; i++)
    {
        if (strcmp(GeoPoints[i].nombre, nombre) == 0)
        {
            return i;
        }
    }
    return -1;    
}

void getGeoPoints(){
    if (cantidadGeoPoints == 0)
    {
        printf("No hay registros de geo points\n");
        return;
    }
    
    for (int i = 0; i < cantidadGeoPoints; i++)
    {
        printf("###################################\n");
        printf("Nombre %s\n", GeoPoints[i].nombre);
        printf("Latitud %f\n", GeoPoints[i].latitud);
        printf("Longitud %f\n", GeoPoints[i].longitud);
        printf("###################################\n");
    }
    
}