/**
 * \file Vehicule.h
 * \brief Classe de base abstraite Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <memory>

namespace saaq
{

  /**
   * \class Vehicule
   * \brief Classe de base
   */
  class Vehicule
  {
  public:
    Vehicule (const std::string& p_niv, const std::string& p_immatriculation);

    std::string reqNiv () const;
    std::string reqImmatriculation () const;
    virtual std::string reqVehiculeFormate () const;

    bool operator== (const Vehicule & p_vehicule) const;

    virtual double tarificationAnnuelle () const = 0;

    virtual std::unique_ptr<Vehicule> clone () const = 0;

    virtual ~Vehicule ();

  protected:
    std::string m_niv;
    std::string m_immatriculation;

    virtual void asgImmatriculation (const std::string& p_nouvelleImmatriculation);

  private:
    void verifieInvariant () const;
  };
} /* namespace saaq*/
#endif /* VEHICULE_H */

