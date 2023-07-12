/*
 * parser.h
 *
 *  Created on: 12 jul 2023
 *      Author: alumno
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_cargarArchivoTexto(char*, LinkedList*);
void imprimirLista(LinkedList*);

void asignarTiempo(void*);

int filtrarGenero(eMovie*,char*);
int controller_FiltrarGenero(LinkedList*);

int controller_ordenarPorDuracion(void*,void*);
int controller_ordenarPorGenero(void*, void*);

void controller_guardar(LinkedList*);
#endif /* CONTROLLER_H_ */
