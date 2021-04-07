#include "MainWindow.h"

void MainWindow::init()
{
	string input;

	while (true) {
		printLine();
		printf("\t\t0 - Construct EBTree\tq - quit\n\
		1 - Print EBTree\t2 - Print Expression\n\
		t - Run Test1\t\ttt - Run Test2\n\
		3 - Print Extra Result\th - Help\n");
		fmt::print("hello, {}\n", "s");

		cin >> input;
		if (input == "t") {
			(this->*afp[5])();
		}
		else if (input == "tt") {
			(this->*afp[6])();
		}
		else if (input == "h") {
			(this->*afp[7])();
		}
		else if (input == "q") {
			break;
		}
		else if (isStringDigital(input))
			(this->*afp[stoi(input)])(); // string to int
		else
			printf("Invalid input\n");			
	}
	printf("\n");
	system("pause");
}

void MainWindow::test0()
{
	printLine();
	

	return;
}

void MainWindow::test1()
{
	printLine();
	

	return;
}

void MainWindow::test2()
{
	printLine();
	

	return;
}

void MainWindow::test3()
{
	printLine();
	

	return;
}

void MainWindow::test4()
{
	printLine();
	
	return;
}

void MainWindow::test5()
{
	printLine();
	

	return;
}

void MainWindow::test6()
{
	printLine();
	

	return;
}

void MainWindow::test7()
{
	printLine();
	printf("Data Structures and Algorithms  Expression Binary Tree\n");
	return;
}

void MainWindow::printLine()
{
	printf("__________________________________________________________________\n");
}

bool MainWindow::isStringDigital(const string& s)
{
	for (auto& i : s) {
		if (!isdigit(i))
			return false;
	}
	return true;
}
