
#include "classDefine.h"

int CountNumType::proc(vector<int> const &arrayList)
{
	vector<int>::const_iterator vectorIter;
	set<int> result;
	pair<set<int>::iterator, bool> insertResult;

	for (vectorIter = arrayList.begin();vectorIter != arrayList.end();vectorIter++) {
		int num = getCount_one(*vectorIter);
		insertResult = result.insert(num);
		//if (insertResult.second) {
		//	
		//}
	}
	cout << "type is" << result.size() << endl;
	return result.size();
}


//https://blog.csdn.net/feit2417/article/details/98477389?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
//判断二进制数1的个数
int CountNumType::getCount_one(int number)
{
	int num = 0;

	//1.如果是负数，转换成正数并记入符号位
	if (number < 0)
	{
		number = -number;
		++num;
	}

	while (number) {
		if ((number & 1) == 1)
			num++;
		number >>=1; // 等价于 x = x >> 1
	}
	return num;
}


vector<int>& CountNumType::proc2(vector<int> const& baseStationList, vector<int> const& floodList)
{
	vector<int> result;
	vector<int>::const_iterator floodIter;
	vector<int>::const_iterator baseIter;
	for (floodIter = floodList.begin();floodIter != floodList.end();floodIter++) { //洪水轮次
		int floodHeight = *floodIter; //洪水高度
		int preIndex = 0;
		int nowIndex = 0;
		int colonyNum = 0;
		bool allBaseStationExist = true;
		for (baseIter = baseStationList.begin();baseIter != baseStationList.end();baseIter++,nowIndex++) {
			if (*baseIter > floodHeight) {
				if (nowIndex - preIndex > 1)
					colonyNum++;
				preIndex = nowIndex;
			}
			else {
				allBaseStationExist = false;
			}
		}
		if (allBaseStationExist) colonyNum = 1;
		result.push_back(colonyNum);
	}
	return result;
}


int CountNumType::proc3(vector<int> const& input)
{
	int poolCapacity = input[0];
	int timeRange = input[1];
	int waterInletRate = input[2];
	int waterInletTimeChangeStatus = input[3];
	int outfallRate = input[4];
	int outfallTimeChangeStatus = input[5];

	bool openWaterInlet = true;
	bool openOutfall = true;
	int result = 0;
	for (int currentTime = 0;currentTime < timeRange;currentTime++) {
		openOutfall = (currentTime / outfallTimeChangeStatus) % 2 == 0 ?true:false;
		openWaterInlet = (currentTime / waterInletTimeChangeStatus) % 2 == 0 ? true : false;
		result += waterInletRate * (int)openWaterInlet - outfallRate * (int)outfallRate;
		if (result > poolCapacity) result = poolCapacity;
		else if (result < 0) result = 0;
	}
	return result;
}

// 5 O 6 O 7 0 8 0 2
// 
int CountNumType::proc4(vector<int> const& input)
{
	int max = 0;
	vector<int> notNIndex;
	for (int index = 0;index < input.size();index++) {
		if (input[index] != 'N')
			notNIndex.push_back(index);
	}
	
	if (notNIndex.size() < 3)
		return input.size();
	max = notNIndex[2];
	for (int k = 3;k < notNIndex.size();k++) {
		max = (notNIndex[k] - notNIndex[k-3] - 1 > max) ? notNIndex[k] - notNIndex[k - 2] - 1 : max;
	}
	max = input.size() - 1 - notNIndex[notNIndex.size() - 3]  > max ? input.size() -1 - notNIndex[notNIndex.size() - 3] : max;
	return max;
}

