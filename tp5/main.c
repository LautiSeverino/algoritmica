#include <stdio.h>
#include <unistd.h>   // getpid()
#include <stdlib.h>
#include <time.h>
#include <string.h>


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

void leerCodigoFuente();
void leerArchivoCmd(int argc, char *argv[]);
void pidfile();
void leerArchivoDat();
int calcularEdad(struct Fecha fn);
void importarDatos();


int main(int argc, char *argv[]) {

    //leerCodigoFuente();
    //leerArchivoCmd(argc, argv); // ./main ejemplo.txt
    //pidfile();
    //leerArchivoDat();
    importarDatos();
    return 0;
}

//ejercicio 1
void leerCodigoFuente(){
    FILE *f = fopen(__FILE__, "r");
    if (!f)
    {
        perror("fopen");
    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
    fclose(f);
}

//ejercicio 2
void leerArchivoCmd(int argc, char *argv[]){
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s archivo_a_leer\n", argv[0]);
        return;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        perror("fopen");
        return;
    }
    char buf[256];
    while (fgets(buf, sizeof buf, f))
    {
        fputs(buf, stdout);
    }
    fclose(f);
}

//ejercicio 3
void pidfile(){
    const char *fname = "pidfile";
    FILE *f = fopen(fname, "r");
    if (f) //existe
    {
        printf("El programa ya se encuentra en ejecucion\n");
        fclose(f);
        return;
    }
    
    //crear
    f = fopen(fname, "w");
    if (!f)
    {
        perror("fopen");
        return;
    }
    fprintf(f, "%d\n", getpid());  // guardo mi propio PID
    fclose(f);

    printf("Programa iniciado (pid escrito en %s). Presione cualquier tecla para terminar. \n", fname);
    getchar();
    
    if (remove(fname) != 0)
    {
        perror("remove");
    }
    
}

//ejercicio 4
void leerArchivoDat(){
    const char *fname = "registro.dat";
    FILE *f = fopen(fname, "r");

    if (!f) // no existe
    {
        printf("Esta es la primera vez que se ejecuta el programa");
        f = fopen(fname, "w");
        if (!f)
        {
            perror("fopen");
            return;
        }
        // Obtener fecha y hora actual
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char fecha[64];
        strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", tm_info);

        fprintf(f, "%s\n", fecha); // guardar fecha legible
        fclose(f);
        return;
    }

     // Archivo existe
    char buf[64];
    if (fgets(buf, sizeof(buf), f)) {
        printf("El programa se ejecutó por última vez: %s", buf);
    }
    fclose(f);

    // Guardar la nueva fecha y hora actual
    f = fopen(fname, "w");
    if (!f) {
        perror("fopen");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char fecha[64];
    strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", tm_info);

    fprintf(f, "%s\n", fecha);
    fclose(f);

}

//ejercicio 5
// Función que importa datos desde un archivo "datosAImportar.dat"
// y los guarda en "datosImportados.dat" como registros de tipo Persona
void importarDatos() {
    // abrir el file de entrada en modo lectura
    FILE *f = fopen("datosAImportar.dat", "r");
    if (!f) {
        perror("No se pudo abrir datosAImportar.dat");
        return;
    }

    // abrir eñ file file de salida en modo escritura
    FILE *fout = fopen("datosImportados.dat", "w");
    if (!fout) {
        perror("No se pudo crear datosImportados.dat");
        fclose(f);
        return;
    }

    // buffer para leer lineas del file
    char linea[256];

    //leer el file
    while (fgets(linea, sizeof(linea), f)) {
        struct Persona p; // struct donde se alamcena los datos de cada linea
        int d, m, a; // vars para dia, mes y año

        // separar campos por ';'
        char *token = strtok(linea, ";"); // primer token = nombre
        if (token) strncpy(p.nombre, token, sizeof(p.nombre));

        token = strtok(NULL, ";"); // segundo token = apellido
        if (token) strncpy(p.apellido, token, sizeof(p.apellido));

        token = strtok(NULL, ";"); // tercero fecha nac
        if (token) {
            sscanf(token, "%d/%d/%d", &d, &m, &a);
            p.fechaNacimiento.dia = d;
            p.fechaNacimiento.mes = m;
            p.fechaNacimiento.anio = a;
        }

        token = strtok(NULL, ";\n"); // edad
        p.edad = calcularEdad(p.fechaNacimiento); // recalcular edad segun fecha (por si viene mal la edad en el file)

        // guardar en archivo de salida
        fprintf(fout, "%s;%s;%02d/%02d/%04d;%d\n",
                p.nombre, p.apellido,
                p.fechaNacimiento.dia,
                p.fechaNacimiento.mes,
                p.fechaNacimiento.anio,
                p.edad);
    }

    //cerrar los dos files
    fclose(f);
    fclose(fout);

    printf("Importación completada. Datos guardados en datosImportados.dat\n");
}



// Función para calcular edad
int calcularEdad(struct Fecha fn) {
    time_t t = time(NULL);
    struct tm *hoy = localtime(&t);

    int edad = hoy->tm_year + 1900 - fn.anio;

    // ver si cumplio o no años
    if (fn.mes > hoy->tm_mon + 1 || (fn.mes == hoy->tm_mon + 1 && fn.dia > hoy->tm_mday)) {
        edad--;
    }

    return edad;
}

