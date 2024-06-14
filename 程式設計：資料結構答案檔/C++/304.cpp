#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int m;
	string s0;
	vector<string> v;
	int len;
	int i;
	int ans = 0;
	
	cin >> m;
	while(m--){
		cin >> s0;
		v.push_back(s0);
	} 
	sort(v.begin(), v.end());
	
    for(auto s1:v){
    	len = s1.length(); 
    	for(i=1; i<=len/2; i++){
    		if(s1.substr(0, i) == s1.substr(len-i, i)){
				if(binary_search(v.begin(), v.end(), 
				                 s1.substr(i, len-2*i))){
					ans++;
				}
			}
		}
	}
	cout << ans; 

	return 0;
}