#include "maze.h"
void maze::show(int matrix[20][20])
{
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
			cout << matrix[i][j]<<" ";
		cout << "\n";
	}
	cout << "\n";
}
void maze::push(char l_dir)
{
	if (*ptop >= MAX_SIZE)
	{
		cout << " stack is full...";
	}
	else
	{
		if (((*i) == Stack[*ptop].row) && ((*j) == Stack[*ptop].col)) return;
		(*ptop)++;
		Stack[*ptop].row = *i;
		Stack[*ptop].col = *j;
		Stack[*ptop].last_choice = 'a';
		Stack[*ptop].dir = l_dir;
		cout << " : push\n\n";
	}
}


maze maze::pop(void)
{
	if (*ptop<0)
		cout << "The Stack Is Empty";
	else
	{
		maze d1;
		d1.row = Stack[*ptop].row;
		d1.col = Stack[*ptop].col;
		d1.last_choice = Stack[*ptop].last_choice;
		(*ptop)--;
		return d1;
	}
}



int maze::check_s(int p)
{
	if ((*lr) && ((matrix[*i][*j + 1] == 0 && matrix[*i - 1][*j] == 0) || (matrix[*i][*j + 1] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i - 1][*j] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i - 1][*j] == 0 && matrix[*i][*j + 1] == 0 && matrix[*i + 1][*j] == 0)))
	{
		if (p == 1) { push('r'); cout << "e"; }
		return 1;
	}
	if ((*rl) && ((matrix[*i][*j - 1] == 0 && matrix[*i - 1][*j] == 0) || (matrix[*i][*j - 1] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i - 1][*j] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i - 1][*j] == 0 && matrix[*i][*j - 1] == 0 && matrix[*i + 1][*j] == 0)))
	{
		if (p == 1) { push('l'); cout << "w"; }
		return 1;
	}
	if ((*td) && ((matrix[*i][*j + 1] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i][*j + 1] == 0 && matrix[*i][*j - 1] == 0) || (matrix[*i][*j - 1] == 0 && matrix[*i + 1][*j] == 0) || (matrix[*i + 1][*j] == 0 && matrix[*i][*j + 1] == 0 && matrix[*i][*j - 1] == 0)))
	{
		if (p == 1) { push('d'); cout << "s"; }
		return 1;
	}
	if ((*dt) && ((matrix[*i][*j + 1] == 0 && matrix[*i - 1][*j] == 0) || (matrix[*i][*j + 1] == 0 && matrix[*i][*j - 1] == 0) || (matrix[*i][*j + 1] == 0 && matrix[*i][*j - 1] == 0) || (matrix[*i - 1][*j] == 0 && matrix[*i][*j + 1] == 0 && matrix[*i][*j - 1] == 0)))
	{
		if (p == 1) { push('t'); cout << "n"; }
		return 1;
	}
	return 0;
}



void maze::choice_way()
{

	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i - 1][*j] == 0) && (Stack[*ptop].dir == 'r')) { Stack[*ptop].last_choice = 't'; (*i)--; *dt = 1; *td = 0; *lr = 0; *rl = 0;   return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j + 1] == 0) && (Stack[*ptop].dir == 'r')) { Stack[*ptop].last_choice = 'r'; (*j)++; *dt = 0; *td = 0; *lr = 1; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i + 1][*j] == 0) && (Stack[*ptop].dir == 'r')) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i][*j + 1] == 0) && ((Stack[*ptop].dir == 'r'))) { Stack[*ptop].last_choice = 'r'; (*j)++; *dt = 0; *td = 0; *lr = 1; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i][*j + 1] == 0) && ((Stack[*ptop].dir == 'r'))) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'r') && (matrix[*i + 1][*j] == 0) && ((Stack[*ptop].dir == 'r'))) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }


	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j + 1] == 0) && ((Stack[*ptop].dir == 'd'))) { Stack[*ptop].last_choice = 'r'; (*j)++; *dt = 0; *td = 0; *lr = 1; *rl = 0;   return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i + 1][*j] == 0) && ((Stack[*ptop].dir == 'd'))) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j - 1] == 0) && ((Stack[*ptop].dir == 'd'))) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 'r') && (matrix[*i + 1][*j] == 0) && (Stack[*ptop].dir == 'd')) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'r') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 'd')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 'd') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 'd')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }


	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i - 1][*j] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 't'; (*i)--; *dt = 1; *td = 0; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j + 1] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 'r'; (*j)++; *dt = 0; *td = 0; *lr = 1; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i][*j + 1] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 'r'; (*j)++; *dt = 0; *td = 0; *lr = 1; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 'r') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 't')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }


	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i - 1][*j] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 't'; (*i)--; *dt = 1; *td = 0; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i + 1][*j] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 'a') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i + 1][*j] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 'd'; (*i)++; *dt = 0; *td = 1; *lr = 0; *rl = 0;  return; }
	if ((Stack[*ptop].last_choice == 't') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }
	if ((Stack[*ptop].last_choice == 'd') && (matrix[*i][*j - 1] == 0) && (Stack[*ptop].dir == 'l')) { Stack[*ptop].last_choice = 'l'; (*j)--; *dt = 0; *td = 0; *lr = 0; *rl = 1;  return; }

	maze iu;
	iu = pop();
	*i = Stack[*ptop].row;
	*j = Stack[*ptop].col;
	if (Stack[*ptop].dir == 't') { *dt = 1; *td = 0; *lr = 0; *rl = 0; cout << "n"; }
	if (Stack[*ptop].dir == 'r') { *dt = 0; *td = 0; *lr = 1; *rl = 0; cout << "e"; }
	if (Stack[*ptop].dir == 'd') { *dt = 0; *td = 1; *lr = 0; *rl = 0; cout << "s"; }
	if (Stack[*ptop].dir == 'l') { *dt = 0; *td = 0; *lr = 0; *rl = 1; cout << "w"; }
	choice_way();

}
void maze::trace(void)
{
	if ((matrix[(*i) - 1][*j] == 0) && (!(*td)))
	{
		(*i)--;
		*dt = 1; *td = 0; *lr = 0; *rl = 0;
		cout << "n";
		return;
	}
	if ((matrix[*i][*j + 1] == 0) && (!(*rl)))
	{
		cout << "e";
		(*j)++;
		*dt = 0; *td = 0; *lr = 1; *rl = 0;
		return;
	}
	if ((matrix[*i + 1][*j] == 0) && (!(*dt)))
	{
		cout << "s";
		(*i)++;
		*dt = 0; *td = 1; *lr = 0; *rl = 0;
		return;
	}
	if ((matrix[*i][(*j) - 1] == 0) && (!(*lr)))
	{
		cout << "w";
		(*j)--;
		*dt = 0; *td = 0; *lr = 0; *rl = 1;
		return;
	}
	cout << " : pop\n\n";

	*i = Stack[*ptop].row;
	*j = Stack[*ptop].col;
	if ((Stack[*ptop].dir == 't')){ *dt = 1; *td = 0; *lr = 0; *rl = 0; cout << " n"; }
	if (Stack[*ptop].dir == 'r') { *dt = 0; *td = 0; *lr = 1; *rl = 0; cout << " e"; }
	if (Stack[*ptop].dir == 'd') { *dt = 0; *td = 1; *lr = 0; *rl = 0; cout << " s"; }
	if (Stack[*ptop].dir == 'l') { *dt = 0; *td = 0; *lr = 0; *rl = 1; cout << " w"; }
	cout << "," << *i << " " << *j << " ";
	choice_way();
}
int main()
{

	maze mz;
	mz.show(matrix);
	*i = 1; *j = 1;
	(*lr) = 1; (*rl) = 0; (*td) = 0; (*dt) = 0;
	cout << "e,1,1  ";
	while (!(((*i) == n) && ((*j) == m)))
	if (!mz.check_s(0))
	{
		mz.trace();
		cout << "," << *i << "," << *j << "  ";
	}

	else
	{
		mz.check_s(1);
		mz.choice_way();
		cout << "," << *i << "," << *j << "  ";
	}
	cout << " : push";

	cout << "\n\n";
	system("pause");
}
