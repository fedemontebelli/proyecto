#include "moviehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Accion que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a){
	printf("Proximamente tendremos esta funcionalidad :)\n");
}

void Inicializar(Lista **l){
	(*l)=malloc(sizeof(Lista));
	(*l)->head=NULL;
}

void Insertar(Lista **l, Movie a){
	struct Nodo *aux=malloc(sizeof(struct Nodo));
	aux->pelicula=a;
	if ((*l)->head==NULL){
		(*l)->head=aux;
		aux->next=NULL;
	}else{
		aux->next=(*l)->head;
		(*l)->head=aux;
	}
}

void DeTxtALista(Lista **l, FILE *f){
	char auxGenero[15];
	char auxColor[10];
	char auxID[8];
	char auxLikes[8];
	char auxCantidad_votantes[7];
	char auxVoto_promedio[5];
	char auxAnio[6];
	char auxCosto[11];
	Movie aux;
	f=fopen("peliculas.txt","r");
	if(f == NULL ) {
    printf("No fue posible abrir el archivo\n");
   }
while (!feof(f)){
	fgets(auxID,8, f);
	aux.id=atoi(auxID);
	fgets(aux.titulo,56, f);
	strtok(aux.titulo, "\n");
	fgets(aux.director,34, f);
	strtok(aux.director, "\n");
	fgets(auxGenero,100, f);
	if (strncmp("Action",auxGenero,strlen("Action"))==0){
			aux.genero=Action;
	}else if (strncmp("Comedy",auxGenero,strlen("Comedy"))==0){
				aux.genero=Comedy;
		}else if (strncmp("Adventure",auxGenero,strlen("Adventure"))==0){
				aux.genero=Adventure;
			}else if (strncmp("Drama",auxGenero,strlen("Drama"))==0){
					aux.genero=Drama;
				}else if (strncmp("Horror",auxGenero,strlen("Horror"))==0){
					aux.genero=Horror;
					}else if (strncmp("Sci-Fi",auxGenero,strlen("Sci-Fi"))==0){
						aux.genero=SciFi;
						}else if (strncmp("Fantasy",auxGenero,strlen("Fantasy"))==0){
								aux.genero=Fantasy;
							}else if (strncmp("Animation",auxGenero,strlen("Animation"))==0){
									aux.genero=Animation;
								}else{
									printf("--\n");
								}
	fgets(auxLikes,8, f);
	aux.likes=atoi(auxLikes);
	fgets(auxCantidad_votantes,7, f);
	aux.cantidad_votantes=atoi(auxCantidad_votantes);
	fgets(auxVoto_promedio,5, f);
	aux.voto_promedio=atof(auxVoto_promedio);
	fgets(auxAnio,6, f);
	aux.anio=atoi(auxAnio);
	fgets(auxCosto,11, f);
	aux.costo=atoi(auxCosto);

	fgets(auxColor,10, f);
	if (strncmp("Color",auxColor,strlen("Color"))==0){
			aux.color=Color;
	}else if (strncmp("BW",auxColor,strlen("BW"))==0){
				aux.color=BW;
		}

	Insertar(l, aux);
}
  fclose(f);
}

static char* obtenerGenero(generos g) 
{
   switch (g) 
   {
		case Action: return "Action"; 
		break;
		case Comedy: return "Comedy"; 
		break;
		case Adventure: return "Adventure"; 
		break;
		case Drama: return "Drama"; 
		break;
		case Horror: return "Horror"; 
		break;
		case SciFi: return "SciFi"; 
		break;
		case Fantasy: return "Fantasy"; 
		break;
		case Animation: return "Animation"; 
		break;
		default: printf("%i\n",g ); return "Defaul"; 
		break;
   }
}

void MostrarLista(Lista *l){
	struct Nodo *aux;
	aux=l->head;
	int i=1;
	while(aux!=NULL){
		printf("%i\n",i);
		printf("\n");
		printf("%i\n",aux->pelicula.id);
		printf("%s\n",aux->pelicula.titulo);
		printf("%s\n",aux->pelicula.director);
		printf("%s\n",obtenerGenero(aux->pelicula.genero));
		printf("%i\n",aux->pelicula.likes);
		printf("%i\n",aux->pelicula.cantidad_votantes);
		printf("%0.1f\n",aux->pelicula.voto_promedio);
		printf("%i\n",aux->pelicula.anio);
		printf("%i\n",aux->pelicula.costo);
		if (aux->pelicula.color==0){
			printf("Color\n");
		}else{
			printf("BW\n");
		}
		printf("\n");
		printf("------------------------\n");
		aux=aux->next;
		i++;
	}
}

void DeListaAArreglo(Lista **l,Arreglo arr){
	struct Nodo *aux=malloc(sizeof(struct Nodo));
	aux=(*l)->head;
	for (int i=1;i<=SIZE;i++){
		arr.peliculas[i].id=aux->pelicula.id;
		strcpy(arr.peliculas[i].titulo,aux->pelicula.titulo);
		strcpy(arr.peliculas[i].director,aux->pelicula.director);
		arr.peliculas[i].genero=aux->pelicula.genero;
		arr.peliculas[i].likes=aux->pelicula.likes;
		arr.peliculas[i].cantidad_votantes=aux->pelicula.cantidad_votantes;
		arr.peliculas[i].voto_promedio=aux->pelicula.voto_promedio;
		arr.peliculas[i].anio=aux->pelicula.anio;
		arr.peliculas[i].costo=aux->pelicula.costo;
		arr.peliculas[i].color=aux->pelicula.color;
		aux=aux->next;

/*
		MOSTRAR ARREGLO
*/
		// printf("%i\n",i);
		// printf("\n");
		// printf("%i\n",arr.peliculas[i].id);
		// printf("%s\n",arr.peliculas[i].titulo);
		// printf("%s\n",arr.peliculas[i].director);
		// printf("%s\n",obtenerGenero(arr.peliculas[i].genero));
		// printf("%i\n",arr.peliculas[i].likes);
		// printf("%i\n",arr.peliculas[i].cantidad_votantes);
		// printf("%0.1f\n",arr.peliculas[i].voto_promedio);
		// printf("%i\n",arr.peliculas[i].anio);
		// printf("%i\n",arr.peliculas[i].costo);
		// if (arr.peliculas[i].color==0){
		// 	printf("Color\n");
		// }else{
		// 	printf("BW\n");
		// }
		// printf("\n");
		// printf("------------------------\n");
	}
}
