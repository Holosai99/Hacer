#include <iostream>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;

bool calcFirstMove(); 
void drowCube(int res); 
int computerOrPlayerThrow(); 
void showIntermediateResult(int pointsOfComputer, int pointsOfUser, int numberThrow); 

int main()
{
	setlocale(LC_ALL, "ukr");
	srand(time(NULL));

	int playerScore = 0;
	int computerScore = 0;
	int whoMove = 0; 
	char userName[16] = {};

	cout << "���� i�'� (����������): ";
	cin >> userName;
	
	whoMove = calcFirstMove();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			if (whoMove)
			{
				cout << "\n����� ��. ";
				playerScore += computerOrPlayerThrow();
			}
			else
			{
				cout << "\n������ ����'����. ";
				computerScore += computerOrPlayerThrow();
			}
			whoMove = !whoMove;
		}
		showIntermediateResult(computerScore, playerScore, i);		
	}	

	if (computerScore > playerScore)
	{
		cout << "\n���������� ��� - ����'����\n!";
		cout << "��������� ���������� ����.\a\a\a\a\a\n\n";
	}
	else if (computerScore < playerScore)
	{
		cout << "\n���������� �i�� ��� - " << userName << "!!! ";
		cout << "!!!�I���!!!\a\a\a\a\a\n\n";
	}
	else
	{
		cout << "\n� �i� ��i �I�I�!\a\a\a\a\a\n\n";
	}		
	return 0;
}
bool calcFirstMove()
{
	return rand() % 2;
}

void showIntermediateResult(int computerScore, int playerScore, int numberThrow) {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "����: " << computerScore << "  |||  ��:" << playerScore << endl;
	cout << "�i��� " << numberThrow + 1 << "-�� ����� ";
	if (computerScore > playerScore)
		cout << " ����� ����'����!!!\n";
	else if (computerScore < playerScore)
		cout << " ����� �������!!!\n";
	else cout << " �i�i�!!!\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}
void drowCube(int res) 
{
	switch (res)
	{
	case 1:
		cout << "#######\n";
		cout << "##   ##\n";
		cout << "##   ##\n";
		cout << "##   ##\n";
		cout << "#######\n";
		break;
	case 2:
		cout << "#######\n";
		cout << "#  ####\n";
		cout << "#  #  #\n";
		cout << "####  #\n";
		cout << "#######\n";
		break;
	case 3:
		cout << "#######\n";
		cout << "# #####\n";
		cout << "### ###\n";
		cout << "##### #\n";
		cout << "#######\n";
		break;
	case 4:
		cout << "#######\n";
		cout << "# ### #\n";
		cout << "#######\n";
		cout << "# ### #\n";
		cout << "#######\n";
		break;
	case 5:
		cout << "#######\n";
		cout << "# ### #\n";
		cout << "### ###\n";
		cout << "# ### #\n";
		cout << "#######\n";
		break;
	case 6:
		cout << "#######\n";
		cout << "# # # #\n";
		cout << "#######\n";
		cout << "# # # #\n";
		cout << "#######\n\n";
		break;
	}
}

int computerOrPlayerThrow()
{
	int result = 0;
	char c = 0;
	 
	cout << "����i�� Y i Enter, ��� ������ ������i ������: ";	
	do
	{
		cin.sync();
		cin >> c;
	} while (c != 'y' && c != 'Y');
	
	int tmp = 0;
	for (int i = 0; i < 2; ++i) {
		tmp = 1 + rand() % 6;
		drowCube(tmp);
		result += tmp;
		cout << endl;
	}

	cout << "������� �� ������� " << result << " ���i�";
	return result;
}

