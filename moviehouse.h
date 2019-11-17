// Copyright (C) 2019 <nombre y apellido del autor> <e-mail del autor>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#ifndef MOVIEHOUSE_H
#define MOVIEHOUSE_H

#include <stdio.h>

#define SIZE 100

//Registro con informaciÃ³n de una pelicula
// COMPLETAR CON LOS CAMPOS NECESARIOS
enum generos {Action, Comedy, Adventure, Drama, Horror, SciFi, Fantasy, Animation};
typedef enum {Color, BW}Tcolor;
typedef struct{
	char id[15];
	char titulo[100];
	char director[35];
	enum generos genero;
	char likes[10];
	char cantidad_votantes[10];
	char voto_promedio[5];
	char anio[4];
	char costo[15];
	Tcolor color;
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

/**
	Operaciones sobre lista
**/

//Inicializa la lista
void Inicializar(Lista *l);

//Inserta un nodo al comienzo de la lista
void Insertar(Lista *l, Movie a);

//Muestra toda la lista
void MostrarLista(Lista l);

/**
	Funcionalidades del proyecto
**/

//Dado un archivo de texto con la informaciÃ³n de las peliculas, 
//guarda en la lista todas las pelicuas usando el registro Movie
void DeTxtALista(Lista *l, FILE *f);

//AcciÃ³n que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a);

#endif
