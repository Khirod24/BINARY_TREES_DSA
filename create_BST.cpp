#include<iostream>
using namespace std;
#include<queue>
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};
void levelordertraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->left){
              q.push(temp->left);
            }
            if(temp->right){
              q.push(temp->right);
            }
        }
        
    }

}
void inorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" "; 
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }
     
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
Node*insertintobst(Node*root,int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data){
        root->right=insertintobst(root->right,d);
    }
    else{
        root->left=insertintobst(root->left,d);
    }

    return root;

}
void takeinput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintobst(root,data);
        cin>>data;
    }

}

Node*minval(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node*maxval(Node*root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deletefrombst(Node*root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        //0 child
        if(root->right==NULL && root->left==NULL){
            delete root;
            return NULL;
        }
        //1 child
        // left child
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->right!=NULL && root->left!=NULL){
            int minvalue=minval(root->right)->data;
            root->data=minvalue;
            root->right=deletefrombst(root->right,minvalue);
        }

    }
    else if(root->data>val){
        //left part ke lie
        root->left=deletefrombst(root->left,val);
        return root;
    }
    else{
        //right part ke lie
        root->right=deletefrombst(root->right,val);
        return root;
    }
}



int main(){
    Node*root=NULL;
    cout<<"ENTER DATA TO CREATE BST "<<endl;
    takeinput(root);
    cout<<"printing the bst "<<endl; 
    levelordertraversal(root);
    cout<<endl;
    cout<<"printing the inorder "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"printing the preorder "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"printing the postorder "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"printing min value "<<minval(root)->data<<endl;
    cout<<"printing max value "<<maxval(root)->data<<endl;

    // root=deletefrombst(root,30);
    root=deletefrombst(root,90);

    cout<<"printing the bst "<<endl; 
    levelordertraversal(root);
    cout<<endl;
    cout<<"printing the inorder "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"printing the preorder "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"printing the postorder "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"printing min value "<<minval(root)->data<<endl;
    cout<<"printing max value "<<maxval(root)->data<<endl;

    return 0;
}