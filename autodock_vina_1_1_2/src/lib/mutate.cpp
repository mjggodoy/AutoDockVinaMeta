/*

   Copyright (c) 2006-2010, The Scripps Research Institute

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   Author: Dr. Oleg Trott <ot14@columbia.edu>, 
           The Olson Lab, 
           The Scripps Research Institute

*/

#include "mutate.h"
// #include <jmetalcpp/src/core/Algorithm.h>
// #include <jmetalcpp/src/core/Problem.h>
// #include <jmetalcpp/src/core/Operator.h>
// #include <jmetalcpp/src/encodings/solutionType/RealSolutionType.h>
// #include <jmetalcpp/src/SolutionType.h>
// #include <jmetalcpp/src/Variable.h>
// #include <jmetalcpp/metaheuristics/singleObjective/geneticAlgorithm/gGA.hh>
// #include <jmetalcpp/metaheuristics/singleObjective/geneticAlgorithm/ssGA.hh>
// #include <jmetalcpp/metaheuristics/singleObjective/differentialEvolution/DE.hh>
// #include <jmetalcpp/metaheuristics/singleObjective/particleSwarmOptimization/PSO.hh>
// #include <jmetalcpp/core/SolutionSet.hh>
// #include <jmetalcpp/operators/crossover/SBXCrossover.hh>
// #include <jmetalcpp/operators/mutation/PolynomialMutation.hh>
// #include <jmetalcpp/operators/selection/BinaryTournament2.hh>
// #include <jmetalcpp/operators/crossover/DifferentialEvolutionCrossover.hh>
// #include <jmetalcpp/operators/selection/DifferentialEvolutionSelection.hh>
// #include <jmetalcpp/problems/singleObjective/DockingVina.hh>
#include <Algorithm.h>
#include <Problem.h>
#include <Operator.h>
#include <RealSolutionType.h>
#include <SolutionType.h>
#include <Variable.h>
// #include <gGA.hh>
// #include <ssGA.hh>
// #include <DE.hh>
// #include <PSO.hh>
// #include <jmetalcpp/core/SolutionSet.hh>
// #include <jmetalcpp/operators/crossover/SBXCrossover.hh>
// #include <jmetalcpp/operators/mutation/PolynomialMutation.hh>
// #include <jmetalcpp/operators/selection/BinaryTournament2.hh>
// #include <jmetalcpp/operators/crossover/DifferentialEvolutionCrossover.hh>
// #include <jmetalcpp/operators/selection/DifferentialEvolutionSelection.hh>
#include "DockingVina.h"



sz count_mutable_entities(const conf& c) {
	sz counter = 0;
	VINA_FOR_IN(i, c.ligands) //14 entities
		counter += 2 + c.ligands[i].torsions.size();
		//std::cout << " Counter Mutable entities " << counter << "\n";	
	VINA_FOR_IN(i, c.flex) // 22 entities
		counter += c.flex[i].torsions.size();
		//std::cout << " Counter Mutable entities " << counter << "\n";	

	return counter;
}


void ligandTorsion(conf c){

		std::vector<fl>::iterator it2;
		std::vector<ligand_conf> ligands = c.ligands;	
		//std::cout << "1. size ligands: " << ligands.size() << '\n';

		for (std::vector<ligand_conf>::iterator it = ligands.begin() ; it != ligands.end(); ++it){			
			std::vector<fl> torsions = (*it).torsions;
			for (it2 = torsions.begin(); it2 != torsions.end();it2++){
			
				std::cout << " Maria  (mutate class) -> torsions: " << (*it2) << "\n";	
 				//std::cout << "1. size torsions: " << torsions.size() << '\n';

		}
	}		
}


void ligandRigidPosition(conf c){

	std::vector<ligand_conf> ligands = c.ligands;
	int i = 0;
	
	for (std::vector<ligand_conf>::iterator it = ligands.begin() ; it != ligands.end(); ++it){	

		rigid_conf rigid = (*it).rigid;
		std::cout << "Maria (ligand rigid position) " << rigid.position.data[i] << " " << rigid.position.data[i+1] << " " << rigid.position.data[i+2]  <<"\n";			
	
	}
}


void ligandRigidOrientantion(conf c){
	
		std::vector<ligand_conf> ligands = c.ligands;
		int i = 0;
		
		for (std::vector<ligand_conf>::iterator it = ligands.begin() ; it != ligands.end(); ++it){	
	
			rigid_conf rigid = (*it).rigid;
			std::cout << "Maria: ligand rigid orientation: " << rigid.orientation << "\n";			
		}
}


void complexFlex(conf c){

	std::vector<residue_conf> ligands = c.flex;
	for (std::vector<residue_conf>::iterator it = ligands.begin() ; it != ligands.end(); ++it){	
		std::vector<fl> torsions = (*it).torsions;
		for (std::vector<fl>::iterator it2 = torsions.begin(); it2 != torsions.end();it2++){
			std::cout << "Maria: ligand (ligand's flexibility): " << (*it2)<< "\n";		
			std::cout << "Maria: ligand (ligand's flexibility): " << torsions.size()<< "\n";		

		}
	}	
}


void loop(vec temp, fl amplitude){
		
		std::cout << "Maria: temp -> " << temp.data[0] << " " << temp.data[1] << " " << temp.data[2] << " amplitude: " << amplitude <<"\n";	
}

// does not set model
void mutate_conf(conf& c, const model& m, fl amplitude, rng& generator) { // ONE OF: 2A for position, similar amp for orientation, randomize torsion
	sz mutable_entities_num = count_mutable_entities(c);
	if(mutable_entities_num == 0) return;
	int which_int = random_int(0, int(mutable_entities_num - 1), generator);
	VINA_CHECK(which_int >= 0);
	sz which = sz(which_int);
	VINA_CHECK(which < mutable_entities_num);
	//Maria: some methods
	//ligandTorsion(c);
	//ligandRigidPosition(c);
	//ligandRigidOrientantion(c);

	//std::cout << "Maria: energy of conf in mutate method: " << c.e << "\n";	
	

	VINA_FOR_IN(i, c.ligands) {
		if(which == 0) { 

			//std::cout << "Maria: Mutate -> which == 0 -> random rigid position ligand" << "\n";	
			c.ligands[i].rigid.position += amplitude * random_inside_sphere(generator); 
			
			return; 
		}
		--which;
		if(which == 0) { 
			
			//std::cout << "Maria: Mutate -> which == 0 -> cuaternion ligand" << "\n";				
			fl gr = m.gyration_radius(i); 
			if(gr > epsilon_fl) { // FIXME? just doing nothing for 0-radius molecules. do some other mutation?
				vec rotation; 
				rotation = amplitude / gr * random_inside_sphere(generator); 
				quaternion_increment(c.ligands[i].rigid.orientation, rotation);
			}
			return; 
		}
		--which;
		std::cout << "Maria: Mutate -> which !=0 -> ligand torsions " << "\n";				
		
		if(which < c.ligands[i].torsions.size()) { c.ligands[i].torsions[which] = random_fl(-pi, pi, generator); return; }
		which -= c.ligands[i].torsions.size();
	}
	VINA_FOR_IN(i, c.flex) {
		if(which < c.flex[i].torsions.size()) { c.flex[i].torsions[which] = random_fl(-pi, pi, generator); return; }
		which -= c.flex[i].torsions.size();
	}
}


// does not set model
void mutate_conf2_jMetal(conf& c, const model& m, fl amplitude, rng& generator, fl energy) { // ONE OF: 2A for position, similar amp for orientation, randomize torsion
	//amplitude equals to 2
	sz mutable_entities_num = count_mutable_entities(c);
	if(mutable_entities_num == 0) return;
	int which_int = random_int(0, int(mutable_entities_num - 1), generator);
	VINA_CHECK(which_int >= 0);
	sz which = sz(which_int);
	VINA_CHECK(which < mutable_entities_num);
	//Maria: some methods
	//ligandTorsion(c);
	//ligandRigidPosition(c);
	//ligandRigidOrientantion(c);
	//complexFlex(c);
	//std::cout << "Maria: amplitude: " << amplitude << "\n";		

	VINA_FOR_IN(i, c.ligands) {
		if(which == 0) { 

			std::cout << "Maria: Mutate -> which == 0 -> random rigid position ligand" << "\n";	
			c.ligands[i].rigid.position += amplitude * random_inside_sphere(generator); 
			vec temp2 = random_inside_sphere(generator);
			//loop(temp2, amplitude);
			
			return; 
		}
		--which;
		if(which == 0) { 
			
			//std::cout << "Maria: Mutate -> which == 0 -> cuaternion ligand" << "\n";				
			fl gr = m.gyration_radius(i); 
			if(gr > epsilon_fl) { // FIXME? just doing nothing for 0-radius molecules. do some other mutation?
				vec rotation; 
				rotation = amplitude / gr * random_inside_sphere(generator); 
				quaternion_increment(c.ligands[i].rigid.orientation, rotation);
			}
			return; 
		}

		//std::cout << "Maria: Which value: " << which << "\n";				

		--which;
		//std::cout << "Maria: Mutate -> which !=0 -> ligand torsions " << "\n";				
		
		if(which < c.ligands[i].torsions.size()) { 
			c.ligands[i].torsions[which] = random_fl(-pi, pi, generator); 
			return; 
		}

		which -= c.ligands[i].torsions.size();
		std::cout << "Maria: Which value: (ligand's torsions) " << c.ligands[i].torsions.size() << " " << which << "\n";
		
	}
	
	VINA_FOR_IN(i, c.flex) {
		if(which < c.flex[i].torsions.size()) { 
			c.flex[i].torsions[which] = random_fl(-pi, pi, generator); 
			return; 
		}
		which -= c.flex[i].torsions.size();
		std::cout << "Maria: Which value (flex.torsions): " << c.flex[i].torsions.size() << " " << which << "\n";

	}

}


void jMetal(conf& c, const model& m, fl amplitude, rng& generator, fl energy, vec corner1, vec corner2) {

		sz mutable_entities_num = count_mutable_entities(c);
		if(mutable_entities_num == 0) return;
		int which_int = random_int(0, int(mutable_entities_num - 1), generator);
		VINA_CHECK(which_int >= 0);
		sz which = sz(which_int);
		VINA_CHECK(which < mutable_entities_num);
		
		int num_of_variables = 0;
		VINA_FOR_IN(i, c.ligands) {

			num_of_variables += c.ligands[i].rigid.position.size() 
			+ c.ligands[i].torsions.size() +
			c.flex[i].torsions.size();
		}

		std::cout << "num of variables: " << " "<<  num_of_variables << " " <<"\n";	
		// minimum of x,y,z
		float minX = corner1.data[0];
		//float minY = corner1.data[1];
		//float minZ = corner1.data[2];
		// maximun of x.y,z
		//float maxX = corner2.data[0];
		//float maxY = corner2.data[1];
		//float maxZ = corner2.data[2];

		Problem   * problem_molecular_docking;

		problem_molecular_docking = new DockingVina("Real", num_of_variables);
		

		
		
} // ONE OF: 2A for position, similar amp for orientation, randomize torsion
