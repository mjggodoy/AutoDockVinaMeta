//  NadirPoint.h
//
//  Author:
//       Esteban López-Camacho <esteban@lcc.uma.es>
//
//  Copyright (c) 2016 Antonio J. Nebro
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __NADIR_POINT__
#define __NADIR_POINT__

#include <Solution.h>

/**
 * Class representing a nadir point (minimization is assumed)
 */
class NadirPoint : public ReferencePoint {

public:
  NadirPoint(int numberOfObjectives);
  ~NadirPoint();
  void update(Solution * solution);
};

#endif
