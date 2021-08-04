#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Tree                                              
{                            
	int info;
	string name;
	Tree *right, *left;
};

Tree* AddNewNode(Tree* root, int key, string name)
{
	if (root == NULL) 
	{
		Tree* ptr = new Tree;
		ptr->info = key;
		ptr->name = name;
		ptr->right = NULL;                    
		ptr->left = NULL;
		cout << "Root is created!" << endl;
		return ptr;
	}

	Tree* t = root, *prev = NULL;
	int sign = 0;
	while (t != NULL)
	{
		prev = t;
		if (key < t->info)
		{
			t = t->left;
		}
		else if (key == t->info)
		{
			cout << "Enter the key that is possible to be entered" << endl;
			return root;
		}
		else 
		{
			t = t->right;		
		}
	}
	Tree* ptr = new Tree;
	ptr->info = key;
	ptr->name = name;
	ptr->right = NULL;                     
	ptr->left = NULL;
	if (key < prev->info) prev->left = ptr;
	else if (key > prev->info) prev->right = ptr;
	return root;
}

void Del_Tree(Tree* root) 
{
	if (root != NULL)
	{
		Del_Tree(root->left); 		
		Del_Tree(root->right); 			
		delete root;
	}
}

void Print(Tree** Tree, int l) 
{
	int i;
	if (*Tree != NULL)
	{
		Print(&((*Tree)->left), l + 1);
		for (i = 1; i <= l; i++) {
			cout << "   ";
		}
		cout << "(" << (*Tree)->info << ")" << (*Tree)->name << endl;
		Print(&((**Tree).right), l + 1);
	}
}

void CollectDataFromTree(vector<Tree*>&nodes, Tree* root)
{
	if (root->left) CollectDataFromTree(nodes, root->left);
	if (root)  nodes.push_back(root);
	if (root->right) CollectDataFromTree(nodes, root->right);
}

void MakeTreeBalanced(Tree** root, int n, int k, vector<Tree*> nodes)  
{
	if (n == k) 
	{
		*root = NULL;
		return;
	}
	else 
	{
		int m = (n + k) / 2;
		*root = new Tree;
		(*root)->info = nodes[m]->info;
		(*root)->name = nodes[m]->name;
		MakeTreeBalanced(&(*root)->left, n, m, nodes);
		MakeTreeBalanced(&(*root)->right, m + 1, k, nodes);
	}
}

Tree* FindWithKey (Tree *root, int key)
{
	if (key < root->info)
	{
		if (root->left) FindWithKey(root->left, key);
		else return NULL;
	}

	else if (key > root->info)
	{
		if (root->right) FindWithKey(root->right, key);
		else return NULL;
	}

	else if (key == root->info)
	{
		return root;
	}
}

Tree* Del_Info(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key)  Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) {				
		cout << "There is no element with key like this!" << endl;
		return root;
	}
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)  R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Del->left;
			}
		}
	if (Del == root) root = R;			
	else
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;				
		else	Prev_Del->right = R;				
	delete Del;
	return root;
}

int counter = 0;

void MainTask(Tree* root)
{
	if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
	{
		counter++;
		if (root->right) MainTask(root->right);
		if (root->left) MainTask(root->left);
	}

	else if (root->left == NULL && root->right == NULL)
	{
		return;
	}
	
	else if (root->left != NULL && root->right != NULL)
	{
		MainTask(root->right);
		MainTask(root->left);
	}
}

int main()
{
	Tree* root = NULL, * ptr;
	bool endsign = true;
	int find, amount2, choise, key;
	vector<Tree*> nodes;
	string name;
	do
	{
		cout << "1) To add new elements to tree" << endl
			<< "2) To view tree" << endl
			<< "3) To find with key"<< endl
			<< "4) To clean the tree" << endl
			<< "5) To reset tree to balanced" << endl
			<< "6) To delete node with key" << endl 
			<< "7) To do main task" << endl
			<< "8) To end:: " << endl;
		
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Enter amount of elements you want to include : ";
			cin >> amount2;
			for (int i = 0; i < amount2; i++)
			{
				cout << "Enter key of new element : ";
				cin >> key;
				cout << "Enter name of new element : ";
				cin >> name;
				cout << "Element added!" << endl;
				root = AddNewNode(root, key, name);
			}
		break;
		case 2:
			if (root != NULL)
			{
				cout << "Your tree :: " << endl << "------------------------------------" << endl;
				Print(&root, 0);
				cout << "------------------------------------" << endl;
			}
			else cout << "Tree is clear! Add something" << endl;
			break;
		case 3:
			if (root == NULL)
			{
				cout << "Tree is  empty!" << endl;
				break;
			}
			cout << "Enter the key you want to find : ";
			cin >> find;
			ptr = FindWithKey(root, find);
			if (ptr != NULL) cout << "Founded information : " << endl
			 << "Amount : " <<  ptr->info << " ; Name : " << ptr->name << endl;
			else cout << "Nothing found!" << endl;
			ptr = NULL;
			break;
		case 4: 
			Del_Tree(root);
			root = NULL;
			cout << "Tree is clear, Root points to NULL, continue working" << endl;
			break;
		case 5:
			if (root == NULL)
			{
				cout << "Tree is clear, enter something " << endl;
				break;
			}
			CollectDataFromTree(nodes, root);
			root = NULL;
			MakeTreeBalanced(&root, 0, nodes.size(), nodes);
			nodes.clear();
			cout << "New balanced tree is created, keep working!" << endl;
			break;
		case 6:
			cout << "Enter key of element you want to delete : ";
			cin >> key;
			Del_Info(root, key);
			break;
		case 7:
			if (root == NULL)
			{
				cout << "Tree is empty!" << endl;
				break;
			}
			MainTask(root);
			cout << " Amount of one-son nodes : " << counter << endl;
			counter = 0;
			break;
		case 8:
			Del_Tree(root);
			cout << "The End" << endl;
			endsign = false;
		default:
			cout << "Enter something possible to work with !!!!" << endl;
			break;
		}
	} while (endsign);
	
	return 0;
}