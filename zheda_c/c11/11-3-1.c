#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud_node {
    int num;
    char name;
    int score;
    struct stud_node *next;
};

int main(void) {


    return 0;
}

// 创建操作
struct stud_node *Create_stu_Doc() {
    struct stud_node *head, *p;
    int num, score;
    char name[20];
    int size = sizeof(struct stud_node);

    head = NULL;
    printf("Input num, name and score:\n");
    scanf("%d%s%d", &num, name, &score);

    while (num != 0) {
        p = (struct stud_node *) malloc(size);
        p->num = num;
        strcpy(p->name, name);
        p->socre = score;
        head = InsertDoc(head, p);
        scanf("%d%s%d", &num, name, &score);
    }
    return head;
}

// 插入操作
struct stud_node *InsertDoc(struct stud_node *head, struct stud_node *stud) {
    struct stud_node *ptr, *ptr1, *ptr2;

    ptr2 = head;
    ptr = stud;
    //原链表为空时的插入
    if (head == NULL) {
        head = ptr;
        head->next = NULL;
    } else {
        while ((ptr->num > ptr2->num) && (ptr2->next != NULL)) {
            ptr1 = ptr2;
            ptr2 = ptr2->next;

        }
        if (ptr->num <= ptr2->num) {
            if (head == ptr2) {
                head = ptr;
            } else {
                ptr1->next = ptr;
            }
            ptr->next = ptr2;
        } else {
            ptr2->next = ptr;
            ptr->next = NULL;
        }
    }
    return head;

}

// 删除操作
struct stud_node *DeleteDoc(struct stud_node *head, int num) {
    struct stud_node *ptr1, *ptr2;

    while (head != NULL && head->num == num) {
        ptr2 = head;
        head = head->next;
        free(ptr2);
    }
    if (head == NULL) {//链表空
        return NULL;
    }
    //要被删除结点为非表头结点
    ptr1 = head;
    ptr2 = head->next;
    while (ptr2 != NULL) {
        if (ptr2->num == num) {
            ptr1->nex = ptr2->next;
            free(ptr2);
        } else {
            ptr1 = ptr2;
        }
        ptr2 = ptr1->next;
    }

    return head;
}

// 遍历操作
void Print_Stu_Doc(struct stud_node *head) {
    struct sud_node *ptr;
    if (head == NULL) {
        printf("\nNo Records\n");
        return;
    }
    printf("\n The Students' Records Are :\n");
    printf("Num \t name score \n");
    for (ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%d%s%d", ptr->num, ptr->name, ptr->score);
    }
}