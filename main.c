#include <stdio.h>
#include <stdlib.h>

#include "stubylinklist.h"

int
main()
{
    LinkList L;
    Status i;
    int n, a, pos, value;
    int opp = 100;
    int ch;

    i = init_list(&L);
    printf("链表L初始化完毕，ListLength(L)=%d\n", list_length(L));

    printf(
        "\n1.整表创建（头插法） \n2.整表创建（尾插法） \n3.遍历操作 "
        "\n4.插入操作");
    printf("\n5.删除操作 \n6.删除操作（年龄） \n7.清空链表 \n8.销毁链表");
    printf(
        "\n9.链表反转/逆序 \n10.打印链表倒数第N个元素 \n11.找到链表的中间节点 "
        "\n12.判断链表是否有环");
    printf("\n13.链表建环");
    printf("\n14.链表去重");
    printf("\n15.环的入口点");
    printf("\n0.退出 \n请选择你的操作：\n");

    while (opp != '0') {
        printf("等待命令...请输入您的选择（0-15）\n");
        if (scanf("%d", &opp) != 1) {
            while ((ch = getchar()) != EOF && ch != '\n') {
                ;
            }
            continue;
        }
        switch (opp) {
            case 1:
                printf("整体创建L（头插法）请输入元素个数：");
                if (scanf("%d", &n) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                create_list_head(&L, n);
                display(L);
                printf("\n");
                break;
            case 2:
                printf("整体创建L（尾插法）请输入元素个数：");
                if (scanf("%d", &n) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                create_list_tail(&L, n);
                display(L);
                printf("\n");
                break;
            case 3:
                display(L);
                printf("\n");
                break;
            case 4:
                printf("要在第几个位置插入元素？");
                if (scanf("%d", &pos) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                list_insert(L, pos);
                display(L);
                printf("\n");
                break;
            case 5:
                printf("要删除第几个元素？");
                if (scanf("%d", &pos) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                i = list_del(L, pos);
                if (i == OK)
                    printf("删除第%d个元素成功，现在链表为：\n", pos);
                display(L);
                printf("\n");
                break;

            case 6:
                printf("要删除哪个年龄的学生？");
                if (scanf("%d", &a) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                del_stu_info(L, a);
                display(L);
                printf("\n");
                break;

            case 7:
                i = clear_list(L);
                printf("\n清空L后：ListLength(L)=%d\n", list_length(L));
                display(L);
                printf("\n");
                break;

            case 8:
                i = destroy_list(&L);
                printf("\n销毁L后：ListLength(L)=%d\n", list_length(L));
                display(L);
                printf("reinit\n");
                init_list(&L);
                printf("\n");
                break;

            case 9:
                list_reverse4(L->next, L);
                // L=list_reverse3(L);
                printf("\n反转L后\n");
                display(L);
                printf("\n");
                break;

            case 10:
                printf("你要查找倒数第几个结点的值？");
                if (scanf("%d", &value) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                get_Nth_node_fromback(L, value);
                printf("\n");
                break;
                /*
                   case 11:
                   GetMidNode(L, &e);
                   printf("链表中间结点的值为：%d\n", e);
                   printf("\n");
                   break;
                   */
            case 11:
                remove_dup_node(L);
                display(L);
                printf("\n");
                break;
                /* 链表环相关的仅供一次性测试 */
            case 12:
                if (has_loop(L)) {
                    printf("链表有环\n");
                } else {
                    printf("链表无环\n");
                }
                printf("\n");
                break;
            case 13:
                printf("你要在哪个位置开始建环？");
                if (scanf("%d", &pos) != 1) {
                    printf("输入错误，返回主菜单\n");
                    while ((ch = getchar()) != EOF && ch != '\n') {
                        ;
                    }
                    continue;
                }
                build_list_loop(&L, pos);
                printf("\n");
                break;
            case 15:
                find_loop_start(L);
                printf("\n");
                break;
            case 0:
                exit(0);
        }
    }

    return 0;
}
