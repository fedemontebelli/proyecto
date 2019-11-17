// Copyright (C) 2019 <nombre y apellido del autor> <e-mail del autor>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include "moviehouse.h"
#include "moviehouse.c"


//Muestra por pantalla el menu principal
void MenuPrincipal();

//Muestra un mensaje al salir del programa
void CartelSalir();

	
	int a;

//Programa Principal
int main(){
	int op;
	Arreglo a;
	do{
		MenuPrincipal();
		scanf("%d",&op);
		switch(op){
			case 1: {
				MasPopulares(a);
				break;
			};
			case 2: {
				Inicializar(lista);
				DeTxtALista(lista, archivo);
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				break;
			}
			case 7: {
				CartelSalir();
				break;
			}
			default: {
				printf("Ingrese un valor entre 1 y 7.\n");
			}	

		}
	}while(op != 7);
}


//Muestra por pantalla el menu principal
void MenuPrincipal(){
	printf("|-------------------|\n");
	printf("|    Movie House    |\n");
	printf("| Elige una opcion: |\n");
	printf("|-------------------|\n\n");
	printf("1: Peliculas mas populares\n");
	printf("2: \n");
	printf("3: \n");
	printf("4: \n");
	printf("5: \n");
	printf("6: \n");
	printf("7: salir\n");
}

//Muestra un mensaje al salir del programa
void CartelSalir(){
	printf("---------------------------------------|\n");
	printf("|  ¡Gracias por utilizar Movie House!  |\n");
	printf("---------------------------------------|\n");
}
