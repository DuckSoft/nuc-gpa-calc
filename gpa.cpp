#include <iostream>
#include <iomanip>
#include <stdio.h>
inline float getGP(float score, float point) {
	if (score < 60) {
		return 0.0;
	} else {
		return point*(score/10-5);
	}
}


int main() {
	using namespace std;
	setiosflags(ios::fixed);
	setprecision(1);
	
	cout
		<<	"中北大学GPA计算器" << endl
		<<	"--------------------------" << endl
		<<	"附：五级制科目分数折合表：" << endl
		<<	"  优秀：95  |  良好：85" << endl
		<<	"  中等：75  |  及格：65" << endl
		<<	"--------------------------" << endl;

	float sumPoint = 0;	//课程学分总数
	float sumGP = 0.0;	//课程学分绩点总数

	int n;	//课程编号
	for (n=1; ; n++) {
		float nPoint;	//本课程学分
		cout
			<< "课程 #" << n << " 学分(如：4.0；输入负数结束):" << endl
			<< " ->";
		cin >> nPoint;

		if (nPoint < 0) {
			if (n == 1) {
				//在第一个课程就结束时不必参与后面计算
				//应予以直接结束
				return 0;
			}
			break;
		} else {
			sumPoint += nPoint;

			int nScore;	//本课程考试成绩
scoreinput:
			cout
				<< "课程 #" << n << " 考试成绩(0～100):" << endl
				<< " ->";
			cin >> nScore;
			
			if (nScore < 0 || nScore > 100) {
				cout << " - 输入的成绩无效！请重新输入！" << endl;
				goto scoreinput;
			}

			sumGP += getGP(nScore,nPoint);
		}
		
		cout << endl;
		
	}
	cout
		<< "================" << endl
		<< "你的GPA是：\n"
		<< " => " << sumGP/sumPoint << endl
		<< "================" << endl;
	
	cin.get();
	cin.get();
}


