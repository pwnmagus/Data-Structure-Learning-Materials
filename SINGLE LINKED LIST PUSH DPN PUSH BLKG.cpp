#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

// Single linked list

struct package{
	
	char nama[45];
	int harga;

	struct package *next;
	
}*head, *tail, *curr;

void pushDpn(char nama[], int harga){
	
	struct package *node = (struct package*)malloc(sizeof(struct package));
	strcpy(node->nama, nama);
	node->harga = harga;

	if(head==NULL){
		node->next = NULL;
		head=tail=node;
		}
	else{
		node->next = head;
		head = node;
		}
	}

void pushBlkg(char nama[], int harga){
	
	struct package *node = (struct package*)malloc(sizeof(struct package));
	strcpy(node->nama, nama);
	node->harga = harga;

	if(tail==NULL){
	node->next = NULL;
	head = tail = node;
	}

	else{
		tail->next = node;
		node->next = NULL;
		tail = node;
		}	
	}

void ins1(){
	char nama[45];
	int harga;

	do{
		printf("Masukkan nama barangnya [3..45 char]: ");
		scanf("%s", &nama); fflush(stdin);
		}while(strlen(nama)  < 3 || strlen(nama) > 45 );
	
	do{
		printf("Masukkan harga barangnya [1-100 gold] : ");
		scanf("%d", &harga); fflush(stdin);
		}while(harga < 1 || harga > 100);

	printf("Data Successfully added to system...\n");
	pushDpn(nama, harga);
	}

void ins2(){
		char nama[45];
	int harga;

	do{
		printf("Masukkan nama barangnya [3..45 char]: ");
		scanf("%s", &nama); fflush(stdin);
		}while(strlen(nama)  < 3 || strlen(nama) > 45 );
	
	do{
		printf("Masukkan harga barangnya [1-100 gold] : ");
		scanf("%d", &harga); fflush(stdin);
		}while(harga < 1 || harga > 100);

	printf("Data Successfully added to system...\n");
	pushBlkg(nama, harga);
	}

void popDpn(){
	if(head==NULL)
			return;
	if(head==tail){
		free(head);
		head=tail=NULL;
		}
	else{
		curr=head;
		head=head->next;
		free(curr);
		curr=NULL;
		}
	}
void popAll(){
	while(head!=NULL){
		curr=head;
		head=head->next;
		free(curr);
		}
	curr=tail=NULL;
	}

void view(){
	int c=0;
	printf("No  %5s %5s\n", "Name", "Price");
	if(head==NULL){
		printf("\nNo availabe packages\n");
		}
	else{
		curr=head;
		while(curr!=NULL){
			c++;
			printf("%d  %5s %5d\n",c, curr->nama, curr->harga);
			curr=curr->next;
			}
		}
	}

void menu(){
	printf("\n\n=== Hakurei Express ===\n");
	printf("1. Add item [stack]\n");
	printf("2. Add item [queue]\n");
	printf("3. Delete item from top of the list\n");
	printf("4. Delete all registered package\n");
	printf("5. Exit\n");
	printf("Your choice [1-5]: ");
	}

int main(){
int opsi;
head=tail=NULL;

while(true){
	view();
	menu();
	
	do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 5 );

	switch(opsi){
		
	case 1:
		system("cls");
		ins1();
		break;
		
	case 2:
		system("cls");
		ins2();
		break;

	case 3:
		system("cls");
		popDpn();
		break;

	case 4:
		system("cls");
		popAll();
		break;

	case 5:
		exit(0);
		break;

		}

	getchar();
	}
}