/*
 ============================================================================
 Name        : tp1 - Calculadora - Laboratorio 1 1E
 Author      : Asato Fumihito
 Version     : v1.0
 Description :  una calculadora con sus funciones en una biblioteca separada
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main(void) {

   float A,B;
   int choice;
   int flagA=1; //  requeri utilizar estas variables de control, se que se puede hacer de otra forma pero no se me ocurrio una mejor
   int flagB=1; //
   setbuf(stdout, NULL);
   do
{
    printf("\n Menu\n\n");
    printf("1. ingrese primer operando\n");
    printf("2. ingrese segundo operando\n");
    printf("3. calcular todas las operaciones\n");
    printf(" suma, resta, multiplicacion, division, factorial\n");
    printf("4. salir\n");
    scanf("%d",&choice);


 switch (choice)
 {
       case 1: printf("ingrese el primer operando \n");
                scanf("%f",&A);
                flagA=0;
            break;

       case 2: printf("ingrese el segundo operando \n");
                scanf("%f",&B);
                flagB=0;
            break;

       case 3: if(flagA==0 && flagB==0){      // aca tube que utilizar unas variables control para evitar errores de calculo en caso de no ingresar nada.
           printf("calculando A+B,A-B,A*B,A/B,!A,!B");
           suma(A,B);
           resta(A,B);
           multiplicacion(A,B);
           division(A,B);
           factorial(A,B);
       }
       else{
            printf("no se ingreso 1 de los 2 operandos o ninguno "); // esta seria la respuesta obtenida en caso de no haber ingresado operandos
       }
            break;

       case 4: printf("saliendo del programa\n");
            break;

       default: printf("Opcion invalida\n");
            break;
}
} while (choice !=4);
	return EXIT_SUCCESS;
}
