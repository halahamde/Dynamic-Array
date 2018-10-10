// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 3 - Problem 6
// Program: Dynamic Array
// Purpose: Dynamic Array for increasing or decreasing the size
// Author:  Hala Hamdy Hussein
// Date:    6 october 2018
// Version: 1.0


#include <iostream>

using namespace std;

string* addEntry( string *dynamicArray, int &size1, string newEntry); // this function to add a new word and the Old words to a new dynamic array
                                                                      // return new dynamic array with size 6

string* deleteEntry(string *dynamicArray, int &size1, string entryToDelete); // this function search about word if exist it will delete from the dynamic array
                                                                             // return new dynamic array with size 4
int main()
{
    int size1 = 5 ;
    string * dynamicArr = new string [size1] ; // dynamic array with 5 words from my choice

    dynamicArr[0] = "hala" ;
    dynamicArr[1] = "mayada" ;
    dynamicArr[2] = "naglaa" ;
    dynamicArr[3] = "rahma" ;
    dynamicArr[4] = "sara" ;

    cout << "The New dynamicArray is :  " ;
    dynamicArr = addEntry(dynamicArr, size1, "aya") ; // call the function to add a new word

    for ( int i = 0 ; i < size1+1 ; i++ )
    {
        cout << dynamicArr[i] << " ";   // to print the content of the new dynamic array
    }

    cout << endl << "The New dynamicArray after deleting : " ;
    dynamicArr = deleteEntry(dynamicArr, size1, "hala") ; // call the function to delete a word if exist

    for ( int i = 0 ; i < size1 ; i++ )
    {
        cout << dynamicArr[i] << " ";  // to print the content of the new dynamic array
    }

    delete [] dynamicArr ;
    return 0;
}

string* addEntry( string *dynamicArray, int &size1, string newEntry)
{
    string * dynamicArr1 = new string[size1+1] ; // new dynamic array larger than the old one by 1

    for ( int i = 0 ; i < size1+1 ; i++)
    {
        if ( i == 5)
        {
            dynamicArr1[i] = newEntry ;   // to add the new word in the end of the dynamic array
        }
        else
            dynamicArr1[i] = dynamicArray[i];
    }
    delete[] dynamicArray ;
    return dynamicArr1 ;
}

string* deleteEntry(string *dynamicArray, int &size1, string entryToDelete)
{
    string * dynamicArr2 = new string [size1-1] ;  // new dynamic array smaller than the old one by 1

    if ( (entryToDelete == "hala") || (entryToDelete == "mayada") || (entryToDelete == "naglaa") || (entryToDelete == "rahma") || (entryToDelete == "sara") )
    {
        for ( int i =0 ; i < size1-1 ; i++)
        {
            if ( dynamicArray[i] != entryToDelete )
            {
                dynamicArr2[i] = dynamicArray[i] ;
            }
            else // if the word exist
            {
                dynamicArr2[i] = dynamicArray[i+1] ; // it takes the words after the word you want to delete and put them in the new dynamic array
                i++;
                while ( i < size1-1 )  // to continue in putting the words after the word you want to delete in the new dynamic array
                {
                    dynamicArr2[i] = dynamicArray[i+1] ;
                    i++;
                }
            }
        }
        size1-- ; // decrease the size to print the 4 words after deleting
        delete [] dynamicArray ;
        return dynamicArr2 ;
    }
    else // if the word not exist will return the old 5 words
        return dynamicArray ;
}


