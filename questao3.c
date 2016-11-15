#include <stdio.h>
#include <stdlib.h>
//Leonardo
int *vetorA(int A ){
	int *listaA ,i;
	listaA = (int *) malloc(A *sizeof(int));
	for(i=0;i<A ;i++){
		printf("Digite o %d valor do vetorA:",i+1);
		scanf("%d",&listaA[i]);
	}
	return listaA;
}
int *vetorB(int B ){
	int *listaB ,i;
	listaB = (int *) malloc(B*sizeof(int));
	for(i=0;i<B ;i++){
		printf("Digite o %d valor do vetorA:",i+1);
		scanf("%d",&listaB[i]);
	}
	return listaB;
}
int *vetorC(int *vetorA,int *vetorB,int n ){
	int *listaC,i,C,aux1=0,aux2=0;
	listaC = (int *) calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		if(i % 2 == 0){
			listaC[i] = vetorA[aux1];
			aux1 +=1;
		}else if(i % 2 != 0){
			listaC[i] = vetorB[aux2];
			aux2 += 1;
		}
	}
	return listaC;
}
void pesquisa(int *vetorC,int n,int num){
	int i,flag=0;
	for(i=0;i<n;i++){
		if(vetorC[i] == num){
			printf("\nO numero pesquisado existe no vetor C.");
			flag = 1;
			break;
		}
	}if(flag==0){
		printf("\nO numero pesquisado nao existe no vetor C!");
	}
}
void imprimir(int *vetor,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",vetor[i]);
	}
}
int main(int argc, char *argv[]) {
	int n,num,*vA ,*vB,*vC;
	printf("Digite o tamanho dos vetor A e B:");
	scanf("%d",&n);
	printf("Digite o valor que deve ser pesquisado no vetor C:");
	scanf("%d",&num);
	vA = vetorA (n);
	vB = vetorB (n);
	vC = vetorC (vA,vB,n*2);
	pesquisa(vC,n*2,num);
	printf("\nVetorA:");
	imprimir( vA,n );
	printf("\nVetorB:");
	imprimir(vB,n);
	printf("\nVetorC:");
	imprimir(vC,n*2);
	return 0;
}
