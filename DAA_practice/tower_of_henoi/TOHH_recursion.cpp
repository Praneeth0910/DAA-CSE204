#include <iostream>
using namespace std;

void tof(int n, char source, char destination, char auxillary){
    //base case
    if(n==1){
        cout<<"Move disk 1 from"<< source <<" to "<< destination <<endl;
        return;
    }
    tof(n-1, source, auxillary, destination);
    cout<<"Move disk"<<n<<" from "<<source<<" to "<< destination <<endl;
    tof(n-1, auxillary, destination, source);
}
int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    tof(n, 'A', 'C', 'B');
    return 0;
}