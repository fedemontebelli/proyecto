// Copyright (C) 2019 <nombre y apellido del autor> <e-mail del autor>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include "moviehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//AcciÃ³n que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a){
	printf("Proximamente tendremos esta funcionalidad :)\n");
}

void Inicializar(Lista *l){
	l=NULL;
}

void Insertar(Lista *l, Movie a){
	struct Nodo *aux=malloc(sizeof(struct Nodo));
	aux->pelicula=a;
	aux->next=l->head->next;
	l->head->next=aux;
}

void DeTxtALista(Lista *l, FILE *f){
	char auxGenero[15];
	char auxColor[10];
	Movie aux;
	f=fopen("peliculas.txt","r");
	if(f == NULL ) {
    printf("No fue posible abrir el archivo\n");
   }

	fgets(aux.id, sizeof(aux.id), f); 
	fgets(aux.titulo, sizeof(aux.titulo), f);
	fgets(aux.director, sizeof(aux.director), f);
	fgets(auxGenero,(sizeof(auxGenero)), f);
	if (strcmp(auxGenero, "Action") == 0){
			aux.genero=Action;
	}else if (strcmp(auxGenero, "Comedy") == 0){
				aux.genero=Comedy;
		}else if (strcmp(auxGenero, "Adventure") == 0){
				aux.genero=Adventure;
			}else if (strcmp(auxGenero, "Drama") == 0){
					aux.genero=Drama;
				}else if (strcmp(auxGenero, "Horror") == 0){
					aux.genero=Horror;
					}else if (strcmp(auxGenero, "SciFi") == 0){
						aux.genero=SciFi;
						}else if (strcmp(auxGenero, "Fantasy") == 0){
								aux.genero=Fantasy;
							}else if (strcmp(auxGenero, "Animation") == 0){
									aux.genero=Animation;
								}
	fgets(aux.likes,(sizeof(aux.likes)), f);
	fgets(aux.cantidad_votantes,(sizeof(aux.cantidad_votantes)), f);
	fgets(aux.voto_promedio,(sizeof(aux.voto_promedio)), f);
	fgets(aux.anio,(sizeof(aux.anio)), f);
	fgets(aux.costo,(sizeof(aux.costo)), f);
	fgets(auxColor,(sizeof(auxColor)), f);
	if (strcmp(auxColor, "Color") == 0){
			aux.color=Color;
	}else if (strcmp(auxColor, "BW") == 0){
				aux.color=BW;
		}
	Insertar(l, aux);


  fclose(f);
}


void MostrarLista(Lista l){

}
