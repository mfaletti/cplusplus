#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
  int data;
  node* left;
  node* right;
};

class BST 
{
  node* root;
  node* find(node*, int);
  node* findMin(node*);
  node* findMax(node*);
  node* remove(node*, int);
  void insert(node*, int);
  void destroyTree(node*);
  void inOrder(node*);
  void preOrder(node*);
  void postOrder(node*);
  void levelOrder(node*);
  bool isLeafNode(node*);

public:
  BST();
  ~BST();
  void insert(int);
  void destroyTree();
  void display();
  node* remove(int);
  node* find(int);
  node* getRoot();
  int maxdepth();
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  destroyTree();
}

void BST::insert(int key)
{
  if (root != NULL) {
    insert(root, key);
  } else {
    root = new node;
    root->data = key;
    root->left = NULL;
    root->right = NULL;
  }
}

void BST::insert(node* leaf, int key)
{
  if (key < leaf->data){
    if (leaf->left != NULL) {
      insert(leaf->left, key);
    } else {
      leaf->left = new node;
      leaf->left->data = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  } else {
    if (leaf->right != NULL) {
      insert(leaf->right, key);
    } else {
      leaf->right = new node;
      leaf->right->data = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

node* BST::find(int key)
{
  // start from the root
  return find(root, key);
}

node* BST::find(node* leaf, int key)
{
  if (leaf == NULL) {
    return NULL;
  } else if (key == leaf->data) {
      return leaf;
  } else if (key < leaf->data){
    return find(leaf->left, key);
  } else return find(leaf->right, key);
}

node* BST::remove(int key)
{
  return remove(root, key);
}

node* BST::remove(node* t, int key)
{
  node* temp;

  // base case with empty node
  if (t == NULL)
    return NULL;

  if (key < t->data) {
    t->left = remove(t->left, key); // look in left subtree
  } else if (key > t->data) {
    t->right = remove(t->right, key); // look in right subtree
  } 
  else {
  // key has been found.
  if (isLeafNode(t)){
    delete t;
    t = NULL;
  } else if (t->right && t->left) {
    // removing a node with two childen is tricky.
    // first we find the minimum leaf on the right side of the node we're deleting.
    // copy the data from the mimimum node to the node we're deleting.
    // finally delete the minimum node in the right subtree. 
    node* temp = findMin(t->right);
    t->data = temp->data;
    t->right = remove(t->right, t->data);
  } else {
    temp = t;
    if (t->right == NULL)
      t = t->left;
    else if (t->left == NULL)
      t = t->right;
      delete temp;
    }
  }
  // eventually returns root node after node removal completes
  return t;
}

bool BST::isLeafNode(node* t)
{
  if (t != NULL && t->left == NULL && t->right == NULL)
    return true;
  else return false;
}

// find minimum 
node* BST::findMin(node* t)
{
  if (t == NULL)
    return t;
  else if (t->left == NULL)
    return t;
  else return findMin(t->left);
}

node* BST::findMax(node* t)
{
  if (t == NULL)
    return t;
  else if (t->right == NULL)
    return t;
  else return findMax(t->right);
}

void BST::destroyTree()
{
  destroyTree(root);
}

void BST::destroyTree(node* leaf)
{
  if (leaf != NULL) {
    destroyTree(leaf->left);
    destroyTree(leaf->right);
  }

  delete leaf;
}

void BST::inOrder(node* t)
{
  if (t != NULL) {
    inOrder(t->left);
    cout << t->data <<" ";
    inOrder(t->right);
  }
}

void BST::preOrder(node* t)
{
  if (t != NULL) {
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
  }
}

void BST::postOrder(node* t)
{
  if (t != NULL) {
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << " ";
  }
}
void BST::display()
{ 
  cout<<"preOrder: ";
  preOrder(root);
  cout<<"\ninOrder: ";
  inOrder(root);
  cout<<"\npostOrder: ";
  postOrder(root);
  cout<<"\nlevelOrder: ";
  levelOrder(root);
}

// time complexity is always O(n). aaverage space complexity is O(n) for worst case. O(1) for best case
void BST::levelOrder(node* t)
{
  if (t != NULL) {
    queue<node*>q;

    // enque root node
    q.push(t);

    // deque root node, enque left and right children. exit loop when queue is empty.
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

node* BST::getRoot()
{
  return root;
}

int main() {

  BST* tree = new BST();
  tree->insert(50);
  tree->insert(19);
  tree->insert(28);
  tree->insert(40);
  tree->insert(16);
  tree->insert(70);
  tree->insert(55);
  tree->insert(56);
  tree->insert(17);
  tree->insert(90);
  tree->display();
  cout<<"\n"<<maxDepth(tree->getRoot());

  delete tree;
  return 0;
}