#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int>m(5);
	for (int i = 0; i < 5; i++) {
		m[i] = m[i]+1;
	}
	TMatrix<int>tmp(m);
	EXPECT_EQ(true, tmp==m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>tmp(3);
	TMatrix<int>tmp1(tmp);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	tmp[0] = elem;
	EXPECT_EQ(false, tmp == tmp1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int>m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int>tmp(3);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	tmp[0] = elem;
	EXPECT_EQ(elem, tmp[0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int>tmp(3);
	TVector<int>elem(3);
	ASSERT_ANY_THROW(tmp[-1]=elem);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int>tmp(3);
	TVector<int>elem(3);
	ASSERT_ANY_THROW(tmp[4] = elem);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int>tmp(3);
	TMatrix<int>exp_tmp(3);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		tmp[i] = elem;
		exp_tmp[i] = elem;
	}
	tmp=tmp;
	EXPECT_EQ(exp_tmp, tmp);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int>tmp(3);
	TMatrix<int>exp_tmp(3);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		exp_tmp[i] = elem;
	}
	tmp = exp_tmp;
	EXPECT_EQ(exp_tmp, tmp);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int>tmp(5);
	TMatrix<int>tmp2(2);
	tmp = tmp2;
	EXPECT_EQ(2,tmp.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int>tmp(5);
	TMatrix<int>exp_tmp(3);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		exp_tmp[i] = elem;
	}
	tmp = exp_tmp;
	EXPECT_EQ(exp_tmp, tmp);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{

	TMatrix<int>tmp(3);
	TMatrix<int>exp_tmp(3);
	TVector<int>elem(3);
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		exp_tmp[i] = elem;
	}
	tmp = exp_tmp;
	EXPECT_EQ(true, tmp==exp_tmp);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> tmp(3);
	EXPECT_EQ(true, tmp == tmp);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> tmp1(3), tmp2(5);
	EXPECT_EQ(false, tmp1 == tmp2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> tmp1(3), tmp2(3), exp_tmp(3);
	TVector<int> elem;
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		tmp1[i] = elem;
		tmp2[i] = elem;
		exp_tmp[i] = elem*2;
	}
	EXPECT_EQ(exp_tmp, tmp1 + tmp2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> tmp1(2), tmp2(5);
	ASSERT_ANY_THROW(tmp1 + tmp2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> tmp1(3), tmp2(3), exp_tmp(3);
	TVector<int> elem;
	for (int i = 0; i < 3; i++) {
		elem[i] = i;
	}
	for (int i = 0; i < 3; i++) {
		tmp1[i] = elem;
		tmp2[i] = elem;
		exp_tmp[i] = elem - elem;
	}
	EXPECT_EQ(exp_tmp, tmp1 - tmp2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> tmp1(2), tmp2(5);
	ASSERT_ANY_THROW(tmp1 - tmp2);
}

