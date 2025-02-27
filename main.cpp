#include <iostream>
#include "matrix.h"
using namespace std;
using namespace COP3330; 

//**********************************************
// main.cpp
// Assignment #4: Matrix Multiplication Test
// Author: [Your Name]
// Date: [Today's Date]
//**********************************************

int main() {
    cout << "Welcome to the Matrix Multiplication Test Program!" << endl;
    cout << "In this test, you will multiply a 2x3 matrix (Matrix A) by a 3x2 matrix (Matrix B)." << endl;
    cout << "Please enter the values as prompted." << endl << endl;

    // Create Matrix A (2 rows x 3 columns)
    Matrix_Class A(2, 3);
    cout << "Enter values for Matrix A (2x3):" << endl;
    cout << "For best results, enter the following values:" << endl;
    cout << "Row 1: 1 2 3" << endl;
    cout << "Row 2: 4 5 6" << endl;
    A.Input();  // User will input values for A
    A.Print("Matrix A:");

    // Create Matrix B (3 rows x 2 columns)
    Matrix_Class B(3, 2);
    cout << "\nEnter values for Matrix B (3x2):" << endl;
    cout << "For best results, enter the following values:" << endl;
    cout << "Row 1: 7 8" << endl;
    cout << "Row 2: 9 10" << endl;
    cout << "Row 3: 11 12" << endl;
    B.Input();  // User will input values for B
    B.Print("Matrix B:");

    // Multiply matrices: (2x3) * (3x2) = (2x2)
    // Expected multiplication:
    //   C[0][0] = 1*7 + 2*9  + 3*11 = 7 + 18 + 33  = 58
    //   C[0][1] = 1*8 + 2*10 + 3*12 = 8 + 20 + 36  = 64
    //   C[1][0] = 4*7 + 5*9  + 6*11 = 28 + 45 + 66 = 139
    //   C[1][1] = 4*8 + 5*10 + 6*12 = 32 + 50 + 72 = 154
    // Note: Our multiplication operator modifies the left operand.
    // To preserve the original Matrix A, we create a copy.
    Matrix_Class result = A;  // Copy of A
    result = result * B;      // Multiply copy by B; result now holds the product

    cout << "\nResult of A * B:" << endl;
    result.Print("Matrix Product:");

    // Output the expected result for comparison
    cout << "\nExpected Result:" << endl;
    cout << "Row size = 2  Column size = 2" << endl;
    cout << "   58    64" << endl;
    cout << "  139   154" << endl;

    cout << "\nThank you for testing the matrix multiplication!" << endl;
    return 0;
}

