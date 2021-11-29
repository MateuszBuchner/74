#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int const size = 200;
string tab[size];

bool cyfrowe_haslo(char x){
	return (x >= '0' && x <= '9');
}

bool czy_cyfra(string y){
	for(int i = 0; i < y.length(); i++){
		if(!cyfrowe_haslo(y[i])) return false;
	}
	return true;
}

void zad1(){
	int licz = 0;
	for(int i = 0; i < size; i++){
		if(czy_cyfra(tab[i])) licz++;
	}
	cout << "Zadanie 1: "<< endl;
	cout << licz << endl << endl;
}

void zad2(){
	cout << "Zadanie 2: "<< endl << endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(i == j) break;
			if(tab[i] == tab[j]){
				cout << tab[i] << endl;
			}
		}
	}
}

bool ascii(string s){
	if(s.length() < 4)return false;
	char t[4];
	
	for(int i = 0; i < s.length(); i++){
		t[0] = (int) s[i];
		t[1] = (int) s[i + 1];
		t[2] = (int) s[i + 2];
		t[3] = (int) s[i + 3];
		sort(t, t + 4);
    	if (t[0] + 1 == t[1] && t[1] + 1 == t[2] && t[2] + 1 == t[3]) return true;
	}
	return false;
}

void zad3(){
	int licz = 0;
	for(int i = 0; i < size; i++){
		if(ascii(tab[i])){
			licz++;
		}
	}
	cout << endl << "Zadanie 3: "<< endl;
	cout << licz << endl << endl;
}

bool warunek_hasla(string s){
	bool cyfra = false, mala_litera = false, duza_litera = false;
	for(int i = 0; i < s.length(); i++){
		if (s[i] >= '0' && s[i] <= '9') cyfra = true;
	    if (s[i] >= 'a' && s[i] <= 'z') mala_litera = true;
	    if (s[i] >= 'A' && s[i] <= 'Z') duza_litera = true;
	}
	return (cyfra && mala_litera && duza_litera);
}

void zad4(){
	int licz = 0;
	for(int i = 0; i < size; i++){
		if(warunek_hasla(tab[i])) licz++;
	}
	cout << "Zadanie 4: "<< endl;
	cout << licz << endl << endl;
}

int main(int argc, char** argv) {
	ifstream in("hasla.txt");
	for(int i = 0; i < size; i++) in >> tab[i];
	in.close();
	
	zad1();
	zad2();
	zad3();
	zad4();
}
