////La memoria estatica
//int notas[5];
//
////La memoria dinamica
//int cantidad;
//
////direccion de memoria o mas conocida como los punteros
//int* ptr_notas = notas;
//
////memoria por reserva, o memoria dinamica reservada
//malloc(cantidadBytes);
//
//
//int* edades;
//
//edades = (int*)malloc(100 * sizeof(int)); // Reservar memoria para 100 enteros
////??
////? ?
////? ?
////? ?
////? ?
//
//mezclarlo con arreglos
//
//free(edades);
//
//
//edades = (int*)calloc(100 * sizeof(int)); // Reservar memoria para 100 enteros
////0
////0
////0
////0

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cantidad = 5;

	//Para la reserva de memoria dinamica, se utiliza malloc o calloc
	int* edades = (int*)malloc(cantidad * sizeof(int)); // Reservar memoria para 5 enteros
	int* edadescalloc = (int*)calloc(cantidad, sizeof(int)); // Reservar memoria para 5 enteros

	edades[0] = 20;		
	/*edades[1] = 40;*/
	edades[2] = 25;
	edades[3] = 35;
	edades[4] = 18;


	for (int i = 0; i < cantidad; i++) {
		printf("Edad %d: %d\n", i + 1, edades[i]);
		printf("Edad Calloc %d: %d\n", i + 1, edadescalloc[i]);
	}
	
	free(edades); // Liberar la memoria reservada

	return 0;
}

