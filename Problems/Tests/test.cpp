/*
Test cases for testing my implementations of specific algorithms.
E.g. coding quicksort from scratch then running a set of test cases
against it
*/

#include "gtest/gtest.h"
#include "QuicksortLom.h"
#include "QuicksortLomStd.h"
#include "QuicksortCTCI.h"
#include "Quicksort1.h"

//How to write a set of test cases that I can use to test all implementations
//of a specific algorithm? For example, I might write 8 quicksort implementations,
//but I only want to use a single set of tests to test all of them.

//Use value parameterized tests:
//https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#value-parameterized-tests

//Basic background on google test:
//https://github.com/google/googletest/blob/master/googletest/docs/primer.md


//Fixtures
template <typename T>
class QuicksortTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

        bool checkResult(const std::vector<int>& vec)
        {
            bool goodResult = true;
            if (vec.size() < 2)
            {
                return goodResult;
            }
            for (int i = 1; i < vec.size(); ++i)
            {
                if (vec.at(i-1) > vec.at(i))
                {
                    goodResult = false;
                    break;
                }
            }
            return goodResult;
        }

        T lib;
        std::vector<int> vecOdd = { 4, 7, 5, 3, 10, 1, 9 };
        std::vector<int> vecEven = { 4, 55, 1, 78, 23, 34, 66, 29 };
        std::vector<int> vecEmpty = {};
        std::vector<int> vecSingle = { 1 };
        std::vector<int> vecRepeats = { 4, 3, 7, 5, 3, 10, 1, 3, 9, 9, 5, 5, 5 };
        std::vector<int> vecSorted = { 1, 1, 3, 4, 7, 9, 11, 14, 15 };
};

//Declare a type parameterized test passing my fixture
TYPED_TEST_CASE_P(QuicksortTest);

//Define the cases for the type parameterized test (repeat as many times as necessary)
TYPED_TEST_P(QuicksortTest, sortEvenArray)
{
    lib.quicksort(vecEven, 0, vecEven.size() - 1);
    bool vecValsCorrect = checkResult(vecEven);
    EXPECT_TRUE(vecValsCorrect);
}

TYPED_TEST_P(QuicksortTest, sortOddArray)
{
    lib.quicksort(vecOdd, 0, vecOdd.size() - 1);
    bool vecValsCorrect = checkResult(vecOdd);
    EXPECT_TRUE(vecValsCorrect);
}

TYPED_TEST_P(QuicksortTest, sortEmptyArray)
{
    lib.quicksort(vecEmpty, 0, vecEmpty.size() - 1);
    bool vecValsCorrect = checkResult(vecEmpty);
    EXPECT_TRUE(vecValsCorrect);
}

TYPED_TEST_P(QuicksortTest, sortSingleArray)
{
    lib.quicksort(vecSingle, 0, vecSingle.size() - 1);
    bool vecValsCorrect = checkResult(vecSingle);
    EXPECT_TRUE(vecValsCorrect);
}

TYPED_TEST_P(QuicksortTest, sortRepeatArray)
{
    lib.quicksort(vecRepeats, 0, vecRepeats.size() - 1);
    bool vecValsCorrect = checkResult(vecRepeats);
    EXPECT_TRUE(vecValsCorrect);
}

TYPED_TEST_P(QuicksortTest, sortSortedArray)
{
    lib.quicksort(vecSorted, 0, vecSorted.size() - 1);
    bool vecValsCorrect = checkResult(vecSorted);
    EXPECT_TRUE(vecValsCorrect);
}

//Need to register all test patterns before instantiating them
REGISTER_TYPED_TEST_CASE_P(QuicksortTest, 
    sortEvenArray,
    sortOddArray,
    sortEmptyArray,
    sortSingleArray,
    sortRepeatArray,
    sortSortedArray);

typedef ::testing::Types<QuicksortLom, QuicksortLomStd, QuicksortCTCI> QuicksortTypes;
INSTANTIATE_TYPED_TEST_CASE_P(unique_label_qtests, QuicksortTest, QuicksortTypes);