#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> col = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t c;
	c = count_if(col.begin(), col.end(),
	[] (int x) ->bool
	{ 
		bool odd = x % 2;
		cout << x << " is " << (odd? "odd" : "even") << endl;
		return odd;
	}
	);
	cout << "number of odd elementes: " << c << endl;
	return 0;
}
