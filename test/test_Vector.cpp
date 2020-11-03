#include <../gtest/gtest.h> 
#include "Vector.h"

TEST(TVector, can_create_vecrot_with_default_constrant)
{
	ASSERT_NO_THROW(TVector<int> v1);
}

TEST(TVector, can_get_size)
{
	TVector<double> v1(10);

	EXPECT_EQ(1, v1.GetSize());
}


TEST(TVector, can_use_operator_index_for_vectors)
{

	TVector<double> v1(7.85);

	EXPECT_EQ(7.85, v1[0]);
}

TEST(TVector, can_create_vector_eith_size_one)
{
	TVector<double> v1(5.1);

	EXPECT_EQ(1, v1.GetSize());
	EXPECT_EQ(5.1, v1[0]);
}

TEST(TVector, can_create_vector_with_one_value)
{
	TVector<int> v1(5, 10);

	EXPECT_EQ(5, v1.GetSize());
	for (int i = 0; i < v1.GetSize(); i++)
		EXPECT_EQ(10, v1[i]);
}

TEST(TVector, can_copy_vector)
{
	TVector<int> v1(3, 1);
	TVector<int> v2(v1);

	EXPECT_EQ(3, v2.GetSize());
	for (int i = 0; i < v2.GetSize(); i++)
		EXPECT_EQ(1, v2[i]);
}

TEST(TVector, can_use_operator_plus_for_vectors)
{
	TVector <int> v1(3, 1);
	TVector <int> v2(3, -1);

	TVector <int> v3 = v1 + v2;

	EXPECT_EQ(3, v3.GetSize());
	for (int i = 0; i < v3.GetSize(); i++)
		EXPECT_EQ(0, v3[i]);

}


TEST(TVector, can_use_operator_minus_for_vectors)
{
	TVector <int> v1(3, 1);
	TVector <int> v2(3, -1);

	TVector <int> v3 = v1 - v2;

	EXPECT_EQ(3, v3.GetSize());
	for (int i = 0; i < v3.GetSize(); i++)
		EXPECT_EQ(2, v3[i]);

}

TEST(TVector, can_use_operator_multiplication_for_vectors)
{
	TVector <int> v1(4, 2);
	TVector <int> v2(3, 7);

	TVector <int> v3 = v1 * v2;

	EXPECT_EQ(3, v3.GetSize());
	for (int i = 0; i < v3.GetSize(); i++)
		EXPECT_EQ(14, v3[i]);
}


TEST(TVector, two_vectors_can_be_compare)
{
	TVector<int> v1(5, 7);
	TVector<int> v2(4, 2);

	TVector<int> v3(5, 7);
	TVector<int> v4(5, 7);

	EXPECT_TRUE(v3 == v4);
	EXPECT_FALSE(v1 == v2);
}

