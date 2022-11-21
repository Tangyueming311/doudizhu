#include"function.h"
#include"player.h"
#include"ai.h"
#include"card.h"
#include"draw.h"
using namespace std;

//地图的长
int MapLength = 190;
//地图的宽
int MapHeight = 55;
char Map[190][55]={0};

//此坐标为箭头坐标
int Key_x = 0;
int Key_y = 0;
//下面这个为手牌最左端箭头的坐标
int X_point = 0;
//下面这个为手牌最右端箭头的坐标
int Y_point = 0;
//下面这个数组为储存选中了哪几个牌的数组
int KeyCard[20] = { 0 };
//下面这个对应着箭头的位置与数组下标
int KeyCard_x = 0;


//打印手牌相关变量
//手牌长与宽
//长用“~”
const int cardLength = 13;
//宽用“|”
const int cardHeight = 9;





//手牌相关变量

//该值为手牌数
int cardNum = 0;
//该数组为手牌数组
int card_hand[20] = {0 };
//该数组为要打出的手牌的序号
extern int Card[21] = { 0 };
//该数组为要打出的手牌
extern int cardchu[20] = { 0 };
//该值为手牌里有多少个0
int cardzero = 0;


int text[20] = { 3,4,5 };


//tempLeft_x为最左端牌的最左边横坐标,tempLeft_y为最左端牌上边线纵坐标
int tempLeft_x;
int tempLeft_y = MapHeight - 10;



//该函数用来读取打出的牌数，并赋值给cardNum,初始化tempLeft_x
//形参a为手牌数,形参b为数组类型，为手牌数组,形参c为手牌有多少0
void getNum(int a,int*b,int c) {
	cardNum = a;
	tempLeft_x = MapLength / 2 - (cardNum / 2) * 4;

	for (int i = 0; i < 20; i++) {
		card_hand[i] = b[i];
	}
	cardzero = c;

}
//打印指定位置
//形参left_x为最左边的横坐标，high_y为最上面的纵坐标，length为长度，height为高度
void Draw(int left_x, int high_y, int length, int height) {
	for (int i = left_x; i <left_x+length; i++) {
		for (int j = high_y; j <= high_y+height; j++) {
			gotoxy(i, j);
			if (Map[i][j] == '0') {
				putchar(' ');
			}
			else if (Map[i][j] == '2')
				putchar('~');
			else if (Map[i][j] == '3')
				putchar('|');

			else if (Map[i][j] == 3) putchar('3');
			else if (Map[i][j] == 4) putchar('4');
			else if (Map[i][j] == 5) putchar('5');
			else if (Map[i][j] == 6) putchar('6');
			else if (Map[i][j] == 7) putchar('7');
			else if (Map[i][j] == 8) putchar('8');
			else if (Map[i][j] == 9) putchar('9');
			else if (Map[i][j] == 10) putchar('T');
			else if (Map[i][j] == 11)putchar('J');
			else if (Map[i][j] == 12) putchar('Q');
			else if (Map[i][j] == 13) putchar('K');
			else if (Map[i][j] == 14) putchar('A');
			else if (Map[i][j] == 15) putchar('2');
			else if (Map[i][j] == 16) putchar('S');
			else if (Map[i][j] == 17) putchar('B');


		}

	}
}

//该函数时创造画布函数，初始画布以及初始手牌，为每一次最开始调用的函数
//形参a是数字牌面数组，,形参cardNum是牌数,形参temp是手牌里有多少个0
void mapCreat(int* a,  int cardNum,int temp1) {
	//先清屏，然后画出三个边的边界
	system("cls");
	int i = 0, j = 0;
	//for (j = 0; j < MapHeight; j++) {
	//	Map[0][j] = '3';
	//}
	//for (j = 0; j < MapLength; j++) {
	//	Map[j][0] = '3';
	//}
	//
	//for (i = 1; i < MapLength - 1; i++) {
	//	for (j = 1; j < MapLength - 1; j++) {
	//		Map[i][j] = '0';
	//	}
	//}	
	//for (j = 0; j < MapHeight; j++) {
	//	Map[MapLength - 1][j] = '3';
	//}



	//Map[length / 2 + (cardNum / 2 + 1) * 4][height - 10];



	//设置箭头坐标
	Key_x = tempLeft_x + 1;
	Key_y = MapHeight - 15;
	X_point = Key_x;
	Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;


	dachu(temp);

	//打印到了第几张牌
	int num = 1;

	int Temp = tempLeft_x;
	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i = 0; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	while (num <= cardNum) {
		//先把牌所占空间清出来，赋0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = tempLeft_y; j <= tempLeft_y + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][tempLeft_y] = '2';
			Map[i][tempLeft_y + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = tempLeft_y; j < tempLeft_y + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][tempLeft_y + 1] = card_hand[cardzero+num - 1];
		}

		num++;
		Temp += 4;
	}

	Draw(0,0,MapLength,MapHeight);
	
	//打印“不出”按钮
	gotoxy(X_point - 23, MapHeight - 9);
	cout << "【不出】";

	//打印“出牌”按钮
	gotoxy(Y_point + 20, MapHeight - 9);
	cout << "【出牌】";

	

	//下面这个对应着箭头的位置与数组下标
	//将其初始化
	KeyCard_x = 0;

	//下面这个数组为储存选中了哪几个牌的数组
	//将其初始化
	for (i = 0; i < 20; i++) {
		KeyCard[i] = 0;
	}

}

//该函数用于把牌选中和取消选中，即上移下移

void put() {
	int i = 0, j = 0, num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;

	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i =X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	while (num <= cardNum) {

		//如果该牌处于被选中的状态，则纵坐标向上移三个单位
		if (KeyCard[num +cardzero- 1] == 0) {
			TempY = tempLeft_y;
		}
		else {
			TempY = tempLeft_y - 3;
		}



		//先把牌所占空间清出来，赋0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = TempY; j <= TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = TempY; j < TempY + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][TempY + 1] = card_hand[cardzero+num - 1];
		}

		num++;
		Temp += 4;
	}


	//在指定位置画图
	Draw(tempLeft_x, tempLeft_y-4, (cardNum - 1) * 4 + 14, cardHeight+4);
	



}

//打印箭头以及其移动
void move() {
	//先把箭头清空
	for (int j = 2; j < MapLength - 1; j++) {
		for (int i = MapHeight - 15; i > MapHeight - 20; i--) {
			gotoxy(j, i);
			putchar(' ');
		}
	}
	//再打印箭头
	gotoxy(Key_x, Key_y);
	putchar('+');
	gotoxy(Key_x, Key_y - 1);
	putchar('|');
	gotoxy(Key_x, Key_y - 2);
	putchar('|');



}

//不出的函数
//形参为手牌数组
void buchu(int* a) {
	int i = 0, j = 0;
	int num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;
	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i = X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	//重新打印一遍手牌
	while (num <= cardNum) {


		//先把牌所占空间清出来，赋0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = TempY; j < TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = TempY; j < TempY + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][TempY + 1] = a[cardzero+num - 1];
		}

		num++;
		Temp += 4;
	}


	Draw(tempLeft_x, tempLeft_y - 4, (cardNum - 1) * 4 + 14, cardHeight+4);
	//Draw(0, 0, MapLength, MapHeight);
}

//选牌箭头的调整
//有返回值，如果没有点击“不出”或“出牌”，则返回0，反之返回1；2是打了不出
//形参a是是否是第一次出牌，1是0不是
int chooseCard(int a) {
	int key;

	int i = 0, j = 0;
	//a,d移动箭头，按回车选中卡牌。卡牌被选中时，对应数组KeyCard【】赋值为1
	key = _getch();

	//坐标表
	//int tempLeft_x = length / 2 - (cardNum / 2 ) * 4;
	//Key_x = tempLeft_x + 1;
	//Key_y = height - 15;
	//X_point = Key_x;
	//Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;

	//分别输入a,d时的执行语句
	//X_point和Y_point 是对应着“不出”和“出牌”两个按钮
	if (key == 100) {
		if (Key_x < Y_point && Key_x != X_point - 20 && Key_x != Y_point + 23) {
			Key_x += 4;

			//KeyCard_x为KeyCard数组的下标
			KeyCard_x++;

		}
		else if (Key_x == X_point - 20) {
			Key_x = X_point;
			KeyCard_x = 0;


		}
		else if (Key_x == Y_point) {
			Key_x = Y_point + 23;
			KeyCard_x++;
		}
		return 0;
	}

	else if (key == 97) {
		if (Key_x > X_point && Key_x != Y_point + 23) {
			Key_x -= 4;

			KeyCard_x--;
		}
		else if (Key_x == X_point) {
			Key_x = X_point - 20;

			KeyCard_x = -1;
		}
		else if (Key_x == Y_point + 23) {
			Key_x = Y_point;
			KeyCard_x--;
		}
		return 0;
	}
	else if (key == 13 && Key_x != Y_point + 23 && Key_x != X_point - 20) {
		if (KeyCard[KeyCard_x + cardzero] == 1) {
			KeyCard[KeyCard_x + cardzero] = 0;
			put();
		}
		else {
			KeyCard[KeyCard_x + cardzero] = 1;
			put();
		}
		return 0;
	}
	else if (key == 13 && Key_x == Y_point + 23&& a==1) {
		//调用出牌函数，把选中的卡牌的数组传输出去
		
		if (chu(card_hand ,1) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == Y_point + 23 && a == 0) {
		//调用出牌函数，把选中的卡牌的数组传输出去

		if (chu(card_hand, 0) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == X_point - 20 &&a == 0) {
		//调用不出牌函数
		gotoxy(MapLength / 2, MapHeight / 2);
		cout << "    ";
		gotoxy(MapLength / 2, MapHeight / 2);
		cout << "不出";
		buchu(card_hand);
		return 2;
	}


}







//形参为打出了的手牌
void dachu(int* a) {
	//先数一遍形参数组有多少个数
	int num = 1;
	int i = 0, j = 0;
	int Num = 0;
	for (i = 0; i < 20; i++) {
		if (a[i] != 0) {
			Num++;
		}
	}

	int Temp = MapLength / 2 - (Num / 2) * 4;
	//在控制台中央打出来
	int TempY = tempLeft_y - 20;





	//先把牌所占空间清出来，赋0
	for (i = X_point - 15; i < X_point + (cardNum - 1) * 4 + 14; i++) {
		for (j = TempY ; j <= TempY + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	while (num <= Num) {


		//先把牌所占空间清出来，赋0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = TempY; j < TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = TempY; j < TempY + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][TempY + 1] = a[num - 1];
		}

		num++;
		Temp += 4;
	}


	Draw(0, 0, MapLength, MapHeight);


}



//形参a为手牌数组,形参b为是否是地主，1是0不是
int chu(int* a,int b) {

	//储存打出的值
	for (int i = 0; i < 20; i++) {
		cardchu[i] = 0;
		Card[i] = 0;
	}
	Card[20] = 0;

	int i = 0, j = 0;
	//遍历KeyCard数组，看看打出了哪几张牌
	for (i = 0; i + cardzero < 20; i++) {
		if (KeyCard[i+cardzero] == 1) {
			//储存要打出的牌的序号
			Card[j] = i + 1;
			//储存要打出的牌
			cardchu[j] = a[i+cardzero];
			j++;
		}

	}
	

	if (b == 1) {


		if (rightFirst(cardchu) != 0) {

			//打出了多少张
			int numchu = j;

			int num = 1;
			int Temp = tempLeft_x;
			int TempY = tempLeft_y;
			//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
			for (i = X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
				for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
					Map[i][j] = '0';
					gotoxy(i, j);
					putchar(' ');
				}
			}


			if (numchu != cardNum) {


				while (num <= cardNum) {


					for (i = 0; i <= 20; i++) {
						if (num == Card[i]) {
							num++;

						}
					}





					//打补丁，防止出最后一张牌时仍打印空牌面
					if (num == 21) {
						break;
					}


					//先把牌所占空间清出来，赋0
					for (i = Temp; i < Temp + cardLength; i++) {
						for (int j = TempY; j < TempY + cardHeight; j++) {
							Map[i][j] = '0';
						}
					}

					//这里是打印牌的上下边界
					for (i = Temp; i < Temp + cardLength; i++) {
						Map[i][TempY] = '2';
						Map[i][TempY + cardHeight] = '2';
					}
					//这里是打印牌的竖线和牌数值

					for (int j = TempY; j < TempY + cardHeight; j++) {
						Map[Temp][j] = '3';
						Map[Temp + cardLength][j] = '3';
						Map[Temp + 1][TempY + 1] = card_hand[cardzero+num - 1];
					}

					num++;
					Temp += 4;
				}
			}
			
			Draw(0, 0, MapLength, MapHeight);

			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (right(cardchu, temp, tempFunction) != 0) {

			//打出了多少张
			int numchu = j;

			int num = 1;
			int Temp = tempLeft_x;
			int TempY = tempLeft_y;
			//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
			for (i = X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
				for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
					Map[i][j] = '0';
					gotoxy(i, j);
					putchar(' ');
				}
			}

			if (numchu != cardNum) {

				while (num <= cardNum) {
					for (i = 0; i <= 20; i++) {
						if (num == Card[i]) {
							num++;

						}
					}

					//打补丁，防止出最后一张牌时仍打印空牌面
					if (num == 21) {
						break;
					}


					//先把牌所占空间清出来，赋0
					for (i = Temp; i < Temp + cardLength; i++) {
						for (int j = TempY; j < TempY + cardHeight; j++) {
							Map[i][j] = '0';
						}
					}

					//这里是打印牌的上下边界
					for (i = Temp; i < Temp + cardLength; i++) {
						Map[i][TempY] = '2';
						Map[i][TempY + cardHeight] = '2';
					}
					//这里是打印牌的竖线和牌数值

					for (int j = TempY; j < TempY + cardHeight; j++) {
						Map[Temp][j] = '3';
						Map[Temp + cardLength][j] = '3';
						Map[Temp + 1][TempY + 1] = card_hand[cardzero+num - 1];
					}

					num++;
					Temp += 4;
				}
			}

			Draw(0, 0, MapLength, MapHeight);

			return 1;
		}
		else {
			return 0;
		}
	}
}






//int main() {
//	HideCursor();
//
//	mapCreat(card, Card, cardNum);
//
//	while (1) {
//		if (chooseCard() == 0) {
//			move();
//		}
//		else {
//			break;
//		}
//	}
//	dachu(text);
//
//}