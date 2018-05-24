



class truck{
	
	
	public:
	
	void turn();
	void cross();
	void simulate();
	
	
	private:
	
	int *truck;  //트럭 배열.  n개로 초기화되어야함. 안엔 무게 정보 수록
	int *bridge;  // 다리의 길이 배열. 

	int n; // 트럭의 갯수용
	int length; //다리의 길이

	
	
	
};



void truck::cross(int n(트럭수), int* bridge, int* truck, int length )
{
	if(check(한계하중,*bridge,truck[i],다리길이) == true)
	{
		for (   bridge[0~n-1까지] 옆으로 옮긴다 , bridge[0] = truck[i]) // 맨 마지막 요소를 0으로 만들고 맨 마지막 요소를 제외하고 다 옆으로 옮긴다.
	}
	else
	{
		위의 과정을 그대로 하되, bridge[0] = truck[i] 생략
	}
	
	if(마지막이 아니라면)
	{	
		
		턴카운트 +1;
		cross();
	}
	else
	{
		턴카운트 + 1;
		return ;
	}
	
	
}

bool truck::check();
{
	//n[i] 는 현재 다리를 건너야 하는 트럭의 무게
		if((n[i] < 한계하중)  && ( (n[i] + bridge[전체 요소의 합]) < 한계하중) )
				return true;
		else
				return false;
			
	
	
	
	
	
	
	
	
}





int main()
{
		int count = truck::cross();
	
	
}











