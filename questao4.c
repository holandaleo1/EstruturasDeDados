#include <stdio.h>
#include <stdlib.h>
int verificaPrimo(int n){
	int i, flag= 0;
	for(i=n-1;i>1;i--){
		if(n % i == 0){
			flag = 1;
			return 0;
		}
	}if(flag == 0){
		return 1;
	}
}
void verificaPrimoSucessor(int n){
	int i = 0, v1[1],aux1=0,aux2=1;
	while(i!=2){
		if(verificaPrimo(n+aux2)){
			aux1++;
			if(aux1 == 1){
				v1[0] = n+aux2;
			}else if(aux1 == 2){
				v1[1] = n+aux2;
				break;
			}
		 i++;
		}
	aux2++;
	}
	printf("Sucessores Primos:%d,%d",v1[0],v1[1]);
}
int verificaPrimoAntecessor(int n){
	int i = 0, v1[1],aux1=0,aux2=1;
	while(i!=2 && aux2 < n){
		if(verificaPrimo(n-aux2)){
			aux1 +=1;
			if(aux1 == 1){
				v1[0] = n-aux2;
			}else if(aux1 == 2){
				v1[1] = n-aux2;
				break;
			}
		 i++;
		}
	aux2++;
	}
	printf("\nAntecessores Primos:%d,%d",v1[1],v1[0]);
}
int main(int argc, char *argv[]) {
	int n,retorno;
	printf("Digite o numero:");
	scanf("%d",&n);
	retorno = verificaPrimo(n);
	if(n!=3){
	while(retorno != 1 || n == 1){
		printf("Nao eh primo, digite um novo numero:");
		scanf("%d",&n);
		retorno = verificaPrimo(n);
	}
	verificaPrimoSucessor(n);		
	verificaPrimoAntecessor(n);
	}else{
		printf("\nSucessores: 5,7");
		printf("\nAntecessor:2");
	}
	return 0;
}
