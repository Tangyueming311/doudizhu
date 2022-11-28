
#include"function.h"
#include"player.h"
#include"aiYY.h"
#include"draw.h"
using namespace std;

//�����֮ǰ��order��һ����
void AI_YY::order() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (handcard[i] < min) {
				min = handcard[i];
				temp = i;
			}
		}
		swap(handcard[j], handcard[temp]);
	}
}

//�������������temphandcard����ģ�
void AI_YY::order1() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (temphandcard[i] < min) {
				min = temphandcard[i];
				temp = i;
			}
		}
		swap(temphandcard[j], temphandcard[temp]);
	}
}

//�������������ǰ�����˼����ƣ���ȥ�������ƣ�ͬʱ�ں��油�㣬num��ȥ��������
void AI_YY::order2(int b[], int num)
{
	for (int i = 0; i < 20 - num; i++)
	{
		b[i] = b[i + num];
	}
	for (int k = 20 - num; k < 20; k++)
	{
		b[k] = 0;
	}
}

//С��������ͬʱ����ź���
void AI_YY::order3(int a[])
{

	int v = 0;
	while (a[v] == 0)
	{
		v++;
	}

	for (int i = 0; i < 20 - v; i++)
	{
		a[i] = a[i + v];
	}
	for (int k = 20 - v; k < 20; k++)
	{
		a[k] = 0;
	}
}

//��chucardfirst���������ж����ǲ���˫˳
void AI_YY::ifshuangshun()
{
	bool flag = false;
	//��˫˳��
	for (int i = 0; i < 20; i++)
	{
		if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
		{
			flag = true;
			break;
		}
		else flag = false;
	}
}

//��temp�������ȫ������ĺ���
void AI_YY::qingling()
{
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
}

//���ƺ���ǰ�����п����ʼ���ĺ���
void AI_YY::initlize()
{
	for (int i = 0; i < 20; i++)
	{
		zhadan[i] = 0;
		shuangpai[i] = 0;
		sanzhang[i] = 0;
		danshun[i] = 0;
		temphandcard[i] = handcard[i];
		one[i] = handcard[i];
	}
	huojian[0] = 0;
	huojian[1] = 0;
}


//chucard�������������жϽ����ֵ�˳�����ʣ��ĵ�˳����������ܷ�������˳�ӵĺ���
//,b[]��danshun,temphandcard��ʣ�൥��
void AI_YY::ifshunzi(int b[], int temphandcard[], int shuangpai[])
{

	int flag2 = 0;
	//��ŵ�˳ʣ�����Ƶ���ʱ����
	int z[20] = { 0 };
	//����ܹ��������˫�Ƶ��Ƶ���ʱ����
	int q[20] = { 0 };
	int u[20] = { 0 };
	int w[20] = { 0 };
	for (int a = 0; a < 15; a++)
	{
		//���ж��Ƿ������������˳��
		if (b[a] + 1 == b[a + 1] && b[a] + 2 == b[a + 2] && b[a] + 3 == b[a + 3] && b[a] + 4 == b[a + 4])
		{
			//���ܼ�����ɵ�˳����ǰ������ӵ�һ����ʱ������
			for (int i = 0; i < a; i++)
			{
				z[i] = b[i];
			}
			//������ǰ�����
			order2(b, a);
			//����ʱ��������ƷŽ�temphandcard����
			for (int i = 0, m = 19; i < 20; i++, m--)
			{
				if (z[i] != 0)
				{
					//��temphandcard���油��
					temphandcard[m] = z[i];
					//��temphandcard��������
					sort(temphandcard, temphandcard + 20);
					order3(temphandcard);
				}
			}
			int s = 0;
			//���жϴ�ʱtemphandcard������û��˫��
			for (int i = 0; i < 20; i++)
			{
				if (temphandcard[i] == temphandcard[i + 1] && temphandcard[i] != 0)
				{
					q[s] = temphandcard[i];
					q[s] = temphandcard[i + 1];
					i += 1;
					s += 1;
				}

			}
			//����˫������
			for (int i = 0, m = 19; i < 20; i++, m--)
			{
				if (q[i] != 0)
				{
					//��shuangpai���油��
					shuangpai[m] = q[i];
					//��shuangpai��������
					sort(shuangpai, shuangpai + 20);
					order3(shuangpai);
				}
			}
			//�ٽ�temphandcard�����������
			for (int i = 0; i < 20; i++)
			{
				for (int k = 0; k < 20; k++)
					if (temphandcard[k] == q[i] && temphandcard[k] != 0)
					{
						temphandcard[k] = 0;
					}
			}
			//������
			sort(temphandcard, temphandcard + 20);
			order3(temphandcard);

		}
		if (a == 14 && b[a] == 0)
		{
			flag2 = 1;

		}
		if (flag2 == 1)
		{
			//�����Ʒ�����ʱ����u����
			for (int i = 0; i < 20; i++)
			{
				if (b[i] != 0)
				{
					u[i] = b[i];
				}
			}
			//��˳���ڵ���������
			for (int i = 0; i < 20; i++)
			{
				b[i] = 0;
			}
			//��u����
			sort(u, u + 20);
			order3(u);
			//����ʱ��������ƷŽ�temphandcard����
			for (int i = 0, m = 19; i < 20; i++, m--)
			{
				if (u[i] != 0)
				{
					//��temphandcard���油��
					temphandcard[m] = u[i];
					//��temphandcard��������
					sort(temphandcard, temphandcard + 20);
					order3(temphandcard);
				}
			}
			int s = 0;
			//���жϴ�ʱtemphandcard������û��˫��
			for (int i = 0; i < 20; i++)
			{
				if (temphandcard[i] == temphandcard[i + 1] && temphandcard[i] != 0)
				{
					w[s] = temphandcard[i];
					w[s] = temphandcard[i + 1];
					i += 1;
					s += 1;
				}

			}
			//����˫������
			for (int i = 0, m = 19; i < 20; i++, m--)
			{
				if (w[i] != 0)
				{
					//��shuangpai���油��
					shuangpai[m] = w[i];
					//��shuangpai��������
					sort(shuangpai, shuangpai + 20);
					order3(shuangpai);
				}
			}
			//�ٽ�temphandcard�����������
			for (int i = 0; i < 20; i++)
			{
				for (int k = 0; k < 20; k++)
					if (temphandcard[k] == w[i] && temphandcard[k] != 0)
					{
						temphandcard[k] = 0;
					}
			}
			//������
			sort(temphandcard, temphandcard + 20);
			order3(temphandcard);
		}
	}

}

void AI_YY::chucardfirst()
{
	
	bool flag = false;
	//��˫˳��
	for (int i = 0; i < 20; i++)
	{
		if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
		{
			flag = true;
			break;
		}
	};
	//���ҷɻ�
	//ûʱ���ˣ���һ�γ��Ƶ��˾��Ȳ�Ҫ��ɻ��˰�

	//��ɨ��˳��
	if (danshun[0] != 0)
	{
		qingling();
		int x = 0;
		for (int a = 0; a < 20; a++)
		{

			//���ж��Ƿ������������˳��
			if (danshun[a] + 1 == danshun[a + 1] && danshun[a] + 2 == danshun[a + 2] && danshun[a] + 3 == danshun[a + 3] && danshun[a] + 1 == danshun[a + 1] && danshun[a] + 4 == danshun[a + 4] && danshun[a + 4] < 15)
			{
				int b = a;
				b = a;
				number = 0;
				for (int j = 0; j < 5; j++, x++)
				{

					temp[x] = danshun[b];

					temphandcard[b] = 0;
					if (j < 4) { b++; }

				}

				number += 5;
				//�������ŵ�����£�������ֻ��ܼ������˳���������˳�ӵ����ϼ�
				while (danshun[b + 1] == danshun[b] + 1)
				{

					b = b + 1;
					temp[x] = danshun[b];
					x++;
					number++;
				}
				//����
				for (int c = 0; c < number; c++)
				{
					danshun[a + c] = 0;
				}
				order2(danshun, number);


				b = a;
			}

		}
	/*	cout << "˳����Ҫ��Ҫ" << endl;
		for (int i = 0; i < number; i++)
		{
			cout << temp[i] << ' ';
		}
		cout << endl;*/
		//����temp
		
		Ai_Right_Chu(temp, get_handCard_num_());

		//����tempfunction
		tempFunction = 1100+number;
		//����handcard
		//˳�����12��
		for (int k = 0; k < 12; k++)
		{
			if (number - k >= 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (handcard[i] == temp[number - k])
					{
						handcard[i] = 0;
						break;
					}
				}
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;


	}
	//��˫˳��

	else if (flag)
	{
		qingling();
		int x = 0;
		int m = 0; int n = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i + 2] + 1 == shuangpai[i + 4])
			{
				int u = i;
				u = i;
				number = 6;
				for (; x < number; x++)
				{
					temp[x] = shuangpai[u];

					u++;
				}
				m = x - 1;
				n = u - 1;
				x = x - 2;
				u = u - 2;
				//����������У��������ϼ�
				while (shuangpai[u] + 1 == shuangpai[u + 2])
				{

					m += 1;
					n += 1;
					x += 1;
					u += 1;
					temp[m] = shuangpai[n];
					number++;
				}
				i = m + 1;
				order2(shuangpai, number);
				flag = false;
				break;
			}

		};
		Ai_Right_Chu(temp, get_handCard_num_());
		//����tempfunction
		tempFunction = 1200+number;
		//����handcard
		for (int k = 0; k < 20; k++)
		{
			if (number - k >= 0)
			{
				for (int i = 0; i < 20; i++)
				{

					if (handcard[i] == temp[number - k])
					{
						handcard[i] = 0; break;
					}


				}
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
	}
	//����һ��
	else if (sanzhang[0] != 0 && shuangpai[0] != 0 && shuangpai[0] < 14)
	{
		qingling();
		number = 5;
		for (int i = 0; i < 5; i++)
		{
			if (i < 3)
				temp[i] = sanzhang[i];
			else
				temp[i] = shuangpai[i - 3];
		}
		Ai_Right_Chu(temp, get_handCard_num_());
		order2(sanzhang, number - 2);
		order2(shuangpai, number - 3);
		//����tempfunction
		tempFunction = 2205;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 2)
			{
				break;
			}
			if (handcard[i] == temp[3])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;


	}
	//ɨ������һ
	else if (sanzhang[0] != 0 && temphandcard[0] != 0 && temphandcard[0] < 14)
	{
		qingling();
		number = 4;
		for (int i = 0; i < 4; i++)
		{
			if (i < 3)
				temp[i] = sanzhang[i];
			else
				temp[i] = temphandcard[i - 3];
		}
		Ai_Right_Chu(temp, get_handCard_num_());
		order2(sanzhang, number - 1);
		order2(temphandcard, number - 3);
		//
		tempFunction = 2104;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		for (int i = 0; i < 20; i++)
		{

			if (handcard[i] == temp[3])
			{
				handcard[i] = 0; b += 1;
				break;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;


	}
	//����ʲôҲ����
	else if (sanzhang[0] != 0)
	{
		number = 3;
		qingling();
		for (int i = 0; i < 3; i++)
		{
			temp[i] = shuangpai[i];
		}

		Ai_Right_Chu(temp, get_handCard_num_());

		cout << endl;
		order2(sanzhang, number);

		tempFunction = 1303;
		//����handcard
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 3)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
	}

	//�ҵ���
	else if (temphandcard[0] != 0)
	{
		number = 1;
		qingling();
		temp[0] = temphandcard[0];
		Ai_Right_Chu(temp, get_handCard_num_());
		order2(temphandcard, number);
		tempFunction = 101;
		//
		for (int i = 0; i < 20; i++)
		{
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0;
				break;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
	}
	//��˫��
	else if (shuangpai[0] != 0)
	{
		number = 2;
		qingling();
		for (int i = 0; i < 2; i++)
		{
			temp[i] = shuangpai[i];
		}

		Ai_Right_Chu(temp, get_handCard_num_());
		
		cout << endl;
		tempFunction = 202;
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 2)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		order2(shuangpai, number); number = 0;
	}
	//��ը��
	else if (zhadan[0] != 0)
	{
		number = 4;
		qingling();
		for (int i = 0; i < 4; i++)
		{
			temp[i] = zhadan[i];
		}

		Ai_Right_Chu(temp, get_handCard_num_());
		order2(zhadan, number);
		tempFunction = 1;
		//
		for (int i = 0, b = 0; i < 20; i++)
		{
			if (b >= 4)
			{
				break;
			}
			if (handcard[i] == temp[0])
			{
				handcard[i] = 0; b += 1;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;

	}
	//�һ��
	else if (huojian[0] != 0&&huojian[1] != 0)
	{
		number = 2;
		qingling();
		for (int i = 0; i < 2; i++)
		{
			temp[i] = huojian[i];
		}

		Ai_Right_Chu(temp, get_handCard_num_());
		order2(huojian, 2);
		tempFunction = 1;
		for (int i = 0; i < 20; i++)
		{
			if (handcard[i] == 16 || handcard[i] == 17)
			{
				handcard[i] = 0;
			}
		}
		//��handcard����0������ǰ��
		sort(handcard, handcard + 20);
		number = 0;
	}
	chaipai();
}
void AI_YY::chaipai()
{
	initlize();
	int temp = 0;
	order();
	ifshuangshun();
	while (handcard[temp] == 0) {
		temp++;
	}

	for (int i = 0; i < 20; i++) {
		temphandcard[i] = handcard[i];
	}

	for (int j = temp; j < 20; j++)
	{
		if (temphandcard[j + 1] == temphandcard[j])
		{

			two[a] = temphandcard[j + 1];
			one[j + 1] = 0;
			a++;
			order1();
			sort(one, one + 20);
			j++;
			if (temphandcard[j + 1] == temphandcard[j])
			{

				three[b] = temphandcard[j + 1];
				one[j + 1] = 0;
				b++;
				order1();
				sort(one, one + 20);
				j++;
				int temp = 0;

				if (temphandcard[j + 1] == temphandcard[j])
				{
					four[c] = temphandcard[j + 1];

					one[j + 1] = 0;
					c++;
					order1();
					sort(one, one + 20);
					j++;
				}
			}

		}
	}
	sort(four, four + 20);
	sort(three, three + 20);
	sort(two, two + 20);
	//���һ��
	for (int i = 0, o = 0; i < 20; i++)
	{

		if (temphandcard[i] == 16 || temphandcard[i] == 17)
		{
			huojian[o] = temphandcard[i];
			temphandcard[i] = 0;
			o = o + 1;
		}
	}
	order1();
	//��ը��
	int m = 0;
	for (int i = 0; i < 20; i++)
	{
		if (four[i] != 0)
		{
			int k = 0;
			while (k < 4)
			{
				zhadan[m] = four[i];
				k++;
				m++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (three[j] == four[i] && four[i] != 0)
				{

					three[j] = 0;
					//����
					sort(three, three + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (two[j] == four[i])
				{
					two[j] = 0;
					sort(two, two + 10);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (one[j] == four[i])
				{
					one[j] = 0;
					sort(one, one + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == four[i])
				{
					int l = 0;
					while (l < 4)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						order1();
					}

					sort(temphandcard, temphandcard + 20);
				}
			}

		}
	}

	//��������
	int n = 0;
	for (int i = 0; i < 20; i++)
	{

		if (three[i] != 0)
		{
			int k = 0;
			while (k < 3)
			{
				sanzhang[n] = three[i];
				k++;
				n++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (two[j] == three[i])
				{
					two[j] = 0;
					sort(two, two + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (one[j] == three[i])
				{
					one[j] = 0;
					sort(one, one + 20);
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == three[i])
				{
					int l = 0;
					while (l < 3)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						order1();
					};
				}
			}

		}

	}


	//���ҵ�˳
	int x = 0;
	for (int a = 0; a < 20; a++)
	{

		//���ж��Ƿ������������˳��
		if (one[a] + 1 == one[a + 1] && one[a] + 2 == one[a + 2] && one[a] + 3 == one[a + 3] && one[a] + 1 == one[a + 1] && one[a] + 4 == one[a + 4] && one[a + 4] < 15)
		{

			int b = a;
			b = a;
			int counter = 0;

			for (int j = 0; j < 5; j++, x++)
			{

				danshun[x] = one[b];

				//temphandcard[b] = 0;
				if (j < 4) { b++; }

			}

			counter += 5;
			//�������ŵ�����£�������ֻ��ܼ������˳���������˳�ӵ����ϼ�
			while (one[b + 1] == one[b] + 1)
			{

				b = b + 1;
				danshun[x] = one[b];
				x++;
				counter++;
				//temphandcard[b] = 0;
				//sort(temphandcard, temphandcard + 10);
			}
			//����
			for (int c = 0; c < counter; c++)
			{
				one[a + c] = 0;
			}
			sort(one, one + 20);
			counter = 0;
			b = a;



		}



	}
	int tempdanshun[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		tempdanshun[i] = danshun[i];
	}
	for (int j = 0; j < 20; j++)
	{
		for (int k = 0; k < 20; k++)
		{
			if (temphandcard[j] == tempdanshun[k] && tempdanshun[k] != 0)
			{
				temphandcard[j] = 0;
				tempdanshun[k] = 0;
				sort(tempdanshun, tempdanshun + 20);

			}

		}
	}
	for (int k = 0; k < 20; k++)
	{
		//����two���������
		for (int j = 0; j < 20; j++)
		{
			if (two[j] == danshun[k] && two[j] != 0)
			{
				//cout << "true" << "�˴������" << two[j] << endl;

				two[j] = 0;
				sort(two, two + 20);
			}
		}
	}
	order1();

	//����˫��
	int p = 0;
	for (int i = 0; i < 20; i++)
	{

		if (two[i] != 0)
		{
			int k = 0;
			while (k < 2)
			{
				shuangpai[p] = two[i];
				k++;
				p++;
			}
			for (int j = 0; j < 20; j++)
			{
				if (temphandcard[j] == two[i])
				{
					int l = 0;
					while (l < 2)
					{
						temphandcard[j] = 0;
						j++;
						l++;
						order1();
					}
				}
			}

		}
	}
	sort(temphandcard, temphandcard + 20);
	order3(temphandcard);
	//
	for (int i = 0; i < 20; i++)
	{
		one[i] = 0;
		two[i] = 0;
		three[i] = 0;
		four[i] = 0;

	}
}

//chucard�������������ж��Ƿ���ը������ը�����Բ���ʲôtempfunction��ֱ�ӳ�
void AI_YY::zhaozhadan()
{
	//cout << "ը��ѹ��" << endl;

	tempFunction = 1;
	for (int i = 0; i < 20; i++)
	{
		temp[0] = 0;

	}
	for (int i = 0; i < 4; i++)
	{
		temp[i] = zhadan[0];
	}
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << zhadan[0];
	//}
	
	for (int k = 0; k < 20; k++)
	{
		if (handcard[k] == zhadan[0])
		{
			handcard[k] = 0;

		}
	}
	
	order2(zhadan, 4);
	//��handcard����0������ǰ��
	sort(handcard, handcard + 20);
	Ai_Right_Chu(temp, get_handCard_num_());
}

//chucard�������������ж��Ƿ�����ը������ը���Բ���ʲôtempfunction��ֱ�ӳ�
void AI_YY::zhaowangzha()
{
	//cout << "��ըѹ��" << endl;
	//for (int i = 0; i < 2; i++)
	//{

	//	cout << huojian[i];
	//}
	//cout << endl;
	tempFunction = 1;
	//���ÿ���
	huojian[0] = 0;
	huojian[1] = 0;
	sort(handcard, handcard + 20);
	for (int i = 0; i < 20; i++)
	{
		temp[0] = 0;

	}
	temp[0] = 16;
	temp[1] = 17;
	for (int i = 0; i < 20; i++)
	{
		if (handcard[i] == 16 || handcard[i] == 17)
		{
			handcard[i] = 0;
		}

	}
	Ai_Right_Chu(temp, get_handCard_num_());

}

void AI_YY::chucard()
{

	//����
	if (tempFunction == 101)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temphandcard[i] > temp[0])
			{

				//cout << "����,�ҵ���һ��" << endl;
				//cout << temphandcard[i] << endl;

				//����tenpfunction��ֵ
				tempFunction = 101;
				//����temp�����ֵ
				temp[0] = temphandcard[i];
				//��������Ϊ0
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[i])
					{

						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//����Ϊ0
				temphandcard[i] = 0;
				//��������
				sort(temphandcard, temphandcard + 20);
				order3(temphandcard);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 19 && flag3 == 0)
			{
				flag = 1;
			}

		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}

		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}

		else if (flag == 1)
			Ai_Right_Buchu();
			
	}

	//����
	if (tempFunction == 202)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{

			if (shuangpai[i] > temp[0])
			{

				//cout << "���㣬�ҳ�һ��  " << shuangpai[i] << shuangpai[i + 1] << endl;
				//����tempfunction
				tempFunction = 202;
				//����temp�����ֵ
				temp[0] = shuangpai[i];
				temp[1] = shuangpai[i];
				int flag = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == shuangpai[i])
					{
						flag += 1;
						if (flag > 2)
						{
							break;
						}
						handcard[k] = 0;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				shuangpai[i] = 0;
				shuangpai[i + 1] = 0;

				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 18 && flag3 == 0)
			{
				flag = 1;
			}


		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}

		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)

			Ai_Right_Buchu();
	}
	if (tempFunction == 1303)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 3; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value)
			{

				/*cout << "��Ҳ������" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << endl;*/

				//����tempfunction
				tempFunction = 1303;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];


				int flag = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;

				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
	}
	//ը��
	if (tempFunction == 1)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{

			if (zhadan[i] > temp[0])
			{

				/*cout << "������ը���ǰɣ���Ҳ��ը��������" << endl;
				cout << zhadan[i] << zhadan[i + 1] << zhadan[i + 2] << zhadan[i + 3] << endl;*/
				//����tempfunction
				tempFunction = 1;

				temp[0] = zhadan[i];
				temp[1] = zhadan[i];
				temp[2] = zhadan[i];
				temp[3] = zhadan[i];
				int flag = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == zhadan[i])
					{
						flag += 1;
						if (flag > 4)
						{
							break;
						}
						handcard[k] = 0;
					}
				}
				sort(handcard, handcard + 20);
				//����ը���ڵ�ֵ
				zhadan[i] = 0;
				zhadan[i + 1] = 0;
				zhadan[i + 2] = 0;
				zhadan[i + 3] = 0;
				//��������
				sort(zhadan, zhadan + 20);
				order3(zhadan);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 16 && flag3 == 0)
			{
				flag = 1;
			}


		}

		if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)

			//Ai_Right_Chu(temp, get_handCard_num_());
		    Ai_Right_Buchu();
	}
	//����һ
	if (tempFunction == 2104)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value && temphandcard[0] != 0 && temphandcard[0] < 14)
			{

				/*cout << "�벻���ɣ���Ҳ������һ���ٺ�" << endl;
				cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << temphandcard[0] << endl;*/

				//����tempfunction
				tempFunction = 2104;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = temphandcard[0];
				sort(temp, temp + 20);
				order3(temp);
				int flag = 0; int flag1 = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == temphandcard[0] && flag1 < 1)
					{

						handcard[k] = 0;
						flag1 += 1;
					}
					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				order2(temphandcard, 1);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				flag = 1;
			}


		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)

			//Ai_Right_Chu(temp, get_handCard_num_());
		    Ai_Right_Buchu();
	}
	//������
	if (tempFunction == 2205)
	{
		int value = 0;
		//�ж����ĸ���������
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] == temp[i + 2])
			{
				value = temp[i];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{

			if (sanzhang[i] > value && shuangpai[0] != 0 && shuangpai[0] < 14)
			{

				//cout << "�벻���ɣ���������Ҳ�У��ٺ�" << endl;
				//cout << sanzhang[i] << sanzhang[i + 1] << sanzhang[i + 2] << shuangpai[0] << shuangpai[1] << endl;

				//����tempfunction
				tempFunction = 2205;
				//���ò�����
				temp[0] = sanzhang[i];
				temp[1] = sanzhang[i + 1];
				temp[2] = sanzhang[i + 2];
				temp[3] = shuangpai[0];
				temp[4] = shuangpai[1];
				sort(temp, temp + 20);
				order3(temp);
				int flag = 0; int flag1 = 0;
				//��������
				for (int k = 0; k < 20; k++)
				{

					if (handcard[k] == shuangpai[0] && flag1 < 2)
					{

						handcard[k] = 0;
						flag1 += 1;
					}
					if (handcard[k] == sanzhang[i])
					{
						flag += 1;
						if (flag > 3)
						{
							break;
						}
						handcard[k] = 0;
					}

				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				sanzhang[i] = 0;
				sanzhang[i + 1] = 0;
				sanzhang[i + 2] = 0;
				shuangpai[0] = 0;
				shuangpai[1] = 0;
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)

			//Ai_Right_Chu(temp, get_handCard_num_());
		Ai_Right_Buchu();
	}

	//5���Ƶĵ�˳��
	if (tempFunction ==1105)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 4] > 0)
			{
				///*cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i */+ 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << endl;
				//����tempfunction
				tempFunction = 1105;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}


				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
			
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 17 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//6��˳��
	if (tempFunction == 1106)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 5] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << endl;
				//����tempfunction
				tempFunction = 1106;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
			//	Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 16 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			Ai_Right_Buchu();
		}
	}
	//7��˳��
	if (tempFunction == 1107)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 6] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
			//	cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << endl;
				//����tempfunction
				tempFunction = 1107;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//8��˳��
	if (tempFunction == 1108)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 7] > 0)
			{
			//	cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << endl;
				//����tempfunction
				tempFunction = 1108;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				temp[7] = danshun[i + 7];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				danshun[i + 7] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 14 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

		//	Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//9��˳��
	if (tempFunction == 1109)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 8] > 0)
			{
				
				//����tempfunction
				tempFunction =1109;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				temp[7] = danshun[i + 7];
				temp[8] = danshun[i + 8];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);

				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				danshun[i + 7] = 0;
				danshun[i + 8] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 13 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//10��˳��
	if (tempFunction == 1110)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 9] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				///cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << endl;
				//����tempfunction
				tempFunction = 110;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				temp[7] = danshun[i + 7];
				temp[8] = danshun[i + 8];
				temp[9] = danshun[i + 9];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 9])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				danshun[i + 7] = 0;
				danshun[i + 8] = 0;
				danshun[i + 9] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
			//	Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 12 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//11��˳��
	if (tempFunction == 1111)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 10] > 0)
			{
			//	cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << endl;
				//����tempfunction
				tempFunction = 1111;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				temp[7] = danshun[i + 7];
				temp[8] = danshun[i + 8];
				temp[9] = danshun[i + 9];
				temp[10] = danshun[i + 10];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 9])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 10])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				danshun[i + 7] = 0;
				danshun[i + 8] = 0;
				danshun[i + 9] = 0;
				danshun[i + 10] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 11 && flag3 == 0)
			{
				flag = 1;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//12��˳��
	if (tempFunction == 1112)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (danshun[i] > temp[0] && danshun[i + 11] > 0)
			{
				//cout << "���㣬��Ҳ��˳�ӣ���" << endl;
				//cout << danshun[i] << danshun[i + 1] << danshun[i + 2] << danshun[i + 3] << danshun[i + 4] << danshun[i + 5] << danshun[i + 6] << danshun[i + 7] << danshun[i + 8] << danshun[i + 9] << danshun[i + 10] << danshun[i + 11] << endl;
				//����tempfunction
				tempFunction = 1112;
				//����temp
				temp[0] = danshun[i];
				temp[1] = danshun[i + 1];
				temp[2] = danshun[i + 2];
				temp[3] = danshun[i + 3];
				temp[4] = danshun[i + 4];
				temp[5] = danshun[i + 5];
				temp[6] = danshun[i + 6];
				temp[7] = danshun[i + 7];
				temp[8] = danshun[i + 8];
				temp[9] = danshun[i + 9];
				temp[10] = danshun[i + 10];
				temp[11] = danshun[i + 11];
				//��������
				for (int j = 0; j < 20; j++)
				{
					if (handcard[j] == danshun[i])
					{
						handcard[j] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 1])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 2])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 4])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 5])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 6])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 7])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 8])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 9])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 10])
					{
						handcard[k] = 0;
						break;
					}

				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == danshun[i + 11])
					{
						handcard[k] = 0;
						break;
					}

				}
				sort(handcard, handcard + 20);
				//���õ�˳�ڵ�ֵ
				danshun[i] = 0;
				danshun[i + 1] = 0;
				danshun[i + 2] = 0;
				danshun[i + 3] = 0;
				danshun[i + 4] = 0;
				danshun[i + 5] = 0;
				danshun[i + 6] = 0;
				danshun[i + 7] = 0;
				danshun[i + 8] = 0;
				danshun[i + 9] = 0;
				danshun[i + 10] = 0;
				danshun[i + 11] = 0;
				//��������
				sort(danshun, danshun + 20);
				order3(danshun);
				//�ж�ɾ����ĵ�˳�ܷ�������ɵ�˳
				//ifshunzi(danshun, temphandcard, shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
				break;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 11 && flag3 == 0)
			{
				flag = 1;
				break;

			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

		//	Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//6���Ƶ�����
	if (tempFunction ==1206)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4])
			{
			
				//����tempfunction��ֵ
				tempFunction = 1206;
				//����temp�����ֵ
				for(int j=0;j<6;j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//8���Ƶ�����
	if (tempFunction == 1208)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6])
			{
				/*cout << "��������!!" << endl;
				for (int k = i; k < 8 + i; k++)
				{
					cout << shuangpai[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				tempFunction = 1208;
				//����temp�����ֵ
				for (int j = 0; j < 8; j++)
				{
					temp[j] = shuangpai[i+j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//10���Ƶ�����
	if (tempFunction == 1210)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8])
			{
				
				//����tempfunction��ֵ
				tempFunction = 1210;
				//����temp�����ֵ
				for (int j = 0; j < 10; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//12���Ƶ�����
	if (tempFunction == 1212)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10])
			{
				/*cout << "��������!!" << endl;
				for (int k = i; k < 12 + i; k++)
				{
					cout << shuangpai[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				tempFunction = 1212;
				//����temp�����ֵ
				for (int j = 0; j < 12; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 10])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//14���Ƶ�����
	if (tempFunction == 1242)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12])
			{
				
				//����tempfunction��ֵ
				tempFunction = 1242;
				//����temp�����ֵ
				for (int j = 0; j < 14; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 10])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//16���Ƶ�����
	if (tempFunction == 1262)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14])
			{
				
				//����tempfunction��ֵ
				tempFunction = 1262;
				//����temp�����ֵ
				for (int j = 0; j < 16; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 10])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 14])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12];; int u = shuangpai[i + 14];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//18���Ƶ�����
	if (tempFunction == 1218)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16])
			{
			
				//����tempfunction��ֵ
				tempFunction = 1218;
				//����temp�����ֵ
				for (int j = 0; j < 18; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 10])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 14])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 16])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//20���Ƶ�����
	if (tempFunction == 1220)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (shuangpai[i] > temp[0] && shuangpai[i] + 1 == shuangpai[i + 2] && shuangpai[i] + 2 == shuangpai[i + 4] && shuangpai[i] + 3 == shuangpai[i + 6] && shuangpai[i] + 4 == shuangpai[i + 8] && shuangpai[i] + 5 == shuangpai[i + 10] && shuangpai[i] + 6 == shuangpai[i + 12] && shuangpai[i] + 7 == shuangpai[i + 14] && shuangpai[i] + 8 == shuangpai[i + 16] && shuangpai[i] + 9 == shuangpai[i + 18])
			{
				
				//����tempfunction��ֵ
				tempFunction = 1220;
				//����temp�����ֵ
				for (int j = 0; j < 20; j++)
				{
					temp[j] = shuangpai[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 8])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 10])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 14])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 16])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[i + 18])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//����˫���ڵ�ֵ
				for (int j = 0; j < 20; j++)
				{
					int m = shuangpai[i]; int n = shuangpai[i + 2]; int p = shuangpai[i + 4]; int q = shuangpai[i + 6]; int r = shuangpai[i + 8]; int s = shuangpai[i + 10]; int t = shuangpai[i + 12]; int u = shuangpai[i + 14]; int v = shuangpai[i + 16]; int w = shuangpai[i + 18];
					if (shuangpai[j] == m || shuangpai[j] == n || shuangpai[j] == p || shuangpai[j] == q || shuangpai[j] == r || shuangpai[j] == s || shuangpai[j] == t || shuangpai[j] == u || shuangpai[j] == v || shuangpai[j] == w)
					{
						shuangpai[j] = 0;
					}
				}
				//��������
				sort(shuangpai, shuangpai + 20);
				order3(shuangpai);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�������ŵķɻ�
	if (tempFunction == 1306)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3])
			{
			
				//����tempfunction��ֵ
				tempFunction = 1306;
				//����temp�����ֵ
				for (int j = 0; j< 6; j++)
				{
					temp[j] = sanzhang[i+j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�������ŵķɻ�
	if (tempFunction == 1309)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6])
			{
			
				//����tempfunction��ֵ
				tempFunction = 1309;
				//����temp�����ֵ
				for (int j = 0; j < 9; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
			//	Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ĸ����ŵķɻ�
	if (tempFunction == 1312)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9])
			{
				/*cout << "���ҵķɻ�û���!!" << endl;
				for (int k = i; k < 12 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				tempFunction = 1312;
				//����temp�����ֵ
				for (int j = 0; j < 12; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//������ŵķɻ�
	if (tempFunction == 1315)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12])
			{
			/*	cout << "���ҵķɻ�û���!!" << endl;
				for (int k = i; k < 15 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				tempFunction = 1315;
				//����temp�����ֵ
				for (int j = 0; j < 15; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�������ŵķɻ�
	if (tempFunction == 1318)
	{
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > temp[0] && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12] && sanzhang[i] + 5 == sanzhang[i + 14])
			{
			/*	cout << "���ҵķɻ�û���!!" << endl;
				for (int k = i; k < 18 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << endl;*/
				//����tempfunction��ֵ
				tempFunction = 1318;
				//����temp�����ֵ
				for (int j = 0; j < 18; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 15])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12]; int x = sanzhang[i + 12];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r || sanzhang[j] == x)
					{
						sanzhang[j] = 0;
					}
				}
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{
			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ������ŵ���
	if (tempFunction == 2108)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
				break;
			}

		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && temphandcard[0] != 0 && temphandcard[1] != 0)
			{
			/*	cout << "���ҵķɻ��������" << endl;
				for (int k = i; k < 6 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << temphandcard[0] << temphandcard[1] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2108;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				temp[6] = temphandcard[0];
				temp[7] = temphandcard[1];
				//��������
				sort(temp,temp+20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[0])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[1])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n && sanzhang[j] != 0)
					{
						sanzhang[j] = 0;
					}
				}
				//����temphandcard
				order2(temphandcard, 2);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ�������˫��
	if (tempFunction == 2210)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && shuangpai[0] != 0 && shuangpai[2] != 0)
			{
				/*cout << "���ҵķɻ���������" << endl;
				for (int k = i; k < 6 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2210;
				//����temp�����ֵ
				for (int j = 0; j < 6; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for(int k = 0,l=6;k<4;k++,l++)
				{
					temp[l] = shuangpai[k];
				}
				
				//��������
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[0])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n)
					{
						sanzhang[j] = 0;
					}
				}
				//����shuangpai
				order2(shuangpai, 4);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ������ŵ���
	if (tempFunction == 2112)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[0] < 15)
			{
				/*cout << "���ҵ�C919��ɻ�����" << endl;
				for (int k = i; k < 9 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2112;
				//����temp�����ֵ
				for (int j = 0; j < 9; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 9; k < 3; k++, l++)
				{
					temp[l] = temphandcard[k];
				}
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[0])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[1])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[2])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
					{
						sanzhang[j] = 0;
					}
				}
				//����temphandcard
				order2(temphandcard, 3);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

		//	Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ�������˫��
	if (tempFunction == 2215)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && shuangpai[0] != 0 && shuangpai[2] != 0 && shuangpai[4] != 0)
			{
				/*cout << "���ҵķɻ���������" << endl;
				for (int k = i; k < 9 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2215;
				//����temp�����ֵ
				for (int j = 0; j < 9; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 9; k < 6; k++, l++)
				{
					temp[l] = shuangpai[k];
				}
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[0])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p)
					{
						sanzhang[j] = 0;
					}
				}
				//����shuangpai
				order2(shuangpai, 6);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ������ŵ���
	if (tempFunction == 2116)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[3] != 0 && temphandcard[0] < 15)
			{
				/*cout << "���ҵ�C919��ɻ�����" << endl;
				for (int k = i; k < 12 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2116;
				//����temp�����ֵ
				for (int j = 0; j < 12; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 12; k < 4; k++, l++)
				{
					temp[l] = temphandcard[k];
				}
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[0])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[1])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[2])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[3])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
					{
						sanzhang[j] = 0;
					}
				}
				//����temphandcard
				order2(temphandcard, 4);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ������ŵ���
	if (tempFunction == 2120)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && sanzhang[i] + 4 == sanzhang[i + 12] && temphandcard[0] != 0 && temphandcard[1] != 0 && temphandcard[2] != 0 && temphandcard[3] != 0 && temphandcard[4] != 0 && temphandcard[0] < 15)
			{
				/*cout << "���ҵ�C919��ɻ�����" << endl;
				for (int k = i; k < 15 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << temphandcard[0] << temphandcard[1] << temphandcard[2] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2120;
				//����temp�����ֵ
				for (int j = 0; j < 15; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 15; k < 5; k++, l++)
				{
					temp[l] = temphandcard[k];
				}
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 12])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[0])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[1])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[2])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[3])
					{
						handcard[k] = 0;
						break;
					}
				}
				for (int k = 0; k < 20; k++)
				{
					if (handcard[k] == temphandcard[4])
					{
						handcard[k] = 0;
						break;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6]; int q = sanzhang[i + 9]; int r = sanzhang[i + 12];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q || sanzhang[j] == r)
					{
						sanzhang[j] = 0;
					}
				}
				//����temphandcard
				order2(temphandcard, 5);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}
	//�ɻ�������˫��
	if (tempFunction == 2220)
	{
		int value = 0;
		for (int i = 0; i < 20; i++)
		{
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			{
				value = temp[i + 2];
			}
		}
		int flag = 0; int flag3 = 0;
		for (int i = 0; i < 20; i++)
		{
			if (sanzhang[i] > value && sanzhang[i] + 1 == sanzhang[i + 3] && sanzhang[i] + 2 == sanzhang[i + 6] && sanzhang[i] + 3 == sanzhang[i + 9] && shuangpai[0] != 0 && shuangpai[2] != 0 && shuangpai[4] != 0 && shuangpai[6] != 0)
			{
				/*cout << "���ҵķɻ����Ĵ���" << endl;
				for (int k = i; k < 12 + i; k++)
				{
					cout << sanzhang[k];
				}
				cout << shuangpai[0] << shuangpai[1] << shuangpai[2] << shuangpai[3] << shuangpai[4] << shuangpai[5] << shuangpai[6] << shuangpai[7] << endl;*/
				//����tempfunction��ֵ
				tempFunction = 2220;
				//����temp�����ֵ
				for (int j = 0; j < 12; j++)
				{
					temp[j] = sanzhang[i + j];
				}
				for (int k = 0, l = 12; k < 8; k++, l++)
				{
					temp[l] = temphandcard[k];
				}
				sort(temp, temp + 20);
				order3(temp);
				//����handcard
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 3])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 3)
					{
						break;
					}
					if (handcard[k] == sanzhang[i + 9])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[0])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[2])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[4])
					{
						handcard[k] = 0; b += 1;
					}
				}
				for (int k = 0, b = 0; k < 20; k++)
				{
					if (b >= 2)
					{
						break;
					}
					if (handcard[k] == shuangpai[6])
					{
						handcard[k] = 0; b += 1;
					}
				}
				sort(handcard, handcard + 20);
				//���������ڵ�ֵ
				int m = sanzhang[i]; int n = sanzhang[i + 3]; int p = sanzhang[i + 6];; int q = sanzhang[i + 9];
				for (int j = 0; j < 20; j++)
				{
					if (sanzhang[j] == m || sanzhang[j] == n || sanzhang[j] == p || sanzhang[j] == q)
					{
						sanzhang[j] = 0;
					}
				}
				//����shuangpai
				order2(shuangpai, 8);
				//��������
				sort(sanzhang, sanzhang + 20);
				order3(sanzhang);
				flag3 = 1;
				Ai_Right_Chu(temp, get_handCard_num_());
				//Ai_Right_Buchu();
			}
			//ѭ������Ȼû���ҵ�
			if (i == 15 && flag3 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (zhadan[0] != 0 && flag == 1)
		{
			zhaozhadan();
		}
		else if (huojian[0] != 0 && huojian[1] != 0 && flag == 1)
		{
			zhaowangzha();
		}
		else if (flag == 1)
		{

			//Ai_Right_Chu(temp, get_handCard_num_());
			Ai_Right_Buchu();
		}
	}

	chaipai();
}

















//void AI_YY::set_LL(int a) { ifLandlord = a; }



//void AI_YY::set_Left_Right(int a) {
//	left_right_ = a;
//}

int AI_YY::get_handCard_num_()
{
	int temp_num = 0;
	for (int i = 0; i < 20; i++) {
		if (handcard[i] != 0) {
			temp_num++;
		}
	}
	return temp_num;
}


//��������
void AI_YY::set_Card(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handcard[i] = a[i];
	}

}
//���õ�����
void AI_YY::set_LLcard(int* a)
{
	for (int i = 0; i < 3; i++) {
		handcard[i] = a[i];
	}
}


int* AI_YY:: get_Hand() {
	return handcard;
}