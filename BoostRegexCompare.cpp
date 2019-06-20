// BoostRegexCompare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_algorithms.hpp>
#include <boost/regex.hpp>

/*
Ref : https://www.boost.org/doc/libs/1_70_0/doc/html/xpressive/user_s_guide.html
*/

using namespace std;

int main()
{
	string reg0("(\\w){2,2}-(\\w){5,5}-(\\w){3,3}");
	string reg1("1001229(\\w){8,8}");
	string reg2("(\\w){4,4}");
	string reg3("(\\w){2,2}");

	string t0("77-88888-999");
	string t1("ee-bbbbb-fff");
	string t2("77788888-999");
	string t3("77-888889999");
	string t4("7777-88888-999");
	string t5("77-8888888-999");
	string t6("77-88888-9999");
	string t7("    ");
	string t8("100122922222222");
	string t9("444444");
	string t10("4444");
	string t11("44");
	string t12("44444444");

	string test_pattern[13] = {t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12};

#if 1
	using namespace boost::xpressive;
	sregex rex1 = sregex::compile(reg2);
	smatch what;
	for (auto x : test_pattern) {
		if (regex_match(x, what, rex1)) {
			std::cout << " match found ... " << std::endl;
		}
		else {
			std::cout << " no match found ... " << std::endl;
		}

	}

	
#else
	boost::regex rex(reg0);
	for (auto x : test_pattern) {
		bool r = boost::regex_match(x, rex);
		cout << r << endl;
	}
#endif

	return 0;
}
