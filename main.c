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
	Inicializar(&lista);
	DeTxtALista(&lista, archivo);
	int op;
	Arreglo a;
	do{
		MenuPrincipal();
		scanf("%d",&op);
		switch(op){
			case 1: {
				system("@cls||clear");
				MasPopulares(a);
				break;
			};
			case 2: {
				system("@cls||clear");
				DeListaAArreglo(&lista,arrPelis);
				break;
			}
			case 3: {
				system("@cls||clear");
				MostrarLista(lista);
				break;
			}
			case 4: {
				system("@cls||clear");
				break;
			}
			case 5: {
				system("@cls||clear");
				break;
			}
			case 6: {
				system("@cls||clear");
				break;
			}
			case 7: {
				system("@cls||clear");
				CartelSalir();
				break;
			}
			default: {
				system("@cls||clear");
				printf("Ingrese un valor entre 1 y 7.\n");
			}	

		}
	}while(op != 7);
}

//Muestra por pantalla el menu principal
void MenuPrincipal(){
	printf("\n");
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
	printf("\n");
	printf("|-------------------------------------|\n");
	printf("|  Gracias por utilizar Movie House!  |\n");
	printf("|-------------------------------------|\n");
}
