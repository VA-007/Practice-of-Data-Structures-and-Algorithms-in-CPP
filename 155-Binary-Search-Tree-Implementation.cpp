#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

struct Node
{
  Node *left;
  int data;
  Node *right;
};

// =============================>> SEARCHING IN A BINARY SEARCH TREE <<===========================
// --->> Iterative <<---
Node *searchI(Node *t, int key)
{
  while (t)
  {
    if (t->data == key)
      return t;
    else if (key > t->data)
      t = t->right;
    else
      t = t->left;
  }

  return NULL;
}

// --->> Recursive <<---
Node *searchR(Node *t, int key)
{
  if (!t)
    return NULL;
  else if (t->data == key)
    return t;
  else if (key > t->data)
    return searchR(t->right, key);
  else
    return searchR(t->left, key);
}

// =============================>> INSERTING IN A BINARY SEARCH TREE <<===========================
// --->> Iterative <<---
Node *insertI(Node *&t, int key)
{
  Node *head = t, *tail = NULL;

  while (head)
  {
    tail = head;

    if (head->data == key)
      return 0; // Cannot insert as the element is present already hence returning 0
    else if (key < head->data)
      head = head->left;
    else
      head = head->right;
  }

  head = new Node;
  head->data = key;
  head->left = head->right = NULL;

  if (tail) // * To check if there were any nodes in the tree already or not (if BST was empty then tail will be NULL only)
    key > tail->data ? tail->right = head : tail->left = head;
  else
    t = head; // * This ensures that the BST was empty initially then we make the root point on the head node and return the same

  return t;
}

// --->> Recursive <<---
Node *insertR(Node *t, int key)
{
  if (t == NULL)
  {
    Node *p = new Node;
    p->data = key;
    p->right = p->left = NULL;
    return p;
  }
  else if (key < t->data)
    t->left = insertR(t->left, key);
  else
    t->right = insertR(t->right, key);

  return t;
}

// =============================>> DELETING FROM A BINARY SEARCH TREE <<===========================
int inOrderPredecessor(Node *root)
{
  root = root->left;
  while (root->right)
    root = root->right;

  return root->data;
}

int inOrderSucessor(Node *root)
{
  root = root->right;
  while (root->left)
    root = root->left;

  return root->data;
}

Node *deleteNode(Node *root, int key)
{
  if (!root)
    return NULL;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else
  {
    if (!root->left && !root->right)
      root = NULL;
    else if (root->left)
    {
      root->data = inOrderPredecessor(root);
      root->left = deleteNode(root->left, root->data);
    }
    else
    {
      root->data = inOrderSucessor(root);
      root->right = deleteNode(root->right, root->data);
    }
  }

  return root;
}

// ======================>> GENERATING A BINARY SEARCH TREE FROM PRE-ORDER <<======================
// ---------->> Brute O(n^2) <<------------
Node *createFromPreorderBrute(vector<int> pre)
{
  int i = 0;
  Node *root = new Node;
  root->data = pre[i++];
  root->left = root->right = NULL;

  while (i < pre.size())
  {
    insertI(root, pre[i++]);
  }

  return root;
}

// ---------->> Better O(n) <<------------
Node *createFromPreorder(vector<int> &preorder, int parent_value = INT_MAX)
{
  static int idx = 0;

  if (idx == preorder.size() || preorder[idx] > parent_value)
    return NULL;

  int current_value = preorder[idx++];
  Node *temp = new Node;
  temp->data = current_value;
  temp->left = temp->right = NULL;

  temp->left = createFromPreorder(preorder, current_value);
  temp->right = createFromPreorder(preorder, parent_value);

  return temp;
}

// =============================>> TRAVERSING A BINARY SEARCH TREE <<===========================
void inOrder(Node *p)
{
  if (p)
  {
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
  }
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *root = NULL;

  insertI(root, 50);
  insertI(root, 40);
  insertI(root, 30);
  insertI(root, 60);
  insertI(root, 100);

  Node *found = searchI(root, 100);
  found ? cout << "Element found with data: " << found->data << endl : cout << "Element NOT found!" << endl;

  insertI(root, 90);

  inOrder(root);
  cout << endl;

  deleteNode(root, 90);
  inOrder(root);
  cout << endl;

  vector<int> pre{30, 20, 10, 15, 25, 40, 50, 45};
  Node *rootFromPre = createFromPreorder(pre);
  inOrder(rootFromPre);
  cout << endl;

  return 0;
}
