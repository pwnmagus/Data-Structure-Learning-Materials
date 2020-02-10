#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//people with smaller priority scale will be dequeued first

struct data{
	char nama[200];
	int prioritas;
};

data heap[1000];
int count;

void heapup(int index){
	if(index==1)return;
	data temp;
	int parent = index / 2;

	if(heap[index].prioritas < heap[parent].prioritas){
	temp = heap[index];
	heap[index] = heap[parent];
	heap[parent] = temp;
	heapup(parent);
	}
}

void push(char* nama, int prioritas){
	if(count>=1000){
	printf("Heap is full\n");
	return;
	}
	count++;
	strcpy(heap[count].nama, nama);
	heap[count].prioritas = prioritas;
	heapup(count);
}

void insertor(){
	char nama[200];
	int prioritas;

	do{
	printf("Input Name [3..100 char]>> ");
	scanf("%[^\n]s", &nama); fflush(stdin);
	}while(strlen(nama) < 3 || strlen(nama) > 100);
	
	do{
	printf("Input Priority Score [1-10] >>");
	scanf("%d", &prioritas); fflush(stdin);
	}while(prioritas < 1 || prioritas > 10);

	printf("Data saved!\n");
	push(nama,prioritas);
}


void heapdown(int index){
	int curidx = index;
	int curval = heap[index].prioritas;

	if(index*2 <= count && curval > heap[index*2].prioritas){
		curidx = index*2;
		curval = heap[curidx].prioritas;
	}

	if(index*2+1 <= count && curval > heap[index*2+1].prioritas){
		curidx = index*2+1;
		curval = heap[curidx].prioritas;
	}

	if(curidx==index)return;

	//swapping the val
	data temp;
	temp = heap[index];
	heap[index] = heap[curidx];
	heap[curidx] = temp;
	heapdown(curidx);
}

void rmmin(){
	printf("%s 's data removed from system...\n", heap[1].nama);	
	heap[1] = heap[count];
	count--;
	heapdown(1);
}

void menu(){
	printf("Antrian - Min heap ver.01\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Exit\n");
	printf("Your option [1-3] : ");
}

int main(){
int opsi;
int count = 0;

while(true){
	menu();
	do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 3);
	switch(opsi){
	
	case 1:
		insertor();
		break;

	case 2:
		rmmin();
		break;

	case 3:
		printf("Thanks for using this app...\n");
		getchar();
		exit(0);
		break;
	
	}
	getchar();
	}
}