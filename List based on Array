//It is implementing list based on array in c++
//List based on array in C++ has static size, so we cannot change size of list
//It is easier to find value by using index and putting into array, so it give good performance in searching than list based on pointer
//However, when we remove data, it needs to rearrange based on position we removed, so it give bad performance in that aspect.
//Therefore, if I need list in situation that we need to focus on searching, it will be good choice to use.

#include <iostream>


#define LEN_LIST 100

using namespace std;

class ArrayList
{
public:
    ArrayList();                        //initialize value
    // These two functions helps us search list
    bool ListFirst(int* data);          //it stores first value into data(parameter) and return true if it success. 
    bool ListNext(int* data);           //it stores next value into data(parameter) and return true if it success.
    void ListInsert(int data);          //it inserts input data into end of list
    int ListRemove(int data);           //it removes input value in the array and rearrange

private:
    int numofdata;
    int arr[LEN_LIST];
    int current;

};

ArrayList::ArrayList()
{
    numofdata = 0;
    current = -1;
}

bool ArrayList::ListFirst(int* data)
{
    //If there is no data, it gives error with false
    if (numofdata == 0)
    {
        cout << "There is no value in the List" << endl;
        return false;
    }
    
    
    current = 0;      //Make current value from -1 to 0 that means it can start refer values
    *data = arr[0];   //it stores first value into address for data in main function
    return true;

}

bool ArrayList::ListNext(int* data)
{
    //if maximum size is 5 and current is in 4 that means end of list[0,1,2,3,4], it returns false beause there is no next value 
    if (current >= numofdata - 1)
    {
        return false;
    }

    
    current++;                 //move current to next
    *data = arr[current];      //it stores any value that we are refering
    return true;
}

void ArrayList::ListInsert(int data)
{
    //if list has value more than maximum, it gives error message
    if (numofdata >= LEN_LIST)
    {
        cout << "There is no space to add" << endl;
        return;
    }


    arr[numofdata] = data;  //it stores value into end of list
    numofdata++;            //Renewing number of data after we add data
}

int ArrayList::ListRemove(int data)
{
    //if there is no data, it give error
    if (numofdata == 0)
    {
        cout << "There is nothing to remove" << endl;
        return -1;
    }
    
    int idx = 0;

    //Looking for place that value is stored.
    for (int i = 0; i < numofdata; i++)
    {
        if (arr[idx] == data)
        {
            break;
        }
        
        idx++;
      
    }
    

    int rdata = arr[idx]; //Stroing data we want to remove before we remove it

    //After we remove data in the list, we need to rearrange data that makes pull data into previous
    for (int i = idx; i < numofdata -1; i++)
    {
        arr[i] = arr[i + 1];
    }

    numofdata -= 1;

    return rdata;

}




int main()
{
    ArrayList* a = new ArrayList;
    int data;

    a->ListInsert(1);
    a->ListInsert(2);
    a->ListInsert(3);
    a->ListInsert(4);
    a->ListInsert(5);
    a->ListRemove(5);
    



    if (a->ListFirst(&data))
    {
        cout << data << endl;

        while (a->ListNext(&data))
        {
            cout << data << endl;
        }
    }
    
}
