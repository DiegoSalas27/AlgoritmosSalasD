 #include <iostream>
 #include <algorithm>
 #include <vector>
 //using a  functor to customize the behaviour of a library algorithm
 using namespace std;
 //functor to tell which of the items from the vector are odd
 struct  isOdd
 {
 	bool operator()(int x)
	 {
		return x % 2; 	// if 0, the result is false
	 }	
 };
  struct  isEven
 {
 	bool operator()(int x)
	 {
		return !(x % 2); 	// if 0, the result is false
	 }	
 };
 int main()
 {
 	vector<int> col;
 	for(int i = 0; i < 10; i++)
 	col.push_back(i);
 	col.push_back(11);
 	size_t c; //unsinged integral type. Able to represent the size of any object in bytes (widely used to represent sizes and counts!)
 	c = count_if(col.begin(), col.end(), isEven());
 	cout << "integeres that are odd " << c << endl;
 }
