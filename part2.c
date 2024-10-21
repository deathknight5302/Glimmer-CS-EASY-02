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
void delete(int n){//删除节点
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
    temp1->next=temp2->next;//重新建立链接
    free(temp2);
}
int main(){
    struct node* first=(struct node*)malloc(sizeof(struct node));//定义头节点
    head=first;
    first->data=1;
    first->next=NULL;
    char c;
    int a[3],n,j=0;
    scanf("%c",&c);//保留了输入
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
    struct node* temp1=head;
    struct node* temp2;//首先为起始节点，然后为执行节点
    struct node* temp3;//用于重新建立链接关系
    struct node* temp4;//起始/执行节点的上一节点
    struct node* temp5;//用于释放执行节点的空间
    while(temp1->next!=NULL){
        temp4=temp1;
        temp1=temp1->next;
        if(temp1->data==3){//获取起始节点，temp4为起始节点的上一节点
            temp2=temp1;
            break;
        }
    }
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=head;//将链表首尾相连
    while(temp2->next!=temp2){//
        for(int i=1;i<=j;i++){
            temp4=temp2;//temp4为执行节点的上一节点
            temp2=temp2->next;
        }
        temp3=temp2->next;
        printf("%d ",temp2->data);
        temp4->next=temp3;
        temp5=temp2;
        temp2=temp2->next;
        free(temp5);
        j++;
    }
    printf("%d",temp2->data);
    return 0;
}