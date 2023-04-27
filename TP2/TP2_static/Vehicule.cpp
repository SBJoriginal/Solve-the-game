/**
 * \file Vehicule.cpp
 * \brief Implementation de la classe de base abstraite Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#include <iostream>
#include <sstream>
#include "Vehicule.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace util;

namespace saaq
{


  /**
   * \brief Le constructeur de la classe Vehicule prend 2 parametres d'entrer et construit un objet Vehicule.
   * \param[in] p_niv est un string qui représente un numéro de série d'un vehicule
   * \param[in] p_immatriculation est un string qui représente un numéro de plaque d'immatriculation d'un véhicule
   * \pre p_niv doit être un numéro de série valide l'aide de la fonction validerNiv()
   * \pre p_immatriculation doit être un numéro de plaque d'immatriculation valide d'un véhicule de promenade ou d'un camion à l'aide de la fonction validerImmatriculationCamion() ou validerImmatriculationPromenade().
   * \post m_niv prend la valeur de p_niv
   * \post m_immatriculation prend la valeur de p_immatriculation
   */
  Vehicule::Vehicule (const string& p_niv, const string& p_immatriculation) : m_niv (p_niv), m_immatriculation (p_immatriculation)
  {
    PRECONDITION (validerNiv (p_niv));
    PRECONDITION ((validerImmatriculationCamion (m_immatriculation)) || (validerImmatriculationPromenade (m_immatriculation)));

    POSTCONDITION (m_niv == p_niv);
    POSTCONDITION (m_immatriculation == p_immatriculation);

    INVARIANTS ();
  }


  /**
   * \brief Donne le numéro de série d'un objet en string
   * \return m_niv
   */
  string
  Vehicule::reqNiv () const
  {
    return m_niv;
  }


  /**
   * \brief Donne l'immatriculation d'un objet en string
   * \return m_immatriculation
   */
  string
  Vehicule::reqImmatriculation () const
  {
    return m_immatriculation;
  }


  /**
   * \brief Assigne une nouvelle valeure a l'immatriculation d'un objet
   * \param[in] p_nouvelleImmatriculation est un string qui représente un nouveau numéro de plaque d'immatriculation d'un vehicule
   * \pre p_nouvelleImmatriculation doit être un numéro de plaque d'immatriculation valide d'un véhicule de promenade ou d'un camion à l'aide de la fonction validerImmatriculationPromenade ou validerImmatriculationCamion()
   * \post m_immatriculation prend la valeur de p_nouvelleImmatriculation
   */
  void
  Vehicule::asgImmatriculation (const string& p_nouvelleImmatriculation)
  {
    PRECONDITION ((validerImmatriculationCamion (m_immatriculation)) || (validerImmatriculationPromenade (m_immatriculation)));

    m_immatriculation = p_nouvelleImmatriculation;

    POSTCONDITION (m_immatriculation == p_nouvelleImmatriculation);

    INVARIANTS ();
  }


  /**
   * \brief Outil de comparaison entre les objets sur tous les attributs.
   * \param[in] p_vehicule est un objet de type Vehicule qui représente un véhicule créé.
   * \return un bool indiquant si deux vehicules sont identiques
   */
  bool Vehicule::operator == (const Vehicule & p_vehicule) const
  {
    return m_niv == p_vehicule.m_niv && m_immatriculation == p_vehicule.m_immatriculation;
  }


  /**
   * \brief Montre un affichage des informations de bases d'un objet de la class Vehicule
   * \return Un affichage qui contient le numéro de série et le numéro d'immatriculation de l'objet de la classe Vehicule en ostringstream
   */
  std::string
  Vehicule::reqVehiculeFormate () const
  {
    ostringstream os;
    os << "Numero de serie : " << reqNiv () << endl << "Numero d'immatriculation : " << reqImmatriculation () << endl;
    return os.str ();
  }


  /**
   *  \brief Destructeur de la class Vehicule
   */
  Vehicule::~Vehicule () { }


  /**
   *  \brief La méthode d'invariant de la classe Vehicule. Ses conditions doivent en tout temps être respectées
   */
  void
  Vehicule::verifieInvariant () const
  {
    INVARIANT (validerNiv (m_niv) == 1);
    INVARIANT ((validerImmatriculationCamion (m_immatriculation)) || (validerImmatriculationPromenade (m_immatriculation)));
  }
} /*using namespace saaq*/