#include <stdio.h>
#include <stdlib.h>
int *listaX(int n){
	int *vetorX,i;//
	for(i=0;i<n;i++){
		printf("Digite %d valor:",i+1);
		scanf("%d",&vetorX[i]);
	}printf("\nVertorX:");
	for(i=0;i<n;i++){
		printf("%d,",vetorX[i]);
	}
	return vetorX;
}
void listaY(int *vetorX,int n){
	int *vetorY,i,aux=0;
	vetorY = (int*) malloc(n * sizeof(int));
	for(i=0;i<n;i++){
		if(vetorX[i]>10 && vetorX[i]<40){
			vetorY[aux] = vetorX[i];
			aux += 1;
		}
	}printf("\nVetorY:");
	for(i=0;i<aux;i++){
		printf("%d,",vetorY[i]);
	}	
}
void listaW (int *vetorX,int n){
	int *vetorW,i,aux=1;
	vetorW = (int*) malloc(n * sizeof(int));//reserva outro endere?de memoria diferente do vetorX para n?alterar os valores do vetorX
	n = n/2;
	for(i=0;i<n;i++){
		vetorW [i] = vetorX[aux];
		aux += 2;
	}printf("\nVetorW:");
	for(i=0;i<n;i++){
		printf("%d,",vetorW[i]);
	}
}
void pesquisa(int *vetorX,int n, int Z){
	int flag=0,i;
	for(i=0;i<n;i++){
		if(vetorX[i]==Z){
			printf("\nO elemento %d existe no vetorX.",Z);
			flag = 1;
			break;
		}	
	}if(flag == 0){
		printf("\nO elemento %d nao existe no vetorX.",Z);
	}	
}
void ordenaVetorX(int *vetorX,int n){
	int aux,i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(vetorX[i]<vetorX[j]){
				aux = vetorX[i];
				vetorX[i] = vetorX[j];
				vetorX[j] = aux;
			}
		}
	}
	printf("\nMenor:%d",vetorX[n-1]);
	printf("\nMaior:%d\n",vetorX[0]);
}
int main(int argc, char *argv[]) {
	int *vetorX,n,Z;
	printf("Digite a quantidade de numeros do vetor:");
	scanf("%d",&n);
	printf("Digite o numero que vai ser pesquisado no vetor:");
	scanf("%d",&Z);
	vetorX = listaX(n);
	listaY(vetorX,n);
	listaW(vetorX,n);
	pesquisa(vetorX,n,Z);
	ordenaVetorX(vetorX,n);
	return 0;
}
