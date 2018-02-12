#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int c=0;
char matrix[2][2]={'w','o','r','d'};
char word[5];
bool v[2][2];
void printWordsFrom(int i, int j, int idx, int len){

    // BASE
    int a,b;
    if(i<0 ||j<0||i>=2||j>=2)
        return;
    if(v[i][j]==true)
        return;

    word[idx++] = matrix[i][j];
    word[idx] = 0;
    v[i][j]=true;
    if(strlen(word)>=len)
    {
        printf("%s\n",word);
        c++;
    }
    for(a=i-1;a<=i+1;a++)
        for(b=j-1;b<=j+1;b++)
            printWordsFrom(a,b,idx,len);
    v[i][j] = false;



}

void printAllWords(){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            printWordsFrom(i,j,0,2);
}

int main()
{

    printAllWords();
    printf("the count is %d\n",c);
    return 0;
}
