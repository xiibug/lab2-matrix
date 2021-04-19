
#include <iostream>
#include "MyVector.h"
#include "Matrix.h"
using namespace std;

int main()
{
	 Vector<int> a(3);
	 TMatrix<int> m(3);
	 TMatrix<int> k=m;
	 TMatrix<int> b(3);
	m+k;
	cout<< 3 << "\nHi\n";
	return 0;
}
