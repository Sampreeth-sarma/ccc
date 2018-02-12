
#include<cstdio>
#include<cstdlib>
#include<string.h>
  struct LLNode
  {
      char* name;
      LLNode *next;
  };
  LLNode* createNode(char* name)
  {
      LLNode* nn=(LLNode*)malloc(sizeof(LLNode));
      nn->name=(char*)malloc(strlen(name)+1);
      strcpy(nn->name,name);
      nn->next=NULL;
      return nn;
  }
  LLNode* insertInBegin(LLNode* head,char* n)
  {
      LLNode* nn=createNode(n);
      if(head==NULL)
        return nn;
      nn->next=head;
      return nn;
  }
  void traverse(LLNode* head)
  {
      while(head!=NULL)
      {
          printf("%s ",head->name);
          head=head->next;
      }
  }
  LLNode* rSearch(LLNode* head,char* s)
  {
      if(head==NULL)
        return NULL;
        if (strcmp(head->name,s)==0)
            return head;
       return rSearch(head->next,s);
  }
  LLNode* search(LLNode* head,char* s)
  {

      while(head)
      {

          if(strcmp(head->name,s)==0)
            return head;
          head=head->next;
      }
      return NULL;
  }
  LLNode* delete(LLNode* head,char* s)
  {
      if(head==NULL)
        return NULL;
        if(strcmp(head->data,s)==0)
        {
            LLNode *t=head->next;
            free(head);
            return t;
        }
        LLNode *oh=head;
        LLNode *p;
        while(head!=NULL)
        {
            if(strcmp(head->data,data)==0)
            {
                p->next=head->next;
                free(head);
                return oh;
            }
            p=head;
            head=head->next;
        }
        return oh;
  }
int main()
{
    LLNode* head=NULL;
    int n,key;
    scanf("%d\n",&n);
    int i;char word[100];
    for(i=0;i<n;i++)
    {

        scanf("%s",word);
        head=insertInBegin(head,word);
    }

    traverse(head);
    return 0;
}
