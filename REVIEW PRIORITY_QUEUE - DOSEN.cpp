#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct passenger
{
	char name[21];
	int age;
	char status[8];

	int priority;
	struct passenger *next;
} *front, *rear, *curr;

void enqueue(char name[], int age, char status[], int p)
{
	struct passenger *node = (struct passenger*)malloc(sizeof(struct passenger));
	strcpy(node->name, name);
	node->age = age;
	strcpy(node->status, status);
	node->priority = p;

	if(rear == NULL)
	{
		node->next = NULL;
		front = rear = node;
	}
	else if(front->priority > node->priority)
	{
		node->next = front;
		front = node;
	}
	else if(rear->priority <= node->priority)
	{
		rear->next = node;
		node->next = NULL;
		rear = node;
	}
	else
	{
		curr = front;
		while(curr->next->priority <= node->priority)
		{
			curr = curr->next;
		}

		node->next = curr->next;
		curr->next = node;
	}
}

void dequeue()
{
	if(front == NULL)
		return;

	printf("Please enter the airplane, Mr./Ms. %s\n\n",front->name);

	if(front == rear)
	{
		free(front);
		front = rear = NULL;
	}
	else
	{
		curr = front;
		front = front->next;
		free(curr);
		curr = NULL;
	}
}

void printData()
{
	printf("\n\n\n\n\n");
	printf("%-20s %3s %s\n","Name", "Age", "Status");

	curr = front;
	int count = 0;
	int maxAge = 0;
	int minAge = 100;

	while(curr != NULL)
	{
		count++;
		printf("%-20s %3d %s\n",curr->name, curr->age, curr->status);

		if(maxAge < curr->age)
			maxAge = curr->age;
		if(minAge > curr->age)
			minAge = curr->age;

		curr = curr->next;
	}

	printf("Total passenger: %d\n",count);
	printf("Maximum passenger age: %d\n",maxAge);
	printf("Minimum passenger age: %d\n",minAge);
}

void printMenu()
{
	printf("\n\n");

	printf("1. Input new passenger\n");
	printf("2. Remove passenger\n");
	printf("3. Exit\n");
}

void enterPassenger()
{
	char name[21];
	int age;
	char status[8];
	int priority;

	printf("Name: ");
	scanf("%[^\n]",name);
	while(getchar() != '\n');

	printf("Age: ");
	scanf("%d",&age);
	while(getchar() != '\n');

	printf("Status: ");
	scanf("%[^\n]",status);
	while(getchar() != '\n');

	if(strcmp(status,"VIP") == 0)
	{
		priority = 1;
	}
	else if(age > 55)
	{
		priority = 2;
		strcpy(status,"Elderly");
	}
	else
	{
		priority = 3;
	}

	enqueue(name, age, status, priority);
}

int main()
{
	int choice;
	front = rear = NULL;

	do
	{
		printData();
		printMenu();
		printf("Choice: ");
		scanf("%d",&choice);
		while(getchar() != '\n');

		if(choice == 1)
		{
			enterPassenger();
		}
		else if(choice == 2)
		{
			dequeue();
		}
	}
	while(choice != 3);

	getchar();

}
