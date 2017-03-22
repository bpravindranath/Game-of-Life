//************************************************************************
//COSC 501                                              
//Barnabas Ravindranath                                 
//Program Name:  Programming Assignment 2
// 
#include <cstdlib>
#include <fstream>
#include<iostream>
#include<iomanip>

const int SIZE = 30;
void new_line();
char initialize_array(char r[][SIZE], int num);
//initilize the array with character, '.'

void get_input(char g[][SIZE], int num);
//gets user input and puts character where user specifies 
//and updates immage array

char first_array(char r[][SIZE], int num);
//prints out the image array that shows the initial cells

char make_array(char a[][SIZE], char b[][SIZE],int num, int size_d);
//prints array and distributes values from image_2 array to image_2 array 
//so that image can now be read for the next cyle of the while loop

char make_array_1(char g[][SIZE], char b[][SIZE], int num, int size);
//updates image_1 array according to arguements about neighbor cells

int main() {
using namespace std;  
char image[SIZE][SIZE], image_2[SIZE][SIZE], key, input;
 
initialize_array(image, SIZE);

do {
    int z = 0, gen = 0;
    
    get_input(image, SIZE); 
    
    cout << "How many generations do you want to display? ";
    cin >> gen;   
     
     
     while (z < gen) {
        cout << endl << "The " << (z + 1) << "-Generation" << endl;
          
        if (z == 0) {
             first_array(image, SIZE);
             cout << "Press Any Key to Continue!" << endl;
             cin.get(key);
             new_line();
      }
        else {
                
                make_array_1(image, image_2, SIZE, SIZE); 
                make_array(image_2, image, SIZE, SIZE);
                if ((gen - z) == 1) {
                    initialize_array(image, SIZE);
                    break;
                }
                else {
                    cout << "Press Any Key to Continue!" << endl;
                    cin.get(key);
                     new_line();
                }
             }
          
          
          z++;
     }
     cout << endl << "Do you want to do this again? (Yes/No)" << endl;
     cin.get(input);
     new_line();
     
} while((input == 'Y') || (input == 'y'));



    return 0;
}

void new_line() {
    using namespace std;
    char symbol;
    do {
        
        cin.get(symbol);
    } while (symbol != '\n');
}

char initialize_array(char r[][SIZE], int num) {
    using namespace std;
    for(int x = 0; x < SIZE; x++) {
    cout << setw(10);
    for(int y = 0; y < SIZE; y++){
        r[x][y] = '.';   
        }  
    }
    
}

char first_array(char r[][SIZE], int num) {
    using namespace std;
     for(int x = 0; x < SIZE; x++) {
                    cout << setw(10);
                for(int y = 0; y < SIZE; y++){ 
                    cout << r[x][y] << setw(2);  
                    if (y == 29) {
                      cout << endl;
                     }
                 }  
            }
    
}

void get_input(char g[][SIZE], int num) {
    using namespace std;
    int cells, a = 0, b = 0, c = 0; 
    cout << "Please Enter the Number of initial cells: ";
    cin >> cells;

while (a < cells) {
    cout << "The Position of Cell: ";
    cin >> b >> c;
    g[b][c] = '@';
    a++;
}

    
    
}

char make_array(char a[][SIZE],char b[][SIZE], int num, int size_d) {
   using namespace std;
    
   for(int x = 0; x < SIZE; x++) {
    cout << setw(10);
    for(int y = 0; y < size_d; y++){
       b[x][y] = a[x][y]; 
       cout << a[x][y] << setw(2);  
       if (y == 29) {
            cout << endl;
        }
        }  
    }
}

char make_array_1(char g[][SIZE], char b[][SIZE], int num, int size) {
    using namespace std;
int count = 0;
for(int x = 0; x < SIZE; x++) {
  
    for(int y = 0; y < num; y++){
        
            if(x - 1 >= 0) {
            
                if (g[x-1][y] == '@')  {
                count++;

                }
                if (g[x-1][y-1] == '@') {
                count++;
            }
                if (g[x-1][y+1] == '@')  {
                count++;
            }
                
        }
        if(x + 1 < 20) {
            
            if (g[x+1][y] == '@')  {
                 count++;
            }
            if (g[x+1][y-1] == '@')  {
                 count++;
            }
            if (g[x+1][y+1] == '@')  {
                 count++;
            }
            
        }
            
        if(y - 1 >= 0)  {
            if (g[x][y-1] == '@') {
                 count++;
            }
        }
        if(y + 1 < 20)  {
            if (g[x][y+1] == '@') {
                 count++;
            }
        }
        

            if (g[x][y] == '.' && count == 3) {
                    
                    b[x][y] = '@';
                    
                    
                }
            else if (g[x][y] == '@' && count < 2) {
                   b[x][y] = '.';
                      
                }
            else if (g[x][y] == '@' && count > 3) {
                   b[x][y] = '.';
                      
                }
            else if (g[x][y] == '@' && (count == 3 || count == 2)) {
                   b[x][y] = '@';
                      
                }
            else {
                b[x][y] = '.';
            }
 
        count = 0;
            }
        }
    
    
}
 


    
