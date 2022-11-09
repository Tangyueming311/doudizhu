#include"function.h"
using namespace std;

//���ع��ĺ���
void HideCursor() {

	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

//������ڿ���̨������ָ������
//�β�Ϊx�����y����
void gotoxy(unsigned char x, unsigned char y) {
	//COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
	COORD cor;

	//��� 
	HANDLE hout;

	//�趨����Ҫ��λ�������� 
	cor.X = x;
	cor.Y = y;

	//GetStdHandle������ȡһ��ָ���ض���׼�豸�ľ����������׼���룬��׼����ͱ�׼����
	//STD_OUTPUT_HANDLE���Ǵ����׼�����Ҳ������ʾ�����ĺ� 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleCursorPosition�����������ÿ���̨����λ��
	SetConsoleCursorPosition(hout, cor);
}

//�˵�����
void menu() {
	cout << setfill(' ') << setw(35) << "��������������" << endl;
	cout << setfill(' ') << setw(35) << "���롰1���Կ�ʼ��Ϸ!" << endl;
	cout << setfill(' ') << setw(35) << "���롰2�����˳���Ϸ!" << endl;
	int i;
	cin >> i;
}


//�ж�Ҫ��������Ƿ���Դ��
// ���ڳ��γ���
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ1��0�����Դ��Ϊ1��������Ϊ0
int rightFirst(int* a) {
	int num = 0;
	int i = 0;


	//numΪҪ�����������
	while (a[i] != 0)
	{
		num++;
		i++;
	}

	if (num == 1) {
		tempFunction = 1;           //�ݴ�ֵ���Ƶ�����Ϊ����	
		return 1;
	}

	else if (num == 2) {
		if (a[0] == a[1]) {
			tempFunction = 2;      //�ݴ�ֵ���Ƶ�����Ϊ����	
			return 1;
		}
		else return 0;
	}

	else if (num == 3) {
		if (a[0] == a[1] && a[1] == a[2]) {
			tempFunction = 3;         //�ݴ�ֵ���Ƶ�����Ϊ����	
			return 1;
		}
		else return 0;
	}

}






//�ж�Ҫ��������Ƿ���Դ��
// ���ڸ������
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ���ƣ��β�cΪint���ͣ�Ϊ�Ƶ�����
//returnֵΪ1��0�����Դ��Ϊ1��������Ϊ0
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
	
//���Ҫ����Ƶ��������ݴ���������ͬ�����Բ��ܴ�
	if (num != num2) {                
		return 0;
	}


//�ֱ��жϸ������
	else if (num == num2) {

		if (num == 1) {
			if (singleCard(a, b) == 1)
			{
				cout << "����" << endl;
				tempFunction = 1;           
				return 1;
			}
			else {

				cout << "С��" << endl;
				return 0;
			}
		}

		else if (num == 2) {
			if (doubleCard(a, b) == 1)
			{
				cout << "����" << endl;
				tempFunction = 2;
				return 1;
			}
			else if (doubleCard(a, b) == 0) {

				cout << "С��" << endl;
				return 0;
			}
			else if (doubleCard(a, b) == 2) {
				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}

		else if (num == 3) {
			if (threeCard(a, b) == 1)
			{
				cout << "����" << endl;
				tempFunction = 3;
				return 1;
			}
			else if (threeCard(a, b) == 0) {

				cout << "С��" << endl;
				return 0;
			}
			else if (threeCard(a, b) == 2) {
				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}
	}



}

//�����ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1��Ϊ�Ƿ��ܴ��
int singleCard(int* a, int* b) {
	if (a[0] > b[0]) {
		return 1;

	}
	else {

		return 0;

	}
}
//˫���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1��Ϊ�Ƿ��ܴ��
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
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}
//�����ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1��Ϊ�Ƿ��ܴ��
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
		return 2;        //�����Ϲ淶�ĳ��Ʒ���2ֵ
	}
}

