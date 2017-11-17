#include "piece.h"

bool isWhite(piece p)
{
     return p > 0 && p < 10;
}

bool isBlack(piece p)
{
     return p > 10 && p < 20;
}
