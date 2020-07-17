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

AUTOEXT int Length_p, Length_a; // processes / available resources ���ƥ�
AUTOEXT int* Available, *Work;
AUTOEXT int** Allocation, **Request;
AUTOEXT bool* Finish;
//	�i�ϥθ귽[] / �w���t�m�귽[][] / �ݨD�귽[][] / �x�s�i�ϥθ귽[] / �{�ǵ������A[]

void Init();				//��l�ƩҦ���ư}�C: Allocation / Available / Request / Work / Finish
void Assign(int*, int*);	//�N�k���}�C���e�̧ǫ����ܥ���
bool Equal(int*, int);		//�ˬd�}�C���e�O�_�Ҭ�����μƭ�
bool LessEqual(int*, int*);	//�ˬd�}�C���h�O�_�Ҥp�󵥩����μƭ�
int* Add(int*, int*);		//�N��}�C���e�ۥ[�æ^�ǵ��G���s�}�C

/*�]���L�k�����ϥι�:

void operator=(int* left_arr, int* right_arr){
for(int i = 0; i < Length_a; i++)
left_arr[i] = right_arr[i];
}
�� Work = Available;

�άO

bool operator==(int* arr, int cprValue){
for(int i = 0; i < Length_a ; i++)
if(arr[i] != cprValue) return false;
return true;
}
�� if( Allocation[i] != 0) Finish[i] = false;

����...�ӭ���operator (-.-) �u�n�Τ���S�����[����k�ӹ갵
*/
