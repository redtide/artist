#!/bin/bash

pushd $(dirname $0) > /dev/null

if [[ ${OSTYPE} == "linux-gnu"* ]]; then
   HYDE_COMPILER_ARGS="-DARTIST_SKIA=1"
elif [[ ${OSTYPE} == "darwin"* ]]; then
   HYDE_COMPILER_ARGS="-DARTIST_QUARTZ_2D=1"
fi

mkdir -p docs/api

HYDE_ARGS="--hyde-update --access-filter-public --use-system-clang --namespace-blacklist=detail"

hyde ${HYDE_ARGS} lib/include/artist/canvas.hpp -- ${HYDE_COMPILER_ARGS}

popd > /dev/null
