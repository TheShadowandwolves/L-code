#include "Var.h"
#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include <algorithm>
using namespace std;


enum Choices { add, sub, divr, mul, powr, load, write, print, read, scan, endFile, help, store };



//class
void Var::print_c() {
    Print(name + " = " + value);
}


list<Var>::iterator search_val(list<Var>* array, Var var) {
    //Create an iterator of std::list
    std::list<Var>::iterator it;
    list<Var>::iterator is;
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = array->begin(); it != array->end(); it++)
    {
        //Print(it->name);
        if (it->name == var.name) {
            is = it;
            break;
        }
    }
    //Print(is->name);
    return is;
}
// returns Var that has the same name

Var search_var(list<Var>* array, string gname) {
    //Create an iterator of std::list
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    //list<Var>::iterator it;
    // temp class var contains string name, string value and char type
    Var var;
    var.name = "NONE";
    var.value = "0";
    var.type = '!';


    auto it = std::find_if(std::begin(*array),
        std::end(*array),
        [gname](Var const& v) { return v.name == gname; });

    if (array->end() == it)
    {
        std::cout << "item not found" << std::endl;
    }
    else
    {
        const int pos = std::distance(array->begin(), it) + 1;
        //std::cout << "item  found at position " << pos << std::endl;
        var.name = it->name;
        var.value = it->value;
        var.type = it->type;
        //Print("Found with value: " + var.name + var.value);
    }

    return var;
}

bool search_if_val(list<Var>* array, Var var) {
    //Create an iterator of list
    list<Var>::iterator it;

    for (it = array->begin(); it != array->end(); it++)
    {
        // Print(it->name);
        if (it->name == var.name) {
            return true;
        }
    }
    //Print(is->name);
    return false;
}

void change_insid(list<Var>* array, const Var var) {
    // void replace(list<Var> &array, const string &var->name, &var->value ) {
    for (auto it = array->rbegin(); it != array->rend(); it++) {
        if (it->name == var.name) {
            it->type = var.type;
            it->value = var.value;
            /* To stop searching */
            return;
        }
    }
    /* Nothing replaced, error message? */
}

void store_val(list<Var>* val_array, Var var)
{
    if (val_array->empty()) {
        val_array->push_front(var);
        val_array->begin()->print_c();
        //Print("Entering empty");
    }
    else {
        if (!search_if_val(val_array, var)) {
            val_array->push_front(var);
            val_array->begin()->print_c();
            // Print("Entering not found");
        }
        else {
            //Print("Given");
            change_insid(val_array, var);
        }
    }
}




//get digits of string and compare if float or int etc.
string erase_var(string var) {
    var.erase(0, 1);
    return var;
}
char input_type(string var) {
    const char g = var[0];
    //return string
    if (g == '/') {
        return '/';
    }
    //return int
    else if (g == '$') {
        return '$';
    }
    //return double
    else if (g == '%') {
        return '%';
    }
    else if (g == '.') {
        return '.';
    }
    //return false
    else {
        return '!';
    }

}




//void Print(string txt) { cout << "L-> " << txt << endl; }
template <typename T>  void Print(T num) { cout << "L-> " << num << endl; }
//void Print(int num) { cout << "L-> " << num << endl; }
//void Print(double num) { cout << "L-> " << num << endl; }
void Print() { cout << "L-> "; }
string Write() {
    Print();
    string txt;
    cin >> txt;
    return txt;
}


int enumFind() {
    int ok = 0;
    do {
        ok = 0;
        string txt = Write();
        if (txt == "add") {
            return 0;
        }
        else if (txt == "sub") {
            return 1;
        }
        else if (txt == "div") {
            return 2;
        }
        else if (txt == "mul") {
            return 3;
        }
        else if (txt == "powr") {
            return 4;
        }
        else if (txt == "load") {
            return 5;
        }
        else if (txt == "write") {
            return 6;
        }
        else if (txt == "print") {
            return 7;
        }
        else if (txt == "read") {
            return 8;
        }
        else if (txt == "scan") {
            return 9;
        }
        else if (txt == "endFile") {
            return 10;
        }
        else if (txt == "help") {
            return 11;
        }
        else if (txt == "store") {
            return 12;
        }
        else {
            cout << "Wrong input code - cannot understand " << txt << endl;
            Print("Try to input help for all codes available");
            ok = 1;
        }
    } while (ok == 1);
    return 10;
}
//calc of two identical types
string calc_i(string num1, string num2, char op) {
    int res = '!';
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    int n1 = stoi(num1);
    int n2 = stoi(num2);
    if (op == '+') {
        res = n1 + n2;
    }
    else if (op == '-') {
        res = n1 - n2;
    }
    else if (op == '*') {
        res = n1 * n2;
    }
    else if (op == '/') {
        if (n2) {
            res = n1 / n2;
        }
        else {
            cout << "Invalid Input - cannot devide by 0";
        }
    }
    else if (op == '^') {
        res = pow(n1, n2);
    }
    return to_string(res);
}
string calc_d(string num1, string num2, char op) {
    double res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    double n1 = stod(num1);
    double n2 = stod(num2);
    if (op == '+') {
        res = (n1 + n2);
    }
    else if (op == '-') {
        res = (n1 - n2);
    }
    else if (op == '*') {
        res = (n1 * n2);
    }
    else if (op == '/') {

        if (n2) {
            res = n1 / n2;
        }
        else {
            cout << "Invalid Input - cannot devide by 0";
        }
    }
    else if (op == '^') {
        res = pow(n1, n2);
    }
    return to_string(res);
}
string calc_s(string num1, string num2, char op) {
    string res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);

    if (op == '+') {
        res = num1 + num2;
    }
    else if (op == '-') {
        res = num1.substr(0, num2.find(""));
    }
    else if (op == '*') {
        cout << "Invalid operation - cannot multiply strings";
    }
    else if (op == '/') {

        cout << "Invalid Input - cannot devide strings";

    }
    else if (op == '^') {
        cout << "Invalid operation - cannot pow a string";
    }
    return res;
}
// calc of two different types
string calc_id(string num1, string num2, char op) {
    double res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    int n1 = stoi(num1);
    double n2 = stod(num2);
    if (op == '+') {
        res = n1 + n2;
    }
    else if (op == '-') {
        res = n1 - n2;
    }
    else if (op == '*') {
        res = n1 * n2;
    }
    else if (op == '/') {
        if (n2) {
            res = n1 / n2;
        }
        else {
            cout << "Invalid Input - cannot devide by 0";
        }
    }
    else if (op == '^') {
        res = pow(n1, n2);
    }
    return to_string(res);
}
string calc_di(string num1, string num2, char op) {
    double res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    double n1 = stod(num1);
    int n2 = stoi(num2);
    if (op == '+') {
        res = n1 + n2;
    }
    else if (op == '-') {
        res = n1 - n2;
    }
    else if (op == '*') {
        res = n1 * n2;
    }
    else if (op == '/') {
        if (n2) {
            res = n1 / n2;
        }
        else {
            cout << "Invalid Input - cannot devide by 0";
        }
    }
    else if (op == '^') {
        res = pow(n1, n2);
    }
    return to_string(res);
}
// need also for opposite different func
string calc_is_si(string num1, string num2, char op) {
    string res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    int n1 = stoi(num1);
    string n2 = num2;
    if (op == '+') {
        res = num1 + num2;
    }
    else if (op == '-') {
        cout << "Invalid operation - cannot minus string from int";
    }
    else if (op == '*') {
        for (int i = 0; i < n1; i++) {
            num2 += num2;
        }
        res = num2;
    }
    else if (op == '/') {

        cout << "Invalid Input - cannot devide strings";
    }
    else if (op == '^') {
        cout << "Invalid Operation - cannot pow strings";
    }
    return res;
}
string calc_ds_sd(string num1, string num2, char op) {
    string res;
    num1 = erase_var(num1);
    num2 = erase_var(num2);
    int n1 = stoi(num1);
    string n2 = num2;
    if (op == '+') {
        res = num1 + num2;
    }
    else if (op == '-') {
        cout << "Invalid operation - cannot minus string from double";
    }
    else if (op == '*') {
        for (int i = 0; i < n1; i++) {
            num2 += num2;
        }
        res = num2;
    }
    else if (op == '/') {

        cout << "Invalid Input - cannot devide strings";
    }
    else if (op == '^') {
        cout << "Invalid Operation - cannot pow strings";
    }
    return res;
}

char get_variable_type(list<Var>* array, string var) {
    char save = '.';

    var = erase_var(var);
    Var temp = search_var(array, var);
    if (temp.name != "NONE") {
        //Print("type: " + to_string(temp.type));
        return temp.type;
    }
    else {
        return save;
    }
}
string get_variable(list<Var>* array, string var) {
    //Print(var);
    var = erase_var(var);
    //Print("new var: " + var);
    Var temp = search_var(array, var);
    //Print("Found Var name: " + temp.name);
      //Print("Found Var value: " + temp.value);
    if (temp.name != "NONE") {
        string final = temp.type + temp.value;
        // Print(final);
        return final;

    }
    else {
        return var;
    }

}


int cases(list<Var>* val_array)
{
    // array that stores all variables

    int enumVar = enumFind();
    char op;
    string val, res_s;
    Var var1;
    string num1, num2;
    char c1, c2;
    
    switch (enumVar)
    {
    case 0:
    {
        // needs to implement that previous variables can be taken
                 // Print("add");
        op = '+';
        cin >> val;
        var1.name = val;
        cin >> num1;
        cin >> num2;
        //Print(num1);
      //check input type
        c1 = input_type(num1);
        c2 = input_type(num2);
        if (c1 == '.') {
            //Print("Get into .");
            c1 = get_variable_type(val_array, num1);
            //Print(c1);
            num1 = get_variable(val_array, num1);
            //Print(num1);
        }
        if (c2 == '.') {
            c2 = get_variable_type(val_array, num2);
            num2 = get_variable(val_array, num2);
        }

        //equal
        if (c1 == '$' && c2 == '$') {
            var1.value = calc_i(num1, num2, op);
            var1.type = '$';
        }
        else if (c1 == '%' && c2 == '%') {
            var1.value = calc_d(num1, num2, op);
            var1.type = '%';
        }
        else if (c1 == '/' && c2 == '/') {
            num1 = erase_var(num1);
            num2 = erase_var(num2);
            res_s = num1 + num2;
            var1.value = res_s;
            var1.type = '/';
        }
        //different
        else if (c1 == '$' && c2 == '%') {
            var1.value = calc_id(num1, num2, op);
            var1.type = '%';
        }
        else if (c1 == '%' && c2 == '$') {
            var1.value = calc_di(num1, num2, op);
            var1.type = '%';
        }
        else if (c1 == '/' && c2 == '$') {
            var1.value = calc_is_si(num2, num1, op);
            var1.type = '/';
        }
        else if (c1 == '$' && c2 == '/') {
            var1.value = calc_is_si(num1, num2, op);
            var1.type = '/';
        }
        else if (c1 == '/' && c2 == '%') {
            var1.value = calc_ds_sd(num2, num1, op);
            var1.type = '/';
        }
        else if (c1 == '%' && c2 == '/') {
            var1.value = calc_ds_sd(num1, num2, op);
            var1.type = '/';
        }
        else {
            Print("Invalid Operation - cannot convert types");
            break;
        }

        store_val(val_array, var1);
        // var1.print_c();

           // do stuff
        break;
    }
    case 1:
    {
        //Print("sub");
        op = '-';
        cin >> val;
        var1.name = val;
        cin >> num1;
        cin >> num2;
        //check input type
        c1 = input_type(num1);
        c2 = input_type(num2);
        if (c1 == '.') {
            //Print("Get into .");
            c1 = get_variable_type(val_array, num1);
            //Print(c1);
            num1 = get_variable(val_array, num1);
            //Print(num1);
        }
        if (c2 == '.') {
            c2 = get_variable_type(val_array, num2);
            num2 = get_variable(val_array, num2);
        }
        //equal
        if (input_type(num1) == '$' && input_type(num2) == '$') {
            var1.value = calc_i(num1, num2, op);
            var1.type = '$';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '%') {
            var1.value = calc_d(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '/') {

            var1.value = calc_s(num1, num2, op);
            var1.type = '/';
        }
        //different
        else if (input_type(num1) == '$' && input_type(num2) == '%') {
            var1.value = calc_id(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '$') {
            var1.value = calc_di(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '$') {
            var1.value = calc_is_si(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '$' && input_type(num2) == '/') {
            var1.value = calc_is_si(num1, num2, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '%') {
            var1.value = calc_ds_sd(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '/') {
            var1.value = calc_ds_sd(num1, num2, op);
            var1.type = '/';
        }
        else {
            Print("Invalid Operation - cannot convert types");
            break;
        }
        store_val(val_array, var1);
        // var1.print_c();

           // do stuff
        break;
    }
    case 2:
    {
        //Print("div");
        op = '/';
        cin >> val;
        var1.name = val;
        cin >> num1;
        cin >> num2;

        //check input type
        c1 = input_type(num1);
        c2 = input_type(num2);
        if (c1 == '.') {
            //Print("Get into .");
            c1 = get_variable_type(val_array, num1);
            //Print(c1);
            num1 = get_variable(val_array, num1);
            //Print(num1);
        }
        if (c2 == '.') {
            c2 = get_variable_type(val_array, num2);
            num2 = get_variable(val_array, num2);
        }

        //equal
        if (input_type(num1) == '$' && input_type(num2) == '$') {
            var1.value = calc_i(num1, num2, op);
            var1.type = '$';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '%') {
            var1.value = calc_d(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '/') {

            var1.value = calc_s(num1, num2, op);
            var1.type = '/';
        }
        //different
        else if (input_type(num1) == '$' && input_type(num2) == '%') {
            var1.value = calc_id(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '$') {
            var1.value = calc_di(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '$') {
            var1.value = calc_is_si(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '$' && input_type(num2) == '/') {
            var1.value = calc_is_si(num1, num2, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '%') {
            var1.value = calc_ds_sd(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '/') {
            var1.value = calc_ds_sd(num1, num2, op);
            var1.type = '/';
        }
        else {
            Print("Invalid Operation - cannot convert types");
            break;
        }
        store_val(val_array, var1);
        //var1.print_c();
        break;
    }
    case 3:
    {
        //Print("mul");
        op = '*';
        cin >> val;
        var1.name = val;
        cin >> num1;
        cin >> num2;
        //check input type
        c1 = input_type(num1);
        c2 = input_type(num2);
        if (c1 == '.') {
            //Print("Get into .");
            c1 = get_variable_type(val_array, num1);
            //Print(c1);
            num1 = get_variable(val_array, num1);
            //Print(num1);
        }
        if (c2 == '.') {
            c2 = get_variable_type(val_array, num2);
            num2 = get_variable(val_array, num2);
        }
        //equal
        if (input_type(num1) == '$' && input_type(num2) == '$') {
            var1.value = calc_i(num1, num2, op);
            var1.type = '$';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '%') {
            var1.value = calc_d(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '/') {

            var1.value = calc_s(num1, num2, op);
            var1.type = '/';
        }
        //different
        else if (input_type(num1) == '$' && input_type(num2) == '%') {
            var1.value = calc_id(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '$') {
            var1.value = calc_di(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '$') {
            var1.value = calc_is_si(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '$' && input_type(num2) == '/') {
            var1.value = calc_is_si(num1, num2, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '%') {
            var1.value = calc_ds_sd(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '/') {
            var1.value = calc_ds_sd(num1, num2, op);
            var1.type = '/';
        }
        else {
            Print("Invalid Operation - cannot convert types");
            break;
        }

        store_val(val_array, var1);
        // var1.print_c();
           // do stuff
        break;
    }
    case 4:
    {
        //Print("powr");
        op = '^';
        cin >> val;
        var1.name = val;
        cin >> num1;
        cin >> num2;
        // var1.value = to_string(pow(num1, num2)); 
                //check input type
        c1 = input_type(num1);
        c2 = input_type(num2);
        if (c1 == '.') {
            //Print("Get into .");
            c1 = get_variable_type(val_array, num1);
            //Print(c1);
            num1 = get_variable(val_array, num1);
            //Print(num1);
        }
        if (c2 == '.') {
            c2 = get_variable_type(val_array, num2);
            num2 = get_variable(val_array, num2);
        }
        //equal
        if (input_type(num1) == '$' && input_type(num2) == '$') {
            var1.value = calc_i(num1, num2, op);
            var1.type = '$';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '%') {
            var1.value = calc_d(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '/') {

            var1.value = calc_s(num1, num2, op);
            var1.type = '/';

        }
        //different
        else if (input_type(num1) == '$' && input_type(num2) == '%') {
            var1.value = calc_id(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '$') {
            var1.value = calc_di(num1, num2, op);
            var1.type = '%';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '$') {
            var1.value = calc_is_si(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '$' && input_type(num2) == '/') {
            var1.value = calc_is_si(num1, num2, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '/' && input_type(num2) == '%') {
            var1.value = calc_ds_sd(num2, num1, op);
            var1.type = '/';
        }
        else if (input_type(num1) == '%' && input_type(num2) == '/') {
            var1.value = calc_ds_sd(num1, num2, op);
            var1.type = '/';
        }
        else {
            Print("Invalid Operation - cannot convert types");
            break;
        }


        store_val(val_array, var1);
        // var1.print_c();
           // do stuff
        break;
    }
    case 5:
    {
        // do stuff
        break;
    }
    case 6:
    {
        // do stuff
        break;
    }
    case 7:
    {
        // do stuff
        break;
    }
    case 8:
    {

        // do stuff
        break;
    }
    case 9:
    {

        // do stuff
        break;
    }
    case 10:
    {
        return 0;
        // do stuff
        break;
    }
    case 11:
    {
        Help();
        break;
    }
    case 12:
    {
        break;
    }

    default:
    {
        return 0;
        // is likely to be an error
    }
    }
    return 1;
}

void Help() {
    Print("HELP: \n \n MATH INPUTS: \n \n 'add', 'sub', 'div', 'mul', 'powr'\n Insert two number afterwards with space between\n \nTEXT INPUT: \n \n'write' - writes line of text into file\n 'print' - prints out a certain text \n\n FILE INPUT: \n\n 'open' - opens file \n 'close' - closes file \n 'load' - loads the code inside file \n 'read' - reads text of file ('start', 'end')\n 'scan' - write text to file \n\n PROGRAM INPUTS: \n \n'start' - starts the program \n 'endFile' - exit program\n\n");
}
