#!/bin/sh
gmake MAKE=gmake LD="gcc -fcommon" CC="gcc -fcommon" || exit 1
