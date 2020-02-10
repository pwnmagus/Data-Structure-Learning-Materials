#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

/*Extended version of Eirin's Clinic

- using Single Linked List
- priority Queue

- first priority for those vitals below 10
- second priority for those aged over 55
- third priority, reguler patients...

:: Coded by Shinichi Nazakato (c) 2018, 23.31 WIB

*/

struct clinic{

    char nama[50];
    int age;
    int vital;
    int mp;

    int priority;

    struct clinic *next;


}*front, *rear , *curr;

void enqueue(char nama[], int age, int vital, int mp, int p){

    struct clinic *node = (struct clinic*)malloc(sizeof(struct clinic));

    /*Injecting data to node*/
    strcpy(node->nama , nama);
    node->age = age;
    node->vital = vital;
    node->mp = mp;
    node->priority = p;

    if(rear==NULL){
        node->next = NULL;
        front=rear=node;
    }

    else if(front->priority > node->priority){
        node->next = front;
        front = node;
    }

    else if(rear->priority <= node->priority){
        rear->next = node;
        node->next = NULL;
        rear = node;
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
    char nama[50];
    int age;
    int vital;
    int mp;
    int priority;


    do{
        printf("Enter Patient's Name : ");
       scanf("%s", &nama); fflush(stdin);
    }while(strlen(nama) < 2 || strlen(nama) > 50);

    do{
        printf("Enter Patient's Age : ");
        scanf("%d", &age); fflush(stdin);
    }while(age < 1 || age > 100);

    do{
        printf("Enter Patient's Initial Vital : ");
        scanf("%d", &vital); fflush(stdin);
    }while(vital < 1 || vital > 100);

    do{
        printf("Enter Patient's Initial MP : ");
        scanf("%d", &mp); fflush(stdin);
    }while(mp < 1 || mp > 100);

    /*Priority Queue Logic*/
    if(vital < 10){
        priority = 1;
    }
    else if(age > 55){
        priority = 2;
    }
    else{
        priority = 3;
    }
    enqueue(nama, age, vital, mp, priority);
}

void dequeue(){

if(front == NULL)
    return;

    printf("Get in to Dr.Eirin's Room, Mr/Ms. %s\n", front->nama);

    if(front==rear){
        free(front);
        front=rear=NULL;
    }
    else{
        curr = front;
        front = front->next;
        free(curr);
        curr = NULL;

    }
}
void view(){

    printf( "%-20s %3s %3s %3s","Name","Age","Vitality","MP");

    curr=front;
    int count=0;
    int maxAge=0;
    int minAge=100;


    while(curr!=NULL){
    count++;
    printf("\n%-20s %3d %3d %3d\n",curr->nama, curr->age, curr->vital, curr->mp);

	if(maxAge < curr->age)
        maxAge = curr->age;
    if(minAge > curr->age)
        minAge = curr->age;

		curr = curr->next;
    }
    printf("\n\n\n");
    printf("Total Patients in Queue : %d\n", count);
    printf("Patient Max Age : %d\n", maxAge);
    printf("Patient Min Age : %d\n", minAge);
    printf("\n\n\n");
}

void menu(){
    printf("Eirin's Clinic\n");
    printf("Please Pick one option from below\n");
    printf("1. Enqueue Patient\n");
    printf("2. Call Patient\n");
    printf("3. Quit This App\n");
    printf("Your Choice : ");
}


int main(){

    int opsi;
    front = rear = NULL;

    while(true){

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
        printf("bye");
        getchar();
         exit(0);
        break;


        }

        getchar();

    }
}



