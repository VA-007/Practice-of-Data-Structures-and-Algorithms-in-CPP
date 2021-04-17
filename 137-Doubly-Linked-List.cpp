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
  Node *prev;
  int data;
  Node *next;
};

// <----- Displaying a Doubly Linked List ----->
void display(Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

// <----- Counting Nodes in a Doubly Linked List ----->
int countNodes(Node *p)
{
  int total = 0;
  while (p != NULL)
  {
    total++;
    p = p->next;
  }

  return total;
}

// <----- Inserting in a Doubly Linked List ----->
void insertInDoubly(Node *&p, int pos, int x)
{
  Node *t = NULL, *first = p;

  if (pos < 0 || pos > countNodes(p))
    return;

  if (pos == 0)
  {
    t = new Node;
    t->data = x;
    t->prev = NULL;
    t->next = p;
    p->prev = t;
    p = t;
  }
  else
  {
    t = new Node;
    t->data = x;

    for (int i = 1; i < pos && p; i++)
      p = p->next;

    t->next = p->next;
    t->prev = p;
    if (p->next)
      p->next->prev = t;
    p->next = t;

    p = first;
  }
}

// <----- Deleting a Node from a Doubly Linked List ----->
void deleteFromDoubly(Node *&p, int pos)
{
  Node *first = p;

  if (pos < 1 || pos > countNodes(p))
    return;

  if (pos == 1)
  {
    p = p->next;
    if (p)
      p->prev = NULL;

    delete first;
  }
  else
  {
    for (int i = 1; i < pos; i++)
      p = p->next;

    p->prev->next = p->next;
    if (p->next)
      p->next->prev = p->prev;

    delete p;
    p = first;
  }
}

// <----- Reversing a Doubly Linked List ----->
void reverseDoublyList(Node *&p)
{
  Node *first = NULL;

  while (p != NULL)
  {
    Node *temp = p->next;
    p->next = p->prev;
    p->prev = temp;

    first = p;

    p = p->prev; // Moving on to the next Node

    if (p == NULL)
    {
      p = first; // Making the last Node as the first Node
      return;
    }
  }
}

// <----- Creating a Doubly Linked List ----->
Node *create(vector<int> arr)
{
  Node *first = NULL, *last = NULL, *temp = NULL;
  first = new Node;
  first->prev = NULL;
  first->data = arr[0];
  first->next = NULL;
  last = first;

  for (int i = 1; i < arr.size(); i++)
  {
    temp = new Node;
    temp->prev = last;
    temp->data = arr[i];
    temp->next = NULL;
    last->next = temp;
    last = temp;
  }

  return first;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr{1, 3, 5, 7, 9};
  Node *start1 = create(arr);

  // --> Counting Nodes
  // cout << countNodes(start1) << endl;

  // --> Inserting into doubly Linked List
  // display(start1);
  // insertInDoubly(start1, 2, 4);
  // display(start1);
  // insertInDoubly(start1, 0, 34);
  // display(start1);
  // insertInDoubly(start1, 7, 34);
  // display(start1);

  // --> Deleting Node from doubly Linked List
  // display(start1);
  // deleteFromDoubly(start1, 2);
  // display(start1);
  // deleteFromDoubly(start1, 1);
  // display(start1);
  // deleteFromDoubly(start1, 4);
  // display(start1);

  // --> Reversing doubly Linked List
  display(start1);
  reverseDoublyList(start1);
  display(start1);

  return 0;
}
