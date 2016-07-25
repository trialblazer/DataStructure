#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
class TreeNode {
public:
    TreeNode(int d, TreeNode* l=NULL, TreeNode* r=NULL):data(d), right(r), left(l) {}
    int data;
    TreeNode* right;
    TreeNode* left;
};

class AVL_Tree {
public:
    AVL_Tree():root(NULL) {};
    ~AVL_Tree() {destory(root);};
    bool insert(const int);
    bool remove(const TreeNode*&);
    TreeNode*& search(const int);
    void destory(TreeNode*);

    void level_order(TreeNode*);

    void in_order() {_in_order(root);}
    void pre_order() {_pre_order(root);}
    void post_order() {_post_order(root);}

    int size(TreeNode*);

private:
    void _pre_order(TreeNode*);
    void _in_order(TreeNode*);
    void _post_order(TreeNode*);


    int height(TreeNode*&);
    void rotateL(TreeNode**&);
    void rotateR(TreeNode**&);
    void rotateRL(TreeNode**&);
    void rotateLR(TreeNode**&);

private:
    TreeNode* root;
};

#endif // AVL_TREE_H
