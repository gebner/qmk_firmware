# dfu-programmer doesn't have darwin on it's list of supported platforms
{ pkgs ? import <nixpkgs> { config = { allowUnsupportedSystem = true; }; }
, avr ? false, arm ? true, teensy ? true, nrf5 ? true }:

with pkgs;
let
  avr_incflags = [
    "-isystem ${avrlibc}/avr/include"
    "-B${avrlibc}/avr/lib/avr5"
    "-L${avrlibc}/avr/lib/avr5"
    "-B${avrlibc}/avr/lib/avr35"
    "-L${avrlibc}/avr/lib/avr35"
    "-B${avrlibc}/avr/lib/avr51"
    "-L${avrlibc}/avr/lib/avr51"
  ];

  nrfsdk15 = fetchzip {
    url = "https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v15.x.x/nRF5_SDK_15.0.0_a53641a.zip";
    sha256 = "12m9bxjbvq09sigbw7y3fzs280l6qdl9514ildywp1dsb63p2jbd";
  };
in

stdenv.mkDerivation {
  name = "qmk-firmware";

  buildInputs = [ dfu-programmer dfu-util diffutils bear ]
    ++ lib.optional avr [ avrbinutils avrgcc avrlibc avrdude ]
    ++ lib.optional arm [ gcc-arm-embedded ]
    ++ lib.optional teensy [ teensy-loader-cli ];

  CFLAGS = lib.optional avr avr_incflags;
  ASFLAGS = lib.optional avr avr_incflags;

  NRFSDK15_ROOT = lib.optional nrf5 "${nrfsdk15}";
}
