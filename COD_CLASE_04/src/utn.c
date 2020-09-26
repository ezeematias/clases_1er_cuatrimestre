/*
 * utn.c
 *
 *  Created on: 5 sept. 2020
 *      Author: peque
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumber (int* pNumeroIngresado, int minimo, int maximo, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno =-1;
	int numeroIngresado;
	int resultadoScanf;

	while(reintentos > 0)
	{
		printf("%s\n", mensaje);
		fflush(stdin);
		resultadoScanf = scanf("%d", &numeroIngresado);

		if (resultadoScanf == 1 && numeroIngresado >= minimo && numeroIngresado <= maximo)
		{
			*pNumeroIngresado = numeroIngresado;
			retorno = 0;
			break;
		}else
		{
			reintentos--;
			if (reintentos > 0)
			{
				printf("%s\n", mensajeError);
			}
		}
	}
	if(reintentos == 0)
	{
		printf("Se agotaron los reintentos posibles.");
	}

	return retorno;
}

int utn_getNumbreFloat (float* pNumeroFloatIngresado, float minimo, float maximo, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	float numeroFloatIngresado;
	int resultadoScanf;

	while (reintentos > 0)
	{
		printf("%s\n", mensaje);
		fflush(stdin);
		resultadoScanf = scanf("%f", &numeroFloatIngresado);

		if (resultadoScanf == 1 && numeroFloatIngresado >= minimo && numeroFloatIngresado <= maximo)
		{
			*pNumeroFloatIngresado = numeroFloatIngresado;
			retorno = 0;
			break;
		}else
		{
			reintentos--;
			if (reintentos > 0)
			{
				printf("%s\n", mensajeError);
			}
		}
	}
	if(reintentos == 0)
	{
		printf("Se agotaron los reintentos posibles.");
	}

	return retorno;
}

int utn_getChar (char* pNombreIngresado, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char nombreIngresado;
	int resultadoScanf = 0;

	while (reintentos > 0)
	{
		printf("%s\n", mensaje);
		fflush(stdin);
		resultadoScanf = scanf("%s", &nombreIngresado);
		if (resultadoScanf == 1)
		{
			*pNombreIngresado = nombreIngresado;
			retorno = 0;
			break;
		}else
		{
			reintentos--;
			if (reintentos > 0)
			{
				printf("%s\n", mensajeError);
			}
		}
	}
	if(reintentos == 0)
	{
		printf("Se agotaron los reintentos posibles.");
	}
	return retorno;
}
int  get_factorial(int numeroX, int *resultado) {
	int retorno  = -1;
	int repeticiones;
	int bufferResultado = 1;
	if (numeroX != NULL && numeroX > 0) {
		for (repeticiones = numeroX ; repeticiones > 1 ; repeticiones--){
			bufferResultado *= repeticiones;
		}
		*resultado = bufferResultado;
		retorno = 0;
	}else{
		if (numeroX == 0){
		*resultado = 1;
		retorno = 0;
		} else{
			printf("\n El número operador no puede ser negativo");
		}
	}
	return retorno;
}
