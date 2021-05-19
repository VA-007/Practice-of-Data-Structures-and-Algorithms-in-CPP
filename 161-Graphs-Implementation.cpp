#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

// ========================================>> Breadth-First-Search <<================================================
void BFS(vector<vector<int>> G, int start)
{
  int i = start;
  queue<int> q;
  q.push(i);
  cout << i << " ";

  int visited[G.size()] = {0}; // --> Declaring the visited array to mark the visited vertices
  visited[i] = 1;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v = 1; v < G.size(); v++) // v is the row belonging to the value of u i.e. the current element which is being explored
    {
      if (G[u][v] == 1 && visited[v] == 0)
      {
        cout << v << " ";
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}

// ========================================>> Depth-First-Search <<================================================
void DFS(vector<vector<int>> G, int start)
{
  static int visited[7] = {0};

  int u = start;
  if (visited[u] == 0)
  {
    cout << u << " ";
    visited[u] = 1;

    for (int v = 1; v < G.size(); v++)
    {
      if (G[u][v] == 1 && visited[v] == 0)
        DFS(G, v);
    }
  }
}

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // --> Adjacency Matrix of graph having total 6 vertices
  vector<vector<int>> G{
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 0, 0},
      {0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0}};

  cout << "\nBreadth-First-Search:  ";
  BFS(G, 4);

  cout << "\nDepth-First-Search:    ";
  DFS(G, 4);

  cout << "\n\n";
  return 0;
}
