#include <iostream>
#include <fstream>      //для работы с файлами
#include <string>       //для работы со строками

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    string s = "све";                 // (символ\слово\слог) строка для поиска 
    string line; // строка из файла
    string fileName = "file.txt";       //название файла

    int lineNum = 0;                    // для вывода номера строки
    bool found = false;                 // если ничего не найденно
    ifstream file(fileName);            // открытие файла


    if (file.is_open()) {               // проверка на успешное открытие файла
        cout << "\t\t|Файл открыт|" << endl;
        cout << "Cлово для поиска: "<<s <<endl;
        while (getline(file, line)) {               // считывание каждой строки из файла
            lineNum++;
            if (line.find(s) != string::npos) {     // если строка содержит искомую подстроку
                cout << "Номер строки: " << lineNum << "  \| " << line << endl; // вывод строки на экран
                found = true;
            }
        }
        file.close();                   // закрытие файла

        if (!found) {
            cout << "По результату \" " << s <<" \" ничего не найденно." << endl; // Вывод результата
        }
    }
    else if (!file.is_open()) {
        cout << "\t|Не удалось открыть файл|" << endl;      // вывод сообщения об ошибке
    }
    else cout << "\t\t|Файл закрыт|" << endl;

    return 0;
}
