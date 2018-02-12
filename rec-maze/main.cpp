#include <cstdio>

using namespace std;

bool isPathThereHelper(int a[][10],int r,int c,int si,int sj,int ei,int ej){
    if(si>=r || sj>=c || ei>=r || ej>=c)
        return false;
    if(a[si][sj] == 1 || a[ei][ej] == 1)
        return false;
    if(si==ei && ej==sj)
        return true;
    bool right = isPathThereHelper(a,r,c,si,sj+1,ei,ej);
    if(right)
        return true;
    return isPathThereHelper(a,r,c,si+1,sj,ei,ej);
}
bool isPathThere(int a[][10], int r, int c){
    return isPathThereHelper(a,r,c,0,0,r-1,c-1);
}

int main()
{
    int r,c,i,j;
    int a[10][10];
    scanf("%d %d", &r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &a[i][j]);

    printf("%d", isPathThere(a,r,c));

    return 0;
}
