/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Tree
* Tgl : 15 05 2019
*/

#include<iostream>
using namespace std;

struct Simpul {
    int data;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cin >> pBaru->data;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
        Root = pBaru;
    else if (pBaru->data < Root->data)
        insertBST(Root->left,pBaru);
    else if (pBaru->data > Root->data)
        insertBST(Root->right,pBaru);
    else
        cout<<"Already Exist!!!";
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout << Root->data <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->data <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->data <<endl;
    }
}

int height(Tree Root) {
	if (Root==NULL)	return 0;
	else {
		int lHeight = height(Root->left);
		int rHeight = height(Root->right);
		
		if (lHeight > rHeight) return (lHeight + 1);
		else return (rHeight + 1);
	}
}

void givenLevel(Tree Root, int level) {
	if (Root == NULL) return;
	if (level == 1) cout << Root->data << " ";
	else if (level>1) {
		givenLevel(Root->left,level-1);
		givenLevel(Root->right,level-1);
	}
}

void levelOrder(Tree Root) {
	int h = height(Root);
	for (int i = 1; i <= h; i++) {
		cout << i << ": ";
		givenLevel(Root, i);
		cout << endl;
	} 
}

void depthOrder (Tree Root) {
	int h=height(Root);
	for (int i = 1; i <= h; i++) {
		cout << i - 1 << ": ";
		givenLevel(Root, i);
		cout << endl;
	} 
}

Tree searchFather(Tree Root, int key) {
	if (Root==0 || Root->data==key) return Root;
	else if (Root->data<key) return searchFather(Root->left,key);
	else return searchFather(Root->right,key);
}

int main () {
	Tree Root = NULL;
	pointer p;
	int pil, n, key;
	char ans;
	
    
    do{
		cout << "---------------MENU---------------"<<endl;
		cout << "1. Insert" << endl;
		cout << "2. PreOrder" << endl;
		cout << "3. InOrder" << endl;
		cout << "4. PostOrder" << endl;
		cout << "5. Depth and Node(s)" << endl;
		cout << "6. Level and Node(s)" << endl;
		cout << "7. Father & Child" << endl;
		cout << "8. Exit" << endl;
		cout << "Input your choice : "; cin >> pil;
		system("CLS");

		switch(pil){
			case 1:
				cout << "Masukkan banyak data : "; cin >> n;
				cout << "Input data : "; 
				for (int i = 0; i < n; i++){
					CreateSimpul(p);
					insertBST(Root,p);
				}
				break;
			
			case 2:
				cout << "Traversal PreOrder" << endl;
				preOrder(Root);
				break;
			
			case 3:
				cout << "Traversal InOrder" << endl;
				inOrder(Root);
				break;
			
			case 4:
				cout << "Traversal PostOrder" << endl;
				postOrder(Root);
				break;
	
			case 5:
				cout << "Depth and Node(s)" << endl;
				depthOrder(Root);
				break;
	
			case 6:
				cout << "Level and Node(s)" << endl;
				levelOrder(Root);
				break;
				
			case 7:
				cout << "Father & Child" << endl;
				cout << "Insert Father: "; cin >> key;
				preOrder(searchFather(Root,key));
				break;
				
			case 8:
				return 0;
				break;
				
			default:
				cout<<"Invalid choice!!!"<<endl;
				break;
		}
		cout<<"Back to menu?(Y/N)"; cin>>ans;
	} while(ans == 'y' || ans == 'Y');
}
