#ifndef __STUBYLINKLIST_H
#define __STUBYLINKLIST_H

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status; // Status函数的类型，其值是函数结果状态代码，如OK等
typedef int ElemType; // ElemType类型根据实际情况而定，这里假设为int

typedef struct Student {
    char name[20];
    int num;
    char sex[10]; // male or female
    int age;
    struct Student *next;
} Student;
/* 定义LinkList */
typedef Student *LinkList;

Status init_list(LinkList *L);
int list_length(LinkList L);
void create_list_head(LinkList *L, int n);
void create_list_tail(LinkList *L, int n);
Status display(LinkList L);
Status del_stu_info(LinkList L, int a);
Status list_del(LinkList L, int i);
Status list_insert(LinkList L, int i);
LinkList list_reverse(LinkList L);
LinkList list_reverse2(LinkList L);
LinkList list_reverse3(LinkList L);
LinkList list_reverse4(LinkList p, LinkList s);
Status destroy_list(LinkList *L);
Status clear_list(LinkList L);
Status get_Nth_node_fromback(LinkList L, int n);
LinkList remove_dup_node(LinkList L);
int has_loop(LinkList L);
Status build_list_loop(LinkList *L, int pos);
LinkList find_loop_start(LinkList L);

#endif
