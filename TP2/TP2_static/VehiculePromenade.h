/**
 * \file VehiculePromenade.h
 * \brief Classe déerivée de la classe Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#ifndef VEHICULEPROMENADE_H
#define VEHICULEPROMENADE_H

#include "Vehicule.h"
#include <string>

namespace saaq
{

  /**
   * \class VehiculePromenade
   * \brief Classe déerivée de la classe Vehicule
   */
  class VehiculePromenade : public Vehicule
  {
  public:
    VehiculePromenade (const std::string& p_niv, const std::string& p_immatriculation, const int& p_nmbDePlace);

    int reqNombreDePlace () const;
    virtual std::string reqVehiculeFormate () const;

    virtual void asgImmatriculation (const std::string& p_nouvelleImmatriculation);

    virtual double tarificationAnnuelle () const;

    virtual std::unique_ptr<Vehicule> clone ()const;

    virtual ~VehiculePromenade ();

  private:
    int m_nmbDePlace;
    double m_tarif;

    void verifieInvariant () const;
  };
}/*namespace saaq*/
#endif /*VEHICULEPROMENADE_H*/