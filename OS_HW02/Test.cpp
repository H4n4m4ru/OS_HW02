#define BANKERALGORISM_CPP
#include "BankerSAlgorism.h"

void Init(){

    fstream FS;	//接收所需文字檔的串流物件
	string FileDirectory, Buffer;	// 檔案路徑 / 讀取檔案資料用之Buffer(string)

	do{
		cout << "Enter the directory of allocation data : ";
		cin >> FileDirectory;
		FS.open(FileDirectory);
	} while (!FS);

	//已讀取Alloction.txt至FS , 開始計算process之數量
	while (getline(FS, Buffer)){
		Length_p++;
	}
	FS.clear();
	FS.seekg(0, FS.beg);

	//已取得process之數量 , 開始計算available resource之數量
	while (FS >> Buffer){
		char ch_Buffer;
		Length_a++;
		FS.get(ch_Buffer);
		if (ch_Buffer == '\n') break;
	}
	FS.clear();
	FS.seekg(0, FS.beg);

	//維度已取得開始建構各資料陣列
	Allocation = new int*[Length_p];	//建構一維

	for (int i = 0; i < Length_p; i++){
		Allocation[i] = new int[Length_a];	//建構二維
		for (int j = 0; j < Length_a; j++){
			FS >> Buffer;
			Allocation[i][j] = stoi(Buffer);//填入資料
		}
	}
	FS.close();

	//Allocation建構完畢,接著是Request
	do{
		cout << "Enter the directory of request data : ";
		cin >> FileDirectory;
		FS.open(FileDirectory);
	} while (!FS);

	Request = new int*[Length_p];	//建構一維

	for (int i = 0; i < Length_p; i++){
		Request[i] = new int[Length_a];	//建構二維
		for (int j = 0; j < Length_a; j++){
			FS >> Buffer;
			Request[i][j] = stoi(Buffer);//填入資料
		}
	}
	FS.close();

	//Request建構完畢,接著是Available
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

	//最後複製Available至Work,以及初始化Finish
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