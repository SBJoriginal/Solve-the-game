#include <gtest/gtest.h>
#include "Proprietaire.h"
#include "Camion.h"
#include "VehiculePromenade.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
#include <string>

using namespace saaq;
using namespace std;


TEST (Proprietaire, ConstructeurBonNomBonPrenom)
{
  Proprietaire humain ("Plante", "Lenny");
  ASSERT_EQ ("Lenny", humain.reqPrenom ());
  ASSERT_EQ ("Plante", humain.reqNom ());
}


TEST (Proprietaire, ConstructeurMauvaisNom)
{
  ASSERT_THROW (Proprietaire humain ("Plante", ""), ContratException) << "Le prenom est vide";
}


TEST (Proprietaire, ConstructeurMauvaisPrenom)
{
  ASSERT_THROW (Proprietaire humain ("", "Lenny"), ContratException) << "Le nom est vide";
}

class ProprietaireValide : public::testing::Test
{

public:


  ProprietaireValide () : proprietaireTest ("Plante", "Lenny") { }

  Proprietaire proprietaireTest;


} ;


TEST_F (ProprietaireValide, reqNom)
{
  ASSERT_EQ ("Plante", proprietaireTest.reqNom ());
}


TEST_F (ProprietaireValide, reqPrenom)
{
  ASSERT_EQ ("Lenny", proprietaireTest.reqPrenom ());
}


TEST_F (ProprietaireValide, reqNombreDeVehicule0)
{
  VehiculePromenade car ("1M8GDM9AXKP042788", "ABC 000", 5);
  ASSERT_EQ (0, proprietaireTest.reqNombreDeVehicule ());
}


TEST_F (ProprietaireValide, reqNombreDeVehicule1)
{
  VehiculePromenade car ("1M8GDM9AXKP042788", "ABC 000", 5);
  proprietaireTest.ajouterVehicule (car);
  ASSERT_EQ (1, proprietaireTest.reqNombreDeVehicule ());
}


TEST_F (ProprietaireValide, reqNombreDeVehicule2)
{
  VehiculePromenade car ("1M8GDM9AXKP042788", "ABC 000", 5);
  VehiculePromenade car2 ("1M8GDM9AXKP042788", "ABC 000", 5);
  proprietaireTest.ajouterVehicule (car);
  proprietaireTest.ajouterVehicule (car2);
  ASSERT_EQ (2, proprietaireTest.reqNombreDeVehicule ());
}


TEST_F (ProprietaireValide, reqVehiculeFormate)
{
  ostringstream os;
  os << proprietaireTest.reqProprietaireFormate ();
  ASSERT_EQ (os.str (), proprietaireTest.reqProprietaireFormate ());

}


TEST_F (ProprietaireValide,  operatorEgaliteProprietaireTest)
{
  VehiculePromenade vehiculePromenade ("1M8GDM9AXKP042788", "ABC 000", 4);
  Camion vehiculeCamion ("1M8GDM9AXKP042788", "L000000", 3500, 3);
  proprietaireTest.ajouterVehicule (vehiculePromenade);
  proprietaireTest.ajouterVehicule (vehiculeCamion);
  Proprietaire proprietaireTest2 ("antoine", "ayden");
  proprietaireTest.operator = (proprietaireTest2);
  ASSERT_EQ (0, proprietaireTest.reqNombreDeVehicule ());
  ASSERT_EQ (proprietaireTest.reqProprietaireFormate (), proprietaireTest2.reqProprietaireFormate ());

}


TEST_F (ProprietaireValide,  operatorEgaliteProprietaireTest2)
{
  VehiculePromenade vehiculePromenade ("1M8GDM9AXKP042788", "ABC 000", 4);
  Camion vehiculeCamion ("1M8GDM9AXKP042788", "L000000", 3500, 3);
  proprietaireTest.ajouterVehicule (vehiculePromenade);
  proprietaireTest.ajouterVehicule (vehiculeCamion);
  Proprietaire proprietaireTest2 ("antoine", "ayden");
  proprietaireTest2.operator = (proprietaireTest);
  ASSERT_EQ (2, proprietaireTest2.reqNombreDeVehicule ());
  ASSERT_EQ (proprietaireTest2.reqProprietaireFormate (), proprietaireTest.reqProprietaireFormate ());
}


TEST_F (ProprietaireValide,  operatorEgaliteProprietaireTestAVecLuiMemel)
{
  VehiculePromenade vehiculePromenade ("1M8GDM9AXKP042788", "ABC 000", 4);
  Camion vehiculeCamion ("1M8GDM9AXKP042788", "L000000", 3500, 3);
  proprietaireTest.ajouterVehicule (vehiculePromenade);
  proprietaireTest.ajouterVehicule (vehiculeCamion);
  proprietaireTest.operator = (proprietaireTest);
  ASSERT_EQ (2, proprietaireTest.reqNombreDeVehicule ());
  ASSERT_EQ (proprietaireTest.reqProprietaireFormate (), proprietaireTest.reqProprietaireFormate ());
}


TEST_F (ProprietaireValide, constructorCopie)
{
  Camion vehiculeCamion ("1M8GDM9AXKP042788", "L000000", 3500, 3);
  proprietaireTest.ajouterVehicule (vehiculeCamion);
  Proprietaire proprietaireTest2 (proprietaireTest);
  ASSERT_EQ (proprietaireTest.reqProprietaireFormate (), proprietaireTest.reqProprietaireFormate ());
}