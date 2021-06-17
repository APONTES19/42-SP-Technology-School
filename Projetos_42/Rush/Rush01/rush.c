void	print_board (int table[6][6]);

void	ft_putchar(char c);

void	ft_print_error (void);

void	fill_values (int table[6][6])
{
	int	line;
	int	column;

	column = 0;
	line = 0;
	while (column <= 4)
	{
		if (table[line][column] == 4)
			table[line + 1][column] = 1;
		column++;
	}
	line = 1;
	column = 0;
	while (line <= 4)
	{
		if (table[line][column] == 4)
		{
			table[line + 1][column] = 1;
			column++;
		}
		line++;
	}
	print_board(table);
}

void	create_board (int table[6][6], char *str)
{
	table[0][1] = str[0] - '0';
	table[0][2] = str[2] - '0';
	table[0][3] = str[4] - '0';
	table[0][4] = str[6] - '0';
	table[5][1] = str[8] - '0';
	table[5][2] = str[10] - '0';
	table[5][3] = str[12] - '0';
	table[5][4] = str[14] - '0';
	table[1][0] = str[16] - '0';
	table[2][0] = str[18] - '0';
	table[3][0] = str[20] - '0';
	table[4][0] = str[22] - '0';
	table[1][5] = str[24] - '0';
	table[2][5] = str[26] - '0';
	table[3][5] = str[28] - '0';
	table[4][5] = str[30] - '0';
}

void	print_board (int table[6][6])
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			c = '0' + table[i][j];
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	fill_table_zeros (int table[6][6])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			table[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	rush (char *str)
{
	int	table[6][6];

	fill_table_zeros (table);
	create_board (table, str);
	fill_values (table);
	return (0);
}

/*
4 3 2 1 top
1 2 2 2 bottom
4 3 2 1 left
1 2 2 2 right
- do rush

"1 2 4 2 3 2 1 3 1 2 2 3 2 1 3 2" - de test do  game
"3 2 2 1 2 3 1 3 4 2 1 2 1 2 4 2" - de test do  game2
"2 1 3 3 3 2 2 1 2 1 2 3 2 3 2 1" - de test do  game3
"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" - mais um teste da dica erison

   0  1  2  3  4  5
0 [0][4][3][2][1][0]
1 [4][0][0][0][0][1]
2 [3][0][0][0][0][2]
3 [2][0][0][0][0][2]
4 [1][0][0][0][0][2]
5 [0][1][2][2][2][0]
  x  1  x  x
x[ ][4][ ][ ]x
1[4][ ][ ][ ]x
x[ ][ ][ ][4]1
x[ ][ ][4][ ]1
  x  x  1  x
1 - 4

if (table[line][column] == 4 || table[line][column] == 1)
	{
	if (table[line][column] == 4)
	{
		table[line + 1][column] = 1;
		column++;
	}
	else
	{
		table[line + 1][column] = 4;
		column++;
	}
}
column = 0;
while (column < 4)
{
	line = 5;
	column = 1;

	if (table[line][column] == 4 || table[line][column] == 1)
	{
		if (table[line][column] == 4)
		{
			table[line + 1][column] = 1;
			column++;
		}
		else
		{
			table[line + 1][column] = 4;
			column++;
		}
	}
}
*/

/*
"4 3 2 1 top 1 2 2 2 bot 4 3 2 1 left 1 2 2 2 right"

[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]
[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]
[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]
[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]
[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]
[0][0] [0][0] [0][0] [0][0] [0][0] [0][0]

[-][4][3][2][1][-]
[4][0][0][0][0][1]
[3][0][0][0][0][2]
[2][0][0][0][0][2]
[1][0][0][0][0][2]
[-][1][2][2][2][-]

*/

/*
modelo do welton

while (i < 6)
{
	j = 0;
	while (j < 6){
		mat[i][j] = 0;
		j++;
	}
	i++;
}

   0  1  2  3  4  5
0 [4][3][2][1][0]
1 [0][0][0][0][1]
2 [0][0][0][0][2]
3 [0][0][0][0][2]
4 [0][0][0][0][2]
5 [1][2][2][2][0]

mat[0][1] = 4;
mat[0][2] = 3;
mat[0][3] = 2;
mat[0][4] = 1;

mat[1][0] = 4;
mat[1][5] = 1;

mat[2][0] = 3;
mat[2][5] = 2;

mat[3][0] = 2;
mat[3][5] = 2;

mat[4][0] = 1;
mat[4][5] = 2;

mat[5][1] = 1;
mat[5][2] = 2;
mat[5][3] = 2;
mat[5][4] = 2;
*/