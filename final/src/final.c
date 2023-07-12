/*
 ============================================================================
 Name        : final.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "eMovie.h"
#include "inputs.h"
#include "controller.h"

int main(void) {
	srand (time(NULL));
	setbuf(stdout,NULL);

	LinkedList* arrayMovies = ll_newLinkedList();

	int option,cargasFlag;
	option = 0;
	cargasFlag = 0;

	do{
		printf("\n-----Menu-----\n");
		printf("1. Cargar archivo\n");
		printf("2. Imprimir lista\n");
		printf("3. Asignar tiempos\n");
		printf("4. Filtrar por tipo\n");
		printf("5. Mostrar duraciones\n");
		printf("6. Guardar peliculas\n");
		printf("7. Salir\n");

		option = input_GetInt("Ingres la opcion deseada:");

		if(option < 1 || option > 7)
		{
			printf("ERROR// seleccione alguna opcion valida\n");
		}
		else
		{
			if(option != 1 && option != 7 && cargasFlag ==0)
			{
				printf("//ERROR// debe cargar algun dato antes de ingresar otra opcion\n");
			}
			else
			{
				switch(option)
				{
				case 1:
					controller_cargarArchivoTexto("movies.csv",arrayMovies);
					cargasFlag = 1;
					break;
				case 2:
					imprimirLista(arrayMovies);
					break;
				case 3:
					ll_map(arrayMovies, &asignarTiempo);
					imprimirLista(arrayMovies);
					break;
				case 4:
					controller_FiltrarGenero(arrayMovies);
					break;
				case 5:
					ll_sort(arrayMovies, &controller_ordenarPorDuracion, 1);
					ll_sort(arrayMovies, &controller_ordenarPorGenero, 0);
					imprimirLista(arrayMovies);
					break;
				case 6:
					controller_guardar(arrayMovies);
					break;
				case 7:
					printf("Gracias por usar nuestro programa");
				}
			}
		}

	} while(option != 7);



	return 0;
}
