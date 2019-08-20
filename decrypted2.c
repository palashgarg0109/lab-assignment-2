/**
* @file decrypted2.c
* @this c decrypts file
* @author Palash Garg
* @date 6-8-2019
*/ 

#include<stdio.h>
#include<stdlib.h>

//! write the decrypted file as output

void write_file(char* file2,char* decrypted_s,int new_capacity){
    FILE* f2;
	f2 = fopen(file2, "w");
    for(int i=0;i<new_capacity;i++){
    	if(decrypted_s[i]!=96){
    	fprintf(f2,"%c",decrypted_s[i]);
    }
}
    fclose(f2);
}

//! decrypts the file by finding new a' b'
void decrypt(char* s,int l,int n,int a,int b){
	l=l-1;
	//printf("%d\n",l);

int x=l%n;
		int y;
		if(x==0){
			y=0;
		}
		else{
			y=n-x;
		}
		//printf("%d\n",y);
		int new_capacity=l+y;
		char decrypted_s[l+y];
		int A,B;
		for(int z=1;z<=n;z++){
			if((z*a)%n==1){
				A=z;
				break;
			}
		}
		B=n-((A*b)%n);
		//printf("%d\n",A);
		//printf("%d\n",B);

		for(int k=0;k<l+y;k=k+n){
			for(int i=0;i<n;i++){
				int j=(A*i+B)%n;
				
				decrypted_s[i+k]=s[j+k];


			}
		}
		//for(int p=0;p<l+y;p++){
		//	if(decrypted_s[p]!=96)
		//	printf("%c",decrypted_s[p]);
		//}

		write_file("decryptedOutputfile.txt",decrypted_s,new_capacity);
	}

//! main function reads the encrypted file
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
		


	
	decrypt(s,length,n,a,b);

return 0;

}

