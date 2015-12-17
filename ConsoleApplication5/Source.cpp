#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void degree(int m1[3][3], int m2[3][3], int m3[3][3])
{	
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			m3[i][j] = 0; //ìàòðèöà ðåçóëüòàòà
			for (int k = 0; k < 3; k++) 
			{
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}		
}

void out(int m3[3][3])
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << m3[i][j] << ' ';
		}
		cout << endl;
	}
}
void main()
{
	int M1[3][3], M2[3][3], m2[3][3], m3[3][3];		/*	m2,m3 - âñïîìîãàòåëüíûå ìàòðèöû,		*/
	cout << "Fill in first matrix" << endl;						/*	èñïîëüçóåìûå ïðè âîçâåäåíèè â ñòåïåíü,	*/
	for (int s = 0;s < 3;s++)//ñòðîêè							/*	÷òîáû íå òðîãàòü èñêîìûó ìàòðèöû.		*/
	{
		for (int c = 0;c < 3;c++)//ñòîëáöû
		{
			cin >> M1[s][c];
		}
	}
	cout << "Fill in second matrix" << endl;
	for (int s = 0;s < 3;s++)//ñòðîêè
	{
		for (int c = 0;c < 3;c++)//ñòîëáöû
		{
			cin >> M2[s][c];
		}
	}
	int numb = 0, stepen = 0;
	cout << "Power first matrix - push 1\nMultiply matrics - push 2" << endl;
	cin >> numb;
	switch (numb) //âûáîð çàäàíèÿ
	{
		case 1: 
		{
			memcpy(m2, M1, sizeof(m2));
			cout << "Degree?" << endl;
			cin >> stepen;
			if (stepen == 2)
			{
				degree(M1, m2, m3);
			}
			else
			{
				degree(M1, m2, m3);
				for (int i = 2;i < stepen;i++)
				{
					memcpy(m2, m3, sizeof(m2));
					degree(M1, m2, m3);
				}
			}
			
			out(m3);		
		}
			break;
		case 2:
		{
			degree(M1, M2, m3);
			out(m3);
		}
			break;
	}


//fin
}
