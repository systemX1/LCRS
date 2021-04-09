#pragma once
#ifndef MAINWINDOW_H_SY_
#define MAINWINDOW_H_SY_

#include <iostream>
using std::cin;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <regex>
using std::regex_match;

#include <map>
using std::map;

#include <functional>
using std::function;
using std::bind;

#include "fmt/core.h"

#include "LCRS.hpp"

class MainWindow
{
public:
	static MainWindow& getInstance() {
		static MainWindow instance;
		return instance;
	}
	~MainWindow() = default;
private:
	MainWindow() { init(); }
	
	sy::LCRS<string> forest;
	void init();


	void constructForest();
	void displayForest() const;
	void traverseForest() const;
	void printExtraInfo() const;
	void printHelp() const;

	void testHandler(const vector<int>& parent, const vector<string>& elem, int test_num);
	void test1();
	void test2();
	void test3();
	void test4();
	
	static void printLine(const string& s);
	static bool isStringDigital(const string& s);
};

#endif 