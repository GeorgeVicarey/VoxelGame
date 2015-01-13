################################################################################
# Automatically-generated file. Do not edit!
################################################################################

USER_OBJS :=


ifeq ($(OS),Windows_NT)
    LIBS := -lmingw32 -lglew32s -lSDL2main -lSDL2 -lopengl32
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        LIBS := -lSDL2 -lGLEW -lGL
    endif
endif