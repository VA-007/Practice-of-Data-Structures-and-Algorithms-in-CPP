#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

// =============>> Swap Function <<==============
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// =============>> Display Function <<==============
void display(vector<int> arr)
{
  for (int i = 1; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// =================================>> INSERT FUNCTION FOR HEAP <<=======================================
void insert(vector<int> &arr, int pos)
{
  int i = pos;
  int temp = arr[i];

  while (i > 1 && temp > arr[i / 2]) // --> Keeping the condition i>1 as index starts from 1, and last case of insertion will be at index 1
  {
    arr[i] = arr[i / 2];
    i /= 2;
  }
  arr[i] = temp;
}

// =================================>> CREATE HEAP FUNCTION <<=======================================
void createHeap(vector<int> &arr)
{
  for (int i = 1; i < arr.size(); i++)
    insert(arr, i);
}

// =================================>> DELETING FROM HEAP FUNCTION <<=======================================
int deleteFromHeap(vector<int> &arr, int n)
{
  int i, j;
  int val = arr[1];
  arr[1] = arr[n];
  i = 1, j = i * 2;

  while (j < n)
  {
    if (arr[j + 1] > arr[j])
      j = j + 1;

    if (arr[i] < arr[j])
    {
      swap(arr[i], arr[j]);
      i = j;
      j = i * 2;
    }
    else
      break;
  }
  arr[n] = val; // Heap Sort
  return val;
}

// =================================>> FUNCTION FOR HEAP SORT <<=======================================
void heapSort(vector<int> &arr)
{
  for (int i = 1; i < arr.size(); i++)
    deleteFromHeap(arr, arr.size() - i);
}

// =================================>> HEAPIFY <<=======================================
void heapify(vector<int> &arr, int i)
{
  int left = i * 2;
  int right = i * 2 + 1;
  int largest = 0;

  if (left < arr.size() && arr[i] < arr[left])
    largest = left;
  else
    largest = i;

  if (right < arr.size() && arr[largest] < arr[right])
    largest = right;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, largest);
  }
}

// -------------->> Function to build a Max-Heap from the given array <<---------------------
void buildHeap(vector<int> &arr)
{
  // --> Index of last non-leaf node
  int startIdx = (arr.size() - 1) / 2;

  // --> Perform reverse level order traversal from last non-leaf node and heapify each node
  for (int i = startIdx; i >= 1; i--)
    heapify(arr, i);
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> Heap{0, 10, 20, 30, 25, 5, 40, 35};
  cout << "Initial array to be made as Heap:       ";
  display(Heap);

  // createHeap(Heap);
  // cout << "Heap created from the array:            ";
  // display(Heap);

  // deleteFromHeap(Heap, Heap.size() - 1);
  // cout << "Deleted the 1st element from the Heap:  ";
  // display(Heap);

  // // --> Heap Sort
  // heapSort(Heap);
  // cout << "Sorted array using Heap Sort:           ";
  // display(Heap);

  // --> Hepify
  buildHeap(Heap);
  cout << "Heap created using Heapify:             ";
  display(Heap);

  return 0;
}
