/*
 ============================================================================
 Name        : Ghost
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : ABM Fantasma
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "abm.h"
#include "utn.h"

static int isArrayAbmIsEmpty (Struct* list, int len);

/** \brief New Abm.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int abm_add(Struct* list, int len)
{
	int retorno = -1;
	int id;
	int index;
	Struct bufferArrray;

	if (abm_serchIndexEmpty(list, LONG_EMPLOYEE) >= 0 &&
		utn_getName(bufferArrray.name, LONG_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getName(bufferArrray.lastName, LONG_LASTNAME, "\n-------- INGRESE APELLIDO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getFloat(&bufferArrray.salary, 50, 2, "\n--------- INGRESE SALARIO ---------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0 &&
		utn_getInt(&bufferArrray.sector, 50, 2, "\n--------- INGRESE SECTOR ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", LONG_MAX, 1)==0)
	{
		id = abm_newId();
		strupr(bufferArrray.name);
		strupr(bufferArrray.lastName);
		index = abm_serchIndexEmpty(list, LONG_EMPLOYEE);
		list[index].id = id;
		strncpy(list[index].name, bufferArrray.name, LONG_NAME);
		strncpy(list[index].lastName, bufferArrray.lastName, LONG_LASTNAME);
		list[index].salary = bufferArrray.salary;
		list[index].sector = bufferArrray.sector;
		list[index].isEmpty = FALSE;

		printf("\n----------- ID EMPLEADO -----------\n> %d\n", id);
		retorno = 0;

			printf("-----------------------------------\n");
			printf("XXXXXX| NO HAY ESPACIO PARA |XXXXXX\n");
			printf("XXXXXX|  NUEVOS EMPLEADOS   |XXXXXX\n");
			printf("-----------------------------------\n\n");
			retorno = -2;
	}
	return retorno;
}

/** \brief New ID.
 * Generates a new identity number.
 * \param (void)
 * \return int Return (ID), NewID.
 *
 */
int abm_newId(void)
{
	static int id = 999;
	id = id+1;
	return id;
}

/** \brief To initialize all empty array positions.
 * this function put the flag (isEmpty) in TRUE in all and ID to 0.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int abm_initStruct(Struct* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].id = 0;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param Employee* list, Pointer to array of employees.
 * \param int len, Array length.
 * \param int id, Identity number employee.
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int abm_findById(Struct* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].id == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}


/** \brief Sort the elements in the array of employees,  *
 * This function receives the order of the arguments indicates the order UP or DOWN
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int abm_sort(Struct* list, int len, int order)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	Struct bufferArrray;

	if(list != NULL && len > 0)
	{
		while(flagSort==0)
		{
		flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if((strcmp(list[index].lastName, list[index+1].lastName) < 0 && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) > 0) && order == 1) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && list[index].sector < list[index+1].sector) && order == 0) || ((strcmp(list[index].lastName, list[index+1].lastName) == 0 && list[index].sector > list[index+1].sector) && order == 1))
				{
					bufferArrray = list[index];
					list[index] = list[index+1];
					list[index+1] = bufferArrray;
					flagSort=0;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int abm_print(Struct* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\n---------------------------------------------------------------------------------------------");
		printf("\n|| --[ID]-- || ------[NOMBRE]------ || -----[APELLIDO]----- || --[SALARIO]-- || -[SECTOR]- ||");
		printf("\n---------------------------------------------------------------------------------------------");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n|| > %d   || %-20s || %-20s || %13.2f ||   %7d  ||", list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
		printf("\n---------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}

/** \brief Empty employee list
 * This function searches the structure for active employees.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int isArrayAbmIsEmpty (Struct* list, int len)
{
	int i;
	int retorno = 1;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Search for an empty index.
 * This function looks for a space in the structure which is empty to be able to data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int abm_serchIndexEmpty(Struct* list, int len)
{
	int retornar = -1;
	if(list != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].id == 0)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}
