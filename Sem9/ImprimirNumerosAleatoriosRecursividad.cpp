#include <iostream>
#include <vector>
using namespace std;
void serie6_1(int r, int n, int p, int d) {
if (d != 0) {
serie6_1(r, n, p, d - 1);
r = r * 10 + d;//1
if (p == 1) cout << r << endl;
else serie6_1(r, n, p - 1, n);
}
}
void serie6(int n) {
serie6_1(0, n, n, n);//2
}
int main() {
serie6(4);
return 0;
}
