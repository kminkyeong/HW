#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class Queue {
public:
    Queue(int initial_NI, int initial_NO, int initial_capacity)
        : NI(initial_NI), NO(initial_NO), capacity(initial_capacity) {}

    void sprint4(ofstream& outFile) {
        vector<float> queue_fullness;
        int lost = 0;

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
            queue_fullness.push_back(queue_infullness);
        }

        float averageFullness = average(queue_fullness);

        cout << "Average queue fullness: " << averageFullness << "%\n";
        cout << "Packet loss rate: " << lost << "\n";

        // 실험 결과를 파일에 저장
        outFile << NO << "\t" << averageFullness << "\t" << lost << "\n";
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

    ofstream outFile("sprint4.txt");

    // NO를 변화시키기
    for (int varyingNO = 5; varyingNO <= 15; varyingNO += 2) {
        Queue queue(fixedNI, varyingNO, fixedCapacity);

        cout << "NO=" << varyingNO << ":\n";
        queue.sprint4(outFile);
        cout << "\n";
    }

    outFile.close();

    return 0;
}

