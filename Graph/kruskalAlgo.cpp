#include <iostream>
using namespace std;
#define MAX 32767
#define V 7 // Number of  Vertices of Graph
#define E 9 // Number of Edges of Graph


class DisjointSet {
  int *S, size;
  public:
    DisjointSet(int sz) {
      size = sz;
      S = new int[size];
      for (int i=0; i<size; i++)
        S[i] = -1;
    }

    ~DisjointSet() {
      delete [] S;
    }

    void set_union(int, int);
    int find(int);
    void print();
};

void DisjointSet::set_union(int u, int v) {
  if (S[u] < S[v]) {
    S[u] += S[v];
    S[v] = u;
  } else {
    S[v] += S[u];
    S[u] = v;
  }
}

int DisjointSet::find(int u) {
  int elem = u;
  while (S[elem] > 0) {
    elem = S[elem];
  }
  return elem;
}

void printMST(int sol[][V-1]) {
  for (int i=0; i<V-1; i++)
    cout<<sol[0][i]<<" -- "<<sol[1][i]<<"\n";
  cout<<"\n";
}

void kruskalMST(int A[3][E]) {
  int solutionArr[2][V-1];
  int included[E] = {0};
  DisjointSet ds(V+1);
  int i = 0, u_parent, v_parent;
  while (i < V-1) {
    int min = MAX;
    int u = 0, v = 0, k = 0;

    // Find Minimum cost edge
    for (int j=0; j<E; j++) {
      if (included[j] == 0 && A[2][j] < min) {
        min = A[2][j];
        u = A[0][j];
        v = A[1][j];
        k = j;
      }
    }

    // Check if it forms a cycle or not
    u_parent = ds.find(u);
    v_parent = ds.find(v);
    if (u_parent != v_parent) {
      solutionArr[0][i] = u;
      solutionArr[1][i] = v;

      // Perform union
      ds.set_union(u_parent, v_parent);
      i++;
    }
    included[k] = 1;
  }

  printMST(solutionArr);
}

int main() {
  int edges[3][E] = {
    { 1, 1,  2,  2, 3,  4,  4,  5,  5},
    { 2, 6,  3,  7, 4,  5,  7,  6,  7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
  };

  kruskalMST(edges);
  return 0;
}