#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std; 
class connect
{public:

	void display();
	void change(char player, int move);
	void play();
	int bad(int move, int check1);
	int convert(string tochange, int& move);
	connect();
	int pattern(int arr[24], int& four);
	void playertwo();
	int threeinarow(int  arr[24], int& fourthmove1, int& fourthmove2); 
	

	int collectR[24] = {};
	int collectY[24] = {};
	int use[24] = {};
	int const ROW = 6;
	int const COL = 8;
	char corr[6][8] = {};
	int move = 0;
	int row =0; 
	int col=0;
	string tochange = "";
	int end = 1;
	int count = 0;
	int fourR = 0;
	int fourY = 0; 
	const char EMPTY = '-';
	char player = 'C';
	char id = EMPTY;
	int yfourth1 = 0; 
	int yfourth2 = 0; 
	int rfourth1 = 0;
	int rfourth2 = 0;
	int rmove = 0; 
	int ymove = 0;
	
};


int main()
{
	connect myGame; 
	myGame.play();
	cout << "done"; 
}

connect::connect()
{
	for (int k = 0; k < ROW; k++)
	{
		for (int h = 0; h < COL; h++)
		{
			corr[k][h] = EMPTY;


		}
	}
	for (int k = 0; k < 24; k++)
	{
		collectR[k] = 0;
		collectY[k] = 0;
		use[k] = 0;
	}
}

void connect::display()
{
	cout <<"The board is:" << endl; 
	for (int k = 0; k < ROW; k++)
	{
		for (int h = 0; h < COL; h++)
		{
			cout << " " << corr[k][h] << " ";
			if (h == (COL - 1))
			{
				cout << endl;
			}

		}
	}
	

}
int connect::pattern(int arr[24], int& four)
{
	 
	sort(arr, arr + count +1);
	four = 0;
	// in a column, looking for 4 in same column then consecutive

	for (int h = 0; h <= count; h ++)
	{
		
		int diff = 31 - arr[h];
		four++;
		for (int k = 0; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 41)
				four++;
			else if (use[k] == 51)
				four++;
			else if (use[k] == 61)
				four++;
			else;

		}
		if (four == 4)
			return 9;
		else
			four = 0;
	}
	
	//in a row 

	for (int h = 0; h <= count; h ++)
	{
		
		int diff = 61 - arr[h];
		four++;

		for (int k = h; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 62)
				four++;
			else if (use[k] == 63)
				four++;
			else if (use[k] == 64)
				four++;
			else;
			 

		}
		if (four == 4)
			return 9;
		else
			four = 0;
	}
	
	//diagonal down 
	for (int h = 0; h <= count; h ++)
	{
	
		int diff = 31 - arr[h];
		four++;
		for (int k = 0; k <= count; k++)
		{
			use[k] = arr[k] + diff; 
			if (use[k] == 42)
				four++;
			else if (use[k] == 53)
				four++;
			else if (use[k] == 64)
				four++;
			else;

		}
		if (four == 4)
			return 9;
		else
			four = 0;
	}
	//diagonal up 
	for (int h = 0; h <= count; h++)
	{
		int diff = 38 - arr[h];
		four++;
		for (int k = h; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 47)
				four++;
			else if (use[k] == 56)
				four++;
			else if (use[k] == 65)
				four++;
			else;

			
		}
		if (four == 4)
			return 9;
		else
			four = 0;
	}
	
	
		return 1; 

} 
int connect::threeinarow(int arr[24], int& fourthmove1, int& fourthmove2)
{

	sort(arr, arr + count);
	int three = 0;
	fourthmove1, fourthmove2 = 0;
	//blank two blank row 6
	if (count == 0 || count == 1 ) {
		for (int h = 0; h <= count; h++)
		{
			for (int k = h ; k <= count; k++)
			{
				if (arr[h] + 1 == arr[k])
				{
					fourthmove1 = arr[k] + 1;
					fourthmove2 = arr[k] - 1;
					return 2;
				}
				else;

			}
		}
	}
	else; 
	// in a column, looking for 3 in same column 

	for (int h = 0; h <= count; h++)
	{

		int diff = 41 - arr[h];
		three++;
		for (int k = h; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 51)
				three++;
			else if (use[k] == 61)
				three++;
			else;


		}
		if (three == 3)
		{
			fourthmove1 = 31 - diff;
			fourthmove2 = 71 - diff; 
			if (bad(fourthmove1, 1) == 1)
				return 5;
			else if (bad(fourthmove2, 1) == 1)
				return 5;
			else
				three = 0; 
			
		}
		else
		{
			three = 0;

		}

	}

	//in a row 
	for (int h = 0; h <= count; h++)
	{

		int diff = 61 - arr[h];
		three++;
		for (int k = h; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 62)
				three++;
			else if (use[k] == 63)
				three++;
			else;


		}
		if (three == 3)
		{
			fourthmove1 = 64 - diff;
			fourthmove2 = 60 - diff;
			if (bad(fourthmove1, 1) == 1)
				return 5;
			else if (bad(fourthmove2, 1) == 1)
				return 5;
			else
				three = 0;
		}
		else
		{
			three = 0;
		}
	}

	//diagonal down 
	for (int h = 0; h <= count; h++)
	{

		int diff = 42 - arr[h];
		three++;
		for (int k = 0; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 53)
				three++;
			else if (use[k] == 64)
				three++;
			else;

		}
		if (three == 3)
		{
			fourthmove1 = 31 - diff;
			fourthmove2 = 75 - diff;
			if (bad(fourthmove1, 1) == 1)
				return 5;
			else if (bad(fourthmove2, 1) == 1)
				return 5;
			else
				three = 0;
		}
		else
			three = 0; 
	}
	//diagonal up 
	for (int h = 0; h <= count; h++)
	{
		int diff = 47 - arr[h];
		three++;
		for (int k = h; k <= count; k++)
		{
			use[k] = arr[k] + diff;
			if (use[k] == 56)
				three++;
			else if (use[k] == 65)
				three++;
			else;
		}
		if (three == 3)
		{
			fourthmove1 = 38 - diff;
			fourthmove2 = 74 - diff;
			if (bad(fourthmove1, 1) == 1)
				return 5;
			else if (bad(fourthmove2, 1) == 1)
				return 5;
			else
				three = 0;
		}
		else
			three = 0;
	}
	return 0;
}
void connect::playertwo()
{
	int check = 0; 
	while (check == 0)
	{
		if (player == 'p')
		{
			cout << "player two your turn" << endl; 
			id = 'Y';

			cout << "the following shows the coordinates for each position" << endl;
			cout << "11 12 13 14 15 16 17 18" << endl;
			cout << "21 22 23 24 25 26 27 28" << endl;
			cout << "31 32 33 34 35 36 37 38" << endl;
			cout << "41 42 43 44 45 46 47 48" << endl;
			cout << "51 52 53 54 55 56 57 58" << endl;
			cout << "61 62 63 64 65 66 67 68" << endl;
			cout << "player two you are yellow, what is your move? enter the coordinates of that position" << endl;
			cin >> tochange;
			check = convert(tochange, ymove); //0 or 2, sets move
			check = bad(ymove, check); //0 or 1, sets col, row 



		}
		else  //computer 
		{
			cout << "the computer's turn " << endl; 
			int ytoreturn, rtoreturn, firstreturn, ffourth1, ffourth2 = 0; 

			ytoreturn = threeinarow(collectY, yfourth1, yfourth2); //retunrs 5 or 0 
			rtoreturn = threeinarow(collectR, rfourth1, rfourth2) *2; //returns 10 or 0 
			firstreturn = threeinarow(collectR, ffourth1, ffourth2);//returns 2 or 0
			if (firstreturn == 2)
				check = 1; 
			else if (count == 0 || count ==1)  //first or second turn 
				check = 2;
			else if (ytoreturn == 5)  //yellow can win 
				check = 3;
			else if (rtoreturn == 10) // block red from winning
				check = 5;
			else 
				check = 5; 
			int tocheck = 0;
			int col2, row2 = 0;
			switch (check)
			{
			case 1:
				if (bad(ffourth1, 1) == 1)
				{
					ymove = ffourth1;
					break;
				}
				else if (bad(ffourth2, 1) == 1)
				{
					ymove = ffourth2;
					break;
				}
				else;
			case 2:
				while (tocheck == 0)
				{
					ymove = rand() % 19 + 51;
					tocheck = bad(ymove, 1);
				}
				break;
			case 3:
				

				 if (bad(yfourth1, 1) == 1)
				 {
					 ymove = yfourth1;
					 break;
				 }
				 else if (bad(yfourth2, 1) == 1)
				 {
					 ymove = yfourth2;
					 break;
				 }
				 else;
			case 4:
				while (tocheck == 0)
				{
					ymove = rand() % 59 + 11;
					tocheck = bad(ymove, 1);
				}
				break;
			case 5:
				
				if (bad(rfourth1, 1) == 1) //not bad 
				{
					ymove = rfourth1;
					break;
				}
				else if (bad(rfourth2, 1) == 1)
				{
					ymove = rfourth2;
					break;
				}
				else;
			case 6:
				while (tocheck == 0)
				{
					ymove = rand() % 59 + 11;
					tocheck = bad(ymove, 1);
				}
				break;
			
			}

		}
	}
	 
		
}

void connect::play()
{
	

	display(); 
	
	int check = 0;
	int maybe = 1;
	int playerint = 0;
	//determines one or two players 
	while (playerint == 0)
	{
		cout << "Type p if you're playing with another person, c if you're playing against the computer" << endl;
		cin >> player;
		if (player != 'p' && player != 'c' && player != 'P' && player != 'C')
		{
			cout << "That's not an option, please enter 'p' or 'c'" << endl;
		}
		else
			playerint = 1; 
	}
	while (end == 1 && count != 24)
	{	//player one 
		while (check == 0)
		{
			id = 'R';
			cout << "the following shows the coordinates for each position" << endl;
			cout << "11 12 13 14 15 16 17 18" << endl;
			cout << "21 22 23 24 25 26 27 28" << endl;
			cout << "31 32 33 34 35 36 37 38" << endl;
			cout << "41 42 43 44 45 46 47 48" << endl;
			cout << "51 52 53 54 55 56 57 58" << endl;
			cout << "61 62 63 64 65 66 67 68" << endl;
			cout << "player one you are red, what is your move? enter the coordinates of that position" << endl;
			cin >> tochange;
			check = convert(tochange, rmove); //equal to 0 or 2
			check = bad(rmove, check); //equal to 0 or 1, sets col, row
		}
		check = 0;
		change('R', rmove);  
		collectR[count] = rmove; 
		display();
		maybe = pattern(collectR, fourR); //returns 0 or 9
		if (maybe == 9)
		{
			end = 9;
			cout << "Player one you won!" << endl;
			break;
		}
		else
			; 
		
		//player two
		playertwo(); //sets move
		check = 0; 
		change('Y', ymove); 
		collectY[count] = ymove;
		display();
		maybe = pattern(collectY, fourY);
		if (maybe == 9)
		{
			end = 9;
			cout << "Player two you won!" << endl;
		}
		else
			;

		count++;
	}

}
int connect::convert(string tochange, int& move)  //sets equal to check1
{
	char char1 = tochange[0];
	char char2 = tochange[1];
	if (!isdigit(char1) || !isdigit(char2))
	{
		cout << "must be digits" << endl;
		return 0;
	}
	else
	{
		move = (10 * (char1 -'0') + (char2 - '0'));
		return 2;
	}

}
void connect::change(char player, int move)
{
	col = (move % 10);
	row = ((move - col) / 10);
	if (row > 6 || col > 8 || row < 1 || col < 1)
		;
	else
	{
		corr[row - 1][col - 1] = player;
	}
	 
}

int connect::bad(int move, int check1) //sets equal to check 
{
	
	if (check1 == 0)
		return 0;
	else if (move == 0)
		return 0;
	else;
	col = (move % 10);
	row = ((move - col) / 10);
	

	if (row > 6 || col > 8 || row < 1 || col < 1)
	{
		cout << "position not on board" << endl;
		return 0;
	}
	else if (corr[row - 1][col - 1] != EMPTY)
	{
		cout << "this position is already taken" << endl;
		return 0;
	}
	else if (row == 6)
		return 1;
	else if (corr[row][col - 1] == EMPTY)
	{
		cout << "position not valid.  there's no chip below" << endl;
		return 0;
	}
	else
		return 1; 
}




