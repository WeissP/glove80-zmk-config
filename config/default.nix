{ pkgs ? import <nixpkgs> { } }:

let
  firmware = import ../zmk { };
  config = ./.;

  withBoard = board:
    firmware.zmk.override {
      inherit board;
      keymap = "${config}/glove80.c";
      kconfig = "${config}/glove80.conf";
    };

  glove80_left = withBoard "glove80_lh";
  glove80_right = withBoard "glove80_rh";

in firmware.combine_uf2 glove80_left glove80_right
