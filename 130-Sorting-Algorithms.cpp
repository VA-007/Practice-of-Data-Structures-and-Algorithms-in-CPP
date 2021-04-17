#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

// <------------------------------------------------- SWAP FUNCTION ------------------------------------------------->
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// <------------------------------------------------- DISPLAY FUNCTION ------------------------------------------------->
void display(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// <------------------------------------------------- BUBBLE SORT ------------------------------------------------->
void bubbleSort(vector<int> &arr)
{
  bool swapped = false;

  for (int i = 0; i < arr.size() - 1; i++)
  {
    for (int j = 0; j < arr.size() - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = true; // Optimizing Bubble sort
      }
    }
    if (swapped == false)
      break;
  }
}
// <-------- BUBBLE SORT RECURSIVE -------->
void bubbleRecursive(vector<int> &arr, int n)
{
  if (n == 1)
    return;

  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      swap(arr[i], arr[i + 1]);
  }

  bubbleRecursive(arr, n - 1);
}

// <------------------------------------------------- INSERTION SORT ------------------------------------------------->
void insertionSort(vector<int> &arr)
{
  for (int i = 1; i < arr.size(); i++)
  {
    int j = i;
    while (arr[j] < arr[j - 1] && j > 0)
    {
      swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}

// <------------------------------------------------- SELECTION SORT ------------------------------------------------->
void selectionSort(vector<int> &arr)
{
  int j, k;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    k = i;
    for (j = i; j < arr.size(); j++)
    {
      if (arr[j] < arr[k])
      {
        k = j;
      }
    }
    swap(arr[i], arr[k]);
  }
}

// <------------------------------------------------- QUICK SORT ------------------------------------------------->
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low], i = low, j = high;

  do
  {
    do
    {
      i++;
    } while (arr[i] <= pivot); // i finds element greater than the pivot element.

    do
    {
      j--;
    } while (arr[j] > pivot); // j finds the element smaller than or equal to pivot element.

    if (i < j)
    {
      swap(arr[i], arr[j]); // Swapping element at i and j.
    }

  } while (i < j);

  swap(arr[low], arr[j]); // Pivot = arr[low], hence we are swapping arr[j] with the pivot element.

  return j; // returning the partitioning possition.
}

void quickSort(vector<int> &arr, int low, int high)
{
  int j = 0;

  if (low < high)
  {
    j = partition(arr, low, high);
    quickSort(arr, low, j);
    quickSort(arr, j + 1, high);
  }
}

// <------------------------------------------------- MERGE SORT ------------------------------------------------->
void merge(vector<int> &arr, int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low;
  int a[high + 1];

  while (i <= mid && j <= high)
  {
    if (arr[i] < arr[j])
    {
      a[k++] = arr[i++];
    }
    else
    {
      a[k++] = arr[j++];
    }
  }

  while (i <= mid)
  {
    a[k++] = arr[i++];
  }
  while (j <= high)
  {
    a[k++] = arr[j++];
  }

  for (i = low; i <= high; i++)
  {
    arr[i] = a[i];
  }
}

void mergeSortIterative(vector<int> &arr)
{
  int p, i, low, mid, high;
  int n = arr.size();

  for (p = 2; p <= n; p *= 2)
  {
    for (i = 0; i + p - 1 < n; i += p)
    {
      low = i;
      high = i + p - 1;
      mid = (low + high) / 2;
      merge(arr, low, mid, high);
    }
  }

  if ((p / 2) < n)
  {
    merge(arr, 0, (p / 2) - 1, n - 1);
  }
}

void mergeRecursive(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;

    mergeRecursive(arr, low, mid);
    mergeRecursive(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

// <------------------------------------------------- COUNT SORT ------------------------------------------------->
void countSort(vector<int> &arr)
{
  vector<int> temp(*max_element(arr.begin(), arr.end()) + 1, 0);

  for (int i = 0; i < arr.size(); i++)
  {
    temp[arr[i]]++;
  }

  int j = 0;
  for (int i = 0; i < temp.size(); i++)
  {
    if (temp[i] > 0)
    {
      while (temp[i]--)
      {
        arr[j++] = i;
      }
    }
  }
}

// <------------------------------------------------- SHELL SORT ------------------------------------------------->
void shellSort(vector<int> &arr)
{
  int gap, i, j, temp;
  int n = arr.size();

  for (gap = n / 2; gap >= 1; gap /= 2)
  {
    for (i = gap; i < n; i++)
    {
      temp = arr[i];
      j = i - gap;

      while (j >= 0 && arr[j] > temp)
      {
        arr[j + gap] = arr[j];
        j -= gap;
      }
      arr[j + gap] = temp;
    }
  }
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> arr1{80, 5, 98, 20, 36, 42, -3, 7, 20};   // Unsorted
  vector<int> arr2{8, 15, 17, 20, 36, 42, 49, 71, 100}; // Sorted
  vector<int> arr3{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};       // Reverse Sorted

  // --> Bubble
  // display(arr1);
  // bubbleSort(arr1);
  // display(arr1);

  // --> Bubble Recursive
  // display(arr3);
  // bubbleRecursive(arr3, arr3.size());
  // display(arr3);

  // --> Inserstion
  // display(arr1);
  // insertionSort(arr1);
  // display(arr1);

  // --> Selection
  // display(arr3);
  // selectionSort(arr3);
  // display(arr3);

  // --> Quick
  // display(arr3);
  // quickSort(arr3, 0, arr3.size());
  // display(arr3);

  // --> Merge Iterative
  // display(arr3);
  // mergeSortIterative(arr3);
  // display(arr3);

  // --> Merge Recursive
  // display(arr3);
  // mergeRecursive(arr3, 0, arr3.size() - 1);
  // display(arr3);

  // --> Count
  // display(arr3);
  // countSort(arr3);
  // display(arr3);

  // --> Shell
  display(arr3);
  shellSort(arr3);
  display(arr3);

  return 0;
}
