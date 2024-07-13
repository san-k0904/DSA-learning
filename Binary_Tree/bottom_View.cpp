#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void BottomView(NODE<T>* root){
    queue<pair<NODE<T>*,int>> q;//NODE, Horizontal Distance
    map<int,int> m;//Horizontal Distance, NODE->data
    q.push(make_pair(root,0));//just for understanding could've done {root,0}
    while(!q.empty()){//basically go level order
        auto currNode= q.front().first;
        int currHD= q.front().second;
        q.pop();

        m[currHD]=currNode->data;//don't need any condition as we anyway have to overwrite if a value is found at bottom

        if(currNode->left){//!NULL
            q.push({currNode->left,currHD-1});//coz going left reduces the Horizontal Distance
        }
        if(currNode->right){
            q.push({currNode->right,currHD+1});
        }
    } 

    for(auto i:m){//in map automatically key with lesser value comes first
        cout<<i.second<<" ";
    }
    cout<<endl;

}
int main(){

    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    NODE<int>* root=createTree(nodes);
    BottomView(root);
    return 0;
}