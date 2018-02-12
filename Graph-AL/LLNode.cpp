#include "LLNode.h"
#include<stdlib.h>
#include<stdio.h>
LLNode* createNode(int data)
{
    LLNode* n=(LLNode*)malloc(sizeof(LLNode));
    n->data=data;
    n->next=NULL;
    return n;
}
LLNode* insertInBegin(LLNode* head, int data)
{
    LLNode* nn = createNode(data);
    nn->next = head;
    return nn;
}
void traverse(LLNode* head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}



