#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h";
#include"clsPerson.h";
#include"clsInputValidate.h";
#include<iomanip>
#include"clsDate.h";
#include"clsUtil.h";
//#include"Global.h";
using namespace std;


class clsUser :public clsPerson
{

private:
	enum enMode {
		EmptyMode = 1, UpdateMode = 2, AddNewMode = 3
	};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	struct stLOginRegisterRecord ;

	static clsUser _ConvertUsersToObject(string line, string seprater = "#//#") {
		vector<string>vUsres; 
		vUsres = clsstring::Split(line, seprater);

		return clsUser(enMode::UpdateMode, vUsres[0], vUsres[1], vUsres[2], vUsres[3], vUsres[4], vUsres[5], stoi(vUsres[6]));
	}

	static vector<clsUser>_LoadUsersDataFromFile() {
		fstream myfile;
		vector<clsUser>vUser;

		myfile.open("Users.txt", ios::in);
		if (myfile.is_open()) {
			string line;

			while (getline(myfile, line)) {
				clsUser User = _ConvertUsersToObject(line);
				vUser.push_back(User);
			}
			myfile.close();
		}
		return vUser;
	}

	static clsUser _GetEmptyUsreOpject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(clsUser user, string sepr = "#//#") {
		string Dataline = "";
		Dataline += user.FristName + sepr;
		Dataline += user.LastName + sepr;
		Dataline += user.Phon + sepr;
		Dataline += user.Email + sepr;
		Dataline += user.UserName + sepr;
		Dataline +=user.Password + sepr;
		Dataline += to_string(user.Permissions);

		return Dataline;
	}

	static void _SaveUsersDataToFile(vector<clsUser>vusers) {

		fstream myfile;
		myfile.open("Users.txt", ios::out);
		if (myfile.is_open()) {

			string Dataline;
			for (clsUser v : vusers) {
				if (v.MarkDeleteUser() == false) {
					Dataline = _ConvertUserObjectToLine(v);
					myfile << Dataline << endl;
				}
			}
			myfile.close();
		}
	}

	void _Update() {
		vector<clsUser>_vusers;
		_vusers = _LoadUsersDataFromFile();

		for (clsUser& c : _vusers) {
			if (c.UserName == UserName) {
				c = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vusers);
	}

	void _AddNew() {
		_AddDataLinetoFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLinetoFile(string stData) {
		fstream myfile;
		myfile.open("Users.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << stData << endl;
			myfile.close();
		}
	}

	string _PerpareLoginRecord() {
		string line = "", sep = "#//#";

		line += clsDate::GetSystemDateTimeString() + sep;
		line += UserName + sep;
		line +=Password+ sep;
		line += to_string(Permissions);
		return line;
	}

	static stLOginRegisterRecord _ConvertLoginRegisterToRecord(string line,string sep="#//#") {
		stLOginRegisterRecord LOginRegisterRecord;

		vector<string>Vstring= clsstring::Split(line, sep);
		LOginRegisterRecord.Time = Vstring[0];
		LOginRegisterRecord.UserName = Vstring[1];
		LOginRegisterRecord.Password =Vstring[2];
		LOginRegisterRecord.Permission = stoi(Vstring[3]);

		return LOginRegisterRecord;
	}

public:

	enum enpermision {
		pAll = -1, pListClints = 1, pAddNewClint = 2, pDeleteClint = 4, pUpdateClint = 8, pFindClint = 16, pTranaction = 32,
		pManageUser = 64, pLoginRegister = 128, pCurrenciesExchange = 256
	};

	struct stLOginRegisterRecord {
		string Time;
		string UserName;
		string Password;
		int Permission;
	};

	clsUser(enMode Mode, string FristName, string LastName, string Email, string Phon
		, string UserName, string Password, int Permissions) :clsPerson(FristName, LastName, Email, Phon)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmptyMode() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkDeleteUser() {
		return _MarkedForDelete;
	}

	void SetUserName(string Username)
	{
		_UserName = Username;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Pasword) {
		_Password = Pasword;
	}
	string GetPassword() {
		return _Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permissions) {
		_Permissions = Permissions;
	}
	int GetPermissions() {
		return _Permissions;
	}
	_declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	string FullName() {
		return FristName + " " + LastName;
	}

	static clsUser Find(string UserName) {
		fstream myfile;

		myfile.open("Users.txt", ios::in);
		if (myfile.is_open()) {
			string line;

			while (getline(myfile, line)) {
				clsUser User = _ConvertUsersToObject(line);
				if (User.UserName == UserName) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}
		return _GetEmptyUsreOpject();
	}

	static clsUser Find(string UserName, string password) {
		fstream myfile;

		myfile.open("Users.txt", ios::in);
		if (myfile.is_open()) {
			string line;

			while (getline(myfile, line)) {
				clsUser User = _ConvertUsersToObject(line);
				if (User.UserName == UserName && User.Password == password) {
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}
		return _GetEmptyUsreOpject();
	}

	enum enSaveResult { svfailEmptyobject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	static bool IsUserExist(string UserName) {
		clsUser user = clsUser::Find(UserName);
		return (!user.IsEmptyMode());
	}

	enSaveResult Save() {
		switch (_Mode) {
		case enMode::EmptyMode:
		{
			return enSaveResult::svfailEmptyobject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		}
	}

	bool Delete() {
		vector<clsUser>_vusers;
		_vusers = _LoadUsersDataFromFile();

		for (clsUser& c : _vusers) {
			if (c.UserName == _UserName) {
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vusers);
		*this = _GetEmptyUsreOpject();
		return true;
	}

	static clsUser GetAddNewUsertoObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser>GetUsersList() {
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enpermision permission) {
		if (this->_Permissions == enpermision::pAll) {
			return true;
		}
		if ((permission & this->_Permissions) == permission) {
			return true;
		}
		else
		{
			return false;
		}
	}

    void LoginRegister() {
		string stdataline = _PerpareLoginRecord();
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << stdataline << endl;
			myfile.close(); 
		}
	}

	static vector<stLOginRegisterRecord>GitLoginRegister() {
		stLOginRegisterRecord LoginRegisterRecord;
		vector<stLOginRegisterRecord>vLoginRegister;

		fstream myfile;
		myfile.open("LoginRegister.txt", ios::in);

		string line;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				LoginRegisterRecord = _ConvertLoginRegisterToRecord(line);
				vLoginRegister.push_back(LoginRegisterRecord);
			}
			myfile.close();
		}
		return vLoginRegister;
	}
};

