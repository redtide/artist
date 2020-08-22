---
layout: method
title: shadow_style
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void shadow_style(cycfi::artist::point, float, cycfi::artist::color):
    arguments:
      - description: __OPTIONAL__
        name: offset
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: blur
        type: float
      - description: __OPTIONAL__
        name: c
        type: cycfi::artist::color
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void shadow_style(cycfi::artist::point offset, float blur, cycfi::artist::color c)
  void shadow_style(float, cycfi::artist::color):
    arguments:
      - description: __OPTIONAL__
        name: blur
        type: float
      - description: __OPTIONAL__
        name: c
        type: cycfi::artist::color
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void shadow_style(float blur, cycfi::artist::color c)
  void shadow_style(float, float, float, cycfi::artist::color):
    arguments:
      - description: __OPTIONAL__
        name: offsetx
        type: float
      - description: __OPTIONAL__
        name: offsety
        type: float
      - description: __OPTIONAL__
        name: blur
        type: float
      - description: __OPTIONAL__
        name: c
        type: cycfi::artist::color
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void shadow_style(float offsetx, float offsety, float blur, cycfi::artist::color c)
---
