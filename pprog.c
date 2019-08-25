#include<stdio.h>
#include<omp.h>

int main(){
	const int N = 10000;
	int i; 
	int a[N], b[N], c[N]; 
	for (i = 0; i<N; i++){
		a[i]=i*2;
		b[i]=i;
	}
#pragma omp parallel shared(a,b,c) private(i)
	{
#pragma omp for
		for(i=0;i<N;i++){
			c[i]=a[i] + b[i];
		}
	}

	printf("%d ", c[10]);
}

