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

#include "monte_carlo.h"
#include "coords.h"
#include "mutate.h"
#include "quasi_newton.h"

output_type monte_carlo::operator()(model& m, const precalculate& p, const igrid& ig, const precalculate& p_widened, const igrid& ig_widened, const vec& corner1, const vec& corner2, incrementable* increment_me, rng& generator) const {
	std::cout << "Maria: Montecarlo_operator "  << "\n"; 	
	output_container tmp;
	this->operator()(m, tmp, p, ig, p_widened, ig_widened, corner1, corner2, increment_me, generator); // call the version that produces the whole container
	VINA_CHECK(!tmp.empty());
	return tmp.front();
}

bool metropolis_accept(fl old_f, fl new_f, fl temperature, rng& generator) {
	//std::cout << "Maria: Montecarlo_accept "  << "\n"; 	
	if(new_f < old_f) return true;
	const fl acceptance_probability = std::exp((old_f - new_f) / temperature);
	return random_fl(0, 1, generator) < acceptance_probability;
}

void monte_carlo::single_run(model& m, output_type& out, const precalculate& p, const igrid& ig, rng& generator) const {
	std::cout << "Maria: Montecarlo->Single run  "  << "\n"; 	
	conf_size s = m.get_size();
	change g(s);
	vec authentic_v(1000, 1000, 1000);
	out.e = max_fl;
	output_type current(out);
	quasi_newton quasi_newton_par; 
	quasi_newton_par.max_steps = ssd_par.evals;
	VINA_U_FOR(step, num_steps) {
		//TODO: Se mete aqui? SUPERIMPORTANTEEEEEE
		output_type candidate(current.c, max_fl);
		mutate_conf(candidate.c, m, mutation_amplitude, generator);
		quasi_newton_par(m, p, ig, candidate, g, hunt_cap);
		if(step == 0 || metropolis_accept(current.e, candidate.e, temperature, generator)) {
			quasi_newton_par(m, p, ig, candidate, g, authentic_v);
			current = candidate;
			if(current.e < out.e)
				out = current;
		}
	}
	quasi_newton_par(m, p, ig, out, g, authentic_v);
}

void monte_carlo::many_runs(model& m, output_container& out, const precalculate& p, const igrid& ig, const vec& corner1, const vec& corner2, sz num_runs, rng& generator) const {
	std::cout << "Maria: Montecarlo->many runs  "  << "\n"; 		
	conf_size s = m.get_size();
	VINA_FOR(run, num_runs) {
		output_type tmp(s, 0);
		tmp.c.randomize(corner1, corner2, generator);
		single_run(m, tmp, p, ig, generator);
		out.push_back(new output_type(tmp));
	}
	out.sort();
}

output_type monte_carlo::many_runs(model& m, const precalculate& p, const igrid& ig, const vec& corner1, const vec& corner2, sz num_runs, rng& generator) const {
	output_container tmp;
	many_runs(m, tmp, p, ig, corner1, corner2, num_runs, generator);
	VINA_CHECK(!tmp.empty());
	return tmp.front();
}


void writeAtomTorsionsLigand(output_type tmp){
	
		std::vector<ligand_conf> ligandsatom_coordinates = tmp.c.ligands;
		for (std::vector<ligand_conf>::iterator it = ligandsatom_coordinates.begin() ; it != ligandsatom_coordinates.end(); ++it){
			std::vector<fl> torsions = (*it).torsions;
			for (std::vector<fl>::iterator it2 = torsions.begin() ; it2 != torsions.end(); ++it2){
				//std::cout << " Maria ligands' torsions: " << (*it2) << "\n";				 
			}
	}
}

void writeAtomTCoordsLigand(output_type tmp){
	
		std::vector<vec> ligandsatom_coordinates = tmp.coords;
		for (std::vector<vec>::iterator it = ligandsatom_coordinates.begin() ; it != ligandsatom_coordinates.end(); ++it){
			//std::cout << " Maria ligands' atoms coordenates: " << (*it).data[0] << "\n";				 
			
	
		}
}



void loopCorner1(vec corner1, vec corner2){


		std::cout << " Maria grid (corner1):  " 
		<< corner1.data[0] << "  " 
		<< corner1.data[1] << "  "
		<< corner1.data[2] << "\n";				 
		std::cout << " Maria grid (corner2): " << corner2.data[0] << " " << corner2.data[1] << " " << corner2.data[2] << "\n";				 

	
}


void sizeConf(conf_size s){

	std::vector<sz> ligands = s.ligands;
	int ligand_size = s.ligands.size();
	//std::cout << " Maria ligands' size: " << ligand_size << "\n";	
	for (std::vector<sz>::iterator it = ligands.begin() ; it != ligands.end(); ++it){
		
		//std::cout << " Maria ligands: " << (*it) << "\n";			
			 
	}		

	std::vector<sz> ligands_flex = s.flex;
	for (std::vector<sz>::iterator it = ligands_flex.begin() ; it != ligands_flex.end(); ++it){
		
		//std::cout << " Maria ligands flexibility: " << (*it) << "\n";		
	}
	
	sz num_degrees_of_freedom = s.num_degrees_of_freedom();
	//std::cout << " Maria num_degrees_of_freedom: " << num_degrees_of_freedom << "\n";		
	

}

// out is sorted
void monte_carlo::operator()(model& m, output_container& out, const precalculate& p, const igrid& ig, 
const precalculate& p_widened, const igrid& ig_widened, const vec& corner1, const vec& corner2, 
incrementable* increment_me, rng& generator) const {
	std::cout << "Maria: Operator:  "  << "\n"; 	
	
	vec authentic_v(1000, 1000, 1000); // FIXME? this is here to avoid max_fl/max_fl
	conf_size s = m.get_size();	
	//Maria sizeConf(s):
	//sizeConf(s);
	
	change g(s);
	output_type tmp(s, 0);
	
	//Maria: writeAtomCoordsLigand(tmp);
	//std::cout << "Maria: Temp.energy:  " << tmp.e << "\n"; 
	//loopCorner1(corner1, corner2);
		
	tmp.c.randomize(corner1, corner2, generator);

	//loopCorner1(corner1, corner2);

	fl best_e = max_fl;
	//std::cout << "Maria: best energy:  " << best_e << "\n"; 		

	quasi_newton quasi_newton_par; 
	quasi_newton_par.max_steps = ssd_par.evals;
	VINA_U_FOR(step, num_steps) {
		if(increment_me)
			++(*increment_me);
		output_type candidate = tmp;
		
		//writeAtomTorsionsLigand(candidate); //Maria: write torsions from ligand candidate
		//writeAtomTCoordsLigand(candidate); //Maria: write atoms 
		
		//std::cout << "Maria: Candidate.e -> Before mutate_config2  " << candidate.e << "\n"; 		
		
		mutate_conf2_jMetal(candidate.c, m, mutation_amplitude, generator, candidate.e); //Maria: Call the function called mutate_conf2
		jMetal(candidate.c, m, mutation_amplitude, generator, candidate.e, corner1, corner2);
		std::cout << "Maria: Candidate.e -> After mutate_config2  " << candidate.e << "\n"; 		

		quasi_newton_par(m, p, ig, candidate, g, hunt_cap);
		if(step == 0 || metropolis_accept(tmp.e, candidate.e, temperature, generator)) {
			tmp = candidate;

			m.set(tmp.c); // FIXME? useless?

			// FIXME only for very promising ones
			if(tmp.e < best_e || out.size() < num_saved_mins) {
				quasi_newton_par(m, p, ig, tmp, g, authentic_v);
				m.set(tmp.c); // FIXME? useless?
				tmp.coords = m.get_heavy_atom_movable_coords();
				add_to_output_container(out, tmp, min_rmsd, num_saved_mins); // 20 - max size
				if(tmp.e < best_e)
					best_e = tmp.e;
						
						//std::cout << "Maria: Candidate.e -> Best energy at the moment  " << best_e << "\n"; 		

					if(best_e<0){

						//std::cout << "Maria: Candidate.e -> Best energy lower than 0  " << best_e << "\n"; 		

					}

			}
		}
	}
	VINA_CHECK(!out.empty());
	VINA_CHECK(out.front().e <= out.back().e); // make sure the sorting worked in the correct order
	std::cout << "Energy: " << out.front().e << "\n"; 
}
