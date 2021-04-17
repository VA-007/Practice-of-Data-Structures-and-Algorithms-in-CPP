#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

vector<int> mergedArray(vector<int> arr1, vector<int> arr2)
{
  int i = 0, j = 0, k = 0, m = arr1.size(), n = arr2.size();
  vector<int> ans(m + n);

  while (i < m && j < n)
  {
    if (arr1[i] > arr2[j])
    {
      ans[k++] = arr2[j++];
    }
    else
    {
      ans[k++] = arr1[i++];
    }
  }

  while (i < m)
  {
    ans[k++] = arr1[i++];
  }
  while (j < n)
  {
    ans[k++] = arr2[j++];
  }

  return ans;
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr1{2, 6, 8, 10, 12};
  vector<int> arr2{8, 9, 10, 11, 14, 15};

  // mergedArray(arr1, arr2);
  vector<int> ans = mergedArray(arr1, arr2);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
