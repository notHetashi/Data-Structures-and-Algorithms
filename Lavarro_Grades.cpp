#include <iostream>
using namespace std;

void grade(int avg_score){
    if (avg_score >= 70){
        cout << "Result: Passed" << endl;
    } else{
        cout << "Result: Failed" << endl;
    }
}

int main(){
    int score;
    int sum_grade = 0;
    int avg_grade = 0;


    for (int num = 1; num < 4; num++){
        cout << "Enter the score for Exam " << num << ": ";
        cin >> score;

        sum_grade += score;
    }
        avg_grade = sum_grade/3;
        cout << "Average Score: " << avg_grade << endl;

        grade(avg_grade);
    return 0;
}