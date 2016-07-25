#ifndef TREE_H
#define TREE_H

class TreeNode {
public:
    int value;
    TreeNode * right;
    TreeNode * left;
};

class Tree {
public:
    Tree();
    ~Tree();
    bool empty();
    bool insert(int value);
    bool insert1(int value);
    bool find(int value);
    void destory(TreeNode * pointer);
    int depth();
    bool remove(int value);
    void intravel();

private:
    bool _insert1(int value, TreeNode **pointer);
    bool _find(int value, TreeNode *pointer);
    bool _remove(int value, TreeNode **pointer);
    void _intravel(TreeNode * root);
    int _depth(TreeNode * pointer);

private:
    TreeNode * root;
    int total;
};

#endif // TREE_H
