#include <iostream>
using namespace std;

typedef struct ListNode_C {
    int _val;
    struct ListNode_C* _next;
    struct ListNode_C* _prev;
} ListNode_C;

ListNode_C* BuyNode(int val) {
    ListNode_C* node_c = (ListNode_C*)malloc(sizeof(ListNode_C));
    node_c->_val = val;
    node_c->_next = NULL;
    node_c->_prev = NULL;
    return node_c;
}

struct ListNode_CPP {
    int _val;
    ListNode_CPP* _next;
    ListNode_CPP* _prev;

    ListNode_CPP(int val = 0)
        : _val(val)
        , _next(nullptr)
        , _prev(nullptr)
    {}
};

int main() {
    ListNode_C* node1 = BuyNode(1);
    ListNode_C* node2 = BuyNode(2);

    ListNode_CPP* node3 = new ListNode_CPP;
    ListNode_CPP* node4 = new ListNode_CPP(4);
    ListNode_CPP* node5 = new ListNode_CPP[10];
    delete node3;
    delete node4;
    delete[] node5;

    return 0;
}