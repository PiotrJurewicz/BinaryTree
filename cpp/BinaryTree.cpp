#include "BinaryTree.hpp"

//public methods
void BinaryTree::addNode(int value)
{
    if (root == nullptr)
        root = std::make_unique<Node>(value);
    else
        root = addAtNode(value, move(root));
};

int BinaryTree::returnDepth()
{
    int depth;
    std::tie (root, depth) = depthAtNode(move(root));
    return depth;
};

//private methods
std::unique_ptr<Node> BinaryTree::addAtNode(int value, std::unique_ptr<Node> node)
{
    if (value < node->value)
        if (node->left == nullptr)
            node->left = std::make_unique<Node>(value);
        else
            node->left = addAtNode(value, move(node->left));
    else if (node->right == nullptr)
        node->right = std::make_unique<Node>(value);
    else
        node->right = addAtNode(value, move(node->right));

    return move(node);
};

std::tuple<std::unique_ptr<Node>, int> BinaryTree::depthAtNode(std::unique_ptr<Node> node)
{
    int depthAtLeft;
    int depthAtRight;

    if (node == nullptr)
        return { nullptr, 0 };
    else
    {
        std::tie (node->left, depthAtLeft) = depthAtNode(move(node->left));
        std::tie (node->right, depthAtRight) = depthAtNode(move(node->right));

        return std::make_tuple( move(node), depthAtLeft > depthAtRight ? depthAtLeft + 1 : depthAtRight + 1 );
    }
};

