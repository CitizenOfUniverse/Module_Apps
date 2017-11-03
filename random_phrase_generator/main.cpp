#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;

const int parts_of_phrase = 6, dict_size = 7;

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(0));

	char* array[parts_of_phrase][dict_size] = { { "������� ", "�������� ", "", "�������������� ", "", "���������� ", "" },
	{"�������� ", "������ ", "���������� ", "����������� ", "���������� ", "�������� ", "������� "},
	{"������������ ", "��������������� ", "����������� ", "��� ����� �������� ", "��������� ", "", "��������� ����� "},
	{"����� ", "���������� ", "������������� ", "������� ", "����������� ���� ����� ", "��������� �� ���� ", "������� �� ��� ��� �� "},
	{"������������ ��������. ", "����������. ", "���������� � ������. ", "������. ", "�������� ����������. ", "��������. ", "�������. "},
	{"Puma", "Adidas", "Microsoft", "��������", "��������", "���������� ���� ������", "Dior Homme"} };

	bool flag_quit = false;
	do{
		cout << "������ ���� ";
		for (int i = 0; i < parts_of_phrase; i++){
			int j = rand() % dict_size;
			cout << array[i][j];
		}

		cout << endl << endl;
		cout << "������������� ��� ���� ������ (Y/N)? ";
		char user_input;
		cin >> user_input;
		if (user_input == 'N' || user_input == 'n'){
			flag_quit = true;
		}
		
	} while (!flag_quit);

	return 0;
}

