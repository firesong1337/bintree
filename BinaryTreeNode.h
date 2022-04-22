
#ifndef CPPTHIRD_BINARYTREENODE_H
#define CPPTHIRD_BINARYTREENODE_H


class BinaryTreeNode {
public:
    BinaryTreeNode(int data,
                   BinaryTreeNode *left = nullptr,
                   BinaryTreeNode *right = nullptr
    );
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};


#endif //CPPTHIRD_BINARYTREENODE_H
