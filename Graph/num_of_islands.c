
#include<stdio.h>
#include<stdint-gcc.h>
#include<stdbool.h>
#include<stdlib.h>
char SEA = '0'; // not island
char WHITE='1'; // not explored at all
char GRAY='2';  // some adjacent verticies explored.
char BLACK='3'; // all explored;


/*
adj_num: num of adjacent cells
adj_vert: adjacent cells, expressed with bit shift.

output:
row_shift: array of size adj_num, containing the row direction for the adjacent cells
col_shift: array of size adj_num, containing the column direction for the adjacent cells
*/
void fill_shift_nums(uint8_t adj_num, uint8_t adj_vert, int8_t * row_shift, int8_t * col_shift)
{
    uint8_t temp = 0;
    for (int ii = 0; ii<4; ii++)
    {
        if (adj_vert & 0x01)
        {
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
        adj_vert = adj_vert >> 1;
    }
}


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
uint8_t get_adj_idx(char ** grid, int c_row, int c_col, int* gridSize, int* gridColSize, uint8_t* adj_vert)
{
    uint8_t adj_num = 0;
    // top cell
    if (c_row>0 && *(*(grid+c_row-1)+c_col)!=SEA)
    {
        *adj_vert |= 0x01;
        adj_num++;
    }
    // right cell
    if (c_col+1<*gridColSize && *(*(grid+c_row)+c_col+1)!=SEA)
    {
        *adj_vert |= 0x02;
        adj_num++;
    }
    // bottom cell
    if (c_row+1<*gridSize && *(*(grid+c_row+1)+c_col)!=SEA){
       *adj_vert |= 0x04;

        adj_num++;
    }
    // left cell
    if (c_col>0 && *(*(grid+c_row)+c_col-1)!=SEA){
        *adj_vert |= 0x08;
        adj_num++;
    }
    return adj_num;
}


/*
grid: 2D char array
c_row: current row index
c_col: current column index
gridSize: size of rows
gridColSize: size of columns
*/
//DFS algorithm
void DFS_visit(char ** grid, int c_row, int c_col, int* gridSize, int* gridColSize)
{

    // set to gray
    *(*(grid+c_row)+c_col) = GRAY;


    uint8_t adj_vert = 0;
    uint8_t adj_num = get_adj_idx(grid, c_row, c_col, gridSize, gridColSize, &adj_vert);
    if (adj_num>0)
    {
        int8_t row_shift[adj_num];
        int8_t col_shift[adj_num];
        fill_shift_nums(adj_num, adj_vert, row_shift, col_shift);

        for (int ii=0; ii<adj_num; ii++)
        {
            if (*(*(grid+c_row+row_shift[ii])+ c_col+col_shift[ii])==WHITE)
            {
                DFS_visit(grid, c_row+row_shift[ii], c_col+col_shift[ii], gridSize, gridColSize);
            }
        }
    }
    *(*(grid+c_row)+c_col) = BLACK;
}



/*
gridSize: size of the rows
gridColSize: size of the column.

grid: 2D array of char.

*/
int numIslands(char** grid, int gridSize, int* gridColSize){


    // Start from the left
    /*
    1. From left top, check if it's 1 && being white
    2. if yes, perform DFS.
        set all the visited cells to be black (<- This has to be accessible )
    3. increase the island count.
    4. Finish when the iteration of the cell loop end and return the island count

    Consideration:
        The color of the cells has to be accessible in the top level.
    */
    int islandCnt = 0;
    for (int row_i=0; row_i<gridSize; row_i++)
    {

        for (int col_i=0; col_i<(*gridColSize); col_i++)
        {
            if (*(*(grid+row_i)+col_i) == WHITE)
            {
                DFS_visit(grid, row_i, col_i, &gridSize, gridColSize);
                islandCnt++;
            }
        }
    }
    return islandCnt;
}

/* main.c */
int main(int argc, char *argv[]) {

    //printf("Hello, World\n");
int gridSize = 4;
int gridColSize = 5;

// Generate grid
char ** grid = (char**)malloc(sizeof(char*)*gridSize);
for (int ii=0;ii<gridSize; ii++)
{
    grid[ii] = malloc(sizeof(char)*gridColSize);
}
for (int ii=0; ii<gridSize; ii++)
{
    for (int jj =0; jj<gridColSize; jj++)
    {
        grid[ii][jj] = '0';
    }
}

/*
grid ={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','1','1'}
};
*/
// express the locations of the ones by row, col arrays
uint8_t row_idx[11] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3};
uint8_t col_idx[11] = {0, 1, 2, 3, 0, 1, 3, 0, 1, 3, 4};
for (int ii = 0; ii<11; ii++)
{// fill in the ones
    uint8_t row_i = row_idx[ii];
    uint8_t col_i = col_idx[ii];
    grid[row_i][col_i] = '1';
}


/*print the grid*/
for (int ii=0; ii<gridSize; ii++)
{
    for (int jj =0; jj<gridColSize; jj++)
    {
        printf("%c", grid[ii][jj]);
    }
    printf("\n");
}

    int islandCnt = numIslands(grid, gridSize, &gridColSize);
    printf("island Count = %d\n", islandCnt); // results
    return 0;
}
