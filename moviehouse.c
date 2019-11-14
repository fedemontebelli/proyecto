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

//AcciÃ³n que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a){
	printf("Proximamente tendremos esta funcionalidad :)\n");
}

void Inicializar(Lista *l){
	l=malloc(sizeof(struct Nodo));
}

void Insertar(Lista *l, Movie a){
	Lista *aux=malloc(sizeof(struct Nodo));
	aux->head->pelicula=a;
	aux->head->next=l->head->next;
	l->head->next=aux->head;
}

void DeTxtALista(Lista *l, FILE *f){
	archivo=fopen("C:\\Users\\Fede\\Desktop\\Proyecto Final","r");
	if(archivo == NULL ) {
    printf("No fue posible abrir el archivo\n");
   }




  fclose(archivo);
}


void MostrarLista(Lista l){

}
