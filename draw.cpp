#include"function.h"
#include"player.h"
#include"ai.h"
#include"card.h"
#include"draw.h"
using namespace std;

//��ͼ�ĳ�
int MapLength = 190;
//��ͼ�Ŀ�
int MapHeight = 55;
char Map[190][55]={0};

//ai������













//������Ϊ��ͷ����
int Key_x = 0;
int Key_y = 0;
//�������Ϊ��������˼�ͷ������
int X_point = 0;
//�������Ϊ�������Ҷ˼�ͷ������
int Y_point = 0;
//�����������Ϊ����ѡ�����ļ����Ƶ�����
int KeyCard[20] = { 0 };
//���������Ӧ�ż�ͷ��λ���������±�
int KeyCard_x = 0;


//��ӡ������ر���
//���Ƴ����
//���á�~��
const int cardLength = 13;
//���á�|��
const int cardHeight = 9;





//������ر���

//��ֵΪ������
int cardNum = 0;
//������Ϊ��������
int card_hand[20] = {0 };
//������ΪҪ��������Ƶ����
extern int Card[21] = { 0 };
//������ΪҪ���������
extern int cardchu[20] = { 0 };
//��ֵΪ�������ж��ٸ�0
int cardzero = 0;



//tempLeft_xΪ������Ƶ�����ߺ�����,tempLeft_yΪ��������ϱ���������
int tempLeft_x;
int tempLeft_y = MapHeight - 10;




//�˵�����
void menu() {
	system("cls");

	gotoxy(MapLength / 2 - 3, MapHeight / 2 - 6);
	cout << "��������������";
	gotoxy(MapLength / 2 - 3, MapHeight / 2+6);
	cout << "����ʼ��Ϸ��";
	gotoxy(MapLength / 2 - 3, MapHeight / 2 + 10);
	cout << "���������塿";
	gotoxy(MapLength / 2 - 3, MapHeight / 2+14);
	cout << "���˳���Ϸ��";
	
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
	cout << "��������";


	while (1) {
		//a,d�ƶ���ͷ�����س�ѡ��
		key = _getch();

		
			//�ȰѼ�ͷ���
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
		
		

		//����
		if (key == 119) {
		
			if (key_point ==1) {
				//�ٴ�ӡ��ͷ
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 6);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 6);
				cout << "��������";
			//	temp_game = 1;
				key_point--;
				continue;
			}
			else if (key_point == 2) {
				gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
				cout << "����";
				gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
				cout << "����";
				key_point--;
				continue;
			}
			else if (key_point == 0) {
				//�ٴ�ӡ��ͷ
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 6);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 6);
				cout << "��������";
				
				continue;
			}
		}
		//����
		else if (key == 115) {
	
			if (key_point ==1) {
				//�ٴ�ӡ��ͷ
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 14);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 14);
				cout << "��������";
				//	temp_game = 0;
				key_point++;
				continue;
			}
			else if (key_point == 0) {
				gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
				cout << "����";
				gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
				cout << "����";
				key_point++;
				continue;
			}
			else if (key_point == 2) {
				//�ٴ�ӡ��ͷ
				gotoxy(MapLength / 2 - 5, MapHeight / 2 + 14);
				putchar('+');
				gotoxy(MapLength / 2 - 14, MapHeight / 2 + 14);
				cout << "��������";
				continue;
			}
		}
		//����
		else if (key == 100&&key_point==1) {
			
			gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
			cout << "����";
			gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
			cout << "����";
			
			temp_size++;
			SetFont(temp_size);
		
			continue;
		}
		else if (key == 97 && key_point == 1) {
			gotoxy(MapLength / 2 - 8, MapHeight / 2 + 10);
			cout << "����";
			gotoxy(MapLength / 2 + 9, MapHeight / 2 + 10);
			cout << "����";

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

	//��¼�����ж�����
	int cardnum = 0;

	//��¼����ǰ�ж��ٸ�0
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
	


	//��ӡ���˵ڼ�����
	int num = 1;

	int Temp = tempLeft_x;
	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i = 40; i < MapLength - 40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';


		}
	}

	while (num <= cardnum) {
		//�Ȱ�����ռ�ռ����������0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = tempLeft_y; j <= tempLeft_y + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][tempLeft_y] = '2';
			Map[i][tempLeft_y + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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
	cout << "����������";
	gotoxy(MapLength / 2 + 8, MapHeight / 2);
	cout << "��������";


	while (1) {
		//a,d�ƶ���ͷ�����س�ѡ��
		key = _getch();

		//�ȰѼ�ͷ���
		for (int j= MapLength / 2 - 18; j < MapLength - 30; j++) {
			for (int i = MapHeight/2+1; i < MapHeight/2+5 ; i++) {
				gotoxy(j, i);
				putchar(' ');
			}
		}

		if (key == 97) {
			//�ٴ�ӡ��ͷ
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
			//�ٴ�ӡ��ͷ
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




//�������ʼ�ĵ�ͼ
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

//��ӡ���չʾ�ĵ�����
void Landlord_Card_Creat(int* card) {
	int num = 1;

	int temp_x= MapLength / 2 - (3 ) * 4;
	int temp_y = 5;
	while (num <= 3) {
		//�Ȱ�����ռ�ռ����������0
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			for (int j = temp_y; j <= temp_y + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (int i = temp_x; i < temp_x + cardLength; i++) {
			Map[i][temp_y] = '2';
			Map[i][temp_y + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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


	//���
	while (num_left <= left_card_num) {
		//�Ȱ�����ռ�ռ����������0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ�����
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			Map[temp_left_x-1][i] = '3';
			Map[temp_left_x + temp_card_length][i] = '3';
		}
	
		//�����Ǵ�ӡ�Ƶ����±߽�

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
	cout << left_card_num<<"��";
	
	if (if_player_is_landlord == 0) {
		gotoxy(13, temp_left_y + 6);
		cout << "��������";
	}

	

	//�ұ�
	while (num_right <= left_card_num) {
		//�Ȱ�����ռ�ռ����������0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ�����
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			Map[temp_right_x - 1][i] = '3';
			Map[temp_right_x + temp_card_length][i] = '3';
		}

		//�����Ǵ�ӡ�Ƶ����±߽�

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
	cout << right_card_num << "��";








}



//�ú���������ȡ���������������ֵ��cardNum,��ʼ��tempLeft_x
//�β�aΪ������,�β�bΪ�������ͣ�Ϊ��������,�β�cΪ�����ж���0
void getNum(int a,int*b,int c) {
	cardNum = a;
	tempLeft_x = MapLength / 2 - (cardNum / 2) * 4;

	for (int i = 0; i < 20; i++) {
		card_hand[i] = b[i];
	}
	cardzero = c;

}
//��ӡָ��λ��
//�β�left_xΪ����ߵĺ����꣬high_yΪ������������꣬lengthΪ���ȣ�heightΪ�߶�
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

//�ú���ʱ���컭����������ʼ�����Լ���ʼ���ƣ�Ϊÿһ���ʼ���õĺ���
//�β�a�������������飬,�β�cardNum������,�β�temp���������ж��ٸ�0
void Player_Card_Creat(int* a,  int cardNum,int temp1,int if_player_is_landlord) {
	
	
	int i = 0, j = 0;


	//Map[length / 2 + (cardNum / 2 + 1) * 4][height - 10];



	//���ü�ͷ����
	//���±����������仯
	Key_x = tempLeft_x + 1;
	Key_y = MapHeight - 15;
	X_point = Key_x;
	Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;


	dachu(temp);

	//��ӡ���˵ڼ�����
	int num = 1;

	int Temp = tempLeft_x;
	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i = 40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			
			
		}
	}

	while (num <= cardNum) {
		//�Ȱ�����ռ�ռ����������0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = tempLeft_y; j <= tempLeft_y + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][tempLeft_y] = '2';
			Map[i][tempLeft_y + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

		for (int j = tempLeft_y; j < tempLeft_y + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][tempLeft_y + 1] = card_hand[cardzero+num - 1];
		}

		num++;
		Temp += 4;
	}

	Draw(20, tempLeft_y-4, MapLength-40, cardHeight+4);
	
	//��ӡ����������ť
	gotoxy(X_point - 23, MapHeight - 9);
	cout << "��������";

	//��ӡ�����ơ���ť
	gotoxy(Y_point + 20, MapHeight - 9);
	cout << "�����ơ�";

	if (if_player_is_landlord == 1) {
		gotoxy(Y_point + 20, MapHeight - 6);
		cout << "��������";
	}

	

	//���������Ӧ�ż�ͷ��λ���������±�
	//�����ʼ��
	KeyCard_x = 0;

	//�����������Ϊ����ѡ�����ļ����Ƶ�����
	//�����ʼ��
	for (i = 0; i < 20; i++) {
		KeyCard[i] = 0;
	}

}

//�ú������ڰ���ѡ�к�ȡ��ѡ�У�����������

void put() {
	int i = 0, j = 0, num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;

	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i =40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			
			
		}
	}

	while (num <= cardNum) {

		//������ƴ��ڱ�ѡ�е�״̬����������������������λ
		if (KeyCard[num +cardzero- 1] == 0) {
			TempY = tempLeft_y;
		}
		else {
			TempY = tempLeft_y - 3;
		}



		//�Ȱ�����ռ�ռ����������0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = TempY; j <= TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

		for (int j = TempY; j < TempY + cardHeight; j++) {
			Map[Temp][j] = '3';
			Map[Temp + cardLength][j] = '3';
			Map[Temp + 1][TempY + 1] = card_hand[cardzero+num - 1];
		}

		num++;
		Temp += 4;
	}


	//��ָ��λ�û�ͼ
	Draw(tempLeft_x, tempLeft_y-4, (cardNum - 1) * 4 + 14, cardHeight+4);
	



}

//��ӡ��ͷ�Լ����ƶ�
void move() {
	//�ȰѼ�ͷ���
	for (int j = 30; j < MapLength - 30; j++) {
		for (int i = MapHeight - 15; i > MapHeight - 20; i--) {
			gotoxy(j, i);
			putchar(' ');
		}
	}
	//�ٴ�ӡ��ͷ
	gotoxy(Key_x, Key_y);
	putchar('+');
	gotoxy(Key_x, Key_y - 1);
	putchar('|');
	gotoxy(Key_x, Key_y - 2);
	putchar('|');



}

//�����ĺ���
//�β�Ϊ��������
void buchu(int* a,int if_player_is_landlord) {
	int i = 0, j = 0;
	int num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;
	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i = 40; i < MapLength-40; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			;
		}
	}

	//���´�ӡһ������
	while (num <= cardNum) {


		//�Ȱ�����ռ�ռ����������0
		for (i = Temp; i < Temp + cardLength; i++) {
			for (int j = TempY; j < TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (i = Temp; i < Temp + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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
		cout << "��������";
	}
}

//ѡ�Ƽ�ͷ�ĵ���
//�з���ֵ�����û�е�����������򡰳��ơ����򷵻�0����֮����1��2�Ǵ��˲���
//�β�a���Ƿ��ǵ�һ�γ��ƣ�1��0����
int chooseCard(int a) {
	int key;

	int i = 0, j = 0;
	//a,d�ƶ���ͷ�����س�ѡ�п��ơ����Ʊ�ѡ��ʱ����Ӧ����KeyCard������ֵΪ1
	key = _getch();

	//�����
	//int tempLeft_x = length / 2 - (cardNum / 2 ) * 4;
	//Key_x = tempLeft_x + 1;
	//Key_y = height - 15;
	//X_point = Key_x;
	//Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;

	//�ֱ�����a,dʱ��ִ�����
	//X_point��Y_point �Ƕ�Ӧ�š��������͡����ơ�������ť
	if (key == 100) {
		if (Key_x < Y_point && Key_x != X_point - 20 && Key_x != Y_point + 23) {
			Key_x += 4;

			//KeyCard_xΪKeyCard������±�
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
		//���ó��ƺ�������ѡ�еĿ��Ƶ����鴫���ȥ
		
		if (chu(card_hand ,1, K_if_player_is_landlord) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == Y_point + 23 && a == 0) {
		//���ó��ƺ�������ѡ�еĿ��Ƶ����鴫���ȥ

		if (chu(card_hand, 0, K_if_player_is_landlord) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == X_point - 20 &&a == 0) {
		//���ò����ƺ���
		gotoxy(MapLength / 2, MapHeight -17);
		cout << "    ";
		gotoxy(MapLength / 2, MapHeight -17);
		cout << "����";
		buchu(card_hand, K_if_player_is_landlord);
		return 2;
	}


}







//�β�Ϊ����˵�����
void dachu(int* a) {
	//����һ���β������ж��ٸ���
	int num = 1;
	int i = 0, j = 0;
	int Num = 0;
	for (i = 0; i < 20; i++) {
		if (a[i] != 0) {
			Num++;
		}
	}

	int TempX = MapLength / 2 - (Num / 2) * 4;
	//�ڿ���̨��������
	int TempY = tempLeft_y - 20;





	//�Ȱ�����ռ�ռ����������0
	for (i =40; i < MapLength-40; i++) {
		for (j = TempY ; j <= TempY + cardHeight; j++) {
			Map[i][j] = '0';
			
		}
	}

	while (num <= Num) {


		//�Ȱ�����ռ�ռ����������0
		for (i = TempX; i < TempX + cardLength; i++) {
			for (int j = TempY; j < TempY + cardHeight; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ����±߽�
		for (i = TempX; i < TempX + cardLength; i++) {
			Map[i][TempY] = '2';
			Map[i][TempY + cardHeight] = '2';
		}
		//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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



//�β�aΪ��������,�β�bΪ�Ƿ��ǵ�����һ�γ��ƣ�1��0����
int chu(int* a,int b, int if_player_is_landlord) {

	//��������ֵ
	for (int i = 0; i < 20; i++) {
		cardchu[i] = 0;
		Card[i] = 0;
	}
	Card[20] = 0;

	int i = 0, j = 0;
	//����KeyCard���飬����������ļ�����
	for (i = 0; i + cardzero < 20; i++) {
		if (KeyCard[i+cardzero] == 1) {
			//����Ҫ������Ƶ����
			Card[j] = i + 1;
			//����Ҫ�������
			cardchu[j] = a[i+cardzero];
			j++;
		}

	}
	

	if (b == 1) {


		if (rightFirst(cardchu) != 0) {

			//����˶�����
			int numchu = j;

			int num = 1;
			int Temp = tempLeft_x;
			int TempY = tempLeft_y;
			//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
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





					//�򲹶�����ֹ�����һ����ʱ�Դ�ӡ������
					if (num == 21) {
						break;
					}


					//�Ȱ�����ռ�ռ����������0
					for (i = Temp; i < Temp + cardLength; i++) {
						for (int j = TempY; j < TempY + cardHeight; j++) {
							Map[i][j] = '0';
						}
					}

					//�����Ǵ�ӡ�Ƶ����±߽�
					for (i = Temp; i < Temp + cardLength; i++) {
						Map[i][TempY] = '2';
						Map[i][TempY + cardHeight] = '2';
					}
					//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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
				cout << "��������";
			}
			return 1;
		}
		else {
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "��������";
			}
			return 0;
		}
	}
	else {
		if (right(cardchu, temp, tempFunction) != 0) {

			//����˶�����
			int numchu = j;

			int num = 1;
			int Temp = tempLeft_x;
			int TempY = tempLeft_y;
			//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
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

					//�򲹶�����ֹ�����һ����ʱ�Դ�ӡ������
					if (num == 21) {
						break;
					}


					//�Ȱ�����ռ�ռ����������0
					for (i = Temp; i < Temp + cardLength; i++) {
						for (int j = TempY; j < TempY + cardHeight; j++) {
							Map[i][j] = '0';
						}
					}

					//�����Ǵ�ӡ�Ƶ����±߽�
					for (i = Temp; i < Temp + cardLength; i++) {
						Map[i][TempY] = '2';
						Map[i][TempY + cardHeight] = '2';
					}
					//�����Ǵ�ӡ�Ƶ����ߺ�����ֵ

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
				cout << "��������";
			}
			return 1;
		}
		else {
			if (if_player_is_landlord == 1) {
				gotoxy(Y_point + 20, MapHeight - 6);
				cout << "��������";
			}
			return 0;
		}
	}
}




//����Ƶ����飬����������
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


	//���
	while (num_left <= ai_card_num) {
		//�Ȱ�����ռ�ռ����������0
		for (int i = temp_left_x; i < temp_left_x + temp_card_length; i++) {
			for (int j = temp_left_y; j <= temp_left_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ�����
		for (int i = temp_left_y; i < temp_left_y + temp_card_height; i++) {
			Map[temp_left_x - 1][i] = '3';
			Map[temp_left_x + temp_card_length][i] = '3';
		}

		//�����Ǵ�ӡ�Ƶ����±߽�

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
	cout << ai_card_num << "��";
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

	//�ұ�
	while (num_right <= ai_card_num) {
		//�Ȱ�����ռ�ռ����������0
		for (int i = temp_right_x; i < temp_right_x + temp_card_length; i++) {
			for (int j = temp_right_y; j <= temp_right_y + temp_card_height; j++) {
				Map[i][j] = '0';
			}
		}

		//�����Ǵ�ӡ�Ƶ�����
		for (int i = temp_right_y; i < temp_right_y + temp_card_height; i++) {
			Map[temp_right_x - 1][i] = '3';
			Map[temp_right_x + temp_card_length][i] = '3';
		}

		//�����Ǵ�ӡ�Ƶ����±߽�

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
	cout << ai_card_num << "��";






}

void Ai_Left_Buchu() {
	gotoxy(27, MapHeight/2);
	cout << "    ";
	gotoxy(27, MapHeight/2);
	cout << "����";
}


void Ai_Right_Buchu() {
	gotoxy(MapLength- 27, MapHeight / 2);
	cout << "    ";
	gotoxy(MapLength - 27, MapHeight / 2);
	cout << "����";
}