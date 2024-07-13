>*> Q;
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