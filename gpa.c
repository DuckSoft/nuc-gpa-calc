#include <stdio.h>

inline float getGP(float score, float point) {
	if (score < 60) {
		return 0.0;
	} else {
		return point*(score/10-5);
	}
}


int main() {
	float sumPoint = 0;	//�γ�ѧ������
	float sumGP = 0.0;	//�γ�ѧ�ּ�������

	int n;	//�γ̱��
	for (n=1; ; n++) {
		float nPoint;	//���γ�ѧ��
		printf("�γ� #%d ѧ��(�磺4.0�����븺������):\n ->", n);
		scanf("%f", &nPoint);

		if (nPoint < 0) {
			if (n == 1) {
				//�ڵ�һ���γ̾ͽ���ʱ���ز���������
				//Ӧ����ֱ�ӽ���
				return 0;
			}
			break;
		} else {
			sumPoint += nPoint;

			int nScore;	//���γ̿��Գɼ�
scoreinput:
			printf("�γ� #%d ���Գɼ�(0��100):\n ->", n);
			scanf("%d",&nScore);
			
			if (nScore < 0 || nScore > 100) {
				printf(" - ����ĳɼ���Ч�����������룡");
				goto scoreinput;
			}

			sumGP += getGP(nScore,nPoint);
		}
	}
	printf("���GPA�ǣ�%.1f\n",sumGP/sumPoint);
}

