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
/*
	int numeroIngresado;
	float numeroFloatIngresado;
	char nombreIngresado;

	if (utn_getNumber(&numeroIngresado, 10, 50, "Ingrese un n�mero", "Debe ingresar un n�mero v�lido", 3) == 0)
	{
		if (utn_getNumbreFloat(&numeroFloatIngresado , 10.00, 100.00, "Ingrese n�mero decimal: ", "Vuelva a ingresar un n�mero decimal :" , 3)==0)
		{
			if (utn_getChar (&nombreIngresado, "Ingrese su nombre: ", "Coloque un nombre v�lido ", 3)== 0)
			{
				printf("El n�mero ingresado es: %d", numeroIngresado);
				printf("\nEl n�mro flotante ingresado es  :%.2f", numeroFloatIngresado);
				printf("\nEl due�o de los n�meros ingresados es %c", nombreIngresado);
			}
		}
	}
	*/

	int prueba = 5;
	int prueba2 = -1;
	int prueba3 = 3;
	int resultado;

	get_factorial(prueba, &resultado);
	printf("%d", resultado);
	get_factorial(prueba2, &resultado);
	printf("\n%d", resultado);
	get_factorial(prueba3, &resultado);
	printf("\n%d", resultado);

	return EXIT_SUCCESS;
}

