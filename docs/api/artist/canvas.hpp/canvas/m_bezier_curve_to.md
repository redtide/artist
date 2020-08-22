---
layout: method
title: bezier_curve_to
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void bezier_curve_to(cycfi::artist::point, cycfi::artist::point, cycfi::artist::point):
    arguments:
      - description: __OPTIONAL__
        name: cp1
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: cp2
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: end
        type: cycfi::artist::point
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void bezier_curve_to(cycfi::artist::point cp1, cycfi::artist::point cp2, cycfi::artist::point end)
  void bezier_curve_to(float, float, float, float, float, float):
    arguments:
      - description: __OPTIONAL__
        name: cp1x
        type: float
      - description: __OPTIONAL__
        name: cp1y
        type: float
      - description: __OPTIONAL__
        name: cp2x
        type: float
      - description: __OPTIONAL__
        name: cp2y
        type: float
      - description: __OPTIONAL__
        name: x
        type: float
      - description: __OPTIONAL__
        name: y
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void bezier_curve_to(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y)
---
