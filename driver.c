#include <stdlib.h>
#include <stdio.h>
#include "memoryMonitor.h"

int main(void){
	init();
	int *x = calloc(5,sizeof(int));
	double *y = malloc(sizeof(double));
	printf("%d\n",y);
	FILE *f = fopen("monitor.txt","r");
	fseek(f,29,0);
	char s[20];
	fscanf(f,"%d",s);
	printf("%s\n",s);
	//printf("%d\n",atoi(s)==y);
	fclose(f);
	return 0;
}
