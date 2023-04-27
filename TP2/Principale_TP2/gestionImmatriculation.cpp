#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "Proprietaire.h"
#include "validationFormat.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;
using namespace saaq;
using namespace util;


int
main ()
{

  cout << "*******************************************************" << endl << endl;
  cout << "Bienvenue a l'outil d'ajout de gestion de vehicules" << endl << endl;
  cout << "*******************************************************" << endl << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "Ajoutez un vehicule de promenade" << endl;
  cout << "--------------------------------------------------------" << endl << endl;

  bool BadNiv = true;
  bool BadImmatriculation = true;
  bool BadNombreDePlace = true;

  string NivPromenade;
  string ImmatriculationPromenade;
  int nombreDePlacePromenade;

  while (BadNiv)
    {
      cout << "Entrez le numero de serie : " << endl;
      getline (cin, NivPromenade);
      if (validerNiv (NivPromenade) == false)
        {
          cout << "Ce numero de Serie n'est pas valide" << endl << endl;
        }
      else
        {
          BadNiv = false;
          cout << endl;
        }
    }

  while (BadImmatriculation)
    {
      cout << "Entrez le numero d'immatriculation : " << endl;
      getline (cin, ImmatriculationPromenade);
      if (validerImmatriculationPromenade (ImmatriculationPromenade) == false)
        {
          cout << "Le numero d'immatriculation n'est pas valide." << endl << endl;
        }
      else
        {
          BadImmatriculation = false;
          cout << endl;
        }
    }

  while (BadNombreDePlace)
    {
      cout << "Entrez le nombre de places > 0 : " << endl;

      if (!(cin >> nombreDePlacePromenade))
        {
          cout << "Le nombre de place n'est pas valide." << endl << endl;
          cin.clear ();
          cin.ignore (numeric_limits<streamsize>::max (), '\n');
        }
      else if (nombreDePlacePromenade < 1)
        {
          cout << "Le nombre de place n'est pas valide." << endl << endl;
        }
      else
        {
          BadNombreDePlace = false;
          cout << endl << endl;
          cin.ignore (numeric_limits<streamsize>::max (), '\n');
        }
    }

  cout << "--------------------------------------------------------" << endl;
  cout << "Ajoutez un camion" << endl;
  cout << "--------------------------------------------------------" << endl << endl;

  BadNiv = true;
  BadImmatriculation = true;
  bool BadPoid = true;
  bool BadnbEssieux = true;

  string NivCamion;
  string ImmatriculationCamion;
  double poidsCamion;
  int nbEssieuxCamion;

  while (BadNiv)
    {
      cout << "Entrez le numero de serie : " << endl;
      getline (cin, NivCamion);
      if (validerNiv (NivCamion) == false)
        {
          cout << "Ce numero de Serie n'est pas valide" << endl << endl;
        }
      else
        {
          BadNiv = false;
          cout << endl;
        }
    }

  while (BadImmatriculation)
    {
      cout << "Entrez le numero d'immatriculation : " << endl;
      getline (cin, ImmatriculationCamion);
      if (validerImmatriculationCamion (ImmatriculationCamion) == false)
        {
          cout << "Le numero d'immatriculation n'est pas valide." << endl << endl;
        }
      else
        {
          BadImmatriculation = false;
          cout << endl;
        }
    }

  while (BadPoid)
    {
      cout << "Entrez le poids du camion > 3000 kg : " << endl;
      if (!(cin >> poidsCamion))
        {
          cout << "Le nombre de place n'est pas valide." << endl << endl;
          cin.clear ();
          cin.ignore (numeric_limits<streamsize>::max (), '\n');
        }
      else if (poidsCamion <= 3000)
        {
          cout << "Le poids du camion n'est pas valide." << endl << endl;
        }
      else
        {
          BadPoid = false;
          cout << endl << endl;
          cin.ignore (numeric_limits<streamsize>::max (), '\n');
        }
    }

  while (BadnbEssieux)
    {
      cout << "Entrez le nombre d'essieux >= 2 : " << endl;
      if (!(cin >> nbEssieuxCamion))
        {
          cout << "Le nombre de place n'est pas valide." << endl << endl;
          cin.clear ();
          cin.ignore (numeric_limits<streamsize>::max (), '\n');

        }
      else if (nbEssieuxCamion < 2)
        {
          cout << "Le nombre d'essieux n'est pas valide." << endl << endl;
        }
      else
        {
          BadnbEssieux = false;
          cout << endl;
          cin.ignore (numeric_limits<streamsize>::max (), '\n');
        }
    }

  VehiculePromenade vehiculePromenade (NivPromenade, ImmatriculationPromenade, nombreDePlacePromenade);
  Camion vehiculeCamion (NivCamion, ImmatriculationCamion, poidsCamion, nbEssieuxCamion);

  Proprietaire humain ("Tremblay", "Louis");
  humain.ajouterVehicule (vehiculePromenade);
  humain.ajouterVehicule (vehiculeCamion);
  cout << humain.reqProprietaireFormate ();

  return 0;
}

