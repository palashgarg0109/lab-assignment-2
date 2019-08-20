/**
* @file Transpose.c
* @this c program encrypts
* @author Palash Garg
* @date 6-8-2019
*/ 

#include<stdio.h>
#include<stdlib.h>

//! it gives encrypted file as output
void write_file(char* file2,char* encrypted_s,int new_capacity){
    FILE* f2;
	f2 = fopen(file2, "w");
    for(int i=0;i<new_capacity+1;i++){
    	fprintf(f2,"%c",encrypted_s[i]);
    }
    fclose(f2);
}

//! it encrypts the given data
void encrypt(char *s,int l,int n,int a,int b){
		

		int capacity=l-1;
		//printf("%d\n",capacity);
		int x=capacity%n;
		int y;
		if(x==0){
			y=0;
		}
		else{
			y=n-x;
		}

		int new_capacity=capacity+y;
		//printf("%d\n",new_capacity);
		char encrypted_s[new_capacity];
		for(int i=capacity;i<new_capacity;i++){
			s[i]=96;
		}
		for(int k=0;k<new_capacity;k=k+n){
			for(int i=0;i<n;i++){
				int j=(a*i +b)%n;
				encrypted_s[i+k]=s[j+k];

			}
		}

		
			//printf("%s\n",encrypted_s);

		//for(int p=0;p<new_capacity;p++){
		//	printf("%c",encrypted_s[p]);
		//}
		
		write_file("outputfile.txt",encrypted_s,new_capacity);


	}

//! main function reads the n a b and input file	
	int main(int argc,char* argv[]){
	int n,a,b;
	FILE *f;
	
	int length=0;
	n=atoi(argv[1]);
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	
	f= fopen(argv[4],"r");
	
	while ( fgetc(f)!= EOF){	
		length++;
	}
	fclose(f);
	//length=length-1;
	//printf("%d\n",length);
	char s[length];
	f= fopen(argv[4],"r");

	fgets(&s,length,f);
	fclose(f);

	
			//printf("%s\n",s);
		


	
	encrypt(s,length,n,a,b);

return 0;

}