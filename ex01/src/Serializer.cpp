/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:32 by pvong             #+#    #+#             */
/*   Updated: 2023/12/04 17:17:16 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

Serializer::Serializer(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Serializer default constructor called", GREEN) << std::endl;
    }
    return;
}

Serializer::~Serializer(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Serializer destructor called", RED) << std::endl;
    }
    return;
}

Serializer::Serializer(const Serializer &src) {
    (void) src;
    if (SHOWMSG) {
        std::cout << COLOR("Serializer copy constructor called", GREEN) << std::endl;
    }
    return;
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void) other;
    if (SHOWMSG) {
        std::cout << COLOR("Serializer copy assignment operator called", GREEN) << std::endl;
    }
    return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

/**
 * Serializes a Data pointer into a uintptr_t value.
 *
 * @param ptr A pointer to the Data object to be serialized.
 *
 * @return The serialized value of the provided Data pointer.
 *
 * @throws None
 */
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief This function deserializes a raw pointer into a Data object.
 *
 * @param raw The raw pointer to be deserialized.
 * @return A pointer to the deserialized Data object.
 */
Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}