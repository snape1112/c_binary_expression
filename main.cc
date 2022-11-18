#include <iostream>
#include <string>
#include <map>
#include "parser.h"
#include "treeNode.h"

// a helper function parsing the input into the formula string and the assignment string
void parseLine(const std::string &line, std::string &formulaStr, std::string &assignmentStr) {
  // your code starts here
  int index = line.find(';');
  if (index != std::string::npos) {
    formulaStr = line.substr(0, index);
    assignmentStr = line.substr(index + 1);
  } else
    throw std::runtime_error("invalid input");
}

// The program shall continuously ask for new inputs from standard input and output to the standard output
// The program should terminate gracefully (and quietly) once it sees EOF
int main() {
  while (true) // continuously asking for new inputs from standard input
  {
    std::string line; // store each input line
    std::string formulaStr; // store the formula string
    std::string assignmentStr; // store the assignment string
    // your code starts here
    if(!std::getline(std::cin, line))
      break;

    try {
      // parse input into formula and assignment
      parseLine(line, formulaStr, assignmentStr);
      FormulaParser formulaParser(formulaStr);
      AssignmentParser assignmentParser(assignmentStr);
      // parse formula string
      TreeNode *root = formulaParser.getTreeRoot();
      // parse assignment string
      std::map<std::string, bool> assignment;
      assignment = assignmentParser.parseAssignment();
      // evaluate
      std::cout << root->evaluate(assignment) << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}
