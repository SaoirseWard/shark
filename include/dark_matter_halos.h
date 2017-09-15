/*
 * dark_matter_halos.h
 *
 *  Created on: 4Aug.,2017
 *      Author: clagos
 */

#ifndef INCLUDE_DARK_MATTER_HALOS_H_
#define INCLUDE_DARK_MATTER_HALOS_H_


#include <memory>
#include <string>
#include <vector>

#include "components.h"
#include "cosmology.h"
#include "simulation.h"

namespace shark {

class DarkMatterHaloParameters {

public:
	DarkMatterHaloParameters(const Options &options);

	enum DarkMatterProfile {
		NFW = 0,
		EINASTO
	};

	DarkMatterProfile haloprofile;

};

class DarkMatterHalos{

public:
	DarkMatterHalos(DarkMatterHaloParameters parameters, std::shared_ptr<Cosmology> cosmology, SimulationParameters &sim_params);

	double grav_potential_halo(double r, double c);

	double energy_circular (double r, double c);

	double enclosed_mass(double r, double c);

	double halo_dynamical_time (HaloPtr &halo);

	double halo_virial_radius(HaloPtr &halo);

	double halo_virial_velocity (double mvir, double redshift);

	double halo_lambda (xyz<float> L, double mvir, double redshift);

	double disk_size_theory (Subhalo &subhalo);

	double halo_concentration (HaloPtr &halo);

	double gao_nfw_concentration(double mvir, double a_form);

	double mmw98_nfw_concentration(double mvir, double vmax, double rvir);

private:
	DarkMatterHaloParameters parameters;
	std::shared_ptr<Cosmology> cosmology;
	SimulationParameters sim_params;

};

} // namespace shark




#endif /* INCLUDE_DARK_MATTER_HALOS_H_ */
