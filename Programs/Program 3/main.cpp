#include <iostream>
#include "mymatrix.h"

using namespace std;

// test function for the default constructor
bool test_1() {
    // create a matrix of integers
    mymatrix<int> m;

    // return true if the matrix is 4x4
    return (m.numrows() == 4) && (m.numcols(0) == 4) && (m.numcols(1) == 4)
           && (m.numcols(2) == 4) && (m.numcols(3) == 4);
}

// test function for the parameterized constructor
bool test_2() {
    // create a matrix of integers with 2 rows and 3 columns
    mymatrix<int> m(2, 3);

    // return true if the matrix is 2x3
    return (m.numrows() == 2) && (m.numcols(0) == 3) && (m.numcols(1) == 3);
}

// test function for the copy constructor
bool test_3() {
    // create a matrix of integers with 2 rows and 3 columns
    mymatrix<int> m1(2, 3);
    // set some values
    m1(0, 0) = 1;
    m1(1, 2) = 2;

    // create a copy of m1
    mymatrix<int> m2(m1);

    // return true if the copy is 2x3 and has the same values as m1
    return (m2.numrows() == 2) && (m2.numcols(0) == 3) && (m2.numcols(1) == 3)
           && (m2(0, 0) == 1) && (m2(1, 2) == 2);
}

// test function for operator()
bool test_4() {
    // create a matrix of integers with 2 rows and 3 columns
    mymatrix<int> m(2, 3);
    // set some values
    m(0, 0) = 1;
    m(1, 2) = 2;

    // return true if the values are set correctly
    return (m(0, 0) == 1) && (m(1, 2) == 2);
}

// test function for grow basic
bool test_5() {
    // create a matrix of integers with 2 rows and 3 columns
    mymatrix<int> m(2, 3);
    // grow the matrix
    m.grow(3, 4); // call grow function

    // return true if the matrix is 3x3, 3x3, and 3x4
    return (m.numrows() == 3) && (m.numcols(0) == 3) && (m.numcols(1) == 3)
           && (m.numcols(2) == 4);
}

// test function for growcols
bool test_6() {
    // create a matrix of integers with 2 rows and 3 columns
    mymatrix<int> m(2, 3);
    // growcols the matrix
    m.growcols(1, 5);

    // return true if the matrix is 2x3 and 2x5
    return (m.numrows() == 2) && (m.numcols(0) == 3) && (m.numcols(1) == 5);
}



int main() {
    // run tests and print results
    cout << "test_1: " << (test_1() ? "PASSED" : "FAILED") << endl;
    cout << "test_2: " << (test_2() ? "PASSED" : "FAILED") << endl;
    cout << "test_3: " << (test_3() ? "PASSED" : "FAILED") << endl;
    cout << "test_4: " << (test_4() ? "PASSED" : "FAILED") << endl;
    cout << "test_5: " << (test_5() ? "PASSED" : "FAILED") << endl;
    cout << "test_6: " << (test_6() ? "PASSED" : "FAILED") << endl;

    return 0;
}
