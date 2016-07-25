#ifndef TREE_H
#define TREE_H

class Tree_Node {
public:
    int value;
    Tree_Node *right;
    Tree_Node *left;
};

class Tree {
public:
    Tree();
    ~Tree();
    bool insert(int value);
    bool remove(int value);
    void prin();
    void destory();

protected:
    bool _insert(int value, Tree_Node **pointer);
    bool _remove(int value, Tree_Node **pointer);
    void _destory(Tree_Node **pointer);
    void _prin(Tree_Node *pointer);

private:
    Tree_Node *root;
    int total;
};

#endif // TREE_H
