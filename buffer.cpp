/*
Auteur: Pisani Fosso

*/
#include<iostream>
#include <time.h>
#include <vector>
using namespace std;

#define rotationTime 10;

class buffer{
private:
    int hardDrive[5][4];
    int arrayBufer[5];
    int dirtyBit[5];
    int diskAcces;
    int indiceBuffer;
	int index;
public:
    void readBuffer(int);
    void writeBuffer(int);
    void modifyBuffer(int);
    bool bufferAcces(int);
    int hardDriveAccesTime(int);
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

    if(bufferAcces(elt) == false)
    {
        hardDriveAccesTime(elt);
        arrayBufer[indiceBuffer] = elt;
        indiceBuffer++;
    }
}

void buffer::writeBuffer(int elt)
{
    if( bufferAcces(elt) == false)
    {
		hardDriveAccesTime(elt);
	}
    
	else
      {
         dirtyBit[index] = 1;
      }
}

void buffer::modifyBuffer(int elt)
{
    int index = bufferAcces(elt);
    if( bufferAcces(elt) == false)
    {
        readBuffer(elt);
    }
    dirtyBit[indiceBuffer - 1] = 1;
}

bool buffer::bufferAcces(int elt)
{
    for(int i = 0; i < 5; i++)
    {
        if(elt == arrayBufer[i])
            {
				index = i;
                return true;
            }
    }
    return false;
}

int buffer::hardDriveAccesTime(int elt)
{
	int findItemTime = 0;
    for (int i = 0; i < 5; i++)
    {
            for (int j = 0; j < 4; j++)
        {
            if (hardDrive[i][j] = elt);
                findItemTime += 2;
        }
    }

    return diskAcces += findItemTime;
}

void buffer::showItems()
{
	cout<<"Dans le buffer: "<<endl<<endl;
     for (int i = 0; i < 5; ++i)
    {
        cout<<arrayBufer[i]<<"\t";
    }

    cout<<endl;
	cout<<"Dirty bits"<<endl<<endl;
    for (int i = 0; i < 5; ++i)
    {
        cout<<dirtyBit[i]<<"\t";
    }
    cout<<endl;
    cout<<diskAcces<<endl;
}

buffer::buffer(int x)
{

    diskAcces = 0;
    indiceBuffer = 0;
    for (int i = 0; i < 5; i++)
    {
        dirtyBit[i] = 0;
		arrayBufer[i] = 0;
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
        cout<<itemsFile<<"\t";
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
        cout<<request<<"\t";
    }
    cout<<endl;

    operationsFile.showItems();
    return 0;
}
//main
