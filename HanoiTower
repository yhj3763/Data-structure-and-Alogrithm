#include <iostream>
#include <vector>
#include <string>

using namespace std;

//For Hanoi Tower, there are three steps to finish moving by recursion.
//1. We need to move n-1 disks to other place that is not destination.
//2. We need to move the disk at the bottom to destination
//3. We need to move n-1 disks to destination from other place that we moved in first step.


void Hanoi(int num, char from, char by, char to)
{

    //When there is only one disk, it starts returning
    if (num == 1)
    {
        cout << "Disk1 is moved from " << from  << " to " << to << endl;
    }
    else
    {
        Hanoi(num - 1, from, to, by);  // It is a step to move n-1 disks to other place called "by" to make place "from" have biggest disk at the bottom only.
        cout << "Disk"<<num<<" is moved from "<< from  << " to " << to << endl;  // It prints other disks except disk1
        Hanoi(num - 1, by, from, to); // It is a step to move n-1 disks to destination.
    }
}

int main()
{
 
    Hanoi(3, 'A', 'B', 'C');
}
