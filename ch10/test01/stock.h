class Stock
{
	double share_val;
	int shares;
	double total_val;
	
	void set_tot(); // ������Ҫset_tot()��Ϊ��������, ���ǲ���ͷ�ļ��и���������,
					// ����ת����Դ�ļ��и���, ��ʹ��inline�޶���
public:
	
	void initialize(double val, int n); // initialize()������������

	void show();
};

