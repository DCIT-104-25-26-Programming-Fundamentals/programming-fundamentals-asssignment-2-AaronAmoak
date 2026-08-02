// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )
//   2. Subtraction       ( - )
//   3. Multiplication    ( * )
//   4. Division          ( / )
//   5. Modulus           ( % )
//   6. Exponentiation    ( ^ )
//   7. Quit
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double addNumbers(double a, double b) {
    return a + b;
}

double subtractNumbers(double a, double b) {
    return a - b;
}

double multiplyNumbers(double a, double b) {
    return a * b;
}

double divideNumbers(double a, double b) {
    return a / b;
}

double modulusNumbers(double a, double b) {
    return fmod(a, b);
}

double powerNumbers(double base, double exponent) {
    return pow(base, exponent);
}

void printMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please select 1-7." << endl;
            continue;
        }

        double a, b, result;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                result = addNumbers(a, b);
                cout << "Result: " << a << " + " << b << " = " << result << endl;
                break;
            case 2:
                result = subtractNumbers(a, b);
                cout << "Result: " << a << " - " << b << " = " << result << endl;
                break;
            case 3:
                result = multiplyNumbers(a, b);
                cout << "Result: " << a << " * " << b << " = " << result << endl;
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    result = divideNumbers(a, b);
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                }
                break;
            case 5:
                if (b == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    result = modulusNumbers(a, b);
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                }
                break;
            case 6:
                result = powerNumbers(a, b);
                cout << "Result: " << a << " ^ " << b << " = " << result << endl;
                break;
        }
    }

    return 0;
}
