#include "barista.h"
#include <algorithm>
using std::swap;

void CoolBarista::deliverDrinks(const DrinkList* list) {
    //sort vector keeps track of the sorted order list should be in by index
    //without altering list
    vector<unsigned int> sort;
    for(unsigned int i=0;i<list->getSize();i++){
        sort.push_back(i);
    }
    //insertion sorting the list
    for(unsigned int key=1;key<list->getSize();key++){
        for(unsigned int i=key;i>0;i--){
            if (list->getDrink(sort[i])->getCustomerName()<list->getDrink(sort[i-1])->getCustomerName()){
                swap(sort[i],sort[i-1]);
            }
            else{
                break;
            }
        }
    }
    //serving the drinks from list based on sort
    cout<<"Cool Barista: Order's up!"<<endl;
    string currentCustomer;
    unsigned int index=0;
    while(index<list->getSize()){
        currentCustomer=list->getDrink(sort[index])->getCustomerName();
        unsigned int count=0;
        while(index<list->getSize()&&currentCustomer==list->getDrink(sort[index])->getCustomerName()){
            index++;
            count++;
        }
        cout<<"I have "<<count<<" drinks for "<<currentCustomer<<endl;
        for(unsigned int i=index-count;i<index;i++){
            list->getDrink(sort[i])->confirmOrder();
            cout<<endl;
        }
        cout<<endl;
    }
}

void NewbieBarista::deliverDrinks(const DrinkList* list) {
    //sort vector keeps track of the sorted order list should be in by index
    //without altering list
    vector<unsigned int> sort;
    for(unsigned int i=0;i<list->getSize();i++){
        sort.push_back(i);
    }
    //insertion sorting sort vector by the order list should be in
    for(unsigned int key=1;key<list->getSize();key++){
        for(unsigned int i=key;i>0;i--){
            if (list->getDrink(sort[i])->getSize()<list->getDrink(sort[i-1])->getSize()){
                swap(sort[i],sort[i-1]);
            }
            else{
                break;
            }
        }
    }
    //serving the drinks from list based on sort
    cout<<"Newbie Barista: Order's up!"<<endl;
    unsigned int currentSize;
    unsigned int index=0;
    while(index<list->getSize()){
        currentSize=list->getDrink(sort[index])->getSize();
        unsigned int count=0;
        while(index<list->getSize()&&currentSize==list->getDrink(sort[index])->getSize()){
            index++;
            count++;
        }
        cout<<"I have "<<count<<" drinks of size "<<currentSize<<endl;
        for(unsigned int i=index-count;i<index;i++){
            list->getDrink(sort[i])->confirmOrder();
            cout<<endl;
        }
        cout<<endl;
    }
}
