#pragma once
#ifndef MAINWINDOW_H_SY_
#define MAINWINDOW_H_SY_

#include <iostream>
using std::cin;

#include <stdio.h>

#include <string>
using std::string;

#include<vector>
using std::vector;

#include "fmt/core.h"

#include "LCRS.hpp"

const int FUNCTION_NUMBER = 10;

class MainWindow
{
public:
	static MainWindow& getInstance() {
		static MainWindow instance;
		instance.init();
		return instance;
	}

	//Pointer to Function
	typedef void (MainWindow::* fp)();
	//Array of Function pointers
	fp afp[FUNCTION_NUMBER] = { &MainWindow::test0, &MainWindow::test1, &MainWindow::test2, &MainWindow::test3, &MainWindow::test4, &MainWindow::test5, &MainWindow::test6, &MainWindow::test7 };

	void init();
	void test0();
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();
	void printLine();
	bool isStringDigital(const string& s);
private:
	MainWindow() = default;
private:

};

#endif 