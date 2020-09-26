/*
 * utn.c
 *
 *  Created on: 8 sept. 2020
 *      Author: peque
 */

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <string.h>

#include "utn.h"

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

void utn_ordenarArray(int array[], int len)
{
	int indice;
	int flagEstadoDesordenado = 1;
	int aux;

	while(flagEstadoDesordenado==1)
	{
	flagEstadoDesordenado=0;
		for(indice=0 ; indice<(len-1)  ; indice++)
		{
			if(array[indice] > array[indice+1])
			{
				// intercambiar (swap)
				aux = array[indice];
				array[indice] = array[indice+1];
				array[indice+1] = aux;
				flagEstadoDesordenado=1;
			}
		}
	}
}

int utn_printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for (i = 0;i<limite;i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}

int getNombre(char* mensaje, char* mensajeError, char*pResultado, int reintentos, int limite)
{
	int retorno = -1;
	char bufferString[4096];
	int resuldadoScanf;

	printf("Ingrese su nombre");
	fflush(stdin);
	resuldadoScanf = scanf("%s", bufferString);

	if (resuldadoScanf == 1 && strnlen(bufferString,sizeof(bufferString)-1)<= limite)
	{
		retorno = 0;

	}else
	{


	}
	// Entre la a minuscula y la Z mayuscula lo que ingrese el chabon

	/*
	 * GDB DE MAURICIO REUELTA CON LA FUINCIÓN
	 * https://www.onlinegdb.com/SJEXiJJHv
	 */

	return retorno;
}
