#include"function.h"
using namespace std;

//隐藏光标的函数
void HideCursor() {

	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

//将光标在控制台里跳到指定坐标
//形参为x坐标和y坐标
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

//菜单函数
void menu() {
	cout << setfill(' ') << setw(35) << "斗地主！！！！" << endl;
	cout << setfill(' ') << setw(35) << "输入“1”以开始游戏!" << endl;
	cout << setfill(' ') << setw(35) << "输入“2”以退出游戏!" << endl;
	int i;
	cin >> i;
}


//判断要打出的牌是否可以打出
// 属于初次出牌
//形参a为数组类型，为要打出的牌
//return值为1或0，可以打出为1，不可以为0
int rightFirst(int* a) {
	int num = 0;
	int i = 0;


	//num为要打出的牌数量
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
			tempFunction = 2;      //暂存值的牌的类型为对牌	
			return 1;
		}
		else return 0;
	}

	else if (num == 3) {
		if (a[0] == a[1] && a[1] == a[2]) {
			tempFunction = 3;         //暂存值的牌的类型为三牌	
			return 1;
		}
		else return 0;
	}

}






//判断要打出的牌是否可以打出
// 属于跟随出牌
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌；形参c为int类型，为牌的类型
//return值为1或0，可以打出为1，不可以为0
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
	
//如果要打出牌的数量与暂存牌数量不同，明显不能打
	if (num != num2) {                
		return 0;
	}


//分别判断各种情况
	else if (num == num2) {

		if (num == 1) {
			if (singleCard(a, b) == 1)
			{
				cout << "单牌" << endl;
				tempFunction = 1;           
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

//单牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1，为是否能打出
int singleCard(int* a, int* b) {
	if (a[0] > b[0]) {
		return 1;

	}
	else {

		return 0;

	}
}
//双牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1，为是否能打出
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
//三牌判断
//形参a为数组类型，为要打出的牌；形参b为数组类型，为暂存的牌
//return值为0或1，为是否能打出
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

