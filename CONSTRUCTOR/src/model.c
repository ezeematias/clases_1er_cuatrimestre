/*
 ============================================================================
 Name        : CONSTRUCTOR.c
 Author      : Unía, Ezequiel Matías
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "model.h"
#include "utn.h"

int model_menu()
{
	int retorno = -1;
	int option;
	int fields;
	int flagContinue = TRUE;
	int attempts = 2;
	Field bufferArray[LONG_STRUCT];

	model_initArray(bufferArray);
	printf(MSG_START);
	do
	{
		if(utn_getName(bufferArray[0].typeField, LONG_ARRAY, MSG_FIELD_TYPE, MSG_ERROR, attempts)==0 && utn_getName(bufferArray[0].nameField, LONG_STRUCT, MSG_NAME_TYPE, MSG_ERROR, attempts)==0)
		{
			bufferArray[0].isEmpty = 0;
			utn_getInt(&fields, 3, attempts, MSG_QTY_FIELD,MSG_OPTION_ERROR, LONG_STRUCT, 0);
			for(int i = 1; i <= fields; i++)
			{
				printf(MSG_NUMBER_FIELD,i);
				if(utn_getName(bufferArray[i].nameField, LONG_STRUCT, MSG_FIELD_TYPE_FIELD, MSG_ERROR, attempts)==0 && utn_getInt(&option, 3, attempts, MSG_NAME_TYPE_FIELD,MSG_OPTION_ERROR, 3, 0) ==0)
				{
					bufferArray[i].isEmpty = 0;
					switch(option)
					{
						case 1:
							strcpy(bufferArray[i].typeField,"int");
							break;
						case 2:
							strcpy(bufferArray[i].typeField,"float");
							break;
						case 3:
							strcpy(bufferArray[i].typeField,"char");
							break;
					}
				}
			}
		}
		model_new(bufferArray);
		model_delete(bufferArray);
		model_getField(bufferArray);
		model_isValid(bufferArray);
		model_setField(bufferArray);
		break;
	}while(flagContinue == TRUE);
	return retorno;
}

void model_initArray(Field* list)
{
	for(int i = 0; i < LONG_STRUCT; i++)
	{
		list[i].isEmpty = 1;
	}
}

/*1*/
void model_new(Field* list)
{
	printf("\n%s* %s_new()\n{\n\treturn (%s*)malloc(sizeof(%s));\n}\n",list[0].typeField,list[0].nameField,list[0].typeField,list[0].typeField);
}

/*3*/
void model_delete(Field* list)
{
	printf("\nvoid %s_delete(%s* this)\n{\n\tfree(this);\n}\n",list[0].nameField,list[0].typeField);
}

/*4*/
void model_getField(Field* list)
{
	char bufferField[LONG_ARRAY];
	for(int i = 1; i < LONG_STRUCT; i++)
	{
		if(list[i].isEmpty == 0)
		{
			strcpy(bufferField,list[i].nameField);
			bufferField[0] = toupper(bufferField[0]);
			printf("\n%s %s_get%s(%s* this)\n{\n\tif(this!=NULL)\n\t{\n\treturn this->%s;\n\t}\n\treturn NULL;\n}\n",list[i].typeField, list[0].nameField,bufferField,list[0].typeField,list[i].nameField);
		}
	}
}

/*5*/
void model_setField(Field* list)
{
	char bufferField[LONG_ARRAY];
	for(int i = 1; i < LONG_STRUCT; i++)
	{
		if(list[i].isEmpty == 0 && (strcmp(list[i].typeField,"int") == 0 || strcmp(list[i].typeField,"float") == 0))
		{
			strcpy(bufferField,list[i].nameField);
			bufferField[0] = toupper(bufferField[0]);
			printf("\nint %s_set%s(%s* this, %s %s)\n{\n\tint retorno = -1;\n\tif(this != NULL && isValid%s(%s) == 1)\n\t{\n\t\tthis->%s = %s;\n\t\tretorno = 0;\n\t}\n\treturn retorno;\n}",list[0].nameField,bufferField,list[0].typeField,list[i].typeField,list[i].nameField,bufferField,list[i].nameField,list[i].nameField,list[i].nameField);
		}else if (list[i].isEmpty == 0 && strcmp(list[i].typeField,"char") == 0)
		{
			strcpy(bufferField,list[i].nameField);
			bufferField[0] = toupper(bufferField[0]);
			printf("\nint %s_set%s(%s* this, %s %s)\n{\n\tint retorno = -1;\n\tif(this != NULL && isValid%s(%s) == 1)\n\t{\n\t\tstrnpcy(this->%s,%s,(int) sizeof(this->%s));\n\t\tretorno = 0;\n\t}\n\treturn retorno;\n}",list[0].nameField,bufferField,list[0].typeField,list[i].typeField,list[i].nameField,bufferField,list[i].nameField,list[i].nameField,list[i].nameField,list[i].nameField);
		}
	}
}

/*6*/
void model_isValid(Field* list)
{
	char bufferField[LONG_ARRAY];
	for(int i = 1; i < LONG_STRUCT; i++)
	{
		if(list[i].isEmpty == 0)
		{
			strcpy(bufferField,list[i].nameField);
			bufferField[0] = toupper(bufferField[0]);
			printf("\n%s %s_get%s(%s* this)\n{\n\tif(this!=NULL)\n\t{\n\treturn this->%s;\n\t}\n\treturn NULL;\n}\n",list[i].typeField, list[0].nameField,bufferField,list[0].typeField,list[i].nameField);
			printf("\nint isValid%s(%s %s)\n{\n\treturn 1;\n}",bufferField,list[i].typeField,list[i].nameField);
		}
	}
}

