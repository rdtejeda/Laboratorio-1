#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/**
* \brief reserva de forma dinamica memoria para un dato tipo eSalon
* \param es void
* \return Retorna *eSalon a direcion de memoria reservada
*/

Employee* employee_new()
{
	Employee* pEmployee=(Employee*)malloc(sizeof(Employee));
	if(pEmployee==NULL)
		puts("No se ha podido reservar espacio en memoria");

return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee=employee_new();

	if(pEmployee!=NULL && idStr!=NULL&& nombreStr!=NULL && horasTrabajadasStr!=NULL)
	{
		employee_setNombre(pEmployee, nombreStr);
		employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
		employee_setId(pEmployee,atoi(idStr));
		employee_setSueldo(pEmployee,atoi(sueldoStr));

	}
return pEmployee;
}
void employee_delete(Employee* pEmployee)
{
	free(pEmployee);
}
int employee_findByID(LinkedList* listEmployees, int id)
{
	int retorno=-1;
	int posicion;
	int largoLista;
	Employee* pAuxiliarEmployee;
	if(listEmployees!=NULL && id>0)
		{
		largoLista=ll_len(listEmployees);
		for (int i = 0; i < largoLista; i++)
			{
				pAuxiliarEmployee=ll_get(listEmployees, i);
				if(pAuxiliarEmployee->id==id)
				{
					posicion=i;
					break;
				}
			}
		}
	 retorno=posicion;
return retorno;
}

int employee_setId(Employee* this,int id)
{
	 int retorno=-1;

	 return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;

		 return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;

		 return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;

		 return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;

		 return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;

		 return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;

		 return retorno;
}





