#include <iostream>
using namespace std;

int main(void)
{	
	char c;
	bool flag = true; //true for left, false for right
	
	//==========================	
	ios::sync_with_stdio(0);
	cin.tie(0);
	//==========================

	while(cin.get(c)){
		if(c == '"'){
			cout << (flag? "``" : "''");
			flag = !flag;
		}else{
			cout << c;
		}
	}

	return 0; 
}

