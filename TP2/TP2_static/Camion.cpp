/**
 * \file Camion.cpp
 * \brief Implémentation de la classe dérivée Camion de la base abstraite Vehicule
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#include <iostream>
#include <sstream>
#include "Camion.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace util;

namespace saaq
{


  /**
   * \brief Le constructeur de la classe Camion qui prend 4 paramètres d'entrer et construit un objet Camion.
   * \param[in] p_niv est un string qui représente un numéro de série d'un véhicule de promenade
   * \param[in] p_immatriculation est un string qui représente un numéro de plaque d'immatriculation d'un véhicule de promenade
   * \param[in] p_poids est un double qui représente le poids d'un camion
   * \param[in] p_nbEssieux est un int qui représente le nombre d'essieux d'un camion
   * \pre p_niv doit être un numéro de série valide à l'aide de la fonction validerNiv()
   * \pre p_immatriculation doit être un numéro de plaque d'immatriculation valide d'un véhicule de promenade à l'aide de la fonction validerImmatriculationCamion().
   * \pre p_poids doit être plus grand que 3000
   * \pre p_nbEssieux doit être plus grand ou égal que 2
   * \post m_niv prend la valeur de p_niv
   * \post m_immatriculation prend la valeur de p_immatriculation
   * \post m_poids prend la valeur de p_poids
   * \post m_nbEssieux prend la valeur de p_nbEssieux
   */
  Camion::Camion (const std::string& p_niv, const std::string& p_immatriculation, const double& p_poids, const int& p_nbEssieux) : Vehicule (p_niv, p_immatriculation), m_poids (p_poids), m_nbEssieux (p_nbEssieux)
  {
    PRECONDITION (validerNiv (p_niv));
    PRECONDITION (validerImmatriculationCamion (m_immatriculation));
    PRECONDITION ((m_poids) > 3000);
    PRECONDITION ((m_nbEssieux) >= 2);

    POSTCONDITION (m_niv == p_niv);
    POSTCONDITION (m_immatriculation == p_immatriculation);
    POSTCONDITION (m_poids = p_poids);
    POSTCONDITION (m_nbEssieux = p_nbEssieux);

    INVARIANTS ();
  }


  /**
   * \brief Donne le poids d'un objet  en double
   * \return m_poids
   */
  double
  Camion::reqPoids () const
  {
    return m_poids;
  }


  /**
   * \brief Donne le nombre d'essieux d'un objet en int
   * \return m_nbEssieux
   */
  int
  Camion::reqNombreEssieux () const
  {
    return m_nbEssieux;
  }


  /**
   * \brief Assigne une nouvelle valeure à l'immatriculation d'un objet camion
   * \param[in] p_nouvelleImmatriculation est un string qui représente un nouveau numéro de plaque d'immatriculation d'un camion
   * \pre p_nouvelleImmatriculation doit être un numéro de plaque d'immatriculation valide d'un camion à l'aide de la fonction validerImmatriculationCamion().
   * \post m_immatriculation prend la valeur de p_nouvelleImmatriculation
   */
  void
  Camion::asgImmatriculation (const std::string& p_nouvelleImmatriculation)
  {
    PRECONDITION (validerImmatriculationCamion (p_nouvelleImmatriculation));

    m_immatriculation = p_nouvelleImmatriculation;

    POSTCONDITION (m_immatriculation == p_nouvelleImmatriculation);
  }


  /**
   * \brief Calcule le coût du renouvellement de l'immatriculation pour un camion dans la valeur m_tarif
   * \pre p_poids doit être plus grand que 3000
   * \pre p_nbEssieux doit être plus grand ou égal que 2
   * \post m_tarif à la même valeur que total
   * \return m_tarif d'un camion en double;
   */
  double
  Camion::tarificationAnnuelle () const
  {
    PRECONDITION ((m_poids) > 3000);
    PRECONDITION ((m_nbEssieux) >= 2);

    double total;
    double m_tarif;

    if (m_nbEssieux == 2)
      {
        if (m_poids <= 4000)
          {
            m_tarif = 634.89;
            total = 634.89;
          }
        else
          {
            m_tarif = 999.89;
            total = 999.89;
          }
      }
    else if (m_nbEssieux == 3)
      {
        m_tarif = 1711.19;
        total = 1711.19;
      }
    else if (m_nbEssieux == 4)
      {
        m_tarif = 2409.19;
        total = 2409.19;
      }
    else if (m_nbEssieux == 5)
      {
        m_tarif = 3051.13;
        total = 3051.13;
      }
    else
      {
        m_tarif = 4041.13;
        total = 4041.13;
      }

    POSTCONDITION (m_tarif == total)

    INVARIANTS ();

    return m_tarif;
  }


  /**
   * \brief Fait une copie allouée sur le monceau de l'objet courant tout en déléguant la libération de la mémoire à un pointeur intelligent.
   * \return make_unique <Camion> (*this)
   */
  std::unique_ptr<Vehicule>
  Camion::clone ()const
  {
    return make_unique <Camion> (*this);
  }


  /**
   * \brief Montre un affichage des informations de bases de la class Vehicule et les informations unique du camion
   * \return Un affichage qui contient le numéro de série, le numéro d'immatriculation le poids et le nombre d'essieux de l'objet de la classe Vehicule en ostringstream
   */
  std::string
  Camion::reqVehiculeFormate () const
  {
    ostringstream os;
    os << "Format d'un Camion" << endl;
    os << Vehicule::reqVehiculeFormate ();
    os << "nombre d'essieux : " << reqNombreEssieux () << endl << "poids : " << reqPoids () << " kg" << endl << "tarif : " << tarificationAnnuelle () << "$" ;

    return os.str ();
  }


  /**
   * \brief Destructeur de la class Camion
   */
  Camion::~Camion () { }


  /**
   * La méthode d'invariant de la classe Vehicule. Ses conditions doivent en tout temps être respectées
   */
  void
  Camion::verifieInvariant () const
  {
    INVARIANT (validerNiv (m_niv));
    INVARIANT (validerImmatriculationCamion (m_immatriculation));
    INVARIANT ((m_poids) > 3000);
    INVARIANT ((m_nbEssieux) >= 2);
  }
}/*using namespace saaq*/