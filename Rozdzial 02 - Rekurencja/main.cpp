#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void odwroc_tablice(int* tab, int left, int right);
bool poszukiwanie_binarne(int *tab, int left, int right, int x);
void dec_to_bin(int n);
int NWD(int a, int b);
int silnia_bez_rek(int n);

int main()
{
	//Zad 1 - odwracanie tablicy
	int tab[6]{ 1, 2, 4, 6, 3, 7};
	for (auto i : tab)
		cout << i << " ";
	cout << "   ->   ";
	odwroc_tablice(tab, 0, 5);
	for (auto i : tab)
		cout << i << " ";
	cout << endl;

	//Zad 2 - poszukiwanie binarne - sprawdzanie, czy liczba znajduje sie w tablicy (T/F)
	int tab2[15]{ 1,2,3,4,5,6,7,8,9,11,15,16,17,19, 23};
	int n = 15;
	cout << "Czy " << n << " w tablicy?: ";
	if (poszukiwanie_binarne(tab2, 0, 14, n))
		cout << "True\n";
	else
		cout << "False\n";

	//Zad 3 - wyswietlanie liczby dec w formacie bin
	cout << "69 = ";
	dec_to_bin(69);
	cout << endl;

	//Zad 5 - najwiekszy wspolny dzielnik
	cout << "NWD(16, 24): " << NWD(24, 16) << endl;

	//Zad 6 - silnia bez uzycia rekurencji (czyli iteracyjnie)
	cout << "5! = " << silnia_bez_rek(5) << endl;
	cout << "Done!\n";
	getchar();
	return 0;
}

void odwroc_tablice(int* tab, int left, int right)
{
	if (left < right)
	{
		int temp = tab[left];
		tab[left] = tab[right];
		tab[right] = temp;
		odwroc_tablice(tab, left + 1, right - 1);
	}
}

bool poszukiwanie_binarne(int *tab, int left, int right, int x)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (tab[middle] == x)
			return true;
		else if (tab[middle] > x)
			return poszukiwanie_binarne(tab, left, middle - 1, x);
		else //tab[middle] < x
			return poszukiwanie_binarne(tab, middle + 1, right, x);
	}
	return false;
}

void dec_to_bin(int n)
{
	if (n != 0)
	{
		dec_to_bin(n / 2);
		cout << n % 2;
	}
}

int NWD(int a, int b)
{
	if (b == 0)
		return a;
	return NWD(b, a%b);
}

int silnia_bez_rek(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
		res *= i;
	return res;
}
