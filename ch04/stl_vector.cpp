// C++ vector������̽

// ʹ��vector����߱��Ч�ʣ�����Ӧ�أ�vector������Ч�ʵ�������

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vi; // Ԫ������Ϊint��vector�������գ�
	
	int n;
	cout << "input n: ";
	cin >> n;
	
	vector<double> vd(n); // Ԫ������Ϊdouble��vector��������СΪn��

	cout << "created an vector of " << n << " doubles.\n";

	// ���Զ�vectorʹ���б��ʼ��
	vector<int> ints = {1, 2, 3, 4 ,5};	// ע��ʹ�÷�ʽ
										// ��Ҫд��vector<int> ints(5) = {1, 2, 3, 4, 5};
	vector<int> ints2 = {1, 2, 3, 4, 5}; // ����д��Ҳ��ok��
}