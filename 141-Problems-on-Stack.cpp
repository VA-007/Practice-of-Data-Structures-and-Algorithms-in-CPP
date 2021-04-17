#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

bool isOperand(char x)
{
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return false;

  return true;
}

int precedence(char x)
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;

  return 0;
}

string convert(string infix)
{
  string postfix;
  stack<char> st; // Using C++ STL library for using Stack and implementing

  for (int i = 0; i < infix.size(); i++)
  {
    if (isOperand(infix[i]))
      postfix += infix[i];
    else
    {
      if (precedence(infix[i]) > precedence(st.top()))
        st.push(infix[i]);
      else
      {
        postfix += st.top();
        st.pop();
        i--;
      }
    }
  }

  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

int eval(string postfix)
{
  stack<int> st;
  int x1, x2, r;

  for (int i = 0; i < postfix.size(); i++)
  {
    if (isOperand(postfix[i]))
      st.push(postfix[i] - '0');
    else
    {
      x2 = st.top();
      st.pop();
      x1 = st.top();
      st.pop();

      switch (postfix[i])
      {
      case '+':
        r = x1 + x2;
        st.push(r);
        break;

      case '-':
        r = x1 - x2;
        st.push(r);
        break;

      case '*':
        r = x1 * x2;
        st.push(r);
        break;

      case '/':
        r = x1 / x2;
        st.push(r);
        break;

      default:
        break;
      }
    }
  }

  return st.top();
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s = "7+4*9/3";
  string ans = convert(s);
  cout << s << endl;
  cout << ans << endl;

  int res = eval(ans);
  cout << res << endl;

  return 0;
}
