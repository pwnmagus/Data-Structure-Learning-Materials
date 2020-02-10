//  Gabungan Codingan Min dan Max Heap  //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data1{
	char nama[100];
	int prioritas;
};

struct data2{
	char name[100];
	int priority;
};

data1 heap[1000];      // Booking 100 slot memori utk Min heap
data2 heaps[1000];     // Booking 100 slot memori utk Max heap
 
int count;             // Menunjukkan posisi data terakhir dimasukkan

//  === Min Heap === //

void heapup1(int index){
	if(index==1) return;

	int parent = index/2;
	data1 temp1;

	if(heap[index].prioritas < heap[parent].prioritas){
	//swapping the value
	temp1 = heap[index];
	heap[index] = heap[parent];
	heap[parent] = temp1;
	heapup1(parent);
	}
}

void pusher1(char *nama, int prioritas){
	if(count>=1000){
		printf("Sorry, the heap is full . . .\n");
		return;
	}
	count++;
	strcpy(heap[count].nama, nama);
	heap[count].prioritas = prioritas;
	heapup1(count);
}

void insertor1(){
	char nama[100];
	int prioritas;

	do{
		printf("Input name [3..100 chr] >> ");
		scanf("%[^\n]s", &nama); fflush(stdin);
	}while(strlen(nama) < 3 || strlen(nama) > 100);
	
	do{
		printf("Input Priority Score [1-10] >> ");
		scanf("%d", &prioritas); fflush(stdin);
	}while(prioritas < 1 || prioritas > 10);

	printf("Data Pushed to system . . . \n");
	pusher1(nama, prioritas);
}

void heapdown1(int index){
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

	if(curidx==index) return;
	
	//swapping the value
	data1 temp1;
	temp1 = heap[index];
	heap[index] = heap[curidx];
	heap[curidx] = temp1;
	heapdown1(curidx);
}

void rmmin(){
printf("%s 's data removed . . . \n", heap[1].nama);
heap[1] = heap[count];
count--;
heapdown1(1);
}

void menu1(){
printf("\n\n=== Min Heap ===\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Exit to Lobby\n");
printf("Your Option [1-3] >> ");
}

////////////////////////////////////////////////////////////////

//  === Max Heap ===

void heapup2(int index){
	if(index==1) return;

	int parent = index/2;
	data2 temp2;

	if(heaps[index].priority > heaps[parent].priority){
	//swapping the value
	temp2 = heaps[index];
	heaps[index] = heaps[parent];
	heaps[parent] = temp2;
	heapup2(parent);
	}
}

void pusher2(char *name, int priority){
	if(count>=1000){
		printf("Sorry, the heap is full . . .\n");
		return;
	}
	count++;
	strcpy(heaps[count].name, name);
	heaps[count].priority = priority;
	heapup2(count);
}

void insertor2(){
	char name[100];
	int priority;

	do{
		printf("Input name [3..100 chr] >> ");
		scanf("%[^\n]s", &name); fflush(stdin);
	}while(strlen(name) < 3 || strlen(name) > 100);
	
	do{
		printf("Input Priority Score [1-10] >> ");
		scanf("%d", &priority); fflush(stdin);
	}while(priority < 1 || priority > 10);

	printf("Data Pushed to system . . . \n");
	pusher2(name, priority);
}

void heapdown2(int index){
	int curidx = index;
	int curval = heaps[index].priority;

	if(index*2 <= count && curval < heaps[index*2].priority){
		curidx = index*2;
		curval = heaps[curidx].priority;
	}

	if(index*2+1 <= count && curval < heaps[index*2+1].priority){
		curidx = index*2+1;
		curval = heaps[curidx].priority;
	}

	if(curidx==index) return;
	
	//swapping the value
	data2 temp2;
	temp2 = heaps[index];
	heaps[index] = heaps[curidx];
	heaps[curidx] = temp2;
	heapdown2(curidx);
}

void rmmax(){
printf("%s 's data removed . . . \n", heaps[1].name);
heaps[1] = heaps[count];
count--;
heapdown2(1);
}

void menu2(){
printf("\n\n=== Max Heap ===\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Exit to Lobby\n");
printf("Your Option [1-3] >> ");
}

/////////////////////////////////////////////////////////////

void menu_lobi(){
	printf("\n=== Welcome To Heap Program v.01 ===\n");
	printf(">-> Select 1 option to choose what heap you want to use . . .\n\n");
	printf("1. Min Heap\n");
	printf("2. Max heap\n");
	printf("3. Exit\n");
	printf("Your Option >> ");
}

void lobby();

void minheap(){
	int opsi;
	int count = 0;
	while(true){

		menu1();
		do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 3);

		switch(opsi){
		case 1:
			insertor1();
			break;

		case 2:
			rmmin();
			break;

		case 3:
			printf("You're going to Lobby... Your Data is already saved. . . \n");
			lobby();
			break;
		}

	getchar();
	}
}
void maxheap(){
	int opsi;
	int count = 0;
	while(true){

		menu2();
		do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 3);

		switch(opsi){
		case 1:
			insertor2();
			break;

		case 2:
			rmmax();
			break;

		case 3:
			printf("You're going to Lobby... Your Data is already saved. . . \n");
			lobby();
			break;
		}

	getchar();
	}
}

///////////////////////////////////////////////////////////

void lobby(){
	int opsi;
	int count = 0;
	while(true){

		menu_lobi();
		do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 3);

		switch(opsi){
		case 1:
			minheap();
			break;

		case 2:
			maxheap();
			break;

		case 3:
			printf("Thanks For using This App . . . \n");
			getchar();
			exit(0);
			break;
		}

	getchar();
	}
}
//////////////////////////////////////////////////////////////////////////


int main(){
	int opsi;
	int count = 0;
	while(true){

		menu_lobi();
		do{scanf("%d", &opsi); fflush(stdin);}while(opsi < 1 || opsi > 3);

		switch(opsi){
		case 1:
			minheap();
			break;

		case 2:
			maxheap();
			break;

		case 3:
			printf("Thanks For using This App . . . \n");
			getchar();
			exit(0);
			break;
		}

	getchar();
	}

}

