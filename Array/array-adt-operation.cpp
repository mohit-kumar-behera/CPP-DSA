#include <iostream>
using namespace std;


class Array {
    public:
        int *A, size, length;
        
        bool isFull();
        bool validIndex(int);
        bool isSorted();
        
        void display();
        void append(int);
        void insert(int, int);
        
        int deleteIndex(int); 
        
        int linearSearch(int);
        int binarySearch(int, int, int);
        
        int get(int);
        int set(int, int);
        int getMax();
        int getMin();
        int getSum();
        float getAvg();
        
        void reverse();
        void leftShit();
        void rightShift();
        void rotateLeft();
        void rotateRight();
        
        void arrangeSignwise();
        
        Array *merge(Array *, Array *);
        Array *_union(Array *, Array *);
        Array *_intersection(Array *, Array *);
        Array *setDifference(Array *, Array *);
};

// Check whether array size is full or not
bool Array::isFull() {
    return size == length;
}

// Check whether the provided index in valid or not
bool Array::validIndex(int index) {
    return index >= 0 && index < length;
}

// Check whether Array is sorted or not
bool Array::isSorted() {
    int i;
    
    for(i=0; i<length - 2; i++) {
        if(A[i + 1] < A[i])
            return false;
    }
    return true;
}


// Inserting element to Array at certain position
void Array::insert(int pos, int val) {
    int i;
    if(!isFull()) {
        if (validIndex(pos)) {
            for(i=length; i>pos; i--) 
                A[i] = A[i - 1];
            A[pos] = val;
            length++;   
        } else {
            cout<<"Position beyond limit\n";
        }
    } else {
        cout<<"Array is Completely Filled\n";
    }
}



// Appending element to Array
void Array::append(int val) {
    if(!isFull()) 
        A[length++] = val;
    else 
        cout<<"Array is Filled Completely\n";
}



// Deleting element from Array at certain position
int Array::deleteIndex(int pos) {
    int i, temp = -1;
    if(validIndex(pos)) {
        temp = A[pos];
        for(i=pos; i<length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return temp;
    } else {
        cout<<"Position beyond limit\n";   
    }
    return 0;
}



void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Search for an element (LINEAR SEARCH)
int Array::linearSearch(int key) {
    int i;
    for(i=0; i<length; i++) {
        if(A[i] == key) {
            swap(A[i], A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

// Search for an element (BINARY SEARCH)
int Array::binarySearch(int key, int low, int high) {
    if (!validIndex(low) || !validIndex(high)) {
        return -1;
    } else {
        int mid;
        
        if(low <= high) {
            mid = (low + high) / 2;
            
            if(A[mid] == key)
                return mid;
            else if(A[mid] < key)
                return binarySearch(key, mid + 1, high);
            else
                return binarySearch(key, low, mid - 1);
        }
    }
}

// Small Math function
// Get the index of an element
int Array::get(int index) {
   if(validIndex(index))
       return A[index];
      return -1;
}

// Set the value of a certain index
int Array::set(int index, int val) {
    if(validIndex(index)) {
        A[index] = val;
        return 1;
    }
    return -1;
}

// Find Min element
int Array::getMin() {
    int min = A[0], i;
    for(i=0; i<length; i++) {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

// Find Max element
int Array::getMax() {
    int max = A[0], i;
    for(i=0; i<length; i++) {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

// Find Sum
int Array::getSum() {
    int sum = 0, i;
    for(i=0; i<length; i++)
        sum += A[i];
    return sum;
}

// Find Avg 
float Array::getAvg() {
    return (float)getSum() / length;
}



// Reversing, Shifting and Rotating Arrays
// Reverse the Array
void Array::reverse() {
    int i, j;
    
    for(i=0, j=length - 1; i<j; i++, j--)
        swap(A[i], A[j]);
}

// Left shift the Array
void Array::leftShit() {
    int i;
    
    for(i=0; i<length; i++)
        A[i] = A[i + 1];
}

// Right shift the Array
void Array::rightShift() {
    int i;
    
    for(i=length - 1; i>0; i--)
        A[i] = A[i - 1];
    A[i] = 0;
}

// Rotate left the Array
void Array::rotateLeft() {
    int i, temp;
    temp = A[0];
    
    for(i=0; i<length - 1; i++)
        A[i] = A[i + 1];
    A[i] = temp;
}

// Rotate right the Array
void Array::rotateRight() {
    int i, temp;
    temp = A[length - 1];
    
    for(i=length - 1; i>0; i--)
        A[i] = A[i - 1];
    A[i] = temp;
}



// Negative number on one side and positive number on other
void Array::arrangeSignwise() {
    int i=0, j=length - 1;
    
    while(i < j) {
        while(A[i] < 0) 
            i++;
        while(A[j] > 0)
            j--;
        if(i < j)
            swap(A[i], A[j]);
    }
}



// Merge two Arrays
Array *Array::merge(Array *arr1, Array *arrMerge) {
    arrMerge->size = 30;
    arrMerge->A = new int[arrMerge->size * sizeof(int)];
    
    int i=0, j=0, k=0, m=this->length, n=arr1->length;

    while(i<m && j<n) {
        if(this->A[i] < arr1->A[j])
            arrMerge->A[k++] = this->A[i++];
        else
            arrMerge->A[k++] = arr1->A[j++];
    }
   
    // Leftover elements
    while(i<m)
        arrMerge->A[k++] = this->A[i++];
    
    while(j<n)
        arrMerge->A[k++] = arr1->A[j++];

    // Set the length
    arrMerge->length = k;
}



// SET METHOD
// UNION
Array *Array::_union(Array *arr1, Array *arrUnion) {
    arrUnion->size = 30;
    arrUnion->A = new int[arrUnion->size * sizeof(int)];
    
    int i=0, j=0, k=0, m=this->length, n=arr1->length;

    while(i<m && j<n) {
        if(this->A[i] < arr1->A[j]) {
            arrUnion->A[k++] = this->A[i++];   
        } else if(this->A[i] > arr1->A[j]) {
            arrUnion->A[k++] = arr1->A[j++];
        } else {
            // this->A[i] == arr1->A[j]
            arrUnion->A[k++] = arr1->A[j++];
            i++;
        }
    }
   
    // Leftover elements
    while(i<m)
        arrUnion->A[k++] = this->A[i++];
    
    while(j<n)
        arrUnion->A[k++] = arr1->A[j++];

    // Set the length
    arrUnion->length = k;
}

// INTERSECTION 
Array *Array::_intersection(Array *arr1, Array *arrIntersection) {
    arrIntersection->size = 30;
    arrIntersection->A = new int[arrIntersection->size * sizeof(int)];
    
    int i=0, j=0, k=0, m=this->length, n=arr1->length;

    while(i<m && j<n) {
        if(this->A[i] < arr1->A[j]) {
            i++;   
        } else if(this->A[i] > arr1->A[j]) {
            j++;
        } else {
            // this->A[i] == arr1->A[j]
            arrIntersection->A[k++] = arr1->A[j++];
            i++;
        }
    }

    // Set the length
    arrIntersection->length = k;
}

// // SET DIFFERENCE
Array *Array::setDifference(Array *arr1, Array *arrSetDifference) {
    arrSetDifference->size = 30;
    arrSetDifference->A = new int[arrSetDifference->size * sizeof(int)];
    
    int i=0, j=0, k=0, m=this->length, n=arr1->length;

    while(i<m && j<n) {
        if(this->A[i] < arr1->A[j]) {
            arrSetDifference->A[k++] = this->A[i++]; 
        } else if(this->A[i] > arr1->A[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }
	
	// Leftover elements
    while(i<m)
        arrUnion->A[k++] = this->A[i++];
	
    // Set the length
    arrSetDifference->length = k;
}



// Displaying elements in Array
void Array::display() {
    int i;
    
    for(i=0; i<length; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    Array arr, arr1;
    int n, i;
    // cout << "Enter Size of Array\n";
    // cin >> arr.size;
    arr.size = 10;
    arr1.size = 10;
    
    // Dynamic Memory Allocation of Array
    arr.A = new int[arr.size * sizeof(int)];
    arr1.A = new int[arr.size * sizeof(int)];
    cout << "Number of Elements (Less than " << arr.size <<")\n";
    // cin >> arr.length;
    arr.length = 6;
    arr1.length = 6;
    
    //Inserting Elements into Array
    // cout<<"Enter elements into Array\n";
    for(i=0; i<arr.length; i++) {
        // cin >> arr.A[i];
        arr.A[i] = i + 1;
    }
    
    int a[] = {-6, 1, 2, 5, 6, 12};
    for(i=0; i<arr1.length; i++) {
        arr1.A[i] = a[i];
    }
    
    // arr.display();
    
    // arr.append(23);
    // arr.display();
    
    // arr.insert(3, 34);
    // arr.display();
    
    // arr.deleteIndex(3);
    // arr.display();
    
    // cout<<arr.linearSearch(7)<<"\n";
    // cout<<arr.linearSearch(4)<<"\n";
    
    // arr.display();
    
    // cout<<arr.binarySearch(6, 0, arr.length - 1)<<"\n";
    
    // cout<<arr.get(4)<<"\n";
    // cout<<arr.set(2, 7)<<"\n";
    // arr.display();
    // cout<<arr.getMax()<<"\n";
    // cout<<arr.getMin()<<"\n";
    // cout<<arr.getSum()<<"\n";
    // cout<<arr.getAvg()<<"\n";
    
    // arr.reverse();
    // arr.leftShit();
    // arr.rightShift();
    // arr.rotateLeft();
    // arr.rotateRight();
    // arr.display();
    

    // cout<<arr.isSorted()<<"\n";
    // cout<<arr1.isSorted()<<"\n";
    
    // arr1.display();
    // arr1.arrangeSignwise();
    // arr1.display();
    
    // arr.display();
    // arr1.display();
    // Array arrMerge;
    // arr.merge(&arr1, &arrMerge); // Merge arr, arr1 and store it in arrMerge
    // arrMerge.display();
    
    
    /*
        SETS PROPERTY
        Union, Intersection, Difference
        ASSUMPTION: Both arrays are sorted
    */
    // arr.display();
    // arr1.display();
    // Array arrUnion, arrIntersection, arrSetDifference;
    // arr._union(&arr1, &arrUnion);
    // arrUnion.display();
    // arr._intersection(&arr1, &arrIntersection);
    // arrIntersection.display();
    // arr.setDifference(&arr1, &arrSetDifference); // arrSetDifference = arr - arr1
    // arrSetDifference.display();
    
    delete [] arr.A;
    delete [] arr1.A;
    // delete [] arrMerge.A;
    // delete [] arrUnion.A;
    // delete [] arrIntersection.A;
    // delete [] arrSetDifference.A;
    
    return 0;
}

