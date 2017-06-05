 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;

 int main()
 {
 	vector<int> col = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 	int sum = 0;
 	for_each(col.begin(), col.end(), [&sum](int x){ sum += x;}); // don't capture by value, capture by reference &
 	cout << "The sum is: " << sum << endl;
 }
