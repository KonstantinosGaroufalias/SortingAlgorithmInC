#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MTgen.h"

const int i = 4;
const int j = 3;

unsigned int * createArray(int n);
void fillArray(unsigned int *p, int n);
void printArray(unsigned int *p, int n);
void copyArray(unsigned int *p, unsigned int *q, int n);
void rvereseArray(unsigned int *p, int left, int right);
void quickSort(int left, int right, unsigned int *p);
void selectSort(unsigned int *p, int n);
void insertSort(unsigned int *p, int n,int comp);
void shellSort(unsigned int *p, int n);
void fromArrayToFile(float times[i][j], int n);


int main(int argc, char *argv[]) {
	
	int n;
	unsigned int *initArr, *copyArr, *initArrAsc;
	clock_t  ct0, ct1;
	float sec_select, sec_insert, sec_shell, sec_quick;
	float times_Array[4][3];
	int left, right;
	int Select_comp,Insert_comp;
	
	sMTrand(time(NULL));
	
		
	printf("Give the Array size to sort : ");
	scanf("%d", &n);
	Select_comp=(n*(n-1))/2;
	
	left = 0;
	right = n-1;
	printf("Initiallising random array...\n");
	initArr = createArray(n);
	copyArr = createArray(n);
	fillArray(initArr, n);
	

	copyArray(initArr, copyArr, n);

	printf("Select sort...");
	ct0 = clock();
	selectSort(copyArr, n);
	ct1 = clock();
	sec_select = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[0][0] = sec_select;
	printf("DONE!\n");

	copyArray(initArr, copyArr, n);

	printf("Insert sort...");
	ct0 = clock();
	insertSort(copyArr, n,Insert_comp);
	ct1 = clock();
	sec_insert = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[1][0] = sec_insert;
	printf("DONE!\n");

	
	copyArray(initArr, copyArr, n);
	
	printf("Shell sort...");
	ct0 = clock();
	shellSort(copyArr, n);
	ct1 = clock();
	sec_shell = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[2][0] = sec_shell;
	copyArray(initArr, copyArr, n);
	printf("DONE!\n");

	printf("Quick sort...");
	ct0 = clock();
	quickSort(left, right, copyArr);
	ct1 = clock();
	sec_quick = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[3][0] = sec_quick;
	printf("DONE!\n");
	printf("Converting to Ascending Array... \n");

	
	quickSort(left, right, initArr);
	copyArray(initArr, copyArr, n);

	
	copyArray(initArr, copyArr, n);
	
	printf("Select sort...");
	ct0 = clock();
	selectSort(copyArr, n);
	ct1 = clock();
	sec_select = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[0][1] = sec_select;
	printf("DONE!\n");
	
	
	copyArray(initArr, copyArr, n);

	printf("Insert sort...");
	ct0 = clock();
	insertSort(copyArr, n,Insert_comp);
	ct1 = clock();
	sec_insert = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[1][1] = sec_insert;
	printf("DONE!\n");
	
	
	copyArray(initArr, copyArr, n);
	printf("Shell sort...");
	ct0 = clock();
	shellSort(copyArr, n);
	ct1 = clock();
	sec_shell = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[2][1] = sec_shell;
	printf("DONE!\n");
	
	copyArray(initArr, copyArr, n);
	
	printf("Quick sort...");
	ct0 = clock();
	quickSort(left, right, copyArr);
	ct1 = clock();
	sec_quick = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[3][1] = sec_quick;
	printf("DONE!\n");
	
	printf("Converting to Descending Array...\n");
	rvereseArray(initArr, left, right);
	
	copyArray(initArr, copyArr, n);
	
	printf("Select sort...");
	ct0 = clock();
	selectSort(copyArr, n);
	ct1 = clock();
	sec_select = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[0][2] = sec_select;
	printf("DONE!\n");
	
	copyArray(initArr, copyArr, n);

	printf("Insert sort...");
	ct0 = clock();
	insertSort(copyArr, n,Insert_comp);
	ct1 = clock();
	sec_insert = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[1][2] = sec_insert;
	printf("DONE!\n");
	
	copyArray(initArr, copyArr, n);
	printf("Shell sort...");
	ct0 = clock();
	shellSort(copyArr, n);
	ct1 = clock();
	sec_shell = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[2][2] = sec_shell;
    printf("DONE!\n");

	copyArray(initArr, copyArr, n);

	printf("Quick sort...");
	ct0 = clock();
	quickSort(left, right, copyArr);
	ct1 = clock();
	sec_quick = (float)(ct1-ct0)/CLOCKS_PER_SEC;
	times_Array[3][2] = sec_quick;
	printf("DONE!\n");

	
	printf("\n");
	printf("---------------------------------\n");
	printf("Original Array sorting times: \n");
	printf("Select: %f (number of comparisons : %d) \n", times_Array[0][0],Select_comp);
	printf("Insert: %f \n", times_Array[1][0]);
	printf("Shell: %f \n", times_Array[2][0]);
	printf("Quick: %f \n", times_Array[3][0]);
	printf("\n");
	printf("Ascending Array sorting times: \n");
	printf("Select: %f (number of comparisons : %d) \n", times_Array[0][1],Select_comp);
	printf("Insert: %f \n", times_Array[1][1]);
	printf("Shell: %f \n", times_Array[2][1]);
	printf("Quick: %f \n", times_Array[3][1]);
	printf("\n");
	printf("Descending Array sorting times: \n");
	printf("Select: %f (number of comparisons : %d) \n", times_Array[0][2],Select_comp);
	printf("Insert: %f \n", times_Array[1][2]);
	printf("Shell: %f \n", times_Array[2][2]);
	printf("Quick: %f \n", times_Array[3][2]);
	printf("---------------------------------\n");
	
	fromArrayToFile(times_Array,n);
	printf("The results have been printed to a file called TIMES.txt in the excecution folder...\nResults have been rewritten\n\n");
		printf("---------------------------------\n");
	printf("Ergasia domes dedomenon Garoufalias Konstantinos-Marios 19121");
	
	
	return 0;
}



unsigned int * createArray(int n)
{
    unsigned int *p;
    
	p = (unsigned int*)malloc(n*sizeof(unsigned int));
	if(p==NULL)
      {
         printf( "Insufficient memory. Exiting..." );
         exit(1);
      } 
	return p;	
}


void fillArray(unsigned int *p, int n)
{
	int i;
	
	for(i=0; i<n; i++)
        p[i] = MTrand();
		
}


void printArray(unsigned int *p, int n)
{
	int i;
	
	for(i=0; i<n; i++)
	    printf("%u ", p[i]);
	printf("\n");
}


void copyArray(unsigned int *p, unsigned int *q, int n)
{
	int i;
	for(i=0; i<n; i++)
	    q[i] = p[i];	
}



void quickSort(int left, int right, unsigned int *p)
{
	int i, j, mid;
	unsigned int x, temp;
	
	if (left < right)
		{
			i = left;
			j = right;
			mid =(left+right)/2;
			x = p[mid];
			
			while(i <j)
				{
					while(p[i] < x)
						i++;
					while(p[j] >x)
						j--;
						if(i < j)
							{
								if(p[i] == p[j])
									{
										if(i<mid)
											i++;
											
										if(j>mid)
											j--;
									}
								else
									{
										temp = p[i];
										p[i] = p[j];
										p[j] = temp;
									}								
							}
				}
			quickSort(left,j-1,p);
			quickSort(j+1,right,p);
		}
}



void selectSort(unsigned int *p, int n)
{
	int i, j, k;
	unsigned int min;
	
	for(i=0; i<n-1; i++)
       {
          k = i;
          min = p[i];
          for(j=i+1; j<n; j++)
             {
                if(p[j] < min)
                  {
                     k = j;
                     min = p[j];
                  }
             }
          p[k] = p[i];
          p[i] = min;
       }	
}



void insertSort(unsigned int *p, int n,int comp)
{
	int Insert_comp=0;
	int i, j;
	unsigned int x;
	
	for(i=1; i<n; i++)
		{	
			x = p[i];
			j = i-1;
			while(j>=0 && x<p[j])
				{
					Insert_comp++;
					p[j+1] = p[j];
					j = j-1;
					Insert_comp++;
				}
				
			p[j+1] = x;
		}
		printf("(comparisons:%d)" ,Insert_comp);
}



void shellSort(unsigned int *p, int n)
{
	int initInter, h, i, j;
	unsigned int x;
	initInter = n/2;
	
	for(h=initInter; h>0; h=h/2)
		{
			for(i=h; i<n; i++)
				{
					x = p[i];
					j = i-h;
					
					while(j>=0 && x<p[j])
						{
							p[j+h] = p[j];
							j=j-h;
						}
					p[j+h] = x;
				}
		}
}



void rvereseArray(unsigned int *p, int left, int right)
{
    unsigned int temp;
    while (left < right)
    	{
        	temp = p[left];   
        	p[left] = p[right];
        	p[right] = temp;
        	left++;
        	right--;
   		}   
}   


void fromArrayToFile(float times[i][j], int n)
{	int k, m;
	FILE *fp;
	
	fp = fopen("TIMES.TXT", "w");
	fprintf(fp, "==================================\n");
	fprintf(fp, "Array size : %d\n" ,n);
   for(m=0; m<j; m++)
		{
			if(m==0){
				fprintf(fp, "\nRandom Array\n");
			}
			if(m==1){
				fprintf(fp, "\nAscending Array\n");
			}
			if(m==2){	 
				fprintf(fp, "\nDescending Array\n");
		}
		
			for(k=0; k<i; k++)
				{
					
					if(k == 0){
				fprintf(fp, "Select sort:");
			}
			if(k == 1){
				fprintf(fp, "Insert sort:");
			}
			if(k == 2){
				fprintf(fp, "Shell sort:");
			}
			if(k == 3){
				fprintf(fp, "Quick sort:");
			}
			
				fprintf(fp, "%f \n", times[k][m]);
			
				}
		}				
		printf("\n");
      		fprintf(fp, "==================================");
      	
    fclose(fp);
}
