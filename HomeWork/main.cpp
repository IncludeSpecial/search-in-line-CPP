#pragma execution_character_set("1251")
#include <fstream>      
#include <string>       
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	string s = "�����";
	string line; // ������ �� �����
	string fileName = "file.txt";
	int lineNum = 0;
	bool found = false;

	ifstream file(fileName);
	if (file.is_open()) {
		cout << "\t\t|���� ������|" << endl;
		cout << "����� ��� ������: \"" << s << "\"" << endl;
		while (getline(file, line)) {
			lineNum++;
			if (line.find(s) != string::npos) {
				cout << "����� ������: " << lineNum << " \| -  " << line << endl;
				found = true;
			}
		}
		file.close();
		if (!found) {
			cout << "�� ���������� \" " << s << " \" ������ �� �������." << endl;
		}
	}
	else if (!file.is_open()) cout << "\t|�� ������� ������� ����|" << endl;
	else cout << "\t\t|���� ������|" << endl;

	return 0;
}
