#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h";
#include"clsBankClint.h";
#include"clsInputValidate.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTotalBalancesScreen.h";
#include"clsTransfarScreen.h";
#include"clsTransferLogScreen.h";
#include<iomanip>
  using namespace std;


class clsTransactionsMenue:protected clsScreen
{
private:
	enum enTransactionMenueOption {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfar = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionMenueOption() {
		short ch;
		cout << "  Choose What do you Want to do ?[1 to 6]: ";
		ch = clsInputValidate::ReadShortNumberBetween(1, 6, "\n Enter number Between 1 to 6?");

		return ch;
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransfarScreen() {
		clsTransfarScreen::ShowTransfarScreen();
	}

	static void _ShowTransferLogScreen() {

		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionMenue() {
		cout << "\n\tpress any key to go back to main menue...\n";
		system("pause>0");
		ShowTransactionsMenue();
	}


	static void _PerformMainMenueOption(enTransactionMenueOption Transactionoption) {
		switch (Transactionoption) {
		case enTransactionMenueOption::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOption::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOption::eTransfar:
		{
			system("cls");
			_ShowTransfarScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOption::eShowMainMenue:
		{
	
		}
		}
	}


public:

	static void ShowTransactionsMenue() {
		system("cls");
		if (!ChackAccessRight(clsUser::enpermision::pTranaction)) {
			return;
		}
		_DrawScreenHeader("\tTransactuons Screen");

		cout << "=====================================\n";
		cout << "\t  Transaction Menue\n";
		cout << "=====================================\n";
		cout << "   [1] Deposit.\n";
		cout << "   [2] Withdraw.\n";
		cout << "   [3] Total Balances.\n";
		cout << "   [4] Transfar.\n";
		cout << "   [5] Transfer Log.\n";
		cout << "   [6] Main Menue.\n";
		cout << "=====================================\n";

		_PerformMainMenueOption((enTransactionMenueOption)_ReadTransactionMenueOption());

	}

};

