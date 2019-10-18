/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:38:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/18 18:21:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Blueprint_HPP
# define Blueprint_HPP

#include <fstream>

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
		int			getX() const;
		int			getY() const;
		void		setPos(int x, int y);
		void		print() const;
		void		attemptToMove(int x, int y);

	private:
        std::string     _image;
		int				_x;
		int				_y;
		size_t			_sizeX;
		size_t			_sizeY;

};

std::ostream&   operator<<(std::ostream &o, Blueprint const &instance);

#endif