#include <../gtest/gtest.h>
#include "Matrix.h"

TEST(TMatrix, can_create_matrix_with_default_size)
{
	ASSERT_NO_THROW(TMatrix<int> m1);
}


TEST(TMatrix, can_not_create_matrix_with_negative_size)
{
	ASSERT_ANY_THROW(TMatrix<int> m1(-1));
}

TEST(TMatrix, can_get_length)
{
	TMatrix<double> m(12);
	EXPECT_EQ(12, m.GetSize());
}

TEST(TMatrix, can_create_matrix_with_any_size)
{
	TMatrix<int> m1(3);
	for (int i = 0; i < m1.GetSize(); i++)
		EXPECT_TRUE(m1[i].GetSize() == TVector<int>(i + 1, 1).GetSize());
}

TEST(TMatrix, can_copy_matrix)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(m1);
	for (int i = 0; i < m2.GetSize(); i++)
		EXPECT_TRUE(m1[i] == m2[i]);
}

TEST(TMatrix, can_found_a_member_of_matrix)
{
	TMatrix<int> m1(3);
	m1[1][2] = 9;
	EXPECT_EQ(9, m1[1][2]);
}

TEST(TMatrix, can_use_operator_equal)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(2);
	m2 = m1;
	for (int i = 0; i < m2.GetSize(); i++)
		EXPECT_TRUE(m1[i] == m2[i]);
}

TEST(TMatrix, can_use_operator_plus)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	TMatrix<int> m3;

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize(); j++)
			if (i >= j)
				m1[i][j] = 1;
	for (int i = 0; i < m2.GetSize(); i++)
		for (int j = 0; j < m2.GetSize(); j++)
			if (i >= j)
				m2[i][j] = -3;

	m3 = m1 + m2;
	for (int i = 0; i < m3.GetSize(); i++)
		EXPECT_TRUE(m3[i] == TVector<int>(i + 1, -2));
}

TEST(TMatrix, can_not_use_operator_plus_with_different_size_of_matrix)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(7);
	TMatrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 + m2);
}

TEST(TMatrix, can_use_operator_minus)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	TMatrix<int> m3;

	for (int i = 0; i < m1.GetSize(); i++)
		for (int j = 0; j < m1.GetSize(); j++)
			if (i >= j)
				m1[i][j] = 1;
	for (int i = 0; i < m2.GetSize(); i++)
		for (int j = 0; j < m2.GetSize(); j++)
			if (i >= j)
				m2[i][j] = -3;

	m3 = m1 - m2;
	for (int i = 0; i < m3.GetSize(); i++)
		EXPECT_TRUE(m3[i] == TVector<int>(i + 1, 4));
}

TEST(TMatrix, can_not_use_operator_minus_with_different_size_of_matrix)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(7);
	TMatrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 - m2);
}




