/*
 ============================================================================
 Name        : COD_CLASE_09.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"


int main(void)
{
	int op;
	int indice = 0;
	Alumno arrayAlumnos[5];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getInt("\n1> Alta\n2> Modificar \n3> Baja \n4> Salir","\nError",&op,2,3,1);
		switch(op)
		{
			case 1:
					alumno_alta(arrayAlumnos,QTY_ALUMNOS,indice);
					indice++;
				break;
			case 2:
				// alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 3:
				// alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 4:
				// alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 5:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;

		}
	}while(op != 8);
	return EXIT_SUCCESS;
}
