
#include <gtest/gtest.h>
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <sstream>
#include <string>

using namespace saaq;
using namespace std;

class VehiculeTest : public Vehicule
{

public:


  VehiculeTest (const string& p_niv, const string& p_immatriculation) : Vehicule (p_niv, p_immatriculation) { };


  virtual std::string
  reqVehiculeFormate () const override
  {
    return "reqVehiculeFormate";
  };


  virtual std::unique_ptr<Vehicule>
  clone () const override
  {
    return make_unique<VehiculeTest>(*this);
  }


  virtual
  ~VehiculeTest () { };


  double
  tarificationAnnuelle () const override
  {
    return 0.0;
  };


  void
  asgImmatriculation (const std::string& numero_vehicule) override {
    // pas besoin de faire quoi que ce soit ici
  }
} ;



// namespace


TEST (VehiculeTest, ConstructeurBonNivBonImma)
{
  VehiculeTest unVehicule ("1M8GDM9AXKP042788", "L000000");
  ASSERT_EQ ("1M8GDM9AXKP042788", unVehicule.reqNiv ());
  ASSERT_EQ ("L000000", unVehicule.reqImmatriculation ());
}


TEST (VehiculeTest, ConstructeurMauvaisNiv)
{
  ASSERT_THROW (VehiculeTest unVehicule ("asdfh3", "L000000"), ContratException) << "Le niv est invalide";

}


TEST (VehiculeTest, ConstructeurMauvaisImma)
{
  ASSERT_THROW (VehiculeTest unVehicule ("1M8GDM9AXKP042788", "G000000"), ContratException) << "L'immatriculation est invalide";
}


TEST (VehiculeTest, ConstructeurMauvaisNivMauvaisImma)
{
  ASSERT_THROW (VehiculeTest unVehicule ("asdfh3", "L000000"), ContratException) << "Le niv est invalide";
  ASSERT_THROW (VehiculeTest unVehicule ("1M8GDM9AXKP042788", "G000000"), ContratException) << "L'immatriculation est invalide";
}

class VehiculeValide : public::testing::Test
{

public:


  VehiculeValide () : vehiculeTest ("1M8GDM9AXKP042788", "L000000") { }

  VehiculeTest vehiculeTest;

} ;


TEST_F (VehiculeValide, reqNIV)
{
  ASSERT_EQ ("1M8GDM9AXKP042788", vehiculeTest.reqNiv ());
}


TEST_F (VehiculeValide, reqImmatriculation)
{
  ASSERT_EQ ("L000000", vehiculeTest.reqImmatriculation ());
}


TEST_F (VehiculeValide, reqVehiculeFormate)
{
  ostringstream os;
  os << vehiculeTest.reqVehiculeFormate ();
  ASSERT_EQ (os.str (), vehiculeTest.reqVehiculeFormate ());

}


TEST_F (VehiculeValide,  operatorEgalite)
{
  VehiculeTest vehiculeTest2 ("1M8GDM9AXKP042788", "L000000");
  ASSERT_EQ (1, (vehiculeTest.operator == (vehiculeTest2)));
}


TEST_F (VehiculeValide,  operatorEgaliteFausse)
{
  VehiculeTest vehiculeTest2 ("1M8GDM9AXKP042788", "ABC 000");
  ASSERT_EQ (0, (vehiculeTest.operator == (vehiculeTest2)));
}


