/*
 ============================================================================
 Name        : COD_CLASE_10.c
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
#include "student.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int index = 0;
	Student arrayStudent[5];

	student_initArray(arrayStudent, QTY_ALUMNOS);
	do
	{
		if (utn_getInt(&option, 10, 2, "Ingrese una opción\n1 > Nuevo Alumno", "ERROR RE-", 5, 1)==0)
		{
			switch(option)
			{
			case 1:
				student_register(arrayStudent, QTY_ALUMNOS, index);
				index++;
				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

				break;

			case 5:
				student_printr(arrayStudent, QTY_ALUMNOS);
				break;

			}
		}
	}while(option != 8);

	return EXIT_SUCCESS;
}
