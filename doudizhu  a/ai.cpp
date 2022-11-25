////在这里写你的ai吧！
////记得把成员函数声明放进ai.h
////如果不知道怎么用多个文件的话先去百度一下捏
//
//
////提供了一个出牌种类的表，为tempFunction的值
// 
//
//#include"function.h"
//#include"player.h"
//#include"ai.h"
//#include"draw.h"
//using namespace std;
//int ai::get_LL() { return ifLandlord; }
//int* ai::get_Hand() { return ai_handcard_; }
//void ai::set_LL(int a) { ifLandlord = a; }
//int* ai::get_Hand_Boom() {return ai_handcard_boom_;}
//
//void ai::set_Hand_Num() {
//	int temp1 = 0;
//	int temp2 = 0;
//
//	for (int i = 0; i < 20; i++) {
//		if (ai_handcard_[i] != 0) {
//			temp1++;
//		}
//	}
//
//	for (int i = 0; i < 20; i++) {
//		if (ai_handcard_boom_[i] != 0&&ai_handcard_boom_[i]==16) {
//			temp2+=2;
//		}
//		else if (ai_handcard_boom_[i] != 0 && ai_handcard_boom_[i] != 16) {
//			temp2 += 4;
//		}
//	}
//	
//	ai_handcard_num = temp1 + temp2;
//}
//
//int ai::get_Hand_Num() {
//	return ai_handcard_num;
//}
//
////排序函数
//
//
//void ai::Order() {
//	int min;
//	int temp;
//	for (int j = 0; j < 20; j++) {
//		min = 100;
//		temp = 0;
//		for (int i = j; i < 20; i++) {
//			if (ai_handcard_[i] < min) {
//				min = ai_handcard_[i];
//				temp = i;
//			}
//		}
//		swap(ai_handcard_[j], ai_handcard_[temp]);
//	}
//
//	for (int j = 0; j < 20; j++) {
//		min = 100;
//		temp = 0;
//		for (int i = j; i < 20; i++) {
//			if (ai_handcard_chu_[i] < min) {
//				min = ai_handcard_chu_[i];
//				temp = i;
//			}
//		}
//		swap(ai_handcard_chu_[j], ai_handcard_chu_[temp]);
//	}
//
//}
////设置手牌
//void ai::set_Card(int* a)
//{
//	int j = 0;
//	for (int i = 0; i < 17; i++) {
//		ai_handcard_[i] = a[i];
//	}
//
//}
////设置地主牌
//void ai::set_LLcard(int* a) {
//	for (int i = 0; i < 3; i++) {
//		ai_handcard_[i] = a[i];
//	}
//}
//
//
//
//
////void ai::DividCard() {
////	for (int i = 0; i < 20; i++) {
////		handcard_shunzi1_[i] =  0 ;
////	    handcard_shunzi2_[i] =  0 ;
////		handcard_shunzi3_[i] =  0 ;
////		handcard_plane1_[i] = 0 ;
////		handcard_plane2_[i] =  0 ;
////		handcard_boom_[i] =  0 ;
////		handcard_single_[i] =  0 ;
////		handcard_double_[i] =  0;
////	}
////
////
////
////
////
////}
//
//
//
//
//
//void ai::ChuCard() {
//	for (int i = 0; i < 20; i++) {
//		ai_handcard_chu_[i]=0;
//	}
//	//11为单顺子
//	//12为双顺子+对子
//	//13为三顺子+三张
//	//21为飞机带单
//	//22为飞机带双
//	
//	int type_tempFunction = tempFunction / 100;
//	int num_tempFunction = tempFunction % 100;
//
//	//炸弹的情况，有炸即跟炸
//	if (tempFunction == 1) {
//
//
//		for (int i = 0; i < 20; i++) {
//			if (ai_handcard_boom_[i] > temp[0]&&ai_handcard_boom_[i]!=16) {
//				for (int j = 0; j < 4; i++) {
//					ai_handcard_chu_[j] = ai_handcard_boom_[i];
//					ai_handcard_boom_[i] = 0;
//				}
//
//				for (int k = 0; k < 20; i++) {
//					temp[k] = ai_handcard_chu_[k];
//				}
//				break;
//			}
//			else if (ai_handcard_boom_[i] == 16) {
//				
//				ai_handcard_chu_[0] = 16;
//				ai_handcard_chu_[1] = 17;
//				ai_handcard_boom_[i] = 0;
//				
//
//				for (int k = 0; k < 20; i++) {
//					temp[k] = ai_handcard_chu_[k];
//				}
//				break;
//			}
//		}
//
//	}
//	//单牌
//	else if (tempFunction == 101) {
//		if (SearchSingle() == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//双牌
//	else if (tempFunction == 202) {
//		if (SearchDouble() == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//单顺子
//	else if (type_tempFunction == 11) {
//		if (SearchShunzi1(num_tempFunction) == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//双顺子
//	else if (type_tempFunction == 12) {
//		if (SearchShunzi2(num_tempFunction) == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//三顺子
//	else if (type_tempFunction == 13) {
//		if (SearchShunzi3(num_tempFunction) == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//飞机带单
//	else if (type_tempFunction == 21) {
//		if (SearchPlane1(num_tempFunction) == 1) {
//
//		}
//		else {
//
//		}
//	}
//	//飞机带双
//	else if (type_tempFunction == 22) {
//		if (SearchPlane2(num_tempFunction) == 1) {
//
//		}
//		else {
//
//		}
//	}
//
//	
//
//
//
//}
//
//void ai::ChuCardFirst() {
//	for (int i = 0; i < 20; i++) {
//		ai_handcard_chu_[i]=0;
//	}
//
//
//
//
//
//}
//
//
////num_card是张数，num是次数
//int ai::SearchShunzi1(int num_card)
//{
//	int num = num_card;
//
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//
//	int flag = 0;
//	int J = 0;
//	int temp_num = 1;
//	for (int i = temp_zero; i < 20-num; i++) {
//		J = i;
//		temp_num = 1;
//		while ( 1) {
//			if (temp_card[J + 1] == temp_card[J]+1) {
//				J++;
//				temp_num++;
//				if (temp_num == num) {
//					flag = 1;
//					break;
//				}
//			}
//			else {				
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}	
//	}
//
//	//比较大小
//	if (flag == 1) {
//		if (temp_card[J - num + 1] <= temp[0]) {
//			flag = 0;
//		}
//	}
//
//
//	if (flag == 1) {
//		ai_handcard_chu_[num-1] = temp_card[J];
//		for (int i = num-1; i >0; i--) {
//			ai_handcard_chu_[i - 1] = ai_handcard_chu_[i] - 1;
//		}
//
//		for (int i = J; i > J - num; i--) {
//			ai_handcard_[i] = 0;
//		}
//		
//		return 1;
//	}
//
//
//
//
//	else {
//		return 0;
//	}
//}
//
//int ai::SearchShunzi2(int num_card)
//{
//	int num = num_card / 2;
//
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	int J = 0;
//	int temp_num = 1;
//
//	for (int i = temp_zero; i < 20 - num; i++) {
//		J = i;
//		temp_num = 1;
//		while (1) {
//			if (temp_card[J + 2] == temp_card[J] + 1 && temp_card[J] == temp_card[J + 1] && temp_card[J + 2] == temp_card[J + 3]) {
//				J += 2;
//				temp_num++;
//				if (temp_num == num) {
//					flag = 1;
//					break;
//				}
//			}
//			else {
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//	}
//
//	//比较大小
//	if (flag == 1) {
//		if (temp_card[J - num*2 + 1] <= temp[0]) {
//			flag = 0;
//		}
//	}
//
//
//	if (flag == 1) {
//		ai_handcard_chu_[num * 2 - 1] = temp_card[J];
//		for (int i = num * 2 - 1; i > 0; i -= 2) {
//			ai_handcard_chu_[i - 2] = ai_handcard_chu_[i] - 1;
//			ai_handcard_chu_[i - 1] = ai_handcard_chu_[i];
//		}
//
//		for (int i = J+1; i > J - num*2; i--) {
//			ai_handcard_[i] = 0;
//		}
//
//		return 1;
//	}
//
//
//
//	else {
//		return 0;
//	}
//}
//
//int ai::SearchShunzi3(int num_card)
//{
//	int num = num_card / 3;
//
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	int J = 0;
//	int temp_num = 1;
//
//	for (int i = temp_zero; i < 20 - num; i++) {
//		J = i;
//		temp_num = 1;
//		while (1) {
//			if (temp_card[J + 3] == temp_card[J] + 1 && temp_card[J] == temp_card[J + 1] && temp_card[J + 2] == temp_card[J + 1] && temp_card[J + 3] == temp_card[J + 4] && temp_card[J + 4] == temp_card[J + 5]) {
//				J += 3;
//				temp_num++;
//				if (temp_num == num) {
//					flag = 1;
//					break;
//				}
//			}
//			else {
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//	}
//
//	//比较大小
//	if (flag == 1) {
//		if (temp_card[J - num * 3 + 1] <= temp[0]) {
//			flag = 0;
//		}
//	}
//
//
//	if (flag == 1) {
//		ai_handcard_chu_[num * 3 - 1] = temp_card[J];
//		for (int i = num * 3 - 1; i > 0; i -= 3) {
//
//			ai_handcard_chu_[i - 3] = ai_handcard_chu_[i] - 1;
//
//			ai_handcard_chu_[i - 1] = ai_handcard_chu_[i];
//			ai_handcard_chu_[i - 2] = ai_handcard_chu_[i];
//
//		}
//
//		for (int i = J+2; i > J - num*3; i--) {
//			ai_handcard_[i] = 0;
//		}
//
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//int ai::SearchPlane1(int num_card)
//{
//	int num = num_card / 4;
//
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	int J = 0;
//	int temp_num = 1;
//
//	for (int i = temp_zero; i < 20 - num; i++) {
//		J = i;
//		temp_num = 1;
//		while (1) {
//			if (temp_card[J + 3] == temp_card[J] + 1 && temp_card[J] == temp_card[J + 1] && temp_card[J + 2] == temp_card[J + 1] && temp_card[J + 3] == temp_card[J + 4] && temp_card[J + 4] == temp_card[J + 5]) {
//				J += 3;
//				temp_num++;
//				if (temp_num == num) {
//					flag = 1;
//					break;
//				}
//			}
//			else {
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//	}
//
//	//比较大小
//	if (flag == 1) {
//		int temp_temp = 0;
//		for (int i = 0; i < 20; i++) {
//			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2]) {
//				temp_temp = temp[i];
//			}
//		}
//
//		if (temp_card[J - num * 3 + 1] <= temp_temp) {
//			flag = 0;
//		}
//	}
//
//
//
//
//	int j = 0;
//	int temp_single_num = 0;
//	int temp_J = temp_card[J];
//	if (flag == 1) {
//		for (int i = J + 2; i > J - num * 3; i--) {
//			temp_card[i] = 0;
//		}
//
//		for (int i = 0; i < 20; i++) {
//			if (temp_card[i] != 0 && temp_card[i] != 16 && temp_card[i] != 17) {
//				temp_single_num++;
//			}
//		}
//		if (temp_single_num < num) {
//			flag = 0;
//		}
//
//	}
//
//
//
//
//	if (flag == 1) {
//		ai_handcard_chu_[num * 3 - 1] = temp_J;
//		for (int i = num * 3 - 1; i > 0; i -= 3) {
//
//			ai_handcard_chu_[i - 3] = ai_handcard_chu_[i] - 1;
//
//			ai_handcard_chu_[i - 1] = ai_handcard_chu_[i];
//			ai_handcard_chu_[i - 2] = ai_handcard_chu_[i];
//
//		}
//
//		for (int i = J + 2; i > J - num * 3; i--) {
//			ai_handcard_[i] = 0;
//		}
//
//		int k = 0;
//		for (int i = 0; i < 20; i++) {
//			if (temp_card[i] != 0 && temp_card[i] != 16 && temp_card[i] != 17) {
//				ai_handcard_chu_[num * 3 + k] = temp_card[i];
//				ai_handcard_[i] = 0;
//				k++;
//				if (k == num) {
//					break;
//				}
//			}
//		}
//
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//int ai::SearchPlane2(int num_card)
//{
//	int num = num_card / 5;
//
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	int J = 0;
//	int temp_num = 1;
//
//	for (int i = temp_zero; i < 20 - num; i++) {
//		J = i;
//		temp_num = 1;
//		while (1) {
//			if (temp_card[J + 3] == temp_card[J] + 1 && temp_card[J] == temp_card[J + 1] && temp_card[J + 2] == temp_card[J + 1] && temp_card[J + 3] == temp_card[J + 4] && temp_card[J + 4] == temp_card[J + 5]) {
//				J += 3;
//				temp_num++;
//				if (temp_num == num) {
//					flag = 1;
//					break;
//				}
//			}
//			else {
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//	}
//
//	//比较大小
//	if (flag == 1) {
//		int temp_temp = 0;
//		for (int i = 0; i < 20; i++) {
//			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2]) {
//				temp_temp = temp[i];
//			}
//		}
//
//		if (temp_card[J - num * 3 + 1] <= temp_temp) {
//			flag = 0;
//		}
//	}
//
//
//	int j = 0;
//	int temp_double_num = 0;
//	int temp_J = temp_card[J];
//	if (flag == 1) {
//		for (int i = J + 2; i > J - num * 3; i--) {
//			temp_card[i] = 0;
//		}
//
//		for (int i = 0; i < 20; i++) {
//			if (temp_card[i] != 0 && temp_card[i + 1] == temp_card[i] && temp_card[i] != 16 && temp_card[i] != 17) {
//				temp_double_num++;
//				i++;
//			}
//		}
//		if (temp_double_num < num) {
//			flag = 0;
//		}
//
//	}
//
//
//
//
//
//	if (flag == 1) {
//		ai_handcard_chu_[num * 3 - 1] = temp_J;
//		for (int i = num * 3 - 1; i > 0; i -= 3) {
//
//			ai_handcard_chu_[i - 3] = ai_handcard_chu_[i] - 1;
//
//			ai_handcard_chu_[i - 1] = ai_handcard_chu_[i];
//			ai_handcard_chu_[i - 2] = ai_handcard_chu_[i];
//
//		}
//
//		for (int i = J + 2; i > J - num * 3; i--) {
//			ai_handcard_[i] = 0;
//		}
//
//		int k = 0;
//		for (int i = 0; i < 20; i++) {
//			if (temp_card[i] != 0 && temp_card[i + 1] == temp_card[i] && temp_card[i] != 16 && temp_card[i] != 17) {
//				ai_handcard_chu_[num * 3 + k] = temp_card[i];
//				ai_handcard_chu_[num * 3 + k + 1] = temp_card[i + 1];
//				ai_handcard_[i] = 0;
//				ai_handcard_[i + 1] = 0;
//				k += 2;
//				if (k == num * 2) {
//					break;
//				}
//			}
//		}
//
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//int ai::SearchSingle()
//{
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	for (int i = temp_zero; i < 20; i++) {
//		if (     temp_card[i]>temp[0]    &&temp_card[i] != temp_card[i + 1] && temp_card[i] != temp_card[i + 2] && temp_card[i] != 16 && temp_card[i] != 17) {
//			ai_handcard_[i] = 0;
//			ai_handcard_chu_[0] = temp_card[i];
//			flag = 1;
//		}
//	}
//
//	if (flag == 0) {
//		for (int i = temp_zero; i < 20; i++) {
//			if (temp_card[i] > temp[0]) {
//				ai_handcard_[i] = 0;
//				ai_handcard_chu_[0] = temp_card[i];
//				return 1;
//			}
//		}
//		return 0;
//	}
//	else {
//		return 1;
//	}
//
//
//}
//
//int ai::SearchDouble()
//{
//	int temp_card[20] = { 0 };
//	for (int i = 0; i < 20; i++) {
//		temp_card[i] = ai_handcard_[i];
//	}
//	int temp_zero = 0;
//	for (int i = 0; i < 20; i++) {
//		if (temp_card[i] == 0) {
//			temp_zero++;
//		}
//		else {
//			break;
//		}
//	}
//
//	int flag = 0;
//	for (int i = temp_zero; i < 20; i++) {
//		if (temp_card[i] > temp_card[0] && temp_card[i] == temp_card[i + 1] && temp_card[i] != temp_card[i + 2] ) {
//			ai_handcard_[i] = 0;
//			ai_handcard_[i+1] = 0;
//			ai_handcard_chu_[0] = temp_card[i];
//			ai_handcard_chu_[1] = temp_card[i+1];
//			flag = 1;
//		}
//	}
//
//	if (flag == 0) {
//
//		for (int i = temp_zero; i < 20; i++) {
//			if (temp_card[i] > temp[0] && temp_card[i] == temp_card[i + 1]) {
//				ai_handcard_[i] = 0;
//				ai_handcard_[i + 1] = 0;
//				ai_handcard_chu_[0] = temp_card[i];
//				ai_handcard_chu_[1] = temp_card[i + 1];
//				flag = 1;
//			}
//		}
//	}
//
//	if (flag == 0) {
//		return 0;
//	}
//	else {
//		return 1;
//	}
//}
//
//
//void ai::set_Boom()
//{
//	int j = 0;
//	int boom_num = 0;
//	for (int i = 4; i < 20; i++) {
//		if (ai_handcard_[i] == ai_handcard_[i - 1] && ai_handcard_[i - 1] == ai_handcard_[i - 2] && ai_handcard_[i - 2] == ai_handcard_[i - 3]) {
//
//			ai_handcard_[i] = 0;
//			ai_handcard_[i + 1] = 0;
//			ai_handcard_[i + 2] = 0;
//			ai_handcard_[i + 3] = 0;
//
//			ai_handcard_boom_[j] = ai_handcard_[i];
//			j++;
//			boom_num++;
//		}
//		else if (ai_handcard_[i] == 17 && ai_handcard_[i - 1] == 16) {
//			ai_handcard_boom_[j] = 16;
//			j++;
//			boom_num += 100;
//		}
//	}
//	
//	boom_num_=boom_num;
//}
//
//
//
////在这里写你的ai吧！
////记得把成员函数声明放进ai.h
////如果不知道怎么用多个文件的话先去百度一下捏
//
//
////提供了一个出牌种类的表，为tempFunction的值
//// 
////
////#include"function.h"
////#include"player.h"
////#include"ai.h"
////#include"draw.h"
////using namespace std;
////
////void ai::test_set_card_num(int a) {
////	handCard_num = a;
////}
//////int counter = 0;
////void ai:: set_Handcard_Num(){
////	if (ifLandlord == 0) {
////		handCard_num = 17;
////	}
////	else {
////		handCard_num = 20;
////	}
////}
////int ai::get_Handcard_Num() {
////	return handCard_num;
////}
////int ai::getLL() { return ifLandlord; }
////int* ai::get_Hand() { return handCard; }
////void ai::set_LL(int a) { ifLandlord = a; }
////
////
////
////void ai::set_Left_Right(int a) {
////	left_right_ = a;
////}
////
////
//////排序函数
////void ai::Order() {
////	int min;
////	int temp;
////	for (int j = 0; j < 20; j++) {
////		min = 100;
////		temp = 0;
////		for (int i = j; i < 20; i++) {
////			if (handCard[i] < min) {
////				min = handCard[i];
////				temp = i;
////			}
////		}
////		swap(handCard[j], handCard[temp]);
////	}
////}
//////设置手牌
////void ai::set_Card(int* a)
////{
////	int j = 0;
////	for (int i = 0; i < 17; i++) {
////		handCard[i] = a[i];
////	}
////
////}
//////设置地主牌
////void ai::set_LLcard(int* a)
////{
////	for (int i = 0; i < 3; i++) {
////		handCard[i] = a[i];
////	}
////}
////
////void ai::Order_temp() {
////	int temp_zero = 0;
////	for (int i = 0; i < 20; i++)
////	{
////		if (temp[i] != 0)
////			temp_zero++;
////	}
////
////	int temp_temp[20] = { 0 };
////	for (int i = 0; i < 20; i++)
////	{
////		temp[i] = temp_temp[i + temp_zero];
////	}
////
////}
////
////void ai::pass()
////{
////
////};
////void ai::countt()
////{
////	int countte = 0;
////	for (int i = 0; i < 20; i++)
////	{
////		if (temp[i] != 0)
////			countte++;
////	}
////	counter = countte;
////};
////
////
////
////void ai::chuCard()
////
////{
////
////	countt();
////	if (counter > 8)
////	{
////		searchboom();
////		Order();
////
////
////	}
////	else if (counter == 1)
////	{
////		searchsingle2();
////		Order();
////
////	
////	}
////	else {
////		if (left_right_ == -1) {
////			Ai_Left_Buchu();
////		}
////		else  if (left_right_ == 1) {
////			Ai_Right_Buchu();
////		}
////		tempchu++;
////	}
////
////
////
////}
////void ai::searchsingle2()
////{
////	int flag = 0;
////	for (int i = 0; i < 20; i++)
////	{
////		if (handCard[i] > temp[0])
////		{
////			temp[0] = handCard[i];
////			counter = 1;
////			handCard[i] = 0;
////
////			handCard_num--;
////
////			if (left_right_ == -1) {
////				Ai_Left_Chu(temp, handCard_num);
////			}
////			else  if (left_right_ == 1) {
////				Ai_Right_Chu(temp, handCard_num);
////			}
////			tempchu = 0;
////			flag = 1;
////			break;
////		}
////	}
////
////	if (flag == 0) {
////		if (left_right_ == -1) {
////			Ai_Left_Buchu();
////		}
////		else  if (left_right_ == 1) {
////			Ai_Right_Buchu();
////		}
////		tempchu++;
////	}
////}
////void ai::searchboom()
////{
////	for (int i = 0; i < 17; i++)
////	{
////		if (0 != handCard[i] && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2] && handCard[i + 2] == handCard[i + 3])
////		{
////			for (int i = 0; i < 20; i++)
////			{
////				temp[i] = 0;
////			}
////			temp[0] = temp[1] = temp[2] = temp[3] = handCard[i];
////			counter = 4;
////
////			if (left_right_ == -1) {
////				Ai_Left_Chu(temp, handCard_num);
////			}
////			else  if (left_right_ == 1) {
////				Ai_Right_Chu(temp, handCard_num);
////			}
////
////			break;
////		}
////		else {
////			if (left_right_ == -1) {
////				Ai_Left_Buchu();
////			}
////			else  if (left_right_ == 1) {
////				Ai_Right_Buchu();
////			}
////		}
////			
////	}
////}
////
////void ai::chuCardFirst()
////{
////
////	for (int i = 0; i < 20; i++) {
////		temp[i] = 0;
////	}
////
////	//查看有没有飞机牌并打出；
////	searchplane();
////
////
////	if (temp[0] == 0) {
////		searchsingle();
////		handCard_num--;
////		if (left_right_ == -1) {
////			Ai_Left_Chu(temp, handCard_num);
////		}
////		else  if (left_right_ == 1) {
////			Ai_Right_Chu(temp, handCard_num);
////		}
////
////
////
////	}
////
////
////	tempchu = 0;
////
////
////
////}
////void ai::searchsingle()
////{
////	counter = 1;
////	/*int newcard[20] = { 0 }; int a = 0; int counter = 0;*/
////	for (int i = 0; i < 20; i++)
////	{
////		if (handCard[i] != 0) {
////			temp[0] = handCard[i];
////			handCard[i] = 0;
////			Order();
////			break;
////		}
////	}
////};
////
////void ai::searchplane()
////{
////	int y[10] = { 0 };//用来暂存飞机牌
////	int newcard[20] = { 0 }; int a = 0;
////	for (int i = 0; i < 20; i++)
////	{
////		newcard[i] = handCard[i];
////	}
////	/*for (int i = 0; i < 20; i++)
////	{
////		cout<<newcard[i];
////	}*/
////
////	for (int i = 0; i < 20; i++)
////	{
////		bool flag = 0;
////		if (0 != newcard[i] && newcard[i] == newcard[i + 1] && newcard[i + 1] == newcard[i + 2] /*&& newcard[i] != newcard[i + 3]*/)
////		{
////			/*cout << "有三张一样的" << i;*/
////			if (newcard[i] + 1 == newcard[i + 3] && newcard[i + 3] == newcard[i + 4] && newcard[i + 4] == newcard[i + 5]) { cout << "可以出飞机"; flag = 1; }
////
////		}
////		if (flag == 1)
////		{
////			for (int j = i; j < i + 6; j++)
////			{
////				int n = 0;
////				y[n] = newcard[j];
////				handCard[j] = 0; newcard[j] = 0; n++;
////			}
////			Order();
////			/*选择飞机并出牌（这里没有考虑到有三个的飞机）*/
////			//此时要寻找两张单牌(不考虑带两个对子）
////			for (int j = 1; j < 15; j++)
////			{
////				if (newcard[j] != 0 && newcard[j] != newcard[j - 1] && newcard[j] != newcard[j + 1])
////				{
////					y[6] = newcard[j]; handCard[j] = 0; newcard[j] = 0;
////					for (int j = 1; j < 15; j++)
////					{
////						if (newcard[j] != 0 && newcard[j] != newcard[j - 1] && newcard[j] != newcard[j + 1])
////						{
////							y[7] = newcard[j]; handCard[j] = 0; newcard[j] = 0; a = 1;
////							break;
////						}
////						else
////						{
////							if (newcard[j] != 0)
////								y[7] = newcard[j]; handCard[j] = 0; newcard[j] = 0; a = 1;
////							break;
////						}
////					}
////				}
////				else
////				{
////					if (newcard[j] != 0)
////					{
////						y[6] = newcard[j]; y[7] = newcard[j + 1];
////						handCard[j] = 0; handCard[j + 1] = 0; a = 1;
////					}
////				}
////				if (a == 1)
////				{
////					for (int i = 0; i < 20; i++)//排序暂存牌组；
////					{
////						temp[i] = y[i];
////					}
////
////					for (int i = 0; i < 20 - 1; i++)
////					{
////						for (int j = 0; j < 20 - 1 - i; j++)
////							if (temp[j] > temp[j + 1])
////							{
////								int t = temp[j];
////								temp[j] = temp[j + 1];
////								temp[j + 1] = t;
////							}
////					}
////
////					Order_temp();
////
////
////
////					for (int i = 0; i < 20; i++)
////					{
////						if (temp[i] != 0)
////							counter++;
////					}
////					break;
////				}
////
////			}
////
////			break;
////		}
////	}
////
////	;
////}




//提供了一个出牌种类的表，为tempFunction的值

//
#include"function.h"
#include"player.h"
#include"ai.h"
#include"draw.h"
using namespace std;


//int counter = 0;
void ai::set_Handcard_Num() {
	if (ifLandlord == 0) {
		handCard_num = 17;
	}
	else {
		handCard_num = 20;
	}
}
int ai::get_Handcard_Num() {
	return handCard_num;
}
int ai::getLL() { return ifLandlord; }
int* ai::get_Hand() { return handCard; }
void ai::set_LL(int a) { ifLandlord = a; }



void ai::set_Left_Right(int a) {
	left_right_ = a;
}

//设置手牌
void ai::set_Card(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}
//设置地主牌
void ai::set_LLcard(int* a)
{
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}


void ai::Order() {
	int min;
	int tem;
	for (int j = 0; j < 20; j++) {
		min = 100;
		tem = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				tem = i;
			}
		}
		swap(handCard[j], handCard[tem]);
	}
}



void ai::Order_temp() {

	for (int i = 0; i < 20 - 1; i++)
	{
		for (int j = 0; j < 20 - 1 - i; j++)
			if (temp[j] > temp[j + 1])
			{
				int t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
	}

	int temp_zero = 0;

	for (int i = 0; i < 20; i++)
	{
		if (temp[i] == 0)
			temp_zero++;
	}

	int temp_temp[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		temp_temp[i] = temp[i];
	}
	for (int i = 0; i < 20; i++)
	{
		temp[i]=0;
	}
	for (int i = 0; i+temp_zero < 20; i++)
	{
		temp[i] = temp_temp[i + temp_zero];
	}

}




void ai::countt()
{
	int countte = 0;
	for (int i = 0; i < 20; i++)
	{
		if (temp[i] != 0)
			countte++;
	}
	counter = countte;
};
void ai::count_handcard()
{
	int countte = 0;
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] != 0)
			countte++;
	}
	handCard_num = countte;
}



//void ai::pass()
//{
//
//};



void ai::searchsingle2()
{
	int flag = 0;
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] > temp[0])
		{
			temp[0] = handCard[i];
			counter = 1;
			handCard[i] = 0;
			
			
			tempchu = 0; Order(); Order_temp(); count_handcard();
			if (left_right_ == -1) {
				Ai_Left_Chu(temp, handCard_num);
			}
			else  if (left_right_ == 1) {
				Ai_Right_Chu(temp, handCard_num);
			}
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		if (left_right_ == -1) {
			Ai_Left_Buchu();
		}
		else  if (left_right_ == 1) {
			Ai_Right_Buchu();
		}
		tempchu++; Order(); Order_temp(); count_handcard();
	}
}
void ai::searchboom()
{
	bool a = 0;
	for (int i = 0; i < 17; i++)
	{
		if (0 != handCard[i] && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2] && handCard[i + 2] == handCard[i + 3])
		{

			if (temp[0] + temp[1] > 30 || (handCard[i] < temp[0] && (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])))
			{
				endbuchu(); break;
			}
			else
			{
				for (int i = 0; i < 20; i++)
				{
					temp[i] = 0;
				}
				temp[0] = temp[1] = temp[2] = temp[3] = handCard[i];
				handCard[i] = handCard[i + 1] = handCard[i + 2] = handCard[i + 3] = 0;
				Order(); Order_temp(); count_handcard(); endchu();
				break;
			}
		}
		if (i == 16)
			a = 1;
		if (a == 1)
		{
			endbuchu();
			Order(); Order_temp(); count_handcard();
		}

	}
}


void ai::endchu()
{
	if (left_right_ == -1) {
		Ai_Left_Chu(temp, handCard_num);
	}
	else  if (left_right_ == 1) {
		Ai_Right_Chu(temp, handCard_num);
	}
	tempchu = 0;

}
void ai::endbuchu()
{
	if (left_right_ == -1) {
		Ai_Left_Buchu();
	}
	else  if (left_right_ == 1) {
		Ai_Right_Buchu();
	}
	tempchu++;
}

void ai::chuCard()
{
	countt();

	if (counter >= 6)
	{
		searchboom();
		Order();
	}
	if (counter == 1)
	{
		searchsingle2();
		Order();
	}
	if (counter == 2)
	{
		if (temp[0] + temp[1] == 33)
		{
			endbuchu();
		}
		else
			for (int i = 0; i < 20; i++)
			{
				if (handCard[i] == handCard[i + 1] && handCard[i] > temp[0])
				{
					temp[0] = temp[1] = handCard[i]; handCard[i] = handCard[i + 1] = 0;
					Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
				}
				if (i == 19)
				{
					searchboom(); break;
				}
			}
	}
	if (counter == 3)
	{
		for (int i = 0; i < 20; i++)
		{
			if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i] == handCard[i + 2] && handCard[i] > temp[0])
			{
				temp[0] = temp[1] = temp[3] = handCard[i];
				handCard[i] = handCard[i + 1] = handCard[i + 2] = 0;
				Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
			}
			if (i == 17)
			{
				searchboom(); break;
			}
		}
	}
	if (counter == 4)
	{
		if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])
		{
			searchboom();
		}
		else if ((temp[0] == temp[1] && temp[1] == temp[2])|| (temp[1] == temp[2] && temp[3] == temp[2]))
		{
			int max1 = temp[1]; int z = 0;
			for (int i = 0; i < 18; i++)
			{
				if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2] && handCard[i] > max1)
				{
					z = 1;
					temp[0] = handCard[i]; temp[1] = handCard[i + 1]; temp[2] = handCard[i + 2];
					handCard[i] = 0; handCard[i + 1] = 0; handCard[i + 2] = 0;
					Order();
					for (int j = 0; j < 20; j++)
					{
						if (handCard[j] != 0 && handCard[j] != handCard[j - 1] && handCard[j] != handCard[j + 1])
						{
							temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
						}
						else if (j == 19)
						{
							for (int i = 0; i < 20; i++)
							{
								if (handCard[i] != 0) {
									temp[3] = handCard[i];
									handCard[i] = 0; break;
								}
							}
							Order(); Order_temp(); countt(); count_handcard(); endchu(); break;
						}
					}

				}if (z == 1)break;
				

			}
			if (z == 0) { searchboom(); }
		}

	}
	if (counter == 5)
	{
		if ((temp[0] == temp[1] && temp[1] == temp[2]) || (temp[2] == temp[3] && temp[3] == temp[4]))
		{
			searchboom();//未完善
		}
		else if (temp[0] + 1 == temp[1] && temp[1] + 1 == temp[2])
		{
			searchboom();//未完善
		}
	}
}



void ai::chuCardFirst()
{
	//清空temp数组
	for (int i = 0; i < 20; i++)
	{
		temp[i] = 0;
	}
	//改变暂存数组则出牌，不改变则继续扫描
	//查看有没有飞机牌并打出；
	searchplane();
	//连对
	if (temp[0] == 0)
		searchliandui();
	//顺子
	if (temp[0] == 0)
		searchshunzi();
	//三带一，二
	if (temp[0] == 0)
		searchsandaiyi();
	////对子
	 if (temp[0] == 0)
		searchduizi();
	////单牌
	if (temp[0] == 0)
		searchsingle();

	//出牌函数，改变tempchu
	endchu();



}

void ai::searchplane()
{
	bool flag = 0;
	int y[20] = { 0 };//用来暂存飞机牌
	int newcard[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		newcard[i] = handCard[i];
	}
	for (int i = 0; i < 20; i++)
	{
		
		if (0 != newcard[i] && newcard[i] == newcard[i + 1] && newcard[i + 1] == newcard[i + 2] /*&& newcard[i] != newcard[i + 3]*/)
		{
			/*cout << "有三张一样的" << i;*/
			if (newcard[i] + 1 == newcard[i + 3] && newcard[i + 3] == newcard[i + 4] && newcard[i + 4] == newcard[i + 5]) { cout << "可以出飞机"; flag = 1; }

		}
		if (flag == 1)
		{
			int n = 0;
			for (int j = i; j < i + 6; j++)
			{
				
				y[n] = newcard[j];
				handCard[j] = 0; newcard[j] = 0; n++;
			}
			Order();
			/*选择飞机并出牌（这里没有考虑到有三个的飞机）*/
			//此时要寻找两张单牌(不考虑带两个对子）
			for (int j = 1; j < 20; j++)
			{/*
				if (newcard[j] != 0 && newcard[j] != newcard[j - 1] && newcard[j] != newcard[j + 1])
				{
					y[6] = newcard[j]; handCard[j] = 0; newcard[j] = 0;
					for (int j = 1; j < 15; j++)
					{
						if (newcard[j] != 0 && newcard[j] != newcard[j - 1] && newcard[j] != newcard[j + 1])
						{
							y[7] = newcard[j]; handCard[j] = 0; newcard[j] = 0; a = 1;
							break;
						}
						else
						{
							if (newcard[j] != 0)
								y[7] = newcard[j]; handCard[j] = 0; newcard[j] = 0; a = 1;
							break;
						}
					}
				}
				else
				{*/
					if (newcard[j] != 0)
					{
						y[6] = newcard[j]; y[7] = newcard[j + 1];
						handCard[j] = 0; handCard[j + 1] = 0;
					}
				/*}*/
				if (flag == 1)
				{
					for (int i = 0; i < 20; i++)//排序暂存牌组；
					{
						temp[i] = y[i];
					}

					for (int i = 0; i < 20 - 1; i++)
					{
						for (int j = 0; j < 20 - 1 - i; j++)
							if (temp[j] > temp[j + 1])
							{
								int t = temp[j];
								temp[j] = temp[j + 1];
								temp[j + 1] = t;
							}
					}

					Order_temp();



					for (int i = 0; i < 20; i++)
					{
						if (temp[i] != 0)
							counter++;
					}
					break;
				}

			}

			break;
		}
	}

	;
}
void ai::searchliandui()
{
	int newcard[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		newcard[i] = handCard[i];
	}
	for (int i = 0; i < 15; i++)
	{
		if (newcard[i] != 0 && newcard[i] == newcard[i + 1] && newcard[i] + 1 == newcard[i + 2] && newcard[i + 2] == newcard[i + 3] && newcard[i + 2] + 1 == newcard[i + 4] && newcard[i + 4] == newcard[i + 5])
		{
			int n = 0;
			for (int j = i; j < i + 6; j++)
			{
				 temp[n] = newcard[j]; handCard[j] = 0;
				n++;
			}
			Order();
			Order_temp();
			countt();
			count_handcard(); break;
		}

	}

};
void ai::searchshunzi()
{
	
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

	for (int i = 0; i + temp_zero < 40; i++)
	{
		store[i] = temp_temp[i + temp_zero];
	}
	for (int j = 0; j < 20; j++)
	{
		handCard[j] = store[j];
	}
	Order(); Order_temp(); countt(); count_handcard();

}
void ai::searchsandaiyi()
{
	for (int i = 0; i < 18; i++)
	{
		if (handCard[i] != 0 && handCard[i] == handCard[i + 1] && handCard[i + 1] == handCard[i + 2])
		{
			temp[0] = handCard[i]; temp[1] = handCard[i + 1]; temp[2] = handCard[i + 2];
			handCard[i] = 0; handCard[i + 1] = 0; handCard[i + 2] = 0;
			Order();
			for (int j = 0; j < 19; j++)
			{
				if (handCard[j] != 0 && handCard[j] != handCard[j - 1] && handCard[j] != handCard[j + 1])
				{
					temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard(); break;
				}
				if(j==18)
				{
					for (int j = 0; j < 19; j++)
					{
						if(handCard!=0){ temp[3] = handCard[j]; handCard[j] = 0; Order(); Order_temp(); countt(); count_handcard(); break; }
					}
				}
			}
			break;
		}

	}
}
void ai::searchduizi()
{
	for (int i = 0; i < 19; i++)
	{
		if (handCard[i] != 0 && handCard[i] == handCard[i + 1])
		{
			temp[i] = handCard[i]; temp[i + 1] = handCard[i + 1];
			handCard[i] = 0; handCard[i + 1] = 0;
			Order(); Order_temp(); countt(); count_handcard(); break;
		}
	}
};
void ai::searchsingle()
{
	for (int i = 0; i < 20; i++)
	{
		if (handCard[i] != 0)
		{
			temp[0] = handCard[i];
			handCard[i] = 0;
			Order(); Order_temp(); countt(); count_handcard();
			break;
		}
	}
};


