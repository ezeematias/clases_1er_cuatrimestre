/*
 ============================================================================
 Name        : COD_DE_PRUEBAS.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "alumno.h"

int main(void)
{
	setbuf(stdout, NULL);

	int op;
	int indice;
	Alumno arrayAlumnos[5];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getInt("\n1-Alta\n2-Mostrar\n8-Salir","\nError",&op,2,3,1);
		switch(op)
		{
			case 1:
				if(alumno_indexEmptyReference(arrayAlumnos, QTY_ALUMNOS, &indice) == 0)
				// alumno_buscarLibre(arrayAlumnos,QTY_ALUMNOS)
				{
					alumno_alta(arrayAlumnos,QTY_ALUMNOS,indice);
				}
				break;
			case 2:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				// alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 3:
				//alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				// alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 4:
				// alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 5:
				//alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;

		}
	}while(op != 3);

	return EXIT_SUCCESS;
}




