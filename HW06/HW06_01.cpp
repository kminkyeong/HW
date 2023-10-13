#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

float getfrequency(string freq) {
    float f = 0.0;
    if (freq == "3C")	f = 130.81;
    else if (freq == "2B")	f = 246.94/2;
    else if (freq == "3D")	f = 146.83;
    else if (freq == "3E")	f = 164.81;
    else if (freq == "3F")	f = 174.61;
    else if (freq == "3G")	f = 196.0;
    else if (freq == "3A")	f = 220.0;
    else if (freq == "3B")	f = 246.94;
    else if (freq == "4C")	f = 261.83;
    else if (freq == "4D")	f = 293.66;
    else if (freq == "4E")	f = 329.63;
    else if (freq == "4F")	f = 349.23;
    else if (freq == "4G")	f = 392.00;
    else if (freq == "4A")	f = 440.0;
    else if (freq == "4B")	f = 493.88;
    else if (freq == "5C")	f = 523.25;
    else if (freq == "5D")	f = 587.33;
    else if (freq == "5E")	f = 659.26;
    else if (freq == "5F")	f = 698.46;
    else if (freq == "5G")	f = 783.99;
    else if (freq == "5A")	f = 880.00;
    else if (freq == "5B")	f = 987.77;
    return f;
}

float getLength(int eumpyo, int rate) {
    float T = 0.0;
    if (eumpyo == 4)	T = 1.0;
    else if (eumpyo == 8)	T = 0.5;
    else if (eumpyo == 16)	T = 0.25;
    return T * rate;                   //설정다시
}




int main() {
    char header[44];

    ifstream xx("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
    if (!xx) {
        cout << "no Beatles file";
        return 1;
    }
    xx.read(header, 44 * sizeof(char));     //기존 파일 헤더 읽기

    short* n;
    n = (short*)(header + 22);              //numchannels 읽기
    int* fs;
    fs = (int*)(header + 24);               //samplerate 읽기
    int* b;
    b = (int*)(header + 28);                //Byterate 읽기

    int N = fs[0] * 10;                     //N->10*samplerate 로 10초 만들기
    short* data;
    data = new short[N];                    //wav 파일에 입력할 data 만들기

    xx.close();


    int cnt;
    ifstream zz("music.txt");               //정보 들어있는 텍스트 파일 읽기
    if (!zz) {
        cout << "No 'music.txt' file.";
        return 1;
    }
    zz >> cnt;

    ofstream yy("my.wav", ios::binary | ios::out);
    if (!yy) {
        cout << "no 'my.wav' file.";
        return 1;
    }
    yy.write(header, 44 * sizeof(char));        //헤더 작성
    int length, size;
    float f1=440, f2=440;
    string note;
    for (int i = 0; i < cnt; i++) {
        zz >> length >> note >> size;
        if (i % 2) {
            f1 = getfrequency(note);
        }
        else {
            f2 = getfrequency(note);
        }
        
        float soundLength = getLength(length, fs[0]);

        const float pi = 3.141592;
        float dt = 1.0 / fs[0];
        for (int j = 0; j < soundLength; j++) {
            float f1_sample = size * sin(2.0 * pi * f1 * j * dt);
            float f2_sample = size * sin(2.0 * pi * f2 * j * dt);
            data[j] = static_cast<short>(f1_sample + f2_sample);
        }
        yy.write((char*)data, soundLength * sizeof(short));
    }

    yy.close();
    zz.close();
    delete[] data;

    return 0;
}



