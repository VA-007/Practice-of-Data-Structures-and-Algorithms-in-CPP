#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define SIZE 10

using namespace std;

// ====================================>> UTILITY FUNCTIONS <<==============================================
void display(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

int Hash(int x)
{
  return x % SIZE;
}

// =================================>> FUNCITON FOR LINEAR PROBING <<===========================================
void probe(vector<int> &HT, int element)
{
  int pos = Hash(element);

  while (HT[pos] != 0)
  {
    pos = (pos + 1) % SIZE;
  }

  HT[pos] = element;
}

// =============================>> FUNCITON FOR INSERTION INTO THE HASH TABLE <<=====================================
void insert(vector<int> &HT, int element)
{
  int pos = Hash(element);

  if (HT[pos])
    probe(HT, element);
  else
    HT[pos] = element;
}

// =============================>> FUNCITON FOR SEARCHING IN THE HASH TABLE <<=====================================
int search(vector<int> &HT, int element)
{
  int pos = Hash(element);

  int i = 0, j = pos % SIZE;
  bool flag = false;
  while (HT[(pos + i) % SIZE] != element)
  {
    i++;
    flag = true;
  }

  return (i == j) ? -1 : (pos + i) % SIZE;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> HT(10, 0);
  display(HT);

  insert(HT, 10);
  insert(HT, 23);
  insert(HT, 33);
  insert(HT, 46);
  insert(HT, 55);

  display(HT);

  cout << "Enter element to be searched: ";
  int e;
  cin >> e;
  cout << endl;
  if (search(HT, e) != -1)
    cout << e << " is found at possition : " << search(HT, e) << endl;
  else
    cout << e << " is not Found in the Hash Table!" << endl;

  return 0;
}
