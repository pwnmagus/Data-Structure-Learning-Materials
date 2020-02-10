#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


/*Rumah sakit Gensokyo
	jika vital < 10, priority = 1
	jika usia > 50 , priority = 2
	sisanya priority = 3
*/

struct rs{

	char nama[65];
	int vital;

	int priority;

	struct rs *next;

}*front, *rear, *curr;


void enqueue(char nama[], int vital, int p){

	struct rs *node = (struct rs*)malloc(sizeof(struct rs));
	
	strcpy(node->nama, nama);
	node->vital = vital;
	node->priority = p;

	if(rear==NULL){
		node->next=NULL;
		front=rear=node;
	}

	else if(front->priority > node->priority){
		node->next = front;
		front = node;
	}

	else if(rear->priority <= node->priority){
		rear->next = node;
		node->next = NULL;
		rear=node;
	}

	else{
	curr=front;

	while(curr->next->priority <= node->priority){
		
		curr=curr->next;
	}

	node->next = curr->next;
	curr->next = node;
	}
}

void enterData(){
char nama[65];
int vital;
int priority;
system("cls");
do{
	printf("Enter Patient's Name : ");
	gets(nama);
}while(strlen(nama) < 3 || strlen(nama) > 65);

do{
	printf("Enter Patient's Initial Vital [0-100]: ");
	scanf("%d", &vital); fflush(stdin);
}while(vital < 1 || vital > 100);


/*logic for priority*/

if(vital < 10){
	priority = 1;
}
else{
	priority = 2;
}

enqueue(nama, vital, priority);
}


void dequeue(){
	system("cls");
	if(front==NULL)
		return;

	printf("Please enter the examination room, Mr/Ms. %s\n", front->nama);

	if(front==rear){
		free(front);
		front=rear=NULL;
	}

	else{
		curr=front;
		front=front->next;
		free(curr);
		curr=NULL;
	}
}

void view(){

	printf("Waiting List Gensokyo Hospital\n\n");
	printf("%-20s %3s\n", "Patient Name", "Initial Vital");

curr=front;
int count=0;
int maxVital=0;
int minVital=100;

while(curr){

	count++;
	printf("%-20s %3d\n", curr->nama, curr->vital);

	curr=curr->next;
	}
	printf("\n\nWaiting Patients : %d\n", count);
	
	

}
void menu(){
printf("=== + Gensokyo Hospital + ===\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Exit\n");
printf("Your Choice : ");

}


int main(){

int opsi;
front=rear=NULL;

while(true){
	system("cls");
	view();
	menu();

	do{
	scanf("%d", &opsi); fflush(stdin);
	}while(opsi < 1 || opsi > 3);

	switch(opsi){
	
	case 1:
		enterData();
		break;

	case 2:
		dequeue();
		break;

	case 3:
		printf("bye...\n");
		getchar();
		exit(0);
		break;
	}
	getchar();
	}
}