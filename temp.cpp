#include <iostream>

using namespace std;

class interval {
public:
    int low;
    int high;
};

class node {
public:
    interval i;
    node* left;
    node* right;
    node* parent;
};

void copyInterval(interval i, interval& j) {
    j.low = i.low;
    j.high = i.high;
}

void transplant(node* n, node* p) {
    if (n->left == NULL || n->right == NULL) {
        if (p->right == n) {
            p->right = NULL;
            n->parent = NULL;
        }
        else {
            p->left = NULL;
            n->parent = NULL;
        }
    }
    else if (n->left == NULL) {
        if (p->right == n) {
            p->right = n->right;
            n->right->parent = p;
            n->parent = NULL;
        }
        else {
            p->left = n->right;
            n->right->parent = p;
            n->parent = NULL;
        }
    }
    else if (n->right == NULL) {
        if (p->right == n) {
            p->right = n->left;
            n->left->parent = p;
            n->parent = NULL;
        }
        else {
            p->left = n->left;
            n->left->parent = p;
            n->parent = NULL;
        }
    }
    else {
        node* k = n->right;
        while(k->left) {
            k = k->left;
        }
        k->parent->left = k->right;
        k->parent = p;
        p->left = k;
        k->left = n->left;
        k->right = n->right;
        n->parent = NULL;
    }
}

class intervalBST {
public: 
    node* high_root_;
    node* low_root_;
    
    void Insert(interval i) {
        this->highInsert(i, high_root_);
        this->lowInsert(i, low_root_);
    }
    
    void highInsert(interval i, node* root) {
        node* n = new node();
        copyInterval(i, n->i);
        n->left = NULL;
        n->right = NULL;

        if (root == NULL) {
            high_root_ = n;
            high_root_->parent = NULL;
            high_root_->left = NULL;
            high_root_->right = NULL;
        }
        else if (n->i.high < root->i.high) {
            if (root->left == NULL) {
                root->left = n;
                n->parent = root;
            }
            else {
                highInsert(i, root->left);
            }
        }
        else {
            if (root->right == NULL) {
                root->right = n;
                n->parent = root;
            }
            else {
                highInsert(i, root->right);
            }
        }
    }
    
    void lowInsert(interval i, node* root) {
        node* n = new node();
        copyInterval(i, n->i);
        n->left = NULL;
        n->right = NULL;

        if (root == NULL) {
            low_root_ = n;
            low_root_->parent = NULL;
            low_root_->left = NULL;
            low_root_->right = NULL;
        }
        else if (n->i.low < root->i.low) {
            if (root->left == NULL) {
                root->left = n;
                n->parent = root;
            }
            else {
                lowInsert(i, root->left);
            }
        }
        else {
            if (root->right == NULL) {
                root->right = n;
                n->parent = root;
            }
            else {
                lowInsert(i, root->right);
            }
        }        
    }
    
    void Delete(interval i) {
        highDelete(i, high_root_);
        lowDelete(i, low_root_);
    }
    
    void highDelete(interval i, node* root) {
        if (root == NULL) {
            return;
        }
        else if (i.high < root->i.high) {
            highDelete(i, root->left);
        }
        else if (i.high > root->i.high) {
            highDelete(i, root->right);
        }
        else if (root->i.high == i.high) {
            transplant(root, root->parent);
        }
    }
    
    void lowDelete(interval i, node* root) {
        if (root == NULL) {
            return;
        }
        else if (i.low < root->i.low) {
            lowDelete(i, root->left);
        }
        else if (i.low > root->i.low) {
            lowDelete(i, root->right);
        }
        else if (root->i.low == i.low) {
            transplant(root, root->parent);
        }
    }
    
    void Min() {
        node* n;
        n = low_root_;
        while (n->left) {
            n = n->left;
        }
        cout << "[" << n->i.low << " " << n->i.high << "]" << endl;
    }
    
    void Max() {
        node* n;
        n = high_root_;
        while (n->right) {
            n = n->right;
        }
        cout << "[" << n->i.low << " " << n->i.high << "]" << endl;
    }
    
    void LoSucc(interval i) {
        LoSucc_(i, low_root_);
    }
    
    void HiSucc(interval i) {
        HiSucc_(i, high_root_);
    }
    
    void LoSucc_(interval i, node* root) {
        if (root == NULL) {
            cout << "INVALID" << endl;
            return;
        }
        else if (root->i.low < i.low) {
            LoSucc_(i, root->right);
        }
        else if (root->i.low > i.low) {
            LoSucc_(i, root->left);
        }
        else {
            if (root->right == NULL) {
                cout << "[" << root->parent->i.low << " " << root->parent->i.high << "]" << endl;
                return;
            }
            node* n = root->right;
            while(n->left) {
                n = n->left;
            }
            cout << "[" << n->i.low << " " << n->i.high << "]" << endl;
            return;
        }
    }
    
    void HiSucc_(interval i, node* root) {
        if (root == NULL) {
            cout << "INVALID" << endl;
            return;
        }
        else if (root->i.high < i.high) {
            LoSucc_(i, root->right);
        }
        else if (root->i.high > i.high) {
            LoSucc_(i, root->left);
        }
        else {
            if (root->right == NULL) {
                cout << "[" << root->parent->i.low << " " << root->parent->i.high << "]" << endl;
                return;
            }
            node* n = root->right;
            while(n->left) {
                n = n->left;
            }
            cout << "[" << n->i.low << " " << n->i.high << "]" << endl;
            return;
        }
    }
    
    void IsOverlap(interval q) {
        IsOverlap_(q, low_root_);              
    }

    void IsOverlap_(interval q, node* root) {
        if (root == NULL) {
            cout << "0" << endl;
            return;
        }
        else if (q.high < root->i.low) {
            IsOverlap_(q, root->left);
        }
        else if (q.low > root->i.high) {
            IsOverlap_(q, root->right);
        }
        else {
            cout << "1" << endl;
            return;
        }
    }
    
    intervalBST() {
        low_root_ = NULL;
        high_root_ = NULL;
    }
    ~intervalBST() {}
};

int main() {
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int N;
        cin >> N;
        for (int j = 0; i < N; j++) {
            string input;
            cin >> input;
            
            intervalBST* tree = new intervalBST();
            
            if (input == "+") {
                interval i;
                cin >> i.low;
                cin >> i.high;
                tree->Insert(i);
            }
            else if (input == "-") {
                interval i;
                cin >> i.low;
                cin >> i.high;
                tree->Delete(i);
            }
            else if (input == "max") {
                tree->Max();
            }
            else if (input == "min") {
                tree->Min();
            }
            else if (input == "lsucc") {
                interval i;
                cin >> i.low;
                cin >> i.high;
                tree->LoSucc(i);
            }
            else if (input == "hsucc") {
                interval i;
                cin >> i.low;
                cin >> i.high;
                tree->HiSucc(i);
            }
            else if (input == "overlap") {
                interval i;
                cin >> i.low;
                cin >> i.high;
                tree->IsOverlap(i);
            }
        }
    }
}