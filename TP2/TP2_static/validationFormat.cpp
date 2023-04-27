/**
 * \file validationFormat.cpp
 * \brief Implémentation des tests des numéros de séries et d'immatriculations
 * \author Lenny Plante
 * \version 0.1
 * \date 2023-04-22
 */

#include <string>
#include <iostream>

#include "validationFormat.h"

using namespace std;
namespace util
{


  /**
   * \brief Valide si le numéro de série fournit est valide en bool
   * \param[in] p_niv est un string qui représente un numéro de série d'un vehicule
   * \return validate
   */
  bool
  validerNiv (const std::string& p_niv)
  {
    int sum = 0;
    bool validate = false;
    int final_check;
    if (p_niv.size () == 17)
      {


        for (int i = 0; i < 17; i++)
          {
            int translator = 0;

            if (isalpha (p_niv[i]))
              {
                if (p_niv[i] == 'A')
                  {
                    translator = 1;

                  }
                if (p_niv[i] == 'B')
                  {
                    translator = 2;

                  }
                if (p_niv[i] == 'C')
                  {
                    translator = 3;

                  }
                if (p_niv[i] == 'D')
                  {
                    translator = 4;

                  }
                if (p_niv[i] == 'E')
                  {
                    translator = 5;

                  }
                if (p_niv[i] == 'F')
                  {
                    translator = 6;

                  }
                if (p_niv[i] == 'G')
                  {
                    translator = 7;

                  }
                if (p_niv[i] == 'H')
                  {
                    translator = 8;

                  }
                if (p_niv[i] == 'J')
                  {
                    translator = 1;

                  }
                if (p_niv[i] == 'K')
                  {
                    translator = 2;

                  }
                if (p_niv[i] == 'L')
                  {
                    translator = 3;

                  }
                if (p_niv[i] == 'M')
                  {
                    translator = 4;

                  }
                if (p_niv[i] == 'N')
                  {
                    translator = 5;

                  }
                if (p_niv[i] == 'P')
                  {
                    translator = 7;

                  }
                if (p_niv[i] == 'R')
                  {
                    translator = 9;

                  }
                if (p_niv[i] == 'S')
                  {
                    translator = 2;

                  }
                if (p_niv[i] == 'T')
                  {
                    translator = 3;

                  }
                if (p_niv[i] == 'U')
                  {
                    translator = 4;

                  }
                if (p_niv[i] == 'V')
                  {
                    translator = 5;

                  }
                if (p_niv[i] == 'W')
                  {
                    translator = 6;

                  }
                if (p_niv[i] == 'X')
                  {
                    translator = 7;

                  }
                if (p_niv[i] == 'Y')
                  {
                    translator = 8;

                  }
                if (p_niv[i] == 'Z')
                  {
                    translator = 9;

                  }

              }
            if (isdigit (p_niv[i]))
              {
                if (p_niv[i] == '1')
                  {
                    translator = 1;

                  }
                if (p_niv[i] == '2')
                  {
                    translator = 2;

                  }
                if (p_niv[i] == '3')
                  {
                    translator = 3;

                  }
                if (p_niv[i] == '4')
                  {
                    translator = 4;

                  }
                if (p_niv[i] == '5')
                  {
                    translator = 5;

                  }
                if (p_niv[i] == '6')
                  {
                    translator = 6;

                  }
                if (p_niv[i] == '7')
                  {
                    translator = 7;

                  }
                if (p_niv[i] == '8')
                  {
                    translator = 8;

                  }
                if (p_niv[i] == '9')
                  {
                    translator = 9;


                  }
                if (p_niv[i] == '0')
                  {
                    translator = 0;

                  }
              }
            if (i == 0)
              {
                translator = translator * 8;
                sum += translator;
              }
            if (i == 1)
              {
                translator = translator * 7;
                sum += translator;
              }
            if (i == 2)
              {
                translator = translator * 6;
                sum += translator;
              }
            if (i == 3)
              {
                translator = translator * 5;
                sum += translator;
              }
            if (i == 4)
              {
                translator = translator * 4;
                sum += translator;
              }
            if (i == 5)
              {
                translator = translator * 3;
                sum += translator;
              }
            if (i == 6)
              {
                translator = translator * 2;
                sum += translator;
              }
            if (i == 7)
              {
                translator = translator * 10;
                sum += translator;
              }
            if (i == 8)
              {
                final_check = translator;
                translator = translator * 0;
                sum += translator;

              }
            if (i == 9)
              {
                translator = translator * 9;
                sum += translator;
              }
            if (i == 10)
              {
                translator = translator * 8;
                sum += translator;
              }
            if (i == 11)
              {
                translator = translator * 7;
                sum += translator;
              }
            if (i == 12)
              {
                translator = translator * 6;
                sum += translator;
              }
            if (i == 13)
              {
                translator = translator * 5;
                sum += translator;
              }
            if (i == 14)
              {
                translator = translator * 4;
                sum += translator;
              }
            if (i == 15)
              {
                translator = translator * 3;
                sum += translator;
              }
            if (i == 16)
              {
                translator = translator * 2;
                sum += translator;
              }
            // cout << "index " << i << " the symbol is " << p_niv[i] << endl << " which added " << translator << " to the sum of " << sum << endl << endl;


          }
        int checkDigit;
        checkDigit = sum % 11;
        //cout << "check = " << checkDigit;
        //cout << sum << endl << checkDigit << endl;

        if (checkDigit == 10)
          {
            validate = true;

          }
        else if (checkDigit == final_check)
          {
            validate = true;
          }
      }
    return validate;
  }


  /**
   * \brief Valide si le numéro d'immatriculation fournit est valide en bool
   * \param[in] p_immatriculation est un string qui représente un numéro d'immatriculation d'un camion
   * \return validate
   */
  bool
  validerImmatriculationCamion (const std::string& p_immatriculation)
  {
    bool validate = false;
    if (p_immatriculation.size () == 7)
      {
        if ((p_immatriculation[0]) == 'L')
          {
            if (((isdigit (p_immatriculation[1])) && (isdigit (p_immatriculation[2])) && (isdigit (p_immatriculation[3])) && isdigit (p_immatriculation[4])) && (isdigit (p_immatriculation[5])) && (isdigit (p_immatriculation[6])))
              {
                validate = true;
              }
          }
      }
    return validate;
  }


  /**
   * \brief Valide si le numéro d'immatriculation fournit est valide en bool
   * \param[in] p_immatriculation est un string qui représente un numéro d'immatriculation d'un vehicule de promenade
   * \return valide
   */
  bool
  validerImmatriculationPromenade (const std::string& p_immatriculation)
  {
    bool valide = false;

    if (p_immatriculation.size () == 7)
      {
        if ((isdigit (p_immatriculation[0])) && (isdigit (p_immatriculation[1])) && (isdigit (p_immatriculation[2]))) //checks if the first three digits are numbers
          {
            if (isspace (p_immatriculation[3] )) //check if 4 slot is a space (to know if we are going in category 1)
              {
                if ((isalpha (p_immatriculation[4])) && (isalpha (p_immatriculation[5])) && (isalpha (p_immatriculation[6]))) //confirms if in category 1
                  {
                    //cout << "000 abc" << endl;
                    valide = true;
                  }
              }
            else if (isalpha (p_immatriculation[3]))
              {
                if ((isdigit (p_immatriculation[4])) && (isdigit (p_immatriculation[5])) && (isdigit (p_immatriculation[6])))// confirms if in category 2
                  {
                    //cout << "000H000" << endl;
                    valide = true;
                  }
              }
          }
        if ((isalpha (p_immatriculation[0])) && (isspace (p_immatriculation[3])))//either category 3 or 4
          {
            if ((isdigit (p_immatriculation[1])) && (isdigit (p_immatriculation[2])))//checks if in category 3
              {
                if ((isalpha (p_immatriculation[4])) && (isalpha (p_immatriculation[5])) && (isalpha (p_immatriculation[6])))//confirms in category 3
                  {
                    //cout << "A00 ABC" << endl;
                    valide = true;
                  }
              }
            else if ((isalpha (p_immatriculation[1])) && (isalpha (p_immatriculation[2])))//checks if in category 4
              {
                if ((isdigit (p_immatriculation[4])) && (isdigit (p_immatriculation[5])) && (isdigit (p_immatriculation[6])))//confirms if in category 4
                  {
                    //out << "ABC 000" << endl;
                    valide = true;
                  }
              }
          }
      }
    return valide;
  }

} /* namespace util*/
