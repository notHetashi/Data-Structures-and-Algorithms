#include <iostream>
#include <cmath>
using namespace std;

void aop(){
    int x,y;
    int sum;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    sum = x+y;
    cout << "The sum is: " << sum << endl;
}

void dop(){
    int x,y;
    int diff;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    diff = x-y;
    cout << "The difference is: " << diff << endl;
}

void prop(){
    int x,y;
    int prod;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    prod = x*y;
    cout << "The product is: " << prod << endl;
}

void qop(){
    int x,y;
    int qou;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    qou = x/y;
    cout << "The quotient is: " << qou << endl;
}

void userin(){
    int choice = 0;
    cout << "1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Exit" << endl;
    cout << "Enter your operation of choice: ";
    cin >> choice;
    if (choice == 1) {
        aop();
    } else if (choice == 2) {
        dop();
    } else if (choice == 3) {
        prop();
    } else if (choice == 4) {
        qop();
    } else if (choice == 5) {
        exit(1);
    } else {
        cout << "Enter a valid number!";
    }
}

int main(){
    while (true){
        userin();
    }
    return 0;
}