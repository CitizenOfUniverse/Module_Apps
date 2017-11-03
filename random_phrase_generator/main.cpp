#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;

const int parts_of_phrase = 6, dict_size = 7;

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(0));

	char* array[parts_of_phrase][dict_size] = { { "быстрая ", "безумная ", "", "ортодоксальная ", "", "мнительная ", "" },
	{"уборщица ", "медуза ", "подписчица ", "императрица ", "сотрудница ", "гармония ", "Кхалиси "},
	{"самозабвенно ", "профессионально ", "бессовестно ", "без капли сомнения ", "осторожно ", "", "чертовски круто "},
	{"крадёт ", "симулирует ", "эксплуатирует ", "изучает ", "превозносит выше всего ", "выпускает на волю ", "смотрит на вас как на "},
	{"воинственных монстров. ", "архангелов. ", "вьетнамцев в кустах. ", "друзей. ", "крылатых осьминогов. ", "демидрол. ", "леминга. "},
	{"Puma", "Adidas", "Microsoft", "Сколково", "Пятёрочка", "Пенсионный фонд России", "Dior Homme"} };

	bool flag_quit = false;
	do{
		cout << "Только наша ";
		for (int i = 0; i < parts_of_phrase; i++){
			int j = rand() % dict_size;
			cout << array[i][j];
		}

		cout << endl << endl;
		cout << "Сгенерировать еще один слоган (Y/N)? ";
		char user_input;
		cin >> user_input;
		if (user_input == 'N' || user_input == 'n'){
			flag_quit = true;
		}
		
	} while (!flag_quit);

	return 0;
}

