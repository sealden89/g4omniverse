//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// GENERATED FILE.  DO NOT EDIT.
#include "pxr/external/boost/python/class.hpp"
#include ".//tokens.h"

PXR_NAMESPACE_USING_DIRECTIVE

#define _ADD_TOKEN(cls, name) \
    cls.add_static_property(#name, +[]() { return G4Tokens->name.GetString(); });

void wrapG4Tokens()
{
    pxr_boost::python::class_<G4TokensType, pxr_boost::python::noncopyable>
        cls("Tokens", pxr_boost::python::no_init);
    _ADD_TOKEN(cls, angle_unit);
    _ADD_TOKEN(cls, daughters);
    _ADD_TOKEN(cls, fieldprim);
    _ADD_TOKEN(cls, g4type);
    _ADD_TOKEN(cls, length_unit);
    _ADD_TOKEN(cls, limitsprim);
    _ADD_TOKEN(cls, logicalprim);
    _ADD_TOKEN(cls, materialprim);
    _ADD_TOKEN(cls, name);
    _ADD_TOKEN(cls, r1);
    _ADD_TOKEN(cls, r2);
    _ADD_TOKEN(cls, rotation);
    _ADD_TOKEN(cls, sensitiveprim);
    _ADD_TOKEN(cls, solid1prim);
    _ADD_TOKEN(cls, solid2prim);
    _ADD_TOKEN(cls, solid3prim);
    _ADD_TOKEN(cls, solidprim);
    _ADD_TOKEN(cls, solidprims);
    _ADD_TOKEN(cls, translation);
    _ADD_TOKEN(cls, x);
    _ADD_TOKEN(cls, y);
    _ADD_TOKEN(cls, z);
    _ADD_TOKEN(cls, BooleanSolid);
    _ADD_TOKEN(cls, Box);
    _ADD_TOKEN(cls, DisplacedSolid);
    _ADD_TOKEN(cls, Intersection);
    _ADD_TOKEN(cls, Logical);
    _ADD_TOKEN(cls, MultiUnion);
    _ADD_TOKEN(cls, Physical);
    _ADD_TOKEN(cls, Subtraction);
    _ADD_TOKEN(cls, Tubs);
    _ADD_TOKEN(cls, Union);
    _ADD_TOKEN(cls, VSolid);
}
