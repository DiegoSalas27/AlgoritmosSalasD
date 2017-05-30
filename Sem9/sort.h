#ifndef __SORT_H__
#define __SORT_H__

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template <typename T>
bool isSorted(vector<T> &v, function<int(T, T)> compare) {
	int n = v.size();
	for (int i = 0; i < n - 1; ++i) {
		if (compare(v[i], v[i + 1]) > 0) {
			return false;
		}
	}
	return true;
}

template <typename T>
void ordInsercion(vector<T> &v, function<int(T, T)> compare)
{
	int n = v.size();
	T elem;
	int j;
	for(int i = 0; i < n -1; i++){
		elem = v[i];
		for(j = i; j > 0; --j){
			if(compare(v[j], elem) > 0){
				break;
			}
			v[j + 1] = v[j];
		}
		v[j] = elem;
	}
}

#endif
