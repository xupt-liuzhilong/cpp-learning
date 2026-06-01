#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
};

int main() {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

    if (node == NULL) {
        perror("malloc fail");
        return -1;
    }

    node->val = 1;
    node->next = NULL;

    printf("val = %d\n", node->val);

    free(node);
    node = NULL;

    return 0;
}