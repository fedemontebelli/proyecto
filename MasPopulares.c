#include <stdio.h>


int main () {
	
	int i,j,aux;
	int x[20] = {10,36,45,77,95,30,12,36,58,44,66,99,55,88,33,22,11,1,9,6};
	
	i=20;
	while (i>1){
		j=1;
			while (j<i) {
				
				if (x[j]>x[j+1])  {
					
					aux=x[j];
					x[j]=x[j+1];
					x[j+1]=aux;			
				}
				j=j++;					
			}
		
		i=i-1;		
	}
	
	
	i=19;
	while (i>=10){
		
		printf("| %i |\n", x[i]);
		i=i-1;
		
	}
	
	
	
	return 0;
}
