/**
* @file comparefile.c
* @this c compare file
* @author Palash Garg
* @date 6-8-2019
*/ 


#include<stdio.h>
#include<stdlib.h>

//! compare the two string if they are same or not
void compare(char* a,char* b,int length){
	int j=0;
	for(int i=0;i<length;i++){
	if(a[i]!=b[i]){
		printf("%s\n","input and decryptedOutput files are not same.");
		break;
	}
	else{
		j++;
		continue;
	}
}
if(j==length){
	printf("%s\n","input and decryptedOutput files are same.");
}
}

//! reads the input file and decryptedOutput file and store them in string
	int main(int argc,char* argv[]){
	
	FILE *f;
	
	int length=0;
	
	
	f= fopen(argv[1],"r");
	
	while ( fgetc(f)!= EOF){	
		length++;
	}
	fclose(f);
	//length=length-1;
	//printf("%d\n",length);
	char a[length];
	f= fopen(argv[1],"r");

	fgets(&a,length,f);
	fclose(f);


	FILE *f2;
	
	//length=length-1;
	//printf("%d\n",length);
	char b[length];
	f2= fopen(argv[2],"r");

	fgets(&b,length,f2);
	fclose(f2);

	compare(a,b,length);

	return 0;
}