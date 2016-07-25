#ifndef TREE_H
#define TREE_H

struct Tree_node {
    int value;
    Tree_node *right;
    Tree_node *left;
};

class Tree {
public:
    Tree();
    ~Tree();
    bool insert(int value);
    void remove(int value);
    void destory();
    bool find(int key);
    void preorder();
    void inorder();
    void postorder();
    bool isempty();
    int getsize();

protected:
    void preorder_(Tree_node *pointer);
    void inorder_(Tree_node *pointer);
    void postorder_(Tree_node *pointer);
    void destory_(Tree_node** pointer);
    bool find_(int key, Tree_node *pointer);
    void remove_(Tree_node **pointer, int value);
    Tree_node* search_(int key, Tree_node *pointer);

private:
    Tree_node *root;
    int size;
};

#endif // TREE_H
