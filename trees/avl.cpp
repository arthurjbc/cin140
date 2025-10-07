#include <iostream>

using namespace std;

struct BSTnode {
    int val;
    BSTnode* right;
    BSTnode* left;
    int height;
    BSTnode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class AVL {
    private:
        BSTnode* root;
        int size;
    public:

        void freeR (BSTnode* rt){
            if (rt == nullptr) return;
            else{
                freeR(rt->left);
                freeR(rt->right);
                delete rt;
            }
        }

        AVL() {
            root = nullptr;
            size = 0;
        }

        ~AVL(){
            freeR(root);
            root = nullptr;
        }

        BSTnode* getRoot(){
            return root;
        }

        int height (BSTnode* rt){
            if (rt == nullptr){
                return -1;
            }
            return rt->height;
        }

        BSTnode* leftRotate(BSTnode* rt){
            BSTnode* r = rt->right;
            BSTnode* rl = r->left;

            r->left = rt;
            rt->right = rl;

            rt->height = max(height(rt->left), height(rt->right)) + 1;
            r->height = max(height(r->left), height(r->right)) + 1;

            return r;
        }

        BSTnode* rightRotate(BSTnode* rt){
            BSTnode* l = rt->left;
            BSTnode* lr = l->right;

            l->right = rt;
            rt->left = lr;

            rt->height = max(height(rt->left), height(rt->right)) + 1;
            l->height = max(height(l->left), height(l->right)) + 1;

            return l;
        }


        int getBalance(BSTnode* rt){
            if (rt == nullptr) return 0;
            return height(rt->left) - height(rt->right);
        }

        void printIn(BSTnode* rt){
            if (rt == nullptr) return;
            else {
                printIn(rt->left);
                cout << "(" << rt->val << ") "; 
                printIn(rt->right);
            }
        }

        void printPos(BSTnode* rt){
            if (rt == nullptr) return;
            else {
                printPos(rt->left);
                printPos(rt->right);
                cout << "(" << rt->val << ") ";
            }
        }

        void printPre(BSTnode* rt){
            if (rt == nullptr) return;
            else {
                cout << "(" << rt->val << ") ";
                printPre(rt->left);
                printPre(rt->right);
            }
        }

        BSTnode* insertH(BSTnode* rt, int v) {
            if (rt == nullptr) {
                size++;
                return new BSTnode(v);
            }
            
            if (v < rt->val) {
                rt->left = insertH(rt->left, v);
            } else {
                rt->right = insertH(rt->right, v);
            }

            rt->height = 1 + max(height(rt->left), height(rt->right));

            int balance = getBalance(rt);
            
            if (balance < -1 && v >= rt->right->val) return leftRotate(rt); //R
            
            if (balance > 1 && v < rt->left->val) return rightRotate(rt); //L

            if (balance > 1 && v >= rt->left->val) {    //RL
                rt->left = leftRotate(rt->left);
                return rightRotate(rt); 
            }

            if (balance < -1 && v < rt->right->val) {    //LR
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }

            return rt;
        }

        void insert(int v) {
            root = insertH(root, v);
        }
};

int main(){
    AVL *avl = new AVL();
    int a[11] = {20, 10, 15, 30, 25, 9, 7, 8, 12, 6, 5};
    for (int i=0; i<11; i++){
        avl->insert(a[i]);
    }
    avl->printPos(avl->getRoot());
    cout << "\n";
    avl->printIn(avl->getRoot());
    cout << "\n";
    avl->printPre(avl->getRoot());
    cout << "\n";

    delete avl;
}