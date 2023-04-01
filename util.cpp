
#include "util.h"

std::string nameIntToAlpha(int name) {
    std::string nameAlpha;
    switch (name) {
        case 0: nameAlpha = "C"; break;
        case 1: nameAlpha = "Db"; break;
        case 2: nameAlpha = "D"; break;
        case 3: nameAlpha = "Eb"; break;
        case 4: nameAlpha = "E"; break;
        case 5: nameAlpha = "F"; break;
        case 6: nameAlpha = "Gb"; break;
        case 7: nameAlpha = "G"; break;
        case 8: nameAlpha = "Ab"; break;
        case 9: nameAlpha = "A"; break;
        case 10: nameAlpha = "Bb"; break;
        case 11: nameAlpha = "B"; break;
    }
    return nameAlpha;
}

int nameAlphaToInt(std::string name) {
    if (name == "C") {return 0;}
    if (name == "Db") {return 1;}
    if (name == "D") {return 2;}
    if (name == "Eb") {return 3;}
    if (name == "E") {return 4;}
    if (name == "F") {return 5;}
    if (name == "Gb") {return 6;}
    if (name == "G") {return 7;}
    if (name == "Ab") {return 8;}
    if (name == "A") {return 9;}
    if (name == "Bb") {return 10;}
    if (name == "B") {return 11;}
    else {return -1;}
}

std::unique_ptr<std::vector<int>> getChordVec(int numOfNotes) {
    std::cout << "hello";
    std::unique_ptr<std::vector<int>> chordVec;

    for (int i = 0; i < numOfNotes; i++) {
        std::cout << "{ ";

//            for (int j = 0; j < chordVec->size(); j++) { std::cout << (*chordVec)[j] << ", "; }

        std::cout << "}\n";

        std::string note;
        std::cout << "Enter a note to add to the Chord: ";
        std::cin >> note;
        chordVec->push_back(nameAlphaToInt(note));
        std::cout << '\n';
    }
    return chordVec;
}