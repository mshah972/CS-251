/*
    Moksh Shah
    CS 251 - Data Structures
    Program 3
    Testing the mymatrix class
*/


#include <iostream>
#include "mymatrix.h"

using namespace std;

bool test_default_constructor()
{
    mymatrix<int> M;
    if (M.numrows() != 4 || M.numcols(0) != 4 || M(0, 0) != 0)
    {
        return false;
    }
    return true;
}

bool test_parameterized_constructor()
{
    mymatrix<int> M(3, 5);
    if (M.numrows() != 3 || M.numcols(0) != 5 || M(0, 0) != 0)
    {
        return false;
    }
    return true;
}

bool test_copy_constructor()
{
    mymatrix<int> M1(2, 2);
    M1(0, 0) = 1;
    M1(0, 1) = 2;
    M1(1, 0) = 3;
    M1(1, 1) = 4;

    mymatrix<int> M2(M1);
    if (M2.numrows() != 2 || M2.numcols(0) != 2 || M2(0, 0) != 1)
    {
        return false;
    }
    return true;
}

bool test_grow_cols()
{
    mymatrix<int> M(2, 2);
    M(0, 0) = 1;
    M(0, 1) = 2;
    M(1, 0) = 3;
    M(1, 1) = 4;

    M.growcols(1, 3);
    if (M.numcols(1) != 3 || M(1, 2) != 0)
    {
        return false;
    }
    return true;
}

bool test_grow_rows()
{
    mymatrix<int> M(2, 2);
    M(0, 0) = 1;
    M(0, 1) = 2;
    M(1, 0) = 3;
    M(1, 1) = 4;

    M.grow(3, 3);

    return (M.numrows() == 3 && M.numcols(0) == 2 && M.numcols(1) == 2 && M.numcols(2) == 3 && M(2, 2) == 0);
}

bool test_multiplication()
{
    mymatrix<int> M1(2, 2);
    M1(0, 0) = 1;
    M1(0, 1) = 2;
    M1(1, 0) = 3;
    M1(1, 1) = 4;

    mymatrix<int> M2(2, 2);
    M2(0, 0) = 5;
    M2(0, 1) = 6;
    M2(1, 0) = 7;
    M2(1, 1) = 8;

    mymatrix<int> M3 = M1 * M2;

    if (M3.numrows() != 2 || M3.numcols(0) != 2 || M3(0, 0) != 19)
    {
        return false;
    }
    return true;
}

bool test_matrix_multiplication()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;

    mymatrix<int> B(3, 2);
    B(0, 0) = 7;
    B(0, 1) = 8;
    B(1, 0) = 9;
    B(1, 1) = 10;
    B(2, 0) = 11;
    B(2, 1) = 12;

    mymatrix<int> C = A * B;

    return (C.numrows() == 2 && C.numcols(0) == 2 && C.numcols(1) == 2 && C(0, 0) == 58 && C(0, 1) == 64 && C(1, 0) == 139 && C(1, 1) == 154);
}

bool test_at()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 2;
    A(0, 1) = 3;
    A(0, 2) = 4;
    A(1, 0) = 1;
    A(1, 1) = 5;
    A(1, 2) = 2;
    return (A.at(0, 0) == 2 && A.at(1, 1) == 5 && A.at(0, 2) == 4);
}

bool test_scalar_multiplication()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 2;
    A(0, 1) = 3;
    A(0, 2) = 4;
    A(1, 0) = 1;
    A(1, 1) = 5;
    A(1, 2) = 2;
    mymatrix<int> B = A * 2;
    return (B.numrows() == 2 && B.numcols(0) == 3 &&
            B(0, 0) == 4 && B(0, 1) == 6 && B(0, 2) == 8 &&
            B(1, 0) == 2 && B(1, 1) == 10 && B(1, 2) == 4);
}

bool test_matrix_multiplication_jagged()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;

    mymatrix<int> B(3, 2);
    B(0, 0) = 7;
    B(0, 1) = 8;
    B(1, 0) = 9;
    B(1, 1) = 10;
    B(2, 0) = 11;
    B(2, 1) = 12;

    mymatrix<int> C = A * B;

    return (C.numrows() == 2 && C.numcols(0) == 2 && C.numcols(1) == 2 && C(0, 0) == 58 && C(0, 1) == 64 && C(1, 0) == 139 && C(1, 1) == 154);
}

bool test_scalar_multiplication_3x3()
{
    mymatrix<int> A(3, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    A(2, 0) = 7;
    A(2, 1) = 8;
    A(2, 2) = 9;

    mymatrix<int> B = A * 2;

    return (B.numrows() == 3 && B.numcols(0) == 3 && B.numcols(1) == 3 && B.numcols(2) == 3 &&
            B(0, 0) == 2 && B(0, 1) == 4 && B(0, 2) == 6 &&
            B(1, 0) == 8 && B(1, 1) == 10 && B(1, 2) == 12 &&
            B(2, 0) == 14 && B(2, 1) == 16 && B(2, 2) == 18);
}

bool test_scalar_multiplication_2x2_double()
{
    mymatrix<double> A(2, 2);
    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(1, 0) = 3.0;
    A(1, 1) = 4.0;

    mymatrix<double> B = A * 2.0;

    return (B.numrows() == 2 && B.numcols(0) == 2 && B.numcols(1) == 2 &&
            B(0, 0) == 2.0 && B(0, 1) == 4.0 &&
            B(1, 0) == 6.0 && B(1, 1) == 8.0);
}

bool test_matrix_multiplication_3x3()
{
    mymatrix<int> A(3, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    A(2, 0) = 7;
    A(2, 1) = 8;
    A(2, 2) = 9;

    mymatrix<int> B(3, 3);
    B(0, 0) = 1;
    B(0, 1) = 2;
    B(0, 2) = 3;
    B(1, 0) = 4;
    B(1, 1) = 5;
    B(1, 2) = 6;
    B(2, 0) = 7;
    B(2, 1) = 8;
    B(2, 2) = 9;

    mymatrix<int> C = A * B;

    return (C.numrows() == 3 && C.numcols(0) == 3 && C.numcols(1) == 3 && C.numcols(2) == 3 &&
            C(0, 0) == 30 && C(0, 1) == 36 && C(0, 2) == 42 &&
            C(1, 0) == 66 && C(1, 1) == 81 && C(1, 2) == 96 &&
            C(2, 0) == 102 && C(2, 1) == 126 && C(2, 2) == 150);
}

bool test_matrix_multiplication_2x2_double()
{
    mymatrix<double> A(2, 2);
    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(1, 0) = 3.0;
    A(1, 1) = 4.0;

    mymatrix<double> B(2, 2);
    B(0, 0) = 1.0;
    B(0, 1) = 2.0;
    B(1, 0) = 3.0;
    B(1, 1) = 4.0;

    mymatrix<double> C = A * B;

    return (C.numrows() == 2 && C.numcols(0) == 2 && C.numcols(1) == 2 &&
            C(0, 0) == 7.0 && C(0, 1) == 10.0 &&
            C(1, 0) == 15.0 && C(1, 1) == 22.0);
}

bool test_non_rectangle_matrix_multiplication()
{
    mymatrix<int> A(3, 3);
    mymatrix<int> B(2, 4);

    try
    {
        A * B;
    }
    catch (const std::runtime_error &e)
    {
        return true;
    }

    return false;
}

bool test_rectangle_matrix_multiplication()
{
    mymatrix<int> A(3, 2);
    mymatrix<int> B(2, 4);

    try
    {
        A * B;
    }
    catch (const std::runtime_error &e)
    {
        return false;
    }

    return true;
}

bool test_multiplying_matrix_multiplication()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    mymatrix<int> B(4, 4);
    B(0, 0) = 1;
    B(0, 1) = 2;
    B(0, 2) = 3;
    B(0, 3) = 4;
    B(1, 0) = 5;
    B(1, 1) = 6;
    B(1, 2) = 7;
    B(1, 3) = 8;
    B(2, 0) = 9;
    B(2, 1) = 10;
    B(2, 2) = 11;
    B(2, 3) = 12;
    B(3, 0) = 13;
    B(3, 1) = 14;
    B(3, 2) = 15;
    B(3, 3) = 16;
    try
    {
        A * B;
    }
    catch (runtime_error &e)
    {
        return true;
    }

    return false;
}

bool test_non_multiplying_matrix_multiplication()
{
    mymatrix<int> A(2, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    mymatrix<int> B(3, 2);
    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;
    B(2, 0) = 5;
    B(2, 1) = 6;
    try
    {
        A * B;
    }
    catch (runtime_error &e)
    {
        return false;
    }

    return true;
}

bool test_one_empty_matrix_multiplication()
{
    mymatrix<int> A;
    mymatrix<int> B(2, 2);
    try
    {
        A * B;
    }
    catch (runtime_error &e)
    {
        return true;
    }

    return false;
}

bool test_two_empty_matrix_multiplication()
{
    mymatrix<int> A;
    mymatrix<int> B;
    try
    {
        A * B;
    }
    catch (runtime_error &e)
    {
        return false;
    }

    return true;
}

bool text_same_grow()
{
    mymatrix<int> A(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;
    A.grow(3, 3);
    return (A.numrows() == 3 && A.numcols(0) == 3 && A.numcols(1) == 3 && A.numcols(2) == 3 &&
            A(0, 0) == 1 && A(0, 1) == 2 && A(0, 2) == 0 &&
            A(1, 0) == 3 && A(1, 1) == 4 && A(1, 2) == 0 &&
            A(2, 0) == 0 && A(2, 1) == 0 && A(2, 2) == 0);
}

bool test_referance_element()
{
    mymatrix<int> A(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;
    A.grow(3, 3);
    A(2, 2) = 5;
    return (A(2, 2) == 5);
}

int main()
{
    // run tests and print results
    cout << "test 1: " << (test_default_constructor() ? "PASSED" : "FAILED") << endl;
    cout << "test 2: " << (test_parameterized_constructor() ? "PASSED" : "FAILED") << endl;
    cout << "test 3: " << (test_copy_constructor() ? "PASSED" : "FAILED") << endl;
    cout << "test 4: " << (test_grow_cols() ? "PASSED" : "FAILED") << endl;
    cout << "test 5: " << (test_grow_rows() ? "PASSED" : "FAILED") << endl;
    cout << "test 6: " << (test_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 7: " << (test_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 8: " << (test_at() ? "PASSED" : "FAILED") << endl;
    cout << "test 9: " << (test_scalar_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 10: " << (test_matrix_multiplication_jagged() ? "PASSED" : "FAILED") << endl;
    cout << "test 11: " << (test_scalar_multiplication_3x3() ? "PASSED" : "FAILED") << endl;
    cout << "test 12: " << (test_scalar_multiplication_2x2_double() ? "PASSED" : "FAILED") << endl;
    cout << "test 13: " << (test_matrix_multiplication_3x3() ? "PASSED" : "FAILED") << endl;
    cout << "test 14: " << (test_matrix_multiplication_2x2_double() ? "PASSED" : "FAILED") << endl;
    cout << "test 15: " << (test_non_rectangle_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 16: " << (test_rectangle_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 17: " << (test_multiplying_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 18: " << (test_non_multiplying_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 19: " << (test_one_empty_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 20: " << (test_two_empty_matrix_multiplication() ? "PASSED" : "FAILED") << endl;
    cout << "test 21: " << (text_same_grow() ? "PASSED" : "FAILED") << endl;
    cout << "test 22: " << (test_referance_element() ? "PASSED" : "FAILED") << endl;
    cout << endl;

    system("pause");

    cout << "Done." << endl;

    return 0;
}
