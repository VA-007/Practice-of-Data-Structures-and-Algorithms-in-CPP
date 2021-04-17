#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

struct Stack
{
  int size;
  int top;
  int *S;
};

void display(Stack st)
{
  if (st.top == -1)
    cout << "Stack Empty!" << endl;
  else
  {
    for (int i = st.top; i >= 0; i--)
    {
      cout << st.S[i] << " ";
    }
    cout << endl;
  }
}

void push(Stack &st, int x)
{
  if (st.top == st.size - 1)
    cout << "Stack Overflow!" << endl;
  else
  {
    st.top++;
    st.S[st.top] = x;
  }
}

int pop(Stack &st)
{
  int x = -1;
  if (st.top == -1)
    cout << "Stack Underflow!" << endl;
  else
  {
    x = st.S[st.top--];
  }

  return x;
}

int peek(Stack st, int pos)
{
  int x = -1;
  if ((st.top - pos + 1 < 0) || (st.top - pos + 1 > st.size))
    cout << "Invalid Possiton!" << endl;
  else
    x = st.S[st.top - pos + 1];

  return x;
}

int stackTop(Stack st)
{
  int x = -1;
  if (st.top == -1)
    cout << "Stack Empty!" << endl;
  else
    x = st.S[st.top];

  return x;
}

bool isEmpty(Stack st)
{
  if (st.top == -1)
    return true;
  return false;
}

bool isFull(Stack st)
{
  if (st.top == -1)
    return false;
  return true;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Stack st;
  cout << "Enter the size of the Stack: " << flush;
  cin >> st.size;
  st.S = new int[st.size];
  st.top = -1;

  cout << stackTop(st) << endl;

  display(st);
  push(st, 1);
  push(st, 2);
  push(st, 3);
  push(st, 3);
  push(st, 3);
  display(st);

  cout << pop(st) << endl;
  cout << pop(st) << endl;
  cout << pop(st) << endl;
  cout << pop(st) << endl;
  cout << pop(st) << endl;
  display(st);

  cout << peek(st, 1) << endl;
  cout << stackTop(st) << endl;

  cout << boolalpha;
  cout << isEmpty(st) << endl;
  cout << isFull(st) << endl;

  return 0;
}
