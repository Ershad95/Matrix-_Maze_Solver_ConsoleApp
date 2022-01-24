#ifndef MAZE_M_H_INCLUDED
#define MAZE_M_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 100
#define n 14
#define m 14
class maze
{
private:
	int row;
	int col;
	char dir;
	char last_choice;
public:
	void push(char l_dir);
	int check_s(int push);
	void trace(void);
	maze pop(void);
	void choice_way();
	void show(int matrix[20][20]);
};

int top = -1;
int *ptop = &top;
int right_left = 0;
int left_right = 0;
int top_down = 0;
int down_top = 0;
int *rl = &right_left;
int *lr = &left_right;
int *td = &top_down;
int *dt = &down_top;
int i_matrix, j_matrix;
int *i = &i_matrix;
int *j = &j_matrix;
maze Stack[MAX_SIZE];

int matrix[20][20] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

#endif // MAZE_M_H_INCLUDED
