// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//   2. Display All Students
//   3. Calculate Average Score for a Specific Student
//   4. Quit
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Computes the average of a student's scores
double computeAverage(const Student& s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < s.scores.size(); i++) {
        sum += s.scores[i];
    }
    return sum / s.scores.size();
}

// Feature 1: Adds a new student record
void addStudent(vector<Student>& students) {
    Student s;
    cin.ignore(); // clear leftover newline before getline
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// Feature 2: Displays every student's name, ID, scores, and average
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < students.size(); i++) {
        const Student& s = students[i];
        cout << "\nName: " << s.name << endl;
        cout << "ID: " << s.id << endl;
        cout << "Scores: ";
        for (size_t j = 0; j < s.scores.size(); j++) {
            cout << s.scores[j];
            if (j != s.scores.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "Average: " << computeAverage(s) << endl;
    }
}

// Feature 3: Looks up a student by ID and prints their average score
void calculateAverageForId(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << computeAverage(students[i]) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void printMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForId(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Invalid choice. Please enter 1-4." << endl;
                break;
        }
    }

    return 0;
}
