
#include<stdio.h>
#include<stdint-gcc.h>
#include<stdbool.h>
#include<stdlib.h>
#include <time.h>


enum vertex_color
{
    WHITE=0, // not explored at all
    GRAY=1, // some adjacent verticies explored.
    BLACK=2 // all explored;
};

struct vertex
{
    enum vertex_color color;  // coloring for the exploring status
    struct vertex * parent; // parent of the vertex with row, col pair
    int time;   // time of reached exploration
    int row;    // row of the grid
    int col;    // column of the grid
};

/*
This function swaps the value of a and b
*/
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
This function shuffles the entry in an array.
arr[]: array containing integer values
n: size of an array
*/
void randomize ( int arr[], int n )
{   // use the different timing to generate random num
    //srand ( time(NULL) );
    for (int ii = n-1; ii > 0; ii--)
    {
        int jj = rand() % (ii+1);
        swap(&arr[ii], &arr[jj]);
    }
}

/**
This function creates a maze with nxn grid.
Each entry has a number 0~15 representing the direction where there is NO wall.
A: maze map containing the information of which direction is open.
c_row; current row index;
c_col: current column index;
n: size of the maze(nxn)

*/
void generateMaze(int ** A, int c_row, int c_col, int n)
{
    // top = 8
    // right = 4
    // bottom = 2
    // left = 1;

    int d_row, d_col;
    int opp = 0;
    int fwd = 0;

    static int tmp[4] = {0,1,2,3};
    randomize(tmp, 4);
    for (int ii=0; ii<4; ii++)
    {//
        if (tmp[ii] == 0)
        {d_row = -1; d_col = 0; fwd = 8; opp = 2; }// top}
        else if (tmp[ii] == 1){ d_row = 0; d_col=1; fwd = 4; opp = 1;} // right}
        else if (tmp[ii] == 2){ d_row = 1; d_col=0; fwd = 2; opp = 8; }// bottom}
        else if (tmp[ii] == 3){ d_row = 0; d_col=-1; fwd = 1; opp = 4;} // left
        else return;
        int n_row = c_row + d_row;
        int n_col = c_col + d_col;
        if ( n_row>=0 && n_col>=0 && n_row<n && n_col<n && A[n_row][n_col]==0)
        { // new cell is in the grid, and new cell hasn't been visited.
            A[c_row][c_col] += fwd;
            A[n_row][n_col] += opp;
            generateMaze(A, n_row, n_col, n);
        }
    }
}

/*
This function prints out the maze from maze matrix A of size n by n
A: maze map containing the information of which direction is open.
n: size of the maze(nxn)
*/
void printMaze(int ** A, int n)
{
    for (int row_i = -1; row_i<n; row_i++)
    {
        for (int col_i=-1; col_i<n; col_i++)
        {
            if (row_i==-1) printf("__");
            else if (col_i==-1) printf("|");
            else
            {
                bool right = A[row_i][col_i] & 0x04;
                bool bottom = A[row_i][col_i] & 0x02;
                (bottom==0)? printf("_"):printf(" ");
                if (right==0)
                {// right is not open
                    printf("|");
                }
                else
                {// right side is open
                    if (bottom==1)
                    {// bottom is open
                        printf(" ");
                    }else{
                        printf("_");
                    }
                }
            }
        }
        printf("\n");
    }


}

/*
This function recursively explores the grid until it reaches the goal grid(n-1, n-1).

ver_arr: 2D array containing the pointer to a vertex structure
A: maze map containing the information of which direction is open.
time; time of visit
c_row: current row index
c_col: current column index
n: size of the maze(nxn)
*/
int DFS_visit(struct vertex *** ver_arr, int ** A, int * time, int c_row, int c_col, int n)
{
    int fin = 0;
    if (c_col==n-1 && c_row == n-1) return 1;
    (*time)++;

    int adj = *(*(A+c_row)+c_col);
    int top = adj&0x08; int right = adj&0x04; int bottom = adj&0x02; int left = adj&0x01;

    struct vertex * c_vert = *(*(ver_arr+c_row)+c_col);
    c_vert->color = GRAY;
    c_vert->time = (*time);

    if (top && fin==0){
        struct vertex * adj_vert = *(*(ver_arr+c_row-1)+c_col);
        if (adj_vert->color == WHITE)
        {
            adj_vert->parent = c_vert;
            printf("up, %d, (%d,%d)\n", (*time), c_row, c_col);
            fin = DFS_visit(ver_arr, A, time, c_row-1, c_col, n);
        }
    }

    if (right&& fin==0){
        struct vertex * adj_vert = *(*(ver_arr+c_row)+c_col+1);
        if (adj_vert->color == WHITE)
        {
            adj_vert->parent = c_vert;
            printf("right, %d, (%d,%d)\n", (*time), c_row, c_col);
            fin=DFS_visit(ver_arr, A, time, c_row, c_col+1, n);
        }
    }

    if (bottom&& fin==0)
    {
        struct vertex * adj_vert = *(*(ver_arr+c_row+1)+c_col);
        if (adj_vert->color == WHITE)
        {
            adj_vert->parent = c_vert;
            printf("down, %d, (%d,%d)\n", (*time), c_row, c_col);
             fin = DFS_visit(ver_arr, A, time, c_row+1, c_col, n);
        }
    }
    if (left&& fin==0)
    {
        struct vertex * adj_vert = *(*(ver_arr+c_row)+c_col-1);
        if (adj_vert->color == WHITE)
        {
            adj_vert->parent = c_vert;
            printf("left, %d, (%d,%d)\n", (*time), c_row, c_col);
            fin=DFS_visit(ver_arr, A, time, c_row, c_col-1, n);
        }
    }
    c_vert->color = BLACK;
    (*time)++;
    c_vert->time = *time;
    return fin;
}

/*
This function finds the solution to the maze by the depth first search
A: maze map containing the information of which direction is open.
n: size of the maze(nxn)
*/
void DFS(int ** A, int n)
{
    struct vertex *** ver_arr = (struct vertex ***)malloc(sizeof(struct vertex **)*n);
    for (int row_i = 0; row_i<n; row_i++)
    {
        struct vertex ** ver_row = (struct vertex **)malloc(sizeof(struct vertex *)*n);
        for (int col_i = 0; col_i<n; col_i++)
        {
            struct vertex * p_ver = (struct vertex *)malloc(sizeof(struct vertex));
            p_ver->color = WHITE;
            p_ver->parent = NULL;
            p_ver->time = 0;
            p_ver->row = row_i;
            p_ver->col = col_i;
            ver_row[col_i] = p_ver;
        }
        ver_arr[row_i] = ver_row;
    }
    int time = 0;

    int fin= DFS_visit(ver_arr, A, &time, 0, 0, n);
    struct vertex * p_ver = ver_arr[n-1][n-1];

    // print out the route
    while (p_ver)
    {
        printf("(%d,%d)<-", p_ver->row, p_ver->col);
        p_ver = p_ver->parent;
    }

    // free all the memory
    for (int row_i = 0; row_i<n; row_i++)
    {
        for (int col_i = 0; col_i<n; col_i++)
        {
            struct vertex * tmp = ver_arr[row_i][col_i];
            free(tmp);
        }
        free(ver_arr[row_i]);
    }
    free(ver_arr);
}

/* main.c */
int main(int argc, char *argv[]) {

    //printf("Hello, World\n");

    int n = 20; // size of the maze(n by n)s

    int ** A = (int**)malloc(sizeof(int*)*n);
    for (int ii = 0; ii<n; ii++){
        A[ii] = (int*) malloc(sizeof(int)*n);
    }
    for (int row=0; row<n; row++)
    {
        for (int col=0; col<n; col++)
        {
          A[row][col] = 0;
        }
    }
    // create maze
    generateMaze(A, 0, 0, n);

    // display maze
    printMaze(A, n);
    // solve the maze
    DFS(A, n);

    // take care of the maze
    for (int ii = 0; ii<n; ii++)
    {
        free(A[ii]);
    }
    free(A);
    return 0;
}
