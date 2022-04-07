

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int locateMaximum( const  string  array[ ],  int  n ){
    if(n<=0){
        return -1;
    }
    int num_value;
    string last_value;
    // basically the for loop will go through the items in the array and one by one will check if the current vlaue is greater than the last value, and it will at one point finsd which one is the greatest, the for loop below this one will check what index value the maxium sized word is located at.
    for(int i = 0; i <= (n-1); i++){
        if(i == 0){
            last_value = array[0];
        }
        if (array[i] > last_value){
            if(array[i] == last_value){
                continue;
            }
            last_value = array[i];
            continue;
        }
      }
    for(int z = 0; z <= (n-1); z++){
        if(array[z] == last_value){
            num_value = z;
            break;
        }
    }
    return num_value;
}
bool hasDuplicatedValues( const string array[ ], int  n ){
    if(n<=0){
        return false;
    }
    bool result = false;
    // this will check the first item in the list, and then compare the item to every other item not including itself is a duplicate, if it is result will change to true, otherwise it will stay false
    for(int i = 0; i <= n-1; i++){
        for(int j = i+1; j<= n-1; j++){
            if(array[i] == array[j]){
                result = true;
            }
        }
    }
  
    return result;
}
int countAllVowels( const string array[ ], int n ){
    if(n<=0){
        return -1;
    }
    int num_vowels = 0;
    // this for loop does the entire function in which it will make a for loop for each tiem in the array, and then it will make another forloop for each charecter in the item of the array, and it will then use a swith case to find all the possible vowels in the array
    for(int i = 0; i <= n-1; i++){
        string s = array[i];
        int p = s.size();
        char char_array[p+1];
        strcpy(char_array, s.c_str());
        for (int i = 0; i < p; i++){
            switch(char_array[i]){
                case 'A':
                    num_vowels+=1;
                    break;
                case 'E':
                    num_vowels+=1;
                    break;
                case 'I':
                    num_vowels+=1;
                    break;
                case 'O':
                    num_vowels+=1;
                    break;
                case 'U':
                    num_vowels+=1;
                    break;
                case 'Y':
                    num_vowels+=1;
                case 'a':
                    num_vowels+=1;
                    break;
                case 'e':
                    num_vowels+=1;
                    break;
                case 'i':
                    num_vowels+=1;
                    break;
                case 'o':
                    num_vowels+=1;
                    break;
                case 'u':
                    num_vowels+=1;
                    break;
                case 'y':
                    num_vowels+=1;
                default:
                    break;
            }
        }
    }
    return num_vowels;
}
int moveToEnd( string array[ ], int n, int position ){
    if(n<0){
        return -1;
    }
    if(position < 0){
        return -1;
    }
    int c = n-1;
    // I feel like this code is quite self explanatory as the name of the variables give off what is going on at any given time.
    string temporary_hold = array[(position)];
    array[position] = array[c];
    array[c] = temporary_hold;
    
    return position;
}
int countIntegers( const string array[ ], int  n ){
    if(n<=0){
        return -1;
    }
    bool condition = true;
    int total_int = 0;
    // the for loop will check if each char in each item of the array is a digit, which will keep condition true, if it stays true throughout, then and only then does the total int go up by 1
      for(int i = 0; i <= n-1; i++){
          string s = array[i];
          int p = s.size();
          char char_array[p+1];
          strcpy(char_array, s.c_str());
          for (int i = 0; i < p; i++){
              
              if(isdigit(char_array[i])){
                  condition  = true;
                  continue;
              }
              else{
                  condition = false;
                  break;
              }
          }
          if (condition == true){
              total_int +=1;
          }
          else{
              total_int+=0;
          }
          }
    return total_int;
}
 
int shiftLeft(string array[], int n, int amount, string placeholder){
    if(n<=0){
        return -1;
    }
    if(amount < 0){
        return -1;
    }
  
    int total_change = 0;
    // shifts all data points to the left by 1
    for (int i = 0; i <= (n-1); i++){
        array[i] = array[i+amount];
    }
    int interval = amount;
    while(interval >= 1){
        // changes the now emmpty data sets with "foo" or whatever the placeholder is set to
        if(n - interval >= 0){
            array[n-interval] = placeholder;
        interval--;
        }
        else{
            interval = n;
            array[n-interval] = placeholder;
        interval--;
        }
    }
    for(int i = 0; i <n; i++){
        // checks how many of the items have changed into the palceholder and returns that.
        if (array[i] == placeholder){
            total_change += 1;
        }
    }
    return total_change;
}
int rotateRight( string array[ ], int n, int amount ){
    int po = amount;
    if(n <= 0){
        return -1;
    }
    if(amount<=0){
        return  -1;
    }
    string value;
    int p = amount;
    for(int z = 0; z <= 100; z++){
        if(n-p <= 0){
            p-=n;
        }
        else{
            break;
        }
    }
    
    amount = p;
    if (p == 0){
        return (po*n);
    }
    // makes a huge array which has the ability to store the last few values based on the amount variable and it will then be used to get combined with the rest of the items.
    string array_2[1000];
    while(p >= 1){
       
        string value = array[n-p];
        for(int i=0;i<amount;i++){
            if(array_2[i] != ""){
                continue;
            }
            else{
            array_2[i]+=value;
            break;
            }
        }
        p--;
    }
    string current;
    int w = amount;
    string array_3[1000];
    for (int i = 0; i <= n-amount; i++) {
        array_3[i+w]=array[i];
    }
    for(int i =0; i < amount; i++){
        
        array_3[i] = array_2[i];
        // this will add all of the items from array_2 to array_3 so that array3 now will contain the last values on the left most side.
    }
    for(int i = 0; i < n; i++){
        if(array_3[i] != ""){
            // makes it so that array_3 tranfers its values index by index to array[i] and it will automatically stop as soon as the fucntion realizes that the items are now empty
            array[i] = array_3[i];
            
        }
    }
   /* for(int i = 0; i < n; i++){
        cout<<array[i]<<endl;
    }*/
    return (po*n);
    
}


int main(){
    string folks[8] = {"samwell", "jon", "margaery", "daen23erys", "tyri23on","sansa", "llewmas","noj"};
    string s[7] = {  "AA", "BB", "aa", "bb", "cc", "dd", "ee"  };
    cout<<"locate maximum returns: "<< locateMaximum( folks, 4 )<<endl;
    cout<<boolalpha;
    cout<<"has duplicate values  returns: "<<hasDuplicatedValues( folks, 8 )<<endl;
    cout<<"count all vowels returns: "<<countAllVowels( folks, 8 )<<endl;
    cout<<"move to end returns: "<< moveToEnd( folks, 5, 1 )<<endl;
    cout<<"count integers returns: "<<countIntegers( folks, 5 )<<endl;
    cout<<"rotate right returns: "<<rotateRight( s, 5, 1 )<<endl;
    cout<< "shiftLeft returns: "<<shiftLeft( s, 4, 2, "foo" )<<endl;
}
