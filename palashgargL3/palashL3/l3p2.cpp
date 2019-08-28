/**
* @file l3p2
* @this find no.of triplets and print them
* @author Palash Garg
* @date 18-8-2019
*/ 
#include <iostream>

using namespace std;

int count=0;

//! craetes node of linked list
class node
{
    public:
    int data;
    node *next;
};

node *head=NULL;
node *ptr=NULL;

//! store prefix xor in linked list (DYNAMIC PROGRAMMING)
void insertPrefixXOR(int a){
	node *temp=new node();
	temp->data=a;
	if(head==NULL){
		
		head=temp;
		ptr=temp;
		head->next=NULL;

	}
	else{
		ptr->next=temp;
		ptr=temp;

	}

}

//! get the stored prefix xor at specified i
int getElement(int i){

	if(i==0){
		int value=0;
		return value;
	}
	else{
		node *current=head;
	for(int j=1;j<i;j++){
		current=current->next;
	}
	int value=current->data;
	return value;
}
}

//! prints and counts all the triplets present
void print(int i,int k){
	
	for(int j=i+1;j<k+1;j++){
		cout<<"{"<<i<<","<<j<<","<<k<<"}"<<endl;
		count++;
	}
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int num=arr[0];
	insertPrefixXOR(num);
	for(int i=1;i<n;i++){
		num=num^arr[i];
		insertPrefixXOR(num);
	}

	for(int i=0;i<=n;i++){
		for(int k=i+1;k<=n;k++){
			int x=getElement(i);
			int y=getElement(k);
			if((x^y)==0){
				print(i+1,k);
			}
		}
	}

	cout<<"no. of triplets="<<count<<endl;

	// for(int i=0;i<=n;i++){
	// 	cout<<getElement(i)<<endl;
	// }


	return 0;


}