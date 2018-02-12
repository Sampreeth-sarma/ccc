#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct BSTNode
{
    char* data;
    BSTNode* left;
    BSTNode* right;
};
BSTNode* createNode(char* str)
{
    BSTNode* n=(BSTNode*)malloc(sizeof(BSTNode));
    n->data=(char*)malloc(strlen(str)+1);
    strcpy(n->data,str);
    n->left=NULL;
    n->right=NULL;
    return n;
}

BSTNode* insertNode(BSTNode* root,char* str)
{
    if(root==NULL)
        return createNode(str);
    else if(strcmp(root->data,str)<0)
        root->right=insertNode(root->right,str);
    else
        root->left=insertNode(root->left,str);
    return root;
}

/*BSTNode* it_insertNode(BSTNode* root,char* str){
    BSTNode* nn = createNode(str);
    if(!root)
        return nn;
    BSTNode* orig_root = root;
    while(root){
        BSTNode* parent = root;
        if(strcmp(root->data, str)<0)
            root = root->right;
        else
            root = root->left;
    }
    if(strcmp(parent->data, str)<0)
        parent->right = nn;
    else
        parent->left = nn;
    return orig_root;
}*/

void inorder(BSTNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%s\n",root->data);
        inorder(root->right);
    }
}

int height(BSTNode* root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + lh>rh?lh:rh;

}

void levelOrder(BSTNode* root)
{
    if(root==NULL)
        return;
    queue<BSTNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BSTNode* f=q.front();
        q.pop();
        if(f==NULL)
        {
            q.push(NULL);
            printf("\n");
        }
        else
        {
            printf("%s  ",f->data);

            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
}

int main()
{
    BSTNode* root = NULL;
    char str[20];
    while(scanf("%s",str)!=-1)
    {
        root=insertNode(root,str);
    }
    printf("the elements are\n");
    inorder(root);
    printf("\n");
    levelOrder(root);
    return 0;
}
