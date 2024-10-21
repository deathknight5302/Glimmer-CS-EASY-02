#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* next;
};
struct node* top=NULL;
void push(char data){//栈口在头结点处，这样就不用每次遍历到最后一个节点了
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
}
void pop(){
    if(top==NULL){
        printf("NULL\n");
        return;
    }
    struct node* temp=top;
    top=temp->next;
    printf("%c",temp->data);
    free(temp);
}
int main(){
    int a[34]={3,1,1,2,2,1,2,1,1,2,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,1,1,1,1,1,2},k=0;
    char b[26]={"kiglnmrmeiahenrteof4ardar"};
    for(int i=0;i<34;i++){
        if(i%2==0){//a[i]中的i为偶数的时候，数字的位置为奇数
            for(int j=1;j<=a[i];j++){
                push(b[k]);
                k++;
            }
        }else{
            for(int j=1;j<=a[i];j++){
                pop();
            }
        }
    }
    return 0;
}