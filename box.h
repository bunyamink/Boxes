/*
* @Author
* Student Name: Bünyamin İbrahim Kurt
* Student ID : 150140145
* Date: 06.05.2016
*/
#ifndef BOX_H
#define BOX_H
#include "toy.h"
#include "book.h"

using namespace std;

template <class type>
class Box{
    type *tArray;
    int index, tsize;
    string label;
    float totalWeight, totalLength, totalWidth;
    float weight, length, width, maxWeight;
    public:
        Box();
        Box(float, float, float, float);
        type &operator[](int);
        //type &operator=(const type&);
        ~Box();
        string getLabel(){return label;}
        void setLabel(string _label){label = _label;}
        float getWeight(){return weight;}
        void setWeight(float _weight){weight = _weight;}
        float getLength(){return length;}
        void setLength(float _length){length = _length;}
        float getWidth(){return width;}
        void setWidth(float _width){width = _width;}
        float getMaxWeight(){return maxWeight;}
        void setMaxWeight(float _maxWeight){maxWeight = _maxWeight;}
        void add(type);
        void add(type [], int);
        friend ostream &operator<<( ostream &output, Box<type> &b){
            string tName;
            if(b.tArray[0].getType() == "Toy"){
                tName = "<Toy>";
            }else{
                tName = "<Book>";
            }
            output << "***** Box" << tName << "*****" << endl;
            output << "Box item count: " << b.tsize << endl;
            output << "Size: " << b.getLength() << "x" << b.getWidth() << " Box Weight:" << b.getWeight() << "kg Total/Maximum Allowed Weight:" << b.totalWeight << "/" << b.getMaxWeight() << endl;
            output << "Items: " << endl;
            for(int i = 0; i < b.tsize; i++){
                output << i+1 << ":" << b.tArray[i];
            }
            output << "*********************";
            return output;
        }
};

template<class type>
Box<type>::Box(){
    //cout << "Box constructor" << endl;
    tArray = new type[1];
    tsize = 1;
    index = 0;
    totalWeight = 0;
    label = " ";
    weight = 0.0;
    length = 0.0;
    width = 0.0;
    maxWeight = 0.0;
}

template<class type>
Box<type>::Box(float _weight, float _length, float _width, float _maxWeight){
    //cout << "Box copy constructor" << endl;
    tArray = new type[1];
    tsize = 1;
    index = 0;
    weight = _weight;
    totalWeight = _weight;
    length = _length;
    width = _width;
    maxWeight = _maxWeight;
}

template<class type>
type &Box<type>::operator[](int i){
    if( i >= tsize ){
        string e = "Index out of bounds!";
        throw e;
    }else{
        return tArray[i];
    }
}

/*template<class type>
type &Box<type>::operator=(const type &t){
    if (this != &t) {
        memcpy( tArray, t.tArray, tsize );
    }
    return *this;
}*/

template<class type>
void Box<type>::add(type t){
    string err;
    if(index == tsize){
        type* newTArray = new type[tsize * 2];
        for(int i = 0; i < tsize; i++){
            newTArray[i] = tArray[i];
        }
        //delete [] tArray;
        tArray = newTArray;
        tsize = tsize * 2;

        totalWeight += t.getWeight();
        totalLength += t.getLength();
        totalWidth += t.getWidth();

        if(totalWeight > maxWeight) {
            err = "The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
            throw err;
        }else if((totalLength > length && totalWidth > width) ||(totalLength > width && totalWidth > length)){
            err = "The dimensions of the contained object should be equal or smaller than those of the box!";
            throw err;
        }else{
            tArray[index] = t;
            index++;
        }
    }else{
        totalWeight += t.getWeight();
        totalLength += t.getLength();
        totalWidth += t.getWidth();

        if(totalWeight > maxWeight){
            err = "The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
            throw err;
        }else if((totalLength > length && totalWidth > width) ||(totalLength > width && totalWidth > length)){
            err = "The dimensions of the contained object should be equal or smaller than those of the box!";
            throw err;
        }else{
            tArray[index] = t;
            index++;
        }
    }
}

template<class type>
void Box<type>::add(type t[], int k){
    string err;
    for(int i = 0; i < k; i++){
        if(index == tsize){
            type* newTArray = new type[tsize * 2];
            for(int j = 0; j < tsize; j++){
                newTArray[j] = tArray[j];
            }
            delete [] tArray;
            tArray = newTArray;
            tsize = tsize * 2;
            totalWeight += t[i].getWeight();
            totalLength += t[i].getLength();
            totalWidth += t[i].getWidth();
            tArray[index] = t[i];
            index++;
        }else{
            totalWeight += t[i].getWeight();
            totalLength += t[i].getLength();
            totalWidth += t[i].getWidth();
            tArray[index] = t[i];
            index++;
        }
    }
}

template<class type>
Box<type>::~Box(){
    cout << endl << "Box destructor";
    delete [] tArray;
}

#endif
