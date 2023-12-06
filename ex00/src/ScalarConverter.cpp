/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:19:34 by pvong             #+#    #+#             */
/*   Updated: 2023/12/06 14:53:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter(void) {
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter: Default constructor called.", GREEN) << std::endl;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void)src;
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter copy constructor called. ", GREEN) << std::endl;
    }
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter copy assignment operator called.", GREEN) << std::endl;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter destructor called.", RED) << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               UTILS FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

bool isAChar(const std::string &input) {

    bool hasFoundADigit = false;
    bool hasFoundAChar = false;
    for (size_t i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            hasFoundADigit = true;
        } else if (isprint(input[i])) {
            hasFoundAChar = true;
        }
        if (hasFoundAChar && hasFoundADigit) {
            return false;
        } else if (hasFoundAChar && !hasFoundADigit && input.length() > 1) {
            return false;
        }
    }
    int value = static_cast<int>(atoi(input.c_str()));
    if (value >= 0 && value <= 127) {
        return true;
    }
    return false;
}

bool isOnlyDigits(const std::string &input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

bool isInteger(const std::string &str) {
    std::stringstream ss(str);
    int n;

    ss >> n;
    return !ss.fail() && ss.eof();
}


bool isFloat(const std::string &s) {
    std::istringstream iss(s);
    int fFound = 0;
    // Check for f found in string return false if more than one f is found and if it is not at the end of the string;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'f') {
            fFound++;
        }
        if (fFound > 1 || (fFound == 1 && i != s.length() - 1)) {
            return false;
        }
    }
    // Check for f in string and delete it if it is at the end;
    if (s[s.length() - 1] == 'f') {
        std::string s2 = s.substr(0, s.length() - 1);
        iss.str(s2);
    }

    float f;
    iss >> f;
    return iss.eof() && !iss.fail();
}

bool isDouble(const std::string &input) {

    double doubleValue;
    std::istringstream iss(input);

    if (iss >> doubleValue) {
        return true;
    }
    return false;
}

bool isPseudoLiterals(const std::string &input) {

    if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "inf" || input == "nan") {
        return true;
    }
    return false;
}


/**
 * @brief Checks if the input string is a valid value.
 * 
 * A valid value is defined as a string that represents a number, 
 * with at most one decimal point and an optional sign (+/-) at the beginning.
 * 
 * @param input The input string to be checked.
 * @return true if the input string is a valid value, false otherwise.
 */
bool isValidValue(const std::string &input) {
    int dotCount = 0;
    int signCount = 0;
    int signPos = 0;
    
    for (int i = 0; i < static_cast<int>(input.length()); i++) {
        char c = input[i];
        if (c == '+' || c == '-') {
            signCount++;
            signPos = i;
        }
        if (signCount > 1 || signPos != 0) {
            return false;
        }
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false;
            }
        }
    }

    return true;
}

void printChar(const std::string &input) {
    double d = static_cast<double>(atof(input.c_str()));
    int dotFound = (input.find('.') == std::string::npos) ? 0 : 1;
    
    std::string s2;
    if (input[input.length() - 1] == 'f') {
        s2 = input.substr(0, input.length() - 1);
    } 

    if (isAChar(s2) && d <= CHAR_MAX && d >= CHAR_MIN) {
        char c = static_cast<char>(d);
        if (isprint(c)) {
            std::cout << COLOR("char:", CYAN) << " '" << c << "'" << std::endl;
        } else {
            std::cout << COLOR("char:", CYAN) << " Non displayable" << std::endl;
        }
    } else if (!isAChar(s2) && dotFound && (d <= CHAR_MAX && d >= CHAR_MIN)) {
        char c = static_cast<char>(d);
        if (isprint(c)) {
            std::cout << COLOR("char:", CYAN) << " '" << c << "'" << std::endl;
        } else {
            std::cout << COLOR("char:", CYAN) << " Non displayable" << std::endl;
        }
    } else {
        std::cout << COLOR("char:", CYAN) << " impossible" << std::endl;
    }
}

void printInt(const std::string &input) {
    double d = static_cast<double>(atof(input.c_str()));
    int i = static_cast<int>(d);

    if (d <= INT_MAX && d >= INT_MIN) {
        std::cout << COLOR("int:", CYAN) << " " << i << std::endl;
    } else {
        std::cout << COLOR("int:", CYAN) << " impossible" << std::endl;
    }
}

void printFloat(const std::string &input) {
    int dotFound = (input.find('.') == std::string::npos) ? 0 : 1;

    float f = static_cast<float>(atof(input.c_str()));
    double d = static_cast<double>(atof(input.c_str()));

    if (dotFound == 0 && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } else if (dotFound == 1 && input[input.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } else {
        std::cout << COLOR("float:", CYAN) << " " << f << "f" << std::endl;
    }
}

void printDouble(const std::string &input) {
    double d = static_cast<double>(atof(input.c_str()));
    int dotFound = (input.find('.') == std::string::npos) ? 0 : 1;

    if (dotFound == 0 && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("double:", CYAN) << " " << std::fixed << std::setprecision(1) << d << std::endl;
    } else if (dotFound == 1 && input[input.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("double:", CYAN) << " " << std::fixed << std::setprecision(1) << d << std::endl;
    } else {
        std::cout << COLOR("double:", CYAN) << " " << d << std::endl;
    }
}

void convertChar(const std::string &input) {
    int len = input.length();
    char value = (isalpha(input[0]) && len == 1) ? input[0] : static_cast<char>(atoi(input.c_str()));
    if (isprint(value)) {
        std::cout << COLOR("char:", CYAN) << " '" << value << "'" << std::endl;
    } else {
        std::cout << COLOR("char:", CYAN) << " Non displayable" << std::endl;
    }
    /* isFloat will check if input is a valid float which also checks if it is a valid number as the isAChar function already eliminated
    the possibility of having a number with a char in it. */
    if (isFloat(input)) {
        int i = static_cast<int>(value);
        std::cout << COLOR("int:", CYAN) << " " << i << std::endl;
        float f = static_cast<float>(value);
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        double d = static_cast<double>(value);
        std::cout << COLOR("double:", CYAN) << " " << d << std::endl;
    } else {
        std::cout << COLOR("int:", CYAN) << " impossible" << std::endl;
        std::cout << COLOR("float:", CYAN) << " impossible" << std::endl;
        std::cout << COLOR("double:", CYAN) << " impossible" << std::endl;
    }
}

void convertInt(const std::string &input) {
    int i = static_cast<int>(atoi(input.c_str()));

    std::cout << COLOR("char:", CYAN) << " impossible" << std::endl;
    std::cout << COLOR("int:", CYAN) << " " << i << std::endl;

    printFloat(input);
    printDouble(input);
}

void convertFloat(const std::string &input) {
    int dotFound = (input.find('.') == std::string::npos) ? 0 : 1;
    int dotPos = 0, nbDigitsAfterDot = 0;

    if (dotFound == 1) {
        dotPos = input.find('.');
        nbDigitsAfterDot = input.length() - dotPos - 1;
    }
    float f = static_cast<float>(atof(input.c_str()));
    double d = static_cast<double>(atof(input.c_str()));

    printChar(input);
    printInt(input);
    if (dotFound == 0 && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << COLOR("double:", CYAN) << " " << std::fixed << std::setprecision(1) << d << std::endl;
    } else if (dotFound == 1 && input[input.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << COLOR("double:", CYAN) << " " << std::fixed << std::setprecision(1) << d << std::endl;
    } else if (nbDigitsAfterDot <= 1 && (d <= INT_MAX && d >= INT_MIN)) {
        std::cout << COLOR("float:", CYAN) << " " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << COLOR("double:", CYAN) << " " << std::fixed << std::setprecision(1) << d << std::endl;
    } else {
        std::cout << COLOR("float:", CYAN) << " " << f << "f" << std::endl;
        std::cout << COLOR("double:", CYAN) << " " << d << std::endl;
    }
}

void convertDouble(const std::string &input) {
    std::cout << COLOR("char:", CYAN) << " impossible" << std::endl;
    std::cout << COLOR("int:", CYAN) << " impossible" << std::endl;
    std::cout << COLOR("float:", CYAN) << " impossible" << std::endl;
    printDouble(input);
}

void convertPseudoLiterals(const std::string &input) {

    if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "inf" || input == "nan") {
        float f = static_cast<float>(atof(input.c_str()));
        std::cout << COLOR("char:", CYAN) << " impossible" << std::endl;
        std::cout << COLOR("int:", CYAN) << " impossible" << std::endl;
        std::cout << COLOR("float:", CYAN) << " " << f << "f" << std::endl;
        double d = static_cast<double>(atof(input.c_str()));
        std::cout << COLOR("double:", CYAN) << " " << d << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                               MEMBER FUNCTION                              */
/* -------------------------------------------------------------------------- */

void ScalarConverter::convert(const std::string &input) {

    if (!isValidValue(input)) {
        std::cout << COLOR("Error: Invalid value: ", RED) << input << std::endl;
        return;
    }
    if (isPseudoLiterals(input)) {
        // std::cout << "Entered in isPseudoLiterals" << std::endl;
        convertPseudoLiterals(input);
    } else if (isAChar(input)) {
        // std::cout << "Entered in isAChar" << std::endl;
        convertChar(input);
    } else if (isInteger(input)) {
        // std::cout << "Entered in isInt" << std::endl;
        convertInt(input);
    } else if (isFloat(input)) {
        // std::cout << "Entered in isFloat" << std::endl;
        convertFloat(input);
    } else if (isDouble(input)) {
        // std::cout << "Entered in isDouble" << std::endl;
        convertDouble(input);
    } else {
        std::cout << COLOR("Error: input is not a valid literal", RED) << std::endl;
    }
}
