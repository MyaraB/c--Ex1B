#include <iostream>
#include <vector>
#include <stdexcept>
#include "snowman.hpp"
#include <string>
#include <cstdlib>

using namespace ariel;

int main(){
    char goAgain = 'y';
    int count,num1,num2,num3; 
    while (goAgain == 'y' || goAgain == 'Y'){
    cout <<"This is a lottery game, u must choose three digits between 1-4 \n Two snowmans will be printed out. If they are identical you win!!!" << endl;
        int num[3];
        for (int i=0; i<3; i++){ 

            cout <<" \n please choose a single digit between 1-4\n" << endl;
            cin >> num[i];
            while(!cin || num[i]<1 || num[i]>4){
            
                cout << "Not a valid input, please choose an integer between 1-4: "; // incorrect input
                cin.clear();
                cin.ignore();
                cin >> num[i];
        }

        }
        

    
        cout <<"you have successfully chosen the numbers: " <<num[0] << "," << num[1] << "," << num[2] << "\n" << endl;
    
    
    
int userchoise, lottery;
userchoise = 0; 
lottery = 0;
userchoise = num[0];
userchoise = userchoise*10;
userchoise = userchoise+num[1];
userchoise = userchoise*10;
userchoise = userchoise+num[2];

lottery = rand()% 4 +1;
lottery = lottery * 10;
lottery = lottery +rand()% 4 +1;
lottery = lottery * 10;
lottery = lottery +rand()% 4 +1;

for(int i=0; i<5; i++){
    int lottery1 = rand()% 4 +1;
    userchoise = userchoise*10;
    lottery = lottery*10;
    userchoise= userchoise+lottery1;
    lottery = lottery+lottery1;
}

cout <<" your guess is:" << endl;
cout << snowman(userchoise) << " \n\n "<< endl;
cout <<" the winning snowman is:" << endl;
cout << snowman(lottery) << "\n\n" << endl; 
//cout << "lottery:" << lottery << " ,userchoice:" << userchoise << endl;

if ( lottery == userchoise){
    cout <<" Congratulations!!! You won!!! \n" << endl;
}
else {
    cout <<"better luck next time \n" << endl;
}
cout <<" do you want to try again? (y/n) \n" << endl;
cin >> goAgain; 
}
}