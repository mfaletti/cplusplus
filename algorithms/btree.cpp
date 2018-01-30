#include <iostream>
using namespace std;

struct node {
  int data;
  node* left;
  node* right;
};

class BST 
{
  node* root;
  void insert(node*, int);
  void destroyTree(node*);
  node* find(node*, int);
  node* findMin(node*);
  node* findMax(node*);
  node* remove(node*, int);
  bool isLeafNode(node*);
  void inOrder(node*);

public:
  BST();
  ~BST();
  void insert(int);
  void destroyTree();
  node* remove(int);
  node* find(int);
  void display();
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
  // base case with empty node
  if (t == NULL)
    return NULL;

  if (key < t->data) {
    t->left = remove(t->left, key); // look in left subtree
  } else if (key > t->data) {
    t->right = remove(t->right, key); // look in right subtree
  } else {
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
      if (t->right == NULL) {
        t = t->left;
      } else if (t->left == NULL) {
        t = t->right;
      } else {
      return NULL; // not found
      }
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

void BST::display()
{
  inOrder(root);
}

int main() {

  BST* tree = new BST();
  tree->insert(1);
  tree->insert(2);
  tree->insert(3);
  tree->insert(22);
  tree->insert(28);
  tree->display();
  tree->remove(28);
  tree->display();

  delete tree;
  return 0;
}