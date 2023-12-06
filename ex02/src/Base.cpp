/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:46:00 by pvong             #+#    #+#             */
/*   Updated: 2023/12/05 14:17:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <time.h>

Base::~Base(void) {}

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

Base *generate(void) {
    srand(time(NULL));

    int i = rand() % 3;

    if (i == 0)
        return (new A());
    else if (i == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p) {
    std::cout << "Identify by pointer: ";
    if (dynamic_cast<A *>(p))
        std::cout << COLOR("A", CYAN) << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << COLOR("B", CYAN) << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << COLOR("C", CYAN) << std::endl;
}

void identify(Base &p) {
    std::cout << "Identify by reference: ";
    // try catch dynamic cast on each since we cannot use pointer in this function
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << COLOR("A", CYAN) << std::endl;
    } catch (const std::bad_cast &e) {
        // empty
    }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << COLOR("B", CYAN) << std::endl;
    } catch (const std::bad_cast &e) {
        // empty
    }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << COLOR("C", CYAN) << std::endl;
    } catch (const std::bad_cast &e) {
        // empty
    }
}
