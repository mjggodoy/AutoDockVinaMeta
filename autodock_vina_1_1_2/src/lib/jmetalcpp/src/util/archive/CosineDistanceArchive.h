//  CosineDistanceArchive.h
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

#ifndef __COSINE_DISTANCE_ARCHIVE__
#define __COSINE_DISTANCE_ARCHIVE__

#include <Archive.h>
#include <Comparator.h>
#include <CosineDistanceComparator.h>
#include <Distance.h>
#include <DominanceComparator.h>
#include <EqualSolutions.h>
#include <Solution.h>

class CosineDistanceArchive : public Archive {

private:
  int maxSize;
  int objectives;
  Comparator *dominance;
  Comparator *equals;
  Comparator *cosineDistance;
  Distance *distance;
  ReferencePoint * referencePoint;

public:
  CosineDistanceArchive(int maxSize, int numberOfObjectives, ReferencePoint * referencePoint);
  ~CosineDistanceArchive();
  bool add(Solution *solution);

};

#endif /* __COSINE_DISTANCE_ARCHIVE__ */
