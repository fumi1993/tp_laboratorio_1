/*
 ============================================================================
 Name        : main.c
 Author      : asato fumihito
 Version     : 1.0
 Description : programa de carga y administracion de empleados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "headers.h"
#define Qty 1000

int main(void) {
    eEmployee listEmployee[Qty];
	int i;
	int id=1;
	int choice;
	setbuf(stdout,NULL);

	for(i=0; i<Qty; i++)
		    {
			  listEmployee[i].isEmpty=EMPTY;
		    }

	do{
		if(getInt(&choice,"\nElija una opcion: \n\t 1- Alta Empleado\n\t 2- Modificar Empleado\n\t 3- Baja Empleado\n\t 4- Listado de Empleado\n\t 5- Salir\n","opción invalida",1,5)==0)
		{
		}

	switch(choice){

					case 1:

						loadEmployeeList(listEmployee,Qty,&id);
						id++;
						break;

					case 2:

						modifyEmployee( listEmployee,Qty);

						break;

					case 3:

						sortEmployee(listEmployee,Qty);
						deleteEmployee(listEmployee,Qty);

						break;
					case 4:

						sortEmployee(listEmployee, Qty);
						showEmployeeList(listEmployee, Qty);
						break;
					case 5:

						printf("\nsaliendo del programa");
						break;
	}

	}while(choice!=5);

	return 0;
}
