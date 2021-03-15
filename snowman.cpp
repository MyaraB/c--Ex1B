#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"
#include <string>
using namespace std;

const int eight = 8;
const int five = 5;
const int six = 6;
const int seven = 7;


const vector<string> Head = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> Nose = {",", ".", "_", " "};
const vector<string> Leye = {".", "o", "O", "-"};
const vector<string> Reye = {".", "o", "O", "-"};
const vector<string> Larm1 = {" ", "\\", " ", " "};
const vector<string> Larm2 = {"<", " ", "/", " "};
const vector<string> Rarm1 = {" ", "/", " ", " "};
const vector<string> Rarm2 = {">", " ", "\\", " "};
const vector<string> Torso = {" : ", "] [", "> <", "   "};
const vector<string> Base = {" : ", "\" \"", "___", "   "};

int toNum(char a){ // convert a single char to int
    return (a-'0'-1);
}

bool check(string snow) { // check if every "char" in the string is between 1-4
    for (int i = 0; i < snow.size(); i++) {
        if (snow[i] < '1' || snow[i] > '4'){
            return false;
    }}
    return true;

}

namespace ariel {
    string snowman(int num) {
        string snowman;
        string n = to_string(num); // converting the 8 digit string to 8 digit int
        if (n.size()!= eight){
            throw invalid_argument{"not 8 digit length!\n"};
        }
        if (!check(n)){
            throw invalid_argument{"all the digits are not within 1-4 range !\n"};
        }
        snowman+=Head[toNum(n[0])] + "\n" + Larm1[toNum(n[4])] + "(" +Leye[toNum(n[2])];
        snowman+=Nose[toNum(n[1])] + Reye[toNum(n[3])]+ ")" + Rarm1[toNum(n[five])] + "\n" +Larm2[toNum(n[4])];
        snowman+= "(" +Torso[toNum(n[six])] +")" + Rarm2[toNum(n[five])] + "\n" + " " + "(" +Base[toNum(n[seven])]+ ")" + " ";
        return snowman;
    }
};
