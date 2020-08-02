/*
 Copyright (C) 2015 - 2019 by the authors of the ASPECT code.

 This file is part of ASPECT.

 ASPECT is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.

 ASPECT is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with ASPECT; see the file LICENSE.  If not see
 <http://www.gnu.org/licenses/>.
 */

#ifndef _aspect_particle_property_position_h
#define _aspect_particle_property_position_h

#include <aspect/particle/property/interface.h>

namespace aspect
{
  namespace Particle
  {
    namespace Property
    {
      /**
       * A class that sets particle properties to the current position.
       *
       * @ingroup ParticleProperties
       */
      template <int dim>
      class Position : public Interface<dim>
      {
        public:
          /**
           * Initialization function. This function is called once at the
           * creation of every particle for every property to initialize its
           * value.
           *
           * @param [in] position The current particle position.
           * @param [in,out] particle_properties The properties of the particle
           * that is initialized within the call of this function. The purpose
           * of this function should be to extend this vector by a number of
           * properties.
           */
          void
          initialize_one_particle_property (const Point<dim> &position,
                                            std::vector<double> &particle_properties) const override;

          /**
          * @copydoc aspect::Particle::Property::Interface::update_particle_property()
          **/
          virtual
          void
          update_particle_property (const unsigned int data_position,
                                    const Vector<double> &solution,
                                    const std::vector<Tensor<1,dim> > &gradients,
                                    typename ParticleHandler<dim>::particle_iterator &particle) const override;

          /**
           * This implementation tells the particle manager that
           * we need to update particle properties over time.
           */
          UpdateTimeFlags
          need_update () const override;

          /**
           * Set up the information about the names and number of components
           * this property requires.
           *
           * @return A vector that contains pairs of the property names and the
           * number of components this property plugin defines.
           */
          std::vector<std::pair<std::string, unsigned int> >
          get_property_information() const override;
      };
    }
  }
}

#endif

