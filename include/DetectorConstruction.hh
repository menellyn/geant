#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1


#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;
    void ConstructSDandField() override;

    std::vector<G4ThreeVector> CalculateDodecahedronVertices(G4double radius);
    std::vector<G4ThreeVector> CalculateIcosahedronVertices(G4double radius);

  private:
    G4LogicalVolume* logicPhotocatod;
};


#endif
