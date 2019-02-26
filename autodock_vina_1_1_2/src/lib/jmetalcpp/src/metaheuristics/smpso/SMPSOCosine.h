//  SMPSOCosine.h
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

#ifndef _SMPSO_COSINE_H_
#define _SMPSO_COSINE_H_

#include <Algorithm.h>
#include <CosineDistanceArchive.h>
#include <Distance.h>
//#include <Hypervolume.h>
#include <NadirPoint.h>
#include <Problem.h>
#include <ReferencePoint.h>
//#include <QualityIndicator.h>
#include <SolutionSet.h>
#include <XReal.h>
#include <PseudoRandom.h>
#include <math.h>
#include <vector>
#include <string>


class SMPSOCosine : public Algorithm {

private:

  /**
   * Stores the number of particles_ used
   */
  int swarmSize_;
  /**
   * Stores the maximum size for the archive
   */
  int archiveSize_;
  /**
   * Stores the maximum number of iteration_
   */
  int maxIterations_;
  /**
   * Stores the current number of iteration_
   */
  int iteration_;
  /**
   * Stores the particles
   */
  SolutionSet * particles_;
  /**
   * Stores the best_ solutions founds so far for each particles
   */
  Solution ** best_;
  /**
   * Stores the leaders_
   */
  CosineDistanceArchive * leaders_;
  /**
   * Stores the speed_ of each particle
   */
  double ** speed_;
  /**
   * Stores a comparator for checking dominance
   */
  Comparator * dominance_;
  /**
   * Stores a comparator for crowding checking
   */
  Comparator * cosineDistanceComparator_;
  /**
   * Stores a <code>Distance</code> object
   */
  Distance * distance_;
  /**
   * Stores a operator for non uniform mutations
   */
  Operator * polynomialMutation_;
  /**
   * Stores the reference point used to calculate the cosine distances.
   */
  ReferencePoint * referencePoint;

  //QualityIndicator * indicators_; // QualityIndicator object

  double r1Max_;
  double r1Min_;
  double r2Max_;
  double r2Min_;
  double C1Max_;
  double C1Min_;
  double C2Max_;
  double C2Min_;
  double WMax_;
  double WMin_;
  double ChVel1_;
  double ChVel2_;

  double trueHypervolume_;
  //Hypervolume * hy_;
  SolutionSet * trueFront_;
  double * deltaMax_;
  double * deltaMin_;
  bool success_;

  double inertiaWeight(int iter, int miter, double wma,
                                            double wmin);
  double constrictionCoefficient(double c1, double c2);
  double velocityConstriction(double v, double * deltaMax,
                                        double * deltaMin,
                                        int variableIndex,
                                        int particleIndex);
  void computeSpeed(int iter, int miter);
  void computeNewPositions();
  void mopsoMutation(int actualIteration, int totalIterations);
  void initParams();
  void setAlgParams();
  void deleteParams();

public:
  SMPSOCosine(Problem * problem);
  SolutionSet * execute();

};

#endif /* _SMPSO_COSINE_H_ */
