#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;

const int N = 5, M = 6;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	char* array[N][M] = { { "метафизическая ", "", "", "мёртвая ", "", ""},
	{"русалка ", "кошкотянка ", "мышка норушка ", "соечка ", "картонная невеста ", "принцесса "},
	{"", "профессионально ", "", "отчаянно и безрассудно ", "", ""},
	{"крадёт ", "рисует ", "создаёт нейросеть, которая имитирует ", "изучает ", "выдумывает ", "варит "},
	{"дефолт", "струны Бытия", "мемы", "друзей", "духов из костра", "сырую нефть и липовый мёд"} };

	bool flag = 1;
	do {
		for (int i = 0; i < N; i++) {
			int j = rand() % 6;
			cout << array[i][j];
		}

		cout << endl << endl;

		char user_input;
		cin >> user_input;

		if (user_input == 'e')
			flag = 0;
		
	} while (flag);

	return 0;
}

