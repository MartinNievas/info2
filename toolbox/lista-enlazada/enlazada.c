#include "enlazada.h"
#include <stdio.h>
#include <stdlib.h>
int menu(void){
	int choice;
	printf("1. Insertar nodo\n");
	printf("2. Eliminar nodo\n");
	printf("3. Salir\n");
	printf("Ingrese su eleccion: ");
	scanf("%d", &choice);
	return choice;
}
void insert(ptrNodo * ptrInicio, char valor){
	ptrNodo ptrNuevo = malloc(sizeof(Nodo));
	ptrNodo ptrAnterior, ptrActual;

	if(ptrNuevo != NULL){	/*Espacio disponible*/
		ptrNuevo -> dato = valor;
		ptrNuevo -> ptrSig = NULL;
		
		ptrAnterior = NULL;
		ptrActual = *ptrInicio;

		while(ptrActual != NULL && valor > ptrActual -> dato){
			ptrAnterior = ptrActual;
	 		ptrActual = ptrAnterior -> ptrSig;
		}

		if(ptrAnterior == NULL){
			ptrNuevo -> ptrSig = *ptrInicio;
			*ptrInicio = ptrNuevo;
		}
		
		else {
			ptrAnterior -> ptrSig = ptrNuevo;
			ptrNuevo -> ptrSig = ptrActual;		
		}
	} /*Fin Check Espacio Disponible*/
	else {
		printf("No se ha insertado el nodo %c por falta de memoria.\n", valor);
	}
}

void printList(ptrNodo ptrActual){
		if (isEmpty(ptrActual)) 
			printf("La Lista esta Vacia\n");
		else{
			while(ptrActual != NULL){
				printf("%c ---> ", ptrActual -> dato);
				ptrActual = ptrActual -> ptrSig;
			}
			printf("NULL\n");
		}
}

char delete(ptrNodo *ptrInicio, char valor){
	ptrNodo ptrAnterior, ptrActual;
	
	if (valor == (*ptrInicio)->dato) {
		*ptrInicio =(*ptrInicio)->ptrSig;
		return valor;
	}
	else {
		ptrAnterior = *ptrInicio;
		ptrActual = (*ptrInicio)->ptrSig;

		while(ptrActual != NULL && ptrActual->dato != valor){
			ptrAnterior = ptrActual;
			ptrActual = ptrAnterior->ptrSig;
		}

		if(ptrActual != NULL){
			ptrAnterior->ptrSig = ptrActual -> ptrSig;
			free(ptrActual);
			return valor;
		}
	}
	return '\0';
}
	
int isEmpty(ptrNodo ptrInicio){
	return ptrInicio == NULL;
}
