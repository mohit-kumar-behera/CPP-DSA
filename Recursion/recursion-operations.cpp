
#include <iostream>
using namespace std;


int naturalSum(int n) {
    /*
        SUM(n) = 1 + 2 + 3 + ... + n 
        SUM(n) = 1 + 2 + 3 + ... + (n - 1) + n 
        SUM(n) = SUM(n - 1) + n;
    */
    if (n == 0) 
        return 0;
    return  naturalSum(n - 1) + n;
}

int factorialOf(int n) {
    /*
        FACTORIAL(n) = n * (n - 1) * (n - 2) * ... * 1 
        FACTORIAL(n) = 1 * 2 * ... * (n - 1) * n 
        FACTORIAL(n) = FACTORIAL(n - 1) * n
    */
    if (n == 0)
        return 1;
    return factorialOf(n - 1) * n; 
}

int powerOf(int m, int n) {
    /*
        2^5 = 2 * 2 * 2 * 2 * 2
        2^5 = 2^4 * 2 
        2^5 = (2^3 * 2) * 2
        m*n = m * m * m * ... * m (n times)
        POWER(m, n) = m * m * ... * (n - 1)times * m
        POWER(m, n) = POWER(m, n - 1) * m;
    */
    if (n == 0) 
        return 1;
    return powerOf(m, n - 1) * m;
}

double exponentOf(int x, int precession) {
    /*
        TAYLOR SERIES
        e^x = 1 + (x/1!) + (x^2/2!) + ... + (x^n/n!);
        e^4 = 1 + (4/1!) + (4^2/2!) + (4^3/3!) + (4^4/4!);
        
        keep precession >= 10 for correct result
    */
    static double power = 1, factorial = 1;
    double result;
    
    if (precession == 0)
        return 1;
    result = exponentOf(x, precession - 1);
    power *= x;
    factorial *= precession;
    
    return result + power / factorial; 
}

double exponentOf__Horner(int x, int precession) {
    /*
        e^x = 1 + x[1 + x/2[1 + x/3[1 + x/4]]] // precession = 4
    */
    static double s = 1;
    if(precession == 0)
        return s;
    s = 1 + double(x) / precession * s;
    return exponentOf__Horner(x, precession - 1);
}

int fibonacci(int n) {
    /*
        FIB(7) = 0 1 1 2 3 5 8 13
        FIB(n) = FIB(n - 1) + FIB(n - 2)
        FIB(0) = 0
        FIB(1) = 1
    */  
    if (n <= 1)
        return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int fib[10];
int fibonacci__memoization(int n) {
    if (n <= 1) {
        fib[n] = n;
        return n;
    } else {
        if (fib[n - 2] == -1) fib[n - 2] = fibonacci__memoization(n - 2);
        if (fib[n - 1] == -1) fib[n - 1] = fibonacci__memoization(n - 1);
        return fib[n - 2] + fib[n - 1];
    }
}

int nCr(int n, int r) {
    /*
        nCr = n! / (r! * (n - r)!)
    */
    int numerator = factorialOf(n);
    int denom1 = factorialOf(n - r);
    int denom2 = factorialOf(r);
    
    return numerator / (denom1 * denom2);
}

int main()
{
    int findSum = 10;
    cout<<naturalSum(findSum)<<"\n"; // 55
    
    int findFact = 6;
    cout<<factorialOf(findFact)<<"\n"; // 720
    
    cout<<powerOf(2, 5)<<"\n"; // 32
    
    cout<<exponentOf(4, 10)<<"\n"; // 54.4431
    
    cout<<exponentOf__Horner(4, 10)<<"\n"; // 54.4431
    
    cout<<fibonacci(7)<<"\n"; // 13
    
    
    for(int i = 0; i < 10; i++) {
        fib[i] = -1; 
    }
    cout<<fibonacci__memoization(7)<<"\n"; // 13
    
    cout<<nCr(12, 8)<<"\n"; // 495
    
    return 0;
}


