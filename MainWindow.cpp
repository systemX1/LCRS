#include "MainWindow.h"

void MainWindow::init()
{
	string input;

	while (input != string("q")) {
		printLine(string("Main Menu"));
		fmt::print("\t\t0 - Construct Forest\tq - quit\n\
		1 - Display Forest\t2 - Traverse Forest\n\
		3 - Print Extra Result\th - Help\n\
		t1 - Run Test1\t\tt2 - Run Test2\n\
		t+number - Run Test n\n");
		
		map<string, function<void()>> func = {
			{ string("0"), [this] { constructForest(); } },
			{ string("1"), [this] { displayForest(); } },
			{ string("2"), [this] { traverseForest(); } },
			{ string("3"), [this] { printExtraInfo(); } },
			{ string("h"), [this] { printHelp(); } },
			{ string("t1"), [this] { test1(); } },
			{ string("t2"), [this] { test2(); } },
			{ string("t3"), [this] { test3(); } },
			{ string("t4"), [this] { test4(); } },
			{ string("t5"), [this] { test5(); } },
			{ string("t6"), [this] { test6(); } },
			{ string("t7"), [this] { test7(); } },
			{ string("t8"), [this] { test8(); } },
			{ string("t9"), [this] { test9(); } },
			{ string("t10"), [this] { test10(); } },
			{ string("t11"), [this] { test11(); } },
			{ string("t12"), [this] { test12(); } },
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

	fmt::print("parent: ");
	while (true)
	{
		cin >> in;
		if(in == string("#"))
			break;
		parent.push_back(stoi(in));
	}
	in = string("");
	fmt::print("\nelem: ");
	while (true)
	{
		cin >> in;
		if (in == string("#"))
			break;
		elem.push_back(in);
	}
	if(parent.empty() || elem.empty() || parent.size() != elem.size())
	{
		fmt::print("\nNot equal length of two rows or nothing\n");
		return;
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
	forest.printTraverseForest();
}

void MainWindow::printExtraInfo() const
{
	printLine(string("Print Extra Result"));
	forest.printExtraInfo();
}


void MainWindow::testHandler(const vector<int>& parent, const vector<string>& elem, int test_num)
{
	printLine(string("Run Test" + std::to_string(test_num)));
	forest.reset(parent, elem, parent[0] * (-1));
	forest.printLCRS();
	forest.printTraverseForest();
	forest.printExtraInfo();
}

void MainWindow::test1()
{
	const vector<int> parent = { -1 };
	const vector<string> elem = { "Hello" };
	testHandler(parent, elem, 1);
}

void MainWindow::test2()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0" };
	testHandler(parent, elem, 2);
}

void MainWindow::test3()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0, -6, 6, 6, 6, 6, 6 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0", "World", "W", "o", "r", "l", "d" };
	testHandler(parent, elem, 3);
}

void MainWindow::test4()
{
	const vector<int> parent = { -6, 0, 0, 0, 1, 4, -4, 6, 6, 7, -5, 10, 11, 11, 11 };
	const vector<string> elem = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O" };
	testHandler(parent, elem, 4);
}

void MainWindow::test5()
{
	const vector<int> parent = { -1, -4, 1,	1,	2, -1, -1, -1 };
	const vector<string> elem = { "A",	"B", "B1", "B2", "B1X",	"D", "E", "F" };
	testHandler(parent, elem, 5);
}

void MainWindow::test6()
{
	const vector<int> parent = { -15, 0, 0,	2,	2,	4,	4,	5,	7,	7,	9,	9,	11,	11,	13 };
	const vector<string> elem = { "A", "B", "C", "D", "E", "F",	"G", "H", "I", "J",	"K", "L", "M", "N",	"O" };
	testHandler(parent, elem, 6);
}

void MainWindow::test7()
{
	const vector<int> parent = { -12, 0, 0,	0,	1,	1,	3,	6,	6,	6,	7,	9, -2, 	12, -5,	14,	15,	15,	15 };
	const vector<string> elem = { "A", "B", "C", "D", "B1", "B1X", "D1", "D2X", "D2Y", "D2Z",	"D3", "D4", "G", "H", "K", "L", "M", "N", "O" };
	testHandler(parent, elem, 7);
}

void MainWindow::test8()
{
	const vector<int> parent = { -1, -1, -6, 2,	2,	2,	5,	5, -1, -1, -6,	10,	10,	12,	12,	12, -2,	16 };
	const vector<string> elem = { "XX", "YY", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",	"K", "L", "M","N", "O",	"P" };
	testHandler(parent, elem, 8);
}

void MainWindow::test9()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0, -6, 6, 6, 6, 6, 6 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0", "World", "W", "o", "r", "l", "d" };
	testHandler(parent, elem, 9);
}

void MainWindow::test10()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0, -6, 6, 6, 6, 6, 6 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0", "World", "W", "o", "r", "l", "d" };
	testHandler(parent, elem, 10);
}

void MainWindow::test11()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0, -6, 6, 6, 6, 6, 6 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0", "World", "W", "o", "r", "l", "d" };
	testHandler(parent, elem, 11);
}

void MainWindow::test12()
{
	const vector<int> parent = { -6, 0, 0, 0, 0, 0, -6, 6, 6, 6, 6, 6 };
	const vector<string> elem = { "Hello", "H", "e", "l", "l", "0", "World", "W", "o", "r", "l", "d" };
	testHandler(parent, elem, 12);
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(handle, &csbiInfo);
	const WORD wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(handle,
		BACKGROUND_RED |
		BACKGROUND_GREEN |
		BACKGROUND_BLUE |
		BACKGROUND_INTENSITY
	);
	
	fmt::print("{}", s.c_str());
	
	SetConsoleTextAttribute(handle,
		wOldColorAttrs);

	fmt::print("\n");
	
	//fmt::print("{}\n", s.c_str());
	//fmt::print("\033[7m{}\033[m\n", s.c_str());
	//fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray), "{}\n", s.c_str());
}

bool MainWindow::isStringDigital(const string& s)
{
	const std::regex rex("^-?[0-9]+$");
	return std::regex_match(s.begin(), s.end(), rex);
}

