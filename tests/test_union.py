from pxr import Usd, UsdGeom, Gf, Sdf, G4

def setDefaultBox(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(5)
    box.GetYAttr().Set(5)
    box.GetZAttr().Set(5)

def setDefaultBox2(box) :
    box.InstallUpdateListener()
    box.GetXAttr().Set(2)
    box.GetYAttr().Set(2)
    box.GetZAttr().Set(2)

def test_union(stage = None) :
    # make subtraction
    if not stage :
        stage = Usd.Stage.CreateNew("test_union.usda")

    s = G4.Union.Define(stage, "/u1")

    b1 = G4.Box.Define(stage, "/u1/b1")
    b1m = UsdGeom.Mesh.Define(stage,"/u1/u1result")

    setDefaultBox(b1)
    x = G4.DisplacedSolid.Define(stage, "/u1/solid2")
    b2 = G4.Box.Define(stage, "/u1/solid2/b2")
    setDefaultBox2(b2)

    x.InstallUpdateListener()
    x.GetTranslationAttr().Set((5,5,5))
    x.GetRotationAttr().Set((45,0,0))

    s.GetSolid1primAttr().Set("b1")
    s.GetSolid2primAttr().Set("solid2")
    s.GetSolid3primAttr().Set("u1result")

    s.Update()

    stage.Save()

    return s