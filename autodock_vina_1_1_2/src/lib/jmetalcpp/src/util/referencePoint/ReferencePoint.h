//  ReferencePoint.h
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

#ifndef __REFERENCE_POINT__
#define __REFERENCE_POINT__

#include <Solution.h>

/**
 * @class ReferencePoint
 * @brief This class is aimed at representing a reference point
**/
class ReferencePoint : public Solution {

public:
  ReferencePoint(int numberOfObjectives);
  virtual ~ReferencePoint();
  virtual void update(Solution * solution) = 0;

};

#endif
