#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    //constructor
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildtree(Node*root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

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

void buildfromlevelorder(Node*&root){
    queue<Node*>q;
    cout<<"enter value of root "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        cout<<"enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){
    Node*root=NULL;
    buildfromlevelorder(root);
    levelordertraversal(root);
    // creating node
    /*root=buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"printing output of level order traversal "<<endl;
    levelordertraversal(root);
    cout<<endl;
    cout<<"inorder traversal is "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is "<<endl;
    postorder(root);
    cout<<endl;*/
}