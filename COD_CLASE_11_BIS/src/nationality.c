/*
 ============================================================================
 Name        : TP2.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Trabajo préctico 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "nationality.h"
#include "utn.h"

static int newIdNationality(void);
static int initNationality(Nationality* list, int len);
static int newNationality(Nationality* list, int len);
static int addNationality(Nationality* list, int len, int id, char name[]);
static int findNationalityById(Nationality* list, int len,int id);
static int removeNationality(Nationality* list, int len, int id);
static int sortNationality(Nationality* list, int len, int order);
static int printNationality(Nationality* list, int length);
static int modifyNationality(Nationality* list, int len);
static int unsuscribeNationality(Nationality* list, int len);
static int reportNationality(Nationality* list, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int employee_start (void)
{
	int retorno = -1;
	Nationality listEmployee[SIZE_NATIONALITY];
	menuNationality(listEmployee);
	return retorno;
}

int menuNationality(Nationality* aNationality)
{
	int retorno = -1;
	int option;
	int flagFirstEmployee = TRUE;
	int flagContinue = TRUE;
	int attemps = 2;
	printf("-----------------------------------\nXXXXXXXX| SECCIÓN PAISES |XXXXXXXXX\n-----------------------------------\n");
	initNationality(aNationality, SIZE_NATIONALITY);
	do
	{
		utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> AGREGAR NUEVO PAIS\n[2] -> MODIFICAR PAIS\n[3] -> BAJA DE PAIS\n[4] -> INFORMAR DATOS PAIS\n[5] -> SALIR\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1);
		switch (option)
		{
		case 1:
			if(newNationality(aNationality,SIZE_NATIONALITY)==0)
			{
				printf("\n-----------------------------------\nXXXXXXXXX| PAIS CARGADO |XXXXXXXXXX\n-----------------------------------\n");
				flagFirstEmployee = FALSE;
			}else
			{
				printf("\n-----------------------------------\nXXXXXX| NO SE CARGÓ EL PAIS |XXXXXX\n-----------------------------------\n");
			}
			break;
		case 2:
			if(flagFirstEmployee == FALSE)
			{
				if(modifyNationality(aNationality,SIZE_NATIONALITY)==0)
				{
					printf("\n-----------------------------------\nXXXXXXXXX| PAIS CARGADO |XXXXXXXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXXXX| NO SE CARGÓ EL PAIS |XXXXXX\n-----------------------------------\n");
				}

			}else{
					printf("\n-----------------------------------\nXXXX| NO HAY PAISES CARGADOS |XXXX\n-----------------------------------\n");
				attemps--;
				if(attemps <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 3:
			if(flagFirstEmployee == FALSE)
			{
				if(unsuscribeNationality(aNationality, SIZE_NATIONALITY)==0)
				{
					printf("\n-----------------------------------\nXXXXXXX| PAIS DADO DE BAJA |XXXXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXXXXX| NO SE DIÓ DE BAJA |XXXXXXX\n-----------------------------------\n");
				}

			}else{
					printf("\n-----------------------------------\nXXXX| NO HAY PAISES CARGADOS |XXXX\n-----------------------------------\n");
				attemps--;
				if(attemps <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 4:
			if(flagFirstEmployee == FALSE)
			{
				reportNationality(aNationality, SIZE_NATIONALITY);
			}else{
				printf("\n-----------------------------------\nXXXX| NO HAY PAISES CARGADOS |XXXX\n-----------------------------------\n");
				attemps--;
				if(attemps <= 0)
				{
					printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
				}
			}
			break;
		case 5:
			//SALIR
			printf("\n-----------------------------------\nXXXXXXXX| CERRANDO SISTEMA |XXXXXXX\n-----------------------------------\n");
			flagContinue = FALSE;
			break;
		default:
			attemps--;
			if(attemps >= 0)
			{
				printf("XXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n");
			}else
			{
				printf("\n-----------------------------------\nXXXXXX| NO HAY MAS INTENTOS |XXXXXX\nXXXXXX|  CERRANDO PROGRAMA  |XXXXXX\n-----------------------------------\n");
			}
			break;
		}
	}while(flagContinue == TRUE && attemps >= 0);
	return retorno;
}

static int newIdNationality(void)
{
	static int id = 999;
	id = id+1;
	return id;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int initNationality(Nationality* list, int len)
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

static int modifyNationality(Nationality* list, int len)
{
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;

	if(utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL PAISS -----\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 1000)==0 && findNationalityById(list, SIZE_NATIONALITY, bufferId) >= 0)
	{
		bufferIndex = findNationalityById(list, SIZE_NATIONALITY, bufferId);
		printf("\n------ PAIS A MODIFICAR -------\n\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[bufferIndex].name,list[bufferIndex].id,bufferIndex);
		do
		{
			if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> MODIFICAR NOMBRE\n[2] -> SALIR\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1)==0)
			{

				switch (option)
				{
				case 1:
					if (utn_getChar(list[bufferIndex].name, SIZE_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
					{
						strupr(list[bufferIndex].name);
						printf("\n-----------------------------------\nXXXXXXXX| NOMBRE CARGADO |XXXXXXXXX\n-----------------------------------\n");
						retorno = 0;
					}else
					{
						printf("\n-----------------------------------\nXXXXX| NO SE CARGÓ EL NOMBRE |XXXXX\n-----------------------------------\n");
					}
					break;
				case 2:
					flagContinue = FALSE;
					break;
				}
			}

		}while(flagContinue == TRUE && list[bufferIndex].isEmpty == FALSE);

	}else
	{
		printf("\n-----------------------------------\nXXX| NO EXISTE EL ID INGRESADO |XXX\nXXX|    NO HAY MÁS INTENTOS    |XXX\n-----------------------------------");
	}
	return retorno;
}

static int serchIndexEmpty(Nationality* list, int len)
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

static int newNationality(Nationality* list, int len)
{
	int retorno = -1;
	int id;
	Nationality bufferArrray;

	if (serchIndexEmpty(list, SIZE_NATIONALITY) >= 0 &&
		utn_getChar(bufferArrray.name, SIZE_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
	{
		id = newIdNationality();
		strupr(bufferArrray.name);
		if (addNationality(list,SIZE_NATIONALITY,id,bufferArrray.name)==0)
		{
			printf("\n------------- ID PAIS -------------\n> %d\n", id);
			retorno = 0;
		}
	}else if(serchIndexEmpty(list, SIZE_NATIONALITY) == -1){
			printf("-----------------------------------\n");
			printf("XXXXXX| NO HAY ESPACIO PARA |XXXXXX\n");
			printf("XXXXXX|  NUEVOS PAISS   |XXXXXX\n");
			printf("-----------------------------------\n\n");
			retorno = -2;
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
static int addNationality(Nationality* list, int len, int id, char name[])
{
	int retorno = -1;
	int index;
	if(list != NULL && len>0)
	{
		index = serchIndexEmpty(list, SIZE_NATIONALITY);
		list[index].id = id;
		strncpy(list[index].name, name, SIZE_NAME);
		list[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found] /// CONSULTAR EL NULL ///
 *
 */
static int findNationalityById(Nationality* list, int len,int id)
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

static int unsuscribeNationality(Nationality* list, int len)
{
	int retorno = -1;
	int bufferId;
	if((utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL PAIS -----\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 999)==0) && (removeNationality(list, SIZE_NATIONALITY, bufferId)==0))
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
static int removeNationality(Nationality* list, int len, int id)
{
	int retorno = -1;
	int index;
	index = findNationalityById(list, SIZE_NATIONALITY, id);
	if(index > -1)
	{
		list[index].isEmpty = TRUE;
		printf("\n----- PAIS DADO DE BAJAR ------\n\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[index].name,list[index].id,index);
		retorno = 0;
	}
	return retorno;
}

static int reportNationality(Nationality* list, int len)
{
	int retorno = -1;
	int option;

	if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> ORDEN ASCENDENTE\n[2] -> ORDEN DESCENDENTE\n[3] -> ATRAS\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 4, 1)==0)
	{

		switch (option)
		{
		case 1:
			sortNationality(list, SIZE_NATIONALITY, 1);
			printNationality(list, SIZE_NATIONALITY);
			retorno = 0;
			break;
		case 2:
			sortNationality(list, SIZE_NATIONALITY, 0);
			printNationality(list, SIZE_NATIONALITY);
			retorno = 0;
			break;
		case 3:
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int sortNationality(Nationality* list, int len, int order)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	Nationality bufferEmployee;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		while(flagSort==0)
		{
			flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if((strcmp(list[index].name, list[index+1].name) < 0 && order == 1) || (strcmp(list[index].name, list[index+1].name) > 0 && order == 0))
				{
					bufferEmployee = list[index];
					list[index] = list[index+1];
					list[index+1] = bufferEmployee;
					flagSort=0;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
static int printNationality(Nationality* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[i].name,list[i].id,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}
