#include<iostream>
#include<vector>
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
int height(NODE<T>* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

template<class T>
int diameter_approach1(NODE<T>* root){
    if(root==NULL){
        return 0;
    }
    int rootDia = height(root->left)+height(root->right)+1;//the height function itself runs O(n) times
    int leftSubDia= diameter_approach1(root->left);//while diameter _approach1 run n times so 
    int rightSubDia=diameter_approach1(root->right);//total time complexity= O(n*n)=O(n^2)
    
    return max(rootDia,max(leftSubDia,rightSubDia));
}

template<class T>
pair<int,int> diameter_approach2(NODE<T>* root){//O(n)
    if(root==NULL){
        return {0,0};
    }
    //pair=> (diameter, height)
    pair<int,int>leftInfo= diameter_approach2(root->left);//LeftDiameter, LeftHeight
    pair<int,int>rightInfo= diameter_approach2(root->right);//RightDiameter, RightHeight
    int currDiameter= leftInfo.second+rightInfo.second+1;//LeftHeight+RightHeight+1

    int finalDia= max(currDiameter, max(leftInfo.first,rightInfo.first));//max(currDia, max( leftDiameter, rightDiameter))
    int finalHeight= max(leftInfo.second, rightInfo.second)+1; //max(leftHeight,rightHeight)+1

    return {finalDia,finalHeight};//or make_pair(...)
}

int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    cout<<"Via approach 1: "<<diameter_approach1(root)<<"\n";
    pair<int,int> Dia= diameter_approach2(root);
    cout<<"Via approach 2: "<<Dia.first<<"\n";
    return 0;
}