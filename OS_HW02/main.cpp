#include "BankerSAlgorism.h"
#include <queue>
void main(){
	queue<int> processDL;	//依序存放未結束之程序

	//步驟一,初始化所需資料
	Init();
	
	//開始進入步驟二
	while (true){
		int index = -1;	//判斷是否還有未結束且允許配置資源之程序,若有,則index設為該程序對應之索引值,否則維持-1
		for (int i = 0; i < Length_p; i++)
			if (!Finish[i] && LessEqual(Request[i], Work)) index = i;
		
		if (index == -1)break;	//若搜尋失敗,則跳至步驟四

		//步驟三
		Assign(Work, Add(Work, Allocation[index]));	//Work = Work + Allocation[i]
		Finish[index] = true;		
		//回至步驟二
	}
	//結束,步驟四
	
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