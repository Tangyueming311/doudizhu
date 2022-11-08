#include"function.h"
using namespace std;

void HideCursor() {

	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

void gotoxy(unsigned char x, unsigned char y) {
	//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标
	COORD cor;

	//句柄 
	HANDLE hout;

	//设定我们要定位到的坐标 
	cor.X = x;
	cor.Y = y;

	//GetStdHandle函数获取一个指向特定标准设备的句柄，包括标准输入，标准输出和标准错误。
	//STD_OUTPUT_HANDLE正是代表标准输出（也就是显示屏）的宏 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleCursorPosition函数用于设置控制台光标的位置
	SetConsoleCursorPosition(hout, cor);
}

void menu() {
	cout << setfill(' ') << setw(35) << "斗地主！！！！" << endl;
	cout << setfill(' ') << setw(35) << "输入“1”以开始游戏!" << endl;
	cout << setfill(' ') << setw(35) << "输入“2”以退出游戏!" << endl;
	int i;
	cin >> i;
}



int rightFirst(int* a) {
	int num = 0;
	int i = 0;

	while (a[i] != 0)
	{
		num++;
		i++;
	}

	if (num == 1) {
		tempFunction = 1;           //暂存值的牌的类型为单牌	
		return 1;
	}
	else if (num == 2) {
		if (a[0] == a[1]) {
			tempFunction = 2;
			return 1;
		}
		else return 0;
	}

	else if (num == 3) {
		if (a[0] == a[1] && a[1] == a[2]) {
			tempFunction = 3;
			return 1;
		}
		else return 0;
	}

}















int right(int* a, int* b, int c)
{
	int num = 0;
	int i = 0;
	int num2 = 0;
	int j = 0;
	while (a[i] != 0)
	{
		num++;
		i++;
	}
	while (b[i] != 0)
	{
		num2++;
		j++;
	}

	if (num != num2) {                 //如果输入牌的数量
		return 0;
	}

	else if (num == num2) {

		if (num == 1) {
			if (singleCard(a, b) == 1)
			{
				cout << "单牌" << endl;
				tempFunction = 1;           //暂存值的牌的类型为单牌
				return 1;
			}
			else {

				cout << "小了" << endl;
				return 0;
			}
		}

		else if (num == 2) {
			if (doubleCard(a, b) == 1)
			{
				cout << "对牌" << endl;
				tempFunction = 2;
				return 1;
			}
			else if (doubleCard(a, b) == 0) {

				cout << "小了" << endl;
				return 0;
			}
			else if (doubleCard(a, b) == 2) {
				cout << "不符合规范" << endl;
				return 0;
			}
		}

		else if (num == 3) {
			if (threeCard(a, b) == 1)
			{
				cout << "三牌" << endl;
				tempFunction = 3;
				return 1;
			}
			else if (threeCard(a, b) == 0) {

				cout << "小了" << endl;
				return 0;
			}
			else if (threeCard(a, b) == 2) {
				cout << "不符合规范" << endl;
				return 0;
			}
		}
	}



}


int singleCard(int* a, int* b) {
	if (a[0] > b[0]) {
		return 1;

	}
	else {

		return 0;

	}
}

int doubleCard(int* a, int* b) {
	if (a[0] == a[1] && tempFunction == 2) {

		if (a[0] > b[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;        //不符合规范的出牌返回2值
	}
}

int threeCard(int* a, int* b) {
	if (a[0] == a[1] && a[1] == a[2] && tempFunction == 3) {

		if (a[0] > b[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 2;        //不符合规范的出牌返回2值
	}
}

