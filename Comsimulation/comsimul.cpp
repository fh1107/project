// comsimul.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int midumnansu(int b)
{
	string tmp, str, result;
	str = to_string(b);
	int as = b * b;
	int middle;
	 tmp = to_string(as);
	 result = tmp.substr((tmp.size() - str.size()) / 2, str.size());
	middle = atoi(result.c_str());
	return middle;
}

int upmidumnansu(int a, int b)
{
	string tmp, str, result;
	str = to_string(a);
	int upmiddle;
	upmiddle = a * b;
	tmp = to_string(upmiddle);
	result = tmp.substr((tmp.size() - str.size()) / 2, str.size());
	upmiddle = atoi(result.c_str());
	return upmiddle;
}
int gsh(int a, int b, int c)
{
	int nans;
	nans = (a*b) % c;
	return nans;
}
int gsh2(int a, int b, int c, int d)
{
	int nans;
	nans = ((a*b) + c) % d;
	return nans;
}
int gss(int a, int b, int c)
{
	int nans;
	nans = (a+b) % c;
	return nans;
}
int main()
{
	/*int seed, s, mod, u, seed2;//  seed 초기 값, s 상수 값 , mod 나올 값 , u 조항값


			cout << "seed 값을 입력하라" << endl;
			cin >> seed;
			for (int i = 0; i < 100; i++)
			{
				seed = midumnansu(seed);
				cout << seed << endl;
				cout.width(4);
				cout.fill('0');
			}


			cout << "seed1값과 seed2의 값을 입력하라 " << endl;
			cin >> seed >> seed2;
			for (int i = 0; i < 100; i++) {
				seed = upmidumnansu(seed, seed2);
				cout << seed << endl;
				cout.width(4);
				cout.fill('0');
			}


			cout << "상수s와 seed값 mod값을 입력하라" << endl;
			cout << "상수 :";
			cin >> s;
			cout << " seed :";
			cin >> mod;
			cout << "mod :";
			cin >> seed;
			for (int i = 0; i < 100; i++) {
				seed = gsh(s, seed, mod);
				cout << seed << endl;
			}

	cout << "상수s와 seed값과 조항값u mod값을 입력하라 " << endl;
	cout << "상수 :";
	cin >> s;
	cout << "seed :";
	cin >> seed;
	cout << "조항값 : ";
	cin >> u;
	cout << "mod : ";
	cin >> mod;		cout << "seed2 : ";
			cin>> seed2;
			cout << "mod : ";
	for (int i = 0; i < 100; i++) {
		seed = gsh2(s, seed, u, mod);
		cout << seed << endl;
	}

			cout << "seed1 과 seed2 mod값을 입력하라" << endl;
			cout <<"seed1 :";
			cin >> seed;

			cin>> mod;
			for (int i = 0; i < 100; i++) {
				seed = gss(seed, seed2, mod);
				cout << seed << endl;
			}
	unsigned int seed;
	cout << "seed 값을 입력하라" << endl;
	cin >> seed;
	srand(seed);
	for (int i = 0; i < 20; i++)
	{
		cout << rand() % 99 << " " << rand() % (6500 - 5001 + 1) + 5001 << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << rand() << endl;
	}

	mt19937_64 rn,tn(seed);
	uniform_int_distribution<_int64> dist1(0, 99);
	uniform_int_distribution<_int64> dist2(5001, 6500);
	for (int i = 0; i < 20; i++)
	{
		cout << dist1(tn) <<" " << dist2(tn) << endl;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << rn() << endl;
	}
	srand((unsigned int)time(0));
	for (int i = 0; i < 20; i++)
	{
		cout << rand() % 99 <<" " <<rand() % (6500-5001 +1)+5001 << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << rand() << endl;
	}
	random_device rn;
	mt19937_64 rng(
	uniform_int_distribution<_int64> dist1(0, 99);
	uniform_int_distribution<_int64> dist2(5001, 6500);rn());
	for (int i = 0; i < 20; i++)
	{
		cout << rn() << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		cout << dist1(rng) << " " << dist2(rng) << endl;
	}
	_int64 arpart[3][20][4];
	unsigned int seed;
	ofstream csvfile;
	cout << "아파트 청약을 위한 seed값을 입력하시오 " << endl;
	cin >> seed;
	mt19937_64 rn(seed);
	uniform_int_distribution<_int64> dist1(0, 1000);
	uniform_int_distribution<_int64> dist2(1001, 2000);
	uniform_int_distribution<_int64> dist3(2001, 3000);
	for (int s = 0; s < 3; s++) {
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (s == 0) {
					arpart[s][i][j] = dist1(rn);
				}
				else if (s == 1)
				{
					arpart[s][i][j] = dist2(rn);
				}
				else
				{
					arpart[s][i][j] = dist3(rn);
				}

			}
		}
	}
	for (int t = 0; t < 3; t++)
	{
		for (int q = 0; q < 20; q++)
		{
			for (int w = 0; w < 4; w++)
			{
				for (int u = 1; u < 20; u++)
				{
						for (int y = 1; y < 4; y++)
						{
							if (arpart[t][q][w] == arpart[t][u][y] || arpart[t][q][w] == arpart[t][u-1][y] || arpart[t][q][w] == arpart[t][u+1][y])
							{
								if (t == 0) {
									arpart[t][q][w] = dist1(rn);
								}
								else if (t == 1)
								{
									arpart[t][q][w] = dist2(rn);
								}
								else
								{
									arpart[t][q][w] = dist3(rn);
								}
							}
						}
				}
			}
		}
	}
	csvfile.open("아파트 추첨.csv");
	csvfile << "동," << "층," << "호," << "당첨번호," << "\n";
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 20; b++)
		{
			for (int c = 0; c < 4; c++)
			{
				if (a == 0) {
				cout << "1동 "<<b+1 <<"층 "<<c+1<<"호 : "<<arpart[a][b][c]<<" 입니다."<<endl;
				csvfile <<"1동," << b+1 <<"층," << c+1 <<"호 :," << arpart[a][b][c];
				}
				else if (a == 1)
				{
					cout << "2동 " << b + 1 << "층 " << c+1 << "호 : " << arpart[a][b][c] << " 입니다."<<endl;
					csvfile << "2동," << b + 1 << "층," << c + 1 << "호 :," << arpart[a][b][c];
				}
				else
				{
					cout << "3동 " << b + 1 << "층 " << c+1 << "호 : " << arpart[a][b][c] << " 입니다."<<endl;
					csvfile << "3동," << b + 1 << "층," << c + 1 << "호 :," << arpart[a][b][c];
				}
				csvfile << "\n";
			}
		}
	}
	ofstream csvfile;
	double r;
	double a = 1;
	double b = 99;
	double v;
	double x[500];
	double x2[500];
	csvfile.open("지수분포숫자.csv");
	for (int i = 0; i < 100; i++) {
		r = (double)rand() / RAND_MAX;
		csvfile << r << ",";
		x[i] = r * (b - a) + a;
		csvfile << x[i] << "\n";
	}
	cout << "평균값을 입력해주세요 " << endl;
	cin >> v;
	for (int w = 0; w < 500; w++)
	{
		r = (double)rand() / RAND_MAX;
		csvfile  << r<<",";
		x2[w] = -v / 1 * log(1 - r);
		csvfile  << x2[w]<<"\n";
	}
	ofstream csvfile;
	char sirialnumber[36] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };
	string sirialcode[100];
	csvfile.open("시리얼코드.csv");
	double r;
	int x;
	for (int j = 0; j < 100; j++) { 
		for (int i = 0; i < 8; i++) {
			r = (double)rand() / RAND_MAX;
			x = r*(37 - 1) + 1;
			sirialcode[j] += sirialnumber[x-1];
		}
	}
	for (int s = 0; s < 100; s++)
	{
		if (sirialcode[s] == sirialcode[s + 1])
		{
			for (int i = 0; i < 8; i++) {
				r = (double)rand() / RAND_MAX;
				x = r * (37 - 1) + 1;
				sirialcode[s] += sirialnumber[x - 1];
			}
		}
		csvfile  << sirialcode[s] << "\n";
	}*/
    ofstream csvfile;
	double r;
	csvfile.open("엑셀응용.csv");
	for (int i = 0; i < 50; i++)
	{
		r = rand() % (60 - 40 + 1) + 40;
		csvfile << r << "\n";
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
