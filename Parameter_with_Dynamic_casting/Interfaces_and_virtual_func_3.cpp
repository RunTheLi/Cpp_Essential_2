#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cctype>

class StringValidator {
public:
    virtual ~StringValidator() {};
    virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator {
    size_t minLen;
public:
    MinLengthValidator(size_t m) : minLen(m) {}
    bool isValid(std::string input) override {
        return input.length() >= minLen;
    }
};

class MaxLengthValidator : public StringValidator {
    size_t maxLen;
public:
    MaxLengthValidator(size_t m) : maxLen(m) {}
    bool isValid(std::string input) override {
        return input.length() <= maxLen;
    }
};

class UppercaseValidator : public StringValidator {
public:
    bool isValid(std::string input) override {
        for (unsigned char c : input)
            if (std::isupper(c)) return true;
        return false;
    }
};

class LowercaseValidator : public StringValidator {
public:
    bool isValid(std::string input) override {
        for (unsigned char c : input)
            if (std::islower(c)) return true;
        return false;
    }
};

class DigitValidator : public StringValidator {
public:
    bool isValid(std::string input) override {
        for (unsigned char c : input)
            if (std::isdigit(c)) return true;
        return false;
    }
};

class SpecialCharValidator : public StringValidator {
public:
    bool isValid(std::string input) override {
        for (unsigned char c : input)
            if (!std::isalnum(c)) return true;
        return false;
    }
};

class LengthValidator : public StringValidator {
    MinLengthValidator min_validator;
    MaxLengthValidator max_validator;
public:
    LengthValidator(int min, int max)
        : min_validator(min), max_validator(max) {}

    bool isValid(std::string input) override {
        return min_validator.isValid(input) && max_validator.isValid(input);
    }
};

// Composite validator
class CompositeValidator : public StringValidator {
    std::vector<std::unique_ptr<StringValidator>> validators;
public:
    void addValidator(std::unique_ptr<StringValidator> v) {
        validators.push_back(std::move(v));
    }

    bool isValid(std::string input) override {
        for (const auto &v : validators)
            if (!v->isValid(input)) return false;
        return true;
    }
};

// Factory for password validator
std::unique_ptr<StringValidator> makePasswordValidator() {
    auto comp = std::make_unique<CompositeValidator>();

    comp->addValidator(std::make_unique<LengthValidator>(8, 8)); // exactly 8 chars
    comp->addValidator(std::make_unique<UppercaseValidator>());
    comp->addValidator(std::make_unique<LowercaseValidator>());
    comp->addValidator(std::make_unique<DigitValidator>());
    comp->addValidator(std::make_unique<SpecialCharValidator>());

    return comp;
}

void printValid(StringValidator &validator, std::string input) {
    std::cout << "The string '" << input << "' is "
              << (validator.isValid(input) ? "valid" : "invalid") << std::endl;
}

int main() {
    auto passwordValidator = makePasswordValidator();

    std::cout << "Password validation tests:\n";
    printValid(*passwordValidator, "Ab3$efgh");
    printValid(*passwordValidator, "Ab3efgh!");
    printValid(*passwordValidator, "abcdefgh");
    printValid(*passwordValidator, "A1$bc");
    printValid(*passwordValidator, "ABCDEFG1!");
    printValid(*passwordValidator, "Abcdef12");

    return 0;
}
