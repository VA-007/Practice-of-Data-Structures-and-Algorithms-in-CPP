#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

struct Node
{
  int data;
  Node *next;
};

int Hash(int key)
{
  return key % 10;
}

// <===============================>> LINEAR SEARCH IN A LINKED LIST (ITERATIVE) <<==============================>
Node *linearSearchI(Node *p, int key)
{
  while (p != NULL)
  {
    if (p->data == key)
      return p;
    else if (p->data > key)
      return 0;

    p = p->next;
  }

  return 0; // --> Not Found (NULL)
}

// <==========================>> INSERTING AT SORTED POSSITION IN A SORTED LINKED LIST <<===========================>
void insertAtSorted(Node *&p, int x)
{
  Node *t = NULL, *first = p, *q = NULL;
  t = new Node;
  t->data = x;
  t->next = NULL;

  if (p == NULL)
    p = t;
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }

    if (p == first)
    {
      t->next = p;
      p = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
      p = first;
    }
  }
}

// <============================>> DELETING A NODE FROM A LINKED LIST <<==============================>
void deleteNode(Node *&p, int element)
{
  Node *first = p, *q = NULL;

  while (p)
  {
    if (p->data == element)
    {
      break;
    }
    else
    {
      q = p;
      p = p->next;
    }
  }

  if (p == first)
  {
    q = first;
    p = first->next;
    delete q;
  }
  else if (!p)
  {
    cout << "Element not Found! " << endl;
  }
  else
  {
    q->next = p->next;
    delete p;
    p = first;
  }
}

// <===============================>> INSERTING IN HASH TABLE <<===============================>
void insert(vector<Node *> &HT, int key)
{
  int pos = Hash(key);
  insertAtSorted(HT[pos], key);
  cout << key << " is inserted successfully!" << endl;
}

// <===============================>> DELETING FROM HASH TABLE <<===============================>
void Delete(vector<Node *> &HT, int key)
{
  int pos = Hash(key);
  deleteNode(HT[pos], key);
}

// <===============================>> SEARCHING IN HASH TABLE <<===============================>
void search(vector<Node *> &HT, int key)
{
  int pos = Hash(key);
  linearSearchI(HT[pos], key) ? cout << "Found!" << endl : cout << "Not Found!" << endl;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // --> Initialising the Hash table of Node pointer type datatype
  vector<Node *> HT(10, NULL);

  insert(HT, 15);
  insert(HT, 25);
  insert(HT, 35);
  insert(HT, 45);

  search(HT, 45);

  return 0;
}
