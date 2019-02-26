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

#include "Problem.h"
#include "Solution.h"
#include "conf.h"
#include "model.h"
#include "tree.h"
#include "mutate.h"
#include "common.h"
#include "boost/ptr_container/ptr_vector.hpp"
#include "quaternion.h"
#include "random.h"
#include "boost/random.hpp"


class DockingVina : public Problem {


public:
    /// @brief Constructor 1 of the Docking Vina problem
    DockingVina(string solutionType, int numberOfVariables);
    

    /// @brief Destructor
	~DockingVina();

    void evaluate(Solution *solution);


};
