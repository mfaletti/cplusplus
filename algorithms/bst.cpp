#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	node* right;
	node* left;
	int data;
};

// add a node to the tree
node* insert(node* &t, int value)
{
	
	if (t == NULL) {
		t = new node;
		t->data = value;
		t->left = NULL;
		t->right = NULL;
	} else {
		if (value < t->data) 
			insert(t->left, value);
		else insert(t->right, value);
	}

	return t;
}

// searches for a value and returns a pointer to the node if found
node* search(node* t, int value)
{
	if (t == NULL)
		return t;
	else {
		if (value < t->data)
			t = search(t->left, value);
		else if (value > t->data)
			t = search(t->right, value);
		return t;
	}
}

// returns the minimum value in the tree
node* findMin(node* t)
{
	if (t == NULL) {
		return t;
	} else if (t->left == NULL)
			return t;
		else return findMin(t->left);
}

// returns the maximum value in the tree
node* findMax(node* t)
{
	if (t == NULL) {
		return t;
	} else if (t->right == NULL)
			return t;
		else return findMax(t->right);
}

// removes a node from the tree
node* remove(node* &t, int value)
{
	if (t == NULL) {
		return NULL;
	} else {
		if (value < t->data) {
			t->left = remove(t->left, value);
		} else if (value > t->data) {
			t->right = remove(t->right, value);
		} else {
			// found the record to remove
			if (t->left == NULL && t->right == NULL) {
				// if this is a leaf node
				delete t;
				return NULL;
			} else if (t->left == NULL) { // if left tree is null, set t to it's right tree
				t = t->right;
			} else if (t->right == NULL) { // if right tree is null, set t to it's left tree
				t = t->left;
			} else {
				node* min = findMin(t->right);
				t->data = min->data;
				t->right = remove(t->right, t->data);
				delete min;
			}
		}
	}

	return t;
}

// inOrder traversal (DFS)
void inOrder(node* t)
{
	if (t != NULL) {
		inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
}

// preOrder traversal (DFS)
void preOrder(node* t)
{
	if (t != NULL) {
		cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
}

// postOrder traversal (DFS)
void postOrder(node* t)
{
	if (t != NULL) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";
	}
}

// time complexity is always O(n). aaverage space complexity is O(n) for worst case.
void levelOrder(node* t)
{

	if (t != NULL) {
		queue<node*>q;

		// enque root node
    q.push(t);

		while(!q.empty()) {
			node* current = q.front();
			cout<<current->data<<" ";
			if (current->left)
				q.push(current->left);
			if (current->right)
				q.push(current->right);
			q.pop(); //remove the element at the front
		}
	}
}

// returns the max root-to-leaf depth of the tree.
// O(n)
int maxDepth(node* t)
{
  if (t == NULL) {
    return 0;
  } else {
    int ld = maxDepth(t->left);
    int rd = maxDepth(t->right);

    return (max(ld, rd) + 1);
  }
}

void display(node* t)
{
	if (t != NULL) {
		preOrder(t);
	}
}

void destroyTree(node* t)
{
	if (t != NULL) {
		destroyTree(t->left);
		destroyTree(t->right);
	}

	delete t;
}

// returns the number of nodes in the tree. 
int count(node* t)
{
	if (t == NULL) {
		return 0;
	} else {
		return (count(t->right) + count(t->left)) + 1;
	}
}

int main()
{
	node* root = NULL;

	// test insert
	insert(root, 50);
  insert(root, 19);
  insert(root, 28);
  insert(root, 40);
  insert(root, 16);
  insert(root, 70);
  insert(root, 55);
  insert(root, 56);
  insert(root, 17);
  insert(root, 90);
	
	//test search
	if (search(root, 11) == NULL) 
		cout<<"No records returned\n";
	else cout<<"found it\n";

	// test remove
	remove(root, 28);

	// test findMin
	cout<<"min value: "<<findMin(root)->data<<"\n";

	// test findMax
	cout<<"max value: "<<findMax(root)->data<<"\n";

	// test maxDepth
	cout<<"max depth: "<<maxDepth(root);

	// test count
	cout<<"\ncount: "<<count(root);

	// test preOrder traversal
	cout<<"\npreOrder: ";
	preOrder(root);

	// test inOrder traversal
	cout<<"\ninOrder: ";
	inOrder(root);

	// test postOrder traversal
	cout<<"\npostOrder: ";
	postOrder(root);

	// test levelOrder traversal
	cout<<"\nlevelOrder: ";
	levelOrder(root);

	// empty the tree
	destroyTree(root);

	return 0;
}