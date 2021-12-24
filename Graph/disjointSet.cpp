#include <iostream>
using namespace std;

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

void DisjointSet::print() {
  for (int i=0; i<size; i++)
    cout<<S[i]<<" ";
  cout<<"\n";
}

// int main() {
//   int edges[2][9] = {
//     { 1, 1,  2,  2, 3,  4,  4,  5,  5},
//     { 2, 6,  3,  7, 4,  5,  7,  6,  7}
//   };
//   DisjointSet ds(7);
//   return 0;
// }