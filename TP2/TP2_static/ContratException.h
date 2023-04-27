/**
 * \file   ContratException.h
 * \brief  Fichier contenant la déclaration de la classe ContratException et de ses héritiers
 * \author administrateur
 */

#ifndef CONTRATEXCEPTION_H_DEJA_INCLU
#define CONTRATEXCEPTION_H_DEJA_INCLU

#include <string>
#include <stdexcept>
/**
 * \class ContratException
 * \brief Classe de base des exceptions de contrat.
 */
class ContratException: public std::logic_error
{
public:
	ContratException(std::string, unsigned int, std::string, std::string);
	~ContratException() throw ()
	{
	}
	;
	std::string reqTexteException() const;

private:
	std::string m_expression;
	std::string m_fichier;
	unsigned int m_ligne;
};
/**
 * \class AssertionException
 * \brief Classe pour la gestion des erreurs d'assertion.
 */

class AssertionException: public ContratException
{
public:
	AssertionException(std::string, unsigned int, std::string);
};
/**
 * \class PreconditionException
 * \brief Classe pour la gestion des erreurs de précondition.
 */

class PreconditionException: public ContratException
{
public:
	PreconditionException(std::string, unsigned int, std::string);
};
/**
 * \class PostconditionException
 * \brief Classe pour la gestion des erreurs de postcondition.
 */
class PostconditionException: public ContratException
{
public:
	PostconditionException(std::string, unsigned int, std::string);
};

/**
 * \class InvariantException
 * \brief Classe pour la gestion des erreurs d'invariant.
 */
class InvariantException: public ContratException
{
public:
	InvariantException(std::string, unsigned int, std::string);
};


// --- Définition des macros de contrôle de la théorie du contrat

#if !defined(NDEBUG)
// --- Mode debug

#  define INVARIANTS() \
      verifieInvariant()

#  define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__,__LINE__, #f);
#  define PRECONDITION(f)  \
      if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#  define POSTCONDITION(f) \
      if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
#  define INVARIANT(f)   \
      if (!(f)) throw InvariantException(__FILE__,__LINE__, #f);

// --- LE MODE RELEASE
#else

#  define PRECONDITION(f);
#  define POSTCONDITION(f);
#  define INVARIANTS();
#  define INVARIANT(f);
#  define ASSERTION(f);

#endif  // --- if !defined (NDEBUG)
#endif  // --- ifndef CONTRATEXCEPTION_H_DEJA_INCLU

