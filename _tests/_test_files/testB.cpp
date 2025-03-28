#include "gtest/gtest.h"
#include <iomanip>
#include <iostream>

#include "../../includes/midterm/midterm.h"

using namespace std;

bool test_stub()
{
	return true;
}

TEST(TEST_STUB, TestStub)
{
	EXPECT_EQ(true, test_stub());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	std::cout << "\n\n----------running testB.cpp---------\n\n"
			  << std::endl;
	return RUN_ALL_TESTS();
}
