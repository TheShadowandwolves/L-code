// L-code.cpp : 
//
#include <iostream>
#include <string>
#include "Var.h"
using namespace std;

void start(int eximanation, list<Var>* val_array) {
    do {
        eximanation = cases(val_array);
    } while (eximanation != 0);
}

int main() {
    list<Var> val_array;
    string user_input, user_start;
    int eximanation = 1;
    user_start = Write();
    if (user_start == "start") {
        start(eximanation, &val_array);
    }
    else if (user_start == "help") {
        Help();
        start(eximanation, &val_array);
    }
    else {
        cout << "ERROR: Wrong Input! - Exiting program with -1";
    }

}

/*
mathematical operations:

[-operator-] [-write to-] [-value 1-] [-value 2-]
##--enum--## ##-string-## ##-[-type of-]<-"char"+[-value-]<-"string/number"-##

load {number, word, text, File }:

[-load-] [-type of-] [-value-]
##enum## ##--enum-## ##-[-type of-]<-"char"+[-value-]<-"string/number"-##

store {number, word, text, File }:

[-store-] [-type of-] [-write to-] [-value-]
##enum## ##--enum-## ##-string-## ##-[-type of-]<-"char"+[-value-]<-"string/number"-##

write {number, word, text, File }:

[-write-] [-type of-] [-value-]
##enum## ##--enum-## ##-string-## ##-[-type of-]<-"char"+[-value-]<-"string/number"-##

print {number, word, text, File }:

[-print-] [-value-]
##enum## ##--enum-## ##-string-## ##-[-type of-]<-"char"+[-value-]<-"string/number"-##

read {number, word, text, File }:

scan {number, word, text, File }:





*/