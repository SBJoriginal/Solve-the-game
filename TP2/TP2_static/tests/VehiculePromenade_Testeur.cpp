#include <gtest/gtest.h>
#include "VehiculePromenade.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
#include <string>

using namespace saaq;
using namespace std;


TEST (VehiculePromenade, ConstructeurBonNivBonImma)
{
  VehiculePromenade voiture ("1M8GDM9AXKP042788", "ABC 000", 4);
  ASSERT_EQ ("1M8GDM9AXKP042788", voiture.reqNiv ());
  ASSERT_EQ ("ABC 000", voiture.reqImmatriculation ());
  ASSERT_EQ (4, voiture.reqNombreDePlace ());
}


TEST (VehiculePromenade, ConstructeurMauvaisNiv)
{
  ASSERT_THROW (VehiculePromenade voiture ("1M8GDM543XKP042788", "ABC 000", 4), ContratException) << "Le niv est invalide";
}


TEST (VehiculePromenade, ConstructeurMauvaisImma)
{

  ASSERT_THROW (VehiculePromenade voiture ("1M8GDM9AXKP042788", "L000000", 4), ContratException) << "L'immatriculation est invalide";
}


TEST (VehiculePromenade, ConstructeurMauvaisPlace)
{
  ASSERT_THROW (VehiculePromenade voiture ("1M8GDM9AXKP042788", "L000000", 0), ContratException) << "Le nmb de siege ne peut etre plus petit que 1";
}


TEST (VehiculePromenade , TestClone)
{

  VehiculePromenade VehiculePromenadeTestClone1 ("1M8GDM9AXKP042788", "ABC 000", 4);

  std::unique_ptr<Vehicule>  VehiculePromenadeTestClone2 = VehiculePromenadeTestClone1.clone ();

  ASSERT_EQ (VehiculePromenadeTestClone1.reqVehiculeFormate (), VehiculePromenadeTestClone2-> reqVehiculeFormate ());
}

class VehiculeValide : public::testing::Test
{

public:


  VehiculeValide () : vehiculeTest ("1M8GDM9AXKP042788", "ABC 000", 3) { }

  VehiculePromenade vehiculeTest;
} ;


TEST_F (VehiculeValide, reqNIV)
{
  ASSERT_EQ ("1M8GDM9AXKP042788", vehiculeTest.reqNiv ());
}


TEST_F (VehiculeValide, reqImmatriculation)
{
  ASSERT_EQ ("ABC 000", vehiculeTest.reqImmatriculation ());
}


TEST_F (VehiculeValide, reqNombreDePlace)
{
  ASSERT_EQ (3, vehiculeTest.reqNombreDePlace ());
}


TEST_F (VehiculeValide, asgBonneImmatriculation)
{
  vehiculeTest.asgImmatriculation ("IFT 006");
  ASSERT_EQ ("IFT 006", vehiculeTest.reqImmatriculation ());
}


TEST_F (VehiculeValide, asgMauvaiseImmatriculation)
{
  ASSERT_THROW (vehiculeTest.asgImmatriculation ("L000000"), ContratException) << "L'immatriculation est invalide";
}


TEST_F (VehiculeValide, tarificationAnnuelle)
{
  ASSERT_EQ (234.74, vehiculeTest.tarificationAnnuelle ());
}


TEST_F (VehiculeValide, reqVehiculeFormate)
{
  ostringstream os;
  os << vehiculeTest.reqVehiculeFormate ();
  ASSERT_EQ (os.str (), vehiculeTest.reqVehiculeFormate ());

}


TEST_F (VehiculeValide,  operatorEgalite)
{
  VehiculePromenade vehiculeTest2 ("1M8GDM9AXKP042788", "ABC 000", 3);

  ASSERT_EQ (1, (vehiculeTest.operator == (vehiculeTest2)));
}


TEST_F (VehiculeValide,  operatorEgaliteFausse)
{
  VehiculePromenade vehiculeTest2 ("1M8GDM9AXKP042788", "IFT 006", 3);

  ASSERT_EQ (0, (vehiculeTest.operator == (vehiculeTest2)));
}