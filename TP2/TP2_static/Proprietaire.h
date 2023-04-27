/**
 * \file Proprietaire.h
 * \brief Classe Proprietaire
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H

#include "Vehicule.h"
#include <vector>
#include <memory>

namespace saaq
{

  /**
   * \class Proprietaire
   * \brief Classe des proprietaires
   */
  class Proprietaire
  {
  public:
    Proprietaire (const std::string& p_nom, const std::string& p_prenom);
    Proprietaire (const Proprietaire& p_proprietaire);

    std::string reqNom () const;
    std::string reqPrenom () const;
    int reqNombreDeVehicule () const;
    std::string reqProprietaireFormate () const;

    Proprietaire& operator= (const Proprietaire& p_proprietaire);

    void ajouterVehicule (const Vehicule& p_nouveauVehicule);

    virtual ~Proprietaire ();

  private:
    std::string m_nom;
    std::string m_prenom;

    std::vector<std::unique_ptr<Vehicule>> m_vehicules;

    void verifieInvariant () const;
  };
} /* namespace saaq*/
#endif /* PROPRIETAIRE_H */

