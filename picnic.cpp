#include <iostream>
#include <vector>

using namespace std;

int c, n, m;
vector<int>	v;
int cnt = 0;

int recur(vector<int> sav,int a,int check) {
	//1 2 3 4 5 6 -1

	if (sav.size() == n) {
		return cnt++;
	}
	for (int i = a; i < v.size(); i++) {
		//sav 에 들어있는 것들과 하나하나 비교했을때 
		//같은게 있으면 check=1
		for (int j = 0; j < sav.size(); j++) {
			if (sav[j] == v[i] || sav[j + 1] == v[i] || sav[j] == v[i + 1] || sav[j + 1] == v[i + 1]) check = 1;
			j++;
		}
		if (check == 0) {
			sav.push_back(v[i]);
			sav.push_back(v[i + 1]);
			recur(sav, i + 2, 0);
			sav.pop_back();
			sav.pop_back();
		}
		i++;
		check = 0;
	}
	
}


int main() {

	vector<int> sav;
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> n >> m;

		v.assign(m*2, 0);

		for (int j = 0; j < 2 * m; j++) {
			cin >> v[j];		
		}

		sav.clear();
		

		for (int k = 0; k < v.size(); k++) {
			sav.push_back(v[k]);
			sav.push_back(v[k + 1]);

			recur(sav,k+2,0);
			sav.pop_back();
			sav.pop_back();

			k++;
		}
	
		cout << cnt<<endl;
		cnt = 0;
	}


}