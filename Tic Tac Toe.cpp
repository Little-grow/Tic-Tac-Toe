#include <iostream>
#include<cassert>

int n = 3;
int grid[100][100]{ 0 };
int verify = 0;
int rs[100], cs[100], dr[100], dc[100];

void verification()
{
	std::cout << "Enter grid dimension:\n";      std::cin >> n;

	for (int r = 0; r < n; r++)
		rs[verify] = r, cs[verify] = 0, dr[verify] = 0, dc[verify++] = 1;
	for (int c = 0; c < n; c++)
		rs[verify] = 0, cs[verify] = c, dr[verify] = 1, dc[verify++] = 0;

	rs[verify] = 0, cs[verify] = 0, dr[verify] = 1, dc[verify++] = 1;
	rs[verify] = 0, cs[verify] = n - 1, dr[verify] = 1, dc[verify++] = -1;
}
bool validation(int r , int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 0)
	{
		std::cout << "Invalid input. Try again\n";
		return false;
	}
	return true;
}
void print()
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			char ch = '.';
			if (grid[r][c] == 1)
				ch = 'x';
			else if (grid[r][c] == 2)
				ch = 'o';
			std::cout << ch;
		}
		std::cout << '\n';
	}
}
bool Tie(int steps)
{
	if (steps == n * n)
	{
		std::cout << "Tie\n";
		return true;
	}
	return false;
}
void player_turn(int &turn , char &symbol)
{
	symbol = 'x';
	if (turn == 1)
		symbol = 'o';
	std::cout << "Player " << symbol << " turn. Enter empty location (r,c): ";
}
void input_locations(int& r  , int& c)
{
	std::cin >> r >> c;
	r = r - 1, c = c - 1;
}
void check_winner(char symbol)
{
	for (int check = 0; check < verify; check++)
	{
		int r = rs[check], c = cs[check], rd = dr[check], cd = dc[check];
		int cnt = 0, first = grid[r][c];
		if (first == 0)
			continue;
		for (int step = 0; step < n; step++, r += rd, c += cd)
		{
			if (grid[r][c] == first)
				++cnt;
		}

		if (cnt == n)
		{
			std::cout << "Player " << symbol << " won\n";
			return;
		}
	}

}

void Tic_Tac_Toe()
{
	verification();
	int turn = 0;
	int steps = 0;

	while (true)
	{
		if (Tie(steps))
			break;

		char symbol;
		player_turn(turn , symbol);

		int r = 0 , c = 0;
		input_locations(r,c);

		if (!validation(r, c))
			continue;
		
		grid[r][c] = turn + 1;
		
		print();

		check_winner(symbol);
		
		turn = ~ turn;
		steps++;
	}
}

int main()
{
	Tic_Tac_Toe();
}

