/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:08 by pvong             #+#    #+#             */
/*   Updated: 2023/12/04 17:21:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data *myData = new Data();
    uintptr_t raw = Serializer::serialize(myData);
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Raw data: " << raw << std::endl;
    std::cout << "Deserialized data: " << ptr->getValue() << std::endl;
    delete myData;  
    return (0);
}