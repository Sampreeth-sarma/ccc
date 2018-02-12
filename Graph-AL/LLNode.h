#ifndef LLNODE_H_INCLUDED
#define LLNODE_H_INCLUDED

typedef struct ln{
    int data;
    struct ln* next;
}LLNode;

LLNode* insertInBegin(LLNode*, int );
void traverse(LLNode*);


#endif // LLNODE_H_INCLUDED
