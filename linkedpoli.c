#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial {
    int coeff, exponent1, exponent2, exponent3;
    struct polynomial* link;
    int flag;
};
typedef struct polynomial node;

node* getnode() {
    node* temp = (node*)malloc(sizeof(node));
    temp->link = NULL;
    temp->flag = 0;
    return temp;
}

node* insertend(node* head, int c, int x, int y, int z) {
    node* cur = getnode();
    cur->coeff = c;
    cur->exponent1 = x;
    cur->exponent2 = y;
    cur->exponent3 = z;
    node* temp = head->link;
    while (temp->link != head)
        temp = temp->link;
    temp->link = cur;
    cur->link = head;
    return head;
}

node* readpoly(node* head) {
    int i, n, c, x, y, z;
    printf("enter the no of terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("enter the coeffecient, exponent1, exponent2, exponent3\n");
        scanf("%d%d%d%d", &c, &x, &y, &z);
        head = insertend(head, c, x, y, z);
    }
    return head;
}

void printpoly(node* head) {
    node* cur = head->link;
    while (cur->link != head) {
        printf("%dx^%dy^%dz^%d + ", cur->coeff, cur->exponent1, cur->exponent2, cur->exponent3);
        cur = cur->link;
    }
    printf("%dx^%dy^%dz^%d\n", cur->coeff, cur->exponent1, cur->exponent2, cur->exponent3);
}

void evaluate(node* head) {
    node* cur = head->link;
    int sum = 0, x, y, z;
    printf("enter the value of x y and z");
    scanf("%d%d%d", &x, &y, &z);
    while (cur != head) {
        sum = sum + cur->coeff * pow(x, cur->exponent1) * pow(y, cur->exponent2) * pow(z, cur->exponent3);
        cur = cur->link;
    }
    printf("the evaluated result of a polynomial is %d\n", sum);
}

node* addpoly(node* head1, node* head2, node* head3) {
    node* cur1, *cur2;
    int c;
    cur1 = head1->link;
    while (cur1 != head1) {
        cur2 = head2->link;
        while (cur2 != head2) {
            if (cur1->exponent1 == cur2->exponent1 && cur1->exponent2 == cur2->exponent2 && cur1->exponent3 == cur2->exponent3) {
                c = cur1->coeff + cur2->coeff;
                head3 = insertend(head3, c, cur1->exponent1, cur1->exponent2, cur1->exponent3);
                cur1->flag = 1;
                cur2->flag = 1;
            }
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    cur1 = head1->link;
    cur2 = head2->link;
    while (cur1 != head1) {
        if (cur1->flag == 0) {
            head3 = insertend(head3, cur1->coeff, cur1->exponent1, cur1->exponent2, cur1->exponent3);
        }
        cur1 = cur1->link;
    }
    while (cur2 != head2) {
        if (cur2->flag == 0) {
            head3 = insertend(head3, cur2->coeff, cur2->exponent1, cur2->exponent2, cur2->exponent3);
        }
        cur2 = cur2->link;
    }
    return head3;
}

int main() {
    node* head1 = (node*)malloc(sizeof(node));
    head1->link = head1;
    node* head2 = (node*)malloc(sizeof(node));
    head2->link = head2;
    node* head3 = (node*)malloc(sizeof(node));
    head3->link = head3;
    printf("read 1st polynomial\n");
    head1 = readpoly(head1);
    printf("read 2nd polynomial\n");
    head2 = readpoly(head2);
    printf("1st polynomial is\n");
    printpoly(head1);
    printf("2nd polynomial is\n");
    printpoly(head2);
    head3 = addpoly(head1, head2, head3);
    printf("resultant polynomial is\n");
    printpoly(head3);
    evaluate(head1);

    return 0;
}
