//  DockingVina.cc
//
//  Authors:
//       Maria Jesus Garcia Godoy <mjgarciag@lcc.uma.es>
// 
//  Copyright (c) 2011 Antonio J. Nebro, Juan J. Durillo
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
#include "DockingVina.h"


DockingVina::DockingVina(string solutionType, int numberOfVariables) {
    numberOfVariables_   = numberOfVariables;
	numberOfObjectives_  = 1; // monoobjective problem so the number of objectives is just one.
	numberOfConstraints_ = 0;
	problemName_= "Molecular Docking";

    lowerLimit_ = new double[numberOfVariables_];
	if (lowerLimit_ == NULL) {
		cout << "Abinitio::Abinitio. Error reserving memory for storing the array of lower limits" << endl;
		exit(-1) ;
	}	
	
	upperLimit_ = new double[numberOfVariables_];
	if (upperLimit_ == NULL) {
		cout << "Abinitio::Abinitio. Error reserving memory for storing the array of upper limits" << endl;
		exit(-1) ;
	}
    
	float minX = corner1.data[0];
	float minY = corner1.data[1];
	
	float minZ = corner1.data[2];

	float maxX = corner2.data[0];
	float maxY = corner2.data[1];
	float maxZ = corner2.data[2];
    
} // AbInitio


void DockingVina::evaluate(Solution *solution) {


}