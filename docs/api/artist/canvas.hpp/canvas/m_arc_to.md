---
layout: method
title: arc_to
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void arc_to(cycfi::artist::point, cycfi::artist::point, float):
    arguments:
      - description: __OPTIONAL__
        name: p1
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: p2
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: radius
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void arc_to(cycfi::artist::point p1, cycfi::artist::point p2, float radius)
  void arc_to(float, float, float, float, float):
    arguments:
      - description: __OPTIONAL__
        name: x1
        type: float
      - description: __OPTIONAL__
        name: y1
        type: float
      - description: __OPTIONAL__
        name: x2
        type: float
      - description: __OPTIONAL__
        name: y2
        type: float
      - description: __OPTIONAL__
        name: radius
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void arc_to(float x1, float y1, float x2, float y2, float radius)
---
