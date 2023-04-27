/**
 * \file ContratException.cpp
 * \brief Implantation de la classe ContratException et de ses héritiers
 * \author administrateur
 */
#include "ContratException.h"
#include <sstream>

using namespace std;


/**
 * \brief Constructeur de la classe de base ContratException
 * \param p_fichP chaîne de caractères représentant le fichier source dans lequel a eu lieu l'erreur
 * \param p_prmLigne un entier représentant la ligne où a eu lieu l'erreur
 * \param p_msgP Message décrivant l'erreur
 * \param p_exprP Test logique qui a échoué
 */
ContratException::ContratException (std::string p_fichP, unsigned int p_prmLigne,
                                    std::string p_exprP, std::string p_msgP) :
logic_error (p_msgP), m_expression (p_exprP), m_fichier (p_fichP), m_ligne (p_prmLigne) { }


/**
 * \brief Construit le texte complet relié à l'exception de contrat
 * \return une chaîne de caractères correspondant à l'exception
 */
std::string
ContratException::reqTexteException () const
{
  // ---  Prépare le message
  ostringstream os;
  os << "Message : " << what () << endl;
  os << "Fichier : " << m_fichier << endl;
  os << "Ligne   : " << m_ligne << endl;
  os << "Test    : " << m_expression << endl;

  return os.str ();
}


/**
 * \brief Constructeur de la classe AssertionException \n
 *    	Le constructeur public AssertionException(...)initialise
 *     	sa classe de base ContratException. On n'a pas d'attribut local. Cette
 *     	classe est intéressante pour son TYPE lors du traitement des exceptions.
 * \param p_fichP chaîne de caractères représentant le fichier source dans lequel a eu lieu l'erreur
 * \param p_prmLigne un entier représentant la ligne où a eu lieu l'erreur
 * \param p_exprP Test logique qui a échoué
 *
 */

AssertionException::AssertionException (std::string p_fichP, unsigned int p_prmLigne,
                                        std::string p_exprP)
: ContratException (p_fichP, p_prmLigne, p_exprP, "ERREUR D'ASSERTION") { }


/**
 * \brief Constructeur de la classe PreconditionException en initialisant la classe de base ContratException.
 * 		 La classe représente l'erreur de précondition dans la théorie du contrat.
 * \param p_fichP chaîne de caractères représentant le fichier source dans lequel a eu lieu l'erreur
 * \param p_prmLigne un entier représentant la ligne où a eu lieu l'erreur
 * \param p_exprP Test logique qui a échoué
 */
PreconditionException::PreconditionException (std::string p_fichP, unsigned int p_prmLigne,
                                              std::string p_exprP)
: ContratException (p_fichP, p_prmLigne, p_exprP, "ERREUR DE PRECONDITION") { }


/**
 * \brief Constructeur de la classe PostconditionException en initialisant la classe de base ContratException.
 *        La classe représente des erreurs de postcondition dans la théorie du contrat.
 * \param p_fichP chaîne de caractères représentant le fichier source dans lequel a eu lieu l'erreur
 * \param p_prmLigne un entier représentant la ligne où a eu lieu l'erreur
 * \param p_exprP Test logique qui a échoué
 */
PostconditionException::PostconditionException (std::string p_fichP, unsigned int p_prmLigne,
                                                std::string p_exprP)
: ContratException (p_fichP, p_prmLigne, p_exprP, "ERREUR DE POSTCONDITION") { }


/**
 * \brief Constructeur de la classe InvariantException en initialisant la classe de base ContratException.
 * La classe représente des erreurs d'invariant dans la théorie du contrat.
 * \param p_fichP chaîne de caractères représentant le fichier source dans lequel a eu lieu l'erreur
 * \param p_prmLigne un entier représentant la ligne où a eu lieu l'erreur
 * \param p_exprP Test logique qui a échoué
 */
InvariantException::InvariantException (std::string p_fichP, unsigned int p_prmLigne,
                                        std::string p_exprP)
: ContratException (p_fichP, p_prmLigne, p_exprP, "ERREUR D'INVARIANT") { }
