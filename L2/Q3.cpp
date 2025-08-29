#include <iostream>

using namespace std;

int main() 
{
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;

    int** marks = new int*[numStudents];
    int* numCourses = new int[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter number of courses for student " << i + 1 << ": ";
        cin >> numCourses[i];

        marks[i] = new int[numCourses[i]];

        cout << "Enter marks for " << numCourses[i] << " courses:\n";
        
		for (int j = 0; j < numCourses[i]; ++j) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\n--- Average Marks ---\n";
    for (int i = 0; i < numStudents; ++i) {
        int sum = 0;
        
		for (int j = 0; j < numCourses[i]; ++j) {
            sum += marks[i][j];
        }
        
        float average = static_cast<float>(sum) / numCourses[i];
        
        cout << "Student " << i + 1 << " average: " << average << endl;
    }

    for (int i = numsStudents - 1; i >= 0; i--) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numCourses;

    return 0;
}

