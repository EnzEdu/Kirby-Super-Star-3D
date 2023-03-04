#!/bin/bash
find . -maxdepth 1 -name 'CG.aGame_EnzoEduardo.cpp' -execdir g++ -o jogo '{}' -lGL -lGLU -lglut \; && ./jogo