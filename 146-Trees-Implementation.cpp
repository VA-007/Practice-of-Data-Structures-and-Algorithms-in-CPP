#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

// <----------------------------- class for Tree Node --------------------------------->
class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;
};

// <----------------------------- CLASS FOR TREE IMPLEMENTATION --------------------------------->
class Tree
{
public:
  Node *root;

  Tree()
  {
    root = NULL;
  }

  void createTree();

  void preOrderTraversalR(Node *p);
  void inOrderTraversalR(Node *p);
  void postOrderTraversalR(Node *p);

  void preOrderTraversalI(Node *p);
  void inOrderTraversalI(Node *p);
  void postOrderTraversalI(Node *p);

  void levelOrderTraversal(Node *p);

  int height(Node *p);
  int countNodes(Node *p);
  int sumOfNodes(Node *p);
  int countLeafNodes(Node *p);
  int countNonLeafNodes(Node *p);
};

// <----------------------------- MEMBER METHODS IMPLEMENTATION OF THE TREE CLASS --------------------------------->

// <------------- Create Tree ------------>
void Tree::createTree()
{
  Node *p = NULL, *t = NULL;
  queue<Node *> q;
  int x;

  root = new Node;
  cout << "Enter the root value: " << flush;
  cin >> x;
  root->data = x;
  root->rchild = root->lchild = NULL;
  q.push(root);

  while (!q.empty())
  {
    p = q.front();
    q.pop();

    cout << "Enter the left child for " << p->data << " : " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.push(t);
    }

    cout << "Enter the right child for " << p->data << " : " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.push(t);
    }
  }
}

// <------------- Pre-Order Traversals ------------>
void Tree::preOrderTraversalR(Node *p)
{
  if (p)
  {
    cout << p->data << " ";
    preOrderTraversalR(p->lchild);
    preOrderTraversalR(p->rchild);
  }
}

void Tree::preOrderTraversalI(Node *p)
{
  stack<Node *> st;
  Node *t = p;

  while ((!st.empty()) || t != NULL)
  {
    if (t)
    {
      cout << t->data << " " << flush;
      st.push(t);
      t = t->lchild;
    }
    else
    {
      t = st.top();
      st.pop();
      t = t->rchild;
    }
  }
}

// <------------- In-Order Traversals ------------>
void Tree::inOrderTraversalR(Node *p)
{
  if (p)
  {
    inOrderTraversalR(p->lchild);
    cout << p->data << " ";
    inOrderTraversalR(p->rchild);
  }
}

void Tree::inOrderTraversalI(Node *p)
{
  stack<Node *> st;
  Node *t = p;

  while ((!st.empty()) || t != NULL)
  {
    if (t)
    {
      st.push(t);
      t = t->lchild;
    }
    else
    {
      t = st.top();
      st.pop();
      cout << t->data << " ";

      t = t->rchild;
    }
  }
}

// <------------- Post-Order Traversals ------------>
void Tree::postOrderTraversalR(Node *p)
{
  if (p)
  {
    postOrderTraversalR(p->lchild);
    postOrderTraversalR(p->rchild);
    cout << p->data << " ";
  }
}

// void Tree::postOrderTraversalI(Node *t)
// {
//   stack<Node *> st;
//   long int tempAddr;

//   while ((!st.empty()) || t != NULL)
//   {
//     if (t)
//     {
//       st.push(t);
//       t = t->lchild;
//     }
//     else
//     {
//       tempAddr = st.top();
//       st.pop();

//       if (tempAddr > 0)
//       {
//         st.push(-(Node *)tempAddr);
//         t = ((Node *)tempAddr)->rchild;
//       }
//       else
//       {
//         cout << ((Node *)tempAddr)->data << " ";
//         t = NULL;
//       }
//     }
//   }
// }

// <------------- Level-Order Traversals ------------>
void Tree::levelOrderTraversal(Node *p)
{
  queue<Node *> q;

  cout << p->data << " ";
  q.push(p);

  while (!q.empty())
  {
    Node *p = q.front();
    q.pop();

    if (p->lchild)
    {
      cout << p->lchild->data << " ";
      q.push(p->lchild);
    }

    if (p->rchild)
    {
      cout << p->rchild->data << " ";
      q.push(p->rchild);
    }
  }
}

// <------------- Other Function ------------>
int Tree::height(Node *root)
{
  int x = 0, y = 0;

  if (!root)
    return 0;

  x = height(root->lchild);
  y = height(root->rchild);

  // return x > y ? x + 1 : y + 1;
  return max(x, y) + 1;
}

int Tree::countNodes(Node *p)
{
  int x, y;

  if (p)
  {
    x = countNodes(p->lchild);
    y = countNodes(p->rchild);

    return x + y + 1;
  }

  return 0;
}

int Tree::countLeafNodes(Node *p)
{
  int x, y;

  if (p)
  {
    x = countLeafNodes(p->lchild);
    y = countLeafNodes(p->rchild);

    if (p->lchild == NULL && p->rchild == NULL)
      return x + y + 1;

    return x + y;
  }

  return 0;
}

int Tree::countNonLeafNodes(Node *p)
{
  int x, y;

  if (p)
  {
    x = countNonLeafNodes(p->lchild);
    y = countNonLeafNodes(p->rchild);

    if (p->lchild != NULL && p->rchild != NULL)
      return x + y + 1;

    return x + y;
  }

  return 0;
}

int Tree::sumOfNodes(Node *p)
{
  int x, y;

  if (p)
  {
    x = sumOfNodes(p->lchild);
    y = sumOfNodes(p->rchild);

    return x + y + p->data;
  }

  return 0;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Tree t;
  t.createTree();

  t.preOrderTraversalI(t.root);
  cout << endl;
  // t.preOrderTraversalR(t.root);
  // cout << endl;

  t.inOrderTraversalR(t.root);
  cout << endl;
  // t.inOrderTraversalI(t.root);
  // cout << endl;

  t.postOrderTraversalR(t.root);
  cout << endl;
  // t.postOrderTraversalI(t.root);
  // cout << endl;

  t.levelOrderTraversal(t.root);
  cout << endl;

  cout << "Height of the tree: " << t.height(t.root) << endl;
  cout << "Total no. Nodes: " << t.countNodes(t.root) << endl;
  cout << "Sum of all the Nodes: " << t.sumOfNodes(t.root) << endl;
  cout << "No. of Non-Leaf Nodes: " << t.countNonLeafNodes(t.root) << endl;
  cout << "No. of Leaf Nodes: " << t.countLeafNodes(t.root) << endl;

  return 0;
}
