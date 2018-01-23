#include<iostream>
#include <time.h>
#include <vector>
using namespace std;

class buffer{
private:
    int hardDrive[5][4];
    int diskAcces;
    int arrayBufer[5];
    int indiceBuffer;
    int dirtyBit[5];
public:
    void readBuffer(int);
    void writeBuffer(int);
    void modifyBuffer(int);
    int bufferAcces(int);
    bool hardDriveAcces(int);
    void showItems();
    buffer(int);
    ~buffer();
};

void buffer::readBuffer(int elt)
{
    if(indiceBuffer > 4)
            {
                indiceBuffer = 0;
                dirtyBit[indiceBuffer] = 0;
            }

    if(bufferAcces(elt) == 0)
    {
        diskAcces++;
        arrayBufer[indiceBuffer] = elt;
         indiceBuffer++;
    }

}

void buffer::writeBuffer(int elt)
{
    int index = bufferAcces(elt);
    if( index != 0)
    {
        if(dirtyBit[index] == 1)
        {
            diskAcces++;
        }
    }
}

void buffer::modifyBuffer(int elt)
{
    int index = bufferAcces(elt);
    if( index == 0)
    {
        readBuffer(elt);
    }
    dirtyBit[indiceBuffer - 1] = 1;
}

int buffer::bufferAcces(int elt)
{
    int found = 0;
    for(int i = 0; i < 5; i++)
    {
        if(elt == arrayBufer[i])
            {
                found = i;
                break;
            }
    }
    return found;
}

bool buffer::hardDriveAcces(int elt)
{
    bool found = false;
    for (int i = 0; i < 5; i++)
    {
            for (int j = 0; j < 4; j++)
        {
            if (hardDrive[i][j] = elt);
                found = true;
        }
    }

    return found;
}
buffer::buffer(int x)
{
    diskAcces = 0;
    indiceBuffer = 0;
    for (int i = 0; i < 5; i++)
    {
        dirtyBit[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
            for (int j = 0; j < 4; j++)
        {
            hardDrive[i][j] = x;
            x++;
        }
    }
}
void buffer::showItems()
{
     for (int i = 0; i < 5; ++i)
    {
        cout<<arrayBufer[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 5; ++i)
    {
        cout<<dirtyBit[i]<<" ";
    }
    cout<<endl;
    cout<<diskAcces<<endl;
}
buffer::~buffer()
{

}
int main()
{
    srand(time(NULL));
    int x = 0;
    int itemsFile;
    char request;
    int arrayOfItems[10];
    char arrayOfRequest[10];
    buffer operationsFile(0);



    for (int i = 0; i < 10; i++)
    {
        itemsFile = rand() % 20;
        arrayOfItems[i] = itemsFile;
        cout<<itemsFile<<" ";
    }

    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        itemsFile = rand() % 3;
        switch(itemsFile)
        {
            case 0:{
                operationsFile.readBuffer(arrayOfItems[i]);
                request = 'r';
                break ;
            }
            case 1:{
                operationsFile.writeBuffer(arrayOfItems[i]);
                request = 'w';
                break;
            }
            case 2:{
                operationsFile.modifyBuffer(arrayOfItems[i]);
                request = 'm';
                break;
            }
            default:{
                break;
            }

        }
        arrayOfRequest[i] = request;
        cout<<request<<" ";
    }
    cout<<endl;

    operationsFile.showItems();
    return 0;


    cout<<"Hello"<<endl;
    return 0;
}
//
