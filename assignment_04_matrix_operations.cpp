// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
//
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Reads an R x C matrix from the user, element by element
void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Displays an R x C matrix in an aligned grid
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Computes the transpose of an R x C matrix into result (C x R)
void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Part B: Adds two R x C matrices element-wise into result
void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Part C: Multiplies an M x N matrix A by an N x P matrix B into result (M x P)
void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p, int result[10][10]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matA[10][10], matB[10][10], result[10][10];

    // ---------------- PART A: Transpose ----------------
    cout << "--- PART A: Transpose a Matrix ---" << endl;
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(matA, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matA, rowsA, colsA);

    transposeMatrix(matA, rowsA, colsA, result);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, colsA, rowsA);

    // ---------------- PART B: Addition ----------------
    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    int rowsB, colsB;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    cout << "\nEnter values for Matrix 1:" << endl;
    readMatrix(matA, rowsB, colsB);

    cout << "\nEnter values for Matrix 2:" << endl;
    readMatrix(matB, rowsB, colsB);

    addMatrices(matA, matB, rowsB, colsB, result);

    cout << "\nSum of Matrices:" << endl;
    printMatrix(result, rowsB, colsB);

    // ---------------- PART C: Multiplication ----------------
    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int m, n, n2, p;
    cout << "Enter rows of Matrix A: ";
    cin >> m;
    cout << "Enter columns of Matrix A: ";
    cin >> n;
    cout << "Enter rows of Matrix B: ";
    cin >> n2;
    cout << "Enter columns of Matrix B: ";
    cin >> p;

    if (n != n2) {
        cout << "Error: Columns of A must equal rows of B for multiplication." << endl;
        return 0;
    }

    cout << "\nEnter values for Matrix A:" << endl;
    readMatrix(matA, m, n);

    cout << "\nEnter values for Matrix B:" << endl;
    readMatrix(matB, n, p);

    multiplyMatrices(matA, matB, m, n, p, result);

    cout << "\nProduct of Matrix A x B:" << endl;
    printMatrix(result, m, p);

    return 0;
}
