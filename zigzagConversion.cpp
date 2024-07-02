#include <iostream>
#include <string>
#include <map>

using namespace std;

string FindIntersection(string strArr[], int arrLength) {
  map<string, int> result;
  for(int i =0; i<arrLength; i++){
    string num="";
    int j = 0;
    cout << strArr[i].length();
    while(j<strArr[i].length()){
      num = "";
      while(strArr[i][j] != ',' && j < strArr[i].length()){
        num += strArr[i][j];
        j++;
      }
      j+=2;
      result[num]++;
    }
  }
    for( auto &&chr : result){
        std::cout<<chr.first<<" "<<chr.second<<endl;
        
    }
    
  
  string string_result = "";
  for( auto &&chr : result){
    if (chr.second >= 2){
      string_result += chr.first;
      string_result += ",";
    }
  }
  string_result.pop_back();

  return string_result;

}

int main(void) { 
   
  // keep this function call here
  // keep this function call here
  string A[2] = {"1, 3, 4, 7, 13", "1, 2, 4, 13, 15"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout<<arrLength;
  std::cout << FindIntersection(A, arrLength);
  return 0;
    
}
