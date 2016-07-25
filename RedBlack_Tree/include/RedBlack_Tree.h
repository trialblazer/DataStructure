#ifndef REDBLACK_TREE_H
#define REDBLACK_TREE_H

#include <iostream>

class TreeNode {
public:
    bool red_black;  /// true is red
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode* parent;

public:
    TreeNode(int v, bool s = true):red_black(s),lchild(NULL),rchild(NULL),data(v) {}
    TreeNode():red_black(true),lchild(NULL),rchild(NULL) {}
};

class RedBlack_Tree {
public:
    RedBlack_Tree():root(NULL) {}
    ~RedBlack_Tree() {destory(root);}
    bool insert(int);
    bool remove(int);
    bool empty() {return root == NULL;}
    void in_order() {_in_order(root);}

private:
    TreeNode** locate(int);
    void adjust(TreeNode**);
    void adjust_(TreeNode**);
    void destory(TreeNode*);
    void _in_order(TreeNode* sub);

private:
    TreeNode* root;
};

#endif // REDBLACK_TREE_H
