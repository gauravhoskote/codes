#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* Newnode(int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int key){
    if (root == NULL){
        return Newnode(key);
    }
    else{
        if(key < root->val){
            root->left = insert(root->left, key);
        }else{
            root->right = insert(root->right, key);
        }
    }
    return root;
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root != NULL){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int heightofBST(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = heightofBST(root->left);
    int rh = heightofBST(root->right);
    return max(lh, rh) + 1;
}

int sizeofBST(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int ls = sizeofBST(root->left);
    int rs = sizeofBST(root->right);
    return ls + rs + 1;
}

bool searchBST(struct Node* root, int key){
    if(root == NULL){
        return false;
    }
    else{
        if(root->val < key){
            return searchBST(root->right, key);
        }else if(root->val > key){
            return searchBST(root->left, key);
        }else{
            return true;
        }
    }
}
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
    
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

struct Node* deleteBST(struct Node* root, int k){
    if(root == NULL){
        return root;
    }
    if(root->val < k){
        root->right = deleteBST(root->right, k);
    }else if(root->val > k){
        root->left = deleteBST(root->left, k);
    }else{
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteBST(root->right, temp->val);
    }
    return root;
}

int main() {
    
    
    
    return 0;
}
