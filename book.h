/*
* @Author
* Student Name: Bünyamin İbrahim Kurt
* Student ID : 150140145
* Date: 06.05.2016
*/
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book{
    string label;
    float weight;
    float length;
    float width;
    public:
        Book();
        ~Book();
        string getLabel(){return label;}
        void setLabel(string _label){label = _label;}
        float getWeight(){return weight;}
        void setWeight(float _weight){weight = _weight;}
        float getLength(){return length;}
        void setLength(float _length){length = _length;}
        float getWidth(){return width;}
        void setWidth(float _width){width = _width;}
};

#endif

