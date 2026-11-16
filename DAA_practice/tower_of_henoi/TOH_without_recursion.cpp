#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& from, stack<int>& to, char fromRod, char toRod){
    if(from.empty()) return;
    if(to.empty() || from.top() < to.top()){
        to.push(from.top());
        cout<<"Move disk"<<from.top()<<" from "<< fromRod<< " to " << toRod;
        from.pop();
    } else{
        from.push(to.top());
        cout<<"Move disk" << to.top() << " from " << toRod << " to " << fromRod << endl;
        to.pop();
    }
}
void toh(int n){
    stack<int> source, destination, auxillary;
    for ( int disk = n; disk >= 1; disk--){
        source.push(disk);
    }
    int totalMoves = (1 << n) - 1;
    for(int move = 1; move<= totalMoves; move++){
        if(n%2==1){
            if(move % 3 == 1){
                moveDisk(source, destination, 'A', 'C');
            }
            else if(move % 3 == 2){
                moveDisk(source, auxillary, 'A', 'B');
            }
            else{
                moveDisk(auxillary, destination, 'B', 'C');
            }
        }
        else{
            if(move % 3 ==1){
                moveDisk(source, auxillary, 'A', 'C');
            }
            else if(move % 3 == 2){
                moveDisk(source, destination, 'A', 'C');
            }
            else{
                moveDisk(auxillary, destination, 'B', 'C');
            }
        }
    }
}
int main(){
    int n = 3;
    toh(n);
    return 0;
}