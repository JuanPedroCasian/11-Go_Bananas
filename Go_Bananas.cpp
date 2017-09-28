/*
Go_Bananas.cpp
Sep 26, 2017
Juan Casian
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GetDocName(string& DocName){         //This Function has been explained in previous excercises, but is a simple user input and checking if the input works with the program

  cout << "Please insert the name of the document you wish to analize: " << endl;
  cin >> DocName;

  ifstream TestFile (DocName);

  if (TestFile.good() == false){

    cout << "Unable to open this file, please try again." << endl;
    GetDocName (DocName);
  }
}

void GetDocData (string& DocData, const string& DocName){     /*
                                                              Here we learn two new things about the function

                                                              const
                                                              first is when you add: const. before the type of variable
                                                              This will keep the value of the function constant so you won't
                                                              change the variable's value

                                                              &
                                                              this symbol after the variable type (string&) makes it a referenced variable
                                                              which means that what you change in the variable inside tha function will
                                                              change it also from where you call it.
                                                              
                                                              */
                                                          // This function passes the info in the file to a string to be able to analyze it
  string DataLine;

    ifstream TestFile (DocName);

    while (TestFile.eof() == false){    // This gets the lines of the file and then adds it to the rest of the String

      getline(TestFile, DataLine);              /*
                                                  This getline function is new. It gets the whole info from a complete lines
                                                   The function works like this:
                                                  getline(PlaceFromWhereYouGetTheInfo, VariableWhereYouWillPlaceTheInfo);
                                                */
      DocData = DocData + DataLine + "\n";
    }

}

int AnalyzeDocData (string DocData){    //fucntion to convert all to lowercase and find the number of bananas in file

  int WordCounter = 0, Position = 0, Place = 0;
  bool a = true;

  for (int i = 0; i < DocData.length(); i++){     /*
                                                    This loop goes through all the characters of the string and converts them into
                                                    lower case letters
                                                    Note: A string can be used like a vector if needed
                                                  */
    DocData[i] = tolower(DocData[i]);
    }

    while (a == true){          // This loop goes through the positions and searchs for the words

      if (DocData.find("banana", Position) != -1){      /* Here we use a new function which is:
                                                          .find("WordYouWantToSearch", PositionWhereToStartSearching);

                                                          this function goes position by position until it founds the word
                                                          then it returns the position where the word was found

                                                          in case that the function does not finds a word then it will return -1


                                                          This is why we will continue doing the loop until the word is not found
                                                          */
      WordCounter += 1;
      Place = DocData.find("banana",Position);          // This will give the position were the word was found
      Position = Place + 1;                             /* This will add one to the position so that the next time
                                                          the function will search from the position after the word was found
                                                        */
    } else {
      a = false;
    }
  }
return WordCounter;
}

int main () {
  string DocName = "", DocData = "";
  int WordCounter = 0;

  GetDocName(DocName);

  GetDocData(DocData, DocName);

  WordCounter = AnalyzeDocData (DocData);

  cout << "The number of bananas found was: " << WordCounter << endl;

  return 0;
}
