/*
 * funciones.c
 *
 *  Created on: 15 abr. 2020
 *      Author: Asato Fumihito
 */
#include <stdio.h>
#include <stdlib.h>

/*brief : suma: calcula la suma entre 2 valores flotantes.
**param A: representa un valor ingresado por el usuario en los calculos representa el primer numero.
**param B: representa un valor ingresado por el usuario en los calculos representa el segundo numero.
**return devuelve el resultado de param A + param B a la funcion main.
*/

float suma(float A, float B)
{
    float suma;

    suma = A+B;
     printf("\nEl resultado de A+B es %.2f\n",suma);

    return 0;
}
/*brief : resta: calcula la resta entre 2 valores flotantes.
**param A: representa un valor ingresado por el usuario en los calculos representa el primer numero.
**param B: representa un valor ingresado por el usuario en los calculos representa el segundo numero.
**return devuelve el resultado de param A - param B a la funcion main.
*/
float resta(float A, float B)
{
    float resta;

    resta = A-B;
    printf("\n\nEl resultado de A-B es %.2f\n",resta);

    return 0;
}
/*brief : multiplicacion: calcula la suma entre 2 valores flotantes.
**param A: representa un valor ingresado por el usuario en los calculos representa el primer numero.
**param B: representa un valor ingresado por el usuario en los calculos representa el segundo numero.
**return devuelve el resultado de param A * param B a la funcion main.
*/
float multiplicacion(float A, float B)
{
    float multi;

    multi = A*B;
    printf("\n\nEl resultado de A*B es %.2f\n",multi);

    return 0;
}
/*brief : division: calcula la suma entre 2 valores flotantes.
**param A: representa un valor ingresado por el usuario en los calculos representa el primer numero.
**param B: representa un valor ingresado por el usuario en los calculos representa el segundo numero.
**if compara si el valor del segundo numero es 0 , en caso de serlo informa que no se puede dividir.
**return devuelve el resultado de param A / param B a la funcion main.
*/
float division(float A, float B)
{
    float divi;
    divi = A/B;
    if(B==0){
    printf("\n\nno se puede dividir por 0\n");
}
    else{
    printf("\n\nEl resultado de A/B es %.2f\n",divi);
    }
    return 0;
}
/*brief : factorial: calcula el factorial de 2 valores flotantes.
**param A: representa un valor ingresado por el usuario en los calculos representa el primer numero.
**param B: representa un valor ingresado por el usuario en los calculos representa el segundo numero.
**los if evaluan si los valores ingresados son negativos, en caso de serlos informa que no es posible realizar el calculo.
**return devuelve el resultado de param A y param B a la funcion main.
*/
float factorial(float A, float B)
{
    float i,factorialA=1, factorialB=1;
      if(A>=0){
                for(i=1;i<=A;i++){
                    factorialA = factorialA*i;
                }
                printf("\nel factorial de A es :%.1f\n",factorialA);
            }
            else{
                printf("\nno se puede calcular el factorial de un numero negativo\n");
            }

            if(B>=0){
                for(i=1;i<=B;i++){
                    factorialB = factorialB*i;
                }
                printf("\nel factorial de B es :%.1f\n",factorialB);
            }
            else{
                printf("\nno se puede calcular el factorial de un numero negativo\n");
            }

    return 0;
}
