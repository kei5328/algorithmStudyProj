struct StackNode{
    char data;
    struct StackNode * next;
};

struct StackNode * newNode(char data){
    struct StackNode * sn = (struct StackNode*)malloc(sizeof(struct StackNode));
    sn->data = data;
    sn->next = NULL;
    return sn;
}

int isEmpty(struct StackNode * root){
    // implementaiton of isEmpty
    return !root; // !root is true if root is null
}

void push(struct StackNode ** root, char data){
    // generate a new node
    struct StackNode * newN = newNode(data);
    newN->next = *root;
    *root = newN;
}

char pop(struct StackNode ** root){
    // implementation of pop
    if (isEmpty(root)) return '\0';
    struct StackNode * tmp = *root; // hold the curernt root with the temporary value.
    *root = tmp->next; // set the root to the next of current root.
    char res = tmp->data; // this is a return value;
    free(tmp); // you need to free this memory to avoid memory leak.
    return res;
}

char peek(struct StackNode * root){
    // implementation of peek
    if (isEmpty(root)) return '\0';
    return root->data;
}


// map a beginning braket with an ending bracket
char mapping(char input){
    if (input==')'){
        return '(';
    }else if(input=='}'){
        return '{';
    }else if(input==']'){
        return '[';
    }else{
        return '\0';
    }
}

// implementaiton of the main algorithm
bool isValid(char * s){
    if (strlen(s)==0) return 1;
    if (strlen(s)%2==1) return 0;
        struct StackNode * root = NULL; // initialize a stack

    for (int i = 0; i<strlen(s); i++){
        if (s[i]=='(' || s[i]=='{' || s[i]=='['){
            // push it
            push(&root, s[i]); // root is already a pointer
           char test =peek(&root);
        }else if (s[i]==')' || s[i]=='}' || s[i]==']'){
            // pop it
            if (isEmpty(root)) return 0; // there is nothing to pop so we cannot have a valid input.
            char res = pop(&root);

            //printf("%c", res);
            char mp = mapping(s[i]);
            if (res!=mp) return 0;
        }else{
            // unexpected input
            return 0;
        }
    }
    if (!isEmpty(root)){
    while(!isEmpty(root)){
        char c = pop(&root);
    }
        return 0;
    }else{
        return 1;
    }
}
