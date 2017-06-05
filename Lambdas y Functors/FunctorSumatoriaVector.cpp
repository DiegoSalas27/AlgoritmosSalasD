 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;

class sumUp{
	int &m_sum;
public:	
	sumUp(int &sum): m_sum(sum){}
	void operator() (int x)
	{
		m_sum += x;
	}
};
 int main()
 {
 	vector<int> col = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 	int sum = 0;
 	for_each(col.begin(), col.end(), sumUp(sum));
 	cout << "The sum is: " << sum << << endl;
 }
