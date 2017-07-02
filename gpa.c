#include <stdio.h>

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
			printf("课程 #%d 考试成绩(0～100):\n ->", n);
			scanf("%d",&nScore);

			sumGP += ((nScore<60)?(0.0):(nPoint*(nScore/10-5)));
		}
	}
	printf("你的GPA是：%.1f\n",sumGP/sumPoint);
}

