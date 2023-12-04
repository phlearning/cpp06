/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:57:51 by pvong             #+#    #+#             */
/*   Updated: 2023/12/04 17:13:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
    
public:
    Data(void);
    ~Data(void);

    int getValue(void) const;

private:
    int _value;
    Data(const Data &src);
    Data &operator=(const Data &other);
};

#endif