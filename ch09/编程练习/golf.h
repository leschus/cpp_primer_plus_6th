const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};


// �ǽ����汾
void setgolf(golf &g, const char *name, int hc);

// �����汾
int setgolf(golf &g);

// �޸Ľṹ��handicap��Ա
void handicap(golf &g, int hc);

// ��ӡ�ṹ����������
void showgolf(const golf &g);