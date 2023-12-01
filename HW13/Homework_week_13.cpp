#include <iostream>
#include <Windows.h>	//Sleep()
#include <vector>
using namespace std;

//Sprint 1
//int main() {
//	int elapsedSeconds = 0, x, T = 3;
//	cout << " RANDMAX " << RAND_MAX << endl;
//	while (elapsedSeconds < 18) {
//		Sleep(T * 1000);
//		x = rand() % 100;
//		elapsedSeconds += T;
//		cout << " Elapsed time[sec] = " << elapsedSeconds << "  " << x << endl;
//	}
//	return 123;
//}


//Sprint 2
//int main() {
//	int NI = 7, NO = 15, ni, no;
//	vector <int> q;
//	ni = rand() % NI;
//	for (int i = 0; i < ni; i++) {
//		q.push_back(rand() % 20);
//		cout << q[q.size() - 1] << " in " << q.size() << endl;
//	}
//	no = rand() % NO;
//	for (int i = 0; i < no; i++) {
//		int ii = q[0];
//		if (q.size() != 0) {
//			cout << ii << " out " << q.size() << endl;
//			q.erase(q.begin());
//		}
//	}
//	return 123;
//}


//Sprint 3
int main() {
	vector <int> queue;
	int NI = 10, NO = 10, ni, no;			//NI : input data maximum size, NO = output data maximum size
	int capacity = 10, lost = 0;			//capacity : maximum size of vector

	float queue_fullness[10];				//vector fullness after erase data	(datasize = istime)
	float queue_infullness[10];				//vector fullness after input data	(datasize = istime)
	int Nofpackets[10];						//vectorsize after erase data		(datasize = istime)
	int istime = 10;						//total measure time (unit : second)
	for (int i = 0; i < istime; i++) {

		ni = rand() % NI;
		if (capacity < queue.size() + ni) {			//lost value check
			lost += queue.size() + ni - capacity;
			ni = capacity - queue.size();
		}
		for (int i = 0; i < ni; i++) {				//input randomdata about ni size
			queue.push_back(rand() % 20);
		}
		cout << "queue in : " << queue.size() << endl;
		queue_infullness[i] = (queue.size() * 100) / capacity;		//measure fullness after input data

		no = rand() % NO;
		for (int i = 0; i < no; i++) {				//erase(output) randomdata about no size
			if (queue.size() != 0) {
				cout << queue[0] << "  ";
				queue.erase(queue.begin());
			}
		}
		cout << "\n";
		cout << "\n" << "queue out : " << queue.size() << "\n";

		Nofpackets[i] = queue.size();				//measure vector size after erase data
		queue_fullness[i] = (queue.size() * 100) / capacity;	//measure fullness after erase data
		Sleep(1000);								//delay 1s
	}

	cout << "Nofpackets : ";						//check vector size
	for (int i = 0; i < istime; i++) {
		cout << Nofpackets[i] << "  ";
	}
	cout << "\n";
	for (int i = 0; i < istime; i++) {				//check fullness after input data
		cout << " infullness : " << queue_infullness[i] << "%	";
	}
	cout << "\n";
	for (int i = 0; i < istime; i++) {				//check fullness after erase data
		cout << " fullness : " << queue_fullness[i] << "%	";
	}
	cout << "\n" << "lost : " << lost << endl;		//check total lost value
	return 123;
}
