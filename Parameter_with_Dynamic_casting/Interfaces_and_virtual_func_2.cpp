#include <iostream>
#include <string>

using namespace std;

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};


// Your code here
class MinLengthValidator : public StringValidator {
private:
  size_t minLen;
public:
  MinLengthValidator(size_t m) : minLen(m) {}
  bool isValid(std::string input) override {
    return input.length() >= minLen;
  }
};

class MaxLengthValidator : public StringValidator {
  private:
    size_t maxLen;
  public:
    MaxLengthValidator(size_t m) : maxLen(m) {}
    bool isValid(std::string input) override {
      return input.length() <= maxLen;
    } 
};


// PatternValidator: checks if pattern appears anywhere in input using the rules.
// 'D' = digit, 'A' = any letter, '?' = any char, lowercase letters = case-insensitive match.
class PatternValidator : public StringValidator {
private:
  std::string pattern;

  bool matchesAt(const std::string &s, size_t pos) const {
    if (pos + pattern.size() > s.size()) return false;
    for (size_t i = 0; i < pattern.size(); ++i) {
      char p = pattern[i];
      char c = s[pos + i];

      if (p == 'D') {
        if (!std::isdigit(static_cast<unsigned char>(c))) return false;
      } else if (p == 'A') {
        if (!std::isalpha(static_cast<unsigned char>(c))) return false;
      } else if (p == '?') {
        // matches any single character
      } else if (std::isalpha(static_cast<unsigned char>(p)) && std::islower(static_cast<unsigned char>(p))) {
        // lowercase pattern letter matches case-insensitively
        if (std::tolower(static_cast<unsigned char>(p)) != std::tolower(static_cast<unsigned char>(c)))
          return false;
      } else {
        // punctuation or exact-character match
        if (p != c) return false;
      }
    }
    return true;
  }

public:
  PatternValidator(const string &pat) : pattern(pat) {}
  bool isValid(std::string input) override {
    if(pattern.empty()) return true;
    for (size_t pos = 0; pos + pattern.size() <= input.size(); ++pos) {
      if (matchesAt(input, pos)) return true;
    }
    return false;
  }
};


void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
  cout << "MinLengthValidator" << endl;
  MinLengthValidator min(6);
  printValid(min, "hello");
  printValid(min, "welcome");
  cout << endl;

  cout << "MaxLengthValidator" << endl;
  MaxLengthValidator max(6);
  printValid(max, "hello");
  printValid(max, "welcome");
  cout << endl;

  cout << "PatternValidator" << endl;
  PatternValidator digit("D");
  printValid(digit, "there are 2 types of sentences in the world");
  printValid(digit, "valid and invalid ones");
  cout << endl;

  return 0;
}