#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<class T>
class NODE{
public:
    T data;
    NODE* left;
    NODE* right;

    NODE(T data){
        this->data=data;
        left=right=NULL;
    }

};
static int idx=-1;
template<class T>
NODE<T>* createTree(vector<T>& nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    NODE<T>* currNode= new NODE<T>(nodes[idx]);
    currNode->left=createTree(nodes);
    currNode->right=createTree(nodes);

    return currNode;
}
template<class T>
void Preorder_Traversal(NODE<T>* root){
    if(root==NULL){
        // cout<<"NULL ";
        return;
    }
    cout<<root->data<<" ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}
template<class T>
void Inorder_Traversal(NODE<T>* root){
    if(root==NULL){
        // cout<<"NULL ";
        return;
    }
    Inorder_Traversal(root->left);
    cout<<root->data<<" ";
    Inorder_Traversal(root->right);
}
template<class T>
void Postorder_Traversal(NODE<T>* root){
    if(root==NULL){
        // cout<<"NULL ";
        return;
    }
    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right);
    cout<<root->data<<" ";
}

template<class T>
void levelOrder(NODE<T>* root){
    if(root==NULL){
        return;
    }
    queue<NODE<T>*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        NODE<T>* curr= Q.front();
        Q.pop();
        if(curr==NULL){
            if(Q.empty()){
                break;
            }
            Q.push(NULL);//basically NULL tracks newline
            cout<<endl;
        }
        else{
            cout<<curr->data<<" ";
            
            if(curr->left){//if !NULL
                Q.push(curr->left);
            }
            if(curr->right){
                Q.push(curr->right);
            }
        }
    }
}
template<class T>
int height(NODE<T>* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}


int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    Preorder_Traversal(root);
    cout<<endl;
    Inorder_Traversal(root);
    cout<<endl;
    Postorder_Traversal(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    return 0;
}