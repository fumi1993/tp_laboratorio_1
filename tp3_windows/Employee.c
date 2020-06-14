#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"


Employee* employee_new()
{
	Employee* empleado = (Employee*)malloc( sizeof(Employee));

		if(empleado != NULL)
		{
			empleado->id = 0;
			strcpy(empleado->nombre, "");
			empleado->horasTrabajadas = 0;
			empleado->sueldo = 0;
		}
	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* empleado = employee_new();

	if(empleado != NULL  && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
	{
		employee_setId(empleado,atoi(idStr));
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setSueldo(empleado,atoi(sueldo));
	}
	return empleado;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	if(this!=NULL && id>=0)
	{
		this->id = id;

	}
	return 1;
}

int employee_getId(Employee* this,int* id)
{
		if(this!=NULL && id!= NULL)
		{
			*id = this->id;
		}
		return 1;
}
int employee_getNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre !=NULL)
	{
		strcpy(nombre,this->nombre);
	}
	return 1;
}
int employee_setNombre(Employee* this,char* nombre)
{
	if(this!=NULL && nombre!= NULL)
	{
		strcpy(this->nombre,nombre);
	}
	return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
	}
	return 1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
		if(this!=NULL && horasTrabajadas!= NULL)
		{
			*horasTrabajadas = this->horasTrabajadas;
		}
		return 1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
	}
	return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	if(this!=NULL && sueldo!= NULL)
	{
		*sueldo = this->sueldo;
	}
	return 1;
}
