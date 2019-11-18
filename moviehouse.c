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

// #define new_max(a,b) \  ({ typeof (a) _a = (a); \ typeof (b) _b = (b); \ _a > _b ? _a : _b; })

//AcciÃ³n que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a){
	printf("Proximamente tendremos esta funcionalidad :)\n");
}

void Inicializar(Lista **l){
	//printf("ini1\n");
	(*l)=malloc(sizeof(Lista));
	(*l)->head=NULL;
	//printf("ini2\n");
}

void Insertar(Lista **l, Movie a){
	struct Nodo *aux=malloc(sizeof(struct Nodo));
	aux->pelicula=a;
	//printf("insertar1\n");
	if ((*l)->head==NULL){
		//printf("insertar2\n");
		(*l)->head=aux;
		aux->next=NULL;
		printf("lista vacia\n");
	}else{
		//printf("insertar3\n");
		aux->next=(*l)->head;
		(*l)->head=aux;
	}
}

void DeTxtALista(Lista **l, FILE *f){
	//int maxLengthid=0,maxLengthtitulo=0,maxLengthdirector=0,maxLengthlikes=0,maxLengthctdvot=0,maxLengthvoto=0,maxLengthanio=0,maxLengthcosto=0;
	char auxGenero[15];
	char auxColor[10];
	char auxID[8];
	char auxLikes[8];
	char auxCantidad_votantes[7];
	char auxVoto_promedio[5] ;
	char auxAnio[6];
	char auxCosto[11];
	Movie aux;
	f=fopen("peliculas.txt","r");
	if(f == NULL ) {
    printf("No fue posible abrir el archivo\n");
   }
   //printf("cargando pelicula\n");
while (!feof(f)){
	//printf("cargando 2\n");
	fgets(auxID, sizeof(auxID), f);
	aux.id=atoi(auxID);
	fgets(aux.titulo,(sizeof(aux.titulo)), f);
	fgets(aux.director,(sizeof(aux.director)), f);

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
					}else if (strcmp(auxGenero, "Sci-Fi") == 0){
						aux.genero=SciFi;
						}else if (strcmp(auxGenero, "Fantasy") == 0){
								aux.genero=Fantasy;
							}else if (strcmp(auxGenero, "Animation") == 0){
									aux.genero=Animation;
								}

	fgets(auxLikes, sizeof(auxLikes), f);
	aux.likes=atoi(auxLikes);
	fgets(auxCantidad_votantes, sizeof(auxCantidad_votantes), f);
	aux.cantidad_votantes=atoi(auxCantidad_votantes);
	fgets(auxVoto_promedio, sizeof(auxVoto_promedio), f);
	aux.voto_promedio=atof(auxVoto_promedio);
	fgets(auxAnio, sizeof(auxAnio), f);
	aux.anio=atoi(auxAnio);
	fgets(auxCosto, sizeof(auxCosto), f);
	aux.costo=atoi(auxCosto);

	fgets(auxColor,(sizeof(auxColor)), f);
	if (strcmp(auxColor, "Color") == 0){
			aux.color=Color;
	}else if (strcmp(auxColor, "BW") == 0){
				aux.color=BW;
		}


	//printf("txt1\n")
/*
	maxLengthid=new_max(maxLengthid,strlen(aux.id));
	maxLengthtitulo=new_max(maxLengthtitulo,strlen(aux.titulo));
	maxLengthdirector=new_max(maxLengthdirector,strlen(aux.director));
	maxLengthlikes=new_max(maxLengthlikes,strlen(aux.likes));
	maxLengthctdvot=new_max(maxLengthctdvot,strlen(aux.cantidad_votantes));
	maxLengthvoto=new_max(maxLengthvoto,strlen(aux.voto_promedio));
	maxLengthanio=new_max(maxLengthanio,strlen(aux.anio));
	maxLengthcosto=new_max(maxLengthcosto,strlen(aux.costo));
*/
	Insertar(l, aux);
}
  fclose(f);
//  printf("%i %i %i %i %i %i %i %i\n", maxLengthid,maxLengthtitulo,maxLengthdirector,maxLengthlikes,maxLengthctdvot,maxLengthvoto,maxLengthanio,maxLengthcosto );
}

static char* obtenerGenero(enum generos g) 
{
   switch (g) 
   {
		case Action: return "Action"; break;
		case Comedy: return "Comedy"; break;
		case Adventure: return "Adventure"; break;
		case Drama: return "Drama"; break;
		case Horror: return "Horror"; break;
		case SciFi: return "SciFi"; break;
		case Fantasy: return "Fantasy"; break;
		case Animation: return "Animation"; break;
		default: printf("%i\n",g ); return "Defaul"; break;
   }
}

void MostrarLista(Lista *l){
	struct Nodo *aux;
	aux=l->head;
	while(aux!=NULL){
		printf("\n");
		printf("%i\n",aux->pelicula.id);
		printf("%s",aux->pelicula.titulo);
		printf("%s",aux->pelicula.director);
		printf("%s\n",obtenerGenero(aux->pelicula.genero));
		printf("%i\n",aux->pelicula.likes);
		printf("%i\n",aux->pelicula.cantidad_votantes);
		printf("%0.1f\n",aux->pelicula.voto_promedio);
		printf("%i\n",aux->pelicula.anio);
		printf("%i\n",aux->pelicula.costo);
		printf("%d\n",aux->pelicula.color);
		printf("\n");
		printf("------------------------\n");
		printf("\n");
		aux=aux->next;
	}
}
