#include <stdio.h>

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
			printf("�γ� #%d ���Գɼ�(0��100):\n ->", n);
			scanf("%d",&nScore);

			sumGP += ((nScore<60)?(0.0):(nPoint*(nScore/10-5)));
		}
	}
	printf("���GPA�ǣ�%.1f\n",sumGP/sumPoint);
}

