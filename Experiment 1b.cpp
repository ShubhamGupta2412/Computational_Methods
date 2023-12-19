#include<iostream>
using namespace std;
int main(){
	int count=0;
	for(int i=1; i<=2000; i++){
		if((i%2!=0||i%3!=0||i%5!=0)&&i%7==0){
			count++;
		}
	}
	cout << count;
}
