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

// --> Making top as a global variable so that the Stack can access it directly
Node *top = NULL;

void display(Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void push(int x)
{
  Node *t = new Node;
  if (!t)
    cout << "Stack Overflow!";
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
}

int pop()
{
  int x = -1;
  if (top == NULL)
    cout << "Stack Underflow";
  else
  {
    Node *t = top;
    top = top->next;
    x = t->data;
    delete t;
  }
  return x;
}

int peek(int pos, int totalNodes)
{
  int x = -1;
  if (pos < 1 || pos > totalNodes)
    cout << "Invalid Index!";
  else
  {
    Node *t = top;
    for (int i = 1; i < pos; i++)
      t = t->next;

    x = t->data;
  }

  return x;
}

int stackTop()
{
  if (!top)
  {
    cout << "Stack is Empty!";
    return -1;
  }
  return top->data;
}

bool isEmpty()
{
  return top ? 0 : 1;
}

bool isFull()
{
  Node *t = new Node;
  if (t)
  {
    delete t;
    return 0;
  }
  return 1;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node *p = NULL;
  top = p;

  // cout << boolalpha;
  // cout << isEmpty() << endl;

  display(top);
  push(34);
  push(35);
  push(36);
  push(37);
  push(38);
  display(top);

  // cout << stackTop() << endl;

  // pop();
  // display(top);
  // pop();
  // display(top);

  // cout << peek(3, 5) << endl;
  // cout << peek(5, 5) << endl;
  // cout << peek(-3, 5) << endl;

  // cout << boolalpha;
  // cout << isEmpty() << endl;
  // cout << isFull() << endl;

  return 0;
}
