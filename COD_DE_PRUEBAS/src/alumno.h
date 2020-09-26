/*
 * alumno.h
 *
 *  Created on: Sep 22, 2020
 *      Author: Mauro
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int id;
	int legajo;
	int isEmpty;
}Alumno;

int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int alumno_recibeArrayPrint(Alumno* pArray, int limit, int index);
int alumno_indexEmpty(Alumno* pArray,int limite);
int alumno_indexEmptyReference(Alumno* pArray,int limite, int* pIndex);
static int alumno_generarId (void);
int alumno_idIndex(Alumno* pArray,int limite, int id);
int alumno_idIndexReference(Alumno* pArray,int limite, int* pIndex, int id);


#endif /* ALUMNO_H_ */
