#include <iostream>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	string Key, RepeatKey, Text, Cipher; // Ключ, Ключ с повторением, исходный текст
	//Чтение текстового файла и запись его содержимого в строку для исходного текста
	ifstream F, P;
	F.open("C:\\Vigenere\\Input.txt", ios::in);
	if (F.is_open())
		while (!F.eof())
			getline(F, Text);
	F.close();
	cout << "Текст из файла: " << endl << Text << endl;
	//Чтение текстового файла и запись его содержимого в строку для ключа
	P.open("C:\\Vigenere\\Key.txt", ios::in);
	P >> Key;
	P.close();
	cout << "Ключ из файла: " << endl << Key << endl;
	//Изменение регистра исходного текста и ключа (способ R=1)
	transform(Text.begin(), Text.end(), Text.begin(), ::toupper);
	transform(Key.begin(), Key.end(), Key.begin(), ::tolower);
	cout << "Измененный регистр текста и ключа (способ R=1):" << endl;
	cout << "Исходный текст:" << endl << Text << endl;
	cout << "Ключ:" << endl << Key << endl;
	//Перевернем ключ задом на перед
	//в соответствии со способом (P=2)
	reverse(Key.begin(), Key.end());
	cout << "Ключ задом на перед (способ P=2): " << endl << Key << endl;
	//Ключ с повторением 
	for (size_t i = 0; i < Text.size(); i++)
	{
		RepeatKey += Key[i % Key.size()];
	}
	cout << "Ключ с повторением: " << endl << RepeatKey << endl;
	//Шифрование исходного текста
	   //по формуле: С = T + K (mod 26) , где С - зашифрованный символ, T - символ исходного текста, K - символ ключа
		for (int i = 0; i < Text.size(); i++)
		{
			if (Text[i] == ' ')
			{
				Cipher += ' ';
			}
			else
			{
				Cipher += (char)((((int)Text[i]) + ((int)RepeatKey[i] - 32)) % 26) + 65;
			}
		}
	cout << "Зашифрованный текст: " << endl << Cipher << endl;
	//Запись зашифрованного текста в файл
	ofstream L;
	L.open("C:\\Vigenere\\Output.txt", ios::out);
	L << Cipher;
	L.close();
	_getch();
}
