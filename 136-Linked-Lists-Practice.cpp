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

// <----------------------------- ITERATIVE DISPLAY OF LINKED LIST --------------------------------->
void display(Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

// <----- RECURSIVE DISPLAY OF LINKED LIST ----->
void displayRecursive(Node *p)
{
  if (p != NULL)
  {
    cout << p->data << " ";
    displayRecursive(p->next);
  }
  else
    cout << endl;
}

// <----------------------------- COUNTING NODES IN LINKED LIST ITERATIVELY --------------------------------->
int countNodesI(Node *p)
{
  int nodes = 0;

  while (p != NULL)
  {
    nodes++;
    p = p->next;
  }

  return nodes;
}

// <----- COUNTING NODES IN LINKED LIST RECURSIVELY ----->
int countNodesR(Node *p)
{
  if (p != NULL)
    return countNodesR(p->next) + 1;

  return 0;
}

// <----------------------------- SUM OF ALL ELEMENTS OF A LINKED LIST ITERATIVELY --------------------------------->
int sumI(Node *p)
{
  int sum = 0;

  while (p != NULL)
  {
    sum += p->data;
    p = p->next;
  }

  return sum;
}

// <----- SUM OF ALL ELEMENTS OF A LINKED LIST RECURSIVELY ----->
int sumR(Node *p)
{
  if (p != NULL)
    return p->data + sumR(p->next);

  return 0;
}

// <----------------------------- MAX ELEMENT IN A LINKED LIST ITERATIVELY --------------------------------->
int maxI(Node *p)
{
  int max = INT_MIN;

  while (p != NULL)
  {
    if (p->data > max)
      max = p->data;

    p = p->next;
  }

  return max;
}

// <----- MAX ELEMENT IN A LINKED LIST RECURSIVELY ----->
int maxR(Node *p)
{
  if (p != NULL)
    return max(p->data, maxR(p->next));

  return INT_MIN;
}

// <--------------------------------- LINEAR SEARCH IN A LINKED LIST (ITERATIVE) ------------------------------------->
Node *linearSearchI(Node *p, int key)
{
  while (p != NULL)
  {
    if (p->data == key)
      return p;

    p = p->next;
  }

  return 0; // --> Not Found (NULL)
}

// <----- LINEAR SEARCH IN A LINKED LIST (RECURSIVE) ----->
Node *linearSearchR(Node *p, int key)
{
  if (p != NULL)
  {
    if (p->data == key)
      return p;

    return linearSearchR(p->next, key);
  }

  return 0; // --> Not Found (NULL)
}

// <----- IMPROVING LINEAR SEARCH (MOVE TO HEAD/FRONT) ----->
Node *linearSearchImproved(Node *&p, int key)
{
  Node *q = NULL, *first = p;
  while (p != NULL)
  {
    if (p->data == key)
    {
      q->next = p->next;
      p->next = first;
      return p;
    }
    else
    {
      q = p;
      p = p->next;
    }
  }

  return 0; // --> Not Found (NULL)
}

// <----------------------------------- INSERTING IN A LINKED LIST --------------------------------------->
void insert(Node *&p, int pos, int x)
{
  Node *t = NULL, *first = p;

  if (pos < 0 || pos > countNodesI(p)) // Checking the dataidity of the possition
    return;

  t = new Node;
  t->data = x;

  if (pos == 0)
  {
    t->next = p;
    p = t;
  }
  else if (pos > 0)
  {
    for (int i = 1; i < pos && p; i++) // && p ensures that p does not point to NULL.
      p = p->next;

    if (p) // Checking if p is not NULL
    {
      t->next = p->next;
      p->next = t;
      p = first; // Making p to point to first again as p is passed by reference
    }
  }
}

// <------------------------------ INSERTING AT SORTED POSSITION IN A SORTED LINKED LIST ---------------------------------->
void insertAtSorted(Node *&p, int x)
{
  Node *t = NULL, *first = p, *q = NULL;
  t = new Node;
  t->data = x;
  t->next = NULL;

  if (p == NULL)
  {
    p = t;
  }
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

// <------------------------------ DELETING A NODE FROM A LINKED LIST ---------------------------------->
void deleteNode(Node *&p, int pos)
{
  Node *first = p, *q = NULL;

  if (pos < 1 || pos > countNodesI(p))
    return;
  else
  {
    for (int i = 1; i < pos; i++)
    {
      q = p;
      p = p->next;
    }

    if (p == first)
    {
      p = p->next;
      delete first;
    }
    else
    {
      q->next = p->next;
      delete p;
      p = first;
    }
  }
}

// <------------------------------ CHECKING IF A LINKED LIST IS SORTED OR NOT ---------------------------------->
bool isSorted(Node *p)
{
  int x = INT_MIN;

  while (p != NULL)
  {
    if (p->data < x)
      return false;
    else
    {
      x = p->data;
      p = p->next;
    }
  }

  return true;
}

// <------------------------------ REMOVING DUPLICATES FROM A LINKED LIST ---------------------------------->
void removeDuplicates(Node *p)
{
  Node *q = p;
  p = p->next;

  while (p != NULL)
  {
    if (q->data == p->data)
    {
      q->next = p->next;
      delete p;
      p = q->next;
    }
    else
    {
      q = p;
      p = p->next;
    }
  }
}

// <------------------------------ REVERSING A LINKED LIST (Reversing the Links Method) ---------------------------------->
void reverseViaLinks(Node *&p)
{
  Node *q = NULL, *r = NULL;

  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;

    q->next = r; // Reversing the Links here.
  }
  p = q; // Making p point to the last Node i.e. q, as now last node is the first Node.
}

// <----- Reversing the Elements Method ----->
void reverseViaElements(Node *p)
{
  Node *first = p;
  vector<int> elements;
  int i = 0;

  while (p != NULL)
  {
    elements.push_back(p->data);
    i++;
    p = p->next;
  }
  i--;
  p = first;

  while (p != NULL)
  {
    p->data = elements[i--];
    p = p->next;
  }
}

// <----- Recursive Reverse ----->
Node *recursiveReverse(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *newHead = recursiveReverse(head->next);
  head->next->next = head;
  head->next = NULL;

  return newHead;
}

// <------------------------------ MERGE TWO SORTED LINKED LISTS ---------------------------------->
Node *mergeTwoLists(Node *first, Node *second)
{
  Node *third, *last;

  if (first->data < second->data)
  {
    third = last = first;
    first = first->next;
    last->next = NULL;
  }
  else
  {
    third = last = second;
    second = second->next;
    last->next = NULL;
  }

  while (first != NULL && second != NULL)
  {
    if (first->data < second->data)
    {
      last->next = first;
      last = first;
      first = first->next;
      last->next = NULL;
    }
    else
    {
      last->next = second;
      last = second;
      second = second->next;
      last->next = NULL;
    }
  }

  if (first != NULL)
    last->next = first;
  else
    last->next = second;

  return third;
}

// <------------------------------ CHECKING FOR A LOOP IN A LINKED LIST ---------------------------------->
bool detectLoop(Node *p)
{
  Node *q = p;

  do
  {
    q = q->next;
    p = p->next;
    if (p)
      p = p->next;

    if (p == q)
      return true;

  } while (p != NULL);

  return false;
}

// <------------------------------ DISPLAYING A CIRCULAR LINKED LIST ---------------------------------->
void displayCircularListI(Node *p)
{
  Node *head = p;

  do
  {
    cout << p->data;
    p = p->next;
  } while (p != head);
}

// <----- RECURSIVE DISPLAY OF A CIRCULAR LINKED LIST ----->
void displayCircularListR(Node *p)
{
  Node *head = p;
  static bool flag = false;

  if (p != head || flag == false)
  {
    flag = true;
    cout << p->data;
    displayCircularListR(p->next);
  }
}

// <----------------------------- INSERTING IN A CIRCULAR LINKED LIST --------------------------------->
void insertInCircularList(Node *p, int pos, int x)
{
  Node *first = p;
  Node *t = new Node;
  t->data = x;
  t->next = NULL;

  if (pos == 0) // Inserting before head Node
  {
    if (p == NULL) // Checking if the Head Node is empty then making t as the head node and making its next point to itself
    {
      p = t;
      p->next = t;
    }
    else
    {
      t->next = first;
      while (p->next != first)
        p = p->next;

      p->next = t;
      p = t; // Making p as the head Node
    }
  }
  else // Inserting at any other possition
  {
    for (int i = 1; i < pos && p; i++)
      p = p->next;

    t->next = p->next;
    p->next = t;
    p = first;
  }
}

// <----------------------------- CREATING A SINGLY LINKED LIST --------------------------------->
Node *create(vector<int> arr)
{
  Node *t, *first, *last;
  first = new Node;
  first->data = arr[0];
  first->next = NULL;
  last = first;

  for (int i = 1; i < arr.size(); i++)
  {
    t = new Node;
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }

  return first;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> list1{9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> list2{1, 3, 5, 7, 9};

  Node *start1 = NULL, *start2 = NULL;
  start1 = create(list1);
  start2 = create(list2);

  // display(start);
  // displayRecursive(start1);

  // --> Count
  // cout << countNodesI(start1) << " Nodes" << endl;
  // cout << countNodesR(start1) << " Nodes" << endl;

  // --> Sum
  // cout << "Sum = " << sumI(start1) << endl;
  // cout << "Sum = " << sumR(start1) << endl;

  // --> Finding Maximum
  // cout << "Max Element = " << maxI(start1) << endl;
  // cout << "Max Element = " << maxR(start1) << endl;

  // --> Linear Search
  // cout << "Element fount at position = " << linearSearchI(start1, 3) << endl;
  // cout << "Element fount at position = " << linearSearchR(start1, 3) << endl;

  // --> Improved Linear Search
  // display(start);
  // cout << "Element fount at position = " << linearSearchImproved(start1, 1) << endl;
  // cout << "Element fount at position = " << linearSearchImproved(start1, 5) << endl;
  // display(start1);

  // --> Inserting node in a Linked List
  // display(start1);
  // insert(start1, 0, 66);
  // display(start1);
  // insert(start1, 10, 99);
  // display(start1);
  // insert(start1, 3, 45);
  // display(start1);

  // --> Inserting node at a sorted possition in a Linked List
  // display(start2);
  // insertAtSorted(start2, 66);
  // display(start2);
  // insertAtSorted(start2, 6);
  // display(start2);
  // insertAtSorted(start2, 0);
  // display(start2);

  // --> Deleting a node from a Linked List
  // display(start1);
  // deleteNode(start1, 6);
  // display(start1);
  // deleteNode(start1, 1);
  // display(start1);
  // deleteNode(start1, 7);
  // display(start1);

  // --> Checking if a Linked List is sorted or not
  // display(start2);
  // cout << boolalpha;
  // cout << isSorted(start2) << endl;

  // --> Checking if a Linked List is sorted or not
  // display(start2);
  // removeDuplicates(start2);
  // display(start2);

  // --> Reversing a Linked List
  // display(start2);
  // reverseViaElements(start2);
  // display(start2);
  // reverseViaLinks(start2);
  // display(start2);
  // display(recursiveReverse(start2));

  // --> Merging 2 sorted Linked List
  // vector<int> list3{2, 4, 6, 8, 10};
  // Node *start3 = NULL;
  // start3 = create(list3);
  // cout << "First: ";
  // display(start2);
  // cout << "Second: ";
  // display(start3);
  // cout << "Merged: ";
  // display(mergeTwoLists(start2, start3));

  // --> Merging 2 sorted Linked List
  // vector<int> list3{2, 4, 6, 8, 10};
  // Node *start3 = NULL;
  // start3 = create(list3);
  // cout << "First: ";
  // display(start2);
  // cout << "Second: ";
  // display(start3);
  // cout << "Merged: ";
  // display(mergeTwoLists(start2, start3));

  return 0;
}
