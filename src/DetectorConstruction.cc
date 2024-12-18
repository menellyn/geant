#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"

#include "PmtSD.hh"

std::vector<G4ThreeVector> DetectorConstruction::CalculateDodecahedronVertices(G4double radius) {
    static const G4double phi = (1.0 + std::sqrt(5.0)) / 2.0;

    std::vector<G4ThreeVector> vertices = {
        {-1, phi, 0}, {1, phi, 0}, {-1, -phi, 0}, {1, -phi, 0},
        {0, -1, phi}, {0, 1, phi}, {0, -1, -phi}, {0, 1, -phi},
        {phi, 0, -1}, {phi, 0, 1}, {-phi, 0, -1}, {-phi, 0, 1}
    };

    for (auto& vertex : vertices) {
        vertex *= (radius / std::sqrt(1 + phi * phi));
    }

    return vertices;
}

std::vector<G4ThreeVector> DetectorConstruction::CalculateIcosahedronVertices(G4double radius) {
    static const G4double phi = (1.0 + std::sqrt(5.0)) / 2.0;

    std::vector<G4ThreeVector> vertices = {
        {0, 1, phi}, {0, 1, -phi}, {0, -1, phi}, {0, -1, -phi},
        {1, phi, 0}, {1, -phi, 0}, {-1, phi, 0}, {-1, -phi, 0},
        {phi, 0, 1}, {-phi, 0, 1}, {phi, 0, -1}, {-phi, 0, -1}
    };

    for (auto& vertex : vertices) {
        vertex *= (radius / std::sqrt(1 + phi * phi));
    }

    return vertices;
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();

    std::vector<G4double> photonEnergy = { 5.1 * keV, 5.2 * keV, 5.3 * keV};

  // Materials
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    G4Element* el_H = nist->FindOrBuildElement("H");
    G4Element* el_C = nist->FindOrBuildElement("C");
    G4Element* el_O = nist->FindOrBuildElement("O");
    G4Element* el_N = nist->FindOrBuildElement("N");
    G4Element* el_Gd = nist->FindOrBuildElement("Gd");

    G4double LAB_density = 0.863*g/cm3;
    G4Material* LAB = new G4Material("LAB", LAB_density, 2);
    LAB->AddElement(el_H, 22);
    LAB->AddElement(el_C, 10);
    std::vector<G4double> LAB_RIND = {1.51, 1.52, 1.53}; 
    std::vector<G4double> LAB_ABSL = { 12.0 * m, 12.0 * m, 12 * m };
    auto LAB_mt = new G4MaterialPropertiesTable();
    LAB_mt->AddProperty("RINDEX", photonEnergy, LAB_RIND);
    LAB_mt->AddProperty("ABSLENGTH", photonEnergy, LAB_ABSL);
    LAB->SetMaterialPropertiesTable(LAB_mt);

    G4double PPO_density = 1.02*g/cm3;
    G4Material* PPO = new G4Material("PPO", PPO_density, 4);
    PPO->AddElement(el_H, 11);
    PPO->AddElement(el_O, 1);
    PPO->AddElement(el_C, 15);
    PPO->AddElement(el_N, 1);

    G4double Gd_salt_density =  4.139*g/cm3;
    G4Material* Gd_salt = new G4Material("GD_SALT", Gd_salt_density, 1);
    Gd_salt->AddElement(el_Gd, 1);

    G4Material* LAB_ADMIXTURE = new G4Material("LAB_ADMIXTURE", LAB_density, 3);
    LAB_ADMIXTURE->AddMaterial(LAB, 860.0 / (860.0 + 3.0 + 0.5));
    LAB_ADMIXTURE->AddMaterial(PPO, 3.0 / (860.0 + 3.0 + 0.5));
    LAB_ADMIXTURE->AddMaterial(Gd_salt, 0.5 / (860.0 + 3.0 + 0.5));

    auto mt_scint = new G4MaterialPropertiesTable();
    std::vector<G4double> scint_SCINT = {0.1, 0.8, 0.1};
    std::vector<G4double> scint_RIND  = {1.51, 1.52, 1.53};
    std::vector<G4double> scint_ABSL  = { 5.0 * m, 5.0 * m, 5.0 * m };
    mt_scint->AddConstProperty("SCINTILLATIONYIELD", 5000. / MeV);
    mt_scint->AddConstProperty("RESOLUTIONSCALE", 1.0);
    mt_scint->AddProperty("SCINTILLATIONCOMPONENT1", photonEnergy, scint_SCINT);
    mt_scint->AddProperty("RINDEX", photonEnergy, scint_RIND);
    mt_scint->AddProperty("ABSLENGTH", photonEnergy, scint_ABSL);
    mt_scint->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 0.0 * ns);
    LAB_ADMIXTURE->SetMaterialPropertiesTable(mt_scint);

    G4Material* PMMA = nist->FindOrBuildMaterial("G4_PLEXIGLASS");

    std::vector<G4double> PMMA_RIND = {1.49, 1.49, 1.49}; 
    std::vector<G4double> PMMA_ABSL = { 10.0 * m, 10.0 * m, 10.0 * m };
    G4MaterialPropertiesTable* PMMA_mt = new G4MaterialPropertiesTable();
    PMMA_mt->AddProperty("RINDEX", photonEnergy, PMMA_RIND);
    PMMA_mt->AddProperty("ABSLENGTH", photonEnergy, PMMA_ABSL);
    PMMA->SetMaterialPropertiesTable(PMMA_mt);

    G4Material* stainlessSteel = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

    G4Material* PMT_WINDOW = nist->FindOrBuildMaterial("G4_Pyrex_Glass");
    G4Material* PMT_TUBE = stainlessSteel;

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
        
    
    G4OpticalSurface* scintPMMASurface = new G4OpticalSurface("scintPMMASurface");
    scintPMMASurface->SetType(dielectric_dielectric);
    scintPMMASurface->SetFinish(polished);
    scintPMMASurface->SetModel(unified);

    G4MaterialPropertiesTable* scintPMMA_mpt = new G4MaterialPropertiesTable();
    std::vector<G4double> reflectivity = {0.8, 0.8, 0.8}; 
    scintPMMA_mpt->AddProperty("REFLECTIVITY", photonEnergy, reflectivity, 3);
    scintPMMASurface->SetMaterialPropertiesTable(scintPMMA_mpt);

    new G4LogicalBorderSurface("scintPMMASurface", physMaterial2, physSphere, scintPMMASurface);

    // PMT
    G4double pmtWindowRadius = 85*mm;
    G4double pmtTubeRadius1 = 42*mm;
    G4double pmtTubeHeight1 = 89*mm;
    G4double pmtTubeRadius2 = 26*mm;
    G4double pmtTubeHeight2 = 55*mm;
    G4double pmtPhotocatodRadius = 85*mm;

    // PMT Photocatod
    auto solidPhotocatod = new G4Sphere("PMTPhotocatod", 0, pmtPhotocatodRadius, 0 , 360 * deg, 0, 90 * deg );
    logicPhotocatod = new G4LogicalVolume(solidPhotocatod, LAB, "PMTPhotocatod");

    // PMT Window
    auto solidWindow = new G4Sphere("PMTWindow", 0, pmtWindowRadius, 0, 360 * deg, 90*deg, 180 * deg);
    auto logicWindow = new G4LogicalVolume(solidWindow, PMT_WINDOW, "PMTWindow");

    G4ThreeVector windowOffset(0, 0, 0);
    new G4PVPlacement(nullptr, windowOffset, logicWindow, "PMTWindow", logicPhotocatod, false, 0);

    // PMT Tube1
    auto solidTube1 = new G4Tubs("PMTtube1", 0, pmtTubeRadius1, pmtTubeHeight1 / 2, 0, 360 * deg);
    auto logicTube1 = new G4LogicalVolume(solidTube1, PMT_TUBE, "PMTtube1");

    // PMT Tube2
    auto solidTube2 = new G4Tubs("PMTtube2", 0, pmtTubeRadius2, pmtTubeHeight2 / 2, 0, 360 * deg);
    auto logicTube2 = new G4LogicalVolume(solidTube2, PMT_TUBE, "PMTtube2");

    G4ThreeVector upperOffset(0, 0, -pmtWindowRadius);
    new G4PVPlacement(nullptr, upperOffset, logicTube1, "PMTtube1", logicWindow, false, 0);
    
    G4ThreeVector lowerOffset(0, 0, -(pmtTubeHeight1 / 2));
    new G4PVPlacement(nullptr, lowerOffset, logicTube2, "PMTtube2", logicTube1, false, 1);

    G4double radius = 0.75 * m;  

    //auto vertices = CalculateDodecahedronVertices(radius);
    auto vertices = CalculateIcosahedronVertices(radius);

    for (size_t i = 0; i < vertices.size(); ++i) {
        G4ThreeVector direction = -vertices[i].unit();  
        G4ThreeVector zAxis(0, 0, 1);
        G4double angle = std::acos(direction.dot(zAxis));
        G4ThreeVector axis= direction.cross(zAxis);
        axis = axis.unit();
        G4RotationMatrix* rotatePMT = new G4RotationMatrix();
        rotatePMT->rotate(angle, axis); 
        new G4PVPlacement(rotatePMT, vertices[i], logicPhotocatod, "PMT", logicMaterial1, false, i);
    }

  return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
  PmtSD* photocathodeSD = new PmtSD("PhotocathodeSD");
  G4SDManager::GetSDMpointer()->AddNewDetector(photocathodeSD);
  logicPhotocatod->SetSensitiveDetector(photocathodeSD);

}
