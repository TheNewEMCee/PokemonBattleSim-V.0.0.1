#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug
  make -f /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug
  make -f /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug
  make -f /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug
  make -f /Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi

