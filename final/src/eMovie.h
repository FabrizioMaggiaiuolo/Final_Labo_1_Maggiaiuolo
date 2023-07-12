/*
 * mov.h
 *
 *  Created on: 11 Jul 2023
 *      Author: fa_mg
 */

#ifndef EMOVIE_H_
#define EMOVIE_H_

typedef struct
{
	int id_peli;
	char titulo[50];
	char genero[50];
	int duracion;
}eMovie;

eMovie* newMovie();
eMovie* newMovieParametros(char*,char*,char*,char*);
void imprimirUno(eMovie*);
int movie_setDuracion(eMovie*,int);
int movie_setId(eMovie*,int);
int movie_setTitulo(eMovie*, char*);
int movie_setGenero(eMovie*, char*);

int movie_getDuracion(eMovie*,int*);
int movie_getId(eMovie*,int*);
int movie_getTitulo(eMovie*, char*);
int movie_getGenero(eMovie*, char*);

#endif /* EMOVIE_H_ */
