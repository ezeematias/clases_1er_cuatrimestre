#ifndef NATIONALITY_H_
#define NATIONALITY_H_

#define TRUE 1
#define FALSE 0
#define SIZE_NAME 51
#define SIZE_NATIONALITY 50

struct
{
 int id;
 char name[SIZE_NAME];
 int isEmpty;
}typedef Nationality;

int menuNationality(Nationality* aEmployee);

#endif /* NATIONALITY_H_ */
