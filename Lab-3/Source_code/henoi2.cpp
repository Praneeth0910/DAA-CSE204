#include<iostream>
#include<stack>
using namespace std;

struct Task{
	bool isMove;
	int n;
	char src, dest, aux;
};

void hanoiIterative(int totalDisks, char source, char destination, char auxiliary){
	stack<Task> s;
	s.push({false, totalDisks, source, destination, auxiliary});
	while(!s.empty()){
		Task current = s.top();
		s.pop();
		if(current.isMove) {
			cout<<"Move disk"<<current.n<<"from"<<current.src<<"to"<<current.dest<<endl;
		}else{
			if(current.n==1){
				cout<<"Move disk"<<current.n<<"from"<<current.src<<"to"<<current.dest<<endl;
			}
			else {
           			// Base case: only one disk, print directly
               		// Push tasks to the stack in REVERSE order of execution
                
               		// 3. Move n-1 disks from auxiliary to destination
               		s.push({false, current.n - 1, current.aux, current.dest, current.src});
                
			                // 2. Move the largest disk from source to destination
               		s.push({true, current.n, current.src, current.dest, current.aux});
                
			                // 1. Move n-1 disks from source to auxiliary
               		s.push({false, current.n - 1, current.src, current.aux, current.dest});
           	}
    	}
	}
}
int main() {
    cout << "\n--- Iterative (Stack) Towers of Hanoi ---" << endl;
    hanoiIterative(3, 'A', 'C', 'B');
    return 0;
}
