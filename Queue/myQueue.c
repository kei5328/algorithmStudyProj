
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
struct QueueNode {
    int val;
    struct QueueNode* next;
};

typedef struct {
    struct QueueNode * head;
    int size;
}Stack;

Stack * myStackCreate( )
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack!=NULL)
    {
        stack->head = NULL;
        stack->size = 0;
    }
    return stack;
}

void * myStackPush(Stack * s, int val)
{
    if (s==NULL) return;

    struct QueueNode * node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (node!=NULL)
    {//
        node->val = val;
        node->next = s->head;
        s->head = node;
        s->size++;
    }
    return;
}

bool * myStackPop(Stack * s, int * result)
{
    if (s==NULL) return false;
    *result = (s->head)->val;
    struct QueueNode * temp= s->head;
    s->head = temp->next;
    free(temp);
    s->size--;
    return true;
}

bool * myStackPeek(Stack * s, int * result)
{
    if (s==NULL) return false;
    *result = (s->head)->val;
    return true;
}

bool * myStackEmpty(Stack * s)
{
    return s->size==0;
}


typedef struct {
  Stack * s1;
  Stack * s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue * q = (MyQueue*)malloc(sizeof(MyQueue));
    if (q==NULL) return NULL;
    q->s1 = myStackCreate();
    q->s2 = myStackCreate();
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    // always push to s1
    myStackPush(obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    int result;
    if (!myStackEmpty(obj->s2))
    {// s2 is not empty;
        bool success = myStackPop(obj->s2, &result);
    }
    else if (!myStackEmpty(obj->s1))
    {// s1 is not empty
        int val;
        while((obj->s1)->size>1)
        {
            myStackPop(obj->s1, &val);
            myStackPush(obj->s2, val);
        }
        // here, the s1 size is 1(only one item remaining.)
        myStackPop(obj->s1, &val); // pop the last one but do not push to s2.
        result = val;
    }
    else
    {// it's empty but pop is being called... what should I do?
        return 0;
    }
    return result;
}

int myQueuePeek(MyQueue* obj) {
    int result;
    if (!myStackEmpty(obj->s2))
    {
        myStackPeek(obj->s2, &result);
    }
    else if (!myStackEmpty(obj->s1))
    {// we need to pop to get the data.
        int val;
        while((obj->s1)->size>0)
        {
            myStackPop(obj->s1, &val);
            myStackPush(obj->s2, val);
        }
        // here, the s1 size is 1(only one item remaining.)
        result = val;
    }
    return result;
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj==NULL) return true;
    int result = (obj->s1)->size + (obj->s2)->size;
    return result==0;
}

void myQueueFree(MyQueue* obj) {
    if (obj!=NULL)
    {
        while (!myStackEmpty(obj->s1))
        {
            int val;
            myStackPop(obj->s1, &val);
        }
        while (!myStackEmpty(obj->s2))
        {
            int val;
            myStackPop(obj->s2, &val);
        }
        free(obj);
    }
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
