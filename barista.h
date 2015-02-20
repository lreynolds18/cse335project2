#include "drink.h"

#ifndef BARISTA_H
#define	BARISTA_H

class Barista{
public:
    virtual void deliverDrinks(const DrinkList* list)=0;
    
    virtual ~Barista()=default;
    Barista& operator=(const Barista& b)=default;
protected:
    Barista()=default;
    Barista(const Barista& b)=default;
};

class CoolBarista:
public Barista{
public:
    virtual void deliverDrinks(const DrinkList* list);
    
    CoolBarista()=default;
    CoolBarista(const CoolBarista& cb)=default;
    CoolBarista& operator=(const CoolBarista& cb)=default;
    virtual ~CoolBarista()=default;
};

class NewbieBarista:
public Barista{
public:
    virtual void deliverDrinks(const DrinkList* list);
    
    NewbieBarista()=default;
    NewbieBarista(const NewbieBarista& nb)=default;
    NewbieBarista& operator=(const NewbieBarista& nb)=default;
    virtual ~NewbieBarista()=default;
};

#endif	/* BARISTA_H */

