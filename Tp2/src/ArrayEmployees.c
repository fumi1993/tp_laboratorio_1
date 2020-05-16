/*
 * funciones.c
 *
 *  Created on: 29 abr. 2020
 *      Author: asato fumihito
 */
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "headers.h"
#include <string.h>
/*brief: inicializa el array en busca de lugar libre para cargar empleados
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 */
int findEmpty(eEmployee listEmployee[], int Qty)
{

	int index = -1;
	int i;
	for(i=0;i<Qty;i++)
{
	if(listEmployee[i].isEmpty!=FILLED)
{
	index = i;
	break;
}
}
	return index;
}
/*brief: carga a la lista de empleados de manera individual y les asigna un id autoincremental empezando desde el 1 los id no se vuelven a repetir aun
 * si el empleado se dio de baja, primero busca un lugar libre dentro de la estructura luego hace la carga individual.
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id declarado en 1 en la funcion main
 */
void loadEmployeeList(eEmployee listEmployee[],int Qty,int *id){
	    int index;
	    index = findEmpty(listEmployee, Qty);
	    printf("Indice: %d\n", index);
	    if(index!=-1)

	    {
	    	listEmployee[index] = loadEmployee();
	    	listEmployee[index].id = *id;
	    }
	    else
	    {
	        printf("\nNo hay espacio disponible ");
	    }
/*brief: muestra el listado de empleados
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 */
}
void showEmployeeList(eEmployee listEmployee[], int Qty)
{
    int i;

    for(i=0; i<Qty; i++)
    {
        if(listEmployee[i].isEmpty==FILLED)
        {
            showEmployee(listEmployee[i]);
        }

    }
}
/*brief: realiza la carga de empleados de manera individual.
 */
eEmployee loadEmployee(void)
{
    eEmployee Employee;

    if(getName(Employee.name,"ingrese el nombre:","error solo se admiten caracteres aflabeticos\n",2,sizeof(Employee.name))==0)
    	{
    	}
    if(getName(Employee.lastName,"ingrese el apellido:","error solo se admiten caracteres aflabeticos\n",2,sizeof(Employee.lastName))==0)
    	{
    	}
    if(getFloat(&Employee.salary,"ingrese el salario:","opción invalida\n",0,50000)==0)
		{
		}
	if(getInt(&Employee.sector,"ingrese el sector:","opción invalida\n",1,10)==0)
		{
		}

    Employee.isEmpty = 1;

    return Employee;
}
/*brief: muestra un empleado de manera individual, utilizado para su modificacion o eliminacion.
 */
void showEmployee(eEmployee Employee)
{
    printf("id:%d\t nombre:%s\t apellido:%s\t salario:%.2f\t sector:%d\n",Employee.id,Employee.name, Employee.lastName, Employee.salary, Employee.sector);
}
/*brief: busca un empleado por id y comprueba que halla un empleado cargado
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id que se utiliza para la busqueda.
 */
int searchEmployeeById(eEmployee* listEmployee, int Qty, int id)
{
    int i;
    int retorno = -1;

    if(listEmployee!=NULL && Qty>0)
    {

     for(i=0; i<Qty; i++)
    {
        if(listEmployee[i].id==id && listEmployee[i].isEmpty==FILLED)
        {
            retorno = i;
            break;
        }
    }
    }
    return retorno;
}
/*brief: muestra un menu para modificar datos de un empleado
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 */
void modifyEmployee(eEmployee listEmployee[],int Qty )
{
	int choice;
	int id;
		showEmployeeList(listEmployee, Qty);
		if(getInt(&id,"ingrese el id del empleado a modificar:","opción invalida\n",1,1001)==0)
		{
		}
		if(getInt(&choice,"\ningrese que dato modificar \n\t1- nombre : \n\t2- apellido : \n\t3- salario : \n\t4- sector : \n\t5- volver al menu anterior :","opción invalida\n",1,5)==0)
		{
		}

	switch(choice)
	    {
          case 1:

			modifyName(listEmployee,Qty,id);

		  break;

          case 2:

       	    modifyLastName(listEmployee,Qty,id);

		   break;

          case 3:

               modifySalary(listEmployee,Qty,id);

		  break;

          case 4:

               modifySector(listEmployee,Qty,id);

		  break;

          case 5:
              printf("\nvolviendo al menu anterior ");
              break;
          }
}
/*brief: modifica el nombre de un empleado previamente elegido por id
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id que utiliza para buscar al empleado
 */
int modifyName(eEmployee listEmployee[], int Qty, int id)
{
    int index;
    int ok = -1;
    char answer;
    eEmployee aux;

    index = searchEmployeeById(listEmployee, Qty , id);
    if(index!=-1)
    {
        aux = listEmployee[index];
        showEmployee(aux);

        if(getName(aux.name,"ingrese el nuevo nombre:","error solo se admiten caracteres aflabeticos\n",2,sizeof(aux.name))==0)
        	{
        	}
        if(getChar(&answer,"Esta seguro que desea modificar este empleado? : s/n\n","opcion invalida\n",110,115))
        {
        }
        else if(answer=='s')
        {
        	listEmployee[index] = aux;
            ok = 1;
        }
        else
        {
            ok = 0;
        }

    }
    return ok;
}
/*brief: modifica el apellido de un empleado previamente elegido por id
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id que utiliza para buscar al empleado
 */
int modifyLastName(eEmployee listEmployee[],int Qty ,int id)
{
    int index;
    int ok = -1;
    char answer;
    eEmployee aux;

    index = searchEmployeeById(listEmployee,Qty, id);
    if(index!=-1)
    {
        aux = listEmployee[index];
        showEmployee(aux);

        if(getName(aux.lastName,"ingrese el nuevo apellido:","error solo se admiten caracteres aflabeticos\n",2,sizeof(aux.lastName))==0)
        	{
        	}
        if(getChar(&answer,"Esta seguro que desea modificar este empleado? : s/n\n","opcion invalida\n",110,115))
	    {
	    }
        else if(answer=='s')
        {
        	listEmployee[index] = aux;
            ok = 1;
        }
        else
        {
            ok = 0;
        }

    }
    return ok;
}
/*brief: modifica el salario de un empleado previamente elegido por id
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id que utiliza para buscar al empleado
 */
int modifySalary(eEmployee listEmployee[] ,int Qty ,int id)
{
	    int index;
	    float salary;
	    int ok = -1;
	    char answer;
	    eEmployee aux;

	    index = searchEmployeeById(listEmployee,Qty, id);
	    if(index!=-1)
	    {
	        aux = listEmployee[index];
	        showEmployee(aux);

	        if(getFloat(&salary,"ingrese el nuevo salario:","opción invalida\n",1000,50000)==0)
	    		{
	    		}
	        if(getChar(&answer,"Esta seguro que desea modificar este empleado? : s/n\n","opcion invalida\n",110,115))
		    {
		    }
	        else if(answer=='s')
	        {
	        	listEmployee[index] = aux;
	            ok = 1;
	        }
	        else
	        {
	            ok = 0;
	        }

	    }
	    return ok;
	}

/*brief: modifica el sector de un empleado previamente elegido por id
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 * param3: es el id que utiliza para buscar al empleado
 */
int modifySector(eEmployee listEmployee[] ,int Qty ,int id)
{
	   int index;
	    int sector;
	    int ok = -1;
	    char answer;
	    eEmployee aux;


	    index = searchEmployeeById(listEmployee,Qty, id);
	    if(index!=-1)
	    {
	        aux = listEmployee[index];
	        showEmployee(aux);
	    	if(getInt(&sector,"ingrese el nuevo sector:","opción invalida\n",1,10)==0)
	    		{
	    		}
	    	else if(getChar(&answer,"Esta seguro que desea modificar este empleado? : s/n\n","opcion invalida\n",110,115))
		    {
		    }
	        else if(answer=='s')
	        {
	        	listEmployee[index] = aux;
	            ok = 1;
	        }
	        else
	        {
	            ok = 0;
	        }

	    }
	    return ok;
}
/*brief: elimina un empleado previamente elegido por id
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 */
int deleteEmployee(eEmployee listEmployee[], int Qty)
{
    int id;
    int i;
    char answer;

    int ok = -1;

    showEmployeeList(listEmployee,Qty);

    printf("Ingrese el id: ");
    scanf("%d", &id);

    for(i=0; i<Qty; i++)
    {
        if(listEmployee[i].id==id && listEmployee[i].isEmpty==FILLED)
        {
            showEmployee(listEmployee[i]);
            if(getChar(&answer,"Esta seguro que desea eliminar este empleado? : s/n\n","opcion invalida\n",110,115))
		    {
		    }
            else if(answer=='s')

            {
            	listEmployee[i].isEmpty = EMPTY;
                ok = 1;
            }
            else
            {
                ok = 0;
            }
        }

    }

    return ok ;
}
/*brief: ordena los empleados para que se muestren segun el orden alfabetico de su apellido, en caso de que los apellidos se repitan los ordena segun su sector.
 * param: es el array a recorrer
 * param2: es la cantidad de elementos del array definidos en 1000.
 */
void sortEmployee(eEmployee listEmployee[], int Qty)
	{
    int flag;
    int i;
    eEmployee auxEmployee;

        do
        {
            flag=0;
            for(i=0 ; i< Qty ; i++)
            {
                if(strcmp(listEmployee[i].lastName,listEmployee[i+1].lastName)>0)
                {
                    flag=1;
                    auxEmployee = listEmployee[i];
                    listEmployee[i] = listEmployee[i+1];
                    listEmployee[i+1] = auxEmployee;
                }
            }

                for(i=0 ; i< Qty ; i++)
              { if(strcmp(listEmployee[i].lastName,listEmployee[i+1].lastName)==0)
                {
                    if(listEmployee[i].sector > listEmployee[i+1].sector)
                    {
                        flag=1;
                        auxEmployee = listEmployee[i];
                        listEmployee[i] = listEmployee[i+1];
                        listEmployee[i+1] = auxEmployee;
                    }
                }
               }
            }while(flag);
}

