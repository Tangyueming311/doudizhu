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


int text[20] = { 3,4,5 };


//tempLeft_xΪ������Ƶ�����ߺ�����,tempLeft_yΪ��������ϱ���������
int tempLeft_x;
int tempLeft_y = MapHeight - 10;



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
void mapCreat(int* a,  int cardNum,int temp1) {
	//��������Ȼ�󻭳������ߵı߽�
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



	//���ü�ͷ����
	Key_x = tempLeft_x + 1;
	Key_y = MapHeight - 15;
	X_point = Key_x;
	Y_point = tempLeft_x + 1 + (cardNum - 1) * 4;


	dachu(temp);

	//��ӡ���˵ڼ�����
	int num = 1;

	int Temp = tempLeft_x;
	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i = 0; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
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

	Draw(0,0,MapLength,MapHeight);
	
	//��ӡ����������ť
	gotoxy(X_point - 23, MapHeight - 9);
	cout << "��������";

	//��ӡ�����ơ���ť
	gotoxy(Y_point + 20, MapHeight - 9);
	cout << "�����ơ�";

	

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
	for (i =X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
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
	for (int j = 2; j < MapLength - 1; j++) {
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
void buchu(int* a) {
	int i = 0, j = 0;
	int num = 1;
	int Temp = tempLeft_x;
	int TempY = tempLeft_y;
	//�Ȱ�����ռ�ռ�,�Լ��Ѿ�ѡ�е�ͻ�����ƵĿռ����������0
	for (i = X_point-15; i < tempLeft_x + (cardNum - 1) * 4 + 14; i++) {
		for (j = tempLeft_y - 4; j <= tempLeft_y + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
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
		
		if (chu(card_hand ,1) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == Y_point + 23 && a == 0) {
		//���ó��ƺ�������ѡ�еĿ��Ƶ����鴫���ȥ

		if (chu(card_hand, 0) == 1) {
			dachu(cardchu);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == 13 && Key_x == X_point - 20 &&a == 0) {
		//���ò����ƺ���
		gotoxy(MapLength / 2, MapHeight / 2);
		cout << "    ";
		gotoxy(MapLength / 2, MapHeight / 2);
		cout << "����";
		buchu(card_hand);
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

	int Temp = MapLength / 2 - (Num / 2) * 4;
	//�ڿ���̨��������
	int TempY = tempLeft_y - 20;





	//�Ȱ�����ռ�ռ����������0
	for (i = X_point - 15; i < X_point + (cardNum - 1) * 4 + 14; i++) {
		for (j = TempY ; j <= TempY + cardHeight; j++) {
			Map[i][j] = '0';
			gotoxy(i, j);
			putchar(' ');
		}
	}

	while (num <= Num) {


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
			Map[Temp + 1][TempY + 1] = a[num - 1];
		}

		num++;
		Temp += 4;
	}


	Draw(0, 0, MapLength, MapHeight);


}



//�β�aΪ��������,�β�bΪ�Ƿ��ǵ�����1��0����
int chu(int* a,int b) {

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
			
			Draw(0, 0, MapLength, MapHeight);

			return 1;
		}
		else {
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