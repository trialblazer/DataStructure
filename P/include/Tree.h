#ifndef TREE_H
#define TREE_H




















































































/*template <class T>
class BinTreeNode {
private:
    T data;
    BinTreeNode<T>* lchild;
    BinTreeNode<T>* rchild;
public:
    BinTreeNode(T value) {data = value; lchild = NULL; rchild = NULL;}
    BinTreeNode(T value, l=NULL, r=NULL) {data = value; lchild = l; rchild = r;}
    T& getdata() {return data;}
    BinTreeNode<T>* getlchild() {return lchild;}
    BinTreeNode<T>* getrchild() {return rchild;}
};

template <class T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(BinaryTree& b);

    BinTreeNode<T>* getroot() {return root;}
    int height();
    bool isempty() {return root==NULL}
    BinTreeNode<T>* parent(BinTreeNode<T>* current);
    BinTreeNode<T>* lchild(BinTreeNode<T>* current);
    BinTreeNode<T>* rchild(BinTreeNode<T>* current);
    int Size();

    void preOrder() {_preOrder(root);}
    void postOrder() {_postOrder(root);}
    void inOrder() {_inOrder(root);}
    void levelOrder() {_levelOrder(root);}

    int Insert(const T& item);
    BinTreeNode<T>* Find(BinTreeNode<T>* current);

private:
    BinTreeNode<T>* root;
    T RefValue;

protected:
    bool _insert(BinTreeNode<T>*& subtree, const T& value);
    bool _find(BinTreeNode<T>* subtree, const T& item)
    int _height(BinTreeNode<T>* subtree);
    int _size(BinTreeNode<T>* subtree);
    void _destroy(BinTreeNode<T>* subtree);

    void _preOrder(BinTreeNode<T>* current);
    void _postOrder(BinTreeNode<T>* current);
    void _levelOrder(BinTreeNode<T>* current);
    void _inOrder(BinTreeNode<T>* current);

    BinTreeNode<T>* _parent(BinTreeNode<T>* current);

    friend istream& operator >> (istream& i, BinaryTree<T>& t);
    friend ostream& operator << (ostream& o, BinaryTree<T>& t)
};
*/
#endif // TREE_H
