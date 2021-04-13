#include "BinaryTree.hpp"
#include "gtest/gtest.h"

class binaryTreeTest : public ::testing::Test
{
public:
    BinaryTree<int> binaryTree;
};

//Sugested test name: When[something]Than[something]Is[something]

TEST_F(binaryTreeTest, WhenAdd0ThanSmallerAndSmallerThanValueThanDepthIs3)
{
    binaryTree.addNode(0);
    binaryTree.addNode(-1);
    binaryTree.addNode(-2);
    ASSERT_EQ(3, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd0ThanLargerAndSmallerThanValueThanDepthIs2)
{
    binaryTree.addNode(0);
    binaryTree.addNode(1);
    binaryTree.addNode(-1);
    ASSERT_EQ(2, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd0ThanSmallerAndLargerThanValueThanDepthIs2)
{
    binaryTree.addNode(0);
    binaryTree.addNode(-1);
    binaryTree.addNode(1);
    ASSERT_EQ(2, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd0ThanSmalerValueThanDepthIs2)
{
    binaryTree.addNode(0);
    binaryTree.addNode(-1);
    ASSERT_EQ(2, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd0ThanLargerValueThanDepthIs2)
{
    binaryTree.addNode(0);
    binaryTree.addNode(1);
    ASSERT_EQ(2, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd3TimesSameValueThanDepthIs3)
{
    binaryTree.addNode(0);
    binaryTree.addNode(0);
    binaryTree.addNode(0);
    ASSERT_EQ(3, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAdd2TimesSameValueThanDepthIs2)
{
    binaryTree.addNode(0);
    binaryTree.addNode(0);
    ASSERT_EQ(2, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenAddNodeThanDepthIs1)
{
    binaryTree.addNode(0);
    ASSERT_EQ(1, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, WhenTreeCreatedThanDepthIs0)
{
    ASSERT_EQ(0, binaryTree.returnDepth());
}

TEST_F(binaryTreeTest, firstTest)
{
    ASSERT_TRUE(true);
}
