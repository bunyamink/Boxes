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
    string label, type;
    float weight;
    float length;
    float width;
    public:
        Book();
        Book(string , float , float , float);
        ~Book();
        string getLabel(){return label;}
        void setLabel(string _label){label = _label;}
        string getType(){return type;}
        void setType(string _type){type = _type;}
        float getWeight(){return weight;}
        void setWeight(float _weight){weight = _weight;}
        float getLength(){return length;}
        void setLength(float _length){length = _length;}
        float getWidth(){return width;}
        void setWidth(float _width){width = _width;}
        friend ostream &operator<<( ostream &output, Book &b){
            output << "Toy Label: " << b.getLabel() << " # " << b.getLength() << "x" << b.getWidth() << " " << b.getWeight();
            output << "kg " << endl;
            return output;
        }
};

Book::Book(){
    //cout << "Book constructor" << endl;
    type = "Book";
    label = " ";
    weight = 0.0;
    width = 0.0;
    length = 0.0;
}

Book::Book(string _label, float _weight, float _length, float _width){
    //cout << "Book copy constructor" << endl;
    type = "Book";
    label = _label;
    weight = _weight;
    length = _length;
    width = _width;
}

Book::~Book(){}

#endif

