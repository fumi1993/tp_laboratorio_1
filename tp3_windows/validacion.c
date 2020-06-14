#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacion.h"

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo)

{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}while(retorno !=0);
	return retorno;
}
int getFloat(	float *pResultado,
			char *pMensaje,
			char *pMensajeError,
			float minimo,
			float maximo)
{
	int retorno = -1;
	float buffer;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%f",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}while(retorno !=0);
	return retorno;
}

int getName(    char *bName,
				char *pMensaje,
				char *pMensajeError)
{
	int retorno = -1;
	char buffer[255];

	if(		bName != NULL &&
			pMensaje != NULL &&
			pMensajeError != NULL)
	{
		do
		{
			printf("%s",pMensaje);
			fflush(stdin);
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1]='\0';
			if(strlen(buffer)<=255 && strlen(buffer)>=0)
			{
                if(isSpace(buffer)==0)
                {
                    strcpy(bName,buffer);
                    retorno = 0;
                    break;
                }
            }
			printf("%s",pMensajeError);
		}while(retorno != 0);
	}
	return retorno;
}

int isSpace(char buffer[])
{
    int retorno = -1;
    int error;

    for(int i=0;i<strlen(buffer);i++)
    {
        if((buffer[i]>='A' && buffer[i]<='Z') || (buffer[i]>='a' && buffer[i]<='z') || buffer[i]==' ' || buffer[i]=='\0')
        {
            error = 0;
        }
        else
        {
            error = -1;
            break;
        }
    }
    if(error == 0)
    {
        retorno = 0;
    }
    return retorno;
}

char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo)
{
	int retorno = -1;
	char buffer;
	if(	resultado != NULL &&
        mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(scanf("%c",&buffer)==1)
			{
				if(buffer == minimo || buffer == maximo)
				{
					retorno = 0;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
		}while(retorno !=0);
	}
	return retorno;
}
