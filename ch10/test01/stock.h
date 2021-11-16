class Stock
{
	double share_val;
	int shares;
	double total_val;
	
	void set_tot(); // 我们需要set_tot()称为内联函数, 但是不在头文件中给出函数体,
					// 而是转而在源文件中给出, 且使用inline限定符
public:
	
	void initialize(double val, int n); // initialize()不是内联函数

	void show();
};

