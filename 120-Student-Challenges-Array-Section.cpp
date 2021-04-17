#include <iostream>
#include <string>
using namespace std;

// Swap Function to permutations function
void swap(char &a, char &b)
{
  char temp = a;
  a = b;
  b = temp;
}
// <------- Function to print all different permutations of a string -------->
void permutations(string s, int low, int high)
{
  if (low == high)
  {
    cout << s << endl;
  }
  else
  {
    for (int i = low; i <= high; i++)
    {
      swap(s[low], s[i]);
      permutations(s, low + 1, high);
      swap(s[low], s[i]);
    }
  }
}

main()
{
  // <------- Missing Element in sorted Array -------->
  // int arr[11]{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
  // int n = 11;
  // for (int i = 0; i < n - 1; i++)
  // {
  //   if ((arr[i] + 1) != arr[i + 1])
  //   {
  //     int current = arr[i] + 1;
  //     while (current != arr[i + 1])
  //     {
  //       cout << current++ << " ";
  //     }
  //   }
  // }

  // <------- Duplicate Elements in sorted array -------->
  // int arr[12]{6, 6, 8, 8, 11, 12, 15, 16, 16, 16, 19, 19};
  // int n = 12, lastDuplicate = 0;
  // for (int i = 0; i < n - 1; i++)
  // {
  //   if (arr[i] == arr[i + 1] && lastDuplicate != arr[i])
  //   {
  //     lastDuplicate = arr[i];
  //     cout << lastDuplicate << " ";
  //   }
  // }

  // <------- Counting the number of Duplicate Elements in unsorted array -------->
  // int arr[12]{6, 8, 2, 37, 16, 19, 8, 6, 8, 37, 41};
  // int n = 12, count = 0;
  // for (int i = 0; i < n - 1; i++)
  // {
  //   count = 1;
  //   if (arr[i] != -1)
  //   {
  //     for (int j = i + 1; j < n; j++)
  //     {
  //       if (arr[i] == arr[j])
  //       {
  //         arr[j] = -1;
  //         count++;
  //       }
  //     }
  //     if (count > 1)
  //     {
  //       cout << arr[i] << " is appearing " << count << " times." << endl;
  //     }
  //   }
  // }

  // <------- Counting the number of Duplicate Elements in sorted array -------->
  // int arr[12]{6, 6, 8, 8, 11, 12, 15, 16, 16, 16, 19, 19};
  // int n = 12, j = 0;
  // for (int i = 0; i < n; i++)
  // {
  //   if (arr[i] == arr[i + 1])
  //   {
  //     j = i + 1;
  //     while (arr[j] == arr[i] && j < n)
  //     {
  //       j++;
  //     }
  //     cout << arr[i] << " is appearing " << j - i << " times." << endl;
  //     i = j - 1;
  //   }
  // }

  // <------- Finding pair of elements with sum K using Hashing -------->
  // int A[10]{6, 3, 8, 10, 16, 7, 5, 2, 9, -6};
  // int H[16]{0};
  // int n = 10, sum = 10;

  // for (int i = 0; i < n; i++)
  // {
  //   if (H[sum - A[i]] == 1 && (sum - A[i] >= 0))
  //   {
  //     cout << A[i] << " " << sum - A[i] << endl;
  //   }
  //   H[A[i]]++;
  // }

  // <------- Inserting in an sorted Array so that resulting array is sorted -------->
  // int arr[12]{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
  // int x = 13;
  // int i = 10;
  // // cout<<arr[10];
  // while (arr[i] > x)
  // {
  //   arr[i + 1] = arr[i];
  //   i--;
  // }
  // arr[i+1] = x;
  // for (int i = 0; i < 12; i++)
  // {
  //   cout << arr[i] << " ";
  // }

  // <------- Finding the element which occurs odd number of times in an unsorted array using XOR operator < O(n) time >------->
  // int arr[11]{6, 7, 6, 9, 11, 7, 19, 17, 9, 19, 11};
  // int x = arr[0];
  // int i = 1;
  // for (; i < 11; i++)
  // {
  //   x ^= arr[i];
  // }
  // cout << x;

  // <------- Checking if two strings are anagram or not ------->
  // string s1 = "decimal";
  // string s2 = "medical";
  // char a;
  // a = s1[0];
  // char b;
  // b = s2[0];

  // for (int i = 1; i < s1.size(); i++)
  // {
  //   a ^= s1[i];
  //   b ^= s2[i];
  // }

  // if (a == b)
  //   cout << "They are anagram!";
  // else
  //   cout << "They are not anagram";

  // <------- Driver code for function to print all different permutations of a string -------->
  string s = "ABC";
  permutations(s, 0, 2);

  return 0;
}
