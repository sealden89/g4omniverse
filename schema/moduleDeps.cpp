#include "pxr/pxr.h"
#include "pxr/base/tf/registryManager.h"
#include "pxr/base/tf/scriptModuleLoader.h"
#include "pxr/base/tf/token.h"

#include <vector>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfScriptModuleLoader) {
    // List of direct dependencies for this library.
    const std::vector<TfToken> reqs = {
        TfToken("sdf"),
        TfToken("tf"),
        TfToken("usd"),
	  TfToken("usdGeom"),
        TfToken("vt")
    };
    TfScriptModuleLoader::GetInstance().
        RegisterLibrary(TfToken("G4"), TfToken("pxr.G4"), reqs);
}

PXR_NAMESPACE_CLOSE_SCOPE
