/************************************************************************************************
*    Programa: Guia de ejercicios LAB 04                                                           *
*    Objetivo:                                                                                  *
*    Autor/Grupo: Cristian Rojas Saavedra                                                       *
*    Asignatura: Estructura de datos     Sección: 652                                           *
*************************************************************************************************/ 


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printbin(int n){
	int count = pow(2,15);
	for (count;count >0;count >>=1){
		if (count&n){
			printf ("1");
		}else{
			printf ("0");
		}
	}
}

int insertBit(int x,int i){
	printf ("\n****Ingrese un numero -> %i",i);
	printf ("\n");
	if (((x>>i)%2)==0){
		x+=1<<i;
		printf ("Ingresado\n");
		return x;
	}
	else{
		printf ("****Ya existe****\n");
		return x;
	}
}

int elimBit(int x,int i){
	printf ("\n****Ingrese un numero -> %i",i);
	printf ("\n");
	if (((x>>i)%2)==1){
		x-=1<<i;
		printf ("Eliminado\n");
		return x;
	}
	else{
		printf ("****No existe****\n");
		return x;
	}
}

int main (){
	
	int a,b;
	//Inserto los valores a los conjuntos.
	a= (1<<4)+(1<<5)+(1<<2)+(1<<8)+(1<<7);
	b= (1<<0)+(1<<1)+(1<<3)+(1<<4)+(1<<5);

	//Recorro A.
	printf("Conjunto   A: ");
	printbin(a);
	printf("\n");
	//Recorro A.
	printf("Conjunto   B: ");
	printbin(b);
	printf("\n");
	//Union A y B.
	printf("Conjunto AUB: ");
	printbin(a|b);	
	printf("\n");
	
	//Intersección A y B.
	printf("Conjunto AnB: ");
	printbin(a&b);
	printf("\n");
	printf("\n");
	
	
	printf("Conjunto (A-B)U (A+B): ");
	printbin((a&(~b))|(a&b));
	printf("\n");
	
	//Inserto un nuevo numero al conjunto A.
	a=insertBit(a,1);
	a=insertBit(a,2);
	printf("\n");
	
	//Inserto un nuevo numero al conjunto B.
	b=insertBit(b,5);
	//b=elimBit(b,4);
	//printbin(b);
	b=insertBit(b,4);printbin(b);	
	printf("\n");
	
	//Nueva Union A y B.
	printf("Nuevo Conjunto AnB: ");
	printbin(a&b);
	printf("\n");
	
	return 0;
}

