/*
 ============================================================================
 Name        : COD_CLASE_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	float numeroFloatIngresado;
	char nombreIngresado;

	if (utn_getNumber(&numeroIngresado, 10, 50, "Ingrese un número", "Debe ingresar un número válido", 3) == 0)
	{
		if (utn_getNumbreFloat(&numeroFloatIngresado , 10.00, 100.00, "Ingrese número decimal: ", "Vuelva a ingresar un número decimal :" , 3)==0)
		{
			if (utn_getChar (&nombreIngresado, "Ingrese su nombre: ", "Coloque un nombre válido ", 3)== 0)
			{
				printf("El número ingresado es: %d", numeroIngresado);
				printf("\nEl númro flotante ingresado es  :%.2f", numeroFloatIngresado);
				printf("\nEl dueño de los números ingresados es %c", nombreIngresado);
			}
		}
	}
	return EXIT_SUCCESS;
}

