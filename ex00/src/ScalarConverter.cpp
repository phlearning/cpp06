/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:19:34 by pvong             #+#    #+#             */
/*   Updated: 2023/12/01 17:30:24 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

ScalarConverter::ScalarConverter(void) {
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter: Default constructor called.", GREEN) << std::endl;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void) src;
    if (SHOWMSG) {
        std::cout << COLOR("ScalarConverter copy constructor called. ", GREEN) << std::endl;
    }
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void) other;
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
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

// ! Wrong: this isn't what is asked by the exo. Need to static cast as it is the meaning of the exo.
void ScalarConverter::convert(const std::string &input) {
    std::istringstream iss(input);

    // Trying to convert to char
    char convertedToChar;

    if (iss >> convertedToChar) {
        if (isprint(convertedToChar)) { // this isprint check if the char is printable
            std::cout << "char: '" << convertedToChar << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    // Trying to convert to int
    iss.clear();
    iss.seekg(0);
    int convertedToInt;
    if (iss >> convertedToInt) {
        std::cout << "int: " << convertedToInt << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

        // Trying to convert to float
    iss.clear();
    iss.seekg(0);
    float convertedToFloat;
    if (iss >> convertedToFloat) {
        std::cout << "float: " << convertedToFloat << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }

        // Trying to convert to double
    iss.clear();
    iss.seekg(0);
    double convertedToDouble;
    if (iss >> convertedToDouble) {
        std::cout << "double: " << convertedToDouble << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}