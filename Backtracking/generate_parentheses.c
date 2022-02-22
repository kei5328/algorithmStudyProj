struct arr_node{
    char * res;
    struct arr_node * next;
}


 write_parenthesis()
 {
     if (idx>n*2)
        return;
     if (n<cnt)
     {
        write_parenthesis(idx, cnt-1, n, -1);
     }

     write_parenthesis(idx, cnt+1, n, 1);
 }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){

    for (int ii = 0; ii < n; ii++)
    {//

        if (is_valid)
        {

        }
    }
}
