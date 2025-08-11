#include <stdio.h>
#include <time.h>


// prototipo de funcion
void saludarMundo(void);
void saludar(void);
void calcularEdadAproximada(void);
void esMayorDeEdad(void);
void imprimirNumerosFor(void);
void imprimirNumerosWhile(void);
void imprimirNumerosDoWhile(void);
void calcularEdadExacta(void);
void estacionSegunFechaNacimiento(void);
void calcularFactorial(void);
void numerosPrimos(void);
void multiplicarUsandoSuma(void);
void potenciaUsandoSuma(void);
void abecedarioHastaLetra(void);
void abecedarioInversoHastaLetra(void);
void imprimirNumerosFibonacci(void);
void verificarCapicua(void);
void contarDigitos(void);
void calculadora(void);

int main() {
    saludarMundo();    
    // saludar();
    //calcularEdadAproximada();
    //esMayorDeEdad();
    //imprimirNumerosFor();
    //imprimirNumerosWhile();
    //imprimirNumerosDoWhile();
    //calcularEdadExacta();
    //estacionSegunFechaNacimiento();
    //calcularFactorial();
    //numerosPrimos();
    //multiplicarUsandoSuma();
    //potenciaUsandoSuma();
    //abecedarioHastaLetra();
    //abecedarioInversoHastaLetra();
    //imprimirNumerosFibonacci();
    //verificarCapicua();
    //contarDigitos();
    //calculadora();
    return 0;
}


// ejercicio 1
void saludarMundo(void) {
    printf("Hola Mundo");
    
}

// ejercicio 2
void saludar(void) {
    char nombre[20];
    printf("Cual es tu nombre?\n");
    scanf("%s", nombre);
    printf("Hola %s", nombre);
}

// ejercicio 3
void calcularEdadAproximada(void){
    int anioNacimiento;
    printf("Ingrese su año de nacimiento \n");
    scanf("%d", &anioNacimiento);
    printf("Su edad es: %d",  2025 - anioNacimiento);
}

// ejercicio 4
void esMayorDeEdad(void){
    int edad;
    printf("Ingrese su edad: \n");
    scanf("%d", &edad);
    if (edad >= 18) {
        printf("Eres mayor de edad");
    } else
    {
        printf("No eres mayor de edad");
    }
}

// ejercicio 5
void imprimirNumerosWhile(void){
    int numero;
    int i = 1;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    while ( i <= numero)
    {
        printf("%d ", i);
        i++;
    }
}

// ejercicio 6
void imprimirNumerosDoWhile(void){
    int numero;
    int i = 1;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= numero);
    
}

// ejercicio 7
void imprimirNumerosFor(void){
    int numero;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    for (int i = 1; i <= numero; i++) {
        printf("%d ", i);
    }
}

// ejercicio 8
void calcularEdadExacta(void){
    int anioNac, mesNac, diaNac;
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
    
    printf("Ingrese su año de nacimiento:\n");
    scanf("%d", &anioNac);
    
    printf("Ingrese su mes de nacimiento: (1 - 12)\n");
    scanf("%d", &mesNac);
    
    printf("Ingrese su dia de nacimiento: (1 - 31)\n");
    scanf("%d", &diaNac);
    
    edad = anioActual - anioNac;
    
    if (mesActual < mesNac || (mesNac == mesActual && diaActual > diaNac)){
        edad--;
    }
    printf("Su edad es: %d", edad);
}

// ejercicio 9
void estacionSegunFechaNacimiento(void){
    int anioNac, mesNac, diaNac;
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
    
    printf("Ingrese su año de nacimiento:\n");
    scanf("%d", &anioNac);
    
    printf("Ingrese su mes de nacimiento: (1 - 12)\n");
    scanf("%d", &mesNac);
    
    printf("Ingrese su dia de nacimiento: (1 - 31)\n");
    scanf("%d", &diaNac);
    
    if ((mesNac == 12 && diaNac >= 21) || (mesNac == 1) || ( mesNac == 2) || (mesNac == 3 && diaNac <=20 )){
        printf("Naciste en verano");
    }
    
    if ((mesNac == 3 && diaNac >= 21) || (mesNac == 4) || ( mesNac == 5) || (mesNac == 6 && diaNac <=20 )){
        printf("Naciste en otoño");
    }
    
    if ((mesNac == 6 && diaNac >= 21) || (mesNac == 7) || ( mesNac == 8) || (mesNac == 9 && diaNac <=22 )){
        printf("Naciste en invierno");
    }
    
    if ((mesNac == 9 && diaNac >= 23) || (mesNac == 10) || ( mesNac == 11) || (mesNac == 12 && diaNac <=20 )){
        printf("Naciste en primavera");
    }
    
}


// ejercicio 10
void calcularFactorial(void){
    int numero, factorial;
    factorial = 1;
    printf("Ingrese un numero:\n");
    scanf("%d", &numero);
    for (int i = 1; i <= numero; i++)
    {
        factorial = factorial * i;
    }
    printf("Factorial de %d es %d", numero, factorial);
}

// ejercicio 11
void numerosPrimos(void){
    int numero, j, i, esPrimo;
    
    printf("Ingrese un numero:\n");
    scanf("%d", &numero);
    for (i = 2; i <= numero; i++) {
        esPrimo = 1;
        for (j = 2; j * j <= i; j++) { //solo se necesita verificar divisores hasta la raíz cuadrada del número
            if (i % j == 0) {
                esPrimo = 0;
                break;
            }
        }
        if (esPrimo && i != 2) {
            printf("%d ", i);
        }
    }
}


// ejercicio 12
void multiplicarUsandoSuma(void){
    int i, numero1, numero2, resultado;

    printf("Ingrese el primer numero:\n");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero:\n");
    scanf("%d", &numero2);
    
    for (i = 1; i <= numero2; i++)
    {
        resultado += numero1;
    }

    printf("Resultado = %d", resultado);
}



// ejercicio 13
void potenciaUsandoSuma(void){
    int base, potencia, resultado, acumulador;
    
    resultado = 1;
    
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese la potencia: ");
    scanf("%d", &potencia);


    for (int i = 1; i <= potencia; i++){
        acumulador = 0;
        for (int j = 0; j < base; j++)
        {
            acumulador += resultado; 
        }
        resultado = acumulador;
    }
    printf("Resultado: %d", resultado);

}

// ejercicio 15
void abecedarioHastaLetra(void){
    char letra;
    printf("Ingrese la letra: ");
    scanf("%s", &letra);

    if (letra >= 'A' && letra <= 'Z' )
    {
        for (char c = 'A'; c <= letra; c++)
        {
            printf("%c", c);
        }
        
    } else 
    {
        for (char c = 'a'; c <= letra; c++)
        {
            printf("%c", c);
        }
    }
}


// ejercicio 16
void abecedarioInversoHastaLetra(void){
    char letra;
    printf("Ingrese la letra: ");
    scanf("%s", &letra);

    if (letra >= 'A' && letra <= 'Z' )
    {
        for (char c = 'Z'; c >= letra; c--)
        {
            printf("%c", c);
        }
        
    } else 
    {
        for (char c = 'z'; c >= letra; c--)
        {
            printf("%c", c);
        }
    }
}

// ejeecicio 17
void imprimirNumerosFibonacci(void){
    int limite, num1, num2, result;
    num1 = 0;
    num2 = 1;
    printf("Ingrese el limite de la serie Fibonacci: \n");
    scanf("%d", &limite);

    for (int i = 1; i <= limite ; i++)
    {   
        //primer iteracion
        if (i == 1) {
            result = num1;
        } // segunda iteracion
        else if (i == 2) {
            result = num2;
        } // resto de iteraciones
        else if (i == 2) {
            result = num2;
        } else {
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        printf("%d - ", result);
    }
}

//ejercicio 18
void verificarCapicua(void){
    int numero, ultimoDigito, numeroInvertido, numeroOriginal;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    numeroOriginal = numero;
    
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
    
    if (numeroOriginal == numeroInvertido) {
        printf("El numero %d es capicua", numeroOriginal);
    } else
    {
        printf("El numero %d no es capicua", numeroOriginal);
    }
}

// ejercicio 19
void contarDigitos(void){
    int numero, digitos;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);

    if (numero == 0)
    {
        printf("cantidad de digitos: 1");
    } else
    {
        //algoritmo conteo de digitos
        while (numero != 0)
        {
            //eliminar ultimo digito
            numero /= 10;
            digitos++;
        }
        printf("cantidad de digitos %d", digitos);
    }
}

//ejercicio 20
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
        resultado = num1 + num2;
        break;
    case '-':
        resultado = num1 - num2;
        break;
    case '*':
        resultado = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("No se puede divir entre cero");
            break;
        }
        resultado = num1 / num2;
        break;
    default:
        printf("Operando no configurado");
    }
    if (num2 != 0 || operador != '/'){
        printf("%d %c %d = %d", num1, operador, num2, resultado);
    }
}