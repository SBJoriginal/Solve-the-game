/**
 * \file validationFormat.h
 * \brief Classe de validation divers
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

namespace util
{

  bool validerImmatriculationPromenade (const std::string& p_immatriculation);

  bool validerImmatriculationCamion (const std::string& p_immatriculation);

  bool validerNiv (const std::string& p_niv);

} /* namespace util*/
#endif /* VALIDATIONFORMAT_H */