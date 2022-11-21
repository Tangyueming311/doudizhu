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




//��˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int ifShunzi1(int* b) {
	//�ñ��������ж�˳�����Ƿ��2����Ϊ1��û��Ϊ��һ����2��������0������������
	//������2 �Ĵ���ֵΪ15
	int flag_2 = 0;
	for (int i = 0; i < 20; i++) {
		if (b[i] == 15) {
			flag_2 = 1;
			break;
		}
	}

	if (flag_2 == 1) {
		return 0;
	}
	else {

		//�ں�������ʱ����һ�����飬���βθ��ƹ���
		int a[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			a[i] = b[i];
		}

		int temp = a[0];
		//��һ�����ô�������������ȥa[0]��i��������ȫ��Ϊ0������������μ�1��˳��
		int i = 0;
		while (a[i] != 0) {
			a[i] = a[i] - temp - i;
			i++;
		}

		//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
		int temp1 = 1;
		for (int i = 0; i < 20; i++) {
			if (a[i] != 0) {
				temp1 = 0;
			}
		}

		if (temp1 == 1) {
			return 1;
		}
		else {
			return 0;
		}


	}
}

//˫˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int ifShunzi2(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}



	int temp = a[0];
	//��һ�Σ������ö��ӵ�����һ����ȥǰ���һ��������˫˳�ӱ�ɵ�˳��
	//Ȼ��i��2�ۼӣ����е�˳�ӵ�������õ����ȫΪ0
	int i = 0;
	do {

		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 2;

		i = i + 2;
		//�޶�i�ķ�Χ�������
	} while (a[i] != 0 && i < 19);

	//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 20; i++) {
		if (a[i] != 0) {
			temp1 = 0;
		}
	}

	if (temp1 == 1) {
		return 1;
	}
	else {
		return 0;
	}

}


//��˳���жϣ��������������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1������˳�ӣ�0������
int ifShunzi3(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	int temp = a[0];
	//��һ�Σ������ö��ӵ����ж�����ȥ��ǰ���һ����������˳�ӱ�ɼ��2��0�ĵ�˳��
	//Ȼ��i��3�ۼӣ����е�˳�ӵ�������õ����ȫΪ0
	int i = 0;
	//�޶�i�ķ�Χ�������
	while (a[i] != 0 && i < 18) {
		a[i + 2] = a[i + 2] - a[i];
		a[i + 1] = a[i + 1] - a[i];
		a[i] = a[i] - temp - i / 3;

		i = i + 3;
	}

	//���a[]���������Ϊ0����ȷʵ��˳�ӣ�����1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 20; i++) {
		if (a[i] != 0) {
			temp1 = 0;
		}
	}

	if (temp1 == 1) {
		return 1;
	}
	else {
		return 0;
	}


}

//�ɻ�-�����ж�
//�ɻ�����Ϊ��n��������ͬ������n�����ƻ���n������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1�����Ƿɻ���0������
int plane1(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}
	//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
	//forֻ��18����Ϊ���������
	//����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
	int point[5] = { 0 }; 
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			point[temp] = a[i];
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;

			temp++;
		}
	}

	//�Ƚ�point�����ﴢ������֣�
	//��һ������point���������ȥpoint[0]��i��������ȫ��Ϊ0������������μ�1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//���point[]���������Ϊ0����ȷʵ�Ƿɻ�������1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//�ٴα������飬�����в�Ϊ0����Ϊ1��������������������temp�Ƚϣ���ͬ�Ļ���Ϊ��
	int temp2 = 0;
	for (int i = 0; i < 20; i++) {
		if ((a[i] != 1) && (a[i] != 0)) {
			temp2++;

		}
	}
	if (temp == temp2&&temp1==1) {
		return 1;
	}
	else return 0;
}

//�ɻ�-��˫�ж�
//�ɻ�����Ϊ��n��������ͬ������n�����ƻ���n������
//�β�aΪ�������ͣ�ΪҪ�������
//returnֵΪ0��1��1�����Ƿɻ���0������
int plane2(int* b) {
	//�ں�������ʱ����һ�����飬���βθ��ƹ���
	int a[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		a[i] = b[i];
	}

	//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
	//forֻ��18����Ϊ���������
	int point[5] = { 0 };
	int temp = 0;
	for (int i = 0; i < 18; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i] != 0 && a[i] != 1) {
			a[i] = 1, a[i + 1] = 1, a[i + 2] = 1;
			point[temp] = a[i];
			temp++;
		}
	}

	//�ٴα������飬�����в�Ϊ0����Ϊ1��������������������ֵ���µ�����b
	int c[20] = { 0 };
	int j = 0;

	for (int i = 0; i < 20; i++) {
		if ((a[i] != 1) && (a[i] != 0)) {
			c[j] = a[i];
			j++;
		}
	}
	//�Ƚ�point�����ﴢ������֣�
	//��һ������point���������ȥpoint[0]��i��������ȫ��Ϊ0������������μ�1
	int i = 0;
	int Temp = point[0];
	while (point[i] != 0) {
		point[i] = point[i] - Temp - i;
		i++;
	}

	//���point[]���������Ϊ0����ȷʵ�Ƿɻ�������1���෴�򷵻�0
	int temp1 = 1;
	for (int i = 0; i < 5; i++) {
		if (point[i] != 0) {
			temp1 = 0;
		}
	}

	//��ʱ��������b���Ѷ���ȫ�������ж�
	//��������b���±�ÿ��+2��b[i]Ӧ����b[i+1],���������flag=1���м���ֲ�������flag=0
	//ѭ��һ��temp2��һ��������¼���������������������������������һ����flag=1����ȷʵ�Ƿɻ��󣬷���1
	int flag = 1;
	int k = 0;
	int temp2 = 0;
	while (c[k] != 0) {
		if (c[k] != c[k + 1]) {
			flag = 0;
			break;
		}
		k = k + 2;
		temp2++;
	}

	if (flag == 1 && temp == temp2&&temp1==1) {
		return 1;
	}
	else return 0;
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
	//	cout << "�����˵���\n";
		return 1;
	}

	else if (num == 2) {
		if (a[0] == a[1]) {
			tempFunction = 2;      //�ݴ�ֵ���Ƶ�����Ϊ����	
	//		cout << "�����˶���\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 3) {
		if (a[0] == a[1] && a[1] == a[2]) {
			tempFunction = 3;         //�ݴ�ֵ���Ƶ�����Ϊ����	
	//		cout << "����������һ������\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
			tempFunction = 100;         //�ݴ�ֵ���Ƶ�����Ϊը��	

	//		cout << "��ֱ�Ӵ����ը����!!!\n";
			return 1;
		}
		else if ((a[0] == a[1] && a[1] == a[2] && a[2] != a[3]) || (a[0] != a[1] && a[1] == a[2] && a[2] == a[3])) {
			tempFunction = 4;          //�ݴ�ֵ���Ƶ�����Ϊ����һ
	//		cout << "����������һ\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 5) {
		if (ifShunzi1(a)) {
			tempFunction = 51;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-5	
	//		cout << "������5��˳��\n";
			return 1;
		}
		if (plane2(a)) {
			tempFunction = 50;        //�ݴ�ֵ���Ƶ�����Ϊ ������
	//		cout << "����������һ��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 6) {


		if (ifShunzi1(a)) {
			tempFunction = 61;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-6
	//		cout << "������6��˳��\n";
			return 1;
		}
		else if (ifShunzi2(a)) {
			tempFunction = 62;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-6
	//		cout << "������6�ŵ�˫˳��\n";
			return 1;
		}
		else if (ifShunzi3(a)) {
			tempFunction = 63;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-6
	//		cout << "������6�ŵ���˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 7) {
		if (ifShunzi1(a)) {
			tempFunction = 71;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-7
	//		cout << "������7��˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 8) {
		if (ifShunzi1(a)) {
			tempFunction = 81;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-8
	//		cout << "������8��˳��\n";
			return 1;
		}
		else if (ifShunzi2(a)) {
			tempFunction = 82;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-8
	//		cout << "������8�ŵ�˫˳��\n";
			return 1;
		}
		else if (plane1(a)) {
			tempFunction = 83;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-8
	//		cout << "������8�ŵķɻ�����\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}

	}

	else if (num == 9) {
		if (ifShunzi1(a)) {
			tempFunction = 91;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-9
	//		cout << "������9��˳��\n";
			return 1;
		}
		else if (ifShunzi3(a)) {
			tempFunction = 93;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-9
	//		cout << "������9�ŵ���˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 10) {
		if (ifShunzi1(a)) {
			tempFunction = 81;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-10
	//		cout << "������10��˳��\n";
			return 1;
		}
		else if (ifShunzi2(a)) {
			tempFunction = 82;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-10
	//		cout << "������10�ŵ�˫˳��\n";
			return 1;
		}
		else if (plane2(a)) {
			tempFunction = 85;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-10
	//		cout << "������10�ŵķɻ���˫\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 11) {
		if (ifShunzi1(a)) {
			tempFunction = 111;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-11
	//		cout << "������11��˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 12) {
		if (ifShunzi1(a)) {
			tempFunction = 121;         //�ݴ�ֵ���Ƶ�����Ϊ˳��-12
	//		cout << "������12��˳��\n";
			return 1;
		}
		else if (ifShunzi2(a)) {
			tempFunction = 122;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-12
	//		cout << "������12�ŵ�˫˳��\n";
			return 1;
		}
		else if (plane1(a)) {
			tempFunction = 125;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-12
	//		cout << "������12�ŵķɻ�����\n";
			return 1;
		}
		else if (ifShunzi3(a)) {
			tempFunction = 123;         //�ݴ�ֵ���Ƶ�����Ϊ��˳��-12
	//		cout << "������12�ŵ���˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 13) {
	//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 14) {
		if (ifShunzi2(a)) {
			tempFunction = 142;         //�ݴ�ֵ���Ƶ�����Ϊ˫˳��-14
	//		cout << "������14�ŵ�˫˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 15) {
		if (ifShunzi3(a)) {
			tempFunction = 153;          // �ݴ�ֵ���Ƶ�����Ϊ��˳�� - 15
	//		cout << "������15�ŵ���˳��\n";
			return 1;
		}

		else if (plane2(a)) {
			tempFunction = 155;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-15
	//		cout << "������15�ŵķɻ���˫\n";
			return 1;
		}

		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 16) {
		if (ifShunzi2(a)) {
			tempFunction = 162;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 16
	//		cout << "������16�ŵ�˫˳����\n";
			return 1;
		}

		else if (plane1(a)) {
			tempFunction = 165;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-16
	//		cout << "������16�ŵķɻ�����\n";
			return 1;
		}

		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}
	else if (num == 17) {
	//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 18) {
		if (ifShunzi3(a)) {
			tempFunction = 183;          // �ݴ�ֵ���Ƶ�����Ϊ��˳�� - 18
	//		cout << "������18�ŵ���˳��\n";
			return 1;
		}

		if (ifShunzi2(a)) {
			tempFunction = 182;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 18
	//		cout << "������18�ŵ�˫˳��\n";
			return 1;
		}
		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else if (num == 19) {
	//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
	}

	else if (num == 20) {
		if (ifShunzi2(a)) {
			tempFunction = 202;          // �ݴ�ֵ���Ƶ�����Ϊ˫˳�� - 20
	//		cout << "������20�ŵ�˫˳��\n";
			return 1;
		}

		else if (plane1(a)) {
			tempFunction = 205;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ�����-20
	//		cout << "������20�ŵķɻ�����\n";
			return 1;
		}
		else if (plane2(a)) {
			tempFunction = 206;         //�ݴ�ֵ���Ƶ�����Ϊ�ɻ���˫-20
	//		cout << "������20�ŵķɻ���˫\n";
			return 1;
		}

		else {
	//		cout << "���Ʋ����Ϲ淶" << endl;
			return 0;
		}
	}

	else {
	//	cout << "���Ʋ����Ϲ淶" << endl;
		return 0;
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
	while (b[j] != 0)
	{
		num2++;
		j++;
	}
	
//���Ҫ����Ƶ��������ݴ���������ͬ�����Բ��ܴ�
	if (num != num2&&num!=4&&num!=2) {    
//		cout << "��������" << endl;
//		cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
		return 0;
	}



//�ֱ��жϸ������


	else if (num != num2 && num == 4) {
		if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]&&temp[0]!=16&&temp[1]!=17) {
			
//			cout << "ը��ѹ����������" << endl;
			return 1;
		}
		else {
//			cout << "��������" << endl;
//			cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
			return 0;
		}
	}
	else if (num != num2 && num == 2) {
		if (a[0] == 16 && a[1] == 17) {
			
//			cout << "��ը��ɱ����������"<<endl;
			return 1;
		}
		else {
//			cout << "��������" << endl;
//			cout << "�ݴ�������" << num2 << " " << "�������" << num << endl;
			return 0;
		}
	}


	else if (num == num2) {

		if (num == 1) {
			if (singleCard(a, b) == 1)
			{
//				cout << "����" << endl;
				         
				return 1;
			}
			else {

//				cout << "С��" << endl;
				return 0;
			}
		}

		else if (num == 2) {
			if (a[0] == 16 && a[1] == 17) {				
//				cout << "��ը��ɱ����������" << endl;
				return 1;
			}
			else {
				if (doubleCard(a, b) == 1)
				{
	//				cout << "����" << endl;
					
					return 1;
				}
				else if (doubleCard(a, b) == 0) {

	//				cout << "С��" << endl;
					return 0;
				}
				else if (doubleCard(a, b) == 2) {
//					cout << "�����Ϲ淶" << endl;
					return 0;
				}
			}
			
		}

		else if (num == 3) {
			if (threeCard(a, b) == 1)
			{
//				cout << "����" << endl;
				
				return 1;
			}
			else if (threeCard(a, b) == 0) {

	//			cout << "С��" << endl;
				return 0;
			}
			else if (threeCard(a, b) == 2) {
//				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}

		else if (num == 4) {
			if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&b[0]==b[1]&&b[1]==b[2]&&b[2]==b[3]) {
				if (BoomCard(a, b) == 0) {
//					cout << "С��" << endl;
					return 0;
				}
				else if (BoomCard(a, b) == 1) {
	//				cout << "����ը��������" << endl;
					
					return 1;
				}
				else if (BoomCard(a, b) == 2) {
//					cout << "�����Ϲ淶" << endl;
   				    return 0;
				}
			}
			else {
				if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
					
//					cout << "ը��ѹ����������" << endl;
					return 1;
				}

				else if (plane1Card(a, b) == 0) {
//					cout << "С��" << endl;
					return 0;
				}
				else if (plane1Card(a, b) == 1) {
//					cout << "����һ" << endl;
					return 1;
				}
				else if (plane1Card(a, b) == 2) {
//					cout << "�����Ϲ淶" << endl;
					return 0;
				}
			}
		}

		else if (num == 5) {
			if (plane2Card(a, b) == 0) {
//				cout << "С��" << endl;
				return 0;
			}
			else if (plane2Card(a, b) == 1) {
//				cout << "����һ" << endl;
				return 1;
			}
			else if (ifShunzi1Card(a, b) == 0) {
//				cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
//				cout << "˳��" << endl;
				return 1;
			}

			else  {
//				cout << "�����Ϲ淶" << endl;
				return 0;
			}
		}

		else if (num == 6) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (ifShunzi3Card(a, b) == 0) {
//				cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi3Card(a, b) == 1) {
	//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else  {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }

		else if (num == 7) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 8) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (plane2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane2Card(a, b) == 1) {
	//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}
		 
        }

		else if (num == 9) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else if (ifShunzi3Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi3Card(a, b) == 1) {
	//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else  {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}
        }
		else if (num == 10) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (plane2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane2Card(a, b) == 1) {
	//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
//				cout << "�����Ϲ淶" << endl;
			return 0;
			}
        }
		else if (num == 11) {
		    if (ifShunzi1Card(a, b) == 0) {
//				cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
//				cout << "˳��" << endl;
				return 1;
			}
			else {
//				cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 12) {
		    if (ifShunzi1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi1Card(a, b) == 1) {
	//			cout << "˳��" << endl;
				return 1;
			}
			else if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (ifShunzi3Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi3Card(a, b) == 1) {
	//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else if (plane1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane1Card(a, b) == 1) {
	//			cout << "����һ" << endl;
				return 1;
			}
			else  {
				cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 14) {
		    if (ifShunzi2Card(a, b) == 0) {
				cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
				cout << "����" << endl;
				return 1;
			}
			else {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 15) {
		    if (ifShunzi3Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi3Card(a, b) == 1) {
	//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else if (plane2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane2Card(a, b) == 1) {
	//			cout << "�ɻ�" << endl;
				return 1;
			}
			else {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}
        }
		else if (num == 16) {
		  
		    if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (plane1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane1Card(a, b) == 1) {
	//			cout << "����һ" << endl;
				return 1;
			}
			else  {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 18) {

		    if (ifShunzi2Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
	//			cout << "����" << endl;
				return 1;
			}
			else if (ifShunzi3Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi3Card(a, b) == 1) {
	//			cout << "�ɻ�û���" << endl;
				return 1;
			}
			else  {
	//			cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else if (num == 20) {
		  
		    if (ifShunzi2Card(a, b) == 0) {
		//		cout << "С��" << endl;
				return 0;
			}
			else if (ifShunzi2Card(a, b) == 1) {
		//		cout << "����" << endl;
				return 1;
			}
			else if (plane1Card(a, b) == 0) {
	//			cout << "С��" << endl;
				return 0;
			}
			else if (plane1Card(a, b) == 1) {
	//			cout << "����һ" << endl;
				return 1;
			}
			else if (plane2Card(a, b) == 0) {
	//			cout << "С��" << endl;
	 		    return 0;
			}
			else if (plane2Card(a, b) == 1) {
		//		cout << "�ɻ�" << endl;
				return 1;
			}
			else  {
	//		cout << "�����Ϲ淶" << endl;
				return 0;
			}

        }
		else  {
	//	cout << "�����Ϲ淶" << endl;
		return 0;
	    }


	}
	


}


//��˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int ifShunzi3Card(int* a, int* b) {
	if (ifShunzi3(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
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
//˫˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int ifShunzi2Card(int* a, int* b) {
	if (ifShunzi2(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
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







//��˳���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int ifShunzi1Card(int* a, int* b) {
	if (ifShunzi1(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

		if (temp1[0] > temp2[0]) {
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



//�ɻ���˫�ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int plane2Card(int* a, int* b) {
	if (plane2(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
	    //temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}
		//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
        //forֻ��18����Ϊ���������
        //����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
		int point1 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp1[i] == temp1[i + 1] && temp1[i + 1] == temp1[i + 2] && temp1[i] != 0) {
				point1 = temp1[i];
				break;
			}
		}

		int point2 = 0;
		for (int i = 0; i < 18; i++) {
			if (temp2[i] == temp2[i + 1] && temp2[i + 1] == temp2[i + 2] && temp2[i] != 0) {
				point2 = temp2[i];
				break;
			}
		}

		if (point1 > point2) {
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




//�ɻ������ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int plane1Card(int* a, int* b) {
	if (plane1(a) == 1) {
		//�ں�������ʱ�����������飬���βθ��ƹ���
		//temp1�����Ӧa��ΪҪ������ƣ�tenp2�����Ӧb��Ϊ�ݴ����
		int temp1[20] = { 0 };
		int temp2[20] = { 0 };
		for (int i = 0; i < 20; i++) {
			temp1[i] = a[i];
		}
		for (int i = 0; i < 20; i++) {
			temp2[i] = b[i];
		}

	//�������飬��������ͬ���ƶ���ֵΪ1������ֵΪ0����Ϊ��ȱλΪ0���Լ�����Ӱ�죩����ֵһ��temp+1;
	//forֻ��18����Ϊ���������
	//����point��Ϊ�˴�����ֵ�������ͬ���Ƶ����棬��Ϊ�ɻ���Ҫ����
		int point1=0;
		for (int i = 0; i < 18; i++) {
			if (temp1[i] == temp1[i + 1] && temp1[i + 1] == temp1[i + 2] && temp1[i] != 0 ) {
				point1 = temp1[i];
				break;
			}
		}

		int point2=0;
		for (int i = 0; i < 18; i++) {
			if (temp2[i] == temp2[i + 1] && temp2[i + 1] == temp2[i + 2] && temp2[i] != 0) {
				point2 = temp2[i];
				break;
			}
		}

		if (point1 > point2) {
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


//ը���ж�
//�β�aΪ�������ͣ�ΪҪ������ƣ��β�bΪ�������ͣ�Ϊ�ݴ����
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
int BoomCard(int* a, int* b) {
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && tempFunction == 100) {
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
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
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
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
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
//returnֵΪ0��1,2;1��0ָ���Ϲ淶���Ƿ��ܴ����2ָ�����Ϲ淶
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












//�β���6����a��b��c���������ͣ�a1��a2��a3��int���ͣ�
//a��b��c���ֱ������Һ�����ai�����ƣ�a1,a2,a3�ֱ�����������Ƿ��ǵ���
//����if else��������ۣ���������������=0.����꣬��������
void endgame(int*a,int * b,int *c,int a1,int a2 ,int a3){
	int x=0, y=0, z=0;

	for (int i = 0; i < 20; i++) {
		x += a[i];
	}
	for (int i = 0; i < 20; i++) {
		y += b[i];
	}
	for (int i = 0; i < 20; i++) {
		z += c[i];
	}

	if (a1 == 1) {
		system("cls");
		if (x == 0) {
			cout << "����Ӯ����";
			exit(100);
		}
		else if (y == 0||z==0) {
			cout << "ũ��Ӯ����";
			exit(100);
		}
	}
	else if (a2 == 1) {
		system("cls");
		if (y == 0) {
			cout << "����Ӯ����";
			exit(100);
		}
		else if (x == 0 || z == 0) {
			cout << "ũ��Ӯ����";
			exit(100);
		}
	}
	else if (a3 == 1) {
		system("cls");
		if (z == 0) {
			cout << "����Ӯ����";
			exit(100);
		}
		else if (y == 0 || x == 0) {
			cout << "ũ��Ӯ����";
			exit(100);
		}
	}
}

