/*
 * parser.c
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "LinkedList.h"
#include "eMovie.h"
#include "inputs.h"

int controller_cargarArchivoTexto(char* path , LinkedList* arrayMovies)
{
	if(path != NULL && arrayMovies != NULL)
	{
		FILE* pf;
		pf = fopen(path,"r");

		char id[15];
		char titulo[50];
		char genero[50];
		char tiempo[15];
		eMovie* movieAux;

		fscanf(pf,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,tiempo);
		while(!feof(pf))
		{
			fscanf(pf,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,tiempo);
			movieAux = newMovieParametros(id, titulo, genero, tiempo);
			ll_add(arrayMovies, movieAux);
		}
	}
    return 1;
}

void imprimirLista(LinkedList* arrayMovies)
{
	if(arrayMovies != NULL)
	{
		printf("  id                    titulo              genero    tiempo\n");
		for(int i = 0; i<ll_len(arrayMovies);i++)
		{
			imprimirUno(ll_get(arrayMovies, i));
		}
	}
}

void asignarTiempo(void* elemento)
{
	if(elemento != NULL)
	{
		eMovie* movAux;
		movAux = (eMovie*) elemento;
		movie_setDuracion(movAux, rand()%((240-100)+1)+100);
	}

}

int filtrarGenero(eMovie* mov,char* genero)
{
	int retorno;
	retorno = 0;
	if(mov != NULL)
	{
		if(strcmp(mov->genero,genero) == 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int controller_FiltrarGenero(LinkedList* arrayMovies)
{
	FILE* pFile;

	eMovie* auxMov;

	char path[50];
	char generoIngresado[50];

	int option;

	printf("Ingrese por que genero desea filtrar\n");
	printf("1.Adventure\n");
	printf("2.Comedy\n");
	printf("3.Drama\n");
	printf("4.Romance\n");
	printf("5.Documentary\n");
	printf("6.Horror\n");
	printf("7.Musical\n");
	printf("8.Animation\n");
	printf("9.Thriller\n");
	printf("10.Western\n");
	option = input_GetInt("Opcion:");

	switch(option)
	{
	case 1:
		strcpy(path,"Adventure.csv");
		strcpy(generoIngresado,"Adventure");
		break;
	case 2:
		strcpy(path,"Comedy.csv");
		strcpy(generoIngresado,"Comedy");
		break;
	case 3:
		strcpy(path,"Drama.csv");
		strcpy(generoIngresado,"Drama");
		break;
	case 4:
		strcpy(path,"Romance.csv");
		strcpy(generoIngresado,"Romance");
		break;
	case 5:
		strcpy(path,"Documentary.csv");
		strcpy(generoIngresado,"Documentary");
		break;
	case 6:
		strcpy(path,"Horror.csv");
		strcpy(generoIngresado,"Horror");
		break;
	case 7:
		strcpy(path,"Musical.csv");
		strcpy(generoIngresado,"Musical");
		break;
	case 8:
		strcpy(path,"Animation.csv");
		strcpy(generoIngresado,"Animation");
		break;
	case 9:
		strcpy(path,"Thriller.csv");
		strcpy(generoIngresado,"Thriller");
		break;
	case 10:
		strcpy(path,"Western.csv");
		strcpy(generoIngresado,"Western");
		break;
	}

	char titulo[50];
	char genero[50];
	int id;
	int duracion;

	if(arrayMovies != NULL)
	{
		pFile = fopen(path,"w");

		for(int i = 0; i<ll_len(arrayMovies);i++)
		{
			auxMov = (eMovie*)ll_get(arrayMovies, i);
			if(filtrarGenero(auxMov,generoIngresado) == 1)
			{
				movie_getId(auxMov, &id);
				movie_getTitulo(auxMov, titulo);
				movie_getGenero(auxMov, genero);
				movie_getDuracion(auxMov, &duracion);

				fprintf(pFile,"%d,%s,%s,%d\n",id,titulo,genero,duracion);
			}
		}

		fclose(pFile);
	}

	return 1;
}

int controller_ordenarPorDuracion(void* aux1, void* aux2)
{
	int respuesta;
	respuesta = 0;

	if(aux1 != NULL && aux2 != NULL)
	{
		eMovie* mov1 = (eMovie*) aux1;
		eMovie* mov2 = (eMovie*) aux2;
		if(mov1->duracion > mov2->duracion)
		{
			respuesta = 1;
		}
		else
		{
			respuesta = -1;
		}
	};

	return respuesta;
}

int controller_ordenarPorGenero(void* aux1, void* aux2)
{
	int respuesta;
	respuesta = 0;

	if(aux1 != NULL && aux2 != NULL)
	{
		eMovie* mov1 = (eMovie*) aux1;
		eMovie* mov2 = (eMovie*) aux2;
		if(strcmp(mov1->genero,mov2->genero) == -1)
		{
			respuesta = 1;
		}
		else
		{
			respuesta = -1;
		};
	};

	return respuesta;
}

void controller_guardar(LinkedList* arrayMovies)
{
	FILE* pFile;

	eMovie* auxMov;

	char titulo[50];
	char genero[50];
	int id;
	int duracion;

	if(arrayMovies != NULL)
	{
		pFile = fopen("guardados.csv","w");
		ll_sort(arrayMovies, &controller_ordenarPorDuracion, 1);
		ll_sort(arrayMovies, &controller_ordenarPorGenero, 0);
		for(int i = 0; i<ll_len(arrayMovies);i++)
		{
			auxMov = (eMovie*)ll_get(arrayMovies, i);

			movie_getId(auxMov, &id);
			movie_getTitulo(auxMov, titulo);
			movie_getGenero(auxMov, genero);
			movie_getDuracion(auxMov, &duracion);

			fprintf(pFile,"%d,%s,%s,%d\n",id,titulo,genero,duracion);
		}

		fclose(pFile);
	}
}
