#include <iostream>

using namespace std;

// Definition of the function
void draw();
void replace(int i, char c);
bool checkavailbaility(int input);
bool cheakwinner(char XorO);
void initializecharacters();

// global variable 
char c1, c2, c3, c4, c5, c6, c7, c8, c9;
char player = 'X';

int main()
{
	int input;

	// while loop to play again if user enter 1
	while (true)
	{
		int counter = 0;
		initializecharacters();
		cout << "Welcome to X-O game \n";

		// while loop to Repeat until one wins or draw
		while (true)
		{
			draw();

			cout << "player's role " << player << endl;
			cin >> input;

			// while loop to check  to enterd X or O 
			while (!checkavailbaility(input))
			{
				cout << "the number you entered is taken or incorrect \n";
				cout << "please enter another number: \n";
				cin >> input;
			}

			// if condition to know the role of X or O
			if (counter % 2 == 0)
			{
				replace(input, 'X');
				player = 'O';
			}
			else
			{
				replace(input, 'O');
				player = 'X';
			}

			counter++;
			
			// if condition to check winner or draw
			if (cheakwinner('X') || cheakwinner('O'))
			{
				cout << "do you need play again? \n";
				break;
			}
			else if (counter == 9)
			{
				cout << "Draw, do you want play again? \n";
				break;
			}

		}

		cout << "1- yes \n" << "2- no \n";
		cin >> input;

		//if condition to continue or exit game
		if (input == 1)
			continue;
		else
			exit(0);
			
	}

	return 0;
}

// function to initialize characters
void initializecharacters()
{
	c1 = '1';
	c2 = '2';
	c3 = '3';
	c4 = '4';
	c5 = '5';
	c6 = '6';
	c7 = '7';
	c8 = '8';
	c9 = '9';
}

// function to print the paper
void draw()
{
	cout << "|\t" << c1 << "\t|\t" << c2 << "\t|\t" << c3 << "\t|" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|\t" << c4 << "\t|\t" << c5 << "\t|\t" << c6 << "\t|" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|\t" << c7 << "\t|\t" << c8 << "\t|\t" << c9 << "\t|" << endl;
	cout << "-------------------------------------------------" << endl;
}

// function to replace number to X or O
void replace(int i, char c)
{
	switch (i)
	{
		case 1:
			c1 = c;
			break;
		case 2:
			c2 = c;
			break;
		case 3:
			c3 = c;
			break;
		case 4:
			c4 = c;
			break;
		case 5:
			c5 = c;
			break;
		case 6:
			c6 = c;
			break;
		case 7:
			c7 = c;
			break;
		case 8:
			c8 = c;
			break;
		case 9:
			c9 = c;
			break;
	}
}

// function to check number entered between 1 and 9 and check space of number has X or O 
bool checkavailbaility(int input)
{
	if (input < 1 || input > 9)
		return false;

	switch (input)
	{
	case 1:
		if (c1 == '1')
			return true;
		break;
	case 2:
		if (c2 == '2')
			return true;
		break;
	case 3:
		if (c3 == '3')
			return true;
		break;
	case 4:
		if (c4 == '4')
			return true;
		break;
	case 5:
		if (c5 == '5')
			return true;
		break;
	case 6:
		if (c6 == '6')
			return true;
		break;
	case 7:
		if (c7 == '7')
			return true;
		break;
	case 8:
		if (c8 == '8')
			return true;
		break;
	case 9:
		if (c9 == '9')
			return true;
		break;
	}
	
	return false;
}

// function to chexk the winner is X or O 
bool cheakwinner(char XorO)
{
	bool q1 = (c1 == XorO && c2 == XorO && c3 == XorO);
	bool q2 = (c4 == XorO && c5 == XorO && c6 == XorO);
	bool q3 = (c7 == XorO && c8 == XorO && c9 == XorO);

	bool w1 = (c1 == XorO && c4 == XorO && c7 == XorO);
	bool w2 = (c2 == XorO && c5 == XorO && c8 == XorO);
	bool w3 = (c3 == XorO && c6 == XorO && c9 == XorO);

	bool e1 = (c1 == XorO && c5 == XorO && c9 == XorO);
	bool e2 = (c3 == XorO && c5 == XorO && c7 == XorO);

	if (q1 || q2 || q3 || w1 || w2 || w3 || e1 || e2)
	{
		draw();
		cout << "The winner is player " << XorO << endl;
		return true;
	}
	return false;
}