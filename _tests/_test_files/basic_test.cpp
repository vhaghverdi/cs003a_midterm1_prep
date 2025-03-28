#include "gtest/gtest.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
// Files we are testing:

#include "../../includes/midterm/midterm.h"

#include "../../includes/add_entry/add_entry.h"
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/delete_repeats/delete_repeats.h"

//------------------------------------------------------------------------------------------

using namespace std;

void print_array(int *a, int size)
{
	if (a == nullptr)
	{
		cout << endl;
		return;
	}

	for (int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
}

bool test_array_dedupe()
{
	int a[12] = {3, 5, 5, 9, 11, 11, 17};
	int size = 7;

	cout << "\nOriginal array:         ";
	print_array(a, size);

	cout << "Removing duplicates:    ";
	int new_size = 0;
	int *b = array_dedupe(a, size, new_size);
	print_array(b, new_size);
	cout << endl;

	int expected_size = 5;
	int expected_arr[] = {3, 5, 9, 11, 17};

	if (new_size != expected_size)
	{
		cout << "FAILED: Expected a new size of " << expected_size
			 << ", but got " << new_size << " instead." << endl;
		return false;
	}

	for (int i = 0; i < new_size; i++)
	{
		if (b[i] != expected_arr[i])
		{
			cout << "FAILED: Expected value of " << expected_arr[i]
				 << " at index " << i << ", but got " << b[i]
				 << " instead." << endl;
			return false;
		}
	}

	return true;
}

bool test_array_intersect()
{
	int a1[] = {5, 10, 15, 20, 25};
	int size1 = 5;
	int a2[] = {5, 7, 9, 10, 20};
	int size2 = 5;

	cout << "\na1:           ";
	print_array(a1, size1);
	cout << "a2:           ";
	print_array(a2, size2);

	int new_size = 0;
	int *b = array_intersect(a1, size1, a2, size2, new_size);
	cout << "intersection: ";
	print_array(b, new_size);
	cout << endl;

	int expected_size = 3;
	int expected_arr[] = {5, 10, 20};

	if (new_size != expected_size)
	{
		cout << "FAILED: Expected a new size of " << expected_size
			 << ", but got " << new_size << " instead." << endl;
		return false;
	}

	for (int i = 0; i < new_size; i++)
	{
		if (b[i] != expected_arr[i])
		{
			cout << "FAILED: Expected value of " << expected_arr[i]
				 << " at index " << i << ", but got " << b[i]
				 << " instead." << endl;
			return false;
		}
	}

	return true;
}

bool test_array_union()
{
	int a1[] = {5, 10, 15, 20, 25};
	int size1 = 5;
	int a2[] = {5, 7, 9, 10, 20};
	int size2 = 5;

	cout << "\na1:    ";
	print_array(a1, size1);
	cout << "a2:    ";
	print_array(a2, size2);

	int new_size = 0;
	int *b = array_union(a1, size1, a2, size2, new_size);
	cout << "union: ";
	print_array(b, new_size);
	cout << endl;

	int expected_size = 7;
	int expected_arr[] = {5, 7, 9, 10, 15, 20, 25};

	if (new_size != expected_size)
	{
		cout << "FAILED: Expected a new size of " << expected_size
			 << ", but got " << new_size << " instead." << endl;
		return false;
	}

	for (int i = 0; i < new_size; i++)
	{
		if (b[i] != expected_arr[i])
		{
			cout << "FAILED: Expected value of " << expected_arr[i]
				 << " at index " << i << ", but got " << b[i]
				 << " instead." << endl;
			return false;
		}
	}

	return true;
}

TEST(MIDTERM1, TestArrayDedupe)
{
	EXPECT_EQ(true, test_array_dedupe());
}

TEST(MIDTERM1, TestArrayIntersect)
{
	EXPECT_EQ(true, test_array_intersect());
}

TEST(MIDTERM1, TestArrayUnion)
{
	EXPECT_EQ(true, test_array_union());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	std::cout << "\n\n----------running basic_test.cpp---------\n\n"
			  << std::endl;
	return RUN_ALL_TESTS();
}

/*
----------running basic_test.cpp---------


[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from MIDTERM1
[ RUN      ] MIDTERM1.TestArrayDedupe

Original array:         3  5  5  9  11  11  17
Removing duplicates:    3  5  9  11  17

[       OK ] MIDTERM1.TestArrayDedupe (0 ms)
[ RUN      ] MIDTERM1.TestArrayIntersect

a1:           5  10  15  20  25
a2:           5  7  9  10  20
intersection: 5  10  20

[       OK ] MIDTERM1.TestArrayIntersect (0 ms)
[ RUN      ] MIDTERM1.TestArrayUnion

a1:    5  10  15  20  25
a2:    5  7  9  10  20
union: 5  7  9  10  15  20  25

[       OK ] MIDTERM1.TestArrayUnion (0 ms)
[----------] 3 tests from MIDTERM1 (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
*/
