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
  int height;
} *root = NULL; // --> Declaring an root variable here only as a global variable to make it easy for us to access it.

// =============================>> UTILITY FUNCTIONS <<===========================
// -------->> Height of the tree <<--------
int nodeHeight(Node *p)
{
  int hl, hr;

  if (p->left)
    hl = p->left->height; // Directly using the height variable as its stored for every node in the Node structure
  else
    hl = 0;

  if (p->right)
    hr = p->right->height;
  else
    hr = 0;

  return hl > hr ? hl + 1 : hr + 1;
}

// -------->> Finding balance factor of the tree <<--------
int BalanceFactor(Node *p)
{
  int hl, hr;

  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl - hr;
}

// =============================>> PERFORMING ROTATIONS IN AN AVL TREE <<===========================
// ---------->> LL-Rotation <<----------
Node *LLrotation(Node *t)
{
  Node *tl = t->left;
  Node *tlr = t->left->right;

  tl->right = t;
  t->left = tlr;

  // --> Updating the Heights
  t->height = nodeHeight(t);
  tl->height = nodeHeight(tl);

  if (root == t)
    root = tl;

  return tl;
}

// ---------->> LR-Rotation <<----------
Node *LRrotation(Node *t)
{
  Node *tlr = t->left->right;
  Node *tl = t->left;

  t->left = tlr->right;
  tl->right = tlr->left;

  tlr->right = t;
  tlr->left = tl;

  // --> Updating the Heights
  t->height = nodeHeight(t);
  tl->height = nodeHeight(tl);
  tlr->height = nodeHeight(tlr);

  if (t == root)
    root = tlr;

  return tlr;
}

// ---------->> RR-Rotation <<----------
Node *RRrotation(Node *t)
{
  Node *tr = t->right;
  Node *trl = t->right->left;

  tr->left = t;
  t->right = trl;

  // --> Updating the Heights
  t->height = nodeHeight(t);
  tr->height = nodeHeight(tr);

  if (root == t)
    root = tr;

  return tr;
}

// ---------->> RL-Rotation <<----------
Node *RLrotation(Node *t)
{
  Node *tr = t->right;
  Node *trl = t->right->left;

  t->right = trl->left;
  tr->left = trl->right;

  trl->right = tr;
  trl->left = t;

  // --> Updating the Heights
  t->height = nodeHeight(t);
  tr->height = nodeHeight(tr);
  trl->height = nodeHeight(trl);

  if (t == root)
    root = trl;

  return trl;
}

// =============================>> INSERTING IN AN AVL TREE <<===========================
Node *insertR(Node *t, int key)
{
  if (t == NULL)
  {
    Node *p = new Node;
    p->data = key;
    p->right = p->left = NULL;
    p->height = 1;
    return p;
  }
  else if (key < t->data)
    t->left = insertR(t->left, key);
  else if (key > t->data)
    t->right = insertR(t->right, key);

  t->height = nodeHeight(t);

  // --> Checking if the tree is balanced or not by checking the Balance factors
  if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == 1)
    return LLrotation(t);
  else if (BalanceFactor(t) == 2 && BalanceFactor(t->left) == -1)
    return LRrotation(t);
  else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == -1)
    return RRrotation(t);
  else if (BalanceFactor(t) == -2 && BalanceFactor(t->right) == 1)
    return RLrotation(t);

  return t;
}

// =============================>> TRAVERSING A AVL TREE <<===========================
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

  root = insertR(root, 20);
  insertR(root, 30);
  insertR(root, 25);

  inOrder(root);
  cout << endl;

  return 0;
}