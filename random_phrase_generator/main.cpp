#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;

//Warning! This application uses Windows' Cyrillic!

const int parts_of_phrase = 6, dict_size = 7;

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(0));

	char* array[parts_of_phrase][dict_size] = { { "áûñòðàÿ ", "áåçóìíàÿ ", "", "îðòîäîêñàëüíàÿ ", "", "ìíèòåëüíàÿ ", "" },
	{"óáîðùèöà ", "ìåäóçà ", "ïîäïèñ÷èöà ", "èìïåðàòðèöà ", "ñîòðóäíèöà ", "ãàðìîíèÿ ", "Êõàëèñè "},
	{"ñàìîçàáâåííî ", "ïðîôåññèîíàëüíî ", "áåññîâåñòíî ", "áåç êàïëè ñîìíåíèÿ ", "îñòîðîæíî ", "", "÷åðòîâñêè êðóòî "},
	{"êðàä¸ò ", "ñèìóëèðóåò ", "ýêñïëóàòèðóåò ", "èçó÷àåò ", "ïðåâîçíîñèò âûøå âñåãî ", "âûïóñêàåò íà âîëþ ", "ñìîòðèò íà âàñ êàê íà "},
	{"âîèíñòâåííûõ ìîíñòðîâ. ", "àðõàíãåëîâ. ", "âüåòíàìöåâ â êóñòàõ. ", "äðóçåé. ", "êðûëàòûõ îñüìèíîãîâ. ", "äåìèäðîë. ", "ëåìèíãà. "},
	{"Puma", "Adidas", "Microsoft", "Ñêîëêîâî", "Ïÿò¸ðî÷êà", "Ïåíñèîííûé ôîíä Ðîññèè", "Dior Homme"} };

	bool flag_quit = false;
	do{
		cout << "Òîëüêî íàøà ";
		for (int i = 0; i < parts_of_phrase; i++){
			int j = rand() % dict_size;
			cout << array[i][j];
		}

		cout << endl << endl;
		cout << "Ñãåíåðèðîâàòü åùå îäèí ñëîãàí (Y/N)? ";
		char user_input;
		cin >> user_input;
		if (user_input == 'N' || user_input == 'n'){
			flag_quit = true;
		}
		
	} while (!flag_quit);

	return 0;
}

