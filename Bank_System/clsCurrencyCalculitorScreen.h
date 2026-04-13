#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsCurrency.h";
#include<iomanip>
using namespace std;


class clsCurrencyCalculitorScreen:protected clsScreen
{
private:
	static clsCurrency _GetCurrency(string Massage) {
		cout << Massage;
		string CurrencyCode = clsInputValidate::ReadString();


		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			//cout<<""
			cout << "\n\nCurrency is not found ,choose another one: ";
			string CurrencyCode = clsInputValidate::ReadString();
		}
	    clsCurrency currency=clsCurrency::FindByCode(CurrencyCode);
		return currency;
	}

	static void _PrintCurrencyCard(clsCurrency CurrencyFrom) {
		cout << " Currency Card\n";
		cout << "_________________________________\n\n";
		cout << " Country   :" << CurrencyFrom.Country() << endl;
		cout << " Code      : " << CurrencyFrom.CurrencyCode() << endl;
		cout << " Name      : " << CurrencyFrom.CurrencyName() << endl;
		cout << " Rate/(1$) : " << CurrencyFrom.Rate() << endl;
		cout << "_________________________________\n\n";
	}

	static void _PrintCalculationResults(clsCurrency CurrencyFrom,clsCurrency CurrencyTo,float Amount) {
		 
		_PrintCurrencyCard(CurrencyFrom);

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << "USD\n\n";

		if (CurrencyTo.CurrencyCode() == "USD") {
			return;
		}


		_PrintCurrencyCard(CurrencyTo);

		float AmountInOnther = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInOnther
			<<" " <<CurrencyTo.CurrencyCode()<<endl; 


	}


public:
	static void ShowCurrencyCalcoltorScreen() {

		_DrawScreenHeader("Clacolitor Rate Currency Screen\n");
		clsCurrency CurrencyFrom = _GetCurrency("\n\nPlease Enter Currency1 Code From :");
		clsCurrency CurrencyTo = _GetCurrency("\n\nPlease Enter Currency2 Code To :");
		
		cout << "Enter Amount to Exchange :";   
		float Amount = clsInputValidate::ReadFloatNumber();

		_PrintCalculationResults(CurrencyFrom,CurrencyTo,Amount);
	}
};








