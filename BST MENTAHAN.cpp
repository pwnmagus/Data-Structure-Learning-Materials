#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>


struct node{

	int data;
	struct node *left;  //kiri
	struct node *right; //kanan

};

struct node *tree;

//--------[ pake pointer buat operasi ke nodenya ]-------------------------
struct node *masukinAngka(struct node *, int);
struct node *hapusAngka(struct node*, int);
struct node *hapusTree(struct node*);
struct node *cariangkaTerkecil(struct node*);
struct node *cariangkaTerbesar(struct node*);

//--------[ pake void utk bikin tree ama preorder/inorder/postorder ]--------------

void bikin_tree(struct node*);
void preorderTransversal(struct node*);
void inorderTransversal(struct node*);
void postorderTransversal(struct node*);

//-------[ pake int utk operasi tree ]-----------------------------

int totalNodes(struct node*);
int totalExternalnodes(struct node*);
int totalInternalnodes(struct node*);
int tinggi(struct node*);

//==================================================================
int main(){

	int opsi, val;
	struct node *ptr;
	bikin_tree(tree);
	system("cls");

	do{
		printf("\n~~~ BINARY SEARCH TREE SIMULATOR V.01 ~~~~\n");
		printf("1. Masukkan sebuah angka\n");
		printf("2. Preorder Transversal\n");
		printf("3. Inorder Transversal\n");
		printf("4. Postorder Transversal\n");
		printf("5. Cari Angka yang Terbesar\n");
		printf("6. Cari Angka yang Terkecil\n");
		printf("7. Hapus sebuah angka\n");
		printf("8. Hitung jumlah angka dalam nodes\n");
		printf("9. Hitung jumlah angka dalam External Nodes\n");
		printf("10. Hitung jumlah angka dalam Internal Nodes\n");
		printf("11. Cari tinggi treenya\n");
		printf("12. Hapus treenya\n");
		printf("13. Exit\n");
		printf("\nMasukkan opsi: ");
		scanf("%d", &opsi); fflush(stdin);

		switch(opsi){
		//--------------------[ OPSI PILIHAN ]---------------------------
		case 1:
			printf("\nMasukkan angka utk membuat node baru : ");
			scanf("%d", &val); fflush(stdin);
			tree = masukinAngka(tree, val);
			break;

		case 2:
			printf("\nElemen dari tree (secara preorder transversal : \n");
			preorderTransversal(tree);
			break;

		case 3:
			printf("\nElemen dari tree (secara inorder transversal : \n");
			inorderTransversal(tree);
			break;

		case 4:
			printf("\nElemen dari tree (secara postorder transversal : \n");
			postorderTransversal(tree);
			break;

		case 5:
			ptr = cariangkaTerbesar(tree);
			printf("\nAngka Terbesar dari semua elemen : %d\n", ptr->data);
			break;

		case 6:
			ptr = cariangkaTerkecil(tree);
			printf("\nAngka Terkecil dari semua elemen : %d\n", ptr->data);
			break;

		case 7:
			printf("\nMasukkan angka yang ingin dihapus : ");
			scanf("%d", &val); fflush(stdin);
			tree = hapusAngka(tree,val);
			break;

		case 8:
			printf("\n Total angka dari semua nodes : %d\n", totalNodes(tree));
			break;

		case 9:
			printf("\n Total angka dari External nodes : %d\n", totalExternalnodes(tree));
			break;

		case 10:
			printf("\n Total angka dari Internal nodes : %d\n", totalInternalnodes(tree));
			break;

		case 11:
			printf("\nTinggi dari tree = %d\n", tinggi(tree));
			break;

		case 12:
			tree = hapusTree(tree);
			break;

		}
	}while(opsi!=13);
	getchar();

}

//==========================================================
//					Bikin Tree dulu   [pake void ]
//==========================================================
void bikin_tree(struct node *tree){
	tree = NULL;
}
//===========================================================

//===========================================================
//  bikin struct utk masukin angka ke nodes [pake struct node *]
//===========================================================
struct node *masukinAngka(struct node *tree, int val){

	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));

	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;

	if(tree==NULL){
		tree=ptr;
		tree->left = NULL;
		tree->right = NULL;
		}

	else{
		parentptr = NULL;
		nodeptr = tree;
		while(nodeptr!=NULL){

			parentptr=nodeptr;

			if(val<nodeptr->data)
				nodeptr = nodeptr->left;

			else
				nodeptr = nodeptr->right;
			}

			if(val<parentptr->data)
				parentptr->left = ptr;
			else
				parentptr->right = ptr;
		}
	return tree;
}
//=================================================================================
//===== Mencari Angka yg terbesar dan terkecil dari BST ===== [pake struct node *]==

struct node *cariangkaTerkecil(struct node *tree){
	if((tree==NULL) || (tree->left==NULL))
		return tree;
	else
		return cariangkaTerkecil(tree->left);

}

struct node *cariangkaTerbesar(struct node *tree){
	if((tree==NULL) || (tree->right==NULL))
		return tree;
	else
		return cariangkaTerbesar(tree->right);

}
//=======================================================================
// ========== Fungsi utk Hapus Node dan Tree =======[ pake struct node *]============




struct node *hapusAngka(struct node *tree, int val){


	struct node *curr, *parent, *suc, *psuc, *ptr;  //suc = successor, psuc = presuccessor

	if(tree->left == NULL){
		printf("\nTree-nya masih NULL\n");
		return(tree);
	}

	parent=tree;
	curr = tree->left;

	while(curr!=NULL && val!= curr->data){

		parent=curr;
		curr = (val<curr->data)? curr->left:curr->right;
	}

	if(curr==NULL){
		printf("\n Angka yg kamu cari gaada di tree-nya\n");
		return(tree);
	}

	if(curr->left == NULL)
		ptr = curr->right;

	else if(curr->right == NULL)
		ptr = curr->left;

	else{
	//cari inorder succesornya beserta parentnya

		psuc = curr;
		curr = curr->left;

		while(suc->left != NULL){

			psuc = suc;
			suc = suc->left;

		}

		if(curr==psuc){
			//situasi 1
			suc->left = curr->right;
		}
		else{
			//situasi 2
			suc->left = curr->left;
			psuc->left = suc->right;
			suc->right = curr->right;
		}
		ptr = suc;
	}
	//Memasangkan ptr ke parent node
	if(parent->left == curr)
		parent->left = ptr;
	else
		parent->right = ptr;
	free(curr);
	return tree;
}

struct node *hapusTree(struct node *tree){

	if(tree!=NULL){
		hapusTree(tree->left);
		hapusTree(tree->right);
		free(tree);
		tree=NULL;
		}
    return (tree);
}


//=======================================================================
//===============  Transversal SERIES  ============[pake void]===========

void preorderTransversal(struct node *tree){

	if(tree!=NULL){

		printf("%d\t", tree->data);
		preorderTransversal(tree->left);
		preorderTransversal(tree->right);

		}
}

void inorderTransversal(struct node *tree){

	if(tree!=NULL){

		inorderTransversal(tree->left);
		printf("%d\t", tree->data);
		inorderTransversal(tree->right);

		}
}

void postorderTransversal(struct node *tree){

	if(tree!=NULL){

		postorderTransversal(tree->left);
		postorderTransversal(tree->right);
		printf("%d\t", tree->data);

		}
}
//=========================================================

int totalNodes(struct node *tree){

    if(tree==NULL)
        return 0;
    else
        return(totalNodes(tree->left) + totalNodes(tree->right) +1);

}
//==========================================================
int totalExternalnodes(struct node *tree){

    if(tree==NULL)
        return 0;
    else if((tree->left==NULL) && (tree->right==NULL))
        return 1;
    else
        return (totalExternalnodes(tree->left)+totalExternalnodes(tree->right));
}

//=============================================================
int totalInternalnodes(struct node *tree){

    if((tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
        return 0;

    else
        return (totalInternalnodes(tree->left) + totalInternalnodes(tree->right) + 1 );
}

//===================================================================
int tinggi(struct node *tree){

int tinggikiri, tinggikanan;
if(tree==NULL)
    return 0;

else{

    tinggikiri = tinggi(tree->left);
    tinggikanan = tinggi(tree->right);
    if(tinggikiri > tinggikanan)
        return (tinggikiri + 1);
    else
        return (tinggikanan + 1);

}

}
