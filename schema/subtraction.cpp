//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include ".//subtraction.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<G4Subtraction,
        TfType::Bases< G4BooleanSolid > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("Subtraction")
    // to find TfType<G4Subtraction>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, G4Subtraction>("Subtraction");
}

/* virtual */
G4Subtraction::~G4Subtraction()
{
}

/* static */
G4Subtraction
G4Subtraction::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(stage->GetPrimAtPath(path));
}

/* static */
G4Subtraction
G4Subtraction::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("Subtraction");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return G4Subtraction();
    }
    return G4Subtraction(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind G4Subtraction::_GetSchemaKind() const
{
    return G4Subtraction::schemaKind;
}

/* static */
const TfType &
G4Subtraction::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<G4Subtraction>();
    return tfType;
}

/* static */
bool 
G4Subtraction::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
G4Subtraction::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
G4Subtraction::GetG4typeAttr() const
{
    return GetPrim().GetAttribute(G4Tokens->g4type);
}

UsdAttribute
G4Subtraction::CreateG4typeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(G4Tokens->g4type,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
G4Subtraction::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        G4Tokens->g4type,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            G4BooleanSolid::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

#include "cgal_boolean.h"
#include "pxr/usd/usdGeom/xformable.h"
#include "pxr/base/gf/matrix4d.h"

void pxr::G4Subtraction::Update() {
  g4usdboolean(this->GetPrim(), SUBTRACTION);
}

#include "pxr/usd/usd/notice.h"

class SubtractionChangeListener : public pxr::TfWeakBase {
public:
  SubtractionChangeListener(pxr::G4Subtraction sub) : _sub(sub) {
    // Register the listener for object changes
    pxr::TfNotice::Register(pxr::TfCreateWeakPtr<SubtractionChangeListener>(this),
                            &SubtractionChangeListener::Update);
  }

  void Update(const pxr::UsdNotice::ObjectsChanged& notice) {

    // get names of dependent solids
    if(_sub.IsInputAffected(notice))
      _sub.Update();
  }

private:
  pxr::G4Subtraction _sub;
};

void pxr::G4Subtraction::InstallUpdateListener() {
  pxr::TfNotice::Register(pxr::TfCreateWeakPtr<SubtractionChangeListener>(new SubtractionChangeListener(*this)),
                          &SubtractionChangeListener::Update);
}
