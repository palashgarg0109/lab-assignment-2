/**
* @file Mat.c
* @this c program computes the maximal array
* @author Palash Garg
* @date 6-8-2019
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//! to print the quad tree
struct node {
    int label;
    int bit;
    int level;
};

int top=0;
int num_of_nodes=1;
struct node quadtree[5000];

//! calculate size of input array
int calculate_size(){
	FILE* f;
	f=fopen("p2input.txt","r");
	char c;
	int x;
	while((c = fgetc(f)) != EOF){
		if(c==' '||c=='\n'){
			continue;
		}
		else{
			x++;
		}
	}
	fclose(f);
	int size=sqrt(x);
	return size;
}

//! check if array has same input value or not 

bool check_same_bits(int** a,int n,int fi,int fj){
	int value=a[fi][fj];
	for(int i=fi;i<n+fi;i++){
		for(int j=fj;j<n+fj;j++){
			if(a[i][j]!=value){
				return false;
			}
		}
	}
	return true;

}

//! recursive function
void MAT(int** a,int n,int fi,int fj,int** out,int level){
	if(n==0){
		return;
	}

	if(check_same_bits(a,n,fi,fj)){
		for(int i=fi;i<n+fi;i++){
			for(int j=fj;j<n+fj;j++){
				out[i][j]=num_of_nodes;
				quadtree[top].bit = a[i][j];
			}
		}

		quadtree[top].label = num_of_nodes;
        
        quadtree[top].level = level;
        top++;

		num_of_nodes++;
	}
	else{
		MAT(a,n/2,fi,fj,out,level+1);
		MAT(a,n/2,fi,fj+n/2,out,level+1);
		MAT(a,n/2,fi+n/2,fj,out,level+1);
		MAT(a,n/2,fi+n/2,fj+n/2,out,level+1);
	}
}

int main(){
	int size=calculate_size();
	int n=ceil(log2(size));
	n=pow(2,n);

	int **arr = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         arr[i] = (int *)malloc(n * sizeof(int)); 

	for(int i=0;i<(n-size);i++){
		for(int j=0;j<(n-size);j++){
			arr[i][j]=0;
		}
	}
	

	FILE* f;
	f=fopen("p2input.txt","r");
		for(int i=n-size;i<n;i++){
		for(int j=n-size;j<n;j++){
			fscanf(f,"%d ",&arr[i][j]);
		}
	}
// 	char ch = '0';
// 	while(ch != EOF){
// ch = fgetc(f);
// 		if(ch==' '|| ch=='/n'){
// 			continue;
// 		}
// 		else{
// 			for(int i=n-size;i<n;i++){
// 				for(int j=n-size;j<n;j++){
// 					arr[i][j]=ch-'0';
// 				}
// 			}
// 		}
// 	}
// 	fclose(f);

// 	for(int i = n-size ; i < n ; i++)
//     {
// 	for(int j = n - size ; j < n ; j++)
// 	{
// 	    if(j != (n - 1))
// 	    {
// 		fscanf(f , "%d " , &arr[i][j]);
// 	    }
// 	    else
// 	    {
// 		fscanf(f , "%d\n" , &arr[i][j]);
// 	    }
// 	}
//     }
//     fclose(f);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);

		}
		printf("\n");
	}

	printf("\n\n");

	int **new_array = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         new_array[i] = (int *)malloc(n * sizeof(int)); 

	MAT(arr,n,0,0,new_array,0);


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",new_array[i][j]);

		}
		printf("\n");
	}

	printf("\n\n");

	printf("enter the node no. whose level you want to know");
	printf("\n");
	int num;
	scanf("%d",&num);
	printf("(%d,%d,%d)",quadtree[num-1].label, quadtree[num-1].bit, quadtree[num-1].level);
	printf("\n");

return 0;

}



