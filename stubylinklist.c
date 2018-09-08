#include "stubylinklist.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 初始化链表 */
Status
init_list(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Student)); //产生头节点，并使L指向此头节点
    if (!(*L)) //存储分配失败
    {
        return ERROR;
    }
    (*L)->next = NULL;

    return OK;
}

/* 初始条件：链表L已存在 */
/* 操作结果：返回L中数据元素个数 */
int
list_length(LinkList L)
{
    int i = 0;

    if (L) {
        LinkList p = L->next; // p指向第一个节点
        while (p) {
            i++;
            p = p->next;
        }
    }
    return i;
}

/* 建立带头节点的单链表L，链表保存学生信息（头插法） */
void
create_list_head(LinkList *L, int n)
{
    LinkList p;
    int i;

    *L = (LinkList)malloc(sizeof(Student));
    (*L)->next = NULL;
    for (i = 0; i < n; i++) {
        int ch;
        p = (LinkList)malloc(sizeof(Student));
        printf("请输入%d个学生姓名: ", i + 1);
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(p->name, 20, stdin);
        p->name[strlen(p->name) - 1] = '\0';
        printf("请输入学号: ");
        if (scanf("%d", &p->num) != 1) {
            printf("输入错误，请重新输入\n");
            free(p);
            i--;
            continue;
        }
        printf("请输入性别: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(p->sex, 10, stdin);
        p->sex[strlen(p->sex) - 1] = '\0';
        printf("请输入年龄: ");
        if (scanf("%d", &p->age) != 1) {
            printf("输入错误，请重新输入\n");
            free(p);
            i--;
            continue;
        }

        p->next = (*L)->next;
        (*L)->next = p;

        printf("\n");
    }
}

/* 建立带头节点的单链表L，链表保存学生信息（尾插法） */
void
create_list_tail(LinkList *L, int n)
{
    LinkList p, r;
    int i;

    *L = (LinkList)malloc(sizeof(Student));
    r = *L;
    for (i = 0; i < n; i++) {
        int ch;
        p = (LinkList)malloc(sizeof(Student));
        printf("请输入%d个学生姓名: ", i + 1);
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(p->name, 20, stdin);
        p->name[strlen(p->name) - 1] = '\0';
        printf("请输入学号: ");
        if (scanf("%d", &p->num) != 1) {
            printf("输入错误，请重新输入\n");
            free(p);
            i--;
            continue;
        }
        printf("请输入性别: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(p->sex, 10, stdin);
        p->sex[strlen(p->sex) - 1] = '\0';
        printf("请输入年龄: ");
        if (scanf("%d", &p->age) != 1) {
            printf("输入错误，请重新输入\n");
            free(p);
            i--;
            continue;
        }

        r->next = p;
        r = p;

        printf("\n");
    }
    r->next = NULL;
}

/* 初始条件：链表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status
display(LinkList L)
{
    LinkList p;

    if (L == NULL) {
        printf("链表不存在\n");
    } else {
        p = L->next;

        if (p == NULL) {
            printf("链表为空\n");
        }

        else {
            printf("名字\t学号\t性别\t年龄\n");
            printf(
                "----------------------------------------------------------\n");

            while (p) {
                printf("%s\t%d\t%s\t%d\n", p->name, p->num, p->sex, p->age);
                p = p->next;
            }
            printf(
                "----------------------------------------------------------\n");
        }
    }
    return OK;
}

/* 初始条件：链表L已存在 */
/* 操作结果：删除L中age为a的元素 */
Status
del_stu_info(LinkList L, int a)
{
    LinkList p, q;
    LinkList qNext;

    if (L == NULL) {
        return ERROR;
    }
    p = L;
    q = L->next;

    while (q && (a != q->age)) {
        p = q;
        q = q->next;
    }

    if (q == NULL) {
        printf("链表中不存在此年龄\n");
        return ERROR;
    } else {
#if 0
        /** method 1 **/
        /* 常规方法，设一前一后两个指针遍历 */
        p->next = q->next;
        free(q);
        /** method 1 **/

#else

        /** method 2 **/
        /* 把后一个元素赋值给待删除节点，再把待删除节点指向下下个元素，
           这样相当于删除了当前元素 */
        if (q->next != NULL) //如果不是最后节点
        {
            qNext = q->next;
            q->next = qNext->next;
#if 0
            //单个赋值
            strcpy(q->name, qNext->name);
            q->num = qNext->num;
            strcpy(q->sex, qNext->sex);
            q->age = qNext->age;
#else
            //整体赋值
            memcpy(q, qNext, sizeof(Student) - 4);
#endif
            free(qNext);
        } else {
            p->next = NULL; //如果是最后一个节点，让它的前趋节点指向NULL
            free(q); //再删掉最后一个节点
        }
        /** method 2 **/
#endif

        // printf("delete the age success!!!\n");
    }

    return OK;
}

/* 初始条件：链表L已存在 */
/* 操作结果：删除L的第i个元素 */
Status
list_del(LinkList L, int i)
{
    int j = 1;
    LinkList p, q;

    if (L == NULL)
        return ERROR;
    p = L;

    while (p->next &&
           (j < i)) //删除一个节点，判断p->next，因为p跑在删除节点前。
    {
        p = p->next;
        ++j;
    }

    if ((p->next == NULL) || (j > i)) {
        printf("链表中不存在此元素\n");
        return ERROR;
    } else {
        q = p->next;
        p->next = q->next;
        free(q);
        printf("删除节点成功\n");
    }

    return OK;
}

/* 初始条件：链表L已存在 */
/* 操作结果：在L中第i个位置之前插入新的元素，L的长度加1 */
Status
list_insert(LinkList L, int i)
{
    int j = 1;
    LinkList p;
    int ch;

    p = L;

    while (p && (j < i)) {
        p = p->next;
        ++j;
    }

    if ((p == NULL) || (j > i)) {
        printf("您输入的节点不存在，插入失败\n");
        return ERROR;
    } else {
        LinkList q;
    loop:
        q = (LinkList)malloc(sizeof(Student));
        printf("请输入学生姓名: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(q->name, 20, stdin);
        q->name[strlen(q->name) - 1] = '\0';
        printf("请输入学号: ");
        if (scanf("%d", &q->num) != 1) {
            printf("输入错误，请重新输入\n");
            free(q);
            goto loop;
        }
        printf("请输入性别: ");
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        fgets(q->sex, 10, stdin);
        q->sex[strlen(q->sex) - 1] = '\0';
        printf("请输入年龄: ");
        if (scanf("%d", &q->age) != 1) {
            printf("输入错误，请重新输入\n");
            free(q);
            goto loop;
        }

        q->next = p->next;
        p->next = q;
        printf("插入成功\n");
    }

    return OK;
}

/* 单链表反转/逆序 */
/* 三指针法，可以理解为断开法
   此方法第一回指针指向改变两次，之后只需要每回改变一次，
   如果有n个节点，那就需要改变n次 */
LinkList
list_reverse(LinkList L)
{
    LinkList cur, pnext, prev;

    // printf("reverse the seqlist by %s\n", __func__);
    if ((L == NULL) || (L->next == NULL)) {
        return L;
    }

    pnext = L->next;
    L->next = NULL;
    cur = NULL;

    while (pnext) {
        prev = pnext->next;
        pnext->next = cur;
        cur = pnext;
        pnext = prev;
    }

    L->next = cur;

    return L;
}

/* 单链表反转/逆序 */
/* 跨节点法，把旧首节点指向下下元素，把中间元素设为新首节点，最终
   旧首节点指向链尾 */
LinkList
list_reverse2(LinkList L)
{
    // printf("reverse the seqlist by %s\n", __func__);

    if ((L == NULL) || (L->next == NULL)) {
        return L;
    }
    /*
    //不带头节点
    LinkList cur = L->next;
    LinkList end = L;

    while (cur != NULL)
    {
    end->next = cur->next;
    cur->next = L;
    L = cur;
    cur = end->next;
    }
    */
    LinkList cur, prev;

    cur = L->next;

    while (cur->next) {
        prev = cur->next;
        cur->next = cur->next->next;
        prev->next = L->next;
        L->next = prev;
    }

    return L;
}

/* 单链表反转/逆序 */
/* 新节点法，注意调用此反转函数要用返回值赋值 */
LinkList
list_reverse3(LinkList L)
{
    LinkList new_list;
    LinkList tmp;

    // printf("reverse the seqlist by %s\n", __func__);

    new_list = (LinkList)malloc(sizeof(Student));
    new_list->next = NULL;

    while (L->next != NULL) {
        tmp = new_list->next;
        new_list->next = L->next;
        L->next = L->next->next;
        new_list->next->next = tmp;
    }

    free(L);
    return new_list;
}

/* 单链表反转/逆序 */
/* 递归法，带头节点，传入参数为首节点 */
LinkList
list_reverse4(LinkList p, LinkList s)
{
    LinkList new_head;

    // printf("reverse the seqlist by %s\n", __func__);
    if (p == NULL) {
        return p;
    }
    if (p->next == NULL) {
        // printf("next null %s\n", s->name);
        s->next = p;
        return s;
    }

    // printf("%s\n", s->name);
    new_head = list_reverse4(p->next, s);
    p->next->next = p;
    p->next = NULL;

    return new_head;
}
/* 初始条件：链表L已存在 */
/* 操作结果：销毁L */
Status destroy_list(
    LinkList *L) //销毁整个链表包含头节点，所以这里要传头节点本身的地址
{
    LinkList p;

    //注意这里＊L不能赋值给其它变量，因为这里头节点也要清空，所以只能由它自身来清空。
    if ((*L) == NULL) {
        printf("链表不存在\n");
        return ERROR;
    }

    while (*L) {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }

    printf("销毁链表成功\n");

    return OK;
}

/* 初始条件：链表L已存在 */
/* 操作结果：清空L */
Status clear_list(
    LinkList L) //清空除头节点外的其它节点，传头节点即可，因为不用清头节点，
                //所以不用传头节点本身的地址
{
    LinkList p, q;

    if (L == NULL) //判断头节点不为空
    {
        printf("链表不存在\n");
        return ERROR;
    }

    q = L->next;

    while (q) {
        p = q->next;
        free(q);
        q = p;
    }

    L->next = NULL;

    printf("清空链表成功\n");

    return OK;
}

/* 寻找单链表L中倒数第N个节点 */
Status
get_Nth_node_fromback(LinkList L, int n)
{
    int i = 0;
    LinkList first_node = L;

    while (i < n && first_node->next != NULL) {
        //正数N个节点，firstNode指向正的第N个节点
        i++;
        first_node = first_node->next;
        // printf("%d\n", i);
    }
    if ((first_node->next == NULL && i < n) || i == 0) {
        //当节点数量少于N个时，返回NULL
        printf("超出链表长度\n");
        return ERROR;
    }

    LinkList sec_node = L;
    while (first_node != NULL) {
        //查找倒数第N个节点
        sec_node = sec_node->next;
        first_node = first_node->next;
    }
    printf("倒数第%d个学生信息：\n", n);
    printf("%s	%d	%s	%d\n",
           sec_node->name,
           sec_node->num,
           sec_node->sex,
           sec_node->age);

    return OK;
}

// void GetMidNode(LinkList L)
//{
//	;
//}

/* 删除单链表L中重复元素 */
LinkList
remove_dup_node(LinkList L)
{
    LinkList p, q, r;

    if ((L == NULL) || (L->next == NULL)) {
        return L;
    }

    p = L->next;
    while (p) {
        q = p;
        while (q->next) {
            if (q->next->age == p->age) {
                r = q->next;
                q->next = r->next;
                free(r);
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }

    return L;
}

/* 判断单链表L是否存在环 */
int
has_loop(LinkList L)
{
    LinkList slow, fast;

    if ((L == NULL) || (L->next == NULL)) {
        return FALSE;
    }

    slow = L;
    fast = L;
    while ((fast != NULL) && (fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return TRUE;
        }
    }

    return FALSE;
}

/* 初始条件：无环单链表L */
/* 操作结果：给L创建环 */
Status
build_list_loop(LinkList *L, int pos)
{
    int i;
    LinkList cur;
    LinkList tail = NULL;

    if ((pos <= 0) || (L == NULL)) {
        return ERROR;
    }

    cur = (*L);

    for (i = 0; i < pos; i++) {
        if (cur == NULL) {
            return ERROR;
        }
        cur = cur->next;
    }
    tail = cur;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = cur;

    return OK;
}

/* 初始条件：单链表L存在环 */
/* 操作结果：找出环的入口点 */
LinkList
find_loop_start(LinkList L)
{
    LinkList fast, slow;
    slow = fast = L;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow == NULL || fast == NULL)
        return NULL;

    LinkList ptr1 = L;
    LinkList ptr2 = slow;
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    printf("环的入口点：\n");
    printf("%s %d %s %d\n", ptr1->name, ptr1->num, ptr1->sex, ptr1->age);
    return ptr1;
}
