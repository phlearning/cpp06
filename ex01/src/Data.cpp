/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:45 by pvong             #+#    #+#             */
/*   Updated: 2023/12/04 17:15:39 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "iostream"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

Data::Data(void) : _value(50) {
    if (SHOWMSG) {
        std::cout << COLOR("Data default constructor called", GREEN) << std::endl;
    }
    return;
}

Data::~Data(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Data destructor called", RED) << std::endl;
    }
    return;
}

Data::Data(const Data &src) : _value(src._value) {
    if (SHOWMSG) {
        std::cout << COLOR("Data copy constructor called", GREEN) << std::endl;
    }
    return;
}

Data &Data::operator=(const Data &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Data copy assignment operator called", GREEN) << std::endl;
    }
    this->_value = other._value;
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               MEMBER FUNCTION                              */
/* -------------------------------------------------------------------------- */

int Data::getValue(void) const {
    return (this->_value);
}
