/*
Go_Bananas.cpp
Sep 26, 2017
Juan Casian
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void GetDocName(string& DocName){
  cout << "Please insert the name of the document you wish to analize: " << endl;
  cin >> DocName;

  ifstream TestFile (DocName);

  if (TestFile.good() == false){

    cout << "Unable to open this file, please try again." << endl;
    GetDocName (DocName);
  }
}

void GetDocData (string& DocData, const string& DocName){
  string DataLine;

    ifstream TestFile (DocName);

    while (TestFile.eof() == false){
      getline(TestFile, DataLine);
      DocData = DocData + DataLine + "\n";
    }

}

int AnalyzeDocData (const string& DocData){

  transform (DocData.begin(), DocData.end(), DocData.begin(), toupper);

  cout << DocData << endl;


return 0;
}

int main () {
  string DocName = "", DocData = "", MagicWord = "Banana";

  GetDocName(DocName);

  GetDocData(DocData, DocName);

  cout << DocData << "\n" << "\n" << endl;

  AnalyzeDocData (DocData);



  return 0;
}
