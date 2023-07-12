/*
 * mov.c
 *
 *  Created on: 11 Jul 2023
 *      Author: fa_mg
 */

#include "eMovie.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

eMovie* newMovie()
{
	return (eMovie*) malloc(sizeof(eMovie));
}

eMovie* newMovieParametros(char* id,char* titulo,char* genero,char* duracion)
{
	eMovie* aux = newMovie();

	aux->id_peli = atoi(id);
	aux->duracion = atoi(duracion);
	strcpy(aux->genero,genero);
	strcpy(aux->titulo,titulo);

	return aux;
}

void imprimirUno(eMovie* aux)
{
	printf("%4d %30s %15s %4d\n",aux->id_peli,aux->titulo,aux->genero,aux->duracion);
}

int movie_getId(eMovie* mov, int* id)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		*id = mov->id_peli;
		resultado = 1;
	}

	return resultado;
}

int movie_setId(eMovie* mov, int id)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		mov->id_peli = id;
		resultado = 1;
	}

	return resultado;
}

int movie_getDuracion(eMovie* mov, int* duracion)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		*duracion = mov->duracion;
		resultado = 1;
	}

	return resultado;
}

int movie_setDuracion(eMovie* mov, int duracion)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		mov->duracion = duracion;
		resultado = 1;
	}

	return resultado;
}

int movie_getTitulo(eMovie* mov, char* titulo)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		strcpy(titulo,mov->titulo);
		resultado = 1;
	}

	return resultado;
}

int movie_setTitulo(eMovie* mov, char* titulo)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		strcpy(mov->titulo,titulo);
		resultado = 1;
	}

	return resultado;
}

int movie_getGenero(eMovie* mov, char* genero)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		strcpy(genero,mov->genero);
		resultado = 1;
	}

	return resultado;
}

int movie_setGenero(eMovie* mov, char* genero)
{
	int resultado;
	resultado = 0;

	if(mov != NULL)
	{
		strcpy(mov->genero,genero);
		resultado = 1;
	}

	return resultado;
}
