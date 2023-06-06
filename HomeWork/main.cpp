#pragma execution_character_set("1251")
#include <fstream>      
#include <string>       
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	string s = "кругу";
	string line; // строка из файла
	string fileName = "file.txt";
	int lineNum = 0;
	bool found = false;

	ifstream file(fileName);
	if (file.is_open()) {
		cout << "\t\t|Файл открыт|" << endl;
		cout << "Слова для поиска: \"" << s << "\"" << endl;
		while (getline(file, line)) {
			lineNum++;
			if (line.find(s) != string::npos) {
				cout << "Номер строки: " << lineNum << " \| -  " << line << endl;
				found = true;
			}
		}
		file.close();
		if (!found) {
			cout << "По результату \" " << s << " \" ничего не найдено." << endl;
		}
	}
	else if (!file.is_open()) cout << "\t|Не удалось открыть файл|" << endl;
	else cout << "\t\t|Файл закрыт|" << endl;

	return 0;
}
