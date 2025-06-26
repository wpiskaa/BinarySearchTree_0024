#include <iostream>
using namespace std;

class node
{
    public:
    int info;
    node *leftchild;
    node *rightchild;

    //Konstruktor class node
    node()
    {
        leftchild = nullptr; // membuat leftchild menjadi NULL
        rightchild = nullptr; // membuat leftchild menjadi NULL
    }
};