#include <stdio.h>

inline float getGP(float score, float point) {
	if (score < 60) {
		return 0.0;
	} else {
		return point*(score/10-5);
	}
}


int main() {
	float sumPoint = 0;	//课程学分总数
	float sumGP = 0.0;	//课程学分绩点总数

	int n;	//课程编号
	for (n=1; ; n++) {
		float nPoint;	//本课程学分
		printf("课程 #%d 学分(如：4.0；输入负数结束):\n ->", n);
		scanf("%f", &nPoint);

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
			printf("课程 #%d 考试成绩(0～100):\n ->", n);
			scanf("%d",&nScore);
			
			if (nScore < 0 || nScore > 100) {
				printf(" - 输入的成绩无效！请重新输入！");
				goto scoreinput;
			}

			sumGP += getGP(nScore,nPoint);
		}
	}
	printf("你的GPA是：%.1f\n",sumGP/sumPoint);
}

