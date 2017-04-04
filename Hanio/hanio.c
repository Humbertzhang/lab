#include <stdio.h>

void shift(char a,char b){
    printf("%c ---> %c\n",a,b);
}

void recursive(int num,char start,char temp,char target){
    if(num==1){
        shift(start,target);
    }
    else{
        recursive(num - 1,start,target,temp);
        shift(start,target);
        recursive(num - 1,temp,start,target);
    }
}
int main(){
    int n;
    printf("Please input the number of the Hanio Tower\n");
    scanf("%d",&n);
    printf("The steps is that:\n");
    recursive(n,'A','B','C');
}



