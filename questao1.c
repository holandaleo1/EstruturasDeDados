#include <stdio.h>
#include <stdlib.h>
//Leonardo
int *criarLista(int n){
    int i,aux;//
    int *vetor;
    for (i = 0; i < n; ++i){
    	printf("Digite o %d valor:",i+1);
    	scanf("%d",&aux);
    	if(aux<256){
    		vetor[i] = aux;
		}else{
			printf("O valor anterior nao foi registrado.\n");
			i --;
		}
    }
    return vetor;
}
int ordenaVetor(int *vetor,int n){
	int aux,i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(vetor[i]<vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}	
}
void imprimirVetor(int *vetor,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d,",vetor[i]);
	}
}
void paridade(int *vetor,int n){
	int i,par=0,impar=0,j=0;
	float med=0.0;
	for(i=0;i<n;i++){
		if(vetor[i]%2==0){
			par+=1;
		}else if(vetor[i]%2 !=0){
			impar+=1;
			if(vetor[i]>50){
				med += vetor[i];
				j +=1;
			}
		}	
	}
	if(j==0){
		j = 1;
	}
	med = med/j;
	printf("\nQuantidade de numeros Pares: %d",par);
	printf("\nQuantidade de numeros Impares: %d",impar);
	printf("\nMedia de numeros impares maiores que 50: %.2f\n",med);
}
int main(int argc, char *argv[]) {
	int *ponteiro,n;
	printf("Digite o numero de valores do vetor:");
	scanf("%d",&n);
	while(n>100){
		printf("O numero de valores devem ser <= 100, digite um valor novamente!");
		scanf("%d",&n);
	}
	ponteiro = criarLista(n);
	printf("\nLista inserida:");
	imprimirVetor(ponteiro,n);
	ordenaVetor(ponteiro,n);
	printf("\nLista ordenada:");
	imprimirVetor(ponteiro,n);
	paridade(ponteiro,n);
	return 0;
}
