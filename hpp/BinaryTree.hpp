#include <memory>
#include <tuple>

struct Node
{
    Node(int rhs) : value{ rhs }, left{ nullptr }, right{ nullptr } {};

    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

struct BinaryTree
{
    BinaryTree() : root{ nullptr } {};

    void addNode(int value);
    int returnDepth();

private:
    std::unique_ptr<Node> root;

    std::unique_ptr<Node> addAtNode(int value, std::unique_ptr<Node> node);
    std::tuple<std::unique_ptr<Node>, int> depthAtNode(std::unique_ptr<Node> node);
};
