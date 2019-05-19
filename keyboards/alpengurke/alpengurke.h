#pragma once

#include "quantum.h"

#define LAYOUT_ortho_3x10( \
	 K00, K01, K02, K03, K04,   K05, K06, K07, K08, K09 , \
	 K10, K11, K12, K13, K14,   K15, K16, K17, K18, K19 , \
	 K20, K21, K22, K23, K24,   K25, K26, K27, K28, K29   \
) { \
  { K09, K08, K07, K06, K05 }, \
  { K19, K18, K17, K16, K15 }, \
  { K29, K28, K27, K26, K25 }, \
  { K00, K01, K02, K03, K04 }, \
  { K10, K11, K12, K13, K14 }, \
  { K20, K21, K22, K23, K24 } \
}
