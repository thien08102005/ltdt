#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack <int> s ;
	s.push(1);
	s.push(5);
	s.push(8);				
	s.push(-2);				
	s.push(3); 	
				      	
   s.pop();
   	cout << s.top() <<"  " ;
   s.pop();
   s.pop();
						       										  														
		while (!s.empty()) {
		cout << s.top() <<"  " ;
	     s.pop();
		}
	
					return 0;
				
				}
