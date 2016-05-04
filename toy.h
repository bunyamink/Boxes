/*
* @Author
* Student Name: Bünyamin İbrahim Kurt
* Student ID : 150140145
* Date: 06.05.2016
*/
#ifndef TOY_H
#define TOY_H

using namespace std;

class Toy{
    string label, type;
    float weight;
    float length;
    float width;
    bool containsBattery;
    public:
        Toy();
        Toy(string , float , float , float , bool );
        ~Toy();
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
        bool getContainsBattery(){return containsBattery;}
        void setContainsBattery(bool _containsBattery){containsBattery = _containsBattery;}
        friend ostream &operator<<( ostream &output, Toy &t){
            bool f = t.getContainsBattery();
            if(f == true){
                output << "Toy Label: " << t.getLabel() << " # " << t.getLength() << "x" << t.getWidth() << " " << t.getWeight();
                output << "kg " << "Yes Battery" << endl;
                return output;
            }else{
                output << "Toy Label: " << t.getLabel() << " # " << t.getLength() << "x" << t.getWidth() << " " << t.getWeight();
                output << "kg " << "No Battery" << endl;
                return output;
            }
        }
};

Toy::Toy(){
    //cout << "Toy constructor" << endl;
    type = "Toy";
    label = " ";
    weight = 0.0;
    width = 0.0;
    length = 0.0;
    containsBattery = false;
}

Toy::Toy(string _label, float _weight, float _length, float _width, bool _containsBattery){
    //cout << "Toy copy constructor" << endl;
    type = "Toy";
    label = _label;
    weight = _weight;
    length = _length;
    width = _width;
    containsBattery = _containsBattery;
}

Toy::~Toy(){}

#endif

