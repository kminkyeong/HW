#include <iostream>
using namespace std;

/*
int main() {			//1D array
	//A, B ��� ���� -> ��� ��� C ��ķ�
	int N_A, M_A, N_B, M_B;
	cout << "A ��Ŀ��� N, M�� ������� �Է��ϼ��� : ";
	cin >> N_A >> M_A;
	cout << "B ��Ŀ��� N, M�� ������� �Է��ϼ��� : ";
	cin >> N_B >> M_B;
	float* A, * B, * C;
	A = new float[N_A * M_A];
	B = new float[N_B * M_B];
	C = new float[N_A * M_B];
	cout << "A ����� ���� ������� �Է��ϼ��� : " << endl;
	for (int i = 0; i < N_A * M_A; i++) {
		cin >> A[i];
	}
	cout << "B ����� ���� ������� �Է��ϼ��� : " << endl;
	for (int i = 0; i < N_B * M_B; i++) {
		cin >> B[i];
	}
	
	//matrix multi
	if (M_A != N_B) {			//A����� ���� B����� ���� ��ġ�ؾ� ��
		cout << "����� ���� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	float result = 0;
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n * M_B + m] = 0;
			for (int k = 0; k < M_A; k++) {
				result += A[n * N_A + k] * B[k * M_B + m];		//C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j] + ... + A[i][k] * B[k][j]
			}
			C[n * M_B + m] = result;
			result = 0;
		}
	}


	//matrix add
	if((N_A != N_B) || (M_A != M_B)) {
		cout << "����� ������ �������� �ʽ��ϴ�.";
		return 0;
	}
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n * M_B + m] = A[n * M_B + m] + B[n * M_B + m];
		}
	}


	//matix minus
	if ((N_A != N_B) || (M_A != M_B)) {
		cout << "����� ������ �������� �ʽ��ϴ�.";
		return 0;
	}
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n * M_B + m] = A[n * M_B + m] - B[n * M_B + m];
		}
	}
	

	//show C matrix
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_B; j++) {
			cout << C[i * M_B + j] << "  ";
		}
		cout << endl;
	}
}
*/




int main() {		//2D array matrix
	int N_A, M_A, N_B, M_B;
	cout << "A ��Ŀ��� N, M�� ������� �Է��ϼ��� : ";
	cin >> N_A >> M_A;
	cout << "B ��Ŀ��� N, M�� ������� �Է��ϼ��� : ";
	cin >> N_B >> M_B;
	float** A, ** B, ** C;
	A = new float* [N_A];
	for (int n = 0; n < N_A; n++) {
		A[n] = new float[M_A];
	}
	B = new float* [N_B];
	for (int n = 0; n < N_B; n++) {
		B[n] = new float[M_B];
	}
	C = new float* [N_A];
	for (int n = 0; n < N_A; n++) {
		C[n] = new float[M_B];
	}
	cout << "A ����� ���� ������� �Է��ϼ��� : " << endl;
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_A; j++) {
			cin >> A[i][j];
		}
	}
	cout << "B ����� ���� ������� �Է��ϼ��� : " << endl;
	for (int i = 0; i < N_B; i++) {
		for (int j = 0; j < M_B; j++) {
			cin >> B[i][j];
		}
	}
	
	//matix multi
	if (M_A != N_B) {			//A����� ���� B����� ���� ��ġ�ؾ� ��
		cout << "����� ���� �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n][m] = 0;
			for (int k = 0; k < M_A; k++) {
				C[n][m] += A[n][k] * B[k][m];
			}
		}
	}


	//matix add
	if ((N_A != N_B) || (M_A != M_B)) {			//A����� ���� B����� ���� ��ġ�ؾ� ��
		cout << "����� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n][m] = A[n][m] + B[n][m];
		}
	}


	//matrix minus
	if ((N_A != N_B) || (M_A != M_B)) {			//A����� ���� B����� ���� ��ġ�ؾ� ��
		cout << "����� ������ �������� �ʽ��ϴ�." << endl;
		return 0;
	}
	for (int n = 0; n < N_A; n++) {
		for (int m = 0; m < M_B; m++) {
			C[n][m] = A[n][m] - B[n][m];
		}
	}


	//show C matrix
	for (int i = 0; i < N_A; i++) {
		for (int j = 0; j < M_B; j++) {
			cout << C[i][j] << "  ";
		}
		cout << endl;
	}
}
