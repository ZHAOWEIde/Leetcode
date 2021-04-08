
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

// 1 3 5 7 9 10  
int Microsoft2021WJR::proc1(vector<int> const& arrayList)
{
	int start = 0;
	int result = 0;
	
	if (arrayList.size() < 3)
		return 0;
	while (start <= arrayList.size() - 3) {
		bool isArithmeticProgression = false;
		if (2 * arrayList[start + 1] == arrayList[start] + arrayList[start + 2]) {
			isArithmeticProgression = true;
			result++;
			int difference = arrayList[start+1] - arrayList[start];
			int lastValue = arrayList[start + 2];
			for (int end = start + 3;isArithmeticProgression == true&&end<arrayList.size();end++) {
				if (arrayList[end] - lastValue == difference) {
					result++;
					lastValue = arrayList[end];
				}
				else {
					isArithmeticProgression = false;
				}
			}
		}
		start++;
	}
	return result;
}


int WYHY::candy(vector<int> & arrayList) {
	sort(arrayList.begin(), arrayList.end());
	int num = 0;
	bool same = false;
	int len = arrayList.size();
	int next = 0;
	int i = 0;
	while (i < len && arrayList[i] == 0  ) {
		i++;
		num += 1;
	}
	while (i < len) {
		
		if (i + arrayList[i] < len) {
			next = arrayList[i + arrayList[i]];
			if (next == arrayList[i]) {
				num += arrayList[i] + 1;
				i = next + 1;
			}
			else {
				int k = i + 1;
				while (k <= next) {
					if (arrayList[k] != arrayList[i]) {
						num += arrayList[i] + 1;
						i = k;
						break;
					}
					k++;
				}

			}
		}
		else {
			int k = i + 1;
			while (k <= len) {
				if (k == len || arrayList[k] != arrayList[i] ) {
					num += arrayList[i] + 1;
					i = k;
				}
				k++;
			}
		}
	}
	return num;
}

pair<int, int> WYHY::processLetter(vector<int> const&defineWidth, string& letter)
{
	int row = 1;
	int lastRowWidth = 0;
	int nowWidth = 0;
	string::iterator iter;
	for (iter = letter.begin();iter != letter.end();iter++) {
		if (nowWidth + defineWidth[*iter - 'a'] <= 100) {
			nowWidth += defineWidth[*iter - 'a'];
		}
		else {
			row += 1;
			nowWidth = defineWidth[*iter - 'a'];
		}
	}
	pair<int, int> result = make_pair(row, nowWidth);
	return result;
}
