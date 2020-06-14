#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int retorno = 1;
	char id[50];
	char nombre[50];
	char horas[50];
	char sueldo[50];
	int control;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

	while(!feof(pFile))
	{
		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		control = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
		if(control==4)
		{
			empleado = employee_newParametros(id,nombre,horas,sueldo);

			if(empleado!=NULL)
			{
				ll_add(pArrayListEmployee,empleado);
			 	retorno = 0;
			}
			else
			{
				printf("no se pudo generar el empleado \n");
				break;
			}
		}
		else{
			printf("no se pudo leer correctamente el archivo\n");
			break;
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int id;
	char nombre[50];
	int horas;
	int sueldo;
	int control;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			empleado = employee_new();
			control = fread(empleado,sizeof(empleado),1,pFile);

			if(control == 1)
			{
				if(employee_getId(empleado,&id)==0 && employee_getNombre(empleado,nombre)==0 && employee_getHorasTrabajadas(empleado,&horas)==0 && employee_getSueldo(empleado,&sueldo)==0)
				{
					ll_add(pArrayListEmployee,empleado);
				}

			}
		}
	}
    return 1;
}
