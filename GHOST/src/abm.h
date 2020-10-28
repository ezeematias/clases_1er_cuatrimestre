/*
 ============================================================================
 Name        : Ghost
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : ABM Fantasma
 ============================================================================
 */

#ifndef ABM_H_
#define ABM_H_
#define TRUE 1
#define FALSE 0
#define LONG_NAME 51
#define LONG_LASTNAME 51
#define LONG_EMPLOYEE 1000

struct
{
 int id;
 char name[LONG_NAME];
 char lastName[LONG_LASTNAME];
 float salary;
 int sector;
 int isEmpty;
}typedef Struct;

int abm_newId(void);
int abm_add(Struct* list, int len);
int abm_initStruct(Struct* list, int len);
int abm_findById(Struct* list, int len,int id);
int abm_serchIndexEmpty(Struct* list, int len);
int abm__sort(Struct* list, int len, int order);
int abm_print(Struct* list, int len);


#endif /* ABM_H_ */
