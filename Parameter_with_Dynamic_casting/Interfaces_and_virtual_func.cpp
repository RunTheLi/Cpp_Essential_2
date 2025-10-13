#include <iostream>
#include <string>

using namespace std;

class StringValidator {
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

// Dummy validator (already given)
class DummyValidator : public StringValidator {
public:
  bool isValid(std::string input) override {
    return true;
  }
};


class ExactValidator : public StringValidator {
private:
  string match;
public:
  ExactValidator(string m) : match(m) {}
  bool isValid(string input) override {
    return input == match;
  }
};


void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid") << endl;
}

int main()
{
  DummyValidator dummy;
  printValid(dummy, "hello");
  cout << endl;

  ExactValidator exact("secret");
  printValid(exact, "hello");
  printValid(exact, "secret");
  return 0;
}
