/*
* @Author
* Student Name: Bünyamin İbrahim Kurt
* Student ID : 150140145
* Date: 06.05.2016
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "box.h"
#include "toy.h"
#include "book.h"

using namespace std;

int main()
{
    //Toy Constructor: label, weight, length, width, containsBattery
    Toy toy1("Lego: Heroes Batman",1.2,0.2,0.3,false);

    //Box Constructor: weight, length, width, maximumAllowedWeight
    Box<Toy> toyBox(0.1,1.0,1.0,7.0);

    try {
        toyBox.add(toy1);
        cout << toyBox[0]<< endl;

        // trying to get the element at(1)
        // should give an error
        cout << toyBox[1] << endl;
    } catch (const string & err_msg) {
        cout <<"### ERROR ### " << err_msg << endl;
    }

    Toy toy2("Lego: Star Wars Death Star",1.7,0.5,0.3,false);
    toyBox.add(toy2);
    cout<<endl<<toyBox<<endl;

    Toy *toyArray= new Toy[2];
    toyArray[0] = Toy("Hot Wheels: Turbine Twister Track Set",1.4,0.3,0.3,false);
    toyArray[1] = Toy("Lego: Heroes Superman",1.6,0.3,0.3,false);

    Box<Toy> toyBox2 = toyBox;
	toyBox2.add(toyArray,2);
	cout << toyBox2;

    delete [] toyArray;
}
