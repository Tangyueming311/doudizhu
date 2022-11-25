#include<iostream>
using namespace std;
int main() {
	int handCard[20] = { 3,3,4,5,6,7,8,9,10,10,10,11,13,14,15 };
	int temp[20] = { 0 };
    int store[40] = { 0 };
    int newcard[20] = { 0 };
    for (int i = 0; i < 20; i++)
    {
	    newcard[i] = handCard[i];
    }
	int c = 0;

	for (int i = 0; i < 20; i++)
     {
	if (newcard[i] == newcard[i + 1] || newcard[i] >= 15)
	{
		 store[c] = newcard[i];
		newcard[i] = 0; c++;

	}
}
for (int i = 0; i < 20 - 1; i++)
{
	for (int j = 0; j < 20 - 1 - i; j++)
		if (newcard[j] > newcard[j + 1])
		{
			int t = newcard[j];
			newcard[j] = newcard[j + 1];
			newcard[j + 1] = t;
		}
}
for (int i = 0; i < 20; i++)
{
	int n = 0;
	if (newcard[i] != 0)
	{
		if (newcard[i] + 1 == newcard[i + 1]
			&& newcard[i + 1] + 1 == newcard[i + 2]
			&& newcard[i + 2] + 1 == newcard[i + 3]
			&& newcard[i + 3] + 1 == newcard[i + 4])
		{
			if (newcard[i + 4] + 1 == newcard[i + 5])
			{
				if (newcard[i + 5] + 1 == newcard[i + 6])
				{
					if (newcard[i + 6] + 1 == newcard[i + 7])
					{
						for (int j = i; j < i + 8; j++) {
							 temp[n] = newcard[j]; n++;
							newcard[j] = 0;
						}
						break;
					}
					else
					{
						for (int j = i; j < i + 7; j++) {
							 temp[n] = newcard[j]; newcard[j] = 0; n++;
						}
						break;
					}
				}
				else
				{
					for (int j = i; j < i + 6; j++) {
						 temp[n] = newcard[j]; newcard[j] = 0; n++;
					}
					break;
				}
			}
			else
			{
				for (int j = i; j < i + 5; j++) {
				 temp[n] = newcard[j]; newcard[j] = 0; n++;
				}
				break;
			}

		}

	}
}int a = 0;
for (int t = 39; t > 19; t--)
{
	
	store[t] = newcard[a]; a++;

}
int min;
int tem;
for (int j = 0; j < 40; j++) {
	min = 100;
	tem = 0;
	for (int i = j; i < 40; i++) {
		if (store[i] < min) {
			min = store[i];
			tem = i;
		}
	}
	swap(store[j], store[tem]);
}/*
for (int i = 0; i < 40 - 1; i++)
{
	for (int j = i; j < 40 - 1 - i; j++)
		if (store[j] > store[j + 1])
		{
			int t = store[j];
			store[j] = store[j + 1];
			store[j + 1] = t;
		}
}*/
int temp_zero = 0;
for (int i = 0; i < 40; i++)
{
	if (store[i] == 0)
		temp_zero++;
}

int temp_temp[40] = { 0 };
for (int i = 0; i < 40; i++)
{
	temp_temp[i] = store[i];
}

for (int i = 0; i+temp_zero < 40; i++)
{
	store[i] = temp_temp[i + temp_zero];
}
for (int j = 0; j < 20; j++)
{
	handCard[j] = store[j];
}

for (int i = 0; i < 20; i++)
{
	if (temp[i] != 0) 
	{
		cout << temp[i] << " ";
	}
}
for (int i = 0; i < 20; i++)
{
	if (handCard[i] != 0)
		cout << handCard[i] << " ";
}
}