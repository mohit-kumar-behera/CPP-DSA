#include <iostream>
using namespace std;

class String {
    private:
        char *str;
    public:
        String(char *s) {
            str = s;
        }
        
        int length();
        void display();
        
        void upperCase();
        void lowerCase();
        void toggleCase();
        void capitalize();
        void title();
        
        bool isValidString();
        
        void reverse();
        bool compare(String, int); // 2nd param denotes if cases should be considered or neglected
        bool isPalindrome(int); // 1st param denotes if cases should be considered or neglected
        
        int countWords();
};

// Length of string
int String::length() {
    int i=0;
    while (str[i] != '\0') i++;
    return i;
}

// Every character to upper case
void String::upperCase() {
    int i=0;
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
}

// Every character to lower case
void String::lowerCase() {
    int i=0;
    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
}

// Toggle the cases
void String::toggleCase() {
    int i=0;
    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
}

// Capitalize the first letter of first word
void String::capitalize() {
    lowerCase();
    
    if (str[0] >= 97 && str[0] <= 122)
        str[0] -= 32;
}

// Capitalize the first letter of every word
void String::title() {
    lowerCase();
    capitalize();
    
    int i=1;
    while (str[i] != '\0') {
        if(str[i] == ' ' && str[i + 1] >= 97 && str[i + 1] <= 122)
            str[i + 1] -= 32;
        i++;
    }
}

// Validate if string shouldnot contain any special character
bool String::isValidString() {
    int i=0;
    while (str[i] != '\0') {
        if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 59) && !(str[i] == ' '))
            return 0;
        i++;
    }
    return 1;
}

void swap(char *x, char *y) {
   char temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

// Reverse a String
void String::reverse() {
    int i, j;
    i=0;
    j=length() - 1;
    
    char temp; 
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

// Compare two String
bool String::compare(String compStr, int strictCheck) {
    int len1 = this->length();
    int len2 = compStr.length();
    
    if (len1 != len2)
        return 0;
    
    if (!strictCheck) {
        this->lowerCase();
        compStr.lowerCase();
    }
    
    int i=0;
    while (this->str[i] != '\0' && compStr.str[i] != '\0') {
        if (!(this->str[i] == compStr.str[i]))
            return 0;
        i++;
    }
    return 1;
}

// Check if string is palindrome or not
bool String::isPalindrome(int strictCheck) {
    int i, j;
    i=0;
    j=length() - 1;
    
    if (!strictCheck) lowerCase();
    
    char temp; 
    while (i < j) {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

// Count numer of words in a String
int String::countWords() {
    int i=0, count=1;
    
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i - 1] != ' ') count++;
    }
    return count;
}

// display a String
void String::display() {
    cout<<str;
}

int main()
{
    char name[] = "moHiT kuMaR";
    char name2[] = "mohit kumar";
    char name3[] = "nayan";
    char name4[] = "NayAn";
    char name5[] = "mohit kumar singh";
    char name6[] = "mohit kumar   singh";
    String s = String(name);
    String s1 = String(name2);
    String s3 = String(name3);
    String s4 = String(name4);
    String s5 = String(name5);
    String s6 = String(name6);
    
    // cout<<s.length()<<"\n";
    // s.display();
    
    // s.upperCase();
    // s.display();
    // s.lowerCase();
    // s.display();
    // s.toggleCase();
    // s.display();
    // s.capitalize();
    // s.display();
    // s.title();
    // s.display();
   
    // cout<<s.isValidString();
    
    // s.reverse();
    // s.display();
    // cout<<s.compare(s1, 0)<<"\n";
    // cout<<s4.isPalindrome(0)<<"\n";
    
    // cout<<s6.countWords()<<"\n";
    
    return 0;
}
