---
layout: method
title: stroke_text
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void stroke_text(std::string_view, cycfi::artist::point):
    arguments:
      - description: __OPTIONAL__
        name: utf8
        type: std::string_view
      - description: __OPTIONAL__
        name: p
        type: cycfi::artist::point
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void stroke_text(std::string_view utf8, cycfi::artist::point p)
  void stroke_text(std::string_view, float, float):
    arguments:
      - description: __OPTIONAL__
        name: utf8
        type: std::string_view
      - description: __OPTIONAL__
        name: x
        type: float
      - description: __OPTIONAL__
        name: y
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void stroke_text(std::string_view utf8, float x, float y)
---
