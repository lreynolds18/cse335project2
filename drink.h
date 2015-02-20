#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

#ifndef DRINK_H
#define	DRINK_H

class Drink {
public:
    string sizeConvert(unsigned int x); //function to convert int into size string
    virtual void confirmOrder(); //print function, vary's per drink
    unsigned int getSize() {return size;}
    string getCustomerName() {return customerName;}
    
    virtual ~Drink(){}
    Drink& operator=(const Drink& d);
    Drink(const string cn,const unsigned int s=2):size(s),customerName(cn){} 
    Drink(const Drink& d):size(d.size),customerName(d.customerName) {}
private:
    unsigned int size;
    string customerName;
};

class OrangeJuice:public Drink {
public:
    virtual void confirmOrder();
    OrangeJuice(string cn,unsigned int s,bool p):Drink(cn,s),pulp(p){}
    virtual ~OrangeJuice(){}
    OrangeJuice& operator=(const OrangeJuice& oj);
    OrangeJuice(const OrangeJuice& oj):Drink(oj),pulp(oj.pulp){}\
private:
    bool pulp;
};

class BubbleTea:public Drink {
public:
    virtual void confirmOrder();
    BubbleTea(string cn,unsigned int s,bool h,unsigned int bs):Drink(cn,s),hot(h),bSize(bs){}
    virtual ~BubbleTea(){}
    BubbleTea& operator=(const BubbleTea& bt);
    BubbleTea(const BubbleTea& bt):Drink(bt),hot(bt.hot),bSize(bt.bSize){}\
private:
    unsigned int bSize;
    bool hot;
};

class DrinkList {
public:
    virtual unsigned int getSize() const=0;
    virtual Drink* getDrink(unsigned int i) const=0;
    
    virtual ~DrinkList()=default;
    DrinkList& operator=(const DrinkList& list)=default;
protected:
    DrinkList()=default;
    DrinkList(const DrinkList& list)=default;
};

class OrangeJuiceOrderList:
        public DrinkList{
public:
    virtual unsigned int getSize() const {return dList.size();}
    virtual Drink* getDrink(unsigned int i) const {return dList[i];}
    
    OrangeJuiceOrderList(const vector<OrangeJuice*>& list);
    OrangeJuiceOrderList(const OrangeJuiceOrderList& list);
    OrangeJuiceOrderList& operator=(const OrangeJuiceOrderList& list);
    virtual ~OrangeJuiceOrderList();
private:
    vector<OrangeJuice*> dList;
};

class BubbleTeaList:
        public DrinkList{
public:
    virtual unsigned int getSize() const {return dList.size();}
    virtual Drink* getDrink(unsigned int i) const {return dList[i];}
    
    BubbleTeaList(const vector<BubbleTea*>& list);
    BubbleTeaList(const BubbleTeaList& list);
    BubbleTeaList& operator=(const BubbleTeaList& list);
    virtual ~BubbleTeaList();
private:
    vector<BubbleTea*> dList;
};

#endif	/* DRINK_H */

