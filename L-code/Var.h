#pragma once
#include <list>
#include <string>
using namespace std;

class Var {
public:
    string name;
    string value;
    char type;
    void print_c();
};

//void Print(string);
void Print();
template <typename T>  void Print(T);
string Write();
int cases(list<Var>*);
list<Var>::iterator search_val(list<Var>*, Var);
bool search_if_val(list<Var>*, Var);
void store_val(list<Var>*, Var);
void Help();
void store_val(list<Var>*, Var);
string erase_var(string);
char input_type(string);