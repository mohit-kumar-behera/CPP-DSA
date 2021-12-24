#include <iostream>
using namespace std;


// Implementing ROW-MAJOR
class LowerTriangular {
    private:
        int size;
        int *A;
    public:
        LowerTriangular(int n) {
            size = n; // size of 2D matrix
            A = new int[n * (n + 1) / 2]; // size of equivalent 1D matrix
        }
        
        ~LowerTriangular() {
            delete [] A;
        }
        
        int setMatrix(int, int, int);
        int getMatrix(int, int);
        
        void display();
};

int calcIndex(int i, int j) {
    // Formula = 1 + 2 + 3 + ... + i + j = [i * (i+1)]/2 + j
    return i * (i + 1)/2 + j;
}

// Set the matrix
int LowerTriangular::setMatrix(int i, int j, int val) {
    if (i<size && j<size) {
        if (i >= j) {
            A[calcIndex(i, j)] = val;
            return 1;
        }
        return 0;
    }
    return -1;
}

// Get element from the matrix
int LowerTriangular::getMatrix(int i, int j) {
    if (i<size && j<size) {
        if (i >= j)
            return A[calcIndex(i, j)];
        return 0;
    }
    return -1;
}

//Display the matrix
void LowerTriangular::display() {
    int i, j;
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if (i >= j)
                cout<<A[calcIndex(i, j)]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    LowerTriangular lt = LowerTriangular(3);
    lt.setMatrix(0, 0, 3);
    lt.setMatrix(1, 0, 7);
    lt.setMatrix(0, 1, 2); // will not work as i<j
    lt.setMatrix(1, 1, 9);
    lt.setMatrix(2, 0, 1);
    lt.setMatrix(2, 1, 6);
    lt.setMatrix(2, 2, 4);
    lt.setMatrix(1, 2, 9); // will not work as i<j
    
    // cout<<lt.getMatrix(2, 1);
    // cout<<lt.getMatrix(2, 2);

    lt.display();

    return 0;
}
