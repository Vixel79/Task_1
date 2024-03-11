#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>


using namespace std;



int main() {
    int y ;
    cout<<"===============Rail fence cipher===============";
    // make a menu to choose from encryption program or decryption program or exiting the program and do it in a loop
    while (true) {
        cout<<endl<<endl;
        //Display the menu
        cout << "1) Encryption" << endl
             << "2) Decryption" << endl
             << "3) Exit Program" << endl
             << "Choose a number from 1 , 2 and 3:";
        //take the input y from user to choose the program
        cin >> y;


        //Check if the input is 1 or 2 or 3 , if not then take another input from user
        while (y != 1 && y != 2 && y != 3) {
            cout << "Choose a number from 1 , 2 and 3:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> y;
        }

        //if input y is equal to 1 then start the encryption program
        if (y == 1) {
            //initialize k for key and l for the length of text that will be encrypted
            int k, l;
            //initialize 6 inputs (s, w, w1, w2, w3, w4)
            string s, w, w1, w2, w3, w4;
            cout << "Choose a key either 3 or 4:";
            //ignore the last input to make sure program takes input well
            cin.ignore();
            //take the key input from user
            cin >> k;
            //check if key is equal to 3 or 4
            while (k != 4 && k != 3) {
                //if not take input again
                cout << "Choose a key either 3 or 4:";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> k;
            }
            //take input text to encrypt
            cout << "Enter your Text:";
            cin.ignore();
            getline(cin, s);

            //take only chracters from the inout s and add it to string w
            for (int i = 0; i < s.length(); i++) {
                if (isalpha(s[i])) {
                    w += s[i];
                }
            }
            //define l equall to length of w
            l = w.length();

            //if key input is equal to 3
            if (k == 3) {
                //take first char and move 4 steps in length of text and take another char and add all of them to string w1
                for (int j = 0; j < l; j += 4) {
                    w1 += w[j];
                }
                //take second char and move 2 steps in length of text and take another char and add all of them to string w2
                for (int j = 1; j < l; j += 2) {
                    w2 += w[j];
                }
                //take third char and move 4 steps in length of text and take another char and add all of them to string w3
                for (int j = 2; j < l; j += 4) {
                    w3 += w[j];
                }
            }

            //if key input is equal to 4
            if (k == 4) {
                //take first char and move 6 steps in length of text and take another char and add all of them to string w1
                for (int j = 0; j < l; j += 6) {
                    w1 += w[j];
                }
                //take second char and move 2 steps in length of text and take another char and then if last move was 2 steps then add 4 steps and vice versa add ,  all of them to string w2
                for (int j = 1, i = 0; j < l; i++) {
                    w2 += w[j];
                    if (i % 2 == 0) {
                        j += 4;
                    } else {
                        j += 2;
                    }
                }
                //take second char and move 4 steps in length of text and take another char and then if last move was 4 steps then add 2 steps and vice versa add ,  all of them to string w3
                for (int j = 2, i = 0; j < l; i++) {
                    w3 += w[j];
                    if (i % 2 == 1) {
                        j += 4;
                    } else {
                        j += 2;
                    }
                }
                //take fourth char and move 6 steps in length of text and take another char and add all of them to string w4
                for (int j = 3; j < l; j += 6) {
                    w4 += w[j];
                }
            }
            // display the 4 strings beside eachother to make one text
            cout << endl <<"Encrypted text:" << w1 << w2 << w3 << w4;
            cout<<endl<<"________________________________________________________________________________";
        }




        else if (y == 2) {
            //initialize k for key and l for the length of text that will be encrypted
            int k, l;
            //initialize 2 strings (w, w1)
            string w, w1;
            cout << "Choose a key either 3 or 4:";
            cin.ignore();
            //take input key
            cin >> k;
            //check if key is equal to 3 or 4
            while (k != 4 && k != 3) {
                //if not then take input again
                cout << "Choose a key either 3 or 4:";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> k;
            }
            //take the input w (text) from the user
            cout << "Enter your Text:";
            cin.ignore();
            cin >> w;
            //define l equal to length of w (text)
            l = w.length();
            //make a matrix of length equal to key input and width equal to length of text
            char m[k][l];
            //make a loop that makes all of the slots in matrix is equal to "."
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < l; j++) {
                    m[i][j] = '.';
                }
            }
            //initialize x to take the last count of j from each loop and pass it to the next one to start from
            int x;
            //if key is equal to 3
            if (k == 3) {
                //take first char and move 4 steps in length of text and then add it to the next slot in the first row
                for (int i = 0, j = 0; i < l; i += 4) {
                    m[0][i] = w[j];
                    j++;
                    x = j;
                }
                //take the last char from the previous loop char and move 2 steps in length of text and then add it to the next slot in the second row
                for (int i = 1, j = x; i < l; i += 2) {
                    m[1][i] = w[j];
                    j++;
                    x = j;
                }
                //take the last char from the previous loop char and move 4 steps in length of text and then add it to the next slot in the third row
                for (int i = 2, j = x; i < l; i += 4) {
                    m[2][i] = w[j];
                    j++;
                }
            }

            //if key is equal to 4
            else if (k == 4) {
                //take first char and move 6 steps in length of text and then add it to the next slot in the first row
                for (int i = 0, j = 0; i < l; i += 6) {
                    m[0][i] = w[j];
                    j++;
                    x = j;
                }
                //take the last char from the previous loop char and move 2 steps in length of text and then add it to the next slot and then add 4 and then vice versa in the second row
                for (int i = 1, j = x, z = 0; i < l; j++, z++) {
                    m[1][i] = w[j];
                    if (z % 2 == 0) {
                        i += 4;
                    } else {
                        i += 2;
                    }
                    x = j;
                }
                //take the last char from the previous loop char and move 4 steps in length of text and then add it to the next slot and then add 2 and then vice versa in the third row
                for (int i = 2, j = x + 1, z = 0; i < l; j++, z++) {
                    m[2][i] = w[j];
                    if (z % 2 == 0) {
                        i += 2;
                    } else {
                        i += 4;
                    }
                    x = j;
                }
                //take the last char from the previous loop and move 6 steps in length of text and then add it to the next slot in the first row
                for (int i = 3, j = x + 1; i < l; i += 6) {
                    m[3][i] = w[j];
                    j++;
                }

            }

            //display the matrix
            cout << endl << "Decrypted text matrix:"<<endl;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < l; j++) {
                    cout << m[i][j] << " ";
                }
                cout << endl;
            }
            //take each character fro every column starting from first one and add it to empty string w1
            for (int j = 0; j < l; j++) {
                for (int i = 0; i < k; i++) {
                    if (isalpha(m[i][j])) {
                        w1 += m[i][j];
                    }
                }
            }


            cout << endl << "Decrypted text:"<<w1;
            cout<<endl<<"________________________________________________________________________________";
        }

        // if y is equal to 3 ,exit the program
        else if (y ==3){
            return 0;
        }
    }
}
