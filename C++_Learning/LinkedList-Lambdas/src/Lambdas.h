# pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>
#include "utils.h"

auto extractNumbers = [](const std::string & string) {
	std::string res = "";
	for (char c : string) {
		if (isdigit(c)) {
			res += c;
		}
	}
	return res;
};

auto isLowerCase = [](const std::string & string) {
	for (char c : string) {
		if (!islower(c))
			return false;
	}
	return true;
};

auto sumVector = [](const std::vector<int> & vec) {
	int sum = 0;
	for (int num : vec) {
		sum += num;
	}
	return sum;
};

auto sumVectorOdds = [](const std::vector<int>& vec) {
	int sum = 0;
	for (int num : vec) {
		if(num % 2 != 0)
			sum += num;
	}
	return sum;
};

