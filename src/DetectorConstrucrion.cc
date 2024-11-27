#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();

  // Materials
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    G4Element* el_H = nist->FindOrBuildElement("H");
    G4Element* el_C = nist->FindOrBuildElement("C");
    G4Element* el_O = nist->FindOrBuildElement("O");
    G4Element* el_N = nist->FindOrBuildElement("N");
    G4Element* el_S = nist->FindOrBuildElement("S");
    G4Element* el_Gd = nist->FindOrBuildElement("Gd");

    G4double LAB_density = 0.863*g/cm3;
    G4Material* LAB = new G4Material("LAB", LAB_density, 2);
    LAB->AddElement(el_H, 30);
    LAB->AddElement(el_C, 18);

    G4double PPO_density = 1.094*g/cm3;
    G4Material* PPO = new G4Material("PPO", PPO_density, 4);
    PPO->AddElement(el_H, 11);
    PPO->AddElement(el_O, 1);
    PPO->AddElement(el_C, 15);
    PPO->AddElement(el_N, 1);

    G4double Gd_salt_density = 7.32*g/cm3;
    G4Material* Gd_salt = new G4Material("GD_SALT", Gd_salt_density, 3);
    Gd_salt->AddElement(el_Gd, 2);
    Gd_salt->AddElement(el_O, 2);
    Gd_salt->AddElement(el_S, 1);

    G4Material* LAB_ADMIXTURE = new G4Material("LAB_ADMIXTURE", LAB_density, 3);
    LAB_ADMIXTURE->AddMaterial(LAB, 99.6*perCent);
    LAB_ADMIXTURE->AddMaterial(PPO, 0.3*perCent);
    LAB_ADMIXTURE->AddMaterial(Gd_salt, 0.1*perCent);

    G4Material* PMMA = nist->FindOrBuildMaterial("G4_PLEXIGLASS");
    G4Material* stainlessSteel = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

    // World
    G4double world_size = 2.5*m;
    auto solidWorld = new G4Box("World", world_size, world_size, world_size);
    auto logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    auto physWorld = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                           // at (0,0,0)
        logicWorld,                                // its logical volume
        "World",                                   // its name
        nullptr,                                   // its mother  volume
        false,                                     // no boolean operation
        0);                         


    // Cylindrical barrel
    G4double barrel_radius = (1858*0.5 + 2)*mm;
    G4double barrel_height = (1858 + 4)*mm;
    auto solidBarrel = new G4Tubs("Barrel", 0, barrel_radius, barrel_height*0.5, 0*deg, 360*deg); 
    auto logicBarrel = new G4LogicalVolume(solidBarrel, stainlessSteel, "Barrel");
    auto physBarrel = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                          // at (0,0,0)
        logicBarrel,                              // its logical volume
        "Barrel",                                 // its name
        logicWorld,                               // its mother  volume
        false,                                    // no boolean operation
        0);                                        // copy number                  

    
    // Cylindrical LAB material
    G4double mat1_radius = 1858*0.5*mm;
    G4double mat1_height = 1858*mm;
    auto solidMaterial1 = new G4Tubs("LAB", // name
        0, // inner radius
        mat1_radius, // outer radius
        mat1_height*0.5, // Z half length
        0*deg, // starting Phi
        360 * deg); // segment angle
    auto logicMaterial1 = new G4LogicalVolume(solidMaterial1, LAB, "LAB");
    auto physMaterial1 = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                             // at (0,0,0)
        logicMaterial1,                              // its logical volume
        "LAB",                                       // its name
        logicBarrel,                                 // its mother  volume
        false,                                       // no boolean operation
        0);                                          // copy number   

    // Sphere 
    G4double sphere_radius = std::cbrt(3 / (4 * CLHEP::pi))*m;
    auto solidSphere = new G4Sphere	(	"Sphere", //name
      sphere_radius,                            // inner radius
      (sphere_radius + 10*mm),                   // outer radius
      0,                                        // starting Phi
      360 * deg,                            // ending Phi
      0,                                        // starting Theta
      180 * deg                                 // ending Theta
      );
    auto logicSphere = new G4LogicalVolume(solidSphere, PMMA, "Sphere");
    auto physSphere = new G4PVPlacement(nullptr,  // no rotation
        G4ThreeVector(),                          // at (0,0,0)
        logicSphere,                              // its logical volume
        "Sphere",                                 // its name
        logicMaterial1,                           // its mother  volume
        false,                                    // no boolean operation
        0);                                       // copy number
        


    // Spherical LAB_ADMIXTURE material
    auto solidMaterial2 = new G4Orb("LAB_ADMIXTURE", sphere_radius);
    auto logicMaterial2 = new G4LogicalVolume(solidMaterial2, LAB_ADMIXTURE, "LAB_ADMIXTURE");
    auto physMaterial2 = new G4PVPlacement(nullptr, // no rotation
        G4ThreeVector(),                            // at (0,0,0)
        logicMaterial2,                             // its logical volume
        "LAB_ADMIXTURE",                            // its name
        logicSphere,                                // its mother  volume
        false,                                      // no boolean operation
        0);                                         // copy number
        

  return physWorld;
}