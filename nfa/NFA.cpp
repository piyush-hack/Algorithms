#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int main() {
  fstream file;
  file.open("nfa.txt", ios_base::in );

  vector<string> states;
  vector<string> alphabets;

  map<string, int> alphaIndex;
  map<string, int> stateIndex;

  vector<vector<vector<int>>> transitions;
  string initialState;
  vector<bool> finalStates;

  vector<string> inputs;
  if(file.is_open()) while(file.good()) {
    string s;
    file >> s;
    inputs.push_back(s);
  }

  int index = 0;

  int temp = stoi(inputs[index]);
  int m = stoi(inputs[index]);
  index++;
  while(temp--) {
    string tempS = inputs[index];
    states.push_back(tempS);
    stateIndex[tempS] = (int)(states.size() - 1);
    index++;
  }
  temp = stoi(inputs[index]);
  index++;
  while(temp--) {
    string tempS = inputs[index];
    index++;
    alphabets.push_back(tempS);
    alphaIndex[tempS] = (int)(alphabets.size() - 1);
  }

  temp = stoi(inputs[index]);
  index++;

  transitions.resize(states.size());
  for(auto &x: transitions) {
    x.resize(states.size());
  }

  while(temp--) {
    string cState = inputs[index];
    index++;
    string cAlpha = inputs[index];
    index++;
    int nums = stoi(inputs[index]);
    index++;

    while(nums--) {
      string curr = inputs[index];
      index++;
      transitions[stateIndex[cState]][stateIndex[curr]].push_back(alphaIndex[cAlpha]);
    }
  }

  initialState = inputs[index];
  index++;
  temp = stoi(inputs[index]);
  index++;
  finalStates.resize(m, false);
  while(temp--) {
    string tempS = inputs[index];
    finalStates[stateIndex[tempS]] = true;
    index++;
  }

  bool valid = false;

  string s;
  std::cout << "Enter the string that needs to be matched\n";
  std::cin >> s;


  stack<int> stk;
  stk.push(alphaIndex[initialState]);
  for(int i=0; i<s.length(); ++i) {
    vector<int> next;
    string currChar;
    currChar.push_back(s[i]);
    while(!stk.empty()) {
      int current = stk.top();
      stk.pop();
      for(int i=0; i<m; ++i) {
        for(auto x: transitions[current][i]) 
        if(x == alphaIndex[currChar]) {
          next.push_back(i);
        }
      }
    }


    for(auto x: next) {
      stk.push(x);
    }
    if(i == s.length() - 1) {
      for(auto x: next) valid = valid | finalStates[x];
    }
  }
  
  while(!stk.empty()) {
    int curr = stk.top();
    stk.pop();
    valid = valid | finalStates[curr];
  }


  if(valid) {
    std::cout << "Valid string\n";
  } else {
    std::cout << "Invalid string\n";
  }

}
