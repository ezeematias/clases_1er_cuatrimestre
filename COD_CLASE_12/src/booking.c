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

static int initBooking(Booking* list, int len);
static int addBooking(Booking* list, int len, int id, char name[], int quantityDays, float cuitClient,char* idDisplay);
static int newBooking(Booking* list, int len);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
static int initBooking(Booking* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for(int i=0;i<=len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].idBooking = 0;
		}
		retorno = 0;
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
static int addBooking(Booking* list, int len, int id, char name[], int quantityDays, float cuitClient,char* idDisplay)
{
	int retorno = -1;
	int index;
	if(list != NULL && len>0)
	{
		index = serchIndexEmpty(list, SIZE_QTYDISPLAY);
		list[index].idBooking = id;
		strncpy(list[index].nameFileBooking, name, SIZE_NAME);
		list[index].quantityDays = quantityDays;
		list[index].cuitClient = cuitClient;
		strncpy(list[index].idDisplay, idDisplay, SIZE_LOCATION);
		list[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

static int newBooking(Booking* list, int len)
{
	int retorno = -1;
	int id;
	Booking bufferArrray;

	if (serchIndexEmpty(list, SIZE_QTYDISPLAY) >= 0 &&
		utn_getChar(bufferArrray.nameFileBooking, SIZE_NAME,"\n--------- INGRESE NOMBRE ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0 &&
		utn_getInt(&bufferArrray.quantityDays, 10, 2, "INGRESE TIPO \n\n[1] -> LCD\n[2] -> LED", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2, 1)==0 &&
		utn_getFloat(&bufferArrray.cuitClient, 10, 2, "INGRESE PRECIO POR DÍA", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n",LONG_MAX , 1)==0 &&
		utn_getChar(bufferArrray.idDisplay, SIZE_LOCATION,"\n--------- INGRESE DIRECCIÓN ----------", "\nXXXXXXX|  DATO NO VÁLIDO  |XXXXXXXX\n", 2)==0)
	{
		id = newIdDisplay();
		strupr(bufferArrray.nameFileBooking);
		if (addBooking(list,SIZE_QTYDISPLAY,id,bufferArrray.nameFileBooking,bufferArrray.quantityDays,bufferArrray.cuitClient,bufferArrray.idDisplay)==0)
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



