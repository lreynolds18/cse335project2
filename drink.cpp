#include "drink.h"
#include "barista.h"

string Drink::sizeConvert(unsigned int x) { //converts int to size string
    if (x==1) {return("small");}
    else if (x==2) {return("medium");}
    else if (x==3) {return("large");}
    else return("invalid size");
}

void Drink::confirmOrder() {
    cout<<customerName<<" ordered a "<<sizeConvert(size)<<" drink of ";
}

Drink& Drink::operator =(const Drink& d) {
    if(this != &d) {
        size=d.size;
        customerName=d.customerName;
    }
    return *this;
}

void OrangeJuice::confirmOrder()  {
    Drink::confirmOrder();
    cout<<"orange juice with ";
    if (!pulp) {cout<<"no ";}
    cout<<"pulp";
}

OrangeJuice& OrangeJuice::operator =(const OrangeJuice& oj){
    if(this != &oj){
        pulp=oj.pulp;
        Drink::operator =(oj);
    }
    return *this;
}

void BubbleTea::confirmOrder()  {
    Drink::confirmOrder();
    if (hot) {cout<<"hot";} //not in sample output, but part of project
    else {cout<<"warm";}    //specification.
    cout<<" bubble tea with "<<sizeConvert(bSize)
            <<" bubbles";
}

BubbleTea& BubbleTea::operator =(const BubbleTea& bt){
    if(this != &bt){
        hot=bt.hot;
        bSize=bt.bSize;
        Drink::operator =(bt);
    }
    return *this;
}

OrangeJuiceOrderList::OrangeJuiceOrderList(const vector<OrangeJuice*>& list){
    for(unsigned int i=0;i<list.size();i++){
        if(list[i]){
            dList.push_back(new OrangeJuice(*list[i]));
        }
    }
}

OrangeJuiceOrderList::OrangeJuiceOrderList(const OrangeJuiceOrderList& list){
    for(unsigned int i=0;i<list.dList.size();i++){
        if(list.dList[i]){
            dList.push_back(new OrangeJuice(*list.dList[i]));
        }
    }
}

OrangeJuiceOrderList::~OrangeJuiceOrderList(){
    for(unsigned int i=0;i<dList.size();i++){
        delete dList[i];
    }
}

OrangeJuiceOrderList& OrangeJuiceOrderList::operator =(const OrangeJuiceOrderList& list){
    if(this!=&list){
        for(unsigned int i=0;i<dList.size();i++){
            delete dList[i];
        }
        dList.clear();
        for(unsigned int i=0;i<list.dList.size();i++){
            if(list.dList[i]){
                dList.push_back(new OrangeJuice(*list.dList[i]));
            }
        }
    }
    return *this;
}

BubbleTeaList::BubbleTeaList(const vector<BubbleTea*>& list){
    for(unsigned int i=0;i<list.size();i++){
        if(list[i]){
            dList.push_back(new BubbleTea(*list[i]));
        }
    }
}

BubbleTeaList::BubbleTeaList(const BubbleTeaList& list){
    for(unsigned int i=0;i<list.dList.size();i++){
        if(list.dList[i]){
            dList.push_back(new BubbleTea(*list.dList[i]));
        }
    }
}

BubbleTeaList::~BubbleTeaList(){
    for(unsigned int i=0;i<dList.size();i++){
        delete dList[i];
    }
}

BubbleTeaList& BubbleTeaList::operator =(const BubbleTeaList& list){
    if(this!=&list){
        for(unsigned int i=0;i<dList.size();i++){
            delete dList[i];
        }
        dList.clear();
        for(unsigned int i=0;i<list.dList.size();i++){
            if(list.dList[i]){
                dList.push_back(new BubbleTea(*list.dList[i]));
            }
        }
    }
    return *this;
}
