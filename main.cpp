#include <iostream>
#include <cstring>
#include "Country.h"
using namespace std;
const int MAX = 30;

int main() {
	cout << "2018 월드컵 참가국 중에 최대 몇 나라를 등록하시겠습니까? ";
	int size, choice, i = 0;
	cin >> size;
	Country* c = new Country[size];
	int count = 0;
	while (true) {
		cout << "------------------MENU------------------" << endl;
		cout << "1.(나라등록)" << endl;
		cout << "2.(승점쌓기)" << endl;
		cout << "3.(16강진출국조회)" << endl;
		cout << "4.(프로그램종료)" << endl;
		cout << "선택: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (i == size) {
				cout << "등록할 수 있는 최대 나라의 개수를 초과합니다!" << endl;
				break;
			}
			cout << "나라이름 입력: ";
			char name[MAX];
			cin >> name;
			if (i == 0) {
				c[0].setCountryName(name);
				i++;
				break;
			}
			count = 0;
			for (int j = 0; j < i; j++) {
				if (strcmp(c[j].CountryName, name) == 0) {
					count++;
				}
			}
			if (count == 0) {
				c[i].setCountryName(name);
				i++;
			}
			else {
				printf("중복된 나라 이름 존재!\n");
			}
			break;
		case 2:
			if (c->CountryName == NULL) {
				cout << "존재하지 않는 나라 이름입니다." << endl;
				break;
			}
			else {
				cout << "승점 추가를 위한 나라이름 입력: ";
				char name[MAX];
				cin >> name;
				int count = 0;
				for (int i = 0; i < size; i++) {
					if (strcmp(c[i].CountryName, name) == 0) {
						cout << "추가할 승점 포인트 : ";
						int point;
						cin >> point;
						c[i].setPoints(point);
						break;
					}
					else count++;
					printf("%d\n", count);
				}
				if (count == size) {
					cout << "존재하지 않는 나라 이름입니다." << endl;
				}
			}
			break;
		case 3:
			cout << "--나라이름--승점--" << endl;
			for (int i = 0; i < size; i++) {
				if (c[i].Points >= 6) {
					c[i].Print();
				}
			}
			break;
		case 4:
			break;
		default:
			cout << "잘못 입력하셨습니다!" << endl;
			break;
		}
		if (choice == 4) {
			break;
		}
	}
	if (c) {
		delete[] c;
		c = NULL;
	}
	return 0;
}