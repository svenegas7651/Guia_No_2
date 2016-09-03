#include <stdio.h>
#include <stdlib.h>

#define TAMANODECOLA 5
int cola[TAMANODECOLA], f=-1, r=-1;


int lleno() {
	if(r == TAMANODECOLA - 1) {
		return 1;
	}
	return 0;
}


int vacio() {
	if(f > r) {
		return 1;
	}
	return 0;
}


int mostrarcola() {
	int i;
	if(vacio()) {
		printf(" \n La cola esta vacia\n");
	} else {
		printf("Inicio->");
		for(i=f; i<=r; i++) {
			printf("%d ", cola[i]);
		}
		printf("<-Fin");
	}
	return 0;
}


int encolar(int unelemento) {
	if( lleno()) { 
		printf("\n\n Overflow!!!!\n\n");
	} else {
		++r;
		cola[r] = unelemento;
	}
	return 0;
}


int desencolar() {
	int elem;
	if(vacio()) {
		printf(" \n La cola est vacia\n");
		return(-1);
	} else {
		elem=cola[f];
		f=f+1;
		return(elem);
	}
}

int main() {
 	int opcion, element; 
 	char    ch;

 	do {
 	printf("\n Elige 1-Encolar, 2-Desencolar, 3-Mostrar, 4-Salir\n");
 	printf("\n Su seleccion? ");
 	scanf("%d",&opcion);
 	switch(opcion) {
 		case 1:
 			printf("\n\nCotenido que tiene que ser insertado?");
 			scanf("%d",&element);
			encolar(element);
 			break;
 		case 2:
			element=desencolar();
			if( element != -1 ) {
				printf("\n\nElemento eliminado (con su contenido %d) \n",element); 
			}				
			break;
		case 3:
			printf("\n\nEstatus de la cola\n\n");
			mostrarcola();
			break;
		case 4:
			printf("\n\n Fin del programa \n\n");
			break; 
		default:
			printf("\n\nOpcion invalida, intentelo de nuevo! \n\n");
			break;
		}
    } while(opcion != 4);
    return 0; 
}
