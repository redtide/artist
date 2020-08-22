---
layout: method
title: transform
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  cycfi::artist::affine_transform transform() const:
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: cycfi::artist::affine_transform transform() const
  void transform(const cycfi::artist::affine_transform &):
    arguments:
      - description: __OPTIONAL__
        name: mat
        type: const cycfi::artist::affine_transform &
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void transform(const cycfi::artist::affine_transform & mat)
  void transform(double, double, double, double, double, double):
    arguments:
      - description: __OPTIONAL__
        name: a
        type: double
      - description: __OPTIONAL__
        name: b
        type: double
      - description: __OPTIONAL__
        name: c
        type: double
      - description: __OPTIONAL__
        name: d
        type: double
      - description: __OPTIONAL__
        name: tx
        type: double
      - description: __OPTIONAL__
        name: ty
        type: double
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void transform(double a, double b, double c, double d, double tx, double ty)
---
