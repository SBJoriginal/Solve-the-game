/**
 * \file Camion.h
 * \brief Classe déerivée de la classe Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehicule.h"
#include <string>

namespace saaq
{

    /**
   * \class Camion
   * \brief Classe déerivée de la classe Vehicule
   */
  class Camion : public Vehicule
  {
  public:
    Camion (const std::string& p_niv, const std::string& p_immatriculationdouble, const double& m_poids, const int& m_nbEssieux);

    double reqPoids () const;
    int reqNombreEssieux () const;
    virtual std::string reqVehiculeFormate () const;

    virtual void asgImmatriculation (const std::string& p_nouvelleImmatriculation);

    virtual double tarificationAnnuelle () const;

    virtual std::unique_ptr<Vehicule> clone ()const;

    virtual ~Camion ();

  private:
    double m_poids;
    int m_nbEssieux;

    void verifieInvariant () const;
  };
}/*namespace saaq*/
#endif /* CAMION_H */

