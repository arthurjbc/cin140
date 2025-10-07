#include <iostream>

using namespace std;

bool rot = false;

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
                cout << "" << rt->val << " "; 
                printIn(rt->right);
            }
        }

        void printPos(BSTnode* rt){
            if (rt == nullptr) return;
            else {
                printPos(rt->left);
                printPos(rt->right);
                cout << "" << rt->val << " ";
            }
        }

        void printPre(BSTnode* rt){
            if (rt == nullptr) return;
            else {
                cout << "" << rt->val << " ";
                printPre(rt->left);
                printPre(rt->right);
            }
        }

        BSTnode* insertH(BSTnode* rt, int v) {
            if (rt == nullptr) {
                if (size == 0){
                    cout << "no rotation!\n";
                }
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
            
            if (balance < -1 && v >= rt->right->val) {
                rot = true;
                cout << rt->val << " is unbalanced, L-rotation!\n";
                return leftRotate(rt);
            } //R
            
            else if (balance > 1 && v < rt->left->val) {
                rot = true;
                cout << rt->val << " is unbalanced, R-rotation!\n";
                return rightRotate(rt);
            } //L

            else if (balance > 1 && v >= rt->left->val) {    //RL
                rot = true;
                cout << rt->val << " is unbalanced, LR-rotation!\n";
                rt->left = leftRotate(rt->left);
                return rightRotate(rt); 
            }

            else if (balance < -1 && v < rt->right->val) {    //LR
                rot = true;
                cout << rt->val << " is unbalanced, RL-rotation!\n";
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }

            else if (rot == false && rt == root){
                cout << "no rotation!\n";
            }

            return rt;
        }

        void insert(int v) {
            root = insertH(root, v);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    AVL *avl = new AVL();

    int n;
    cin >> n;

    int ent;
    for (int i=0; i<n; i++){
        cin >> ent;
        cout << "insert " << ent << ": ";
        avl->insert(ent);
        rot = false;
    }
    
    cout << "preorder: ";
    avl->printPre(avl->getRoot());
    cout << "\n";
    cout << "inorder: ";
    avl->printIn(avl->getRoot());
    cout << "\n";
    cout << "postorder: ";
    avl->printPos(avl->getRoot());
    cout << "\n";

    delete avl;
}