#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validacion.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno=-1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_EmployeeFromText(pArchivo,pArrayListEmployee)==0)
			{
				fclose(pArchivo);
				retorno=0;
			}
			else
			{
				printf("\nNo se pudo cargar la lista");
			}

		}
		else
		{
			printf("\nNo se pudo abrir el archivo...");
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivoBinario;
	int retorno=-1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivoBinario=fopen(path,"rb");
		if(pArchivoBinario != NULL)
		{
			if(parser_EmployeeFromText(pArchivoBinario,pArrayListEmployee)==0)
			{
				fclose(pArchivoBinario);
				retorno=0;
			}
			else
			{
				printf("\nNo se pudo cargar la lista");
			}

		}
		else
		{
			printf("\nNo se pudo abrir el archivo...");
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* empleado;
	int i;
	//int flag=0;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int bufferId ;
	int largo;
	if(pArrayListEmployee!=NULL)
	    	{
			getName(bufferNombre,"ingrese nombre","error al ingresar el nombre");
		    getInt(&bufferHoras,"Horas trabajadas: ","\nError",1,1000000);
			getInt(&bufferSueldo,"Sueldo: ","\nError",1,1000000);
			largo = ll_len(pArrayListEmployee);
			        bufferId = 0;

			        for(i=0;i<largo;i++)
			        {
			            empleado = ll_get(pArrayListEmployee,i);
			            if(empleado->id > bufferId)
			            {
			                bufferId = empleado->id;
			            }
			        }
			            bufferId++;
			            printf("%d\n",bufferId);
				empleado=employee_new();
				if(empleado != NULL && employee_setId(empleado,bufferId)==1 &&
						employee_setNombre(empleado,bufferNombre)==1 &&
						employee_setSueldo(empleado,bufferSueldo)==1 &&
						employee_setHorasTrabajadas(empleado,bufferHoras)==1)
				{
							if(ll_add(pArrayListEmployee,empleado)==0)
							{
								printf("\nEmpleado cargado\n");
								retorno = 0;
							}
							else
							{
								employee_delete(empleado);
								printf("\nError al agregar empleado\n");
							}
				}

	    	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* empleado;
	int bufferId;
	int auxBufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int i;
	int len;
	int option = 0;


	if(pArrayListEmployee != NULL)
	{
		getInt(&auxBufferId,"\nId de empleado a modificar: ","\nError",1,1000000);
		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
	empleado = (Employee*)ll_get(pArrayListEmployee,i);
	employee_getId(empleado,&bufferId);

	if(bufferId != auxBufferId)
		continue;
			else
{
	employee_getSueldo(empleado,&bufferSueldo);
	employee_getHorasTrabajadas(empleado,&bufferHoras);
	employee_getNombre(empleado,bufferNombre);
	printf("\nId\t\tNombre\tHoras\tSueldo\n");
	printf("%d\t\t%s\t%d\t%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

	getInt(&option,"\nModificar:\n1-Nombre\n2-Sueldo\n3-Cantidad de horas\nElija una opcion: ","\nError",1,3);

		switch(option)
		{
		case 1:
			getName(bufferNombre,"\ningrese el nuevo nombre:","\nerror");
			employee_setNombre(empleado,bufferNombre);
			break;
		case 2:
			getInt(&bufferSueldo,"\ningrese el nuevo sueldo: ","\nerror",1,9999);
			employee_setSueldo(empleado,bufferSueldo);
			break;
		case 3:
			getInt(&bufferHoras,"\ningrese la cantidad de horas: ","\nerror",1,9999);
			employee_setHorasTrabajadas(empleado,bufferHoras);
			break;
			}
		}
	}
		retorno=0;
			}
	return retorno;

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	 int retorno=-1;
	    int len;
	    int i;
	    int bufferId;
	    int bufferSueldo;
	    char bufferNombre[50];
	    int bufferHoras;
	    Employee* empleado;
	    if(pArrayListEmployee != NULL)
	    {
	        len=ll_len(pArrayListEmployee);
	        printf("\n**Id\t    Nombre\t  Horas trabajadas\tSueldo**\n\n");
	        for(i=0;i<len;i++)
	        {
	        	empleado=(Employee*)ll_get(pArrayListEmployee,i);
	            if(empleado!=NULL)
	            {
	            	employee_getId(empleado,&bufferId);
	            	employee_getSueldo(empleado,&bufferSueldo);
	            	employee_getHorasTrabajadas(empleado,&bufferHoras);
	            	employee_getNombre(empleado,bufferNombre);
	            	printf("%4d%14s\t\t%d\t\t%6d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
	            }
	        }
	        retorno=0;
	    }
	    return retorno;
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* empleado = NULL;
	int retorno = -1;
	int bufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int i;
	int len;

	FILE* pArchivo;
	pArchivo= fopen(path,"w");

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(pArchivo != NULL)
		{
			for(i=0;i<len;i++)
			{
				empleado = ll_get(pArrayListEmployee,i);
				employee_getId(empleado,&bufferId);
				employee_getSueldo(empleado,&bufferSueldo);
				employee_getHorasTrabajadas(empleado,&bufferHoras);
				employee_getNombre(empleado,bufferNombre);
				fprintf(pArchivo,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
			}
			printf("\nArchivo guardado correctamente.\n");
			retorno = 0;
		}
		else
		{
			printf("\nError al guardar el archivo\n");
		}

	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee* empleado = NULL;
	int retorno = -1;
	int bufferId;
	char bufferNombre[50];
	int bufferHoras;
	int bufferSueldo;
	int i;
	int len;

	FILE* pArchivo;
	pArchivo= fopen(path,"wb");

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(pArchivo != NULL)
		{
			for(i=0;i<len;i++)
			{
				empleado = ll_get(pArrayListEmployee,i);
				employee_getId(empleado,&bufferId);
				employee_getSueldo(empleado,&bufferSueldo);
				employee_getHorasTrabajadas(empleado,&bufferHoras);
				employee_getNombre(empleado,bufferNombre);
				fprintf(pArchivo,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
			}
			printf("\nArchivo guardado correctamente.\n");
			retorno = 0;
		}
		else
		{
			printf("\nError al guardar el archivo\n");
		}

	}
	fclose(pArchivo);
    return retorno;
}

