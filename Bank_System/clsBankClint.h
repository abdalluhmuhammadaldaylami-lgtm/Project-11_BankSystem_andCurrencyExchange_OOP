#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h";
#include"clsBankclint.h";
#include"clsstring.h";
#include"clsDate.h";
#include"Global.h";
using namespace std;


class clsBankclint :public clsPerson
	{
	private:
		enum enmode { emptymode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
		enmode _Mode;
		string _AccountNumber;
		string _Pincode;
		float  _AccountBalance;
		bool _MarkedForDelete = false;

	    struct stTransferLog;

		static clsBankclint _ConvertlinetoClintObject(string line, string seprater = "#//#") {
			vector<string>vclintData;
			vclintData = clsstring::Split(line, seprater);

			return clsBankclint(enmode::UpdateMode, vclintData[0], vclintData[1], vclintData[2],
				vclintData[3], vclintData[4], vclintData[5], stod(vclintData[6]));
		}

		static clsBankclint _GetEmptyClintObject() {
			return clsBankclint(enmode::emptymode, "", "", "", "", "", "", 0);
		}

		static string _ConvertClintObjectToLine(clsBankclint clint, string sepr = "#//#") {
			string Dataline = "";
			Dataline += clint.FristName + sepr;
			Dataline += clint.LastName + sepr;
			Dataline += clint.Phon + sepr;
			Dataline += clint.Email + sepr;
			Dataline += clint.AccountNumber() + sepr;
			Dataline += clint.Pincode + sepr;
			Dataline += to_string(clint.AccountBalance);

			return Dataline;
		}

		static void _SaveClintsDataToFile(vector<clsBankclint>vclints) {

			fstream myfile;
			myfile.open("clints.txt", ios::out);
			if (myfile.is_open()) {

				string Dataline;
				for (clsBankclint v : vclints) {
					if (v.MarkDeleteClint() == false) {
						Dataline = _ConvertClintObjectToLine(v);
						myfile << Dataline << endl;
					}
				}
				myfile.close();
			}
		}

		static vector<clsBankclint>_LoadClintDataFromFile() {
			vector<clsBankclint>vclints;

			fstream myfile;
			myfile.open("clints.txt", ios::in);
			if (myfile.is_open()) {
				string line;
				while (getline(myfile, line)) {
					clsBankclint clint = _ConvertlinetoClintObject(line);
					vclints.push_back(clint);
				}
				myfile.close();
			}
			return vclints;
		}

		void _Update() {
			vector<clsBankclint>_vclints;
			_vclints = _LoadClintDataFromFile();

			for (clsBankclint& c : _vclints) {
				if (c.AccountNumber() == AccountNumber()) {
					c = *this;
					break;
				}
			}
			_SaveClintsDataToFile(_vclints);
		}

		void _AddNew() {
			_AddDataLinetoFile(_ConvertClintObjectToLine(*this));
		}

		void _AddDataLinetoFile(string stData) {
			fstream myfile;
			myfile.open("clints.txt", ios::out | ios::app);

			if (myfile.is_open()) {
				myfile << stData << endl;
				myfile.close();
			}
		}

		string _ConvertTransfarAmountToLine(clsBankclint DestinationClint,float Amount,string UserName) {
			string line = "", sep = "#//#";

			line += clsDate::GetSystemDateTimeString() + sep;
			line += AccountNumber() + sep;
			line += DestinationClint.AccountNumber() + sep;
			line += to_string(Amount) + sep;
			line += to_string(AccountBalance) + sep;
			line += to_string(DestinationClint.AccountBalance) + sep;
			line += UserName;

			return line;
		}

		void _LoginTransfar(string UserName, clsBankclint DestinationClint, float Amount) {
			fstream myfile;

			myfile.open("LogTransfar.txt", ios::out | ios::app);
			if (myfile.is_open())
			{
				string line = _ConvertTransfarAmountToLine(DestinationClint, Amount, UserName);
				myfile << line << endl;
				myfile.close();
			}
		}

		static stTransferLog _ConvertTransferLogLinetoRecord(string line,string sep="#//#") {
			vector<string>vstring = clsstring::Split(line, sep);
			stTransferLog TransferLog;

			TransferLog.DateTime = vstring[0];
			TransferLog.SoursAccountNumber = vstring[1];
			TransferLog.DestinationAccountNumber = vstring[2];
			TransferLog.Amount = stod(vstring[3]);
			TransferLog.soursBalance = stod(vstring[4]);
			TransferLog.DestinationBalance =stod(vstring[5]);
			TransferLog.UserName = vstring[6];

			return TransferLog;
		}

	public:

		struct stTransferLog {
			string DateTime;
			string SoursAccountNumber;
			string DestinationAccountNumber;
			float Amount;
			float soursBalance;
			float DestinationBalance;
			string UserName;
		};


		clsBankclint(enmode Mode, string FristName, string LastName, string Email, string Phon,
			string AccountNumber, string Pincode, float AccountBalance) :clsPerson(FristName, LastName, Email, Phon)
		{
			_Mode = Mode;
			_AccountNumber = AccountNumber;
			_Pincode = Pincode;
			_AccountBalance = AccountBalance;
		}

		bool IsEmpty() {
			return (_Mode == enmode::emptymode);
		}

		bool MarkDeleteClint() {
			return _MarkedForDelete;
		}

		string AccountNumber() {
			return _AccountNumber;
		}

		void SetPincode(string pincode) {
			_Pincode = pincode;
		}

		string getPincode() {
			return _Pincode;
		}

		_declspec(property(get = getPincode, put = SetPincode))string Pincode;

		void SetAccountBalance(float AccountBalance) {
			_AccountBalance = AccountBalance;
		}

		float getAccountBalance() {
			return _AccountBalance;
		}

		_declspec(property(get = getAccountBalance, put = SetAccountBalance))float AccountBalance;

		string FullName() {
			return FristName + " " + LastName;
		}

		static clsBankclint Find(string AccountNumber) {
			vector<clsBankclint>vclints;
			fstream myfile("clints.txt", ios::in);

			if (myfile.is_open()) {
				string line;
				while (getline(myfile, line)) {
					clsBankclint clint = _ConvertlinetoClintObject(line);
					if (clint.AccountNumber() == AccountNumber) {
						myfile.close();
						return clint;
					}
					vclints.push_back(clint);
				}
				myfile.close();
			}
			return _GetEmptyClintObject();
		}

		static clsBankclint Find(string AccountNumber, string pincode) {
			vector<clsBankclint>vclints;
			fstream myfile("clints.txt", ios::in);

			if (myfile.is_open()) {
				string line;
				while (getline(myfile, line)) {
					clsBankclint clint = _ConvertlinetoClintObject(line);
					if (clint.AccountNumber() == AccountNumber && clint.Pincode == pincode) {
						myfile.close();
						return clint;
					}
					vclints.push_back(clint);
				}
				myfile.close();
			}
			return _GetEmptyClintObject();
		}

		bool Delete() {
			vector<clsBankclint>_vclints;
			_vclints = _LoadClintDataFromFile();

			for (clsBankclint& c : _vclints) {
				if (c.AccountNumber() == _AccountNumber) {
					c._MarkedForDelete = true;
					break;
				}
			}
			_SaveClintsDataToFile(_vclints);
			*this = _GetEmptyClintObject();
			return true;
		}

		static bool IsclaintExist(string Accountnumber) {
			clsBankclint clint1 = clsBankclint::Find(Accountnumber);
			return (!clint1.IsEmpty());
		}

		enum enSaveResult { svfailEmptyobject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

		enSaveResult Save() {
			switch (_Mode) {
			case enmode::emptymode:
			{
				return enSaveResult::svfailEmptyobject;
			}
			case enmode::UpdateMode:
			{
				_Update();
				return enSaveResult::svSucceeded;
				break;
			}
			case enmode::AddNewMode:
			{
				if (clsBankclint::IsclaintExist(_AccountNumber))
				{
					return enSaveResult::svFaildAccountNumberExists;
				}
				else
				{
					_AddNew();
					//enmode::UpdateMode;
					return enSaveResult::svSucceeded;
				}
			}
			}
		}

		//Add New Clint
		static clsBankclint GetAddNewClinttoObject(string Accountnumber) {
			return clsBankclint(enmode::AddNewMode, "", "", "", "", Accountnumber, "", 0);
		}

		static vector<clsBankclint>GetClintList() {
			return _LoadClintDataFromFile();
		}

		static double GetTotalBalances() {
			vector<clsBankclint>vclint = clsBankclint::GetClintList();
			double TotalBalances = 0;

			for (clsBankclint c : vclint) {
				TotalBalances += c.AccountBalance;
			}
			return TotalBalances;
		}

		void Deposit(double amount) {
			_AccountBalance += amount;
			Save();
		}

		bool Withdraw(double amount) {
			if (amount > _AccountBalance) 
			{
				return false;
			}
			else
			{
				_AccountBalance -= amount;
				Save();
			}
		}

		bool Trancfar(float Amount, clsBankclint& DestinationClint,string UserName) {
			if (Amount > AccountBalance) {
				return false;
			}
			Withdraw(Amount);
			DestinationClint.Deposit(Amount);

			_LoginTransfar(UserName, DestinationClint, Amount);
			return true;
		}

		static vector<stTransferLog>GitTransferLogList() {
			vector<stTransferLog>vtransfer;

			fstream myfile;
			stTransferLog TransferLog;

			myfile.open("LogTransfar.txt", ios::in);

			if (myfile.is_open()) {
				string line;

				while (getline(myfile, line)) {
					TransferLog = _ConvertTransferLogLinetoRecord(line);
					vtransfer.push_back(TransferLog);
				}
				myfile.close();
			}
			return vtransfer;
		}





	};

