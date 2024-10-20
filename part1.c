//参考网课：b站up主：fengmuzi2003,如有雷同，纯属巧合
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insert1(int data){//头部插入
    struct node* temp=(struct node*)malloc(sizeof(struct node));//申请空间
    temp->data=data;
    temp->next=head;
    head=temp;
}
void insert2(int data){//尾部插入
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    struct node* temp2=head;
    while(temp2->next!=NULL){//遍历链表
        temp2=temp2->next;
    }
    temp1->data=data;
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void print(struct node* n){//打印链表
    struct node* temp=head;
    printf("List is:");
    while(temp!=n){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);
}
void delete(int n){
    struct node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);//释放空间
        return;//结束函数
    }
    for(int i=1;i<=n-2;i++){
        temp1=temp1->next;
    }
    struct node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
int main(){
    // head->data=1;
    struct node* first=(struct node*)malloc(sizeof(struct node));//定义头节点
    head=first;
    first->data=1;
    first->next=NULL;
    char c;
    int a[3],n;
    scanf("%c",&c);
    while(c!='C'){
        if(c=='H'){
            for(int i=0;i<3;i++){
                scanf("%d",&a[i]);
            }
            for(int i=2;i>=0;i--){
                insert1(a[i]);
            }
        }else if(c=='T'){
            for(int i=0;i<3;i++){
                scanf("%d",&a[i]);
            }
            for(int i=0;i<3;i++){
                insert2(a[i]);
            }
        }else if(c=='D'){
            scanf("%d",&n);
            delete(n);
        }
        scanf("%c",&c);
    }
    struct node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=head;//将链表首尾相连
    print(temp2);//以原来的首尾打印链表
    return 0;
}