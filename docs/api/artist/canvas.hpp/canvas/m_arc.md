---
layout: method
title: arc
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void arc(cycfi::artist::point, float, float, float, bool):
    arguments:
      - description: __OPTIONAL__
        name: p
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: radius
        type: float
      - description: __OPTIONAL__
        name: start_angle
        type: float
      - description: __OPTIONAL__
        name: end_angle
        type: float
      - description: __OPTIONAL__
        name: ccw
        type: bool
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void arc(cycfi::artist::point p, float radius, float start_angle, float end_angle, bool ccw)
  void arc(float, float, float, float, float, bool):
    arguments:
      - description: __OPTIONAL__
        name: x
        type: float
      - description: __OPTIONAL__
        name: y
        type: float
      - description: __OPTIONAL__
        name: radius
        type: float
      - description: __OPTIONAL__
        name: start_angle
        type: float
      - description: __OPTIONAL__
        name: end_angle
        type: float
      - description: __OPTIONAL__
        name: ccw
        type: bool
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void arc(float x, float y, float radius, float start_angle, float end_angle, bool ccw)
---
