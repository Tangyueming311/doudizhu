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

//ai牌坐标













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



//tempLeft_x为最左端牌的最左边横坐标,tempLeft_y为最左端牌上边线纵坐标
int tempLeft_x;
int tempLeft_y = MapHeight - 10;




//菜单函数
void menu() {
	system("cls");

	gotoxy(MapLength / 2 - 3, MapHeight / 2 - 6);
	cout << "斗地主！！！！";
	gotoxy(MapLength / 2 - 3, MapHeight / 2+6);
	cout << "【开始游戏】";
	gotoxy(MapLength / 2 - 3, MapHeight / 2 + 10);
	cout << "【调整字体】";
	gotoxy(MapLength / 2 - 3, MapHeight / 2+14);
	cout << "【退出游戏】";
	
 //  //char map_title[100][100]={'0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','4','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','4','4','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','4','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','4','4','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '4','4','4','4','4','4','4','4','4','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	//						 '0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',

	//};








	int key;
	//int temp_game = -1;
	int key_point = 0;
	int key_point_y = MapHeight / 2 + 6;
	int temp_size = 16;
	

	gotoxy(MapLength / 2 - 5, MapHeight / 2 + 6);
	putchar('+');
	gotoxy(MapLength / 2 - 14, MapHeight / 2 + 6);
	cout << "————";


	while (1) {
		//a,d移动箭头，按回车选中
		key = _getch();

		
			//先把箭头清空
			for (int j = MapLength / 2 - 14; j < MapLength / 2 - 3; j++) {
				for (int i = 10; i < MapHeight - 11; i++) {
					gotoxy(j, i);
					putchar(' ');
				}
			}
			for (int j = MapLength / 2 + 9; j < MapLength / 2 + 20; j++) {
				for (int i = 10; i < MapHeight - 11; i++) {
					gotoxy(j, i);
					putchar(' ');
				}
			}
		
		

		//向上
		if (key == 119) {
		
			if (key_point ==1) {
				//再打印箭头
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 6);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 6);
				cout << "————";
			//	temp_game = 1;
				key_point--;
				continue;
			}
			else if (key_point == 2) {
				gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
				cout << "《《";
				gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
				cout << "》》";
				key_point--;
				continue;
			}
			else if (key_point == 0) {
				//再打印箭头
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 6);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 6);
				cout << "————";
				
				continue;
			}
		}
		//向下
		else if (key == 115) {
	
			if (key_point ==1) {
				//再打印箭头
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 14);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 14);
				cout << "————";
				//	temp_game = 0;
				key_point++;
				continue;
			}
			else if (key_point == 0) {
				gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
				cout << "《《";
				gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
				cout << "》》";
				key_point++;
				continue;
			}
			else if (key_point == 2) {
				//再打印箭头
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 14);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 14);
				cout << "————";
				continue;
			}
		}
		//向右
		else if (key == 100&&key_point==1) {
			
			gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
			cout << "《《";
			gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
			cout << "》》";
			
			temp_size++;
			SetFont(temp_size);
		
			continue;
		}
		else if (key == 97 && key_point == 1) {
			gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
			cout << "《《";
			gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
			cout << "》》";

			temp_size--;
			SetFont(temp_size);
	
			continue;

		}
		else if (key == 13 && key_point == 0) {
			break;
		}
		
		else if (key == 13 &&key_point==2) {
			system("cls");
			exit(100);
		}

	}





	
}






int Choose_Landlord(int* handcard) {
	system("cls");

	int i = 0, j = 0;

	//记录手牌有多少张
	int cardnum = 0;

	//记录手牌前有多少个0
	int cardzero = 0;
	for (int k = 0; k < 20; k++) {
		if (handcard[k] != 0) {
			cardnum++;
		}
		else {
			cardzero++;
		}
	}

	//Map[length / 2 + (cardNum / 2 + 1) * 4][height - 10];

	tempLeft_x = MapLength / 2 - (cardnum / 2) * 4;

	for (int i = 0; i < 20; i++) {
		card_hand[i] = handcard[i];
	}
	


	//打印到了第几张牌
	int num = 1;

	int Temp = tempLeft_x;
	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i = 40; i < MapLength - 40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';


		}
	}

	while (num <= cardnum) {
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
			Map[Temp + 1][tempLeft_y + 1] = card_hand[cardzero + num - 1];
		}

		num++;
		Temp += 4;
	}

	Draw(20, tempLeft_y - 4, MapLength - 40, cardHeight + 4);




	int key;
	int temp_landlord = -1;

	gotoxy(MapLength / 2 - 18, MapHeight / 2);
	cout << "【抢地主】";
	gotoxy(MapLength / 2 + 8, MapHeight / 2);
	cout << "【不抢】";


	while (1) {
		//a,d移动箭头，按回车选中
		key = _getch();

		//先把箭头清空
		for (int j= MapLength / 2 - 18; j < MapLength - 30; j++) {
			for (int i = MapHeight/2+1; i < MapHeight/2+5 ; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}

		if (key == 97) {
			//再打印箭头
			gotoxy(MapLength / 2 - 14, MapHeight / 2 + 2);
			putchar('+');
			gotoxy(MapLength / 2 - 14, MapHeight / 2 + 3);
			putchar('|');
			gotoxy(MapLength / 2 - 14, MapHeight / 2 + 4);
			putchar('|');
			temp_landlord = 1;
			continue;
		}
		else if (key == 100) {
			//再打印箭头
			gotoxy(MapLength / 2 + 12, MapHeight / 2 + 2);
			putchar('+');
			gotoxy(MapLength / 2 + 12, MapHeight / 2 + 3);
			putchar('|');
			gotoxy(MapLength / 2 + 12, MapHeight / 2 + 4);
			putchar('|');
			temp_landlord = 0;
			continue;
		}
		else if (key == 13 && temp_landlord == 1) {
			return 1;
		}
		else if (key == 13 && temp_landlord == 0) {
			return 0;
		}

	}
}




//创造最初始的地图
void Map_Creat() {
	int i = 0, j = 0;
	system("cls");
	for (j = 0; j < MapHeight; j++) {
	    Map[0][j] = '3';
    }
    for (j = 0; j < MapLength; j++) {
	    Map[j][0] = '3';
    }

    for (i = 1; i < MapLength - 1; i++) {
	     for (j = 1; j < MapLength - 1; j++) {
		 Map[i][j] = '0';
	     }
    }	
    for (j = 0; j < MapHeight; j++) {
	     Map[MapLength - 1][j] = '3';
    }
	Draw(0, 0, MapLength, MapHeight);
}

//打印最顶上展示的地主牌
void Landlord_Card_Creat(int* card) {
	int num = 1;

	int temp_x= MapLength / 2 - (3 ) * 4;
	int temp_y = 5;
	while (num <= 3) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			for (int j = temp_y; j <= temp_y + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			Map[i][temp_y] = '2';
			Map[i][temp_y + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = temp_y; j < temp_y + cardHeight; j++) {
			Map[temp_x][j] = '3';
			Map[temp_x + cardLength][j] = '3';
			Map[temp_x + 1][temp_y + 1] = card[ num - 1];
		}

		num++;
		temp_x += 4;
	}

	Draw(MapLength / 2 - (3 ) * 4, temp_y, (3- 1) * 4 + 14, cardHeight + 4);

}

void Ai_Card_Creat(int left_card_num, int right_card_num,int if_player_is_landlord) {
	int num_left = 1;
	int num_right = 1;

	int temp_card_length = 20;
	int temp_card_height = 6;


	int temp_left_x = 5;
	int temp_left_y = 8;

	int temp_right_x = MapLength - 5 - temp_card_length;
	int temp_right_y = 8;
	
	//for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
	//	for (int j = 1; j < MapHeight; j++) {
	//		Map[i][j] = '0';
	//	}
	//}


	//左边
	while (num_left <= left_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			Map[temp_left_x-1][i] = '3';
			Map[temp_left_x + temp_card_length][i] = '3';
		}
	
		//这里是打印牌的上下边界

		for (int j = temp_left_x; j < temp_left_x + temp_card_length; j++) {
			Map[j][temp_left_y] = '2';
			Map[j][temp_left_y+temp_card_height] = '2';
			
		}

		num_left++;
		temp_left_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;
	
	Draw(4, 8, temp_card_length+2, (left_card_num - 1) * 2 + 6);
	gotoxy(13, temp_left_y +1);
	cout << left_card_num<<"张";
	
	if (if_player_is_landlord == 0) {
		gotoxy(13, temp_left_y + 6);
		cout << "【地主】";
	}

	

	//右边
	while (num_right <= left_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			Map[temp_right_x - 1][i] = '3';
			Map[temp_right_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_right_x; j < temp_right_x + temp_card_length; j++) {
			Map[j][temp_right_y] = '2';
			Map[j][temp_right_y + temp_card_height] = '2';

		}

		num_right++;
		temp_right_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	Draw(temp_right_x-1, 8, temp_card_length + 2, (left_card_num - 1) * 2 + 6);
	gotoxy(MapLength- 13, temp_right_y + 1);
	cout << right_card_num << "张";








}



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
			else if (Map[i][j] == '4')
				putchar('$');
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
void Player_Card_Creat(int* a,  int cardNum,int temp1,int if_player_is_landlord) {
	
	
	int i = 0, j = 0;


	//Map[length / 2 + (cardNum / 2 + 1) * 4][height - 10];



	//设置箭头坐标
	//以下变量随牌数变化
	Key_x = tempLeft_x + 1;
	Key_y = MapHeight - 15;
	X_point = Key_x;
	Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;


	dachu(temp);

	//打印到了第几张牌
	int num = 1;

	int Temp = tempLeft_x;
	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i = 40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			
			
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

	Draw(20, tempLeft_y-4, MapLength-40, cardHeight+4);
	
	//打印“不出”按钮
	gotoxy(X_point - 23, MapHeight - 9);
	cout << "【不出】";

	//打印“出牌”按钮
	gotoxy(Y_point + 20, MapHeight - 9);
	cout << "【出牌】";

	if (if_player_is_landlord == 1) {
		gotoxy(Y_point + 20, MapHeight - 6);
		cout << "【地主】";
	}

	

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
	for (i =40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			
			
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
	for (int j = 30; j < MapLength - 30; j++) {
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
void buchu(int* a,int if_player_is_landlord) {
	int i = 0, j = 0;
	int num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;
	//先把牌所占空间,以及已经选中的突出的牌的空间清出来，赋0
	for (i = 40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			;
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
	if (if_player_is_landlord == 1) {
		gotoxy(Y_point + 20, MapHeight - 6);
		cout << "【地主】";
	}
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
		
		if (chu(card_hand ,1, K_if_player_is_landlord) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == Y_point + 23 && a == 0) {
		//调用出牌函数，把选中的卡牌的数组传输出去

		if (chu(card_hand, 0, K_if_player_is_landlord) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == X_point - 20 &&a == 0) {
		//调用不出牌函数
		gotoxy(MapLength / 2, MapHeight -17);
		cout << "    ";
		gotoxy(MapLength / 2, MapHeight -17);
		cout << "不出";
		buchu(card_hand, K_if_player_is_landlord);
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

	int TempX = MapLength / 2 - (Num / 2) * 4;
	//在控制台中央打出来
	int TempY = tempLeft_y - 20;





	//先把牌所占空间清出来，赋0
	for (i =40; i < MapLength-40; i++) {
		for (j = TempY ; j <= TempY + cardHeight; j++) {
			Map[i][j] = '0';
			
		}
	}

	while (num <= Num) {


		//先把牌所占空间清出来，赋0
		for (i = TempX; i < TempX + cardLength; i++) {
			for (int j = TempY; j < TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的上下边界
		for (i = TempX; i < TempX + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//这里是打印牌的竖线和牌数值

		for (int j = TempY; j < TempY + cardHeight; j++) {
			Map[TempX][j] = '3';
			Map[TempX + cardLength][j] = '3';
			Map[TempX + 1][TempY + 1] = a[num - 1];
		}

		num++;
		TempX += 4;
	}


	Draw(15, tempLeft_y - 20 , MapLength - 15, cardHeight + 4);


}



//形参a为手牌数组,形参b为是否是地主第一次出牌，1是0不是
int chu(int* a,int b, int if_player_is_landlord) {

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
			for (i = 40; i < MapLength-40; i++) {
				for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
					Map[i][j] = '0';
					
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
			
			Draw(tempLeft_x, tempLeft_y - 4, (cardNum - 1) * 4 + 14, cardHeight + 4);
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "【地主】";
			}
			return 1;
		}
		else {
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "【地主】";
			}
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
			for (i = 40; i < MapLength - 40; i++) {
				for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
					Map[i][j] = '0';
					
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

			Draw(tempLeft_x, tempLeft_y - 4, (cardNum - 1) * 4 + 14, cardHeight + 4);
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "【地主】";
			}
			return 1;
		}
		else {
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "【地主】";
			}
			return 0;
		}
	}
}




//打出牌的数组，和手牌数量
void Ai_Left_Chu(int *ai_card_chu,int ai_card_num) {
	dachu(ai_card_chu);

	int ai_card_chu_num = 0;
	for (int i = 0; i < 20; i++) {
		if (ai_card_chu[i] != 0) {
			ai_card_chu_num++;
		}
	}

	ai_card_num -= ai_card_chu_num;

	int num_left = 1;


	int temp_card_length = 20;
	int temp_card_height = 6;


	int temp_left_x = 5;
	int temp_left_y = 8;


	for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
		for (int j = 1; j < MapHeight; j++) {
			Map[i][j] = '0';
		}
	}


	//左边
	while (num_left <= ai_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			Map[temp_left_x - 1][i] = '3';
			Map[temp_left_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_left_x; j < temp_left_x + temp_card_length; j++) {
			Map[j][temp_left_y] = '2';
			Map[j][temp_left_y + temp_card_height] = '2';

		}

		num_left++;
		temp_left_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	Draw(4, 8, temp_card_length + 2, (ai_card_num - 1) * 2 + 6);
	gotoxy(13, temp_left_y + 1);
	cout << ai_card_num << "张";
}


void Ai_Right_Chu(int* ai_card_chu, int ai_card_num) {
	dachu(ai_card_chu);

	int ai_card_chu_num = 0;
	for (int i = 0; i < 20; i++) {
		if (ai_card_chu[i] != 0) {
			ai_card_chu_num++;
		}
	}

	ai_card_num -= ai_card_chu_num;


	int num_right = 1;

	int temp_card_length = 20;
	int temp_card_height = 6;




	int temp_right_x = MapLength - 5 - temp_card_length;
	int temp_right_y = 8;

	for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
		for (int j = 1; j < MapHeight; j++) {
			Map[i][j] = '0';
		}
	}

	//右边
	while (num_right <= ai_card_num) {
		//先把牌所占空间清出来，赋0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//这里是打印牌的竖线
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			Map[temp_right_x - 1][i] = '3';
			Map[temp_right_x + temp_card_length][i] = '3';
		}

		//这里是打印牌的上下边界

		for (int j = temp_right_x; j < temp_right_x + temp_card_length; j++) {
			Map[j][temp_right_y] = '2';
			Map[j][temp_right_y + temp_card_height] = '2';

		}

		num_right++;
		temp_right_y += 2;
	}

	//Map[temp_left_x + 10][temp_left_y + 2] = left_card_num;

	Draw(temp_right_x - 1, 8, temp_card_length + 2, (ai_card_num - 1) * 2 + 6);
	gotoxy(MapLength - 13, temp_right_y + 1);
	cout << ai_card_num << "张";






}

void Ai_Left_Buchu() {
	gotoxy(27, MapHeight/2);
	cout << "    ";
	gotoxy(27, MapHeight/2);
	cout << "不出";
}


void Ai_Right_Buchu() {
	gotoxy(MapLength- 27, MapHeight / 2);
	cout << "    ";
	gotoxy(MapLength - 27, MapHeight / 2);
	cout << "不出";
}