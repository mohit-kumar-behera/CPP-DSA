#include <iostream>
using namespace std;

class Diagonal {
    private:
        int size;
        int *A;
        
    public:
        Diagonal(int n) {
            size = n;
            A = new int[size];
        }
        
        int setMatrix(int, int, int);
        int getMatrix(int, int);
        
        void display();
        
        ~Diagonal() {
            delete []A;
        }
};

// Set the Matrix
int Diagonal::setMatrix(int i, int j, int val) {
    if (i<size && j<size) {
        if (i==j) {
            A[i - 1] = val;
            return 1; // Matrix is set
        }
    }
    return -1; // Outside range of matrix
}

// Get element from the Matrix
int Diagonal::getMatrix(int i, int j) {
    if (i<size && j<size) {
        if (i==j)
            return A[i - 1];
        return 0;
    }
    return -1; // Outside range of matrix
}

// Display the Matrix
void Diagonal::display() {
    int i, j;
    
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if (i == j)
                cout<<A[i - 1]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<"\n";
    }
}

int main()
{

    Diagonal d = Diagonal(3);
    d.setMatrix(0, 0, 5);
    d.setMatrix(1, 1, 7);
    d.setMatrix(2, 2, 3);
    
    d.display();

    return 0;
}
