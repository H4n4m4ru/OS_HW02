#include "BankerSAlgorism.h"
#include <queue>
void main(){
	queue<int> processDL;	//�̧Ǧs�񥼵������{��

	//�B�J�@,��l�Ʃһݸ��
	Init();
	
	//�}�l�i�J�B�J�G
	while (true){
		int index = -1;	//�P�_�O�_�٦��������B���\�t�m�귽���{��,�Y��,�hindex�]���ӵ{�ǹ��������ޭ�,�_�h����-1
		for (int i = 0; i < Length_p; i++)
			if (!Finish[i] && LessEqual(Request[i], Work)) index = i;
		
		if (index == -1)break;	//�Y�j�M����,�h���ܨB�J�|

		//�B�J�T
		Assign(Work, Add(Work, Allocation[index]));	//Work = Work + Allocation[i]
		Finish[index] = true;		
		//�^�ܨB�J�G
	}
	//����,�B�J�|
	
	bool DeadLock = false;
	
	for (int i = 0; i < Length_p; i++)
		if (!Finish[i]){ 
			DeadLock = true; 
			processDL.push(i);
		}

	if (DeadLock){
		cout << "Deadlock:";
		int DeadLockNumbers = processDL.size();
		for (int i = 0; i < (DeadLockNumbers - 1); i++){
			cout << "p" << processDL.front() << ",";
			processDL.pop();
		}
		cout << "p" << processDL.front() << endl;
	}
	else{
		cout << "No Deadlock\n";
	}
	system("PAUSE");
}