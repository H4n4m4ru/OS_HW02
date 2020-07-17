#define BANKERALGORISM_CPP
#include "BankerSAlgorism.h"

void Init(){

    fstream FS;	//�����һݤ�r�ɪ���y����
	string FileDirectory, Buffer;	// �ɮ׸��| / Ū���ɮ׸�ƥΤ�Buffer(string)

	do{
		cout << "Enter the directory of allocation data : ";
		cin >> FileDirectory;
		FS.open(FileDirectory);
	} while (!FS);

	//�wŪ��Alloction.txt��FS , �}�l�p��process���ƶq
	while (getline(FS, Buffer)){
		Length_p++;
	}
	FS.clear();
	FS.seekg(0, FS.beg);

	//�w���oprocess���ƶq , �}�l�p��available resource���ƶq
	while (FS >> Buffer){
		char ch_Buffer;
		Length_a++;
		FS.get(ch_Buffer);
		if (ch_Buffer == '\n') break;
	}
	FS.clear();
	FS.seekg(0, FS.beg);

	//���פw���o�}�l�غc�U��ư}�C
	Allocation = new int*[Length_p];	//�غc�@��

	for (int i = 0; i < Length_p; i++){
		Allocation[i] = new int[Length_a];	//�غc�G��
		for (int j = 0; j < Length_a; j++){
			FS >> Buffer;
			Allocation[i][j] = stoi(Buffer);//��J���
		}
	}
	FS.close();

	//Allocation�غc����,���۬ORequest
	do{
		cout << "Enter the directory of request data : ";
		cin >> FileDirectory;
		FS.open(FileDirectory);
	} while (!FS);

	Request = new int*[Length_p];	//�غc�@��

	for (int i = 0; i < Length_p; i++){
		Request[i] = new int[Length_a];	//�غc�G��
		for (int j = 0; j < Length_a; j++){
			FS >> Buffer;
			Request[i][j] = stoi(Buffer);//��J���
		}
	}
	FS.close();

	//Request�غc����,���۬OAvailable
	do{
		cout << "Enter the directory of available data : ";
		cin >> FileDirectory;
		FS.open(FileDirectory);
	} while (!FS);

	Available = new int[Length_a];

	for (int i = 0; i < Length_a; i++){
		FS >> Buffer;
		Available[i] = stoi(Buffer);
	}
	FS.close();

	//�̫�ƻsAvailable��Work,�H�Ϊ�l��Finish
	Work = new int[Length_a]; Finish = new bool[Length_p];
	Assign(Work, Available);
	for (int i = 0; i < Length_p; i++){
		if (!Equal(Allocation[i], 0)) Finish[i] = false;
		else Finish[i] = true;
	}
}

void Assign(int* left_arr, int* right_arr){
	for (int i = 0; i < Length_a; i++)
		left_arr[i] = right_arr[i];
}

bool Equal(int* _arr, int cprValue){
	for (int i = 0; i < Length_a; i++)
		if (_arr[i] != cprValue) return false;
	return true;
}

bool LessEqual(int* left_arr, int* right_arr){
	for (int i = 0; i < Length_a; i++)
		if (left_arr[i] > right_arr[i]) return false;
	return true;
}

int* Add(int* left_arr, int* right_arr){
	int* newArr = new int[Length_a];
	for (int i = 0; i < Length_a; i++)
		newArr[i] = left_arr[i] + right_arr[i];
	return newArr;
}