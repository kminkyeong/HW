#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class queue {
public:
	queue() {};
	queue(int NI, int NO, int capacity) {
		this->NI = NI;
		this->NO = NO;
		this->capacity = capacity;
	}

	int NI, NO, capacity;

	void FIFO();
};

void queue::FIFO() {
	int elapsedSeconds = 0, T = 1;
	int NofPackets[120];
	int ni, no;
	int lost = 0;
	int overflow = 0;
	int underflow = 0;

	vector <int>q;

	while (elapsedSeconds < 120) {
		Sleep(T * 10);
		elapsedSeconds += T;
		cout << " Elapsed tiem[sec] = " << elapsedSeconds << endl; ni = rand() % NI;

		if (capacity < q.size() + ni) {
			cout << "overflow! " << q.size() + ni << endl;
			overflow += 1;
			lost += q.size() + ni - capacity;
			ni = capacity - q.size();
		}

		for (int i = 0; i < ni; i++) {
			q.push_back(rand() % 20);
		}
		no = rand() % NO;
		for (int i = 0; i < no; i++) {
			if (q.size() != 0) {
				q.erase(q.begin());
			}
			else {
				cout << "underflow " << endl;
				underflow += 1;
				break;
			}
		}
		NofPackets[elapsedSeconds - 1] = q.size();
		cout << NofPackets[elapsedSeconds - 1] << endl;
	}
	int avg = 0;
	int max = 0;
	for (int i = 0; i < 120; i++) {
		avg += NofPackets[i];
		if (max < NofPackets[i])max = NofPackets[i];
	}
	avg /= 120;
	cout << "평균 패킷 개수 : " << avg << endl;
	cout << "최고 패킷 개수 : " << max << endl;
	cout << "손실된 패킷 개수 : " << lost << endl;
	cout << "overflow 발생 횟수: " << overflow << endl;
	cout << "underflow 발생 횟수 " << underflow << endl;
	ofstream out("data.txt");
	for (int i = 0; i < 120; i++) {
		out << NofPackets[i] << endl;
	}
}

void main() {
	queue q1(10, 10, 10);
	queue q2(10, 10, 100);
	queue q3(50, 10, 100);
	queue q4(10, 50, 100);
	q1.FIFO();
	q2.FIFO();
	q3.FIFO();
	q4.FIFO();
}