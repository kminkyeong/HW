#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int A, B;
void integrateSin(double a, double b, int n) {
	float dt, num = 0, anal = 0;
	anal = (-A / B) * (cos(B * b) - cos(B * a));                                                    //analytic 결과
	dt = (b - a) / n;
	for (int i = 0; i < n; i++) {                                                       //numerical, t에서 도함수 근사화
		num += A * sin(B * (a + dt * i)) * dt;
	}
	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic 오차율
}

void integrateCos(double a, double b, int n) {
	float dt, num = 0, anal = 0;
	anal = (A / B) * (sin(B * b) - sin(B * a));                                                    //analytic 결과
	dt = (b - a) / n;
	for (int i = 0; i < n; i++) {                                                       //numerical, t에서 도함수 근사화
		num += A * cos(B * (a + dt * i)) * dt;
	}
	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic 오차율
}

void differentiateSin(float t, float dt) {
	float anal = 0, num = 0;
	anal = A * B * cos(B * t);                                 //analytic
	num = A * (sin(B * (t + dt)) - sin(B * t)) / dt; //numerical, t에서 도함수 근사화

	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic 오차율
}

void differentiateCos(float t, float dt) {
	float anal = 0, num = 0;
	anal = -A * B * sin(B * t);                                 //analytic
	num = A * (cos(B * (t + dt)) - cos(B * t)) / dt; //numerical, t에서 도함수 근사화

	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%\n";//numerical, analytic 오차율
}

void main() {
	int N;
	float t, dt, anal = 0, num = 0;
	string equat;
	string type;
	cout << "방정식의 유형을 입력하세요 (다항함수 / 삼각함수 / 지수함수) : ";		//방정식 유형 결정
	cin >> equat;

	if (equat == "다항함수") {														//1. 다항함수 미분/적분
		cout << "미분과 적분을 선택하세요 : ";										//미분/적분 선택
		cin >> type;
		cout << "최고차항의 차수를 입력하세요 : ";									//차수결정
		cin >> N;
		int* Coeff;																	//계수 -> 동적할당
		Coeff = (int*)malloc((N + 1) * sizeof(int));
		if (Coeff == NULL) {
			cout << "동적 할당에 실패하였습니다.";
		}
		cout << "최고차항부터 순서대로 계수를 입력하세요 : ";
		for (int i = 0; i < N + 1; i++) {
			cin >> Coeff[i];														//계수 입력받기
		}
		
		if (type == "미분") {														//다항함수 미분
			cout << "t, dt를 입력하세요 : ";
			cin >> t >> dt;
			for (int i = 0; i < N + 1; i++) {
				anal += Coeff[i] * (N - i) * pow(t, (N-i-1));						//analytical
			}
			float num_1 = 0, num_2 = 0;
			for (int i = 0; i < N + 1; i++) {										//numerical
				num_1 += Coeff[i] * pow(t, (N-i));
				num_2 += Coeff[i] * pow((t + dt), (N - i));
			}
			num = (num_2 - num_1) / dt;
			cout << "anal = " << anal << " num = " << num << endl;
			cout << "error = " << (abs(anal - num) / anal) * 100 << "%" << endl;
		}
		
		else if (type == "적분") {													//다항함수 적분
			float a, b, n;
			float anal1 = 0, anal2 = 0;
			cout << "a, b, N을 입력하세요 : ";
			cin >> a >> b >> n;
			float num = 0;				
			for (int i = 0; i < N + 1; i++) {										//analytical
				anal1 += Coeff[i] * pow(b, (N - i + 1)) / (N - i + 1);
				anal2 += Coeff[i] * pow(a, (N - i + 1)) / (N - i + 1);
			}
			anal = anal1 - anal2;
			dt = (b - a) / n;
			for (int i = 0; i < n; i++) {											//numerical
				for (int j = 0; j < N + 1; j++) {
					num += Coeff[j] * pow((a + dt * i), (N - j)) * dt;
				}
			}
			cout << "anal = " << anal << " num = " << num << endl;
			cout << "error = " << (abs(anal - num) / anal) * 100 << "%" << endl;
		}
		
		else {
			cout << "입력이 잘못 되었습니다." << endl;
		}
	}

	else if (equat == "삼각함수") {													//2. 삼각함수 미분/적분
		float x, a, b, n;
		string func;
		cout << "미분과 적분을 선택하세요 : ";
		cin >> type;
		cout << "sin과 cos을 선택하세요 : ";
		cin >> func;
		cout << " Asin(Bt) or Acon(Bt)의 A B에 대해 입력하세요 = ";
		cin >> A >> B;
		
		if (type == "미분") {
			cout << "t dt를 입력하세요 : ";
			cin >> t >> dt;
			if (func == "sin") {
				differentiateSin(t, dt);
			}
			else if (func == "cos") {
				differentiateCos(t, dt);
			}
		}
		else if (type == "적분") {
			cout << "a, b, N을 입력하세요 : ";
			cin >> a >> b >> n;
			if (func == "sin") {
				integrateSin(a, b, n);
			}
			else if (func == "cos") {
				integrateCos(a, b, n);
			}
		}
		else {
			cout << "입력이 잘못 되었습니다." << endl;
		}
	}

	else if (equat == "지수함수") {													//3. 지수함수(밑이 상수인) 미분/적분
		float k, x, l;
		cout << "미분과 적분을 선택하세요 : ";										//미분/적분 선택
		cin >> type;

		cout << "계수, 밑, 지수 계수의 순서대로 입력하세요 ";
		cin >> k >> x >> l;

		if (type == "미분") {														//미분
			cout << "t, dt를 입력하세요 : ";
			cin >> t >> dt;
			if (x <= 0 || x == 1) {
				cout << "밑의 범위를 다시 설정하시오.";								//밑의 범위가 오류일 때
			}
			else {
				x = pow(x, l);
				anal = k * pow(x, t) * log(x);
				num = k * (pow(x, t + dt) - pow(x, t)) / dt;

				cout << "num " << num << "  anal " << anal << endl;
				cout << "error = " << (num - anal) / anal * 100 << "%" << endl;
			}
		}
		else if (type == "적분") {													//적분
			float a, b;
			int n;

			cout << "a, b, N을 입력하세요 : ";
			cin >> a >> b >> n;

			x = pow(x, l);
			anal = k * (pow(x, b) - pow(x, a)) / log(x);
			dt = (b - a) / n;
			num = 0;
			for (int i = 0; i < n; i++) {
				num += k * pow(x, a + dt * i) * dt;
			}
			cout << "num " << num << "  anal " << anal << endl;
			cout << "error = " << (num - anal) / anal * 100 << "%" << endl;
		}
		else {
			cout << "입력이 잘못 되었습니다." << endl;
		}
	}

	else {
		cout << "방정식 유형이 잘못 입력되었습니다." << endl;
	}

}