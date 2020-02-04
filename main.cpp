#include <iostream>
#include <cstring>
#include "Country.h"
using namespace std;
const int MAX = 30;

int main() {
	cout << "2018 ������ ������ �߿� �ִ� �� ���� ����Ͻðڽ��ϱ�? ";
	int size, choice, i = 0;
	cin >> size;
	Country* c = new Country[size];
	int count = 0;
	while (true) {
		cout << "------------------MENU------------------" << endl;
		cout << "1.(������)" << endl;
		cout << "2.(�����ױ�)" << endl;
		cout << "3.(16�����ⱹ��ȸ)" << endl;
		cout << "4.(���α׷�����)" << endl;
		cout << "����: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (i == size) {
				cout << "����� �� �ִ� �ִ� ������ ������ �ʰ��մϴ�!" << endl;
				break;
			}
			cout << "�����̸� �Է�: ";
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
				printf("�ߺ��� ���� �̸� ����!\n");
			}
			break;
		case 2:
			if (c->CountryName == NULL) {
				cout << "�������� �ʴ� ���� �̸��Դϴ�." << endl;
				break;
			}
			else {
				cout << "���� �߰��� ���� �����̸� �Է�: ";
				char name[MAX];
				cin >> name;
				int count = 0;
				for (int i = 0; i < size; i++) {
					if (strcmp(c[i].CountryName, name) == 0) {
						cout << "�߰��� ���� ����Ʈ : ";
						int point;
						cin >> point;
						c[i].setPoints(point);
						break;
					}
					else count++;
					printf("%d\n", count);
				}
				if (count == size) {
					cout << "�������� �ʴ� ���� �̸��Դϴ�." << endl;
				}
			}
			break;
		case 3:
			cout << "--�����̸�--����--" << endl;
			for (int i = 0; i < size; i++) {
				if (c[i].Points >= 6) {
					c[i].Print();
				}
			}
			break;
		case 4:
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�!" << endl;
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