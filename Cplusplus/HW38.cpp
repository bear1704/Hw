#include <iostream>
#include <fstream>
//런타임 오류 안 고쳐짐
enum Player
{
	P0,
	P1,
	P2
	
};

class ConnectFour
{
public:
	ConnectFour()
	{
		player = P0;
		vtCombo = 0;
		hrCombo = 0;
		diagComboL = 0;
		diagComboR = 0;
		exist = false;
	}

	ConnectFour(unsigned int player_) 
	{
		vtCombo = 0;
		hrCombo = 0;
		diagComboL = 0;
		diagComboR = 0;
		player = player_;
		exist = false;
	}

private:

	unsigned int vtCombo;//vertical combo
	unsigned int hrCombo; //horizontal combo
	unsigned int diagComboL;
	unsigned int diagComboR;
	unsigned int player;
	bool exist;

public:

	int GetVtCombo()
	{
		return vtCombo;
	}
	int GetHrCombo() 
	{
		return hrCombo;
	}
	int GetDiagComboL()
	{
		return diagComboL;
	}
	int GetDiagComboR()
	{
		return diagComboR;
	}
	void SetVtCombo(unsigned int vt)
	{
		vtCombo = vt;
	}
	void SetHrCombo(unsigned int hr)
	{
		hrCombo = hr;
	}
	void SetDiagComboL(unsigned int dg)
	{
		diagComboL = dg;
	}
	void SetDiagComboR(unsigned int dg)
	{
		diagComboR = dg;
	}
	void SetExist(bool exist_)
	{
		exist = exist_;
	}
	int GetPlayer()
	{
		return player;
	}
	
	bool isExist()
	{
		return exist;
	}

	

};


void AddCombo(ConnectFour(*board)[8], int x, int y);
int TestBoard(ConnectFour(*board)[8]);
void InsertStone(ConnectFour(*board)[8], unsigned int stoneX, int player);

int main()
{

	std::ifstream in;
	in.open("input.txt");
	int cases, n;

	in >> cases;

	for (int c = 0; c < cases; c++)
	{
		ConnectFour board[7][8];

		in >> n;

		for (int i = 0; i <= n; )
		{
			int insNum;

			if (i == (n)) //우위가 안 정해졌을때
			{
				std::cout << "0" << std::endl;
				break;
			}

		
			in >> insNum;

			InsertStone(board, insNum, P1);

			for (int y = 1; y <= 6; y++)
			{
				for (int x = 1; x <= 7; x++)
				{
					AddCombo(board, x, y);
				}
			}  //P1의 스톤을 넣고, P1의 점수계산
			
			if (TestBoard(board) > 0)
			{
				std::cout << TestBoard(board) << std::endl;
			
				break;
			}
			i++;
	

			if (i == (n)) //우위가 안 정해졌을때
			{
				std::cout << "0" << std::endl;
				break;
			}  //런타임오류뜰때 개방

			
			in >> insNum;
			InsertStone(board, insNum, P2);
			for (int y = 1; y <= 6; y++)
			{
				for (int x = 1; x <= 7; x++)
				{
					AddCombo(board, x, y);
				}
			}  //P2의 스톤을 넣고, P1의 점수계산

			if (TestBoard(board) > 0)
			{
				std::cout << TestBoard(board) << std::endl;
				break;
			}
			i++;
		
		
		}


	}


	//system("pause");
	in.close();
	return 0;
}

void AddCombo(ConnectFour (*board)[8], int x, int y)  
{
	

	if (x != 7) //마지막단
	{
		if ((board[y][x + 1].GetPlayer() == board[y][x].GetPlayer())  &&   board[y][x].GetPlayer() != P0) // 오른쪽의 플레이어가 같다면
		{
			board[y][x + 1].SetHrCombo((board[y][x].GetHrCombo()) + 1);//자기콤보 + 1해서 적용
		}
	}

	if (y != 6) //마지막단
	{
		if ((board[y + 1][x].GetPlayer() == board[y][x].GetPlayer()) && board[y][x].GetPlayer() != P0) // 아래쪽 동일
		{
			board[y + 1][x].SetVtCombo((board[y][x].GetVtCombo()) + 1);
		}

	}

	if (x != 7 || y != 6)
	{
		if ((board[y + 1][x + 1].GetPlayer() == board[y][x].GetPlayer()) && board[y][x].GetPlayer() != P0)
		{
			board[y + 1][x + 1].SetDiagComboR((board[y][x].GetDiagComboR()) + 1);
		} //오른대각선 동일
		
	}

	if (x != 1 || y != 6)
	{
		if ((board[y + 1][x - 1].GetPlayer() == board[y][x].GetPlayer()) && board[y][x].GetPlayer() != P0)
		{
			board[y + 1][x - 1].SetDiagComboL((board[y][x].GetDiagComboL()) + 1);
		} //왼대각선 동일
	}

	
}

void InsertStone(ConnectFour (*board)[8], unsigned int stoneX,int player)
{

	for (int y = 6; y >= 1; y--)
	{
		if (board[y][stoneX].isExist() == false)
		{
			board[y][stoneX] = ConnectFour(player);
			board[y][stoneX].SetExist(true);
			board[y][stoneX].SetVtCombo(1);
			board[y][stoneX].SetHrCombo(1);
			board[y][stoneX].SetDiagComboL(1);
			board[y][stoneX].SetDiagComboR(1);
			break;
		}
	}


}


int TestBoard(ConnectFour (*board)[8])
{
	//
	//for (int i = 1; i <= 6; i++)
	//{
	//	for (int j = 1; j <= 7; j++)
	//	{
	//		std::cout << board[i][j].GetPlayer() << " ";
	//	}
	//	std::cout << std::endl;
	//}

	


	//for (int i = 1; i <= 6; i++)
	//{
	//	for (int j = 1; j <= 7; j++)
	//	{
	//		std::cout << board[i][j].GetVtCombo() << " ";
	//	}
	//	std::cout << std::endl;
	//}


	
	
	
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			if (board[i][j].GetHrCombo() >= 4 || board[i][j].GetVtCombo() >= 4)
			{
				return board[i][j].GetPlayer();
			}
			
			if ((board[i][j].GetDiagComboL() >= 4) || (board[i][j].GetDiagComboR() >= 4))
			{
				return board[i][j].GetPlayer();
			}
		}
		
	}

	return 0;

}