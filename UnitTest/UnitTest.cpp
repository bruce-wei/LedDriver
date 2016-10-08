// UnitTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(LedDriver);

int main(int argc, char** argv)
{
	RUN_ALL_TESTS(argc, argv);
	system("pause");
	return 0;
}

