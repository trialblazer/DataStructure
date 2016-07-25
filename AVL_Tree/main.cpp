#include <iostream>

#include <iostream>
#include <queue>

using namespace std;

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


int AVL_Tree::height(TreeNode*& sub) {
    if (sub == NULL)
        return 0;
    int right = height(sub->right);
    int left = height(sub->left);
    return right>left? right+1:left+1;
}

void AVL_Tree::rotateL(TreeNode**& sub) {
    TreeNode *r = (*sub)->right, *temp = *sub;
    temp->right = r->left;
    r->left = temp;
    *sub = r;
}

void AVL_Tree::rotateR(TreeNode**& sub) {
    TreeNode *l = (*sub)->left, *temp = *sub;
    temp->left = l->right;
    l->right = temp;
    *sub = l;
}

void AVL_Tree::rotateLR(TreeNode**& sub) {
    TreeNode *temp = *sub, *l = (*sub)->left, *r = (*sub)->right;
    TreeNode *lr = l->right;
    l->right = lr->left;
    lr->left = l;
    temp->left = lr->right;
    lr->right = r;
    *sub = lr;
}

void AVL_Tree::rotateRL(TreeNode**& sub) {
    TreeNode *temp = *sub, *l = (*sub)->left, *r = (*sub)->right;
    TreeNode *rl = r->left;
    r->left = rl->right;
    rl->right = r;
    temp->right = rl->left;
    rl->left = l;
    *sub = rl;
}

bool AVL_Tree::insert(const int value) {
    TreeNode *add = new TreeNode(value), *r = root;
    TreeNode** pos = &r;
    if (add == NULL)
        return false;
    while (*pos != NULL) {
        if (value < (*pos)->data)
            *pos = (*pos)->left;
        else
            *pos = (*pos)->right;
    }
    *pos = add;
    return true;
}


void AVL_Tree::_in_order(TreeNode* start) {
    if (start == NULL)
        return;
    _in_order(start->left);
    cout << start->data << "  ";
    _in_order(start->right);
}


void AVL_Tree::_pre_order(TreeNode* start) {
    if (start == NULL)
        return;
    cout << start->data << "  ";
    _pre_order(start->left);
    _pre_order(start->right);
}

void AVL_Tree::_post_order(TreeNode* start) {
    if (start == NULL)
        return;
    _post_order(start->left);
    _post_order(start->right);
    cout << start->data << "  ";
}

void AVL_Tree::level_order(TreeNode* start) {
    if (root == NULL)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->data << "  ";
        q.push(temp->left);
        q.push(temp->right);
    }
}

int AVL_Tree::size(TreeNode* start) {
    if (start == NULL)
        return 0;
    int right = size(start->left);
    int left = size(start->right);
    return right+left+1;
}


void AVL_Tree::destory(TreeNode* start) {
    if (start == NULL)
        return;
    destory(start->left);
    destory(start->right);
    delete start;
    start = NULL;
}



void test() {
    int a[10] = {9,3, 12,23,6,7,10,4,8,11};
    AVL_Tree avlt;
    for (int i=0; i<10; i++) {
        /// cin >> a[i];
        avlt.insert(a[i]);
    }
    avlt.pre_order();
    cout << endl;
    ///avlt.in_order();
    ///cout << endl;
    ///avlt.post_order();
    cout << endl;
}

int main()
{
    test();
    return 0;
}
