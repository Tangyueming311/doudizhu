#include"function.h"
#include"player.h"
using namespace std;

//return����ֵ
int player::getLL() { return ifLandlord; }
//return��������
int* player::getHand() { return handCard; }
//�β�aΪint���ͣ�������ҵ���ֵ
void player::setLL(int a) { ifLandlord = a; }

//�����������������
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

//�β�a���������ͣ������Ƹ�ֵ
void player::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}

//�β�a���������ͣ������Ƽ��ϵ�����
void player::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}


//�״γ��Ƶĺ���
void player::chuCardFirst() {
	//����Ҫ������Ƶ���ŵ����飬��0��β
	int x[20] = { 0 };   
	//����Ҫ������Ƶ���ֵ�����飬��0��β
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;


	//��ѭ����Ϊ��ʵ�������������Ƶ���ź��ж��ܷ������ܴ��������ѭ�����������ظ�ѭ��
	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		for (int i = 0; i < 20; i++) {
			y[i] = 0;
		}

		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);
 
		//handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0
		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}

	} while (rightFirst(y) == 0);

//��������ƽ����ݴ�
	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];
	}

	//��������ƺ�����Ƹ�ֵΪ0
	i = 0;
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0; 
		i++;
	}
	order();

	cout << "����� ";
	
	
//����
	i = 0;
	
	while (y[i] != 0) {
		cout << y[i] << " ";
		i++;
	}
	cout << endl;


}
//������Ƶĺ���
void player::chuCard() {
	//����Ҫ������Ƶ���ŵ����飬��0��β
	int x[20] = { 0 };
	//����Ҫ������Ƶ���ֵ�����飬��0��β
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;

	//��ѭ����Ϊ��ʵ�������������Ƶ���ź��ж��ܷ������ܴ��������ѭ�����������ظ�ѭ��
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

		//handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0
		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			 
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}


	} while (right(y, temp, tempFunction) == 0);


	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];                                        //�ı��ݴ�ֵ
	}
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;                            //��������ƺ�����Ƹ�ֵΪ0
		i++;
	}
	order();                                                   //��������

	//����
	while (y[i] != 0) {
		cout << "�����" << y[i] << " ";
	}
	cout << endl;
}
