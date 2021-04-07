#include "MainWindow.h"

void MainWindow::init()
{
	string input;

	while (input != string("q")) {
		printLine(string("Main Menu"));
		fmt::print("\t\t0 - Construct Forest\tq - quit\n\
		1 - Display Forest\t2 - Traverse Forest\n\
		3 - Print Extra Result\th - Help\n\
		t - Run Test1\t\ttt - Run Test2\n");
		
		map<string, function<void()>> func = {
			{ string("0"), [this] { constructForest(); }},
			{ string("1"), [this] { displayForest(); }},
			{ string("2"), [this] { traverseForest(); }},
			{ string("3"), [this] { printExtraInfo(); }},
			{ string("h"), [this] { printHelp(); }},
			{ string("t"), [this] { test1(); }},
			{ string("tt"), [this] { test2(); }}
		};
		
		cin >> input;

		if (input == string("q"))
			break;
		else if(func.find(input) == func.end())
			fmt::print("Invalid Input\n"); 
		else
			func[input]();
		
	}
	fmt::print("\n");
	system("pause");
}

/*
  0 1 2 3 4 5  6 7 8 9 10 11 12 14 15
 -6 0 0 0 1 4 -4 6 6 7 -5 10 11 11 11 #
  A B C D E F  G H I J  K  L  M  N  O #
 */
void MainWindow::constructForest()
{
	printLine(string("Construct Forest"));
	
	vector<int> parent;
	vector<string> elem;
	string in;
	while (true)
	{
		cin >> in;
		if(in == string("#"))
			break;
		parent.push_back(stoi(in));
	}
	in = string("");
	while (true)
	{
		cin >> in;
		if (in == string("#"))
			break;
		elem.push_back(in);
	}

	forest.reset(parent, elem, parent[0] * (-1));
}

void MainWindow::displayForest() const
{
	printLine(string("Display Forest"));
	forest.printLCRS();
}

void MainWindow::traverseForest() const
{
	printLine(string("Traverse Forest"));
}

void MainWindow::printExtraInfo() const
{
	printLine(string("Print Extra Result"));
}

void MainWindow::test1()
{
	printLine(string("Run Test1"));
	const vector<int> parent = { -6, 0, 0, 0, 1, 4, -4, 6, 6, 7, -5, 10, 11, 11, 11 };
	const vector<string> elem = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O" };
	
	forest.reset(parent, elem, parent[0] * (-1));
	forest.printLCRS();
}

void MainWindow::test2()
{
	printLine(string("Run Test2"));
}

void MainWindow::printHelp() const
{
	printLine(string("Help"));
	fmt::print("\tData Structures and Algorithms II\n\
	Left-Child Right-Sibling Representation of Forest(LCRS)\n\
	Inputs of Construct Forest should be 2 lines of numbers\n\
	and strings split by ' ' and end by '#'\n\
	Example:\n\
	-6 0 0 0 1 4 -4 6 6 7 -5 10 11 11 11 #\n\
	 A B C D E F  G H I J  K  L  M  N  O #\n");
}

void MainWindow::printLine(const string& s)
{
	fmt::print("__________________________________________________________________\n");
	fmt::print("\033[7m{}\033[m\n", s.c_str());
}

bool MainWindow::isStringDigital(const string& s)
{
	const std::regex rex("^-?[0-9]+$");
	return std::regex_match(s.begin(), s.end(), rex);
}

