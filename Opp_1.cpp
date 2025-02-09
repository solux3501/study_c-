#include <iostream>
#include <cstring>

using namespace std;
const int name_len = 20;

//함수 선언
void ShowMenu(void);
void MakeAccount(void);
void input_Money(void);
void output_Money(void);
void Show_Info(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int ID;
	int balance;
	char name[name_len];
} Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE :
			MakeAccount();
			break;
		case DEPOSIT :
			input_Money();
			break;
		case WITHDRAW :
			output_Money();
			break;
		case INQUIRE :
			Show_Info();
			break;
		case EXIT:
			return 0;
		default :
			cout << "Illegal selection..." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[name_len];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum].ID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].name, name);
	accNum++;
}
void input_Money(void)
{
	int money;
	int id;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].ID == id)
		{
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}
void output_Money(void)
{
	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].ID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}
void Show_Info(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].ID << endl;
		cout << "이  름: " << accArr[i].name << endl;
		cout << "잔  액: " << accArr[i].balance << endl << endl;
	}
}