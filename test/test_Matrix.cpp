
#include <gtest.h>
#include "Matrix.h"
#include "MyVector.h"
TEST(TMatrix, can_create_matrix)
{
    TMatrix<int> A(3);
    ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(TMatrix, cant_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int>A(-3));
}

TEST(TMatrix, can_copy_matrix)
{
    TMatrix<int> A(3);

    ASSERT_NO_THROW(TMatrix<int>B(A));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int>A(3);
    TMatrix<int>B = A;

    EXPECT_EQ(A, B);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> A(3);
    EXPECT_EQ(A.Length(), 3);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int>A(3);
    A[0][0] = 2;

    EXPECT_EQ(A[0][0], 2);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int>A(3);
    ASSERT_ANY_THROW(A[0][-1] = 2);
}

TEST(TMatrix, throws_when_set_element_with_larger_index)
{
    TMatrix<int>A(4);
    ASSERT_ANY_THROW(A[0][5] = 2);
}

TEST(TMatrix, can_equate_matrixes_of_equal_size)
{
    TMatrix<int> A(3);
    TMatrix<int> B(3);

    ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> A(3);
    TMatrix<int> B(4);

    ASSERT_NO_THROW(A = B);
}


TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> A(7);
    TMatrix<int> B(7);

    EXPECT_EQ(A == B, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> A(5);

    EXPECT_EQ(A == A, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> A(6);
    TMatrix<int> B(5);

    EXPECT_EQ(A == B, false);
}

TEST(TMatrix, assignment_operator_change_matrix_size)
{
    TMatrix<int> A(2);
    TMatrix<int> RES(3);
    A = 3;
    EXPECT_EQ(A, RES);
}

TEST(TMatrix, can_add_matrixes_with_equal_size)
{
    TMatrix<int> A(1);
    A[0][0] = 10;
    TMatrix<int> B(1);
    B[0][0] = 20;

    TMatrix<int> res(1);
    res[0][0] = 30;


    EXPECT_EQ(A + B, res);
}

TEST(TMatrix, throws_when_add_matrixes_with_different_sizes)
{
    TMatrix<int> A(4);
    TMatrix<int> B(5);

    ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, can_subtract_matrixes_with_equal_size)
{
    TMatrix<int> A(1);
    TMatrix<int> B(1);

    TMatrix<int> res(1);
    A[0][0] = 10;
    B[0][0] = 3;
    res[0][0] = 7;

    EXPECT_EQ(A - B, res);
}

TEST(TMatrix, throws_when_subtract_matrices_with_different_sizes)
{
    TMatrix<int> A(4);
    TMatrix<int> B(5);

    ASSERT_ANY_THROW(A - B);
}

TEST(TMatrix, can_multiply_matrixes_with_equal_size)
{
    TMatrix<int> A(1), B(1), C(1);
    A[0][0] = 10;
    B[0][0] = 2;
    C[0][0] = 20;
    EXPECT_EQ(A * B, C);
}

TEST(TMatrix, throws_when_multiply_matrices_with_different_sizes)
{
    TMatrix<int> A(3), B(4);

    ASSERT_ANY_THROW(A * B);
}