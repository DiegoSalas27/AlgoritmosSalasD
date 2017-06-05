 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 //we create a functor
class isMultipleOf{
 	int m_multi;
public:
 	isMultipleOf(int multi) : m_multi(multi){}
	bool operator() (int x){
		return !(x % m_multi);
	}	
 };
 int main()
 {
 	vector<int> col; 
 	for(int i = 0; i < 10; i++)
 	col.push_back(i);
 	col.push_back(11);
 	int multi = 5;
 	size_t c; //unsinged integral type. Able to represent the size of any object in bytes (widely used to represent sizes and counts!)
 	c = count_if(col.begin(), col.end(), isMultipleOf(multi) );
 	cout << "integeres that are multiple of " << multi << ": " <<  c << endl;
 }
