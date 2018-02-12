#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long memory[100];

unsigned long long getNthFib(int n){

    if(n==1)
        return 0;
    if(n==2)
    {
        memory[n]=1;
        return 1;
    }
     if(memory[n-2]==0)
            memory[n-2]=getNthFib(n-2);
     if(memory[n-1]==0)
            memory[n-1]=getNthFib(n-1);
    return memory[n-2]+memory[n-1];
}

int main()
{
    printf("%llu", getNthFib(85));
    return 0;
}
