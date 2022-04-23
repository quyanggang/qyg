#include <iostream>
using namespace std;
typedef struct node 
{
	struct node* lChild;
	struct node* rChild;
	char data;
}

BiTreeNode, * BiTree;

void createBiTree(BiTree& T) 
{
	char c;
	cin >> c;
	if (c == '#')
	{
		T = NULL;
		return;
	}
	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree(T->lChild);
		createBiTree(T->rChild);
	}
}

void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";
		preTraverse(T->lChild);
		preTraverse(T->rChild);
	}
}

void midTraverse(BiTree T)
{
	if (T) 
	       {
		midTraverse(T->lChild);
		cout << T->data << " ";
		midTraverse(T->rChild);
	}
}

void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lChild);
		postTraverse(T->rChild);
		cout << T->data << " ";
	}
}

int main() 
{
	BiTree T;
	createBiTree(T);
	preTraverse(T);
	cout << endl;
	midTraverse(T);
	cout << endl;
	postTraverse(T);
	cout << endl;
	system("pause");
	return 0;
}