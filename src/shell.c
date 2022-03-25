#include "shell.h"


void Initialize(Vector *v){
	
	//Porque 42? Leia o guia definitivo do mochileiro das galáxias :).
	srand(42); 
    
    v->itens = (int*)malloc(MAXSIZE*sizeof(int));
	for(int i=0; i<MAXSIZE; i++)
		v->itens[i] = rand()%100;
	v->swap = 0;
}

void Imprime(Vector *v){
	for(int i=0; i<MAXSIZE; i++)
		printf("%d\t", v->itens[i]);
	printf("\n");
}


void ShellSort(Vector *v){
	int h = 1;
	int aux, j;

	do{
		h = 3 * h + 1;
	}while(h < MAXSIZE);

	do{
		h = h/3;
		//se considerar vetor de 1 a n o i deve começar com i=h+1
		for(int i=h; i<MAXSIZE; i++){
			aux = v->itens[i];
			j = i;
			while(v->itens[j-h] > aux){
				v->itens[j] = v->itens[j - h];
				v->swap ++;
				j = j - h;
				if(j<=h || j <= 0)
					break;
				
			}
			v->itens[j] = aux;
			Imprime(v);
		}

	}while(h != 1);
}