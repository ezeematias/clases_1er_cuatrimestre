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
	int flagContinue = TRUE;
	int attempts = 2;
	Field bufferArray;

	printf(MSG_START);
	do
	{
		utn_getInt(&option, 3, attempts, MSG_OPTION_MENU,MSG_OPTION_ERROR, 8, 0);
		switch(option)
		{
		case 0:
			flagContinue = FALSE;
			printf(MSG_OFF);
			break;
		case 1:
			if(utn_getName(bufferArray.nameField, LONG_ARRAY, MSG_NAME_TYPE, MSG_ERROR, attempts)==0)
			{
				model_new(bufferArray.nameField);
			}
			break;
		case 2:

			break;
		case 3:
			if(utn_getName(bufferArray.nameField, LONG_ARRAY, MSG_NAME_TYPE, MSG_ERROR, attempts)==0 && utn_getName(bufferArray.thisField, LONG_ARRAY, MSG_THIS, MSG_ERROR, attempts)==0)
			{
				model_delete(bufferArray.nameField,bufferArray.thisField);
			}
			break;
		case 4:
			if(utn_getName(bufferArray.typeField, LONG_ARRAY, MSG_FIELD_TYPE, MSG_ERROR, attempts)==0 && utn_getName(bufferArray.nameField, LONG_ARRAY, MSG_NAME_TYPE, MSG_ERROR, attempts)==0 && utn_getName(bufferArray.thisField, LONG_ARRAY, MSG_THIS, MSG_ERROR, attempts)==0 && utn_getName(bufferArray.field, LONG_ARRAY, MSG_FIELD, MSG_ERROR, attempts)==0)
			{
				model_getField(bufferArray.typeField,bufferArray.nameField,bufferArray.thisField,bufferArray.field);
			}
			break;
		case 5:

			break;
		case 6:

			break;
		}
	}while(flagContinue == TRUE);
	return retorno;
}

/*1*/
void model_new(char* msgType)
{
	char type[LONG_ARRAY];
	char typeFuntion[LONG_ARRAY];
	strcpy(type,msgType);
	strcpy(typeFuntion,msgType);
	typeFuntion[0] = tolower(typeFuntion[0]);
	printf("\n%s* %s_new()\n{\n\treturn (%s*)malloc(sizeof(%s));\n}\n",type,typeFuntion,type,type);
}

/*3*/
void model_delete(char* msgType, char* msgThis)
{
	char type[LONG_ARRAY];
	char typeFuntion[LONG_ARRAY];
	char this[LONG_ARRAY];
	strcpy(type,msgType);
	strcpy(typeFuntion,msgType);
	typeFuntion[0] = tolower(typeFuntion[0]);
	strcpy(this,msgThis);
	printf("\nvoid %s_delete(%s* %s)\n{\n\tfree(%s);\n}\n",typeFuntion,type,this,this);
}

/* 4 */
void model_getField(char* msgTypeField, char* msgType,char* msgThis, char* msgField)
{
	char typeField[LONG_ARRAY];
	char type[LONG_ARRAY];
	char typeFuntion[LONG_ARRAY];
	char this[LONG_ARRAY];
	char field[LONG_ARRAY];
	strcpy(typeField,msgTypeField);
	strcpy(type,msgType);
	strcpy(typeFuntion,msgType);
	typeFuntion[0] = tolower(typeFuntion[0]);
	strcpy(this,msgThis);
	strcpy(field,msgField);

	printf("\n%s %s_getField(%s* %s)\n{\n\tif(%s!=NULL)\n\t{\n\treturn %s->%s;\n\t}\nreturn NULL;\n}\n",typeField,typeFuntion,type,this,this,this,field);
}


/* 5 */
void model_setField(char* msgTypeField, char* msgType,char* msgThis, char* msgField)
{
	char typeField[LONG_ARRAY];
	char type[LONG_ARRAY];
	char typeFuntion[LONG_ARRAY];
	char this[LONG_ARRAY];
	char field[LONG_ARRAY];
	strcpy(typeField,msgTypeField);
	strcpy(type,msgType);
	strcpy(typeFuntion,msgType);
	typeFuntion[0] = tolower(typeFuntion[0]);
	strcpy(this,msgThis);
	strcpy(field,msgField);

	printf("\n%s %s_getField(%s* %s)\n{\n\tif(%s!=NULL)\n\t{\n\treturn %s->%s;\n\t}\nreturn NULL;\n}\n",typeField,typeFuntion,type,this,this,this,field);
}
int tipo_setCampo(tipo* this, tipoCampo campo)
{
	int retorno = -1;
	if(this != NULL && isValidCampo(campo) == 1)
	{
		this->campo = campo;
		retorno = 0;
	}
	return retorno;
}

