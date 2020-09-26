/*
 * student.h
 *
 *  Created on: 24 sept. 2020
 *      Author: peque
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{
	char name[LONG_NOMBRE];
	int file;
	int isEmpty;
}Student;

int student_register(Student* pArray, int len, int index);
int student_initArray(Student* pArray, int len);


#endif /* STUDENT_H_ */
