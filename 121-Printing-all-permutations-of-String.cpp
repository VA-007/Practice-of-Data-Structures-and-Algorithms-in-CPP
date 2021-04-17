#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

void swap(char &a, char &b)
{
  char temp = a;
  a = b;
  b = temp;
}
void permutations(string s, int low, int high)
{
  if (low == high)                    // --> Printing the results when low == high
    cout << s << endl;

  for (int i = low; i <= high; i++)
  {
    swap(s[low], s[i]);               // --> Finding the combinations by swaping the numbers
    permutations(s, low + 1, high);   // --> Finding Permutations by fixing the elements below low + i
    swap(s[low], s[i]);               // --> Backtracking to previous result by swaping again
  }
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t = 0;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> s;
    cout << endl;
    permutations(s, 0, s.size() - 1);
    cout << endl;
  }

  return 0;
}
