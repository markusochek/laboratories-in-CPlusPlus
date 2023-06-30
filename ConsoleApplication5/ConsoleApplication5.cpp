/*
Шапка программы
Постановка задачи:
5.3 Анаграмма. Даны две буквенные строки s1 и s2.
Определить, является ли строка s1 анаграммой строки s2? 
Анаграмма - это строка, полученная из другой строки перестановкой её символов.

*/

#include <iostream>
#include <string>

using namespace std;

void main() {

	const int M = 40;

	cout << "enter the first word" << endl;
	string s1;
	cin >> s1;

	cout << "enter the second word" << endl;
	string s2;
	cin >> s2;

	int k = 0, j = 0;
	string d;

	if (s1.length() == s2.length()) {

		for (int i = 0; i <= s1.length()-1; i++) {

			j = k - 1;
			do
			{
				j++;
			} while (s1[i] != s2[j] and j<=s1.length()-1);
			if (s1[i] == s2[j])
			{
				d[0] = s2[i];
				s2[i] = s2[j];
				s2[j] = d[0];
			}
			k++;
			cout << "s1 " << s1 << endl;
			cout << "s2 " << s2 << endl;
			cout << endl;
		}

	}

	if (s1 == s2) {

		cout << "this is an anagram" << endl;

	}
	else {

		cout << "this is not an anagram" << endl;

	}

	system("pause");

}


