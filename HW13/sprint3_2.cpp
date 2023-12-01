#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <Windows.h>	//Sleep()
using namespace std;

class Queue {
public:
    Queue(int NI, int NO, int capacity) : NI(NI), NO(NO), capacity(capacity) {}

    void sprint3_2(ofstream& outFile) {
        vector<float> queueFullness;
        int lost = 0;
        int NofPackets[120]; 

        for (int i = 0; i < 120; i++) { 
            int ni = rand() % NI;

            if (capacity < queue.size() + ni) {
                lost += queue.size() + ni - capacity;
                ni = capacity - queue.size();
            }

            for (int j = 0; j < ni; j++) {
                queue.push_back(rand() % 20);
            }

            int no = rand() % NO;
            for (int j = 0; j < no; j++) {
                if (!queue.empty()) {
                    queue.erase(queue.begin());
                }
            }

            float queue_infullness = (float(queue.size()) / capacity) * 100;
            queueFullness.push_back(queue_infullness);

            // 2분 지남
            if (i == 119) {
                NofPackets[i] = queue.size();
            }
        }

        float averageFullness = average(queueFullness);

        cout << "Average Queue Fullness: " << averageFullness << "%\n";
        cout << "Packet Loss Rate: " << lost << "\n";

        // 2분이 지난 후 NofPackets[120]에 저장된 값의 평균, 최고치 구함
        float sum = 0;
        int max_Packets = NofPackets[0];

        for (int i = 0; i < 120; i++) {
            sum += NofPackets[i];

            if (NofPackets[i] > max_Packets) {
                max_Packets = NofPackets[i];
            }
        }

        float averagePackets = sum / 120.0;

        cout << "평균 : " << averagePackets << "\n";
        cout << "최고치 : " << max_Packets << "\n";

        // NofPackets[120]를 text file에 저장
        outFile << "Time\tPackets\n";
        for (int i = 0; i < 120; i++) {
            outFile << i << "\t" << NofPackets[i] << "\n";
        }
    }

private:
    int NI;
    int NO;
    int capacity;
    vector<int> queue;

    float average(const vector<float>& data) {
        if (data.empty()) {
            return 0.0f;
        }

        float sum = 0.0f;
        for (float value : data) {
            sum += value;
        }

        return sum / data.size();
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    int fixedNI = 7;
    int fixedCapacity = 10;

    ofstream outFile("sprint3_2.txt");

    Queue queue(fixedNI, 10, fixedCapacity); 

    queue.sprint3_2(outFile);
    cout << "\n";

    outFile.close();

    return 0;
}
