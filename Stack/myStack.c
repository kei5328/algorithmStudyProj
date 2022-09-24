// solution using two queue
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode * next;
};

typedef struct{
    struct ListNode * head;
    struct ListNode * tail;
    uint32_t size;
}Queue;

Queue * myQueueCreate()
{
    Queue * q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) return NULL; // handle nullptr
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void myQueuePush(Queue* q, int x)
{
    if (q==NULL) return;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node==NULL) return; // handle nullptr
    node->val = x;
    if (q->size==0)
    {// size is 0. empty queue.
        q->head = node;
        q->tail = node;
        node->next = NULL;
    }
    else
    {// there is at least one item in this queue.
        node->next = NULL;
        struct ListNode * tail_node = q->tail;
        tail_node->next = node;
        q->tail = node;
        // set tail to the
    }
    q->size++;
}

bool myDequeue(Queue* q, int *val)
{
    if (q==NULL) return false;
    struct ListNode * head_node = q->head;
    if (head_node == NULL) return false;
    *val=head_node->val;
    q->head = head_node->next;
    free(head_node);
    q->size--;
    return true;
}
bool myQueuePeek(Queue* q, int * result)
{
    struct ListNode * temp = q->head;
    if (temp!=NULL)
    {
        *result = temp->val;
        return true;
    }
    else
        return false;
}
int  myQueueSize(Queue * q)
{
    return q->size;
}

typedef struct{
    Queue * q1;
    Queue * q2;
}MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack!=NULL)
    {
        stack->q1 = myQueueCreate();
        stack->q2 = myQueueCreate;
    }
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj==NULL) return;
    myQueuePush(obj->q1, x);
}



int myStackPop(MyStack* obj) {
    int result;
    int curr_val;
    bool success;
    if (obj==NULL) return 0;
    // first pop until the end
    if (obj->q1==NULL) return;
    if (obj->q2==NULL) return;
    while ((obj->q1)->size>1)
    {
        success = myDequeue(obj->q1, &curr_val);
        myQueuePush(obj->q2, curr_val);
    }
    // here, the q1 has size 1.
    success = myDequeue(obj->q1, &curr_val);

    // need to swap q1 and q2
    Queue * temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp ;

    result = curr_val;
    return result;
}

int myStackTop(MyStack* obj) {
    int result;
    int curr_val;
    bool success;
    if (obj==NULL) return 0;
    // first pop until the end
    if (obj->q1==NULL) return;
    if (obj->q2==NULL) return;
    // for this operation, we need to push everything.
    while ( (obj->q1)->size>0)
    {
        success = myDequeue(obj->q1, &curr_val);
        myQueuePush(obj->q2, curr_val);
    }

    // need to swap q1 and q2
    Queue * temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp ;

    result = curr_val;
    return result;
}

bool myStackEmpty(MyStack* obj) {
    return myQueueSize(obj->q1)==0;
}

void myStackFree(MyStack* obj) {
    int curr_val;
    bool success;
    while ((obj->q1)->size>0)
    {
        success = myDequeue(obj->q1, &curr_val);
    }
    while ((obj->q2)->size>0)
    {
        success = myDequeue(obj->q2, &curr_val);
    }
    free(obj->q1);
    free(obj->q2);
    free(obj);
    return;
}

// General Stack Solution
/*

typedef struct{
    int val;
    bool is_head;
    struct MyStack * next;
}MyStack;


MyStack* myStackCreate() {
    MyStack * stack_node = (MyStack*) malloc(sizeof(MyStack));
    memset(stack_node, 0, sizeof(MyStack));
    stack_node->is_head = true;
    stack_node->next = NULL;
    stack_node->val = 0;
    return stack_node;
}

void myStackPush(MyStack* obj, int x) {
    MyStack* stack_node = (MyStack*) malloc(sizeof(MyStack));
    stack_node->val = x;
    stack_node->next = obj->next;
    stack_node->is_head = false;
    obj->next = stack_node;
    printf("%d", obj->val);
}

int myStackPop(MyStack* obj) {
    if (obj==NULL || obj->next==NULL)
    {
        return 0;
    }

    MyStack * temp = (obj->next);
    int val = temp->val;
    obj->next = temp->next;
    //free(temp);
    return val;
}

int myStackTop(MyStack* obj) {
    if (obj==NULL || obj->next==NULL)
    {
        return 0;
    }
    MyStack* temp = obj->next;
    return temp->val;
}

bool myStackEmpty(MyStack* obj) {
    if (obj==NULL || obj->next==NULL)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {

    MyStack * temp1 = obj;
    MyStack * temp2 = obj;
    while(temp1!=NULL)
    {

        MyStack * temp2 = temp1;

        temp1 = temp1->next;

        //printf("%d", temp1->val);
        free(temp2);
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

