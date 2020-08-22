---
layout: method
title: draw
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
overloads:
  void draw(const cycfi::artist::image &, const cycfi::artist::rect &):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: dest
        type: const cycfi::artist::rect &
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, const cycfi::artist::rect & dest)
  void draw(const cycfi::artist::image &, const cycfi::artist::rect &, const cycfi::artist::rect &):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: src
        type: const cycfi::artist::rect &
      - description: __OPTIONAL__
        name: dest
        type: const cycfi::artist::rect &
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, const cycfi::artist::rect & src, const cycfi::artist::rect & dest)
  void draw(const cycfi::artist::image &, cycfi::artist::point):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: pos
        type: cycfi::artist::point
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, cycfi::artist::point pos)
  void draw(const cycfi::artist::image &, cycfi::artist::point, float):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: pos
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: scale
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, cycfi::artist::point pos, float scale)
  void draw(const cycfi::artist::image &, float, float):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: posx
        type: float
      - description: __OPTIONAL__
        name: posy
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, float posx, float posy)
  void draw(const cycfi::artist::image &, float, float, float):
    arguments:
      - description: __OPTIONAL__
        name: pic
        type: const cycfi::artist::image &
      - description: __OPTIONAL__
        name: posx
        type: float
      - description: __OPTIONAL__
        name: posy
        type: float
      - description: __OPTIONAL__
        name: scale
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: void draw(const cycfi::artist::image & pic, float posx, float posy, float scale)
---
