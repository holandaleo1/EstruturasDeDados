#include <stdio.h>
#include <stdlib.h>
int *vetor(int n){
	int *lista,i;
	for(i=0;i<n;i++){
		printf("Digite o %d do vetor:",i+1);
		scanf("%d",&lista[i]);
	}
	return lista;
}
void ordenaVetor(int *vetor,int n){
	int aux,i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(vetor[i]>vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}	
}
int elementosRepetidos(int *vetor,int n){
	int i,j,posicao,flag = 0,cont=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(vetor[i]==vetor[j]){
					posicao = j;//posicao onde aparece uma repetição
					flag = 1;
					j--;//verificar se existe outra repetição 
					n--;//diminuir tamanho do vetor
					i--;//verificar se existe outra repetição 
					cont++;//número de elementos removidos
					while(posicao<n){
						vetor[posicao] = vetor[posicao+1];
						posicao++;
					}
				}
			}
		}
		if(flag == 0){
			printf("\nOk!");
		}else{
			printf("\nQuantidade de elementos removidos: %d",cont);
		}
	return n;
}
void pesquisaBinaria(int *vetor, int n , int busca){
	int inicio = 0,
		fim = (n-1),
		meio = (inicio+fim)/2,
		flag = 0;
	while(inicio<=fim && flag == 0){
		if(vetor[meio] == busca){
			flag = 1;
		}else if(busca > vetor[meio]){
				inicio = meio+1;
				meio = (inicio+fim)/2;
			}else if(busca < vetor[meio]){
				fim = meio-1;
				meio = (inicio+fim)/2;
			}
		}
	if(flag ==0){
		printf("\nElemento %d nao existe no vetor!",busca);
	}else{
		printf("\nElemento %d  existe no vetor!",busca);
	}
}
void imprimir(int *vetor,int n){
	int i;
	printf("\nvetor:");
	for(i=0;i<n;i++){
		printf("%d",vetor[i]);
	}
}
int main(int argc, char *argv[]) {
	int *vet,n,newTam,busca;
	printf("Digite o tamanho do vetor:");	
	scanf("%d",&n);
	printf("Digite o elemento que deve ser buscado:");
	scanf("%d",&busca);
	vet = vetor(n);
	ordenaVetor(vet,n);
	newTam = elementosRepetidos(vet,n);
	pesquisaBinaria(vet, newTam , busca);
	imprimir(vet,newTam);
	return 0;
}


