#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int A, B;
void integrateSin(double a, double b, int n) {
	float dt, num = 0, anal = 0;
	anal = (-A / B) * (cos(B * b) - cos(B * a));                                                    //analytic ���
	dt = (b - a) / n;
	for (int i = 0; i < n; i++) {                                                       //numerical, t���� ���Լ� �ٻ�ȭ
		num += A * sin(B * (a + dt * i)) * dt;
	}
	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic ������
}

void integrateCos(double a, double b, int n) {
	float dt, num = 0, anal = 0;
	anal = (A / B) * (sin(B * b) - sin(B * a));                                                    //analytic ���
	dt = (b - a) / n;
	for (int i = 0; i < n; i++) {                                                       //numerical, t���� ���Լ� �ٻ�ȭ
		num += A * cos(B * (a + dt * i)) * dt;
	}
	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic ������
}

void differentiateSin(float t, float dt) {
	float anal = 0, num = 0;
	anal = A * B * cos(B * t);                                 //analytic
	num = A * (sin(B * (t + dt)) - sin(B * t)) / dt; //numerical, t���� ���Լ� �ٻ�ȭ

	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%" << endl;//numerical, analytic ������
}

void differentiateCos(float t, float dt) {
	float anal = 0, num = 0;
	anal = -A * B * sin(B * t);                                 //analytic
	num = A * (cos(B * (t + dt)) - cos(B * t)) / dt; //numerical, t���� ���Լ� �ٻ�ȭ

	cout << " num: " << num << " anal: " << anal << endl;
	cout << " error = " << ((num - anal) / anal) * 100 << "%\n";//numerical, analytic ������
}

void main() {
	int N;
	float t, dt, anal = 0, num = 0;
	string equat;
	string type;
	cout << "�������� ������ �Է��ϼ��� (�����Լ� / �ﰢ�Լ� / �����Լ�) : ";		//������ ���� ����
	cin >> equat;

	if (equat == "�����Լ�") {														//1. �����Լ� �̺�/����
		cout << "�̺а� ������ �����ϼ��� : ";										//�̺�/���� ����
		cin >> type;
		cout << "�ְ������� ������ �Է��ϼ��� : ";									//��������
		cin >> N;
		int* Coeff;																	//��� -> �����Ҵ�
		Coeff = (int*)malloc((N + 1) * sizeof(int));
		if (Coeff == NULL) {
			cout << "���� �Ҵ翡 �����Ͽ����ϴ�.";
		}
		cout << "�ְ����׺��� ������� ����� �Է��ϼ��� : ";
		for (int i = 0; i < N + 1; i++) {
			cin >> Coeff[i];														//��� �Է¹ޱ�
		}
		
		if (type == "�̺�") {														//�����Լ� �̺�
			cout << "t, dt�� �Է��ϼ��� : ";
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
		
		else if (type == "����") {													//�����Լ� ����
			float a, b, n;
			float anal1 = 0, anal2 = 0;
			cout << "a, b, N�� �Է��ϼ��� : ";
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
			cout << "�Է��� �߸� �Ǿ����ϴ�." << endl;
		}
	}

	else if (equat == "�ﰢ�Լ�") {													//2. �ﰢ�Լ� �̺�/����
		float x, a, b, n;
		string func;
		cout << "�̺а� ������ �����ϼ��� : ";
		cin >> type;
		cout << "sin�� cos�� �����ϼ��� : ";
		cin >> func;
		cout << " Asin(Bt) or Acon(Bt)�� A B�� ���� �Է��ϼ��� = ";
		cin >> A >> B;
		
		if (type == "�̺�") {
			cout << "t dt�� �Է��ϼ��� : ";
			cin >> t >> dt;
			if (func == "sin") {
				differentiateSin(t, dt);
			}
			else if (func == "cos") {
				differentiateCos(t, dt);
			}
		}
		else if (type == "����") {
			cout << "a, b, N�� �Է��ϼ��� : ";
			cin >> a >> b >> n;
			if (func == "sin") {
				integrateSin(a, b, n);
			}
			else if (func == "cos") {
				integrateCos(a, b, n);
			}
		}
		else {
			cout << "�Է��� �߸� �Ǿ����ϴ�." << endl;
		}
	}

	else if (equat == "�����Լ�") {													//3. �����Լ�(���� �����) �̺�/����
		float k, x, l;
		cout << "�̺а� ������ �����ϼ��� : ";										//�̺�/���� ����
		cin >> type;

		cout << "���, ��, ���� ����� ������� �Է��ϼ��� ";
		cin >> k >> x >> l;

		if (type == "�̺�") {														//�̺�
			cout << "t, dt�� �Է��ϼ��� : ";
			cin >> t >> dt;
			if (x <= 0 || x == 1) {
				cout << "���� ������ �ٽ� �����Ͻÿ�.";								//���� ������ ������ ��
			}
			else {
				x = pow(x, l);
				anal = k * pow(x, t) * log(x);
				num = k * (pow(x, t + dt) - pow(x, t)) / dt;

				cout << "num " << num << "  anal " << anal << endl;
				cout << "error = " << (num - anal) / anal * 100 << "%" << endl;
			}
		}
		else if (type == "����") {													//����
			float a, b;
			int n;

			cout << "a, b, N�� �Է��ϼ��� : ";
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
			cout << "�Է��� �߸� �Ǿ����ϴ�." << endl;
		}
	}

	else {
		cout << "������ ������ �߸� �ԷµǾ����ϴ�." << endl;
	}

}