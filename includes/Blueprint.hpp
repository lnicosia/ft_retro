/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:38:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/18 21:40:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Blueprint_HPP
# define Blueprint_HPP

#include <fstream>
#include "Vec2.hpp"

class Blueprint
{
	public:
		Blueprint(void);
		Blueprint(std::string f);
		Blueprint(Blueprint const &instance);
		Blueprint &operator=(Blueprint const &rhs);
		~Blueprint(void);
        int         parseBlueprint(std::string f);
		std::string	getImage() const;
		std::string	getImageNoN() const;
		size_t		getSizeX() const;
		size_t		getSizeY() const;
		void		print(Vec2) const;

	private:
        std::string     _image;
		std::string		_imageNoN;
		size_t			_sizeX;
		size_t			_sizeY;

};

std::ostream&   operator<<(std::ostream &o, Blueprint const &instance);

#endif