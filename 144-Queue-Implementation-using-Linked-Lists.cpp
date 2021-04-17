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

struct Queue
{
  Node *front = NULL;
  Node *rear = NULL;
};

void enqueue(Queue &q, int x)
{
  Node *t = new Node;
  if (t == NULL)
    cout << "Queue is Full!" << endl;
  else
  {
    t->data = x;
    t->next = NULL;
    if (q.front == NULL)
      q.front = q.rear = t;
    else
    {
      q.rear->next = t;
      q.rear = t;
    }
  }
}

int dequeue(Queue &q)
{
  int x = -1;
  if (q.front == NULL)
    cout << "Queue is Empty!" << endl;
  else
  {
    Node *p = q.front;
    q.front = q.front->next;
    x = p->data;
    delete p;
  }

  return x;
}

void display(Queue q)
{
  if (q.front == NULL)
    cout << "Queue is Empty!" << endl;
  else
  {
    while (q.front != NULL)
    {
      cout << q.front->data << " ";
      q.front = q.front->next;
    }
    cout << endl;
  }
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Queue q;
  display(q);

  enqueue(q, 10);
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  display(q);

  dequeue(q);
  display(q);
  dequeue(q);
  display(q);
  dequeue(q);
  display(q);
  dequeue(q);
  display(q);

  return 0;
}
