//**********************************************
// Matrix.cpp                                  *
// Assignment #4: Matrix Multiplication        *
// Betty Phipps                                *
// 02/24/25                                    *
//**********************************************

#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace COP3330;

//**********************************************
// Function Name: Default constructor          *
// Description: Initializes an empty matrix    *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
Matrix_Class::Matrix_Class() : rowsize(0), colsize(0), matrix(nullptr) {       // Default Constructor
}
//**********************************************
// Function Name: Constructor with parameters  *
// Description: Initializes a matrix with user *
//              input of rows and cols         *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
Matrix_Class::Matrix_Class(const int r, const int c){       // Constructor
    rowsize = (r >= 2 && r <=6) ? r : 6;
    colsize = (r >= 2 && r <=6) ? c : 6;

    matrix = new int*[rowsize];
    for (int i = 0; i < rowsize; i++){                      //alllocates array of pointers 
        matrix[i] = new int[colsize]();                     //memory allocated for each row
    }
}

//**********************************************
// Function Name: Deconstructor                *
// Description: Clears matrix and memory       *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
Matrix_Class::~Matrix_Class(){
    Clear();
}

//**********************************************
// Function Name: Clear                        *
// Description: Deletes matrix and resets size
//              to 0x0                         *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
void Matrix_Class::Clear(){                                   // Delete Matrix
    if (matrix){
        //delete each row
        for (int i = 0; i < rowsize; i++){
            delete[] matrix[i];
        }
        //delete the array of pointers
        delete[] matrix;
        matrix = nullptr;
    }
    //initialize row and col to 0
    rowsize = 0;
    colsize = 0;
}

//**********************************************
// Function Name: Zero                         *
// Description: Sets all elements in the       *
//              matrix to zero                 *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
void Matrix_Class::Zero(){                                    // Set all values in matrix to zero
    for (int i = 0; i < rowsize; i++){
        for (int j = 0; j < colsize; j++){
            matrix[i][j] = 0;
        }
    }
}

//**********************************************
// Function Name: Print                        *
// Description: Prints the matrix              *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
void Matrix_Class::Print(string msg)const {                                   // Print Matrix to Stdout
    cout<<msg<<" "<<endl;
    cout<<"Row size ="<< rowsize << " Column size = "<< colsize <<"\n";
    for (int i = 0; i < rowsize; i++){
        for (int j = 0; j < colsize; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

//**********************************************
// Function Name: Input                        *
// Description: Reads iput values from user    *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
void Matrix_Class::Input(){                                   // Input Matrix from Stdin
    for (int i = 0; i < rowsize; i++){
        cout<<"Enter "<<colsize<<" numbers for Row "<<i + 1<<":";
        for (int j =0; j < colsize; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Matrix Output ";
}

//**********************************************
// Function Name: Resize                       *
// Description: Reads input values from user   *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
void Matrix_Class::Resize(const int r, const int c){          // Clear and resize to row and col
    //error checking
    if ((r >= 2 && r <= 6) && (c >= 2 && c <=6)){
        Clear();        // free exisitng memory
        rowsize = r;
        colsize = c;
    }
    
    //allocating memory for the  new matrix
    matrix = new int*[rowsize];
    for (int i = 0; i < rowsize; i++){
        matrix[i] = new int[colsize]();
    }
}

//**********************************************
// Function Name: operator=                    *
// Description: Assigns one matrix values to   *
//              another                        *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
Matrix_Class &Matrix_Class::operator= (const Matrix_Class & m){
    if (this !=&m){         //avoid self assignment
        Resize(m.rowsize, m.colsize);   //match m dimesions
        for (int i = 0; i < rowsize; i++){
            copy(m.matrix[i], m.matrix[i] + colsize, matrix[i]);    //copy each row
        }
    }
    return *this;   //return current object
}

//**********************************************
// Function Name: operator*                    *
// Description: multiplies two matrixes        *
// Date: 02/25/25                              *
// Author: Betty Phipps                        * 
//**********************************************
Matrix_Class &Matrix_Class::operator* (Matrix_Class & m1){
    //Check if columns match rows to multiply according values
    if (colsize != m1.rowsize){
        return *this;
    }

    //allocate a temporary result matrix
    Matrix_Class *result = new Matrix_Class(rowsize, m1.colsize);
    for (int i = 0; i < rowsize; i++){
        for (int j = 0; j < m1.colsize; j++){
            result->matrix[i][j] = 0;       //elements i and j result matrix is set to zero
            for (int k =0; k < colsize; k++){
                //loop thorugh corresponding elements and product is added to the running total for result matrix
                result->matrix[i][j] += matrix[i][k] * m1.matrix[k][j];
            }
        }
    }
    *this = *result;    //assigning result to object
    delete result;      //free space
    return *this;       //returning updated object
}