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
void levelOrder(NODE<T>*root){
    queue<NODE<T>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        NODE<T>* curr=q.front();
        q.pop();
        if(curr==NULL){
            if(q.empty()){
                cout<<endl;
                break;
            }
            cout<<"\n";
            q.push(curr);
        }
        else{
            cout<<curr->data<<"\t";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

template<class T>
int ConvertToSumTree(NODE<T>*root){
    if(root==NULL){
        return 0;
    }
    int leftOld=ConvertToSumTree(root->left);
    int rightOld=ConvertToSumTree(root->right);
    int currdata=root->data;
    root->data= leftOld+rightOld;
    if(root->left){
        root->data+=root->left->data;
    }
    if(root->right){
        root->data+=root->right->data;;
    }
         
    return currdata;

}

int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    ConvertToSumTree(root);
    levelOrder(root);
    return 0;
}