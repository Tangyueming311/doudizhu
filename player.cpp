#include"function.h"
#include"player.h"
#include"draw.h"

using namespace std;

//return����ֵ
// int player::getLL() { return ifLandlord; }
//return��������
int* player::getHand() { return handCard; }
//�β�aΪint���ͣ�������ҵ���ֵ
//void player::setLL(int a) { ifLandlord = a; }

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
    //Card[]  
	//����Ҫ������Ƶ���ֵ�����飬��0��β
    //cardchu[]
	for (int i = 0; i < 20; i++) {
		temp[i] = 0;
	}

	int j = 0;
	int i = 0;

	//��¼�����ж�����
	int Temp = 0;
	
	//��¼����ǰ�ж��ٸ�0
	int temp2 = 0;
	for (int k = 0; k < 20; k++) {
		if (handCard[k] != 0) {
			Temp++;
		}
		else {
			temp2++;
		}
	}
	
	//cout << endl<<"�ֵ����ȳ���"<<endl;
	
	getNum(Temp, handCard,temp2);

//�ú���ʱ���컭����������ʼ�����Լ���ʼ���ƣ�Ϊÿһ���ʼ���õĺ���
//�β�a�������������飬�β�cardNum������
	Player_Card_Creat(handCard, Temp,temp2, K_if_player_is_landlord);

	while (1) {

		int a = chooseCard(1);

		if (a == 0) {
			move();
		}
		else if (a == 1) {			
			break;
		}
		
	}



	
	



		//��������ƽ����ݴ�
		for (int i = 0; i < 20; i++) {
			temp[i] = cardchu[i];
		}

		//��������ƺ�����Ƹ�ֵΪ0
		i = 0;
		while (Card[i] != 0) {
			handCard[temp2 + Card[i] - 1] = 0;
			i++;
		}
		order();



		tempchu = 0;



}


//������Ƶĺ���
void player::chuCard() {
	//����Ҫ������Ƶ���ŵ����飬��0��β
	//Card[]  
	//����Ҫ������Ƶ���ֵ�����飬��0��β
	//cardchu[]

	int j = 0;
	int i = 0;
	int Temp = 0;

	//flagΪ�Ƿ񲻳���Ϊ1�ǳ��ƣ�Ϊ0�ǲ���
	int flag = 1;

	
	
	//��¼����ǰ�ж��ٸ�0
	int temp2 = 0;
	for (int k = 0; k < 20; k++) {
		if (handCard[k] != 0) {
			Temp++;
		}
		else {
			temp2++;
		}
	}



	getNum(Temp, handCard,temp2);
	//�ú���ʱ���컭����������ʼ�����Լ���ʼ���ƣ�Ϊÿһ���ʼ���õĺ���
	//�β�a�������������飬�β�cardNum������
	Player_Card_Creat(handCard, Temp, temp2, K_if_player_is_landlord);

	
		while (1) {
			int a = chooseCard(0);
			if (a == 0) {
				move();
			}
			else if (a == 1) {
				flag = 1;
				dachu(cardchu);
				break;
			}
			else if (a == 2) {
				flag = 0;
				Sleep(100);
				break;
			}
		}
	
	


	if (flag == 1) {
        //�ı��ݴ�ֵ
		for (int i = 0; i < 20; i++) {
			temp[i] = cardchu[i];                                        
		}

        //��������ƺ�����Ƹ�ֵΪ0
		i = 0;
		while (Card[i] != 0) {
			handCard[temp2 + Card[i] - 1] = 0;                            
			i++;
		}
		
		//��������
		order();                                                   


		tempchu = 0;

	}


	//�����tempchu��ô��⣬��ʼֵΪ2������chuFirst����������tempchu=0��tempchu=0������chucard��������������������tempchu=0��
	//tempchu=0������chucard����������������tempchu+1��ֵΪ1����Ϊtempchu=1����һ���Ե���chucard�����������һ�ε���chucard�������Բ�����tempchu+1��
	//tempchu=2�������chufirst����������
	else {
		tempchu ++;
		
	}
}
