//first of all ,you should know this is a dou di zhu.
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>
using namespace std;
void HideCursor();
void gotoxy(unsigned char x, unsigned char y);
void menu();
int right(int* a, int* b, int c);
int rightFirst(int* a);
int singleCard(int* a, int* b);
int doubleCard(int* a, int* b);
int threeCard(int* a, int* b);
int temp[20] = { 0 };
int tempFunction = 0;

class player {
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //是否为地主，是为1，否为0

public:
	void order();
	int getLL() { return ifLandlord; }
	void setCard(int* a);
	int* getHand() { return handCard; }
	void setLL(int a) { ifLandlord = a; }

	void setLLcard(int* a);
	void chuCard();
	void chuCardFirst();

};

class ai
{
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //是否为地主，是为1，否为0

public:
	void order();
	int getLL() { return ifLandlord; }
	void setCard(int* a);
	int* getHand() { return handCard; }
	void setLL(int a) { ifLandlord = a; }

	void setLLcard(int* a);
	void chuCard();

};




class card {
private:
	int player[17];
	int player1[17];
	int player2[17];
	int landlord[3];
	int p[54];

public:
	card();                                     //对牌进行赋值
	void washCard();
	void dealcard();
	void order();
	int getCard_a(int a) { return p[a]; }
	int* getCard() { return p; }
	int* getP() { return player; }
	int* getP1() { return player1; }
	int* getP2() { return player2; }
	int* getL() { return landlord; }

};






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

card::card() {
	int p1[54] = { 3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,15,15,15,15,16,17 };
	for (int i = 0; i < 54; i++) {
		p[i] = p1[i];
	}
}

void card::washCard() {
	int temp1_x;
	int temp1_y;
	int temp2_x;
	int temp2_y;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 1000; i++) {
		temp1_x = p[temp1_y = rand() % 54];
		temp2_x = p[temp2_y = rand() % 54];
		p[temp1_y] = temp2_x;
		p[temp2_y] = temp1_x;
	}

}
void card::dealcard() {

	//int player[20];
	//int player1[20];
	//int player2[20];
	//int landlord[3];
	for (int i = 0; i <= 16; i++)
	{
		player[i] = p[i];
	}
	for (int i = 17; i <= 33; i++)
	{
		player1[i - 17] = p[i];
	}
	for (int i = 34; i <= 50; i++)
	{
		player2[i - 34] = p[i];
	}
	for (int i = 51; i <= 53; i++)
	{
		landlord[i - 51] = p[i];
	}
}



void player::order() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				temp = i;
			}
		}
		swap(handCard[j], handCard[temp]);
	}
}
void player::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}


void player::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}
void player::chuCardFirst() {
	int x[20] = { 0 };    //要打出的牌

	int j = 0;

	int i = 0;
	int Temp = 0;

	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);


		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  //handCard数组里下标为Temp的元素开始不为0
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
		}
	} while (rightFirst(x) == 0);

	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];
	}

	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;
	}
	order();




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
		if (x[0] == x[1]) {
			tempFunction = 2;
			return 1;
		}
		else return 0;
	}

	else if (num == 3) {
		if (x[0] == x[1] && x[1] == x[2]) {
			tempFunction = 3;
			return 1;
		}
		else return 0;
	}

}















void player::chuCard() {
	int x[20] = { 0 };    //要打出的牌的序号
	int y[20] = { 0 };    //要打出的牌
	int j = 0;
	int i = 0;
	int Temp = 0;


	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);


		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  //handCard数组里下标为Temp的元素开始不为0
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
		}


	} while (right(y, temp, tempFunction) == 0);


	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];                                        //改变暂存值
	}
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;                            //将打出了牌后的手牌赋值为0
	}
	order();                                                   //重新排序
	cout << "出了" << y[0] << endl;

}



void ai::order() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				temp = i;
			}
		}
		swap(handCard[j], handCard[temp]);
	}
}
void ai::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}


void ai::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}

void ai::chuCard() {


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





int main() {
	menu();

	card a;
	a.washCard();

	a.dealcard();


	player b;
	b.setCard(a.getP());


	player b1;
	b1.setCard(a.getP1());


	player b2;
	b2.setCard(a.getP2());



	b.order();
	b1.order();
	b2.order();



	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}	 //cout << endl;
	//for(int i=0;i<20;i++){
	   //cout<< b1.getHand()[i]<<" ";
	   //
	//}
	//cout << endl;
 //   for(int i=0;i<20;i++){
	   //cout<< b2.getHand()[i]<<" ";
	   //
	//}


	cout << endl;

	cout << "你要叫地主吗？" << endl;
	cout << "输入1叫地主，不然则输入0." << endl;
	int y;
	cin >> y;
	if (y == 1) {
		b.setLL(1);
		b.setLLcard(a.getL());
		cout << "现在你是地主." << endl;
	}
	else {
		b1.setLL(1);
		b1.setLLcard(a.getL());
		srand((unsigned)time(NULL));
		int x = rand() % 2 + 1;
		cout << "地主是AI" << x << "号" << endl;
	}








	cout << endl;
	b.order();
	b1.order();
	cout << "底牌为：";
	cout << a.getL()[0] << " " << a.getL()[1] << " " << a.getL()[2] << " " << endl;

	cout << "您的手牌为：";
	for (int i = 0; i < 20; i++)
	{
		cout << b.getHand()[i] << " ";
	}




	cout << "请输入你要打出的手牌." << endl;









	temp[0] = 6;

	//此为第一个回合
	if (b.getLL() == 1) {
		b.chuCardFirst();
		//b1.chuCard();
		//b2.chuCard();
	}



	//以下是第2个以及以后的回合
	while (1) {
		if (b.getLL() == 1) {
			b.chuCard();   //仅指出牌  judge()和right()    //判断是否符合规则,以及能否打出  //以及是否打完
			//b1.chuCard();
			//b2.chuCard();
		}
		else if (b1.getLL() == 1) {
			//b1.chuCard();
			b.chuCard();   //仅指出牌  judge()和right()    //判断是否符合规则,以及能否打出
			//b2.chuCard();
		}


	}


}


