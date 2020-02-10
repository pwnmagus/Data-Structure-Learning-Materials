#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

/*antrian mahasiswa*/

struct mhs {

    char name[225];
    char NIM[11];
    char keperluan[50];

        struct mhs *next, *prev;

}*front , *rear, *curr;

void dash(){

    printf("====================================================\n");
    printf("|               Student Service Center             |\n");
    printf("|          >> ==  BINUS University  == <<          |\n");
    printf("====================================================\n");

}

void menu(){

    printf("\n\n\t=== [Queue Registration] ===\n");
    printf("\t[1] View Current Queue\n");
    printf("\t[2] Queue a Student\n");
    printf("\t[3] Dequeue a Student\n");
    printf("\t[4] Exit\n");
    printf("\tChoose >> ");
}

void view(){
system("cls");
if(front==NULL){

    printf("\n\n\tThe Queue is Empty\n");

}

else if(front!=NULL){

        int c=0;
        curr=front;

        while(curr!=NULL){

            printf("\tAntrian Ke-[%d]\n", ++c);
            printf(" \tNama      : %s\n", curr->name);
            printf(" \tNIM       : %s\n", curr->NIM);
            printf(" \tKeperluan : %s\n\n", curr->keperluan);

            curr=curr->next;

            }
        }



getchar();
}


void push(){
    system("cls");
    dash();
    printf("\n\n");
    char temp1[225];  //tembak ke curr->nama
    char temp2[11];   //tembak ke curr->nim
    char temp3[50];   //tembak ke curr->keperluan

    do{
        printf("Masukkan Nama Mahasiswa : ");
        gets(temp1);
    }while(strlen(temp1) < 3 || strlen(temp1) > 225);

    do{
        printf("Masukkan NIM : ");
        gets(temp2);
    }while(strlen(temp2) < 1 || strlen(temp2) > 10);

    do{
        printf("Masukkan Keperluan Mahasiswa [Administrasi/Absensi/dll] : ");
        gets(temp3);
    }while(strcmpi(temp3, "Administrasi")!=0 && strcmpi(temp3, "Absensi")!=0 && strcmpi(temp3, "dll")!=0);

    struct mhs *curr = (struct mhs*)malloc(sizeof(struct mhs));
    curr->next = curr->prev = NULL;

    strcpy(curr->name, temp1);
    strcpy(curr->NIM, temp2);
    strcpy(curr->keperluan, temp3);

    if(rear==NULL){
        front=rear=curr;

    }

    else{
        rear->next=curr;
        curr->prev=rear;
        rear=curr;
    }

    printf("\n\n --- Data yang dimasukkan berhasil masuk ke antrian ---\n");
}

void pop(){
    system("cls");
    dash();
    printf("\n");
    if(front==NULL){
        printf("The Queue is Empty\n");
    }

    else if(front==rear){

        printf("Silakan menuju ke konter konsultasi, \n\n");

        printf("Nama      : %s\n", front->name);
        printf("NIM       : %s\n", front->NIM);
        printf("Keperluan : %s\n", front->keperluan);

        free(front);
        front=rear=NULL;

    }

    else{

        printf("Silakan menuju ke konter konsultasi, \n\n");

        printf("Nama      : %s\n", front->name);
        printf("NIM       : %s\n", front->NIM);
        printf("Keperluan : %s\n", front->keperluan);


        front=front->next;
        free(front->prev);
        front->prev=NULL;

    }

}


int main(){

    int opsi;

    while(true){
        system("cls");
        dash();
        menu();
        do{
            scanf("%d", &opsi); fflush(stdin);

        }while(opsi < 1 || opsi > 4);

    switch(opsi){

    case 1:
        view();
        break;

    case 2:
        push();
        break;

    case 3:
        pop();
        break;

    case 4:
        printf("\tGoodbye :) \n");
        getchar();
        exit(0);
        break;


    }
    getchar();

    }

}
