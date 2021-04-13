#include <memory>
#include <tuple>

template <class myType>
struct Node
{
    Node(myType rhs) : value{ rhs }, left{ nullptr }, right{ nullptr } {};

    myType value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

template <class myType>
struct BinaryTree
{
    BinaryTree() : root{ nullptr } {};
   
    void addNode(myType value)
    {
        if (root == nullptr)
            root = std::make_unique<Node<myType>>(value);
        else
            root = addAtNode(value, move(root));
    };

    int returnDepth()
    {
        int depth;
        std::tie (root, depth) = depthAtNode(move(root));
        return depth;
    };

private:
    std::unique_ptr<Node<myType>> root;

    std::unique_ptr<Node<myType>> addAtNode(int value, std::unique_ptr<Node<myType>> node)
    {
        if (value < node->value)
            if (node->left == nullptr)
                node->left = std::make_unique<Node<myType>>(value);
            else
                node->left = addAtNode(value, move(node->left));
        else if (node->right == nullptr)
            node->right = std::make_unique<Node<myType>>(value);
        else
            node->right = addAtNode(value, move(node->right));

        return move(node);
    };

    std::tuple<std::unique_ptr<Node<myType>>, int> depthAtNode(std::unique_ptr<Node<myType>> node)
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
};
