#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>

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





