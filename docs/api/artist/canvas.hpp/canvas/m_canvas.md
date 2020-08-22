---
layout: method
title: canvas
owner: __MISSING__
brief: __MISSING__
tags:
  - method
defined_in_file: artist/canvas.hpp
is_ctor: true
overloads:
  canvas(const cycfi::artist::canvas &):
    annotation:
      - delete
    arguments:
      - description: __OPTIONAL__
        name: rhs
        type: const cycfi::artist::canvas &
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: canvas(const cycfi::artist::canvas & rhs)
  canvas(cycfi::artist::canvas &&):
    annotation:
      - delete
    arguments:
      - description: __OPTIONAL__
        name: rhs
        type: cycfi::artist::canvas &&
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: canvas(cycfi::artist::canvas && rhs)
  explicit canvas(cycfi::artist::canvas_impl *):
    arguments:
      - description: __OPTIONAL__
        name: context_
        type: cycfi::artist::canvas_impl *
    description: __MISSING__
    return: __OPTIONAL__
    signature_with_names: explicit canvas(cycfi::artist::canvas_impl * context_)
---
