namespace SALES
{
	const int QUARTERS = 4;

	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	// ������ar�е�min{4, n}��������s��sales��Ա��, 
	// ���㿽�����⼸��ֵ��ƽ��ֵ/���ֵ/��Сֵ, ��
	// �����������Ӧ�ĳ�Ա. sales��û�б�����ʣ��
	// �ֵΪ0
	void setSales(Sales &s, const double ar[], int n);

	// ����ʽ������4��ֵ�洢��s��sales��Ա��, ���ż�������
	// ��ƽ��ֵ/���ֵ/��Сֵ, ��������Ӧ�ĳ�Ա
	void setSales(Sales &s);

	// ��ӡs����Ϣ
	void showSales(const Sales &s);
}