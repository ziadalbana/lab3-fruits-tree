#ifndef FRUITS_H_INCLUDED
#define FRUITS_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Fruit
{
    Fruit *left, *right;
public:
    string type;
    string shape;
    string Fsize ;
    float weight ;
    Fruit();
    void setLeft(Fruit* n)
    {
        left = n;
    }
    Fruit* getLeft()
    {
        return left;
    }
    void setRight(Fruit* n)
    {
        right = n;
    }
    Fruit* getRight()
    {
        return right;
    }
    float getWeight()
    {
        return weight;
    }
    string getType()
    {
        return type;
    }
    string getShape(){
        return shape;
    }
    string getSize(){
        return Fsize;
    }
};

Fruit ::Fruit()
    : type("Fruit")
    , weight(100)
    , shape("Unknown")
    , Fsize("Unknown")
    , left(NULL)
    , right(NULL)
{
}

class Oval_Fruit: virtual public Fruit
{
public:
    Oval_Fruit()
    {
        shape = "Oval";
    }
};
class Tiny_Fruit: virtual public Fruit
{
public:
    Tiny_Fruit()
    {
        Fsize = "Tiny";
    }
};

class Huge_Fruit: virtual public Fruit
{
public:
    Huge_Fruit()
    {
        Fsize = "Huge";
    }
};


class Circular_Shaped: virtual public Fruit
{
public:
   Circular_Shaped()
    {
        shape = "circular";
    }
};


class Berry: virtual public Fruit
{
public:
    Berry()
    {
        shape = "Berry";
    }
};



class Medium_Fruit: virtual public Fruit
{
public:
    Medium_Fruit()
    {
        Fsize = "Medium";
    }
};

class Apple: public Medium_Fruit, public Oval_Fruit
{
public:
    Apple()
    {
        weight = 195;
        type="Apple";
    }
    Apple(float w)
    {
        weight = w;
        type="Apple";
    }
};

class Avocado: public Medium_Fruit, public Oval_Fruit
{
public:
    Avocado()
    {
        weight = 170;
        type="Avocado";
    }
    Avocado(float w)
    {
        weight = w;
        type="Avocado";
    }
};

class Blackberries: public Tiny_Fruit, public Berry
{
public:
    Blackberries()
    {
        weight = 2.45;
        type="Blackberries";
    }
    Blackberries(float w)
    {
        weight = w;
        type="Blackberries";
    }
};

class Elderberries: public Tiny_Fruit, public Berry
{
public:
    Elderberries()
    {
        weight = 0.5;
        type="Elderberries";
    }
    Elderberries(float w)
    {
        weight = w;
        type="Elderberries";
    }
};


class Gooseberries: public Tiny_Fruit, public Berry
{
public:
    Gooseberries()
    {
        weight = 2.3;
        type="Gooseberries";
    }
    Gooseberries(float w)
    {
        weight = w;
        type="Gooseberries";
    }
};


class Cranberries: public Tiny_Fruit, public Berry
{
public:
    Cranberries()
    {
        weight = 1.7;
        type="Cranberries";
    }
    Cranberries(float w)
    {
        weight = w;
        type="Cranberries";
    }
};

class Blueberries: public Tiny_Fruit, public Berry
{
public:
    Blueberries()
    {
        weight = 0.5;
        type="Blueberries";
    }
    Blueberries(float w)
    {
        weight = w;
        type="Blueberries";
    }
};

class Grapes: public Tiny_Fruit, public Circular_Shaped
{
public:
    Grapes()
    {
        weight = 5;
        type="Grapes";
    }
    Grapes(float w)
    {
        weight = w;
        type="Grapes";
    }
};

class Banana: public Medium_Fruit
{
public:
    Banana()
    {
        weight = 120;
        type="Banana";
    }
    Banana(float w)
    {
        weight = w;
        type="Banana";
    }
};

class Figs: public Medium_Fruit, public Oval_Fruit
{
public:
    Figs()
    {
        weight = 50;
        type="Figs";
    }
    Figs(float w)
    {
        weight = w;
        type="Figs";
    }
};

class Orange: public Medium_Fruit, public Circular_Shaped
{
public:
    Orange()
    {
        weight = 130;
        type="Orange";
    }
    Orange(float w)
    {
        weight = w;
        type="Orange";
    }
};

class Apricot: public Tiny_Fruit, public Circular_Shaped
{
public:
    Apricot()
    {
        weight = 35;
        type="Apricot";
    }
    Apricot(float w)
    {
        weight = w;
        type="Apricot";
    }
};

class Pineapple: public Huge_Fruit, public Oval_Fruit
{
public:
    Pineapple()
    {
        weight = 1590;
        type="Pineapple";
    }
    Pineapple(float w)
    {
        weight = w;
        type="Pineapple";
    }
};

class Peaches: public Medium_Fruit, public Circular_Shaped
{
public:
    Peaches()
    {
        weight = 150;
        type="Peaches";
    }
    Peaches(float w)
    {
        weight = w;
        type="Peaches";
    }
};

class Pear: public Medium_Fruit, public Oval_Fruit
{
public:
    Pear()
    {
        weight = 180;
        type="Pear";
    }
    Pear(float w)
    {
        weight = w;
        type="Pear";
    }
};



class Strawberries: public Tiny_Fruit, public Oval_Fruit
{
public:
    Strawberries()
    {
        weight = 12;
        type="Strawberries";
    }
    Strawberries(float w)
    {
        weight = w;
        type="Strawberries";
    }
};

class Watermelon: public Huge_Fruit, public Circular_Shaped
{
public:
    Watermelon()
    {
        weight = 9000;
        type="Watermelon";
    }
    Watermelon(float w)
    {
        weight = w;
        type="Watermelon";
    }
};

class Guava: public Medium_Fruit, public Oval_Fruit
{
public:
    Guava()
    {
        weight = 200;
        type="Guava";
    }
    Guava(float w)
    {
        weight = w;
        type="Guava";
    }
};


class Mango: public Medium_Fruit, public Oval_Fruit
{
public:
    Mango()
    {
        weight = 200;
        type="Mango";
    }
    Mango(float w)
    {
        weight = w;
        type="Mango";
    }
};

class Cantaloupe: public Huge_Fruit, public Oval_Fruit
{
public:
    Cantaloupe()
    {
        weight = 2750;
        type="Cantaloupe";
    }
    Cantaloupe(float w)
    {
        weight = w;
        type="Cantaloupe";
    }
};






#endif // FRUITS_H_INCLUDED
