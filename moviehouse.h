#ifndef MOVIEHOUSE_H
#define MOVIEHOUSE_H
#include <stdio.h>
#define SIZE 200

//Registro con informacion de una pelicula
typedef enum gen{Action,Comedy,Adventure,Drama,Horror,SciFi,
	Fantasy,Animation}generos;
enum colores{Color, BW};
typedef struct{
	int id;
	char titulo[56];
	char director[34];
	generos genero;
	int likes;
	int cantidad_votantes;
	float voto_promedio;
	int anio;
	int costo;
	enum colores color;
}Movie;

//LSE de Movie
struct Nodo{
	Movie pelicula;
	struct Nodo *next; 
};

//Puntero al primer elemento de la LSE
typedef struct{
	struct Nodo *head;
}Lista;

//Arreglo de peliculas con cantidad
typedef struct{
	 Movie peliculas[SIZE];
	 int cant;
}Arreglo;

FILE *archivo;
Lista *lista;
Arreglo arrPelis;
/**
	Operaciones sobre lista
**/

//Inicializa la lista
void Inicializar(Lista **l);

//Inserta un nodo al comienzo de la lista
void Insertar(Lista **l, Movie a);

//Muestra toda la lista
void MostrarLista(Lista *l);

/**
	Funcionalidades del proyecto
**/

void DeListaAArreglo(Lista **l,Arreglo arr);


//Dado un archivo de texto con la informacion de las peliculas, 
//guarda en la lista todas las pelicuas usando el registro Movie
void DeTxtALista(Lista **l, FILE *f);

//Accion que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a);

#endif
