#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

class circularQueue
{
private:
  int size;
  int front;
  int rear;
  int *arr;

public:
  circularQueue();
  circularQueue(int size);
  ~circularQueue();

  void enqueue(int x);
  int dequeue();
  void display();
};

circularQueue::circularQueue()
{
  front = rear = 0;
  size = 10;
  arr = new int[size];
}

circularQueue::circularQueue(int size)
{
  front = rear = 0;
  this->size = size;
  arr = new int[this->size];
}

circularQueue::~circularQueue()
{
  delete[] arr;
}

void circularQueue::enqueue(int x)
{
  if ((rear + 1) % size == front)
    cout << "Queue is Full!" << endl;
  else
  {
    rear = (rear + 1) % size;
    arr[rear] = x;
  }
}

int circularQueue::dequeue()
{
  int x = -1;
  if (front == rear)
    cout << "Queue is Empty!" << endl;
  else
  {
    front = (front + 1) % size;
    x = arr[front];
  }

  return x;
}

void circularQueue::display()
{
  if (front == rear)
    cout << "Queue is Empty!" << endl;
  else
  {
    for (int i = (front + 1) % size; i != ((rear + 1) % size); i = (i + 1) % size)
      cout << arr[i] << " ";
    cout << endl;
  }
}

class Queue
{
private:
  int size;
  int front;
  int rear;
  int *arr;

public:
  Queue();
  Queue(int size);
  ~Queue();

  void enqueue(int x);
  int dequeue();
  void display();
};

void Queue::enqueue(int x)
{
  if (rear == size - 1)
    cout << "Queue is Full!" << endl;
  else
    arr[++rear] = x;
}

int Queue::dequeue()
{
  int x = -1;

  if (rear == front)
    cout << "Queue is Empty!" << endl;
  else
    x = arr[++front];

  return x;
}

void Queue::display()
{
  if (front == rear)
  {
    cout << "Queue is Empty!" << endl;
  }
  else
  {
    for (int i = front + 1; i <= rear; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
}

Queue::Queue()
{
  front = rear = -1;
  size = 10;
  arr = new int[size];
}

Queue::Queue(int size)
{
  front = rear = -1;
  this->size = size;
  arr = new int[size];
}

Queue::~Queue()
{
  delete[] arr;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  circularQueue q{3};
  q.display();

  q.enqueue(1);
  q.enqueue(21);
  q.enqueue(51);
  q.enqueue(17);
  q.display();

  // q.dequeue();
  // q.display();

  // q.dequeue();
  // q.display();

  // q.dequeue();
  // q.display();

  // q.dequeue();
  // q.display();

  return 0;
}
