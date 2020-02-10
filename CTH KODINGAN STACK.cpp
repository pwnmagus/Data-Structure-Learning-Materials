/*koding stack latihan lagi*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>



struct parts{

	char item[50];
	int rarity;

	struct parts *next;
}*top, *curr;


void menu(){
	printf("\tvvvvvvvvvvvvvvvvvvvv\n");
	printf("\t|Nitori's Warehouse|\n");
	printf("\t^^^^^^^^^^^^^^^^^^^^\n");
	
	if(top!=NULL){
	
		curr=top;
		while(curr!=NULL){
		
		printf(" %5s | Rp. %-4d  |", curr->item, curr->rarity);
		if(curr==top){
		
			printf(" [Top]\n");
		
		}

		else{
		
			printf("\n");

		}
		curr=curr->next;
		}
	}

	printf("=== [ Menu Selection ] ===");
	printf("[1]. Stack Part Crates\n");
	printf("[2]. Take Part Crates from Stack\n");
	printf("[3]. Exit The Warehouse\n");
	printf("\nInput Your Choice >> ");
}

void push(){
	
	char temp[50];
	int rate;

	do{
	printf("Input the parts name [3-50 char] : ");
	scanf("%s", &temp); fflush(stdin);
	}while(strlen(temp) < 3 || strlen(temp) > 50 );

	do{
	printf("Input the parts rarity [1-5] : ");
	scanf("%d", &rate);
	}while(rate < 1 || rate > 5);


	struct parts *node = (struct parts*)malloc(sizeof(struct parts));
	strcpy(node->item, temp);
	node->rarity = rate;

	node->next = top;
	top = node;


	printf("--- Add Parts crate success ---\n");

}

void pop(){

	if(top==NULL){
	
	printf("--- The Warehouse is empty, please stack an item first --- \n");
	
	}

	else{
	
	struct parts *del;
	del=top;
	top=top->next;
	free(del);
	del=NULL;
	printf("--- The top Parts crate from stack has taken out from the stack  ---\n");
	
	}

}

int main(){

int opsi;

while(true){

	menu();
	do{
	scanf("%d", &opsi); fflush(stdin);
	}while(opsi < 1 || opsi > 3);


	switch(opsi){
	
	case 1: 
		push();
		break;

	case 2:
		pop();
		break;

	case 3:
		printf("--- Thanks For using this App ---\n");
		exit(0);
		break;
	}
	getchar();
	}
}
