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
#include "display.h"
#include "utn.h"

static int newIdDisplay(void);
static int initDisplay(Display* list, int len);
static int newDisplay(Display* list, int len);
static int addDisplay(Display* list, int len, int id, char name[], int typeDisplay, float priceDay,char* locationAddress);
static int findDisplayById(Display* list, int len,int id);
static int removeDisplay(Display* list, int len, int id);
static int sortDisplay(Display* list, int len, int order);
static int modifyDisplay(Display* list, int len);
static int unsuscribeDisplay(Display* list, int len);
static int reportDisplay(Display* list, int len);

int menuDisplay(Display* aDisplay)
{
	int retorno = -1;
	int option;
	int flagFirstEmployee = TRUE;
	int flagContinue = TRUE;
	int attemps = 2;
	printf("-----------------------------------\nXXXXXXXX| SECCIÓN PANTALLAS |XXXXXXXXX\n-----------------------------------\n");
	initDisplay(aDisplay, SIZE_QTYDISPLAY);
	do
	{
		utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> AGREGAR NUEVA PANTALLA\n[2] -> MODIFICAR PANTALLA\n[3] -> BAJA DE PANTALLA\n[4] -> CONTRATAR PANTALLA\n[5] -> SALIR\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1);
		switch (option)
		{
		case 1:
			if(newDisplay(aDisplay,SIZE_QTYDISPLAY)==0)
			{
				printf("\n-----------------------------------\nXXXXXXXXX| PANTALLA CARGADA |XXXXXXXXXX\n-----------------------------------\n");
				flagFirstEmployee = FALSE;
			}else
			{
				printf("\n-----------------------------------\nXXXXXX| NO SE CARGÓ PANTALLA |XXXXXX\n-----------------------------------\n");
			}
			break;
		case 2:
			if(flagFirstEmployee == FALSE)
			{
				if(modifyDisplay(aDisplay,SIZE_QTYDISPLAY)==0)
				{
					printf("\n-----------------------------------\nXXXXXXXXX| PANTALLA CARGADA |XXXXXXXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXXXX| NO SE CARGÓ PANTALLA |XXXXXX\n-----------------------------------\n");
				}

			}else{
					printf("\n-----------------------------------\nXXXX| NO HAY PANTALLAS CARGADOS |XXXX\n-----------------------------------\n");
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
				if(unsuscribeDisplay(aDisplay, SIZE_QTYDISPLAY)==0)
				{
					printf("\n-----------------------------------\nXXXXXXX| PANTALLA DADA DE BAJA |XXXXXXX\n-----------------------------------\n");
				}else
				{
					printf("\n-----------------------------------\nXXXXXXX| NO SE DIÓ DE BAJA |XXXXXXX\n-----------------------------------\n");
				}

			}else{
					printf("\n-----------------------------------\nXXXX| NO HAY PANTALLAS CARGADAS |XXXX\n-----------------------------------\n");
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
				reportDisplay(aDisplay, SIZE_QTYDISPLAY);
			}else{
				printf("\n-----------------------------------\nXXXX| NO HAY PANTALLAS CARGADAS |XXXX\n-----------------------------------\n");
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

static int newIdDisplay(void)
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
static int initDisplay(Display* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].idDisplay = 0;
		}
		retorno = 0;
	}
	return retorno;
}

static int modifyDisplay(Display* list, int len)
{
	int retorno = -1;
	int bufferId;
	int bufferIndex;
	int option;
	int flagContinue = TRUE;

	if(utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL PAISS -----\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 1000)==0 && findDisplayById(list, SIZE_QTYDISPLAY, bufferId) >= 0)
	{
		bufferIndex = findDisplayById(list, SIZE_QTYDISPLAY, bufferId);
		printf("\n------ PAIS A MODIFICAR -------\n\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[bufferIndex].nameDisplay,list[bufferIndex].idDisplay,bufferIndex);
		do
		{
			if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> MODIFICAR NOMBRE\n[2] -> SALIR\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 5, 1)==0)
			{

				switch (option)
				{
				case 1:
					if (utn_getChar(list[bufferIndex].nameDisplay, SIZE_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
					{
						strupr(list[bufferIndex].nameDisplay);
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

static int serchIndexEmpty(Display* list, int len)
{
	int retornar = -1;
	if(list != NULL && len>0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE && list[i].idDisplay == 0)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

static int newDisplay(Display* list, int len)
{
	int retorno = -1;
	int id;
	Display bufferArrray;

	if (serchIndexEmpty(list, SIZE_QTYDISPLAY) >= 0 &&
		utn_getChar(bufferArrray.nameDisplay, SIZE_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getInt(&bufferArrray.typeDisplay, 10, 2, "INGRESE TIPO \n\n[1] -> LCD\n[2] -> LED", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2, 1)==0 &&
		utn_getFloat(&bufferArrray.priceDay, 10, 2, "INGRESE PRECIO POR DÍA", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n",LONG_MAX , 1)==0 &&
		utn_getChar(bufferArrray.locationAddress, SIZE_LOCATION,"\n--------- INGRESE DIRECCIÓN ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
	{
		id = newIdDisplay();
		strupr(bufferArrray.nameDisplay);
		if (addDisplay(list,SIZE_QTYDISPLAY,id,bufferArrray.nameDisplay,bufferArrray.typeDisplay,bufferArrray.priceDay,bufferArrray.locationAddress)==0)
		{
			printf("\n------------- ID PAIS -------------\n> %d\n", id);
			retorno = 0;
		}
	}else if(serchIndexEmpty(list, SIZE_QTYDISPLAY) == -1){
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
static int addDisplay(Display* list, int len, int id, char name[], int typeDisplay, float priceDay,char* locationAddress)
{
	int retorno = -1;
	int index;
	if(list != NULL && len>0)
	{
		index = serchIndexEmpty(list, SIZE_QTYDISPLAY);
		list[index].idDisplay = id;
		strncpy(list[index].nameDisplay, name, SIZE_NAME);
		list[index].typeDisplay = typeDisplay;
		list[index].priceDay = priceDay;
		strncpy(list[index].locationAddress, locationAddress, SIZE_LOCATION);
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
static int findDisplayById(Display* list, int len,int id)
{
	int retorno = -1;
	for(int i=0;i<len;i++)
	{
		if(list[i].idDisplay == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

static int unsuscribeDisplay(Display* list, int len)
{
	int retorno = -1;
	int bufferId;
	if((utn_getInt(&bufferId, 50, 2, "\n----- INGRESE ID DEL PAIS -----\n", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2000, 999)==0) && (removeDisplay(list, SIZE_QTYDISPLAY, bufferId)==0))
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
static int removeDisplay(Display* list, int len, int id)
{
	int retorno = -1;
	int index;
	index = findDisplayById(list, SIZE_QTYDISPLAY, id);
	if(index > -1)
	{
		list[index].isEmpty = TRUE;
		printf("\n----- PAIS DADO DE BAJAR ------\n\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[index].nameDisplay,list[index].idDisplay,index);
		retorno = 0;
	}
	return retorno;
}

static int reportDisplay(Display* list, int len)
{
	int retorno = -1;
	int option;

	if(utn_getInt(&option, 2, 2, "\n------ SELECCIONE UNA OPCIÓN ------\n\n[1] -> ORDEN ASCENDENTE\n[2] -> ORDEN DESCENDENTE\n[3] -> ATRAS\n\n[OPCIÓN SELECCIONADA]", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 4, 1)==0)
	{

		switch (option)
		{
		case 1:
			sortDisplay(list, SIZE_QTYDISPLAY, 1);
			printDisplay(list, SIZE_QTYDISPLAY);
			retorno = 0;
			break;
		case 2:
			sortDisplay(list, SIZE_QTYDISPLAY, 0);
			printDisplay(list, SIZE_QTYDISPLAY);
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
static int sortDisplay(Display* list, int len, int order)
{
	int retorno = -1;
	int index;
	int flagSort = 0;
	Display bufferEmployee;

	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		while(flagSort==0)
		{
			flagSort=1;
			for(index=0 ; index<(len-1)  ; index++)
			{
				if((strcmp(list[index].nameDisplay, list[index+1].nameDisplay) < 0 && order == 1) || (strcmp(list[index].nameDisplay, list[index+1].nameDisplay) > 0 && order == 0))
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
int printDisplay(Display* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n[NOMBRE] ---> %s\n[ID] -------> %d\n[INDEX] ----> %d\n",list[i].nameDisplay,list[i].idDisplay,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}
