#include <stdio.h>
#include "recursive.h"

int main(){
	Stack *s = createStack();
	char a[100];
	char b[100];
	printf("Ingrese la primer cadena\n");
	scanf("%[^\n]",a);
	printf("Ingrese la cadena que quiere buscar\n");
	scanf("%s",b);

	contador(a,b,0,s);
	int i=0;
	StackEntry r;
	r = pop(s);
	if (r!=-1){
	printf("Las posiciones en que se repiten la segunda cadena en la primera son:\n");
		while(r!=-1){
			printf(" %d ", r);
			r = pop(s);	
		}
		int efe=0;
	}else{
		printf("No hay coincidencias\n");
	}
}

int contador(char*a,char*b,int pos,Stack *e){
	
	if (a[pos]!= '\0'){
		if (a[pos]==*b){
			if (comprobador(a,b,pos)){
				push(pos,e);
				contador(a,b,pos+1,e);
			}else{
				contador(a,b,pos+1,e);
			}
		}else{
			contador(a,b,pos+1,e);
		}
	}else{
		return 0;
	}
}

int comprobador(char*a, char*b,int pos){
	int flag=1;
	while(*b!='\0'){
		if (a[pos]!=*b){
			flag=0;
			break;
		}
		pos++;
		b++;
	}	
	return flag;
}
