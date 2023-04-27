/**
 * \file VehiculePromenade.cpp
 * \brief Implementation de la classe dérivée VehiculePromenade de la base abstraite Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#include <iostream>
#include <sstream>
#include "VehiculePromenade.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace util;

namespace saaq
{


  /**
   * \brief Le constructeur de la classe VehiculePromenade qui prend 3 paramètres d'entrer et construit un objet VehiculePromenade.
   * \param[in] p_niv est un string qui représente un numéro de série d'un véhicule de promenade
   * \param[in] p_immatriculation est un string qui représente un numéro de plaque d'immatriculation d'un véhicule de promenade
   * \param[in] p_nmbDePlace est un int qui représente le nombre de place dans un véhicule de promenade
   * \pre p_niv doit être un numéro de série valide l'aide de la fonction validerNiv()
   * \pre p_immatriculation doit être un numéro de plaque d'immatriculation valide d'un véhicule de promenade à l'aide de la fonction validerImmatriculationPromenade()
   * \pre p_nmbDePlace doit être plus grand que 0
   * \post m_niv prend la valeur de p_niv
   * \post m_immatriculation prend la valeur de p_immatriculation
   * \post m_nmbDePlace prend la valeur de p_nmbDePlace
   */
  VehiculePromenade::VehiculePromenade (const std::string& p_niv, const std::string& p_immatriculation,  const int& p_nmbDePlace) : Vehicule (p_niv, p_immatriculation), m_nmbDePlace (p_nmbDePlace)
  {
    PRECONDITION (validerNiv (p_niv));
    PRECONDITION (validerImmatriculationPromenade (p_immatriculation));
    PRECONDITION (p_nmbDePlace > 0);

    POSTCONDITION (m_niv == p_niv);
    POSTCONDITION (m_immatriculation == p_immatriculation);
    POSTCONDITION (m_nmbDePlace == p_nmbDePlace);

    INVARIANTS ();
  }


  /**
   * \brief Donne le nombre de place d'un objet en string
   * \return m_nmbDePlace
   */
  int
  VehiculePromenade::reqNombreDePlace () const
  {
    return m_nmbDePlace;
  }


  /**
   * \brief Assigne une nouvelle valeure à l'immatriculation d'un objet
   * \param[in] p_nouvelleImmatriculation est un string qui représente un nouveau numéro de plaque d'immatriculation d'un véhicule de promenade
   * \pre p_nouvelleImmatriculation doit être un numéro de plaque d'immatriculation valide d'un véhicule de promenade à l'aide de la fonction validerImmatriculationPromenade().
   * \post m_immatriculation prend la valeur de p_nouvelleImmatriculation
   */
  void
  VehiculePromenade::asgImmatriculation (const std::string& p_nouvelleImmatriculation)
  {
    PRECONDITION (validerImmatriculationPromenade (p_nouvelleImmatriculation) == 1);

    m_immatriculation = p_nouvelleImmatriculation;

    POSTCONDITION (m_immatriculation == p_nouvelleImmatriculation);

    INVARIANTS ();
  }


  /**
   * \brief Donne la tarification fixe d'un véhicule de promenade de 232.74 $ dans la valeur de retour
   * \return m_tarif d'un véhicule de promenade en double;

   */
  double
  VehiculePromenade::tarificationAnnuelle () const
  {
    double m_tarif = 234.74;
    return m_tarif;
  }


  /**
   * \brief Fait une copie allouée sur le monceau de l'objet courant tout en déléguant la libération de la mémoire à un pointeur intelligent.
   * \return make_unique <VehiculePromenade> (*this)
   */
  std::unique_ptr<Vehicule>
  VehiculePromenade::clone ()const
  {
    return make_unique <VehiculePromenade> (*this);
  }


  /**
   * \brief Montre un affichage des informations de bases de la class Vehicule et les informations uniques du véhicule de promenade
   * \return Un affichage qui contient le numéro de série, le numéro d'immatriculation et le nombre de place de l'objet de la classe Vehicule en ostringstream
   */
  std::string
  VehiculePromenade::reqVehiculeFormate () const
  {
    ostringstream os;
    /*
    os << "Numero de serie : " << reqNiv () << endl << "Numero d'immatriculation : " << reqImmatriculation () << endl << "nombre de places : " << reqNombreDePlace () << endl << "tarif : " << tarificationAnnuelle () << "$" << endl;
     * */
    os << "Format d'un Vehicule De Promenade" << endl;
    os << Vehicule::reqVehiculeFormate ();
    os << "nombre de places : " << reqNombreDePlace () << endl << "tarif : " << tarificationAnnuelle () << "$";

    return os.str ();
  }


  /**
   * \brief Destructeur de la class VehiculePromenade
   */
  VehiculePromenade::~VehiculePromenade () { }


  /**
   *  \brief La méthode d'invariant de la classe Vehicule. Ses conditions doivent en tout temps être respectées
   */
  void
  VehiculePromenade::verifieInvariant () const
  {
    INVARIANT (validerNiv (m_niv));
    INVARIANT (validerImmatriculationPromenade (m_immatriculation));
    INVARIANT (m_nmbDePlace > 0);
  }
}/*using namespace saaq*/