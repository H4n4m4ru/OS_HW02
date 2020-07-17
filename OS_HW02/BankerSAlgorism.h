#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

#ifdef BANKERALGORISM_CPP
#define AUTOEXT
#else
#define AUTOEXT extern
#endif

AUTOEXT int Length_p, Length_a; // processes / available resources 的數目
AUTOEXT int* Available, *Work;
AUTOEXT int** Allocation, **Request;
AUTOEXT bool* Finish;
//	可使用資源[] / 預先配置資源[][] / 需求資源[][] / 儲存可使用資源[] / 程序結束狀態[]

void Init();				//初始化所有資料陣列: Allocation / Available / Request / Work / Finish
void Assign(int*, int*);	//將右側陣列內容依序指派至左側
bool Equal(int*, int);		//檢查陣列內容是否皆為比較用數值
bool LessEqual(int*, int*);	//檢查陣列內層是否皆小於等於比較用數值
int* Add(int*, int*);		//將兩陣列內容相加並回傳結果之新陣列

/*因為無法直接使用像:

void operator=(int* left_arr, int* right_arr){
for(int i = 0; i < Length_a; i++)
left_arr[i] = right_arr[i];
}
→ Work = Available;

或是

bool operator==(int* arr, int cprValue){
for(int i = 0; i < Length_a ; i++)
if(arr[i] != cprValue) return false;
return true;
}
→ if( Allocation[i] != 0) Finish[i] = false;

等等...來重載operator (-.-) 只好用比較沒那麼直觀的方法來實做
*/
