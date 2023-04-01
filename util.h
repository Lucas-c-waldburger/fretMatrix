
#ifndef FRETMATRIX_UTIL_H
#define FRETMATRIX_UTIL_H
#include <iostream>
#include <vector>
#include <memory>


std::string nameIntToAlpha(int name);

int nameAlphaToInt(std::string name);

std::unique_ptr<std::vector<int>> getChordVec(int numOfNotes);


#endif //FRETMATRIX_UTIL_H
