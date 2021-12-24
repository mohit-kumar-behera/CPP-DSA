#include<iostream>
#include<math.h>
using namespace std;

class Term {
    public:
        int coeff, expo;
};

class Polynomial {
    int numTerms;
    Term *term;
    public:
        Polynomial() {
            numTerms = 0;
            term = new Term[numTerms];
        }
        
        Polynomial(int n) {
            numTerms = n;
            term = new Term[numTerms];
        }
        
        ~Polynomial() {
            delete [] term;
        }
        
        friend istream & operator >> (istream &, Polynomial &);
        friend ostream & operator << (ostream &, Polynomial &);
        
        int evaluate(int);
        
        Polynomial operator + (Polynomial &);
};
// Input
istream & operator >> (istream &is, Polynomial &p) {
    int i=0;
    
    cout<<"Enter Coeffiecient then exponent\n";
    for(; i<p.numTerms; i++)
        cin >> p.term[i].coeff >> p.term[i].expo;
    
    return is;
}

// Output
ostream & operator << (ostream &os, Polynomial &p) {
    int i=0;
    
    cout<<"Polynomial:\t";
    for(; i<p.numTerms; i++) {
        cout<<p.term[i].coeff<<"x^"<<p.term[i].expo;
        
        if (i != p.numTerms - 1) cout<<" + ";

    }
}

// Evaluation of Polynomial
int Polynomial::evaluate(int val) {
    int i=0;
    int eval=0;
    
    for(; i<numTerms; i++) {
        eval += term[i].coeff * pow(val, term[i].expo);
    }
    
    return eval;
}

// Add two Polynomial
Polynomial Polynomial::operator + (Polynomial &p) {
    int totalTerms = numTerms + p.numTerms; 
    Polynomial p3;
    p3 = Polynomial(totalTerms);
    
    int i=0, j=0, k=0;
    while (i<numTerms && j<p.numTerms) {
        if (term[i].expo > p.term[j].expo) {
            p3.term[k].coeff = term[i].coeff;
            p3.term[k].expo = term[i].expo;
            k++;
            i++;
        } else if (term[i].expo < p.term[j].expo) {
            p3.term[k].coeff = p.term[j].coeff;
            p3.term[k].expo = p.term[j].expo;
            k++;
            j++;
        } else {
            p3.term[k].coeff = term[i].coeff + p.term[j].coeff;
            p3.term[k].expo = p.term[j].expo;
            k++;
            j++;
            i++;
        }
    }
    
    for(; i<numTerms; i++) {
        p3.term[k++].coeff = term[i++].coeff;
        p3.term[k++].expo = term[i++].expo;
    }
    
    for(; j<p.numTerms; i++) {
        p3.term[k++].coeff = p.term[j++].coeff;
        p3.term[k++].expo = p.term[j++].expo;
    }
    
    p3.numTerms = k;
    return p3;
}

int main() {
    
    // Polynomial p = Polynomial(4);
    // cin>>p;
    // cout<<p;
    // cout<<"\n"<<p.evaluate(2)<<"\n";
    
    Polynomial p1 = Polynomial(4);
    cin>>p1;
    Polynomial p2 = Polynomial(5);
    cin>>p2;
    Polynomial p3 = p1 + p2;
    cout<<p3;
    cout<<"\n"<<p3.evaluate(2)<<"\n";
    
    return 0;
}