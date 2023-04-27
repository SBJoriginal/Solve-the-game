/**
 * \file Proprietaire.cpp
 * \brief Implémentation de la classe Proprietaire
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#include <iostream>
#include <sstream>
#include <memory>
#include <list>
#include "VehiculePromenade.h"
#include "Vehicule.h"
#include "Camion.h"
#include "Proprietaire.h"
#include "ContratException.h"

using namespace std;
namespace saaq
{


  /**
   * \brief Le constructeur de la classe Proprietaire qui prend 2 paramètres d'entrer et construit un objet Proprietaire.
   * \param[in] p_nom est un string qui représente un nom d'un proprietaire
   * \param[in] p_prenom est un string qui représente un prenom d'un proprietaire
   * \pre p_nom ne doit pas être vide
   * \pre p_prenom ne doit pas être vide
   * \post m_nom prend la valeur de p_nom
   * \post m_prenom prend la valeur de p_prenom
   */
  Proprietaire::Proprietaire (const std::string& p_nom, const std::string& p_prenom) : m_nom (p_nom), m_prenom (p_prenom)
  {
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (!p_prenom.empty ());

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_prenom == p_prenom);

    INVARIANTS ();
  }


  /**
   * \brief Le constructeur copie de la classe Proprietaire qui prend 1 paramètre d'entrer
   * \param p_proprietaire est un objet de type Proprietaire&
   */
  Proprietaire::Proprietaire (const Proprietaire& p_proprietaire) : m_nom (p_proprietaire.m_nom), m_prenom (p_proprietaire.m_prenom)
  {
    PRECONDITION (dynamic_cast<const Proprietaire*> (&p_proprietaire) != nullptr);
    for (auto & element : p_proprietaire.m_vehicules)
      {
        ajouterVehicule (*element);
      }
    POSTCONDITION (m_nom == p_proprietaire.m_nom);
    POSTCONDITION (m_prenom == p_proprietaire.m_prenom);
  }


  /**
   * \brief Donne le nom d'un objet en string
   * \return m_nom
   */
  string
  Proprietaire::reqNom () const
  {
    return m_nom;
  }


  /**
   * \brief Donne le prénom d'un objet en string
   * \return m_prenom
   */
  string
  Proprietaire::reqPrenom () const
  {
    return m_prenom;
  }


  /**
   * \brief Donne le nombre de Véhicule qui sont associés à un objet Proprietaire dans la variable number en int.
   * \return number
   */
  int
  Proprietaire::reqNombreDeVehicule () const
  {
    int number = 0;
    for (const auto & element : m_vehicules)
      {
        number++;
      }
    return number;
  }


  /**
   * \brief Rajoute un vehicule à un objet Proprietaire
   * \param[in] p_nouveauVehicule est un objet de type VehiculePromenade ou Camion qui represente un véhicule
   * \pre p_nouveauVehicule doit appertenir à la classe VehiculePromenade ou Camion
   */
  void
  Proprietaire::ajouterVehicule (const Vehicule& p_nouveauVehicule)
  {
    PRECONDITION ((dynamic_cast<const Camion*> (&p_nouveauVehicule) != nullptr) || (dynamic_cast<const VehiculePromenade*> (&p_nouveauVehicule) != nullptr));

    m_vehicules.push_back (p_nouveauVehicule.clone ());

    INVARIANTS ();
  }


  /**
   * \brief C'est une forme canonique de coplien, il faut faire une copie en profondeur
   *  \param[in] p_proprietaire est un objet de type Proprietaire qui représente un proprietaire
   * @return *this
   */
  Proprietaire& Proprietaire::operator= (const Proprietaire& p_proprietaire)
  {
    PRECONDITION (dynamic_cast<const Proprietaire*> (&p_proprietaire) != nullptr);

    if (!(this == & p_proprietaire  ))
      {
        m_nom = p_proprietaire.m_nom;
        m_prenom = p_proprietaire.m_prenom;
        m_vehicules.clear ();

        for (auto & element : p_proprietaire.m_vehicules)
          {
            ajouterVehicule (*element);
          }
      }
    POSTCONDITION (m_nom == p_proprietaire.m_nom);
    POSTCONDITION (m_prenom == p_proprietaire.m_prenom);
    return *this;
  }


  /**
   * \brief Montre un affichage des informations du Proprietaire et chaque véhicule qui lui sont associés.
   * \return Un affichage qui contient le nom et le prenom de l'objet de la classe proprietaire. Ensuite il affiche le numéro de série, le numéro d'immatriculation et les détails uniques dependent du type de véhicule pour chaque objets des classes dérivées de Vehicule en ostringstream
   */
  string
  Proprietaire::reqProprietaireFormate () const
  {
    ostringstream os;
    os << endl << "Proprietaire" << endl << "-------------------" << endl << "Nom : " << reqNom () << endl << "Prenom : " << reqPrenom () << endl ;
    for (const auto & element : m_vehicules)
      {
        os << "-------------------" << endl << element ->reqVehiculeFormate () << endl;
      }

    return os.str ();
  }


  /**
   *\brief Destructeur de la class Proprietaire
   */
  Proprietaire::~Proprietaire () { }


  /**
   *  \brief La méthode d'invariant de la classe Proprietaire. Ses conditions doivent en tout temps être respectées
   */
  void
  Proprietaire::verifieInvariant () const
  {
    INVARIANT (!m_nom.empty ());
    INVARIANT (!m_prenom.empty ());
  }
}/*using namespace saaq*/