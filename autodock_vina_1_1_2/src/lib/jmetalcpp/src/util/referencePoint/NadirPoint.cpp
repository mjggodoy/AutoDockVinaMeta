//  NadirPoint.cpp
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


#include <ReferencePoint.h>
#include <NadirPoint.h>

/**
 * Constructor
 */
NadirPoint::NadirPoint(int numberOfObjectives) : ReferencePoint(numberOfObjectives) {
  for (int i = 0; i < numberOfObjectives; i++) {
    setObjective(i, -std::numeric_limits<double>::max());
  }
} // NadirPoint


/**
 * Destructor
 */
NadirPoint::~NadirPoint() { } // ~NadirPoint


void NadirPoint::update(Solution * solution) {
  
  if (solution == NULL) {
    cerr << "NadirPoint::update - The solution is null" << endl;
    exit(-1);
  } else if (solution->getNumberOfObjectives() != getNumberOfObjectives()) {
     cerr << "NadirPoint::update - The number of objectives of the solution ("
          << solution->getNumberOfObjectives()
          << ") "
          << "is different to the size of the reference point("
          << getNumberOfObjectives()
          << ")" << endl;
     exit(-1);
  }
  
  for (int i = 0; i < getNumberOfObjectives(); i++) {
    if (getObjective(i) < solution->getObjective(i)) {
      setObjective(i, solution->getObjective(i));
    }
  }
} // update

