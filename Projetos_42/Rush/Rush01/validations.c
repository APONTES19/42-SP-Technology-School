int	space_verification (char c)
{
	if (c == 32)
	{
		return (1);
	}
	return (0);
}

int	to_n (char c)
{
	return (c - '0');
}

int	valid_board (char *str)
{
	int	top;
	int	bot;
	int	left;
	int	right;

	top = to_n(str[0]) + to_n(str[2]) + to_n(str[4]) + to_n(str[6]);
	bot = to_n(str[8]) + to_n(str[10]) + to_n(str[12]) + to_n(str[14]);
	left = to_n(str[16]) + to_n(str[18]) + to_n(str[20]) + to_n(str[22]);
	right = to_n(str[24]) + to_n(str[26]) + to_n(str[28]) + to_n(str[30]);
	if (top + bot == 16 || top + bot == 17 || top + bot == 18)
	{
		if (left + right == 16 || left + right == 17 || left + right == 18)
		{
			return (1);
		}
	}
	return (0);
}

int	validate_input (char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if ((counter + 1) % 2 != 0)
		{
			if ((str[counter] >= '1' && str[counter] <= '4'))
				counter++;
			else
				return (0);
		}
		if ((counter + 1) % 2 == 0)
		{
			if (space_verification(str[counter]))
				counter++;
		}
	}
	if (!valid_board(str))
		return (0);
	return (counter == 31);
}

/*
	0 2 4 6
	8 10 12 14
	16 18 20 22
	24 26 28 30

	str[0] + str[2] == str[8] + str[10]
	top_sum = str[0] + str[2] + str[4] + str[6]
	col_bot_sum = str[8] + str[10] + str[12] + str[14]

	if (col_top_sum == col_bot_sum)
	{
		return (1)
	}
	*/

	// 35 a soma de todos os valores
	/*
	se a linha de cima for 8 || 9 a de baixo tambem precisa ser 8 || 9

	se a coluna de cima for 8 || 9 a de baixo tambem precisa ser 8 || 9
	"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" - do rush
	"1 2 4 2 3 2 1 3 1 2 2 3 2 1 3 2" - de test do  game
	"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" - mais um teste da dica erison lenda
	8 + 8
	9 + 9
	lados podem ser 10 + 7 || 9 + 9
	se lado 10 / 7
	mas coluna e linha nunca podem ter o mesmo numero, 8 - 9, nao pode 9-9 8-8
	"4 3 2 1 top 1 2 2 2 bot 4 3 2 1 left 1 2 2 2 right"

	4 3 2 1 top - 10
	1 2 2 2 bot - 7
	4 3 2 1 left - 10
	1 2 2 2 right - 7
*/