
#include <iostream>
using namespace std;

class Element {
    public:
        int row, col, elem; 
};

class SparseMatrix {
  int numRow, numCol, numElem;
  Element *e;
  
  public:
    void createMatrix();
    void displayTable();
    void displayMatrix();
};

void SparseMatrix::createMatrix() {
    cout<<"Enter num of row, col, elements\n";
    cin>>numRow>>numCol>>numElem;
    e = new Element[numElem];
    
    int i;
    cout<<"Enter all Elements\nEnter row, then col and then elem\n";
    for(i=0; i<numElem; i++) {
        cin >> e[i].row >> e[i].col >> e[i].elem;
    }
}

void SparseMatrix::displayTable() {
    cout<<"\nSPARSE TABLE\n";
    cout << "ROW\t" << "COL\t" << "ELEM\n";
    cout << numRow << "\t" << numCol << "\t" << numElem << "\n";
    cout << "--------------------------\n";
    
    int i;
    for(i=0; i<numElem; i++) {
        cout << e[i].row << "\t" << e[i].col << "\t" << e[i].elem <<"\n";
    }
}

void SparseMatrix::displayMatrix() {
    cout<<"\nSPARSE MATRIX\n";
    int i, j, k=0;
    
    for(i=1; i<=numRow; i++) {
        for(j=1; j<=numCol; j++) {
            if (i==e[k].row && j==e[k].col) {
                cout<<e[k].elem;
                k++;
            }
            else {
                cout<<0;
            }
            cout<<"\t";
        }
        cout<<"\n";
    }
}

int main()
{
    SparseMatrix s;
    s.createMatrix();
    s.displayTable();
    s.displayMatrix();
    
    return 0;
}
