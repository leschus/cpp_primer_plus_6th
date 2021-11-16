const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};


// 非交互版本
void setgolf(golf &g, const char *name, int hc);

// 交互版本
int setgolf(golf &g);

// 修改结构的handicap成员
void handicap(golf &g, int hc);

// 打印结构变量的内容
void showgolf(const golf &g);