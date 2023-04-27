#include <gtest/gtest.h>
#include "Camion.h"
#include "ContratException.h"
#include "validationFormat.h"


using namespace saaq;


TEST (Camion, ConstructeurBonNivBonImmaBonPoidBonEssieux)
{
  Camion camion ("1M8GDM9AXKP042788", "L000000", 3500, 3);
  ASSERT_EQ ("1M8GDM9AXKP042788", camion.reqNiv ());
  ASSERT_EQ ("L000000", camion.reqImmatriculation ());
  ASSERT_EQ (3500, camion.reqPoids ());
  ASSERT_EQ (3, camion.reqNombreEssieux ());
}


TEST (Camion, ConstructeurMauvaisNiv)
{
  ASSERT_THROW (Camion camion ("1M8GDM9AP042788", "L000000", 3500, 3), ContratException) << "Le niv est invalide";
}


TEST (Camion, ConstructeurMauvaisImma)
{
  ASSERT_THROW (Camion camion ("1M8GDM9AXKP042788", "ABC 000", 3500, 3), ContratException) << "L'immatriculation est invalide";
}


TEST (Camion, ConstructeurMauvaisPoids)
{
  ASSERT_THROW (Camion camion ("1M8GDM9AXKP042788", "L000000", 2999, 3), ContratException) << "Le poids est invalide";
}


TEST (Camion, ConstructeurMauvaisEssieux)
{
  ASSERT_THROW (Camion camion ("1M8GDM9AXKP042788", "ABC 000", 3500, 2), ContratException) << "Le nombre d'essieux est invalide";
}


TEST (Camion , TestClone)
{

  Camion camionTestClone1 ("1M8GDM9AXKP042788", "L000000", 4000, 5);

  std::unique_ptr<Vehicule>  camionTestClone2 = camionTestClone1.clone ();

  ASSERT_EQ (camionTestClone1.reqVehiculeFormate (), camionTestClone2-> reqVehiculeFormate ());
}

class VehiculeValide : public::testing::Test
{

public:


  VehiculeValide () : vehiculeTest ("1M8GDM9AXKP042788", "L000000", 3001, 3) { }


  Camion vehiculeTest;
} ;


TEST_F (VehiculeValide, reqNIV)
{


  ASSERT_EQ ("1M8GDM9AXKP042788", vehiculeTest.reqNiv ());
}


TEST_F (VehiculeValide, reqImmatriculation)
{


  ASSERT_EQ ("L000000", vehiculeTest.reqImmatriculation ());
}


TEST_F (VehiculeValide, reqPoids)
{


  ASSERT_EQ (3001, vehiculeTest.reqPoids ());
}


TEST_F (VehiculeValide, reqNombreEssieux)
{


  ASSERT_EQ (3, vehiculeTest.reqNombreEssieux ());
}


TEST_F (VehiculeValide, asgBonneImmatriculation)
{


  vehiculeTest.asgImmatriculation ("L000000");
  ASSERT_EQ ("L000000", vehiculeTest.reqImmatriculation ());
}


TEST_F (VehiculeValide, asgMauvaiseImmatriculation)
{


  ASSERT_THROW (vehiculeTest.asgImmatriculation ("IFT 006"), ContratException) << "L'immatriculation est invalide";
}


TEST_F (VehiculeValide, tarificationAnnuelle)
{


  ASSERT_EQ (1711.19, vehiculeTest.tarificationAnnuelle ());
}


TEST_F (VehiculeValide,  operatorEgalite)
{


  Camion vehiculeTest2 ("1M8GDM9AXKP042788", "L000000", 3500, 2);

  ASSERT_EQ (1, (vehiculeTest.operator == (vehiculeTest2)));
}


TEST_F (VehiculeValide,  operatorEgaliteFausse)
{
  Camion vehiculeTest2 ("1M8GDM9AXKP042788", "L000001", 3500, 2);

  ASSERT_EQ (0, (vehiculeTest.operator == (vehiculeTest2)));
}
