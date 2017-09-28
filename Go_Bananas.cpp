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

void GetDocData (string& DocData, const string& DocName){     // This function passes the info in the file to a string to be able to analyze it
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

int AnalyzeDocData (string DocData){

  int WordCounter = 0, Position = 0, Place = 0;
  bool a = true;

  for (int i = 0; i < DocData.length(); i++){
    DocData[i] = tolower(DocData[i]);
    }

    while (a == true){
      if (DocData.find("banana", Position) != -1){
      WordCounter += 1;
      Place = DocData.find("banana",Position);
      Position = Place + 1;
    } else {
      a = false;
    }
  }
return WordCounter;
}

int main () {
  string DocName = "", DocData = "", MagicWord = "Banana";
  int WordCounter = 0;

  GetDocName(DocName);

  GetDocData(DocData, DocName);

  WordCounter = AnalyzeDocData (DocData);

  cout << "The number of bananas found was: " << WordCounter << endl;

  return 0;
}
