#include <iostream>
#include <stdlib.h>
#include <stdio.h>



struct BSTNode
{
    int data;
    BSTNode *left, *right;
    int bf;
};


int getBF(BSTNode*);
void rotateLeft(BSTNode*);
void rotateRight(BSTNode*);
int getHeight(BSTNode*);
BSTNode* createBSTNode(int);
BSTNode* deleteBSTNode(BSTNode*,int);

BSTNode* getMaxBSTNode(BSTNode* root)
{
    if(root->right==NULL)
        return root;
    else
        return getMaxBSTNode(root->right);
}

void rotateLeft(BSTNode* root)
{
    BSTNode* n=createBSTNode(root->data);
    root->data=root->right->data;
    n->left=root->left;
    n->right=root->right->left;
    n->bf=getBF(n);
    root->left=n;
    root->right=deleteBSTNode(root->right,root->data);
    root->bf=getBF(root);
}

void rotateRight(BSTNode* root)
{
    BSTNode* n=createBSTNode(root->data);
    root->data=root->left->data;
    n->right=root->right;
    n->left=root->left->right;
    n->bf=getBF(n);
    root->right=n;
    root->left=deleteBSTNode(root->left,root->data);
    root->bf=getBF(root);

}
BSTNode* deleteBSTNode(BSTNode* root,int d)
{
    if(root==NULL)
        return NULL;
    if(root->data==d&&root->left==NULL&&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    else if(root->data>d)
        root->left=deleteBSTNode(root->left,d);
    else if(root->data<d)
        root->right=deleteBSTNode(root->right,d);
    else
    {
        if(root->left!=NULL&&root->right==NULL)
        {
            free(root);
            return root->left;
        }
        else if(root->right!=NULL&&root->left==NULL)
        {
            free(root);
            return root->right;
        }
        else
        {
            BSTNode* replace=getMaxBSTNode(root->left);
            root->data=replace->data;
            root->left=deleteBSTNode(root->left,replace->data);

        }
    }

    root->bf = getBF(root);

    if(root->bf == -2)
    {
        // Right Heavy
        if(root->right->bf==-1)
        {
            //RR:perform left rotation
            rotateLeft(root);

        }
        else
        {
            //RL
            rotateRight(root->right);
            rotateLeft(root);
        }
    }
    else if(root->bf ==2)
    {
        // Left Heavy
        if(root->left->bf==-1)
        {
            //LR
            rotateLeft(root->left);
            rotateRight(root);
        }
        else
        {
            //LL:perform right rotation
            rotateRight(root);
        }
    }
    return root;
}

BSTNode *createBSTNode(int d)
{
    BSTNode *bt = (BSTNode*)malloc(sizeof(BSTNode));
    bt->left = bt->right = NULL;
    bt->data = d;
    bt->bf=0;
    return bt;
}

void inOrder(BSTNode *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d (%d)  ", root->data,root->bf);
    inOrder(root->right);
}


int getHeight(BSTNode* root)
{
    if(root==NULL)
        return 0;
    int lh=getHeight(root->left);
    int rh=getHeight(root->right);
    return 1+(lh>rh?lh:rh);
}
int getBF(BSTNode* root)
{
    if(root==NULL)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}

BSTNode *insertBSTNode(BSTNode *root, int d)
{
    if(root==NULL)
        return createBSTNode(d);
    if(d<=root->data)
        root->left = insertBSTNode(root->left, d);
    else
        root->right = insertBSTNode(root->right, d);

    root->bf = getBF(root);

    if(root->bf == -2)
    {
        // Right Heavy
        if(root->right->bf==-1)
        {
            //RR:perform left rotation
            rotateLeft(root);
        }
        else
        {
            //RL
            rotateRight(root->right);
            rotateLeft(root);
        }
    }
    else if(root->bf ==2)
    {
        // Left Heavy
        if(root->left->bf==-1)
        {
            //LR
            rotateLeft(root->left);
            rotateRight(root);
        }
        else
        {
            //LL:perform right rotation
            rotateRight(root);
        }
    }

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    int i, x;
    BSTNode *root = NULL;
    for(i=1; i<=n; i++)
    {
        scanf("%d", &x);
        root = insertBSTNode(root, x);
    }
    //printf("the root is %d ",root->data);
    inOrder(root);

    return 0;
}
