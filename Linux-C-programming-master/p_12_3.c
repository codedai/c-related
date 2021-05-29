#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point {int row, col;};
int top = 0;

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

int find_way(int row, int col) {
    if (
        (row >= MAX_ROW || row < 0) || (col >= MAX_COL || col < 0)
    ) return 0;
    maze[row][col] = 2;
    if ((row == MAX_ROW - 1) && (col == MAX_COL - 1)) {
        printf("(%d, %d)\n", row, col);
        return 1;
    } else if (
        (maze[row][col+1] == 0) && find_way(row, col+1) 
    ) {
        printf("(%d, %d)\n", row, col);
        return 1;
    } else if (
        (maze[row][col-1] == 0) && find_way(row, col-1) 
    ) {
        printf("(%d, %d)\n", row, col);
        return 1;
    } else if (
        (maze[row+1][col] == 0) && find_way(row+1, col) 
    ) {
        printf("(%d, %d)\n", row, col);
        return 1;
    } else if (
        (maze[row-1][col] == 0) && find_way(row-1, col) 
    ) {
        printf("(%d, %d)\n", row, col);
        return 1;
    }
    return 0;
}

int main(void)
{
    if (!find_way(0, 0)) {
        printf("No Path!\n");
    }
	return 0;
}