
// practice problem for graph: https://leetcode.com/problems/max-area-of-island/


/*
The idea.

1. Loop thru all grids
2. If one of the grid is 1(island) and NOT visited, then start the BFS
3. While doing the BFS, keep track of the number of ones in the current search area.
4. When the BFS from current grid is complete, get the total number of area.
5. If the obtained area is above the current maximum, update.
6. Continue until the end of the grid.
*/


/*
BFS:
1. get all adjacent cells(we need to build a function to quickly identify the index of each cell)
2. put the obtained cells into each
*/




#include<stdio.h>
#include<stdint-gcc.h>
#include<stdbool.h>
#include<stdlib.h>


enum visit_state_e {SEA = 0, // not island
WHITE=1, // not explored at all
GRAY=2,  // some adjacent verticies explored.
BLACK=3, // all explored;
};

struct list
{
    uint8_t row;
    uint8_t col;
    struct list * next;
};

// This function sets the linked lists' field values row and col to the given values. Sets the next to NULL.
void init_list(struct list * p_list, uint8_t row_num, uint8_t col_num)
{
    p_list->row = row_num;
    p_list->col = col_num;
    p_list->next = NULL;
    return;
}

struct list * enqueue(struct list * head, struct list * input_list)
{
    struct list *curr_list = head;

    if (head==NULL)
    {
        head=input_list;
        //printf("Enqueue case 1: (%d, %d)\n", input_list->row, input_list->col);
        return head;
    }
    // head is not NULL, we have at least 1 item in the queue.
    while (curr_list->next != NULL)
    {
        curr_list = curr_list->next;
    }
    curr_list->next = input_list;
    //printf("Enqueue case 2: (%d, %d)\n", input_list->row, input_list->col);
    return head;
};


struct list * pop(struct list ** head)
{
    struct list *curr_list = *head;
    if (*head==NULL) return NULL;
    *head = curr_list->next;
    return curr_list;
};


/*
gets the adjacent cell information and returns with bit shift
grid: 2D char array
c_row: current row index
c_col: current column index
gridSize: size of rows
gridColSize: size of columns
output:
adj_num: number of adjacent cells
adj_vert: adjacent cells expressed with bit shift.

0th bit: top
1st bit: right
2nd bit: bottom
3rd bit: left
*/
uint8_t get_adj_idx(int** grid, struct list * grid_pt,  int* gridSize, int* gridColSize, uint8_t* adj_vert)
{
    uint8_t adj_num = 0;
    // top cell
    if (grid_pt->row>0 && *(*(grid+grid_pt->row-1)+grid_pt->col)!=SEA)
    {
        *adj_vert |= 0x01;
        adj_num++;
    }
    // right cell
    if (grid_pt->col+1<*gridColSize && *(*(grid+grid_pt->row)+grid_pt->col+1)!=SEA)
    {
        *adj_vert |= 0x02;
        adj_num++;
    }
    // bottom cell
    if (grid_pt->row+1<*gridSize && *(*(grid+grid_pt->row+1)+grid_pt->col)!=SEA){
       *adj_vert |= 0x04;
        adj_num++;
    }
    // left cell
    if (grid_pt->col>0 && *(*(grid+grid_pt->row)+grid_pt->col-1)!=SEA){
        *adj_vert |= 0x08;
        adj_num++;
    }
    return adj_num;
}
void fill_shift_nums(uint8_t adj_num, uint8_t adj_vert, int8_t * row_shift, int8_t * col_shift)
{
    uint8_t temp = 0;
    for (int ii = 0; ii<4; ii++)
    {
        if (adj_vert & 0x01)
        {// the lowest bit is 1.
            if (ii==0)
            { // top
                *(row_shift+temp) = -1;
                *(col_shift+temp) = 0;
            }
            else if (ii==1)
            { // rights
                *(row_shift+temp) = 0;
                *(col_shift+temp) = 1;

            }
            else if (ii==2)
            { // bottom
                *(row_shift+temp) = 1;
                *(col_shift+temp) = 0;
            }
            else if (ii==3)
            { // left
                *(row_shift+temp) = 0;
                *(col_shift+temp) = -1;
            }
            temp++;
        }
        // bit shift right to get the higher bit
        adj_vert = adj_vert >> 1;
    }
}

uint8_t count_area_by_BFS(int** grid, struct list * BFS_queue, struct list * grid_pt, int * gridSize, int * gridColSize, int * area_cnt)
{
    // define the normal variables
    uint8_t adj_num;
    struct list * p_grid_pt2;
    uint8_t adj_vert = 0;

    // 1: get the adjacent cells
    adj_num=get_adj_idx(grid, grid_pt, gridSize, gridColSize, &adj_vert);
    if (adj_num>0)
    {
        int8_t row_shift[adj_num];
        int8_t col_shift[adj_num];
        //printf("(%d, %d)", grid_pt->row, grid_pt->col);
        fill_shift_nums(adj_num, adj_vert, row_shift, col_shift);
        *(*(grid+grid_pt->row)+grid_pt->col) = GRAY;
        //printf("(%d, %d): %d", grid_pt->row, grid_pt->col, *(*(grid+grid_pt->row)+grid_pt->col));

        // 2: for each adj_nums, intput into a queue
        for (int ii = 0; ii<adj_num; ii++)
        {
            uint8_t curr_row = grid_pt->row + row_shift[ii];
            uint8_t curr_col = grid_pt->col + col_shift[ii];
            //printf("(%d, %d): %d,%d  \n", curr_row, curr_col, (*(*(grid+curr_row)+curr_col)), *area_cnt);

            if (*(*(grid+curr_row)+curr_col)==WHITE)
            {
                struct list * adj_list = (struct list *)malloc(sizeof(struct list));
                init_list(adj_list, curr_row, curr_col);
                *(*(grid+curr_row)+curr_col) = GRAY;
                BFS_queue = enqueue(BFS_queue, adj_list);
            }
        }
    }
    *(*(grid+grid_pt->row)+grid_pt->col) = BLACK;

    // dequeue
    p_grid_pt2 = pop(&BFS_queue);
    (*area_cnt)++;
    printf("(%d, %d): area=%d \n", grid_pt->row, grid_pt->col, ((*area_cnt)));

    if (p_grid_pt2!=NULL)
    {
        struct list * p_temp = p_grid_pt2;

        printf("Popped: (%d, %d)\n", p_grid_pt2->row, p_grid_pt2->col);

        printf("[");
        while (p_temp!=NULL)
        {
            printf("(%d, %d),", p_temp->row, p_temp->col);
            p_temp = p_temp->next;
        }
        printf("]\n");
        count_area_by_BFS(grid, BFS_queue, p_grid_pt2, gridSize, gridColSize, area_cnt);
        free(p_grid_pt2);
    }

    // free the grid point if malloced here.

    return *area_cnt;
}




// main function for the problem.
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){

    int max_area = 0; // maximum area found so far
    int area = 0; // area of an island returned by BFS.
    struct list * BFS_queue;
    struct list grid_pt;

    BFS_queue = NULL;
    for (int ii=0; ii<gridSize; ii++)
    {
        for (int jj=0; jj<(*gridColSize); jj++)
        {
            uint8_t tmp = *(*(grid+ii)+jj);
            if (tmp==WHITE)
            {// when the current grid is an island and not visited, run BFS to explore.
               area = 0;
               init_list(&grid_pt, ii, jj);
               count_area_by_BFS(grid, BFS_queue, &grid_pt, &gridSize, gridColSize, &area);
            }
            //printf("(%d, %d): %d", ii, jj, tmp);

            if (area>max_area)
            {// when the returned area is larger than the current max.
                max_area = area;
            }
        }
    }
    // TODO: have get location function.
    return max_area;
}
/* main.c */
int main(int argc, char *argv[]) {

    //printf("Hello, World\n");
int gridSize = 50;
int gridColSize = 50;

// Generate grid
int ** grid = (int**)malloc(sizeof(int*)*gridSize);
for (int ii=0;ii<gridSize; ii++)
{
    grid[ii] = malloc(sizeof(int)*gridColSize);
}
for (int ii=0; ii<gridSize; ii++)
{
    for (int jj =0; jj<gridColSize; jj++)
    {
        grid[ii][jj] = 1;
    }
}

/*
grid ={
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','1'},
        {'0','0','0','1','1'}
};
*/
// express the locations of the ones by row, col arrays
uint8_t row_idx[8] = {0, 0, 1, 1, 2, 2, 3, 3};
uint8_t col_idx[8] = {0, 1, 0, 1, 3, 4, 3, 4};
for (int ii = 0; ii<8; ii++)
{// fill in the ones
    uint8_t row_i = row_idx[ii];
    uint8_t col_i = col_idx[ii];
    grid[row_i][col_i] = 1;
}

/*print the grid*/
for (int ii=0; ii<gridSize; ii++)
{
    for (int jj =0; jj<gridColSize; jj++)
    {
        printf("%d", grid[ii][jj]);
    }
    printf("\n");
}

    int islandCnt = maxAreaOfIsland(grid, gridSize, &gridColSize);
    printf("island Count = %d\n", islandCnt); // results


    // free malloc memory
    for (int ii=0;ii<gridSize; ii++)
    {
        free(grid[ii]);
    }
    free(grid);

    return 0;
}
