#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<fstream>
#include<stdio.h>

using namespace std;

struct store{

	char item[200];
	char type[200];
	int harga;
	int stok;


}x[1000];

int i=0;
int j=0;
int k=0;
int val;
int flag;
char sname[200];

void write(){

	ofstream fp;
	fp.open("marisa_store.txt");

	for(j=0; j<i; j++){
		fp << x[j].item << "#" << x[j].type << "#" << x[j].harga << "#" << x[j].stok;
	}
	fp.close();
}


void read(){
	FILE *fp = fopen("marisa_store.txt", "r");
	if(!fp){
	cout << "File Not Found!";
	getch();
	return ;
	}

	while(!feof(fp)){
		fscanf(fp, "%[^#]#%{^#]#%d#%d\n", &x[i].item, &x[i].type, &x[i].harga, &x[i].stok);
		i++;
	}
	fclose(fp);
}


void menu(){
system("cls");
cout<<"\t$$$$$===========================$$$$$\n";
cout<<"\t===== Marisa's Magic Item Shop  =====\n";
cout<<"\t$$$$$===========================$$$$$\n";
cout<<"\n";
cout<<"\tWelcome to Marisa's Shop... \n\tPlease Pick one option from below...\n";
cout<<"\n";
cout<<"\t1. Store an Item\n";
cout<<"\t2. View Item List\n";
cout<<"\t3. Sort Item List\n";
cout<<"\t4. Buy an Item\n";
cout<<"\t5. Update Item List [Admin]\n";
cout<<"\t6. Delete Item from List\n";
cout<<"\t0. Save And Exit\n";
cout<<"\n";
}

void store(){
system("cls");
cout<<"Store an Item\n";
cout<<"=============\n";
cout<<"\n";
cout<<"Please fill this form first DaZe!\n";
cout<< "Please Input item Name >>> ";
do{
scanf("%[^\n]s", &x[i].item); fflush(stdin);
}while(strlen(x[i].item) < 3 || strlen(x[i].item) > 200 );
cout<< "Please Input item Type [weapon, potion, spellcard] >>> ";
do{
scanf("%[^\n]s", &x[i].type); fflush(stdin);
}while(strcmp(x[i].type, "weapon") !=0 && strcmp(x[i].type, "potion")!=0 && strcmp(x[i].type, "spellcard")!=0 );
cout<< "Please Input item Price [1000-1000000] >>> ";
do{
scanf("%d", &x[i].harga); fflush(stdin);
}while(x[i].harga < 1000 || x[i].harga > 10000000);
cout<< "Please Input item Stock [1-999] >>> ";
do{
scanf("%d", &x[i].stok); fflush(stdin);
}while(x[i].stok < 1 || x[i].stok > 999);

cout<<"Data Successfuly stored to system...\n";
	i++;
	getch();
	system("cls");
}

void view(){
	system("cls");
cout<<"View Item List\n";
cout<<"==============\n";
cout<<"\n";
for(j=0; j<i; j++){
cout<<"===== Item ["<<j+1<<"] ====================\n";
cout<<"Item Name : "<<x[j].item <<"\n";
cout<<"Item Type : "<<x[j].type <<"\n";
cout<<"Item Price: "<<x[j].harga <<"\n";
cout<<"Item Stock: "<<x[j].stok <<"\n";
cout<<"===================================\n";
}
cout<<"Press [ENTER] to continue...\n";
getch();
system("cls");
}

void buy(){}


void sort(){
system("cls");
int sorts;
char temps[2000];

cout<<"Sort Item List\n";
cout<<"==============\n";
cout<<"In Which Way do You Want To sort the data, Daze?\n";
cout<<"1. ASC   [By Name]\n";
cout<<"2. DESC  [By Name]\n";
cout<<"3. ASC   [By Price]\n";
cout<<"4. DESC  [By Price]\n";
cout<<"\n";

cout<<"Your Choice >>> ";
cin>>sorts;

switch(sorts){
case 1:
	for(j=0; j<i; j++){
		for(k=j+1; k<i; k++){
			if(strcmpi(x[j].item, x[k].item)>0){
				store tmp = x[j];
				x[j] = x[k];
				x[k] = tmp;;

			}
		}
	}
	break;

case 2:
	for(j=0; j<i; j++){
		for(k=j+1; k<i; k++){
			if(strcmpi(x[k].item, x[j].item)>0){
			store tmp = x[k];
			x[k]= x[j];
			x[j] = tmp;;
			}
		}
	}
	break;

case 3:
	for(j=0; j<i; j++){
		for(k=j+1; k<i; k++){
			if(x[j].harga > x[k].harga){
			store tmp = x[j];
			x[j] = x[k];
			x[k] = tmp;;
			}
		}
	}
	break;

case 4:
	for(j=0; j<i; j++){
		for(k=j+1; k<i; k++){
			if(x[k].harga > x[j].harga){
			store tmp = x[k];
			x[k] = x[j];
			x[j] = tmp;;
			}
		}
	}
	break;

}

system("cls");
}




int main(){
	int opsi;

	read();
	while(true){

	menu();
	cout<<"\tYour Choice : ";
	cin>>opsi;

	switch(opsi){

	case 1:
		store();
		break;

	case 2:
		view();
		break;

	case 3:
		sort();
		break;

	case 0:
		write();
		exit(0);


			}
		getch();
	}

}
