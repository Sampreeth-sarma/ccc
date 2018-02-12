#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define ALPHA_SIZE  26

typedef struct node
{
    bool isEndOfWord;
    struct node* next[ALPHA_SIZE];
} Node;

Node* createNode()
{
    Node* nn=(Node*)malloc(sizeof(Node));
    nn->isEndOfWord=false;
    for(int i=0; i<ALPHA_SIZE; i++)
        nn->next[i]=NULL;
    return nn;
}

bool insertWord(Node* root,char word[])
{
    Node* temp=root;
    for(int i=0; word[i]!='\0'; i++)
    {
        int idx=word[i]-'a';
        if(temp->next[idx]==NULL)
            temp->next[idx]=createNode();
        temp=temp->next[idx];
    }
    if(true==temp->isEndOfWord)
        return false;
    temp->isEndOfWord=true;
    return true;
}

void printAllWords(Node* root, char *prefix){
    if(root->isEndOfWord)
        printf("%s\n",prefix);
    for(int i=0;i<ALPHA_SIZE;i++)
    {
        if(root->next[i]!=NULL)
        {
            int len=strlen(prefix);
            char ch=i+'a';
            char *new_prefix=(char*)malloc(len+2);
            strcpy(new_prefix,prefix);
            new_prefix[len++]=ch;
            new_prefix[len]='\0';
            printAllWords(root->next[i],new_prefix);
            free(new_prefix);

        }
    }


}



int showMenu()
{
    int ch;
    printf("1.insert word\n 2.print all words\n 3.auto suggest\n 4.exit\n");
    scanf("%d",&ch);
    return ch;
}

void autoSuggest(Node* root,char *prefix)
{
    Node* temp=root;
    for(int i=0;prefix[i]!='\0';i++)
    {
        int idx=prefix[i]-'a';
        if(temp->next[idx]==NULL){
            printf("no word found\n");
            return;
        }
        temp=temp->next[idx];
    }
    printAllWords(temp,prefix);
}
int main()
{
    char word[100];
    Node* root=createNode();
    FILE *fp = fopen("dictionary.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%s", word);
        insertWord(root, word);
    }
    fclose(fp);
    while(1)
    {
        switch(showMenu())
        {
        case 1:
            printf("\nenter the word:");
            scanf("%s",word);
            if(insertWord(root,word))
                printf("inserted\n");
            else
                printf("already existed\n");
            break;
        case 2:
            printAllWords(root,"");
            break;
        case 3:
            printf("enter the prefix:\n");
            scanf("%s",word);
            autoSuggest(root,word);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
