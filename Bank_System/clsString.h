#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsstring
{
private:
	string _value;

public:
	static vector<string>Split(string s1, string Delim) {

		vector<string>vstring;

		short pos = 0;
		string sword;

		while ((pos = s1.find(Delim)) != std::string::npos) {
			sword = s1.substr(0, pos);
			if (s1 != "") {
				vstring.push_back(sword);
			}
			s1.erase(0, pos + Delim.length());
		}
		if (s1 != "") {
			vstring.push_back(s1);
		}

		return vstring;
	}

	vector<string>Split(string Delim) {
		return Split(_value, Delim);
	}
};

