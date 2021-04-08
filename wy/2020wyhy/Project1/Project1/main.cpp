
#include "classDefine.h"

int main()
{
	//CountNumType a = CountNumType();
	//a.proc2(a.baseStation, a.floodList);
	//Microsoft2021WJR b = Microsoft2021WJR();
	//b.proc1(b.eg);
	WYHY test = WYHY();
	//test.candy(test.eg_proc1);
	vector<int> define;
	string str = "helloworld";
	string a;
	getline(cin, a, '\n');
	a.push_back('\n');
	int i = 0;
	int num = 0;
	while(i<a.size())
	{
		if (a[i] == ' ' || a[i]=='\t' || a[i]== '\n') {
			define.push_back(num);
			num = 0;
		}
		else {
			num = num * 10 + a[i] - '0';
		}
		i++;
	}
	//for (int i = 0;i < 26;i++) {
	//	define.push_back(5);
	//}
	test.processLetter(define,str);
}