---
layout: method
title: linear_gradient
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
is_ctor: true
overloads:
  linear_gradient(const cycfi::artist::canvas::linear_gradient &):
    arguments:
      - description: __OPTIONAL__
        name: unnamed-0
        type: const cycfi::artist::canvas::linear_gradient &
        unnamed: true
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: linear_gradient(const cycfi::artist::canvas::linear_gradient &)
  linear_gradient(cycfi::artist::canvas::linear_gradient &&):
    arguments:
      - description: __OPTIONAL__
        name: unnamed-0
        type: cycfi::artist::canvas::linear_gradient &&
        unnamed: true
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: linear_gradient(cycfi::artist::canvas::linear_gradient &&)
  linear_gradient(cycfi::artist::point, cycfi::artist::point):
    arguments:
      - description: __OPTIONAL__
        name: start
        type: cycfi::artist::point
      - description: __OPTIONAL__
        name: end
        type: cycfi::artist::point
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: linear_gradient(cycfi::artist::point start, cycfi::artist::point end)
  linear_gradient(float, float, float, float):
    arguments:
      - description: __OPTIONAL__
        name: startx
        type: float
      - description: __OPTIONAL__
        name: starty
        type: float
      - description: __OPTIONAL__
        name: endx
        type: float
      - description: __OPTIONAL__
        name: endy
        type: float
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: linear_gradient(float startx, float starty, float endx, float endy)
---
