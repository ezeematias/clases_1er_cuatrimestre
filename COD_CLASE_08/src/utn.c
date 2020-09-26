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

	if(pArray != NULL && limite > 0)
	{
		for (i = 0;i<limite;i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n",i,pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int utn_contarIntEnArray(int* pArray, int limite, int numero)
{
	int retorno = -1;
	int i;
	int contadorNumeros = 0;

	if(pArray != NULL && limite > 0)
	{
		for (i = 0;i<limite;i++)
		{
			if (pArray[i] == numero)
			{
				contadorNumeros++;
			}
		}
		retorno = 0;
		printf("La cantidad de %d en su array es de:\n> %d",numero, contadorNumeros);
	}
	return retorno;
}

int utn_contarIntEnArrayReferencia(int* pArray, int limite, int numero, int* pContador)
{
	int retorno = -1;
	int i;
	int bufferContador=0;

	if(pArray != NULL && pContador != NULL && limite > 0)
	{
		for (i = 0;i<limite;i++)
		{
			if (pArray[i] == numero)
			{
				bufferContador++;
			}
		}
		retorno = 0;
		*pContador = bufferContador;
	}
	return retorno;
}

int utn_contarCharEnArray(char* pArray, int limite, char letra)
{
	int retorno = -1;
	int i;
	int contadorNumeros = 0;

	if(pArray != NULL && limite > 0)
	{
		for (i = 0;i<limite;i++)
		{
			if (pArray[i] == letra)
			{
				contadorNumeros++;
			}
		}
		retorno = 0;
		printf("La cantidad de %c en su array es de:\n> %d",letra, contadorNumeros);
	}
	return retorno;
}

int utn_contarCharEnArrayReferencia(char* pArray, int limite, char letra, int* pContador)
{
	int retorno = -1;
	int i;
	int bufferContador=0;

	if(pArray != NULL && pContador != NULL && limite > 0)
	{
		for (i = 0;i<limite;i++)
		{
			if (pArray[i] == letra)
			{
				bufferContador++;
			}
		}
		retorno = 0;
		*pContador = bufferContador;
	}
	return retorno;
}

int utn_verificarCharEnArray(char* pArray)
{
	int retorno = 0;
	int i;

	if(pArray != NULL)
	{
		for (i = 0;pArray[i] != '\0';i++)
		{
			if ((pArray[i] < 'a' || pArray[i] > 'z') && (pArray[i] < 'A' || pArray[i] > 'Z'))
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNombre(char* aNombre)
{
	int retorno = -1;
	int resultadoScanf;
	printf("Ingrese su nombre \n > ");
	fflush(stdin);
	resultadoScanf = scanf("%s", aNombre);
	if(resultadoScanf > 0)
	{
		retorno = 0;
	}
	return retorno;
}
