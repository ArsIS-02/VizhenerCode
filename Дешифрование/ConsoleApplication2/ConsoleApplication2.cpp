// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
void main ()
{
	setlocale(LC_ALL, "Russian");
	string Key, RepeatKey, Cipher, DeCipher; // Ключ, Ключ с повторением, зашифрованный текст, расшифрованный текст
	//Чтение текстового файла и запись его содержимого в строку для зашифрованного текста
	fstream F, P, L;
	F.open("C:\\Vigenere\\Output.txt", ios::in);
	if (F.is_open())
		while (!F.eof())
			getline(F, Cipher);
	F.close();
	cout << "Текст из файла: " << endl << Cipher << endl;
	//Чтение текстового файла и запись его содержимого в строку для ключа 
	P.open("C:\\Vigenere\\Key.txt", ios::in);
	P >> Key;
	P.close();
	cout << "Ключ из файла: " << endl << Key << endl;
	//(Способ R=1)
	transform(Key.begin(), Key.end(), Key.begin(), ::tolower);
	cout << "Ключ переведенный в прописные символы: " << endl << Key << endl;
	//Перевернем ключ задом на перед
	//в соответствии со способом (P=2)
	reverse(Key.begin(), Key.end());
	cout << "Ключ задом наперед (способ P=2): " << endl << Key << endl;
	//Ключ с повторением 
	for (size_t i = 0; i < Cipher.size(); i++)
	{
		RepeatKey += Key[i % Key.size()];
	}
	cout << "Ключ с повторением: " << endl << RepeatKey << endl;
	//Расшифровка зашифрованного текста
	//по формуле: T = C - K + 26 (mod 26) , где С - зашифрованный символ,T - символ исходного текста, K - символ ключа
		for (int i = 0; i < Cipher.size(); i++)
		{
			if (Cipher[i] == ' ')
			{
				DeCipher += ' ';
			}
			else
			{
				DeCipher += (char)(((int)Cipher[i] - ((int)RepeatKey[i] - 32) + 26) % 26) + 65;
			}
		}
	cout << "Расшифрованный текст: " << endl << DeCipher << endl;
	//Запись зашифрованного текста в файл
	L.open("C:\\Vigenere\\Decipher.txt", ios::out);
	L << DeCipher;
	L.close();
	_getch();
}
