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
		<<	"�б���ѧGPA������" << endl
		<<	"--------------------------" << endl
		<<	"�����弶�ƿ�Ŀ�����ۺϱ�" << endl
		<<	"  ���㣺95  |  ���ã�85" << endl
		<<	"  �еȣ�75  |  ����65" << endl
		<<	"--------------------------" << endl;

	float sumPoint = 0;	//�γ�ѧ������
	float sumGP = 0.0;	//�γ�ѧ�ּ�������

	int n;	//�γ̱��
	for (n=1; ; n++) {
		float nPoint;	//���γ�ѧ��
		cout
			<< "�γ� #" << n << " ѧ��(�磺4.0�����븺������):" << endl
			<< " ->";
		cin >> nPoint;

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
			cout
				<< "�γ� #" << n << " ���Գɼ�(0��100):" << endl
				<< " ->";
			cin >> nScore;
			
			if (nScore < 0 || nScore > 100) {
				cout << " - ����ĳɼ���Ч�����������룡" << endl;
				goto scoreinput;
			}

			sumGP += getGP(nScore,nPoint);
		}
		
		cout << endl;
		
	}
	cout
		<< "================" << endl
		<< "���GPA�ǣ�\n"
		<< " => " << sumGP/sumPoint << endl
		<< "================" << endl;
	
	cin.get();
	cin.get();
}


