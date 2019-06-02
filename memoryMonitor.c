#include "memoryMonitor.h"

#undef malloc
#undef calloc
#undef free

void init(){
	FILE *f = fopen("monitor.txt","w");
	fprintf(f,"Address\t\tUnit Size\tAmount\t\tTotal\n\n");
	fclose(f);
}

void *XMALLOC(int n){
	void *ptr = malloc(n);
	FILE *f = fopen("monitor.txt","a");
	fprintf(f,"%d \t%d\t\t1\t\t%d\n",ptr,n,n);
	fclose(f);
	return ptr;
}

void *XCALLOC(int n,int s){
	void *ptr = calloc(n,s);
	FILE *f = fopen("monitor.txt","a");
	fprintf(f,"%d \t%d\t\t%d\t\t%d\n",ptr,s,n,n*s);
	fclose(f);
	return ptr;
}

void XFREE(void *ptr){
	FILE *f = fopen("monitor.txt","r");
	FILE *nf = fopen("tmp.txt","w");
	char s[81];
	char r[11];
	sprintf(r,"%d",ptr);
	while (!feof(f)){
		fgets(s,80,f);	
		int i;
		for (i=0;i<=10;++i)
			if (s[i]!=r[i])
				break;
		if (i<11)
			continue;
		fprintf(nf,"shit");
	}
	fclose(f);
	fclose(nf);
	//remove("monitor.txt");
	//rename("tmp.txt","monitor.txt");
	
	free(ptr);
}


#define malloc XMALLOC
#define calloc XCALLOC
#define free XFREE
