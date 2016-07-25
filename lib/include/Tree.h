#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

template <class T>
struct BinTreeNode {
    T data;
    BinTreeNode<T> *rchild;
    BinTreeNode<T> *lchild;
    BinTreeNode():rchild(NULL), lchild(NULL) {}
    BinTreeNode<T>(T value, BinTreeNode<T>* r = NULL, BinTreeNode<T>* l = NULL):
        data(value), rchild(NULL), lchild(NULL) {}
};

template <class T>
class BinaryTree {
public:
    BinaryTree():root(NULL) {};
    BinaryTree(T s):sign(s), root(NULL) {};
    BinaryTree(BinaryTree<T>& t);
    ~BinaryTree();

    bool isempty() {return (root==NULL);}
    void destory(BinTreeNode<T>* current) {if (current != NULL) _destory(current, root);}
    bool insert_(T value);
    bool remove_(T value);

    BinTreeNode<T>* find_(T value) {return _find(value, root);}
    BinTreeNode<T>* get_root() {return root;}
    BinTreeNode<T>* get_parent(BinTreeNode<T> *current) {
        return current==NULL? NULL:_parent(current, root);}
    BinTreeNode<T>* get_rchild(BinTreeNode<T> *current) {
        return current==NULL? NULL:current->rchild;}
    BinTreeNode<T>* get_lchild(BinTreeNode<T> *current) {
        return current==NULL? NULL:current->lchild;}
    T get_data(BinTreeNode<T> *current) {
        return current==NULL? NULL:current->data;}

    void pre_order() {_preOrder(root);};
    void in_order() {_inOrder(root);};
    void post_order() {_postOrder(root);};

protected:
    BinTreeNode<T>* _parent(BinTreeNode<T> *current, BinTreeNode<T>* subtree);
    BinTreeNode<T>* _find(T value, BinTreeNode<T> *subtree);
    void _destory(BinTreeNode<T> *current, BinTreeNode<T> *subtree);
    void _preOrder(BinTreeNode<T> *subtree);
    void _inOrder(BinTreeNode<T> *subtree);
    void _postOrder(BinTreeNode<T> *subtree);
    void _remove(BinTreeNode<T>* current);
    void _copy(const BinaryTree& t);

private:
    BinTreeNode<T> *root;
    T sign;
};

#endif // TREE_H
