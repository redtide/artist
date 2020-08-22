---
layout: method
title: radial_gradient
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
is_ctor: true
overloads:
  radial_gradient(const cycfi::artist::canvas::radial_gradient &):
    arguments:
      - description: __OPTIONAL__
        name: unnamed-0
        type: const cycfi::artist::canvas::radial_gradient &
        unnamed: true
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: radial_gradient(const cycfi::artist::canvas::radial_gradient &)
  radial_gradient(cycfi::artist::canvas::radial_gradient &&):
    arguments:
      - description: __OPTIONAL__
        name: unnamed-0
        type: cycfi::artist::canvas::radial_gradient &&
        unnamed: true
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: radial_gradient(cycfi::artist::canvas::radial_gradient &&)
  radial_gradient(cycfi::artist::point, float, cycfi::artist::point, float):
    arguments:
      - description: __OPTIONAL__
        name: c1
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: c1r
        type: float
      - description: __OPTIONAL__
        name: c2
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: c2r
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: radial_gradient(cycfi::artist::point c1, float c1r, cycfi::artist::point c2, float c2r)
  radial_gradient(float, float, float, float, float, float):
    arguments:
      - description: __OPTIONAL__
        name: c1x
        type: float
      - description: __OPTIONAL__
        name: c1y
        type: float
      - description: __OPTIONAL__
        name: c1r
        type: float
      - description: __OPTIONAL__
        name: c2x
        type: float
      - description: __OPTIONAL__
        name: c2y
        type: float
      - description: __OPTIONAL__
        name: c2r
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: radial_gradient(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r)
---
