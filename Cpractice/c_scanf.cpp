#include <cmath> 
#include <climits> 
#include <queue> 
#include <vector> 
#include <map> 
#include <cstdlib> 
#include <fstream> 
#include <iomanip>    
#include <iostream>   
#include <sstream>  // istringstream buffer(myString); 
#include <stack> 
#include <algorithm> 
#include <cstring> 
#include <cassert> 
using namespace std;
#define pb push_back 
typedef int it;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

void test_back_begin_end();


int main() {
	
	int length = 5;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0;  j < length;  j++)
		{
			if (!i || !j) {
				printf("1, ");			}
			else {
				printf("0, ");
			}
		}
		printf("\n");
	}
	return 0;
};

void test_back_begin_end()
{
	vvi ans;
	vi arr(5, 0);
	ans.pb({ 1 });
	for (size_t i = 0; i < 5; i++)
	{
		vi dr = { 0 };
		dr.insert(dr.end(), ans.back().begin(), ans.back().end());
		dr.push_back(0);

	}
}


