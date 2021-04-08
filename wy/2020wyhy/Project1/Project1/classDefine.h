#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;



//discibe
// https://blog.csdn.net/weixin_43022263/article/details/105121154
class CountNumType {

public:
	// 题一
	vector<int> const& arrayList = { 1,1,3,7,1 };
	int proc(vector<int> const &arrayList);
	int getCount_one(int number);

	// 题二
	vector<int> const& baseStation = { 6,12, 20, 14, 15, 15, 7, 19, 18, 13 };
	vector<int> const& floodList = { 15 ,23, 19, 1, 17, 24 };
	vector<int>& proc2(vector<int> const& baseStationList, vector<int> const& floodList);

	// 题3

	int proc3(vector<int> const& input);

	// 题4
	int proc4(vector<int> const& input);

};

class Microsoft2021WJR {

public:
	//题目1
	//等差区间
	vector<int> eg = { 1,3,5,6,7,8,9 };
	int proc1(vector<int> const& arrayList);

	//题目2	
};

class WYHY{


public:
	//https://www.nowcoder.com/questionTerminal/8ff3e3a14ea04c6bb3a60e2e457dafb1?orderByHotValue=0&mutiTagIds=1063&page=1&onlyReference=false
	//糖果 2018年
	vector<int> eg_proc1 = { 0,0,0,0};
	int candy(vector<int> & arrayList);

	//奇怪的信
	pair<int, int> processLetter(vector<int> const&defineWidth, string& letter);
};



