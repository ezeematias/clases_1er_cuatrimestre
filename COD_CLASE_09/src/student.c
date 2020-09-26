/*
 ============================================================================
 Name        : ALUMNO.C
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Bibioteca "alumno.c"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "student.h"

int student_register(Student*  pArray, int len, int index)
{
	int retorno = -1;
	Student bufferStudent;

	if(pArray != NULL && len > 0 && index > 0 && pArray[index].isEmpty == TRUE)
	{
		if (utn_getChar(bufferStudent.name, LONG_NOMBRE, "Ingrese el nombre del Alumno: \n >", "ERROR! RE-", 2) == 0 &&
			utn_getInt(&bufferStudent, LONG_NOMBRE, 2, "Ingrese el número de legajo \n >", "ERROR! RE-", 32767, -32767))
		{
			pArray[index] = bufferStudent;
			pArray[index].isEmpty = FALSE;
			retorno = 0;
		}
	}


	return retorno;
}

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int student_initArray(Student* pArray, int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}
