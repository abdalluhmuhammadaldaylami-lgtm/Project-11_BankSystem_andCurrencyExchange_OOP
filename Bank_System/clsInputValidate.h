#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsInputValidate
{
public:
	static string ReadString() {
		string s1 = "";
		getline(cin >> ws, s1);

		return s1;
	}

	static float ReadIntNumber(string massage = "invalid Number, Enter again\n") {
		float num;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return num;
	}

	static float ReadFloatNumber(string massage = "invalid Number, Enter again\n") {
		float num;
		while (!(cin >> num)) {
			cout << massage;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return num;
	}

	static bool IsNumberBetween(int num,int from,int to) {
		if (num >= from && num <= to) {
			return true;
		}
		else {
			return false;
		}
	}

	static int ReadShortNumberBetween(int from, int to, string errorMass = "number is not within rang, Enter agin:") {

		int num = ReadFloatNumber();
		while (!IsNumberBetween(num, from, to)) {
			cout << errorMass;
			num = ReadFloatNumber();
		}
		return num;
	}

	static double ReadDblNumber(string Error="Invalid Number ,Enter again\n") {
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Error;
		}
		return number;
	}

	static int ReadDblNumberBetween(int from, int to, string erorMass = "number is not within rang, Enter agin:") {
		int num = ReadDblNumber();
		while (!IsNumberBetween(num, from, to)) {
			cout << erorMass;
			num = ReadFloatNumber();
		}
		return num;
	}
};

