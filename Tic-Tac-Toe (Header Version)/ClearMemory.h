#pragma once
#include <iostream>
#include <cstdlib>		//for atoi

using namespace std;
// clears cin buffer
void clear_cin()
{
	cin.clear();
	cin.ignore(1000, '\n');
}
